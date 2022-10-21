

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from driveAssembly.idl
using RTI Code Generator (rtiddsgen) version 3.1.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef driveAssembly_1394428467_h
#define driveAssembly_1394428467_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#include "rti/xcdr/Interpreter.hpp"
#else
#include "ndds_standalone_type.h"
#endif

typedef enum going
{
    going_null  = 0, 
    forward  = 1, 
    backward  = 2
} going;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * going_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *going_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *going_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *going_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(goingSeq, going);

NDDSUSERDllExport
RTIBool going_initialize(
    going* self);

NDDSUSERDllExport
RTIBool going_initialize_ex(
    going* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool going_initialize_w_params(
    going* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool going_finalize_w_return(
    going* self);

NDDSUSERDllExport
void going_finalize(
    going* self);

NDDSUSERDllExport
void going_finalize_ex(
    going* self,RTIBool deletePointers);

NDDSUSERDllExport
void going_finalize_w_params(
    going* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void going_finalize_optional_members(
    going* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool going_copy(
    going* dst,
    const going* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
typedef enum direction
{
    direction_null  = 0, 
    left  = 1, 
    right  = 2
} direction;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * direction_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *direction_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *direction_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *direction_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(directionSeq, direction);

NDDSUSERDllExport
RTIBool direction_initialize(
    direction* self);

NDDSUSERDllExport
RTIBool direction_initialize_ex(
    direction* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool direction_initialize_w_params(
    direction* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool direction_finalize_w_return(
    direction* self);

NDDSUSERDllExport
void direction_finalize(
    direction* self);

NDDSUSERDllExport
void direction_finalize_ex(
    direction* self,RTIBool deletePointers);

NDDSUSERDllExport
void direction_finalize_w_params(
    direction* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void direction_finalize_optional_members(
    direction* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool direction_copy(
    direction* dst,
    const direction* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
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

    going   drive ;
    direction   steer ;

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

