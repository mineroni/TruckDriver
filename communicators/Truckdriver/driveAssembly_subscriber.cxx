#define WAITTIME 200 // Wait time in ms

#define PERIOD_DRIVE 64000
#define DUTY_FORWARD_MIN 40000 // MIN AT 46000 by default
#define DUTY_BACKWARD_DRIVE 46000 // ha csak egy db fordulattal mehet?nk h?trafel?. Am?gy nem kell TODO
#define PERIOD_STEER 3000000
#define DUTY_LEFT_STEER 2600000
#define DUTY_RIGHT_STEER 1700000 //MAX AT 1500000
#define DUTY_STRAIGHT_STEER 2150000

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include "driveAssembly.h"
#include "driveAssemblySupport.h"
#include "ndds/ndds_cpp.h"
#include "application.h"

using namespace application;

static int shutdown(
    DDSDomainParticipant* participant,
    const char* shutdown_message,
    int status);

static double drive = 0; // poz -> forward, neg -> backward, interval: [-1,1]
static double drive_last = 0; 
static double steer = 0; // poz -> right, neg -> left, interval: [-1,1]
static double steer_last = 0;
static int lamp_mode = 0;
static int last_lamp_mode = 0;
static int horn_voice = 0;
static int last_horn_voice = 0;


void process_Output()
{
    if (drive != drive_last)
    {
        std::fstream pwm_forward;
        std::fstream pwm_backward;
        pwm_forward.open("/dev/pwm/ehrpwm1a/duty_cycle");
        pwm_backward.open("/dev/pwm/ehrpwm1b/duty_cycle");
        if (drive > 0 && drive <= 1)
        {
            pwm_backward << 0;
            pwm_forward << DUTY_FORWARD_MIN + (PERIOD_DRIVE - DUTY_FORWARD_MIN) * drive;
        }
        else if (drive < 0 && drive >= -1)
        {
            pwm_forward << 0;
            //pwm_backward << DUTY_BACKWARD_DRIVE;
            pwm_backward << DUTY_FORWARD_MIN + (PERIOD_DRIVE - DUTY_FORWARD_MIN) * (-drive);

        }
        else
        {
            pwm_forward << 0;
            pwm_backward << 0;
        }
        pwm_forward.close();
        pwm_backward.close();
        drive_last = drive;
    }
    if (steer != steer_last)
    {
        std::fstream fs;
        fs.open("/dev/pwm/ehrpwm0a/duty_cycle");
        if (steer < 0 && steer >= -1)
            fs << DUTY_LEFT_STEER;
        else if (steer > 0 && steer <= 1)
            fs << DUTY_RIGHT_STEER;
        else
            fs << DUTY_STRAIGHT_STEER;
        fs.close();
        steer_last = steer;
    }
    if (lamp_mode != last_lamp_mode)
    {
        std::fstream fs;
        fs.open("/sys/class/gpio/gpio60/value");
        switch (lamp_mode)
        {
            case(1):
                fs << 1;
                break;
            default:
                fs << 0;
                break;
        }
        fs.close();
        last_lamp_mode = lamp_mode;
    }
    if (horn_voice != last_horn_voice)
    {
        std::fstream fs;
        fs.open("/sys/class/gpio/gpio48/value");
        switch (horn_voice)
        {
            case(1):
                fs << 1;
                break;
            default:
                fs << 0;
                break;
        }
        fs.close();
        last_horn_voice = horn_voice;
    }
    //std::cout << "Drive: " << (drive == forward ? "Forward, " : (drive == backward ? "Backward, " : "Stopped, ")) << "Direction: " << (steer == left ? "Left" : (steer == right ? "Right" : "Straight")) << std::endl;
    std::cout << (drive > 0 ? "Forward, " : (drive < 0 ? "Backward, " : "Stopped, ")) << (steer < 0 ? "Left, " : (steer > 0 ? "Right, " : "Straight, ")) << (lamp_mode == 1 ? "Lamp turned on, " : "Lamp turned off, ") << (horn_voice == 1 ? "Horn turned on" : "Horn turned off") << std::endl;
}

// Process data. Returns number of samples processed.
unsigned int process_data(DriveAssemblyDataReader* driveAssembly_reader)
{
    DriveAssemblySeq data_seq;
    DDS_SampleInfoSeq info_seq;
    unsigned int samples_read = 0;

    // Take available data from DataReader's queue
    DDS_ReturnCode_t retcode = driveAssembly_reader->take(data_seq, info_seq);

    if (retcode != DDS_RETCODE_OK)
    {
        std::cerr << "take error " << retcode << std::endl;
        return 0;
    }

    // Iterate over all available data
    for (int i = 0; i < data_seq.length(); ++i)
    {
        // Check if a sample is an instance lifecycle event
        if (!info_seq[i].valid_data)
        {
            std::cout << "Received instance state notification" << std::endl;
            continue;
        }
        // Print data
        //DriveAssemblyTypeSupport::print_data(&data_seq[i]);
        drive = data_seq[i].drive;
        steer = data_seq[i].steer;
        horn_voice = data_seq[i].horn_voice;
        lamp_mode = data_seq[i].lamp_mode;
        samples_read++;
    }
    // Data sequence was loaned from middleware for performance.
    // Return loan when application is finished with data.
    driveAssembly_reader->return_loan(data_seq, info_seq);

    return samples_read;
}

int run_code(unsigned int domain_id, unsigned int sample_count)
{
    // Connext DDS Setup
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
        shutdown(participant, "create_participant error", EXIT_FAILURE);
    }

    // A Subscriber allows an application to create one or more DataReaders
    // Subscriber QoS is configured in USER_QOS_PROFILES.xml
    DDSSubscriber* subscriber = participant->create_subscriber(
        DDS_SUBSCRIBER_QOS_DEFAULT,
        NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (subscriber == NULL)
    {
        shutdown(participant, "create_subscriber error", EXIT_FAILURE);
    }

    // Register the datatype to use when creating the Topic
    const char* type_name = DriveAssemblyTypeSupport::get_type_name();
    DDS_ReturnCode_t retcode =
        DriveAssemblyTypeSupport::register_type(participant, type_name);
    if (retcode != DDS_RETCODE_OK)
    {
        shutdown(participant, "register_type error", EXIT_FAILURE);
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
        shutdown(participant, "create_topic error", EXIT_FAILURE);
    }

    // This DataReader will read data of type driveAssembly on Topic
    // "DriveTruckTopic". DataReader QoS is configured in
    // USER_QOS_PROFILES.xml
    DDSDataReader* reader = subscriber->create_datareader(
        topic,
        DDS_DATAREADER_QOS_DEFAULT,
        NULL,
        DDS_STATUS_MASK_NONE);
    if (reader == NULL)
    {
        shutdown(participant, "create_datareader error", EXIT_FAILURE);
    }

    // Get status condition: Each entity has a Status Condition, which
    // gets triggered when a status becomes true
    DDSStatusCondition* status_condition = reader->get_statuscondition();
    if (status_condition == NULL)
    {
        shutdown(participant, "get_statuscondition error", EXIT_FAILURE);
    }

    // Enable only the status we are interested in:
    //   DDS_DATA_AVAILABLE_STATUS
    retcode = status_condition->set_enabled_statuses(DDS_DATA_AVAILABLE_STATUS);
    if (retcode != DDS_RETCODE_OK)
    {
        shutdown(participant, "set_enabled_statuses error", EXIT_FAILURE);
    }

    // Create the WaitSet and attach the Status Condition to it. The WaitSet
    // will be woken when the condition is triggered.
    DDSWaitSet waitset;
    retcode = waitset.attach_condition(status_condition);
    if (retcode != DDS_RETCODE_OK)
    {
        shutdown(participant, "attach_condition error", EXIT_FAILURE);
    }

    // A narrow is a cast from a generic DataReader to one that is specific
    // to your type. Use the type specific DataReader to read data
    DriveAssemblyDataReader* driveAssembly_reader = DriveAssemblyDataReader::narrow(reader);
    if (driveAssembly_reader == NULL)
    {
        shutdown(participant, "DataReader narrow error", EXIT_FAILURE);
    }

    // Main loop. Wait for data to arrive, and process when it arrives.
    // ----------------------------------------------------------------
    unsigned int samples_read = 0;
    while (!shutdown_requested && samples_read < sample_count)
    {
        DDSConditionSeq active_conditions_seq;

        // wait() blocks execution of the thread until one or more attached
        // Conditions become true, or until a user-specified timeout expires.
        DDS_Duration_t wait_timeout = { 0, WAITTIME * 1000000 };
        retcode = waitset.wait(active_conditions_seq, wait_timeout);

        // You get a timeout if no conditions were triggered before the timeout
        if (retcode == DDS_RETCODE_TIMEOUT)
        {
            //std::cout << "Wait timed out. All values set to zero." << std::endl;
            drive = 0;
            steer = 0;
            horn_voice = 0;
            process_Output();
            continue;
        }
        else if (retcode != DDS_RETCODE_OK)
        {
            std::cerr << "wait returned error: " << retcode << std::endl;
            break;
        }

        // Get the status changes to check which status condition
        // triggered the WaitSet to wake
        DDS_StatusMask triggeredmask = driveAssembly_reader->get_status_changes();

        // If the status is "Data Available"
        if (triggeredmask & DDS_DATA_AVAILABLE_STATUS)
        {
            samples_read += process_data(driveAssembly_reader);
            process_Output();
        }
    }

    // Cleanup
    // -------
    // Delete all entities (DataReader, Topic, Subscriber, DomainParticipant)
    return shutdown(participant, "shutting down", 0);
}

// Delete all entities
static int shutdown(
    DDSDomainParticipant* participant,
    const char* shutdown_message,
    int status)
{
    DDS_ReturnCode_t retcode;

    std::cout << shutdown_message << std::endl;

    if (participant != NULL)
    {
        // This includes everything created by this Participant, including
        // DataWriters, Topics, Publishers. (and Subscribers and DataReaders)
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK)
        {
            std::cerr << "delete_contained_entities error" << retcode << std::endl;
            status = EXIT_FAILURE;
        }

        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK)
        {
            std::cerr << "delete_participant error" << retcode << std::endl;
            status = EXIT_FAILURE;
        }
    }
    return status;
}

static void setup_pins()
{
    std::fstream fs;
    //Pin P9_14 -> Motor forward PWM
    fs.open("/dev/pwm/ehrpwm1a/period");
    fs << PERIOD_DRIVE;
    fs.close();
    fs.open("/dev/pwm/ehrpwm1a/duty_cycle");
    fs << 0;
    fs.close();
    fs.open("/dev/pwm/ehrpwm1a/enable");
    fs << 1;
    fs.close();
    //Pin P9_16 -> Motor Backward PWM
    fs.open("/dev/pwm/ehrpwm1b/period");
    fs << PERIOD_DRIVE;
    fs.close();
    fs.open("/dev/pwm/ehrpwm1b/duty_cycle");
    fs << 0;
    fs.close();
    fs.open("/dev/pwm/ehrpwm1b/enable");
    fs << 1;
    fs.close();
    //Pin P9_22 -> Servo Control PWM
    fs.open("/dev/pwm/ehrpwm0a/period");
    fs << PERIOD_STEER;
    fs.close();
    fs.open("/dev/pwm/ehrpwm0a/duty_cycle");
    fs << DUTY_STRAIGHT_STEER;
    fs.close();
    fs.open("/dev/pwm/ehrpwm0a/enable");
    fs << 1;
    fs.close();
    //Pin P9_12 -> Lamp control pin 1
    fs.open("/sys/class/gpio/gpio60/export");
    fs << 60;
    fs.close();
    fs.open("/sys/class/gpio/gpio60/direction");
    fs << "out";
    fs.close();
    fs.open("/sys/class/gpio/gpio60/value");
    fs << 0;
    fs.close();
    fs.open("/sys/class/gpio/gpio60/enable");
    fs << 1;
    fs.close();
    //Pin P9_15 -> Horn control pin 1
    fs.open("/sys/class/gpio/gpio48/export");
    fs << 48;
    fs.close();
    fs.open("/sys/class/gpio/gpio48/direction");
    fs << "out";
    fs.close();
    fs.open("/sys/class/gpio/gpio48/value");
    fs << 0;
    fs.close();
    fs.open("/sys/class/gpio/gpio48/enable");
    fs << 1;
    fs.close();
}

void finalize_pins()
{
    std::fstream fs;
    //Pin p9_14 -> Motor forward PWM
    fs.open("/dev/pwm/ehrpwm1a/enable");
    fs << 0;
    fs.close();
    //Pin P9_16 -> Motor Backward PWM
    fs.open("/dev/pwm/ehrpwm1b/enable");
    fs << 0;
    fs.close();
    //Pin P9_22 -> Servo Control PWM
    fs.open("/dev/pwm/ehrpwm0a/enable");
    fs << 0;
    fs.close();
    //Pin P9_12 -> Lamp control pin 1
    fs.open("/sys/class/gpio/gpio60/enable");
    fs << 0;
    fs.close();
    //Pin P9_15 -> Horn control pin 1
    fs.open("/sys/class/gpio/gpio48/enable");
    fs << 0;
    fs.close();
}

int main(int argc, char* argv[])
{
    // Parse arguments and handle control-C
    ApplicationArguments arguments;
    parse_arguments(arguments, argc, argv);
    if (arguments.parse_result == PARSE_RETURN_EXIT)
    {
        return EXIT_SUCCESS;
    }
    else if (arguments.parse_result == PARSE_RETURN_FAILURE)
    {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();

    setup_pins();

    // Sets Connext verbosity to help debugging
    NDDSConfigLogger::get_instance()->set_verbosity(arguments.verbosity);

    int status = run_code(arguments.domain_id, arguments.sample_count);

    // Releases the memory used by the participant factory.  Optional at
    // application shutdown
    DDS_ReturnCode_t retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK)
    {
        std::cerr << "finalize_instance error" << retcode << std::endl;
        status = EXIT_FAILURE;
    }

    finalize_pins();

    return status;
}
