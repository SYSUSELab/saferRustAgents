# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/default/app_verify_default.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 389 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/default/app_verify_default.c" 2
# 16 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/default/app_verify_default.c"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/default/app_verify_default.h" 1
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/default/app_verify_default.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_verify_hal.h" 1
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_verify_hal.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdint.h" 1
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdint.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 116 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned int uintptr_t;
# 131 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef int intptr_t;
# 147 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef signed char int8_t;




typedef signed short int16_t;




typedef signed int int32_t;




typedef signed long long int64_t;




typedef signed long long intmax_t;




typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef unsigned int uint32_t;




typedef unsigned long long uint64_t;
# 197 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned long long uintmax_t;
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdint.h" 2

typedef int8_t int_fast8_t;
typedef int64_t int_fast64_t;

typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef uint8_t uint_fast8_t;
typedef uint64_t uint_fast64_t;

typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;
# 95 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdint.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/stdint.h" 1
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 96 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdint.h" 2
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_verify_hal.h" 2
# 29 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_verify_hal.h"
typedef int32_t (*GetDeviceUdid)(unsigned char *udid, int32_t size);

typedef struct {
    GetDeviceUdid devUdidFunc;
} ProductDiff;

void RegistHalFunc();
int32_t InquiryDeviceUdid(unsigned char *udid, int32_t size);
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/default/app_verify_default.h" 2







void RegistBaseDefaultFunc(ProductDiff *productFunc);
# 17 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/default/app_verify_default.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_verify_pub.h" 1
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_verify_pub.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdbool.h" 1
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_verify_pub.h" 2








typedef enum {
    V_OK = 0,


    V_ERR_GET_CERT_INFO = 0xef000002,
    V_ERR_UNTRUSTED_CERT = 0xef000003,
    V_ERR_INTEGRITY = 0xef000004,
    V_ERR_GET_SIGNHEAD = 0xef000005,
    V_ERR_GET_SIGN_BLOCK = 0xef000006,
    V_ERR_GET_HASH_DIFF = 0xef000007,
    V_ERR_INVALID_CONTENT_TAG = 0xef000008,
    V_ERR_INVALID_HASH_ALG = 0xef000009,
    V_ERR_GET_ROOT_HASH = 0xef00000a,
    V_ERR_CALC_BLOCK_HASH = 0xef00000c,
    V_ERR_PARSE_PKC7_DATA = 0xef00000d,
    V_ERR_VERIFY_CERT_CHAIN = 0xef00000e,
    V_ERR_VERIFY_SIGNATURE = 0xef00000f,
    V_ERR_GET_CERT_TYPE = 0xef000010,


    V_ERR_GET_PROFILE_DATA = 0xef000011,
    V_ERR_GET_PARSE_PROFILE = 0xef000012,
    V_ERR_PROF_CONTENT_INVALID = 0xef000013,
    V_ERR_VERFIY_PROF_CERT = 0xef000014,
    V_ERR_GET_CERT_PK = 0xef000015,
    V_ERR_GET_APPID = 0xef000016,
    V_ERR_INVALID_DISP_TYPE = 0xef000017,
    V_ERR_INVALID_APP_BUNDLE = 0xef000018,
    V_ERR_INVALID_DATE = 0xef000019,
    V_ERR_INVALID_DEVID = 0xef00001a,


    V_ERR_FILE_OPEN = 0xef00001b,
    V_ERR_FILE_STAT = 0xef00001c,
    V_ERR_FILE_LENGTH = 0xef00001d,


    V_ERR_MEMSET = 0xef00001e,
    V_ERR_MEMCPY = 0xef00001f,
    V_ERR_MALLOC = 0xef000020,


    V_ERR = 0xffffffff,
} AppVErrCode;

typedef struct {
    int32_t notBefore;
    int32_t notAfter;
} ProfValidity;

typedef struct {
    char *developerId;
    unsigned char *devCert;
    unsigned char *releaseCert;
    char *bundleName;
    char *appFeature;
} ProfBundleInfo;

typedef struct {
    int32_t restricNum;
    char **restricPermission;
    int32_t permissionNum;
    char **permission;
} ProfPermission;

typedef struct {
    char *devIdType;
    int32_t devidNum;
    char **deviceId;
} ProfDebugInfo;

typedef struct {
    int32_t versionCode;
    char *versionName;
    char *uuid;
    char *type;
    char *appDistType;
    ProfValidity validity;
    ProfBundleInfo bundleInfo;
    ProfPermission permission;
    ProfDebugInfo debugInfo;
    char *issuer;
    char *appid;
} ProfileProf;

typedef struct {
    char *pk;
    int32_t len;
} AppSignPk;

struct VfyRst;
typedef int32_t (*GetSignPk)(struct VfyRst *verifyRst, AppSignPk *pk);
typedef void (*FreeSignPK)(AppSignPk *pk);
typedef int32_t (*MessageFunc)(unsigned char operationResult, const char *bundleName, unsigned char errCode);

typedef struct VfyRst {
    ProfileProf profile;
} VerifyResult;


int32_t APPVERI_AppVerify(const char *filePath, VerifyResult *verifyRst);


void APPVERI_FreeVerifyRst(VerifyResult *verifyRst);


int32_t APPVERI_SetDebugMode(_Bool mode);


int32_t APPVERI_GetUnsignedFileLength(const char *filePath);


void APPVERI_RegisterMsgFunc(MessageFunc messageFunc);
void APPVERI_SetActsMode(_Bool mode);
int32_t APPVERI_IsActsMode(void);
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/default/app_verify_default.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/startup/init/interfaces/innerkits/include/syspara/parameter.h" 1
# 32 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/startup/init/interfaces/innerkits/include/syspara/parameter.h"
static const char EMPTY_STR[] = { "" };
# 52 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/startup/init/interfaces/innerkits/include/syspara/parameter.h"
int GetParameter(const char *key, const char *def, char *value, uint32_t len);
# 69 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/startup/init/interfaces/innerkits/include/syspara/parameter.h"
int SetParameter(const char *key, const char *value);
# 90 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/startup/init/interfaces/innerkits/include/syspara/parameter.h"
int WaitParameter(const char *key, const char *value, int timeout);
# 106 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/startup/init/interfaces/innerkits/include/syspara/parameter.h"
typedef void (*ParameterChgPtr)(const char *key, const char *value, void *context);
int WatchParameter(const char *keyPrefix, ParameterChgPtr callback, void *context);
# 123 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/startup/init/interfaces/innerkits/include/syspara/parameter.h"
int RemoveParameterWatcher(const char *keyPrefix, ParameterChgPtr callback, void *context);
# 135 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/startup/init/interfaces/innerkits/include/syspara/parameter.h"
int SaveParameters(void);
const char *GetSecurityPatchTag(void);
const char *GetOSFullName(void);
const char *GetVersionId(void);
const char *GetBuildRootHash(void);
const char *GetOsReleaseType(void);
int GetSdkApiVersion(void);

const char *GetDeviceType(void);
const char *GetProductModel(void);
const char *GetManufacture(void);
const char *GetBrand(void);
const char *GetMarketName(void);
const char *GetProductSeries(void);
const char *GetSoftwareModel(void);
const char *GetHardwareModel(void);
const char *GetHardwareProfile(void);
const char *GetSerial(void);
const char *GetAbiList(void);
const char *GetDisplayVersion(void);
const char *GetIncrementalVersion(void);
const char *GetBootloaderVersion(void);
const char *GetBuildType(void);
const char *GetBuildUser(void);
const char *GetBuildHost(void);
const char *GetBuildTime(void);
int GetFirstApiVersion(void);
int GetDevUdid(char *udid, int size);

const char *AclGetSerial(void);
int AclGetDevUdid(char *udid, int size);
# 178 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/startup/init/interfaces/innerkits/include/syspara/parameter.h"
uint32_t FindParameter(const char *key);
uint32_t GetParameterCommitId(uint32_t handle);
int GetParameterName(uint32_t handle, char *key, uint32_t len);
int GetParameterValue(uint32_t handle, char *value, uint32_t len);
long long GetSystemCommitId(void);

int32_t GetIntParameter(const char *key, int32_t def);
uint32_t GetUintParameter(const char *key, uint32_t def);

const char *GetDistributionOSName(void);
const char *GetDistributionOSVersion(void);
int GetDistributionOSApiVersion(void);
const char *GetDistributionOSApiName(void);
const char *GetDistributionOSReleaseType(void);
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/default/app_verify_default.c" 2

static int32_t GetUdid(unsigned char *udid, int32_t size)
{
    int32_t ret = GetDevUdid((char *)udid, size);
    return ret;
}

void RegistBaseDefaultFunc(ProductDiff *productFunc)
{
    productFunc->devUdidFunc = GetUdid;
}
