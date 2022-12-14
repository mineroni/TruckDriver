

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from driveAssembly.idl 
using RTI Code Generator (rtiddsgen) version 3.1.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif 
#ifndef dds_c_log_infrastructure_h                      
#include "dds_c/dds_c_infrastructure_impl.h"       
#endif 

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "driveAssembly.h"

#ifndef NDDS_STANDALONE_TYPE
#include "driveAssemblyPlugin.h"
#endif

#include <new>

/* ========================================================================= */
const char *DriveAssemblyTYPENAME = "DriveAssembly";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode * DriveAssembly_get_typecode(void)
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member DriveAssembly_g_tc_members[4]=
    {

        {
            (char *)"drive",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"steer",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"lamp_mode",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"horn_voice",/* Member name */
            {
                3,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode DriveAssembly_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"DriveAssembly", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            DriveAssembly_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for DriveAssembly*/

    if (is_initialized) {
        return &DriveAssembly_g_tc;
    }

    DriveAssembly_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    DriveAssembly_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double_w_new;
    DriveAssembly_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double_w_new;
    DriveAssembly_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    DriveAssembly_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;

    /* Initialize the values for member annotations. */
    DriveAssembly_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
    DriveAssembly_g_tc_members[0]._annotations._defaultValue._u.double_value = 0.0;
    DriveAssembly_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
    DriveAssembly_g_tc_members[0]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
    DriveAssembly_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
    DriveAssembly_g_tc_members[0]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;

    DriveAssembly_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
    DriveAssembly_g_tc_members[1]._annotations._defaultValue._u.double_value = 0.0;
    DriveAssembly_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
    DriveAssembly_g_tc_members[1]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
    DriveAssembly_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
    DriveAssembly_g_tc_members[1]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;

    DriveAssembly_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    DriveAssembly_g_tc_members[2]._annotations._defaultValue._u.long_value = 0;
    DriveAssembly_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    DriveAssembly_g_tc_members[2]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    DriveAssembly_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    DriveAssembly_g_tc_members[2]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    DriveAssembly_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    DriveAssembly_g_tc_members[3]._annotations._defaultValue._u.long_value = 0;
    DriveAssembly_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    DriveAssembly_g_tc_members[3]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    DriveAssembly_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    DriveAssembly_g_tc_members[3]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    DriveAssembly_g_tc._data._sampleAccessInfo =
    DriveAssembly_get_sample_access_info();
    DriveAssembly_g_tc._data._typePlugin =
    DriveAssembly_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &DriveAssembly_g_tc;
}

#define TSeq DriveAssemblySeq
#define T DriveAssembly
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *DriveAssembly_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo DriveAssembly_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(DriveAssemblySeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        DriveAssemblySeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &DriveAssembly_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *DriveAssembly_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    DriveAssembly *sample;

    static RTIXCdrMemberAccessInfo DriveAssembly_g_memberAccessInfos[4] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo DriveAssembly_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &DriveAssembly_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        DriveAssembly);
    if (sample == NULL) {
        return NULL;
    }

    DriveAssembly_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->drive - (char *)sample);

    DriveAssembly_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->steer - (char *)sample);

    DriveAssembly_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->lamp_mode - (char *)sample);

    DriveAssembly_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->horn_voice - (char *)sample);

    DriveAssembly_g_sampleAccessInfo.memberAccessInfos = 
    DriveAssembly_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(DriveAssembly);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            DriveAssembly_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            DriveAssembly_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    DriveAssembly_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    DriveAssembly_g_sampleAccessInfo.getMemberValuePointerFcn = 
    DriveAssembly_get_member_value_pointer;

    DriveAssembly_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &DriveAssembly_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *DriveAssembly_get_type_plugin_info()
{
    static RTIXCdrTypePlugin DriveAssembly_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        DriveAssembly_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        DriveAssembly_finalize_w_return,
        NULL
    };

    return &DriveAssembly_g_typePlugin;
}
#endif

RTIBool DriveAssembly_initialize(
    DriveAssembly* sample) {
    return DriveAssembly_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool DriveAssembly_initialize_ex(
    DriveAssembly* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return DriveAssembly_initialize_w_params(
        sample,&allocParams);

}

RTIBool DriveAssembly_initialize_w_params(
    DriveAssembly* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->drive = 0.0;

    sample->steer = 0.0;

    sample->lamp_mode = 0;

    sample->horn_voice = 0;

    return RTI_TRUE;
}

RTIBool DriveAssembly_finalize_w_return(
    DriveAssembly* sample)
{
    DriveAssembly_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void DriveAssembly_finalize(
    DriveAssembly* sample)
{

    DriveAssembly_finalize_ex(sample,RTI_TRUE);
}

void DriveAssembly_finalize_ex(
    DriveAssembly* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    DriveAssembly_finalize_w_params(
        sample,&deallocParams);
}

void DriveAssembly_finalize_w_params(
    DriveAssembly* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void DriveAssembly_finalize_optional_members(
    DriveAssembly* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool DriveAssembly_copy(
    DriveAssembly* dst,
    const DriveAssembly* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyDouble (
            &dst->drive, &src->drive)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyDouble (
            &dst->steer, &src->steer)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->lamp_mode, &src->lamp_mode)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->horn_voice, &src->horn_voice)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'DriveAssembly' sequence class.
*/
#define T DriveAssembly
#define TSeq DriveAssemblySeq

#define T_initialize_w_params DriveAssembly_initialize_w_params

#define T_finalize_w_params   DriveAssembly_finalize_w_params
#define T_copy       DriveAssembly_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        const RTIXCdrTypeCode * type_code<DriveAssembly>::get() 
        {
            return (const RTIXCdrTypeCode *) DriveAssembly_get_typecode();
        }

    } 
}
#endif
