#define WAITTIME 100 // Wait time in ms

#define GOING_FAST 100 // Speed in %
#define GOING_NORMAL 50
#define GOING_SLOW 1

#include <iostream>


#include <WinSock2.h>
#include <windows.h>
#include <Xinput.h>

#include <stdio.h>
#include <stdlib.h>

#include "driveAssembly.h"
#include "driveAssemblySupport.h"
#include "ndds/ndds_cpp.h"
#include "application.h"


using namespace application;

static int shutdown(
    DDSDomainParticipant* participant,
    const char* shutdown_message,
    int status);

double getSpeed()
{
    if (GetAsyncKeyState(0x59) < 0)
        return GOING_SLOW * 0.01;
    if (GetAsyncKeyState(0x41) < 0)
        return GOING_FAST * 0.01;
    return GOING_NORMAL * 0.01;
}

static int lamp_state;

int run_code(unsigned int domain_id, unsigned int sample_count)
{
    // Connext DDS setup
    // -----------------
    // A DomainParticipant allows an application to begin communicating in
    // a DDS domain. Typically there is one DomainParticipant per application.
    // DomainParticipant QoS is configured in USER_QOS_PROFILES.xml
    DDSDomainParticipant* participant =
        DDSTheParticipantFactory->create_participant(
            domain_id,
            DDS_PARTICIPANT_QOS_DEFAULT,
            NULL /* listener */,
            DDS_STATUS_MASK_NONE);
    if (participant == NULL)
    {
        return shutdown(participant, "create_participant error", EXIT_FAILURE);
    }

    // A Publisher allows an application to create one or more DataWriters
    // Publisher QoS is configured in USER_QOS_PROFILES.xml
    DDSPublisher* publisher = participant->create_publisher(
        DDS_PUBLISHER_QOS_DEFAULT,
        NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (publisher == NULL)
    {
        return shutdown(participant, "create_publisher error", EXIT_FAILURE);
    }

    // Register the datatype to use when creating the Topic
    const char* type_name = DriveAssemblyTypeSupport::get_type_name();
    DDS_ReturnCode_t retcode =
        DriveAssemblyTypeSupport::register_type(participant, type_name);
    if (retcode != DDS_RETCODE_OK)
    {
        return shutdown(participant, "register_type error", EXIT_FAILURE);
    }

    // A Topic has a name and a datatype. Create a Topic called
    // "DriveTruckTopic" with your registered data type
    DDSTopic* topic = participant->create_topic(
        "DriveTruckTopic",
        type_name,
        DDS_TOPIC_QOS_DEFAULT,
        NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL)
    {
        return shutdown(participant, "create_topic error", EXIT_FAILURE);
    }

    // This DataWriter will write data on Topic "DriveTruckTopic"
    // DataWriter QoS is configured in USER_QOS_PROFILES.xml
    DDSDataWriter* writer = publisher->create_datawriter(
        topic,
        DDS_DATAWRITER_QOS_DEFAULT,
        NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (writer == NULL)
    {
        return shutdown(participant, "create_datawriter error", EXIT_FAILURE);
    }

    // A narrow is a cast from a generic DataWriter to one that is specific
    // to your type. Use the type specific DataWriter to write()
    DriveAssemblyDataWriter* driveAssembly_writer =
        DriveAssemblyDataWriter::narrow(writer);
    if (driveAssembly_writer == NULL)
    {
        return shutdown(participant, "DataWriter narrow error", EXIT_FAILURE);
    }

    // Create data sample for writing
    DriveAssembly* sample = DriveAssemblyTypeSupport::create_data();
    if (sample == NULL)
    {
        return shutdown(
            participant,
            "DriveAssemblyTypeSupport::create_data error",
            EXIT_FAILURE);
    }

    unsigned int message_counter = 0;
    bool lamp_pressed = false;

    // Main loop, write data
    // ---------------------
    for (unsigned int count = 0; !shutdown_requested && count < sample_count; ++count)
    {
        
        //Getting state from XBOX controller
        DWORD controllerConnected;
        XINPUT_STATE controllerState;
        ZeroMemory(&controllerState, sizeof(XINPUT_STATE));
        controllerConnected = XInputGetState(0, &controllerState);

        bool lamp_toggle = false;

        // Set driving variables to zero
        sample->drive = 0;
        sample->steer = 0;
        sample->horn_voice = 0;

        // Xbox controller connected
        if (controllerConnected == ERROR_SUCCESS)
        {
            // Check for driving data
            if (controllerState.Gamepad.bRightTrigger != 0 && controllerState.Gamepad.bLeftTrigger == 0)
                sample->drive = (double)controllerState.Gamepad.bRightTrigger / 255;
            else if (controllerState.Gamepad.bLeftTrigger != 0 && controllerState.Gamepad.bRightTrigger == 0)
                sample->drive = -(double)controllerState.Gamepad.bLeftTrigger / 255;
            if (abs(controllerState.Gamepad.sThumbLX) > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
                sample->steer = (double)controllerState.Gamepad.sThumbLX / 32768;

            if(controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && !lamp_pressed) // Controller right shoulder
            {
                lamp_toggle = true;
                lamp_state = lamp_state + 1;
                lamp_state = lamp_state > 3 ? 0 : lamp_state;
            }
            if (controllerConnected == ERROR_SUCCESS && controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_A) // Controller A
                sample->horn_voice = 1;
        }
        if(sample->drive == 0 && sample->steer == 0 && sample->horn_voice == 0 && !lamp_toggle)
        {
            // Check pressed keys
            if (GetAsyncKeyState(VK_UP) < 0)
                sample->drive = getSpeed();
            else if (GetAsyncKeyState(VK_DOWN) < 0)
                sample->drive = -getSpeed();
            if (GetAsyncKeyState(VK_LEFT) < 0)
                sample->steer = -1;
            else if (GetAsyncKeyState(VK_RIGHT) < 0)
                sample->steer = 1;
            if (GetAsyncKeyState(0x4C) && !lamp_pressed) // L button
            {
                lamp_toggle = true;
                lamp_state = lamp_state + 1;
                lamp_state = lamp_state > 3 ? 0 : lamp_state;
            }
            if (GetAsyncKeyState(0x48)) // H button
                sample->horn_voice = 1;
        }

        lamp_pressed = controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER || GetAsyncKeyState(0x4C);

        sample->lamp_mode = lamp_state;
        //If we pressing any of the direction keys
        if (sample->drive != 0 || sample->steer != 0 || sample->horn_voice != 0 || lamp_toggle)
        {
            retcode = driveAssembly_writer->write(*sample, DDS_HANDLE_NIL);
            if (retcode != DDS_RETCODE_OK)
            {
                std::cerr << "write error " << retcode << std::endl;
            }
            else
            {
                std::cout << "Loop counter: " << count << ", Sent command counter: " << message_counter << ", Sent command: " << (sample->drive > 0 ? "Forward, " : (sample->drive < 0 ? "Backward, " : "Stopped, ")) << (sample->steer < 0  ? "Left, " : (sample->steer > 0 ? "Right, " : "Straight, ")) << (sample->lamp_mode > 0 ? "Lamp turned on, " : "Lamp turned off, ") << (sample->horn_voice == 1 ? "Horn turned on" : "Horn turned off") << std::endl;
                ++message_counter;
            }
        }

        // Send every 50 millisec
        DDS_Duration_t send_period = { 0, WAITTIME * 1000000 };
        NDDSUtility::sleep(send_period);
    }

    // Cleanup
    // -------
    // Delete data sample
    retcode = DriveAssemblyTypeSupport::delete_data(sample);
    if (retcode != DDS_RETCODE_OK) {
        std::cerr << "DriveAssemblyTypeSupport::delete_data error " << retcode << std::endl;
    }

    // Delete all entities (DataWriter, Topic, Publisher, DomainParticipant)
    return shutdown(participant, "shutting down", EXIT_SUCCESS);
}

// Delete all entities
static int shutdown(
    DDSDomainParticipant* participant,
    const char* shutdown_message,
    int status)
{
    DDS_ReturnCode_t retcode;

    std::cout << shutdown_message << std::endl;

    if (participant != NULL) {
        // This includes everything created by this Participant, including
        // DataWriters, Topics, Publishers. (and Subscribers and DataReaders)
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK) {
            std::cerr << "delete_contained_entities error " << retcode
                << std::endl;
            status = EXIT_FAILURE;
        }

        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            std::cerr << "delete_participant error " << retcode << std::endl;
            status = EXIT_FAILURE;
        }
    }

    return status;
}

int main(int argc, char* argv[])
{
    // Parse arguments and handle control-C
    ApplicationArguments arguments;
    parse_arguments(arguments, argc, argv);
    if (arguments.parse_result == PARSE_RETURN_EXIT) {
        return EXIT_SUCCESS;
    }
    else if (arguments.parse_result == PARSE_RETURN_FAILURE) {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();

    // Sets Connext verbosity to help debugging
    NDDSConfigLogger::get_instance()->set_verbosity(arguments.verbosity);

    int status = run_code(arguments.domain_id, arguments.sample_count);

    // Releases the memory used by the participant factory.  Optional at
    // application shutdown
    DDS_ReturnCode_t retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        std::cerr << "finalize_instance error " << retcode << std::endl;
        status = EXIT_FAILURE;
    }

    return status;
}