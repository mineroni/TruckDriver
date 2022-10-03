

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
const char *goingTYPENAME = "going";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode * going_get_typecode(void)
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member going_g_tc_members[3]=
    {

        {
            (char *)"going_null",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            going_null, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"forward",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            forward, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"backward",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            backward, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode going_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"going", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            going_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for going*/

    if (is_initialized) {
        return &going_g_tc;
    }

    going_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    going_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    going_g_tc._data._annotations._defaultValue._u.long_value = 0;

    going_g_tc._data._sampleAccessInfo =
    going_get_sample_access_info();
    going_g_tc._data._typePlugin =
    going_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &going_g_tc;
}

#define TSeq goingSeq
#define T going
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *going_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo going_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(goingSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        goingSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &going_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *going_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo going_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo going_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &going_g_sampleAccessInfo;
    }

    going_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

    going_g_sampleAccessInfo.memberAccessInfos = 
    going_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(going);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            going_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            going_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    going_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    going_g_sampleAccessInfo.getMemberValuePointerFcn = 
    going_get_member_value_pointer;

    going_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &going_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *going_get_type_plugin_info()
{
    static RTIXCdrTypePlugin going_g_typePlugin = 
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
        going_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        going_finalize_w_return,
        NULL
    };

    return &going_g_typePlugin;
}
#endif

RTIBool going_initialize(
    going* sample) {
    *sample = going_null;
    return RTI_TRUE;
}

RTIBool going_initialize_ex(
    going* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return going_initialize_w_params(
        sample,&allocParams);

}

RTIBool going_initialize_w_params(
    going* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = going_null;
    return RTI_TRUE;
}

RTIBool going_finalize_w_return(
    going* sample)
{
    if (sample) {} /* To avoid warnings */

    return RTI_TRUE;
}

void going_finalize(
    going* sample)
{

    if (sample==NULL) {
        return;
    }
}

void going_finalize_ex(
    going* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    going_finalize_w_params(
        sample,&deallocParams);
}

void going_finalize_w_params(
    going* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void going_finalize_optional_members(
    going* sample, RTIBool deletePointers)
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

RTIBool going_copy(
    going* dst,
    const going* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'going' sequence class.
*/
#define T going
#define TSeq goingSeq

#define T_initialize_w_params going_initialize_w_params

#define T_finalize_w_params   going_finalize_w_params
#define T_copy       going_copy

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

/* ========================================================================= */
const char *directionTYPENAME = "direction";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode * direction_get_typecode(void)
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member direction_g_tc_members[3]=
    {

        {
            (char *)"direction_null",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            direction_null, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"left",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            left, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"right",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            right, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode direction_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"direction", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            direction_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for direction*/

    if (is_initialized) {
        return &direction_g_tc;
    }

    direction_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    direction_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    direction_g_tc._data._annotations._defaultValue._u.long_value = 0;

    direction_g_tc._data._sampleAccessInfo =
    direction_get_sample_access_info();
    direction_g_tc._data._typePlugin =
    direction_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &direction_g_tc;
}

#define TSeq directionSeq
#define T direction
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *direction_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo direction_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(directionSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        directionSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &direction_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *direction_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo direction_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo direction_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &direction_g_sampleAccessInfo;
    }

    direction_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

    direction_g_sampleAccessInfo.memberAccessInfos = 
    direction_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(direction);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            direction_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            direction_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    direction_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    direction_g_sampleAccessInfo.getMemberValuePointerFcn = 
    direction_get_member_value_pointer;

    direction_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &direction_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *direction_get_type_plugin_info()
{
    static RTIXCdrTypePlugin direction_g_typePlugin = 
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
        direction_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        direction_finalize_w_return,
        NULL
    };

    return &direction_g_typePlugin;
}
#endif

RTIBool direction_initialize(
    direction* sample) {
    *sample = direction_null;
    return RTI_TRUE;
}

RTIBool direction_initialize_ex(
    direction* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return direction_initialize_w_params(
        sample,&allocParams);

}

RTIBool direction_initialize_w_params(
    direction* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = direction_null;
    return RTI_TRUE;
}

RTIBool direction_finalize_w_return(
    direction* sample)
{
    if (sample) {} /* To avoid warnings */

    return RTI_TRUE;
}

void direction_finalize(
    direction* sample)
{

    if (sample==NULL) {
        return;
    }
}

void direction_finalize_ex(
    direction* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    direction_finalize_w_params(
        sample,&deallocParams);
}

void direction_finalize_w_params(
    direction* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void direction_finalize_optional_members(
    direction* sample, RTIBool deletePointers)
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

RTIBool direction_copy(
    direction* dst,
    const direction* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'direction' sequence class.
*/
#define T direction
#define TSeq directionSeq

#define T_initialize_w_params direction_initialize_w_params

#define T_finalize_w_params   direction_finalize_w_params
#define T_copy       direction_copy

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

/* ========================================================================= */
const char *DriveAssemblyTYPENAME = "DriveAssembly";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode * DriveAssembly_get_typecode(void)
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member DriveAssembly_g_tc_members[2]=
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
            2, /* Number of members */
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

    DriveAssembly_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)going_get_typecode();
    DriveAssembly_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)direction_get_typecode();

    /* Initialize the values for member annotations. */
    DriveAssembly_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    DriveAssembly_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

    DriveAssembly_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    DriveAssembly_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

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

    static RTIXCdrMemberAccessInfo DriveAssembly_g_memberAccessInfos[2] =
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

    sample->drive = going_null;
    sample->steer = direction_null;
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

    going_finalize_w_params(&sample->drive,deallocParams);

    direction_finalize_w_params(&sample->steer,deallocParams);

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

        if (!going_copy(
            &dst->drive,(const going*)&src->drive)) {
            return RTI_FALSE;
        } 
        if (!direction_copy(
            &dst->steer,(const direction*)&src->steer)) {
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
