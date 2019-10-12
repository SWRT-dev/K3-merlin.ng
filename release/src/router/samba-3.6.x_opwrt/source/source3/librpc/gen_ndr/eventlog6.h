/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_eventlog6
#define _PIDL_HEADER_eventlog6

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#include "librpc/gen_ndr/misc.h"
#define MAX_RPC_GUID_ARRAY_COUNT (MAX_PAYLOAD / sizeof(struct GUID))
#define eventlog6_EvtRpcSubscribePull    0x10000000
#define eventlog6_EvtRpcVarFlagsModified 0x00000001
#ifndef _HEADER_eventlog6
#define _HEADER_eventlog6

#define MAX_PAYLOAD	( 2*1024*1024 )
#define MAX_RPC_QUERY_LENGTH	( MAX_PAYLOAD/sizeof(uint16_t) )
#define MAX_RPC_CHANNEL_NAME_LENGTH	( 512 )
#define MAX_RPC_QUERY_CHANNEL_SIZE	( 512 )
#define MAX_RPC_EVENT_ID_SIZE	( 256 )
#define MAX_RPC_FILE_PATH_LENGTH	( 32768 )
#define MAX_RPC_CHANNEL_PATH_LENGTH	( 32768 )
#define MAX_RPC_BOOKMARK_LENGTH	( MAX_PAYLOAD/sizeof(uint16_t) )
#define MAX_RPC_PUBLISHER_ID_LENGTH	( 2048 )
#define MAX_RPC_PROPERTY_BUFFER_SIZE	( MAX_PAYLOAD )
#define MAX_RPC_FILTER_LENGTH	( MAX_RPC_QUERY_LENGTH )
#define MAX_RPC_RECORD_COUNT	( 1024 )
#define MAX_RPC_EVENT_SIZE	( MAX_PAYLOAD )
#define MAX_RPC_BATCH_SIZE	( MAX_PAYLOAD )
#define MAX_RPC_RENDERED_STRING_SIZE	( MAX_PAYLOAD )
#define MAX_RPC_CHANNEL_COUNT	( 8192 )
#define MAX_RPC_PUBLISHER_COUNT	( 8192 )
#define MAX_RPC_EVENT_METADATA_COUNT	( 256 )
#define MAX_RPC_VARIANT_LIST_COUNT	( 256 )
#define MAX_RPC_BOOLEAN8_ARRAY_COUNT	( MAX_PAYLOAD/sizeof(uint8_t) )
#define MAX_RPC_UINT32_ARRAY_COUNT	( MAX_PAYLOAD/sizeof(uint32_t) )
#define MAX_RPC_UINT64_ARRAY_COUNT	( MAX_PAYLOAD/sizeof(uint64_t) )
#define MAX_RPC_STRING_ARRAY_COUNT	( MAX_PAYLOAD/512 )
#define MAX_RPC_STRING_LENGTH	( MAX_PAYLOAD/sizeof(uint16_t) )
struct eventlog6_RpcInfo {
	uint32_t error;
	uint32_t sub_err;
	uint32_t sub_err_param;
};

struct eventlog6_boolean8Array {
	uint32_t count;/* [range(0,MAX_RPC_BOOLEAN8_ARRAY_COUNT)] */
	uint8_t *ptr;/* [unique,size_is(count)] */
};

struct eventlog6_UInt32Array {
	uint32_t count;/* [range(0,MAX_RPC_UINT32_ARRAY_COUNT)] */
	uint32_t *ptr;/* [unique,size_is(count)] */
};

struct eventlog6_UInt64Array {
	uint32_t count;/* [range(0,MAX_RPC_UINT64_ARRAY_COUNT)] */
	uint64_t *ptr;/* [unique,size_is(count)] */
};

struct eventlog6_StringArray {
	uint32_t count;/* [range(0,MAX_RPC_STRING_ARRAY_COUNT)] */
	const char *ptr;/* [charset(UTF16),unique,size_is(count)] */
};

struct eventlog6_GuidArray {
	uint32_t count;/* [range(0,MAX_RPC_GUID_ARRAY_COUNT)] */
	struct GUID *ptr;/* [unique,size_is(count)] */
};

enum eventlog6_EvtRpcVariantType
#ifndef USE_UINT_ENUMS
 {
	EvtRpcVarTypeNull=(int)(0),
	EvtRpcVarTypeboolean8=(int)(1),
	EvtRpcVarTypeUInt32=(int)(2),
	EvtRpcVarTypeUInt64=(int)(3),
	EvtRpcVarTypeString=(int)(4),
	EvtRpcVarTypeGuid=(int)(5),
	EvtRpcVarTypeboolean8Array=(int)(6),
	EvtRpcVarTypeUInt32Array=(int)(7),
	EvtRpcVarTypeUInt64Array=(int)(8),
	EvtRpcVarTypeStringArray=(int)(9),
	EvtRpcVarTypeGuidArray=(int)(10)
}
#else
 { __donnot_use_enum_eventlog6_EvtRpcVariantType=0x7FFFFFFF}
#define EvtRpcVarTypeNull ( 0 )
#define EvtRpcVarTypeboolean8 ( 1 )
#define EvtRpcVarTypeUInt32 ( 2 )
#define EvtRpcVarTypeUInt64 ( 3 )
#define EvtRpcVarTypeString ( 4 )
#define EvtRpcVarTypeGuid ( 5 )
#define EvtRpcVarTypeboolean8Array ( 6 )
#define EvtRpcVarTypeUInt32Array ( 7 )
#define EvtRpcVarTypeUInt64Array ( 8 )
#define EvtRpcVarTypeStringArray ( 9 )
#define EvtRpcVarTypeGuidArray ( 10 )
#endif
;

enum eventlog6_EvtRpcAssertConfigFlags
#ifndef USE_UINT_ENUMS
 {
	EvtRpcChannelPath=(int)(0),
	EvtRpcPublisherName=(int)(1)
}
#else
 { __donnot_use_enum_eventlog6_EvtRpcAssertConfigFlags=0x7FFFFFFF}
#define EvtRpcChannelPath ( 0 )
#define EvtRpcPublisherName ( 1 )
#endif
;

union eventlog6_EvtRpcVariantUnion {
	int32_t nullVal;/* [case(EvtRpcVarTypeNull)] */
	uint8_t boolean8Val;/* [case(EvtRpcVarTypeboolean8)] */
	uint32_t uint32Val;/* [case(EvtRpcVarTypeUInt32)] */
	uint64_t uint64Val;/* [case(EvtRpcVarTypeUInt64)] */
	const char *stringVal;/* [unique,case(EvtRpcVarTypeString),charset(UTF16)] */
	struct GUID *guidVal;/* [case(EvtRpcVarTypeGuid),unique] */
	struct eventlog6_boolean8Array boolean8Array;/* [case(EvtRpcVarTypeboolean8Array)] */
	struct eventlog6_UInt32Array uint32Array;/* [case(EvtRpcVarTypeUInt32Array)] */
	struct eventlog6_UInt64Array uint64Array;/* [case(EvtRpcVarTypeUInt64Array)] */
	struct eventlog6_StringArray stringArray;/* [case(EvtRpcVarTypeStringArray)] */
	struct eventlog6_GuidArray guidArray;/* [case(EvtRpcVarTypeGuidArray)] */
}/* [switch_type(eventlog6_EvtRpcVariantType)] */;

struct eventlog6_EvtRpcVariant {
	enum eventlog6_EvtRpcVariantType type;
	uint32_t flags;
	union eventlog6_EvtRpcVariantUnion *var;/* [switch_is(type),ref] */
};

struct eventlog6_EvtRpcVariantList {
	uint32_t count;/* [range(0,MAX_RPC_VARIANT_LIST_COUNT)] */
	struct eventlog6_EvtRpcVariant *props;/* [size_is(count),unique] */
};

struct eventlog6_EvtRpcQueryChannelInfo {
	const char *name;/* [unique,charset(UTF16)] */
	uint32_t status;
};


struct eventlog6_EvtRpcRegisterRemoteSubscription {
	struct {
		const char *channelPath;/* [range(0,MAX_RPC_CHANNEL_NAME_LENGTH),unique,charset(UTF16)] */
		const char *query;/* [charset(UTF16),ref,range(1,MAX_RPC_QUERY_LENGTH)] */
		const char *bookmarkXml;/* [unique,charset(UTF16),range(0,MAX_RPC_BOOKMARK_LENGTH)] */
		uint32_t flags;
	} in;

	struct {
		struct policy_handle *handle;/* [ref] */
		struct policy_handle *control;/* [ref] */
		uint32_t *queryChannelInfoSize;/* [ref] */
		struct eventlog6_EvtRpcQueryChannelInfo **queryChannelInfo;/* [size_is(,*queryChannelInfoSize),range(0,MAX_RPC_QUERY_CHANNEL_SIZE),ref] */
		struct eventlog6_RpcInfo *error;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcRemoteSubscriptionNextAsync {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t numRequestedRecords;
		uint32_t flags;
	} in;

	struct {
		uint32_t *numActualRecords;/* [ref] */
		uint32_t **eventDataIndices;/* [range(0,MAX_RPC_RECORD_COUNT),size_is(,*numActualRecords),ref] */
		uint32_t **eventDataSizes;/* [size_is(,*numActualRecords),range(0,MAX_RPC_RECORD_COUNT),ref] */
		uint32_t *resultBufferSize;/* [ref] */
		uint8_t **resultBuffer;/* [ref,size_is(,*resultBufferSize),range(0,MAX_RPC_BATCH_SIZE)] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcRemoteSubscriptionNext {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t numRequestedRecords;
		uint32_t timeOut;
		uint32_t flags;
	} in;

	struct {
		uint32_t *numActualRecords;/* [ref] */
		uint32_t **eventDataIndices;/* [ref,range(0,MAX_RPC_RECORD_COUNT),size_is(,*numActualRecords)] */
		uint32_t **eventDataSizes;/* [range(0,MAX_RPC_RECORD_COUNT),size_is(,*numActualRecords),ref] */
		uint32_t *resultBufferSize;/* [ref] */
		uint8_t **resultBuffer;/* [size_is(,*resultBufferSize),range(0,MAX_RPC_BATCH_SIZE),ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcRemoteSubscriptionWaitAsync {
	struct {
		struct policy_handle *handle;/* [ref] */
	} in;

	struct {
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcRegisterControllableOperation {
	struct {
		struct policy_handle *handle;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcRegisterLogQuery {
	struct {
		const char *path;/* [range(0,MAX_RPC_CHANNEL_PATH_LENGTH),charset(UTF16),unique] */
		const char *query;/* [range(1,MAX_RPC_QUERY_LENGTH),charset(UTF16),ref] */
		uint32_t flags;
	} in;

	struct {
		struct policy_handle *handle;/* [ref] */
		struct policy_handle *opControl;/* [ref] */
		uint32_t *queryChannelInfoSize;/* [ref] */
		struct eventlog6_EvtRpcQueryChannelInfo **queryChannelInfo;/* [range(0,MAX_RPC_QUERY_CHANNEL_SIZE),size_is(,*queryChannelInfoSize),ref] */
		struct eventlog6_RpcInfo *error;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcClearLog {
	struct {
		struct policy_handle *control;/* [ref] */
		const char *channelPath;/* [charset(UTF16),ref,range(0,MAX_RPC_CHANNEL_NAME_LENGTH)] */
		const char *backupPath;/* [charset(UTF16),unique,range(0,MAX_RPC_FILE_PATH_LENGTH)] */
		uint32_t flags;
	} in;

	struct {
		struct eventlog6_RpcInfo *error;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcExportLog {
	struct {
		struct policy_handle *control;/* [ref] */
		const char *channelPath;/* [range(0,MAX_RPC_CHANNEL_NAME_LENGTH),charset(UTF16),unique] */
		const char *query;/* [range(1,MAX_RPC_QUERY_LENGTH),ref,charset(UTF16)] */
		const char *backupPath;/* [range(1,MAX_RPC_FILE_PATH_LENGTH),ref,charset(UTF16)] */
		uint32_t flags;
	} in;

	struct {
		struct eventlog6_RpcInfo *error;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcLocalizeExportLog {
	struct {
		struct policy_handle *control;/* [ref] */
		const char *logFilePath;/* [ref,charset(UTF16),range(1,MAX_RPC_FILE_PATH_LENGTH)] */
		uint32_t locale;
		uint32_t flags;
	} in;

	struct {
		struct eventlog6_RpcInfo *error;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcMessageRender {
	struct {
		struct policy_handle *pubCfgObj;/* [ref] */
		uint32_t sizeEventId;/* [range(1,MAX_RPC_EVENT_ID_SIZE)] */
		uint8_t *eventId;/* [ref,size_is(sizeEventId)] */
		uint32_t messageId;
		struct eventlog6_EvtRpcVariantList *values;/* [ref] */
		uint32_t flags;
		uint32_t maxSizeString;
	} in;

	struct {
		uint32_t *actualSizeString;/* [ref] */
		uint32_t *neededSizeString;/* [ref] */
		uint8_t **string;/* [ref,range(0,MAX_RPC_RENDERED_STRING_SIZE),size_is(,*actualSizeString)] */
		struct eventlog6_RpcInfo *error;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcMessageRenderDefault {
	struct {
		uint32_t sizeEventId;/* [range(1,MAX_RPC_EVENT_ID_SIZE)] */
		uint8_t *eventId;/* [size_is(sizeEventId),ref] */
		uint32_t messageId;
		struct eventlog6_EvtRpcVariantList *values;/* [ref] */
		uint32_t flags;
		uint32_t maxSizeString;
	} in;

	struct {
		uint32_t *actualSizeString;/* [ref] */
		uint32_t *neededSizeString;/* [ref] */
		uint8_t **string;/* [ref,size_is(,*actualSizeString),range(0,MAX_RPC_RENDERED_STRING_SIZE)] */
		struct eventlog6_RpcInfo *error;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcQueryNext {
	struct {
		struct policy_handle *logQuery;/* [ref] */
		uint32_t numRequestedRecords;
		uint32_t timeOutEnd;
		uint32_t flags;
	} in;

	struct {
		uint32_t *numActualRecords;/* [ref] */
		uint32_t **eventDataIndices;/* [ref,size_is(,*numActualRecords),range(0,MAX_RPC_RECORD_COUNT)] */
		uint32_t **eventDataSizes;/* [ref,range(0,MAX_RPC_RECORD_COUNT),size_is(,*numActualRecords)] */
		uint32_t *resultBufferSize;/* [ref] */
		uint8_t **resultBuffer;/* [ref,range(0,MAX_RPC_BATCH_SIZE),size_is(,*resultBufferSize)] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcQuerySeek {
	struct {
		struct policy_handle *logQuery;/* [ref] */
		uint64_t pos;
		const char *bookmarkXml;/* [charset(UTF16),unique,range(0,MAX_RPC_BOOKMARK_LENGTH)] */
		uint32_t timeOut;
		uint32_t flags;
	} in;

	struct {
		struct eventlog6_RpcInfo *error;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcClose {
	struct {
		struct policy_handle **handle;/* [ref] */
	} in;

	struct {
		struct policy_handle **handle;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcCancel {
	struct {
		struct policy_handle *handle;/* [ref] */
	} in;

	struct {
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcAssertConfig {
	struct {
		const char *path;/* [range(1,MAX_RPC_CHANNEL_NAME_LENGTH),charset(UTF16),ref] */
		uint32_t flags;
	} in;

	struct {
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcRetractConfig {
	struct {
		const char *path;/* [range(1,MAX_RPC_CHANNEL_NAME_LENGTH),charset(UTF16),ref] */
		uint32_t flags;
	} in;

	struct {
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcOpenLogHandle {
	struct {
		const char *channel;/* [ref,charset(UTF16),range(1,MAX_RPC_CHANNEL_NAME_LENGTH)] */
		uint32_t flags;
	} in;

	struct {
		struct policy_handle *handle;/* [ref] */
		struct eventlog6_RpcInfo *error;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcGetLogFileInfo {
	struct {
		struct policy_handle *logHandle;/* [ref] */
		uint32_t propertyId;
		uint32_t propertyValueBufferSize;/* [range(0,MAX_RPC_PROPERTY_BUFFER_SIZE)] */
	} in;

	struct {
		uint8_t *propertyValueBuffer;/* [ref,size_is(propertyValueBufferSize)] */
		uint32_t *propertyValueBufferLength;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcGetChannelList {
	struct {
		uint32_t flags;
	} in;

	struct {
		uint32_t *numChannelPaths;/* [ref] */
		const char ***channelPaths;/* [charset(UTF16),ref,size_is(,*numChannelPaths),range(0,MAX_RPC_CHANNEL_COUNT)] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcGetChannelConfig {
	struct {
		const char *channelPath;/* [ref,charset(UTF16),range(1,MAX_RPC_CHANNEL_NAME_LENGTH)] */
		uint32_t flags;
	} in;

	struct {
		struct eventlog6_EvtRpcVariantList *props;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcPutChannelConfig {
	struct {
		const char *channelPath;/* [ref,charset(UTF16),range(1,MAX_RPC_CHANNEL_NAME_LENGTH)] */
		uint32_t flags;
		struct eventlog6_EvtRpcVariantList *props;/* [ref] */
	} in;

	struct {
		struct eventlog6_RpcInfo *error;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcGetPublisherList {
	struct {
		uint32_t flags;
	} in;

	struct {
		uint32_t *numPublisherIds;/* [ref] */
		const char ***publisherIds;/* [charset(UTF16),ref,size_is(,*numPublisherIds),range(0,MAX_RPC_PUBLISHER_COUNT)] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcGetPublisherListForChannel {
	struct {
		uint16_t *channelName;/* [ref] */
		uint32_t flags;
	} in;

	struct {
		uint32_t *numPublisherIds;/* [ref] */
		const char ***publisherIds;/* [range(0,MAX_RPC_PUBLISHER_COUNT),size_is(,*numPublisherIds),charset(UTF16),ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcGetPublisherMetadata {
	struct {
		const char *publisherId;/* [range(0,MAX_RPC_PUBLISHER_ID_LENGTH),charset(UTF16),unique] */
		const char *logFilePath;/* [charset(UTF16),unique,range(0,MAX_RPC_FILE_PATH_LENGTH)] */
		uint32_t locale;
		uint32_t flags;
	} in;

	struct {
		struct eventlog6_EvtRpcVariantList *pubMetadataProps;/* [ref] */
		struct policy_handle *pubMetadata;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcGetPublisherResourceMetadata {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t propertyId;
		uint32_t flags;
	} in;

	struct {
		struct eventlog6_EvtRpcVariantList *pubMetadataProps;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcGetEventMetadataEnum {
	struct {
		struct policy_handle *pubMetadata;/* [ref] */
		uint32_t flags;
		const char *reservedForFilter;/* [unique,charset(UTF16),range(0,MAX_RPC_FILTER_LENGTH)] */
	} in;

	struct {
		struct policy_handle *eventMetaDataEnum;/* [ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcGetNextEventMetadata {
	struct {
		struct policy_handle *eventMetaDataEnum;/* [ref] */
		uint32_t flags;
		uint32_t numRequested;
	} in;

	struct {
		uint32_t *numReturned;/* [ref] */
		struct eventlog6_EvtRpcVariantList **eventMetadataInstances;/* [range(0,MAX_RPC_EVENT_METADATA_COUNT),size_is(,*numReturned),ref] */
		WERROR result;
	} out;

};


struct eventlog6_EvtRpcGetClassicLogDisplayName {
	struct {
		const char *logName;/* [range(1,MAX_RPC_CHANNEL_NAME_LENGTH),ref,charset(UTF16)] */
		uint32_t locale;
		uint32_t flags;
	} in;

	struct {
		uint16_t **displayName;/* [ref] */
		WERROR result;
	} out;

};

#endif /* _HEADER_eventlog6 */
#endif /* _PIDL_HEADER_eventlog6 */