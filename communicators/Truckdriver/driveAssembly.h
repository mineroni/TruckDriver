

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from driveAssembly.idl
using RTI Code Generator (rtiddsgen) version 3.1.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef driveAssembly_1394428357_h
#define driveAssembly_1394428357_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#include "rti/xcdr/Interpreter.hpp"
#else
#include "ndds_standalone_type.h"
#endif

extern "C" {

    extern const char *DriveAssemblyTYPENAME;

}

struct DriveAssemblySeq;
#ifndef NDDS_STANDALONE_TYPE
class DriveAssemblyTypeSupport;
class DriveAssemblyDataWriter;
class DriveAssemblyDataReader;
#endif
class DriveAssembly 
{
  public:
    typedef struct DriveAssemblySeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef DriveAssemblyTypeSupport TypeSupport;
    typedef DriveAssemblyDataWriter DataWriter;
    typedef DriveAssemblyDataReader DataReader;
    #endif

    DDS_Double   drive ;
    DDS_Double   steer ;
    DDS_Long   lamp_mode ;
    DDS_Long   horn_voice ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * DriveAssembly_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *DriveAssembly_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *DriveAssembly_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *DriveAssembly_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(DriveAssemblySeq, DriveAssembly);

NDDSUSERDllExport
RTIBool DriveAssembly_initialize(
    DriveAssembly* self);

NDDSUSERDllExport
RTIBool DriveAssembly_initialize_ex(
    DriveAssembly* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool DriveAssembly_initialize_w_params(
    DriveAssembly* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool DriveAssembly_finalize_w_return(
    DriveAssembly* self);

NDDSUSERDllExport
void DriveAssembly_finalize(
    DriveAssembly* self);

NDDSUSERDllExport
void DriveAssembly_finalize_ex(
    DriveAssembly* self,RTIBool deletePointers);

NDDSUSERDllExport
void DriveAssembly_finalize_w_params(
    DriveAssembly* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void DriveAssembly_finalize_optional_members(
    DriveAssembly* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool DriveAssembly_copy(
    DriveAssembly* dst,
    const DriveAssembly* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        template <>
        struct type_code<DriveAssembly> {
            static const RTIXCdrTypeCode * get();
        };

    } 
}

#endif

#endif /* driveAssembly */

