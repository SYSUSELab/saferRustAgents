# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/app_file.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 389 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/app_file.c" 2
# 16 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/app_file.c"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_file.h" 1
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_file.h"
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
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_file.h" 2
# 29 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_file.h"
enum ReadFileErrorCode {
    DEST_BUFFER_IS_NULL = -1,
    FILE_IS_CLOSE = -2,
    MMAP_COPY_FAILED = -3,
    READ_OFFSET_OUT_OF_RANGE = -4,
    MMAP_FAILED = -5,
    MMAP_PARAM_INVALID = -6,
};

typedef struct {
    int32_t mmapPosition;
    int32_t readMoreLen;
    int32_t mmapSize;
    char* mapAddr;
} MmapInfo;

typedef struct {
    int32_t fp;
    int32_t offset;
    int32_t len;
} FileRead;

int32_t InitVerify(FileRead *file, const char *filePath, int32_t *handle);
int32_t HapMMap(int32_t bufCapacity, int32_t offset, MmapInfo *mmapInfo, const FileRead *file);
void HapMUnMap(char *mapAddr, int32_t mmapSize);
# 17 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/app_file.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/fcntl.h" 1







# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/features.h" 1
# 9 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/fcntl.h" 2
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/fcntl.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 75 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned int size_t;
# 126 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef int ssize_t;
# 203 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned mode_t;
# 213 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef long long off_t;
typedef long long loff_t;
typedef off_t off64_t;
# 294 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef int pid_t;
# 370 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
struct iovec { void *iov_base; size_t iov_len; };
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/fcntl.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/fcntl.h" 1
# 23 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/fcntl.h" 2

struct flock {
 short l_type;
 short l_whence;
 off_t l_start;
 off_t l_len;
 pid_t l_pid;
};

int creat(const char *, mode_t);
int fcntl(int, int, ...);
int fcntl64(int, int, ...);
int open(const char *, int, ...);
int openat(int, const char *, int, ...);
int posix_fadvise(int, off_t, off_t, int);
int posix_fallocate(int, off_t, off_t);
# 168 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/fcntl.h"
struct f_owner_ex {
 int type;
 pid_t pid;
};
# 182 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/fcntl.h"
int fallocate(int, int, off_t, off_t);
int fallocate64(int, int, off64_t, off64_t);
ssize_t readahead(int, off_t, size_t);
int sync_file_range(int, off_t, off_t, unsigned);
ssize_t vmsplice(int, const struct iovec *, size_t, unsigned);
ssize_t splice(int, off_t *, int, off_t *, size_t, unsigned);
ssize_t tee(int, int, size_t, unsigned);
# 201 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/fcntl.h"
int open64(const char *, int, ...);
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/app_file.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/limits.h" 1





# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 7 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/limits.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/common/los_config.h" 1
# 39 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/common/los_config.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 1
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_err.h" 1
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_err.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h" 1
# 39 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stddef.h" 1
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stddef.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned wchar_t;
# 59 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef struct { long long __ll; long double __ld; } max_align_t;
# 121 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef int ptrdiff_t;
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stddef.h" 2
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdbool.h" 1
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_builddef.h" 1
# 43 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_toolchain.h" 1
# 44 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h" 2
# 55 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h"
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef signed char INT8;
typedef signed short INT16;
typedef signed int INT32;
typedef float FLOAT;
typedef double DOUBLE;
typedef char CHAR;







typedef unsigned long long UINT64;
typedef signed long long INT64;
typedef unsigned int UINTPTR;
typedef signed int INTPTR;
# 83 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h"
typedef INT32 ssize_t;
typedef UINT32 size_t;


typedef UINTPTR AARCHPTR;
typedef size_t BOOL;
# 205 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h"
typedef int status_t;
typedef unsigned long vaddr_t;
typedef unsigned long PADDR_T;
typedef unsigned long VADDR_T;
typedef unsigned long paddr_t;
typedef unsigned long DMA_ADDR_T;
typedef unsigned long ADDR_T;
typedef unsigned long VM_OFFSET_T;
typedef unsigned long PTE_T;
typedef unsigned int ULONG_T;
typedef int STATUS_T;
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_err.h" 2
# 70 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_err.h"
typedef void (*LOS_ERRORHANDLE_FUNC)(CHAR *fileName,
                                     UINT32 lineNo,
                                     UINT32 errorNo,
                                     UINT32 paraLen,
                                     void *para);
# 98 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_err.h"
extern UINT32 LOS_ErrHandle(CHAR *fileName, UINT32 lineNo,
                            UINT32 errorNo, UINT32 paraLen,
                            void *para);







extern void LOS_SetErrHandleHook(LOS_ERRORHANDLE_FUNC fun);

enum LOS_MOUDLE_ID {
    LOS_MOD_SYS = 0x0,
    LOS_MOD_MEM = 0x1,
    LOS_MOD_TSK = 0x2,
    LOS_MOD_SWTMR = 0x3,
    LOS_MOD_TICK = 0x4,
    LOS_MOD_MSG = 0x5,
    LOS_MOD_QUE = 0x6,
    LOS_MOD_SEM = 0x7,
    LOS_MOD_MBOX = 0x8,
    LOS_MOD_HWI = 0x9,
    LOS_MOD_HWWDG = 0xa,
    LOS_MOD_CACHE = 0xb,
    LOS_MOD_HWTMR = 0xc,
    LOS_MOD_MMU = 0xd,

    LOS_MOD_LOG = 0xe,
    LOS_MOD_ERR = 0xf,

    LOS_MOD_EXC = 0x10,
    LOS_MOD_CSTK = 0x11,

    LOS_MOD_MPU = 0x12,
    LOS_MOD_NMHWI = 0x13,
    LOS_MOD_TRACE = 0x14,
    LOS_MOD_KNLSTAT = 0x15,
    LOS_MOD_EVTTIME = 0x16,
    LOS_MOD_THRDCPUP = 0x17,
    LOS_MOD_IPC = 0x18,
    LOS_MOD_STKMON = 0x19,
    LOS_MOD_TIMER = 0x1a,
    LOS_MOD_RESLEAKMON = 0x1b,
    LOS_MOD_EVENT = 0x1c,
    LOS_MOD_MUX = 0X1d,
    LOS_MOD_CPUP = 0x1e,
    LOS_MOD_HOOK = 0x1f,
    LOS_MOD_PERF = 0x20,
    LOS_MOD_PM = 0x21,
    LOS_MOD_SHELL = 0x31,
    LOS_MOD_DRIVER = 0x41,
    LOS_MOD_BUTT
};
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_errno.h" 1
# 42 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/arch/arm/arm/include/hal_timer.h" 1
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/arch/arm/arm/include/hal_timer.h"
extern UINT32 HalClockFreqRead(void);
extern void HalClockFreqWrite(UINT32 freq);
extern void HalClockStart(void);
extern void HalClockIrqClear(void);
extern void HalClockInit(void);
extern UINT64 HalClockGetCycles(void);
extern void HalDelayUs(UINT32 usecs);
extern UINT32 HalClockGetTickTimerCycles(void);
extern UINT64 HalClockTickTimerReload(UINT64 cycles);

extern UINT32 HrtimersInit(void);
extern void HrtimerClockIrqClear(void);
extern void HrtimerClockStart(UINT32 period);
extern void HrtimerClockStop(void);
extern UINT32 HrtimerClockValueGet(void);
extern void HrtimerClockInit(void);
# 43 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 2
# 86 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h"
extern UINT32 g_sysClock;





extern UINT32 g_tickPerSecond;
# 115 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h"
extern void LOS_GetCpuCycle(UINT32 *puwCntHi, UINT32 *puwCntLo);
# 134 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h"
extern UINT64 LOS_CurrNanosec(void);
# 153 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h"
extern void LOS_Udelay(UINT32 usecs);
# 172 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h"
extern void LOS_Mdelay(UINT32 usecs);
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/common/los_config.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/base/include/los_vm_zone.h" 1
# 35 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/base/include/los_vm_zone.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/device/board/hisilicon/hispark_taurus/liteos_a/board/target_config.h" 1
# 36 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/base/include/los_vm_zone.h" 2
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/common/los_config.h" 2
# 52 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/common/los_config.h"
extern CHAR __int_stack_start;
extern CHAR __rodata_start;
extern CHAR __rodata_end;
extern CHAR __bss_start;
extern CHAR __bss_end;
extern CHAR __text_start;
extern CHAR __text_end;
extern CHAR __ram_data_start;
extern CHAR __ram_data_end;
extern UINT32 __heap_start;
extern UINT32 __heap_end;
# 474 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/common/los_config.h"
extern UINT32 OsMain(void);

typedef void (*SystemRebootFunc)(void);
void OsSetRebootHook(SystemRebootFunc func);
SystemRebootFunc OsGetRebootHook(void);
# 9 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/limits.h" 2
# 73 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/limits.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/limits.h" 1
# 74 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/limits.h" 2
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/app_file.c" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/string.h" 1
# 25 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/string.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 345 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef struct __locale_struct *locale_t;
# 26 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/string.h" 2

void *memcpy (void *restrict, const void *restrict, size_t);
void *memmove (void *, const void *, size_t);
void *memset (void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void *memchr (const void *, int, size_t);

char *strcpy (char *restrict, const char *restrict);
char *strncpy (char *restrict, const char *restrict, size_t);

char *strcat (char *restrict, const char *restrict);
char *strncat (char *restrict, const char *restrict, size_t);

int strcmp (const char *, const char *);
int strncmp (const char *, const char *, size_t);

int strcoll (const char *, const char *);
size_t strxfrm (char *restrict, const char *restrict, size_t);

char *strchr (const char *, int);
char *strrchr (const char *, int);

size_t strcspn (const char *, const char *);
size_t strspn (const char *, const char *);
char *strpbrk (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *restrict, const char *restrict);

size_t strlen (const char *);

char *strerror (int);


# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/strings.h" 1
# 11 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/strings.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 12 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/strings.h" 2




int bcmp (const void *, const void *, size_t);
void bcopy (const void *, void *, size_t);
void bzero (void *, size_t);



int ffs (int);
int ffsl (long);
int ffsll (long long);


int strcasecmp (const char *, const char *);
int strncasecmp (const char *, const char *, size_t);

int strcasecmp_l (const char *, const char *, locale_t);
int strncasecmp_l (const char *, const char *, size_t, locale_t);
# 60 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/string.h" 2





char *strtok_r (char *restrict, const char *restrict, char **restrict);
int strerror_r (int, char *, size_t);
char *stpcpy(char *restrict, const char *restrict);
char *stpncpy(char *restrict, const char *restrict, size_t);
size_t strnlen (const char *, size_t);
char *strdup (const char *);
char *strndup (const char *, size_t);
char *strsignal(int);
char *strerror_l (int, locale_t);
int strcoll_l (const char *, const char *, locale_t);
size_t strxfrm_l (char *restrict, const char *restrict, size_t, locale_t);




void *memccpy (void *restrict, const void *restrict, int, size_t);



char *strsep(char **, const char *);
size_t strlcat (char *, const char *, size_t);
size_t strlcpy (char *, const char *, size_t);
void explicit_bzero (void *, size_t);




int strverscmp (const char *, const char *);
char *strchrnul(const char *, int);
char *strcasestr(const char *, const char *);
void *memmem(const void *, size_t, const void *, size_t);
void *memrchr(const void *, int, size_t);
void *mempcpy(void *, const void *, size_t);

char *basename(const char *);
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/app_file.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/mman.h" 1
# 17 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/mman.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/mman.h" 2
# 117 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/mman.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/mman.h" 1
# 118 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/mman.h" 2

void *mmap (void *, size_t, int, int, int, off_t);
int munmap (void *, size_t);

int mprotect (void *, size_t, int);
int msync (void *, size_t, int);

int posix_madvise (void *, size_t, int);

int mlock (const void *, size_t);
int munlock (const void *, size_t);
int mlockall (int);
int munlockall (void);


void *mremap (void *, size_t, size_t, int, ...);
int remap_file_pages (void *, size_t, int, size_t, int);
int memfd_create (const char *, unsigned);
int mlock2 (const void *, size_t, unsigned);



int madvise (void *, size_t, int);
int mincore (void *, size_t, unsigned char *);


int shm_open (const char *, int, mode_t);
int shm_unlink (const char *);
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/app_file.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/stat.h" 1
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/stat.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 65 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef long long time_t;
# 208 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned int nlink_t;
# 220 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned long long ino_t;




typedef unsigned long long dev_t;




typedef long blksize_t;




typedef long long blkcnt_t;
# 285 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
struct timespec { time_t tv_sec; long tv_nsec; };

struct timespec64 { long long tv_sec; long long tv_nsec; };
# 304 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned uid_t;




typedef unsigned gid_t;
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/stat.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/stat.h" 1



struct stat {
 dev_t st_dev;
 int __st_dev_padding;
 long __st_ino_truncated;
 mode_t st_mode;
 nlink_t st_nlink;
 uid_t st_uid;
 gid_t st_gid;
 dev_t st_rdev;
 int __st_rdev_padding;
 off_t st_size;
 blksize_t st_blksize;
 blkcnt_t st_blocks;
 struct {
  long tv_sec;
  long tv_nsec;
 } __st_atim32, __st_mtim32, __st_ctim32;
 ino_t st_ino;
 struct timespec st_atim;
 struct timespec st_mtim;
 struct timespec st_ctim;
};






# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 33 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/stat.h" 2
struct statx {
 uint32_t stx_mask;
 uint32_t stx_blksize;
 uint64_t stx_attributes;
 uint32_t stx_nlink;
 uint32_t stx_uid;
 uint32_t stx_gid;
 uint16_t stx_mode;
 uint16_t pad1;
 uint64_t stx_ino;
 uint64_t stx_size;
 uint64_t stx_blocks;
 uint64_t stx_attributes_mask;
 struct {
  int64_t tv_sec;
  uint32_t tv_nsec;
  int32_t pad;
 } stx_atime, stx_btime, stx_ctime, stx_mtime;
 uint32_t stx_rdev_major;
 uint32_t stx_rdev_minor;
 uint32_t stx_dev_major;
 uint32_t stx_dev_minor;
 uint64_t spare[14];
};
# 24 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/stat.h" 2
# 73 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/stat.h"
int stat(const char *restrict, struct stat *restrict);
int fstat(int, struct stat *);
int lstat(const char *restrict, struct stat *restrict);
int fstatat(int, const char *restrict, struct stat *restrict, int);
int chmod(const char *, mode_t);
int fchmod(int, mode_t);
int fchmodat(int, const char *, mode_t, int);
mode_t umask(mode_t);
int mkdir(const char *, mode_t);
int mkfifo(const char *, mode_t);
int mkdirat(int, const char *, mode_t);
int mkfifoat(int, const char *, mode_t);


int mknod(const char *, mode_t, dev_t);
int mknodat(int, const char *, mode_t, dev_t);


int futimens(int, const struct timespec [2]);
int utimensat(int, const char *, const struct timespec [2], int);


int lchmod(const char *, mode_t);







int fstat64(int, struct stat *);
# 23 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/app_file.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/types.h" 1
# 54 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/types.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 70 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef long long suseconds_t;
# 86 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef struct cpu_set_t { unsigned long __bits[32/(8 * sizeof(unsigned long int))]; } cpu_set_t;




struct sched_param {
  int sched_priority;
};




typedef struct __pthread_attr_s {
  unsigned int detachstate;
  unsigned int schedpolicy;
  struct sched_param schedparam;
  unsigned int inheritsched;
  unsigned int scope;
  unsigned int stackaddr_set;
  void* stackaddr;
  unsigned int stacksize_set;
  size_t stacksize;



} pthread_attr_t;
# 141 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef int register_t;
# 192 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned long long u_int64_t;
# 240 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned long long fsblkcnt_t;




typedef unsigned long long fsfilcnt_t;
# 262 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef void * timer_t;




typedef int clockid_t;




typedef long clock_t;
# 299 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned id_t;
# 314 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef int key_t;




typedef unsigned useconds_t;





typedef long pthread_t;




typedef int pthread_once_t;




typedef int pthread_key_t;




typedef int pthread_condattr_t;
# 55 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/types.h" 2


typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned u_int32_t;
typedef char *caddr_t;
typedef unsigned char u_char;
typedef unsigned short u_short, ushort;
typedef unsigned u_int, uint;
typedef unsigned long u_long, ulong;
typedef long long quad_t;
typedef unsigned long long u_quad_t;
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/endian.h" 1
# 10 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/endian.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 11 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/endian.h" 2
# 23 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/endian.h"
static inline uint16_t __bswap16(uint16_t __x)
{
 return __x<<8 | __x>>8;
}

static inline uint32_t __bswap32(uint32_t __x)
{
 return __x>>24 | __x>>8&0xff00 | __x<<8&0xff0000 | __x<<24;
}

static inline uint64_t __bswap64(uint64_t __x)
{
 return __bswap32(__x)+0ULL<<32 | __bswap32(__x>>32);
}
# 84 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/endian.h"
static inline uint32_t
be32dec(const void *pp)
{
    uint8_t const *p = (uint8_t const *)pp;

    return (((unsigned)p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3]);
}

static inline void
be32enc(void *pp, uint32_t u)
{
    uint8_t *p = (uint8_t *)pp;

    p[0] = (u >> 24) & 0xff;
    p[1] = (u >> 16) & 0xff;
    p[2] = (u >> 8) & 0xff;
    p[3] = u & 0xff;
}

static inline void
be64enc(void *pp, uint64_t u)
{
    uint8_t *p = (uint8_t *)pp;

    be32enc(p, (uint32_t)(u >> 32));
    be32enc(p + 4, (uint32_t)(u & 0xffffffffU));
}
# 68 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/types.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/select.h" 1
# 16 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/select.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 277 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
struct timeval { time_t tv_sec; suseconds_t tv_usec; };

struct timeval64 { long long tv_sec; long long tv_usec; };
# 365 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned long long sigset_t;
# 17 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/select.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 1
# 31 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 32 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 2
# 48 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h"
typedef struct sigaltstack stack_t;



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/signal.h" 1
# 10 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/signal.h"
typedef int greg_t, gregset_t[18];
typedef struct sigcontext {
 unsigned long trap_no, error_code, oldmask;
 unsigned long arm_r0, arm_r1, arm_r2, arm_r3;
 unsigned long arm_r4, arm_r5, arm_r6, arm_r7;
 unsigned long arm_r8, arm_r9, arm_r10, arm_fp;
 unsigned long arm_ip, arm_sp, arm_lr, arm_pc;
 unsigned long arm_cpsr, fault_address;
} mcontext_t;






struct sigaltstack {
 void *ss_sp;
 int ss_flags;
 size_t ss_size;
};

typedef struct ucontext {
 unsigned long uc_flags;
 struct ucontext *uc_link;
 stack_t uc_stack;
 mcontext_t uc_mcontext;
 sigset_t uc_sigmask;
 unsigned long long uc_regspace[64];
} ucontext_t;
# 53 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 2
# 98 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h"
union sigval {
 int sival_int;
 void *sival_ptr;
};

typedef struct {
 int si_signo, si_errno, si_code;
 union {
  char __pad[128 - 2*sizeof(int) - sizeof(long)];
  struct {
   union {
    struct {
     pid_t si_pid;
     uid_t si_uid;
    } __piduid;
    struct {
     int si_timerid;
     int si_overrun;
    } __timer;
   } __first;
   union {
    union sigval si_value;
    struct {
     int si_status;
     clock_t si_utime, si_stime;
    } __sigchld;
   } __second;
  } __si_common;
 } __si_fields;
} siginfo_t;
# 137 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h"
struct sigaction {
 union {
  void (*sa_handler)(int);
  void (*sa_sigaction)(int, siginfo_t *, void *);
 } sa_sigactionhandler;
 sigset_t sa_mask;
 int sa_flags;
 void (*sa_restorer)(void);
};






struct sigevent {
 union sigval sigev_value;
 int sigev_signo;
 int sigev_notify;
 union {
  char __pad[64 - 2*sizeof(int) - sizeof(union sigval)];
  pid_t sigev_notify_thread_id;
  struct {
   void (*sigev_notify_function)(union sigval);
   pthread_attr_t *sigev_notify_attributes;
  } __sev_thread;
 } __sev_fields;
};
# 178 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h"
int pthread_sigmask(int, const sigset_t *, sigset_t *);
int sigfillset(sigset_t *);
int sigdelset(sigset_t *, int);



void (*sigset(int, void (*)(int)))(int);
# 204 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h"
typedef void (*sig_t)(int);






typedef void (*sighandler_t)(int);
void (*bsd_signal(int, void (*)(int)))(int);
# 222 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h"
typedef int sig_atomic_t;

void (*signal(int, void (*)(int)))(int);
int raise(int);
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/select.h" 2
# 27 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/select.h"
typedef unsigned long fd_mask;

typedef struct {
 unsigned long fds_bits[1024 / 8 / sizeof(long)];
} fd_set;






int select (int, fd_set *restrict, fd_set *restrict, fd_set *restrict, struct timeval *restrict);
int pselect (int, fd_set *restrict, fd_set *restrict, fd_set *restrict, const struct timespec *restrict, const sigset_t *restrict);
# 69 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/types.h" 2
# 24 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/app_file.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/unistd.h" 1
# 37 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/unistd.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 38 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/unistd.h" 2

int pipe(int [2]);
int pipe2(int [2], int);
int close(int);
int posix_close(int, int);
int dup(int);
int dup2(int, int);
int dup3(int, int, int);
off_t lseek(int, off_t, int);
int fsync(int);
int fdatasync(int);

ssize_t read(int, void *, size_t);
ssize_t write(int, const void *, size_t);
ssize_t pread(int, void *, size_t, off_t);
ssize_t pwrite(int, const void *, size_t, off_t);

int chown(const char *, uid_t, gid_t);
int fchown(int, uid_t, gid_t);
int lchown(const char *, uid_t, gid_t);
int fchownat(int, const char *, uid_t, gid_t, int);

int link(const char *, const char *);
int linkat(int, const char *, int, const char *, int);
int symlink(const char *, const char *);
int symlinkat(const char *, int, const char *);
ssize_t readlink(const char *restrict, char *restrict, size_t);
ssize_t readlinkat(int, const char *restrict, char *restrict, size_t);
int unlink(const char *);
int unlinkat(int, const char *, int);
int rmdir(const char *);
int truncate(const char *, off_t);
int ftruncate(int, off_t);






int access(const char *, int);
int faccessat(int, const char *, int, int);

int chdir(const char *);
int fchdir(int);
char *getcwd(char *, size_t);

unsigned alarm(unsigned);
unsigned sleep(unsigned);

pid_t fork(void);
pid_t _Fork(void);
int execve(const char *, char *const [], char *const []);
int execv(const char *, char *const []);
int execle(const char *, const char *, ...);
int execl(const char *, const char *, ...);
int execvp(const char *, char *const []);
int execlp(const char *, const char *, ...);
int fexecve(int, char *const [], char *const []);
_Noreturn void _exit(int);

pid_t getpid(void);
pid_t getppid(void);
pid_t getpgrp(void);
pid_t getpgid(pid_t);
int setpgid(pid_t, pid_t);
pid_t setsid(void);
pid_t getsid(pid_t);
char *ttyname(int);
int ttyname_r(int, char *, size_t);
int isatty(int);
pid_t tcgetpgrp(int);
int tcsetpgrp(int, pid_t);

uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);
int getgroups(int, gid_t []);
int setuid(uid_t);
int seteuid(uid_t);
int setgid(gid_t);
int setegid(gid_t);

char *getlogin(void);
int getlogin_r(char *, size_t);
int gethostname(char *, size_t);
char *ctermid(char *);

int getopt(int, char * const [], const char *);
extern char *optarg;
extern int optind, opterr, optopt;

long pathconf(const char *, int);
long fpathconf(int, int);
long sysconf(int);
size_t confstr(int, char *, size_t);






int setreuid(uid_t, uid_t);
int setregid(gid_t, gid_t);
int lockf(int, int, off_t);
long gethostid(void);
int nice(int);
void sync(void);
pid_t setpgrp(void);
char *crypt(const char *, const char *);
void encrypt(char *, int);
void swab(const void *restrict, void *restrict, ssize_t);




int usleep(unsigned);
unsigned ualarm(unsigned, unsigned);






int brk(void *);
void *sbrk(intptr_t);
pid_t vfork(void);
int vhangup(void);
int chroot(const char *);
int getpagesize(void);
int getdtablesize(void);
int sethostname(const char *, size_t);
int getdomainname(char *, size_t);
int setdomainname(const char *, size_t);
int setgroups(size_t, const gid_t *);
char *getpass(const char *);
int daemon(int, int);
void setusershell(void);
void endusershell(void);
char *getusershell(void);
int acct(const char *);
long syscall(long, ...);
int execvpe(const char *, char *const [], char *const []);
int issetugid(void);
int getentropy(void *, size_t);
extern int optreset;



extern char **environ;
int setresuid(uid_t, uid_t, uid_t);
int setresgid(gid_t, gid_t, gid_t);
int getresuid(uid_t *, uid_t *, uid_t *);
int getresgid(gid_t *, gid_t *, gid_t *);
char *get_current_dir_name(void);
int syncfs(int);
int euidaccess(const char *, int);
int eaccess(const char *, int);
ssize_t copy_file_range(int, off_t *, int, off_t *, size_t, unsigned);
pid_t gettid(void);



off64_t lseek64(int, off64_t, int);
ssize_t pread64(int, void *, size_t, off64_t);
ssize_t pwrite64(int, const void *, size_t, off64_t);
int truncate64(const char *, off64_t);
int ftruncate64(int, off64_t);
off_t _lseek(int fd, off_t offset, int whence);
off64_t _lseek64(int fd, int offsetHigh, int offsetLow, off64_t *result, int whence);
# 260 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/unistd.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/posix.h" 1
# 261 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/unistd.h" 2
# 25 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/app_file.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_centraldirectory.h" 1
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_centraldirectory.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h" 1
# 13 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/private_access.h" 1
# 14 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/build_info.h" 1
# 108 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/build_info.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/../port/config/config_liteos_a.h" 1
# 43 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/../port/config/config_liteos_a.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdlib.h" 1
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdlib.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdlib.h" 2

int atoi (const char *);
long atol (const char *);
long long atoll (const char *);
double atof (const char *);

float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);

long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);
long long strtoll (const char *restrict, char **restrict, int);
unsigned long long strtoull (const char *restrict, char **restrict, int);

int rand (void);
void srand (unsigned);

void *malloc (size_t);
void *calloc (size_t, size_t);
void *realloc (void *, size_t);
void free (void *);
void *aligned_alloc(size_t, size_t);
void *zalloc(size_t);

_Noreturn void abort (void);
int atexit (void (*) (void));
_Noreturn void exit (int);
_Noreturn void _Exit (int);
int at_quick_exit (void (*) (void));
_Noreturn void quick_exit (int);

char *getenv (const char *);

int system (const char *);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));
void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);
long long llabs (long long);

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

div_t div (int, int);
ldiv_t ldiv (long, long);
lldiv_t lldiv (long long, long long);

int mblen (const char *, size_t);
int mbtowc (wchar_t *restrict, const char *restrict, size_t);
int wctomb (char *, wchar_t);
size_t mbstowcs (wchar_t *restrict, const char *restrict, size_t);
size_t wcstombs (char *restrict, const wchar_t *restrict, size_t);




size_t __ctype_get_mb_cur_max(void);
# 102 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdlib.h"
int posix_memalign (void **, size_t, size_t);
int setenv (const char *, const char *, int);
int unsetenv (const char *);
int mkstemp (char *);
int mkostemp (char *, int);
char *mkdtemp (char *);
int getsubopt (char **, char *const *, char **);
int rand_r (unsigned *);






char *realpath (const char *restrict, char *restrict);
long int random (void);
void srandom (unsigned int);
char *initstate (unsigned int, char *, size_t);
char *setstate (char *);
int putenv (char *);
int posix_openpt (int);
int grantpt (int);
int unlockpt (int);
char *ptsname (int);
char *l64a (long);
long a64l (const char *);
void setkey (const char *);
double drand48 (void);
double erand48 (unsigned short [3]);
long int lrand48 (void);
long int nrand48 (unsigned short [3]);
long mrand48 (void);
long jrand48 (unsigned short [3]);
void srand48 (long);
unsigned short *seed48 (unsigned short [3]);
void lcong48 (unsigned short [7]);



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/alloca.h" 1








# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 10 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/alloca.h" 2

void *alloca(size_t);
# 142 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdlib.h" 2
char *mktemp (char *);
int mkstemps (char *, int);
int mkostemps (char *, int, int);
void *valloc (size_t);
void *memalign(size_t, size_t);
int getloadavg(double *, int);
int clearenv(void);


void *reallocarray (void *, size_t, size_t);
void qsort_r (void *, size_t, size_t, int (*)(const void *, const void *, void *), void *);



int ptsname_r(int, char *, size_t);
char *ecvt(double, int, int *, int *);
char *fcvt(double, int, int *, int *);
char *gcvt(double, int, char *);
char *secure_getenv(const char *);
struct __locale_struct;
# 44 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/../port/config/config_liteos_a.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdio.h" 1
# 26 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdio.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 29 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef __builtin_va_list va_list;




typedef __builtin_va_list __isoc_va_list;
# 355 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef struct _IO_FILE FILE;
# 27 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdio.h" 2
# 56 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdio.h"
typedef union _G_fpos64_t {
 char __opaque[16];
 long long __lldata;
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);

char *fgets(char *restrict, int, FILE *restrict);




int fputs(const char *restrict, FILE *restrict);
int puts(const char *);

int printf(const char *restrict, ...);
int fprintf(FILE *restrict, const char *restrict, ...);
int sprintf(char *restrict, const char *restrict, ...);
int snprintf(char *restrict, size_t, const char *restrict, ...);

int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

int scanf(const char *restrict, ...);
int fscanf(FILE *restrict, const char *restrict, ...);
int sscanf(const char *restrict, const char *restrict, ...);
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
void dprintf(const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);




char *cuserid(char *);
void setlinebuf(FILE *);
void setbuffer(FILE *, char *, size_t);
int fgetc_unlocked(FILE *);
int fputc_unlocked(int, FILE *);
int fflush_unlocked(FILE *);
size_t fread_unlocked(void *, size_t, size_t, FILE *);
size_t fwrite_unlocked(const void *, size_t, size_t, FILE *);
void clearerr_unlocked(FILE *);
int feof_unlocked(FILE *);
int ferror_unlocked(FILE *);
int fileno_unlocked(FILE *);
int getw(FILE *);
int putw(int, FILE *);
char *fgetln(FILE *, size_t *);
int asprintf(char **, const char *, ...);
int vasprintf(char **, const char *, __isoc_va_list);



char *fgets_unlocked(char *, int, FILE *);
int fputs_unlocked(const char *, FILE *);

typedef ssize_t (cookie_read_function_t)(void *, char *, size_t);
typedef ssize_t (cookie_write_function_t)(void *, const char *, size_t);
typedef int (cookie_seek_function_t)(void *, off_t *, int);
typedef int (cookie_close_function_t)(void *);

typedef struct _IO_cookie_io_functions_t {
 cookie_read_function_t *read;
 cookie_write_function_t *write;
 cookie_seek_function_t *seek;
 cookie_close_function_t *close;
} cookie_io_functions_t;

FILE *fopencookie(void *, const char *, cookie_io_functions_t);
# 45 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/../port/config/config_liteos_a.h" 2
# 109 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/build_info.h" 2
# 167 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/build_info.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_psa.h" 1
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_psa.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_legacy.h" 1
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_psa.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_adjust_config_synonyms.h" 1
# 24 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_psa.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_adjust_psa_superset_legacy.h" 1
# 26 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_psa.h" 2
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_psa.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_adjust_psa_from_legacy.h" 1
# 42 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_psa.h" 2



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_adjust_config_key_pair_types.h" 1
# 46 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_psa.h" 2







# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_adjust_auto_enabled.h" 1
# 54 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_psa.h" 2
# 168 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/build_info.h" 2


# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_adjust_legacy_crypto.h" 1
# 171 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/build_info.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_adjust_x509.h" 1
# 173 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/build_info.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/config_adjust_ssl.h" 1
# 175 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/build_info.h" 2



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/check_config.h" 1
# 1124 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/check_config.h"
typedef int mbedtls_iso_c_forbids_empty_translation_units;
# 179 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/build_info.h" 2
# 16 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h" 1
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform_util.h" 1
# 170 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform_util.h"
void mbedtls_platform_zeroize(void *buf, size_t len);
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h" 2
# 47 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
typedef enum {
    MBEDTLS_MD_NONE=0,



    MBEDTLS_MD_MD5,

    MBEDTLS_MD_RIPEMD160=0x04,
    MBEDTLS_MD_SHA1=0x05,
    MBEDTLS_MD_SHA224=0x08,
    MBEDTLS_MD_SHA256=0x09,
    MBEDTLS_MD_SHA384=0x0a,
    MBEDTLS_MD_SHA512=0x0b,
    MBEDTLS_MD_SHA3_224=0x10,
    MBEDTLS_MD_SHA3_256=0x11,
    MBEDTLS_MD_SHA3_384=0x12,
    MBEDTLS_MD_SHA3_512=0x13,
} mbedtls_md_type_t;
# 111 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
typedef struct mbedtls_md_info_t mbedtls_md_info_t;






typedef enum {
    MBEDTLS_MD_ENGINE_LEGACY = 0,
    MBEDTLS_MD_ENGINE_PSA,
} mbedtls_md_engine_t;




typedef struct mbedtls_md_context_t {

    const mbedtls_md_info_t *private_md_info;







    void *private_md_ctx;



    void *private_hmac_ctx;

} mbedtls_md_context_t;
# 153 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
const mbedtls_md_info_t *mbedtls_md_info_from_type(mbedtls_md_type_t md_type);
# 163 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
void mbedtls_md_init(mbedtls_md_context_t *ctx);
# 178 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
void mbedtls_md_free(mbedtls_md_context_t *ctx);
# 201 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
int mbedtls_md_setup(mbedtls_md_context_t *ctx, const mbedtls_md_info_t *md_info, int hmac);
# 227 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
int mbedtls_md_clone(mbedtls_md_context_t *dst,
                     const mbedtls_md_context_t *src);
# 239 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
unsigned char mbedtls_md_get_size(const mbedtls_md_info_t *md_info);
# 250 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
static inline unsigned char mbedtls_md_get_size_from_type(mbedtls_md_type_t md_type)
{
    return mbedtls_md_get_size(mbedtls_md_info_from_type(md_type));
}
# 264 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
mbedtls_md_type_t mbedtls_md_get_type(const mbedtls_md_info_t *md_info);
# 280 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
int mbedtls_md_starts(mbedtls_md_context_t *ctx);
# 299 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
int mbedtls_md_update(mbedtls_md_context_t *ctx, const unsigned char *input, size_t ilen);
# 320 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
int mbedtls_md_finish(mbedtls_md_context_t *ctx, unsigned char *output);
# 341 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
int mbedtls_md(const mbedtls_md_info_t *md_info, const unsigned char *input, size_t ilen,
               unsigned char *output);
# 355 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
const int *mbedtls_md_list(void);
# 366 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
const mbedtls_md_info_t *mbedtls_md_info_from_string(const char *md_name);
# 377 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
const char *mbedtls_md_get_name(const mbedtls_md_info_t *md_info);
# 389 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
const mbedtls_md_info_t *mbedtls_md_info_from_ctx(
    const mbedtls_md_context_t *ctx);
# 411 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
int mbedtls_md_file(const mbedtls_md_info_t *md_info, const char *path,
                    unsigned char *output);
# 434 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
int mbedtls_md_hmac_starts(mbedtls_md_context_t *ctx, const unsigned char *key,
                           size_t keylen);
# 457 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
int mbedtls_md_hmac_update(mbedtls_md_context_t *ctx, const unsigned char *input,
                           size_t ilen);
# 479 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
int mbedtls_md_hmac_finish(mbedtls_md_context_t *ctx, unsigned char *output);
# 497 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
int mbedtls_md_hmac_reset(mbedtls_md_context_t *ctx);
# 522 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h"
int mbedtls_md_hmac(const mbedtls_md_info_t *md_info, const unsigned char *key, size_t keylen,
                    const unsigned char *input, size_t ilen,
                    unsigned char *output);
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h" 2


# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h" 1
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h" 1
# 168 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
typedef int32_t mbedtls_mpi_sint;
typedef uint32_t mbedtls_mpi_uint;


typedef uint64_t mbedtls_t_udbl;
# 207 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
typedef struct mbedtls_mpi {




    mbedtls_mpi_uint *private_p;
# 225 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
    signed short private_s;


    unsigned short private_n;
# 238 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
}
mbedtls_mpi;
# 249 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
void mbedtls_mpi_init(mbedtls_mpi *X);
# 258 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
void mbedtls_mpi_free(mbedtls_mpi *X);
# 273 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_grow(mbedtls_mpi *X, size_t nblimbs);
# 290 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_shrink(mbedtls_mpi *X, size_t nblimbs);
# 305 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_copy(mbedtls_mpi *X, const mbedtls_mpi *Y);







void mbedtls_mpi_swap(mbedtls_mpi *X, mbedtls_mpi *Y);
# 343 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_safe_cond_assign(mbedtls_mpi *X, const mbedtls_mpi *Y, unsigned char assign);
# 372 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_safe_cond_swap(mbedtls_mpi *X, mbedtls_mpi *Y, unsigned char swap);
# 384 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_lset(mbedtls_mpi *X, mbedtls_mpi_sint z);
# 396 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_get_bit(const mbedtls_mpi *X, size_t pos);
# 413 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_set_bit(mbedtls_mpi *X, size_t pos, unsigned char val);
# 427 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
size_t mbedtls_mpi_lsb(const mbedtls_mpi *X);
# 441 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
size_t mbedtls_mpi_bitlen(const mbedtls_mpi *X);
# 456 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
size_t mbedtls_mpi_size(const mbedtls_mpi *X);
# 468 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_read_string(mbedtls_mpi *X, int radix, const char *s);
# 492 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_write_string(const mbedtls_mpi *X, int radix,
                             char *buf, size_t buflen, size_t *olen);
# 517 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_read_file(mbedtls_mpi *X, int radix, FILE *fin);
# 534 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_write_file(const char *p, const mbedtls_mpi *X,
                           int radix, FILE *fout);
# 550 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_read_binary(mbedtls_mpi *X, const unsigned char *buf,
                            size_t buflen);
# 565 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_read_binary_le(mbedtls_mpi *X,
                               const unsigned char *buf, size_t buflen);
# 583 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_write_binary(const mbedtls_mpi *X, unsigned char *buf,
                             size_t buflen);
# 601 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_write_binary_le(const mbedtls_mpi *X,
                                unsigned char *buf, size_t buflen);
# 616 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_shift_l(mbedtls_mpi *X, size_t count);
# 628 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_shift_r(mbedtls_mpi *X, size_t count);
# 640 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_cmp_abs(const mbedtls_mpi *X, const mbedtls_mpi *Y);
# 652 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_cmp_mpi(const mbedtls_mpi *X, const mbedtls_mpi *Y);
# 669 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_lt_mpi_ct(const mbedtls_mpi *X, const mbedtls_mpi *Y,
                          unsigned *ret);
# 682 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_cmp_int(const mbedtls_mpi *X, mbedtls_mpi_sint z);
# 695 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_add_abs(mbedtls_mpi *X, const mbedtls_mpi *A,
                        const mbedtls_mpi *B);
# 710 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_sub_abs(mbedtls_mpi *X, const mbedtls_mpi *A,
                        const mbedtls_mpi *B);
# 724 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_add_mpi(mbedtls_mpi *X, const mbedtls_mpi *A,
                        const mbedtls_mpi *B);
# 738 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_sub_mpi(mbedtls_mpi *X, const mbedtls_mpi *A,
                        const mbedtls_mpi *B);
# 752 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_add_int(mbedtls_mpi *X, const mbedtls_mpi *A,
                        mbedtls_mpi_sint b);
# 767 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_sub_int(mbedtls_mpi *X, const mbedtls_mpi *A,
                        mbedtls_mpi_sint b);
# 782 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_mul_mpi(mbedtls_mpi *X, const mbedtls_mpi *A,
                        const mbedtls_mpi *B);
# 798 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_mul_int(mbedtls_mpi *X, const mbedtls_mpi *A,
                        mbedtls_mpi_uint b);
# 819 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_div_mpi(mbedtls_mpi *Q, mbedtls_mpi *R, const mbedtls_mpi *A,
                        const mbedtls_mpi *B);
# 840 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_div_int(mbedtls_mpi *Q, mbedtls_mpi *R, const mbedtls_mpi *A,
                        mbedtls_mpi_sint b);
# 860 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_mod_mpi(mbedtls_mpi *R, const mbedtls_mpi *A,
                        const mbedtls_mpi *B);
# 879 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_mod_int(mbedtls_mpi_uint *r, const mbedtls_mpi *A,
                        mbedtls_mpi_sint b);
# 909 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_exp_mod(mbedtls_mpi *X, const mbedtls_mpi *A,
                        const mbedtls_mpi *E, const mbedtls_mpi *N,
                        mbedtls_mpi *prec_RR);
# 930 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_fill_random(mbedtls_mpi *X, size_t size,
                            int (*f_rng)(void *, unsigned char *, size_t),
                            void *p_rng);
# 966 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_random(mbedtls_mpi *X,
                       mbedtls_mpi_sint min,
                       const mbedtls_mpi *N,
                       int (*f_rng)(void *, unsigned char *, size_t),
                       void *p_rng);
# 983 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_gcd(mbedtls_mpi *G, const mbedtls_mpi *A,
                    const mbedtls_mpi *B);
# 1002 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_inv_mod(mbedtls_mpi *X, const mbedtls_mpi *A,
                        const mbedtls_mpi *N);
# 1032 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_is_prime_ext(const mbedtls_mpi *X, int rounds,
                             int (*f_rng)(void *, unsigned char *, size_t),
                             void *p_rng);






typedef enum {
    MBEDTLS_MPI_GEN_PRIME_FLAG_DH = 0x0001,
    MBEDTLS_MPI_GEN_PRIME_FLAG_LOW_ERR = 0x0002,
} mbedtls_mpi_gen_prime_flag_t;
# 1065 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/bignum.h"
int mbedtls_mpi_gen_prime(mbedtls_mpi *X, size_t nbits, int flags,
                          int (*f_rng)(void *, unsigned char *, size_t),
                          void *p_rng);
# 23 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h" 2
# 85 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
typedef struct mbedtls_rsa_context {
    int private_ver;



    size_t private_len;

    mbedtls_mpi private_N;
    mbedtls_mpi private_E;

    mbedtls_mpi private_D;
    mbedtls_mpi private_P;
    mbedtls_mpi private_Q;

    mbedtls_mpi private_DP;
    mbedtls_mpi private_DQ;
    mbedtls_mpi private_QP;

    mbedtls_mpi private_RN;

    mbedtls_mpi private_RP;
    mbedtls_mpi private_RQ;

    mbedtls_mpi private_Vi;
    mbedtls_mpi private_Vf;

    int private_padding;


    int private_hash_id;







}
mbedtls_rsa_context;
# 139 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
void mbedtls_rsa_init(mbedtls_rsa_context *ctx);
# 175 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_set_padding(mbedtls_rsa_context *ctx, int padding,
                            mbedtls_md_type_t hash_id);
# 187 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_get_padding_mode(const mbedtls_rsa_context *ctx);
# 198 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_get_md_alg(const mbedtls_rsa_context *ctx);
# 229 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_import(mbedtls_rsa_context *ctx,
                       const mbedtls_mpi *N,
                       const mbedtls_mpi *P, const mbedtls_mpi *Q,
                       const mbedtls_mpi *D, const mbedtls_mpi *E);
# 268 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_import_raw(mbedtls_rsa_context *ctx,
                           unsigned char const *N, size_t N_len,
                           unsigned char const *P, size_t P_len,
                           unsigned char const *Q, size_t Q_len,
                           unsigned char const *D, size_t D_len,
                           unsigned char const *E, size_t E_len);
# 307 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_complete(mbedtls_rsa_context *ctx);
# 349 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_export(const mbedtls_rsa_context *ctx,
                       mbedtls_mpi *N, mbedtls_mpi *P, mbedtls_mpi *Q,
                       mbedtls_mpi *D, mbedtls_mpi *E);
# 400 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_export_raw(const mbedtls_rsa_context *ctx,
                           unsigned char *N, size_t N_len,
                           unsigned char *P, size_t P_len,
                           unsigned char *Q, size_t Q_len,
                           unsigned char *D, size_t D_len,
                           unsigned char *E, size_t E_len);
# 426 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_export_crt(const mbedtls_rsa_context *ctx,
                           mbedtls_mpi *DP, mbedtls_mpi *DQ, mbedtls_mpi *QP);
# 437 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
size_t mbedtls_rsa_get_bitlen(const mbedtls_rsa_context *ctx);
# 447 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
size_t mbedtls_rsa_get_len(const mbedtls_rsa_context *ctx);
# 467 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_gen_key(mbedtls_rsa_context *ctx,
                        int (*f_rng)(void *, unsigned char *, size_t),
                        void *p_rng,
                        unsigned int nbits, int exponent);
# 486 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_check_pubkey(const mbedtls_rsa_context *ctx);
# 524 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_check_privkey(const mbedtls_rsa_context *ctx);
# 537 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_check_pub_priv(const mbedtls_rsa_context *pub,
                               const mbedtls_rsa_context *prv);
# 559 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_public(mbedtls_rsa_context *ctx,
                       const unsigned char *input,
                       unsigned char *output);
# 592 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_private(mbedtls_rsa_context *ctx,
                        int (*f_rng)(void *, unsigned char *, size_t),
                        void *p_rng,
                        const unsigned char *input,
                        unsigned char *output);
# 621 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_pkcs1_encrypt(mbedtls_rsa_context *ctx,
                              int (*f_rng)(void *, unsigned char *, size_t),
                              void *p_rng,
                              size_t ilen,
                              const unsigned char *input,
                              unsigned char *output);
# 648 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_rsaes_pkcs1_v15_encrypt(mbedtls_rsa_context *ctx,
                                        int (*f_rng)(void *, unsigned char *, size_t),
                                        void *p_rng,
                                        size_t ilen,
                                        const unsigned char *input,
                                        unsigned char *output);
# 682 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_rsaes_oaep_encrypt(mbedtls_rsa_context *ctx,
                                   int (*f_rng)(void *, unsigned char *, size_t),
                                   void *p_rng,
                                   const unsigned char *label, size_t label_len,
                                   size_t ilen,
                                   const unsigned char *input,
                                   unsigned char *output);
# 725 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_pkcs1_decrypt(mbedtls_rsa_context *ctx,
                              int (*f_rng)(void *, unsigned char *, size_t),
                              void *p_rng,
                              size_t *olen,
                              const unsigned char *input,
                              unsigned char *output,
                              size_t output_max_len);
# 767 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_rsaes_pkcs1_v15_decrypt(mbedtls_rsa_context *ctx,
                                        int (*f_rng)(void *, unsigned char *, size_t),
                                        void *p_rng,
                                        size_t *olen,
                                        const unsigned char *input,
                                        unsigned char *output,
                                        size_t output_max_len);
# 808 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_rsaes_oaep_decrypt(mbedtls_rsa_context *ctx,
                                   int (*f_rng)(void *, unsigned char *, size_t),
                                   void *p_rng,
                                   const unsigned char *label, size_t label_len,
                                   size_t *olen,
                                   const unsigned char *input,
                                   unsigned char *output,
                                   size_t output_max_len);
# 851 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_pkcs1_sign(mbedtls_rsa_context *ctx,
                           int (*f_rng)(void *, unsigned char *, size_t),
                           void *p_rng,
                           mbedtls_md_type_t md_alg,
                           unsigned int hashlen,
                           const unsigned char *hash,
                           unsigned char *sig);
# 883 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_rsassa_pkcs1_v15_sign(mbedtls_rsa_context *ctx,
                                      int (*f_rng)(void *, unsigned char *, size_t),
                                      void *p_rng,
                                      mbedtls_md_type_t md_alg,
                                      unsigned int hashlen,
                                      const unsigned char *hash,
                                      unsigned char *sig);
# 935 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_rsassa_pss_sign_ext(mbedtls_rsa_context *ctx,
                                    int (*f_rng)(void *, unsigned char *, size_t),
                                    void *p_rng,
                                    mbedtls_md_type_t md_alg,
                                    unsigned int hashlen,
                                    const unsigned char *hash,
                                    int saltlen,
                                    unsigned char *sig);
# 985 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_rsassa_pss_sign(mbedtls_rsa_context *ctx,
                                int (*f_rng)(void *, unsigned char *, size_t),
                                void *p_rng,
                                mbedtls_md_type_t md_alg,
                                unsigned int hashlen,
                                const unsigned char *hash,
                                unsigned char *sig);
# 1020 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_pkcs1_verify(mbedtls_rsa_context *ctx,
                             mbedtls_md_type_t md_alg,
                             unsigned int hashlen,
                             const unsigned char *hash,
                             const unsigned char *sig);
# 1045 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_rsassa_pkcs1_v15_verify(mbedtls_rsa_context *ctx,
                                        mbedtls_md_type_t md_alg,
                                        unsigned int hashlen,
                                        const unsigned char *hash,
                                        const unsigned char *sig);
# 1080 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_rsassa_pss_verify(mbedtls_rsa_context *ctx,
                                  mbedtls_md_type_t md_alg,
                                  unsigned int hashlen,
                                  const unsigned char *hash,
                                  const unsigned char *sig);
# 1120 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_rsassa_pss_verify_ext(mbedtls_rsa_context *ctx,
                                      mbedtls_md_type_t md_alg,
                                      unsigned int hashlen,
                                      const unsigned char *hash,
                                      mbedtls_md_type_t mgf1_hash_id,
                                      int expected_salt_len,
                                      const unsigned char *sig);
# 1137 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
int mbedtls_rsa_copy(mbedtls_rsa_context *dst, const mbedtls_rsa_context *src);
# 1146 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/rsa.h"
void mbedtls_rsa_free(mbedtls_rsa_context *ctx);
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h" 2



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h" 1
# 102 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
typedef enum {
    MBEDTLS_ECP_DP_NONE = 0,
    MBEDTLS_ECP_DP_SECP192R1,
    MBEDTLS_ECP_DP_SECP224R1,
    MBEDTLS_ECP_DP_SECP256R1,
    MBEDTLS_ECP_DP_SECP384R1,
    MBEDTLS_ECP_DP_SECP521R1,
    MBEDTLS_ECP_DP_BP256R1,
    MBEDTLS_ECP_DP_BP384R1,
    MBEDTLS_ECP_DP_BP512R1,
    MBEDTLS_ECP_DP_CURVE25519,
    MBEDTLS_ECP_DP_SECP192K1,
    MBEDTLS_ECP_DP_SECP224K1,
    MBEDTLS_ECP_DP_SECP256K1,
    MBEDTLS_ECP_DP_CURVE448,
} mbedtls_ecp_group_id;
# 127 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
typedef enum {
    MBEDTLS_ECP_TYPE_NONE = 0,
    MBEDTLS_ECP_TYPE_SHORT_WEIERSTRASS,
    MBEDTLS_ECP_TYPE_MONTGOMERY,
} mbedtls_ecp_curve_type;
# 140 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
typedef struct mbedtls_ecp_curve_info {
    mbedtls_ecp_group_id grp_id;
    uint16_t tls_id;
    uint16_t bit_size;
    const char *name;
} mbedtls_ecp_curve_info;
# 158 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
typedef struct mbedtls_ecp_point {
    mbedtls_mpi private_X;
    mbedtls_mpi private_Y;
    mbedtls_mpi private_Z;
}
mbedtls_ecp_point;
# 233 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
typedef struct mbedtls_ecp_group {
    mbedtls_ecp_group_id id;
    mbedtls_mpi P;
    mbedtls_mpi A;




    mbedtls_mpi B;

    mbedtls_ecp_point G;
    mbedtls_mpi N;
    size_t pbits;
    size_t nbits;




    unsigned int private_h;
    int(*private_modp)(mbedtls_mpi *);

    int(*private_t_pre)(mbedtls_ecp_point *, void *);
    int(*private_t_post)(mbedtls_ecp_point *, void *);
    void *private_t_data;
    mbedtls_ecp_point *private_T;
    size_t private_T_size;
}
mbedtls_ecp_group;
# 364 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
typedef struct mbedtls_ecp_restart_mul mbedtls_ecp_restart_mul_ctx;






typedef struct mbedtls_ecp_restart_muladd mbedtls_ecp_restart_muladd_ctx;




typedef struct {
    unsigned private_ops_done;
    unsigned private_depth;
    mbedtls_ecp_restart_mul_ctx *private_rsm;
    mbedtls_ecp_restart_muladd_ctx *private_ma;
} mbedtls_ecp_restart_ctx;
# 402 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_check_budget(const mbedtls_ecp_group *grp,
                             mbedtls_ecp_restart_ctx *rs_ctx,
                             unsigned ops);
# 428 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
typedef struct mbedtls_ecp_keypair {
    mbedtls_ecp_group private_grp;
    mbedtls_mpi private_d;
    mbedtls_ecp_point private_Q;
}
mbedtls_ecp_keypair;
# 521 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
void mbedtls_ecp_set_max_ops(unsigned max_ops);







int mbedtls_ecp_restart_is_enabled(void);





mbedtls_ecp_curve_type mbedtls_ecp_get_type(const mbedtls_ecp_group *grp);
# 549 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
const mbedtls_ecp_curve_info *mbedtls_ecp_curve_list(void);
# 565 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
const mbedtls_ecp_group_id *mbedtls_ecp_grp_id_list(void);
# 576 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
const mbedtls_ecp_curve_info *mbedtls_ecp_curve_info_from_grp_id(mbedtls_ecp_group_id grp_id);
# 587 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
const mbedtls_ecp_curve_info *mbedtls_ecp_curve_info_from_tls_id(uint16_t tls_id);
# 598 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
const mbedtls_ecp_curve_info *mbedtls_ecp_curve_info_from_name(const char *name);






void mbedtls_ecp_point_init(mbedtls_ecp_point *pt);
# 616 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
void mbedtls_ecp_group_init(mbedtls_ecp_group *grp);






void mbedtls_ecp_keypair_init(mbedtls_ecp_keypair *key);






void mbedtls_ecp_point_free(mbedtls_ecp_point *pt);
# 639 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
void mbedtls_ecp_group_free(mbedtls_ecp_group *grp);
# 648 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
void mbedtls_ecp_keypair_free(mbedtls_ecp_keypair *key);
# 657 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
void mbedtls_ecp_restart_init(mbedtls_ecp_restart_ctx *ctx);
# 666 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
void mbedtls_ecp_restart_free(mbedtls_ecp_restart_ctx *ctx);
# 680 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_copy(mbedtls_ecp_point *P, const mbedtls_ecp_point *Q);
# 693 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_group_copy(mbedtls_ecp_group *dst,
                           const mbedtls_ecp_group *src);
# 705 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_set_zero(mbedtls_ecp_point *pt);
# 716 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_is_zero(mbedtls_ecp_point *pt);
# 730 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_point_cmp(const mbedtls_ecp_point *P,
                          const mbedtls_ecp_point *Q);
# 745 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_point_read_string(mbedtls_ecp_point *P, int radix,
                                  const char *x, const char *y);
# 773 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_point_write_binary(const mbedtls_ecp_group *grp,
                                   const mbedtls_ecp_point *P,
                                   int format, size_t *olen,
                                   unsigned char *buf, size_t buflen);
# 803 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_point_read_binary(const mbedtls_ecp_group *grp,
                                  mbedtls_ecp_point *P,
                                  const unsigned char *buf, size_t ilen);
# 825 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_tls_read_point(const mbedtls_ecp_group *grp,
                               mbedtls_ecp_point *pt,
                               const unsigned char **buf, size_t len);
# 851 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_tls_write_point(const mbedtls_ecp_group *grp,
                                const mbedtls_ecp_point *pt,
                                int format, size_t *olen,
                                unsigned char *buf, size_t blen);
# 873 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_group_load(mbedtls_ecp_group *grp, mbedtls_ecp_group_id id);
# 892 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_tls_read_group(mbedtls_ecp_group *grp,
                               const unsigned char **buf, size_t len);
# 913 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_tls_read_group_id(mbedtls_ecp_group_id *grp,
                                  const unsigned char **buf,
                                  size_t len);
# 934 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_tls_write_group(const mbedtls_ecp_group *grp,
                                size_t *olen,
                                unsigned char *buf, size_t blen);
# 967 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_mul(mbedtls_ecp_group *grp, mbedtls_ecp_point *R,
                    const mbedtls_mpi *m, const mbedtls_ecp_point *P,
                    int (*f_rng)(void *, unsigned char *, size_t), void *p_rng);
# 1001 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_mul_restartable(mbedtls_ecp_group *grp, mbedtls_ecp_point *R,
                                const mbedtls_mpi *m, const mbedtls_ecp_point *P,
                                int (*f_rng)(void *, unsigned char *, size_t), void *p_rng,
                                mbedtls_ecp_restart_ctx *rs_ctx);
# 1022 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
static inline int mbedtls_ecp_group_a_is_minus_3(const mbedtls_ecp_group *grp)
{
    return grp->A.private_p == ((void*)0);
}
# 1062 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_muladd(mbedtls_ecp_group *grp, mbedtls_ecp_point *R,
                       const mbedtls_mpi *m, const mbedtls_ecp_point *P,
                       const mbedtls_mpi *n, const mbedtls_ecp_point *Q);
# 1106 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_muladd_restartable(
    mbedtls_ecp_group *grp, mbedtls_ecp_point *R,
    const mbedtls_mpi *m, const mbedtls_ecp_point *P,
    const mbedtls_mpi *n, const mbedtls_ecp_point *Q,
    mbedtls_ecp_restart_ctx *rs_ctx);
# 1140 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_check_pubkey(const mbedtls_ecp_group *grp,
                             const mbedtls_ecp_point *pt);
# 1162 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_check_privkey(const mbedtls_ecp_group *grp,
                              const mbedtls_mpi *d);
# 1180 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_gen_privkey(const mbedtls_ecp_group *grp,
                            mbedtls_mpi *d,
                            int (*f_rng)(void *, unsigned char *, size_t),
                            void *p_rng);
# 1212 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_gen_keypair_base(mbedtls_ecp_group *grp,
                                 const mbedtls_ecp_point *G,
                                 mbedtls_mpi *d, mbedtls_ecp_point *Q,
                                 int (*f_rng)(void *, unsigned char *, size_t),
                                 void *p_rng);
# 1241 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_gen_keypair(mbedtls_ecp_group *grp, mbedtls_mpi *d,
                            mbedtls_ecp_point *Q,
                            int (*f_rng)(void *, unsigned char *, size_t),
                            void *p_rng);
# 1259 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_gen_key(mbedtls_ecp_group_id grp_id, mbedtls_ecp_keypair *key,
                        int (*f_rng)(void *, unsigned char *, size_t),
                        void *p_rng);
# 1291 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_set_public_key(mbedtls_ecp_group_id grp_id,
                               mbedtls_ecp_keypair *key,
                               const mbedtls_ecp_point *Q);
# 1328 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_read_key(mbedtls_ecp_group_id grp_id, mbedtls_ecp_keypair *key,
                         const unsigned char *buf, size_t buflen);
# 1376 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_write_key(mbedtls_ecp_keypair *key,
                                             unsigned char *buf, size_t buflen);
# 1399 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_write_key_ext(const mbedtls_ecp_keypair *key,
                              size_t *olen, unsigned char *buf, size_t buflen);
# 1428 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_write_public_key(const mbedtls_ecp_keypair *key,
                                 int format, size_t *olen,
                                 unsigned char *buf, size_t buflen);
# 1452 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_check_pub_priv(
    const mbedtls_ecp_keypair *pub, const mbedtls_ecp_keypair *prv,
    int (*f_rng)(void *, unsigned char *, size_t), void *p_rng);
# 1469 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_keypair_calc_public(
    mbedtls_ecp_keypair *key,
    int (*f_rng)(void *, unsigned char *, size_t), void *p_rng);
# 1482 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
mbedtls_ecp_group_id mbedtls_ecp_keypair_get_group_id(
    const mbedtls_ecp_keypair *key);
# 1509 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecp.h"
int mbedtls_ecp_export(const mbedtls_ecp_keypair *key, mbedtls_ecp_group *grp,
                       mbedtls_mpi *d, mbedtls_ecp_point *Q);
# 25 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h" 2



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h" 1
# 68 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
typedef mbedtls_ecp_keypair mbedtls_ecdsa_context;
# 77 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
typedef struct mbedtls_ecdsa_restart_ver mbedtls_ecdsa_restart_ver_ctx;






typedef struct mbedtls_ecdsa_restart_sig mbedtls_ecdsa_restart_sig_ctx;
# 98 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
typedef struct {
    mbedtls_ecp_restart_ctx private_ecp;

    mbedtls_ecdsa_restart_ver_ctx *private_ver;
    mbedtls_ecdsa_restart_sig_ctx *private_sig;



} mbedtls_ecdsa_restart_ctx;
# 123 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
int mbedtls_ecdsa_can_do(mbedtls_ecp_group_id gid);
# 161 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
int mbedtls_ecdsa_sign(mbedtls_ecp_group *grp, mbedtls_mpi *r, mbedtls_mpi *s,
                       const mbedtls_mpi *d, const unsigned char *buf, size_t blen,
                       int (*f_rng)(void *, unsigned char *, size_t), void *p_rng);
# 269 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
int mbedtls_ecdsa_sign_restartable(
    mbedtls_ecp_group *grp,
    mbedtls_mpi *r, mbedtls_mpi *s,
    const mbedtls_mpi *d,
    const unsigned char *buf, size_t blen,
    int (*f_rng)(void *, unsigned char *, size_t),
    void *p_rng,
    int (*f_rng_blind)(void *, unsigned char *, size_t),
    void *p_rng_blind,
    mbedtls_ecdsa_restart_ctx *rs_ctx);
# 373 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
int mbedtls_ecdsa_verify(mbedtls_ecp_group *grp,
                         const unsigned char *buf, size_t blen,
                         const mbedtls_ecp_point *Q, const mbedtls_mpi *r,
                         const mbedtls_mpi *s);
# 414 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
int mbedtls_ecdsa_verify_restartable(mbedtls_ecp_group *grp,
                                     const unsigned char *buf, size_t blen,
                                     const mbedtls_ecp_point *Q,
                                     const mbedtls_mpi *r,
                                     const mbedtls_mpi *s,
                                     mbedtls_ecdsa_restart_ctx *rs_ctx);
# 472 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
int mbedtls_ecdsa_write_signature(mbedtls_ecdsa_context *ctx,
                                  mbedtls_md_type_t md_alg,
                                  const unsigned char *hash, size_t hlen,
                                  unsigned char *sig, size_t sig_size, size_t *slen,
                                  int (*f_rng)(void *, unsigned char *, size_t),
                                  void *p_rng);
# 519 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
int mbedtls_ecdsa_write_signature_restartable(mbedtls_ecdsa_context *ctx,
                                              mbedtls_md_type_t md_alg,
                                              const unsigned char *hash, size_t hlen,
                                              unsigned char *sig, size_t sig_size, size_t *slen,
                                              int (*f_rng)(void *, unsigned char *, size_t),
                                              void *p_rng,
                                              mbedtls_ecdsa_restart_ctx *rs_ctx);
# 554 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
int mbedtls_ecdsa_read_signature(mbedtls_ecdsa_context *ctx,
                                 const unsigned char *hash, size_t hlen,
                                 const unsigned char *sig, size_t slen);
# 589 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
int mbedtls_ecdsa_read_signature_restartable(mbedtls_ecdsa_context *ctx,
                                             const unsigned char *hash, size_t hlen,
                                             const unsigned char *sig, size_t slen,
                                             mbedtls_ecdsa_restart_ctx *rs_ctx);
# 610 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
int mbedtls_ecdsa_genkey(mbedtls_ecdsa_context *ctx, mbedtls_ecp_group_id gid,
                         int (*f_rng)(void *, unsigned char *, size_t), void *p_rng);
# 628 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
int mbedtls_ecdsa_from_keypair(mbedtls_ecdsa_context *ctx,
                               const mbedtls_ecp_keypair *key);







void mbedtls_ecdsa_init(mbedtls_ecdsa_context *ctx);
# 646 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
void mbedtls_ecdsa_free(mbedtls_ecdsa_context *ctx);
# 655 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
void mbedtls_ecdsa_restart_init(mbedtls_ecdsa_restart_ctx *ctx);
# 664 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecdsa.h"
void mbedtls_ecdsa_restart_free(mbedtls_ecdsa_restart_ctx *ctx);
# 29 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h" 2



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h" 1
# 16 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_platform.h" 1
# 32 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_platform.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/build_info.h" 1
# 33 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_platform.h" 2
# 17 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h" 2
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h" 1
# 59 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef int32_t psa_status_t;
# 78 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef uint16_t psa_key_type_t;
# 97 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef uint8_t psa_ecc_family_t;
# 116 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef uint8_t psa_dh_family_t;
# 134 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef uint32_t psa_algorithm_t;
# 183 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef uint32_t psa_key_lifetime_t;
# 219 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef uint8_t psa_key_persistence_t;
# 260 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef uint32_t psa_key_location_t;
# 275 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef uint32_t psa_key_id_t;
# 292 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef psa_key_id_t mbedtls_svc_key_id_t;
# 323 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef uint32_t psa_key_usage_t;
# 432 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef struct psa_key_attributes_s psa_key_attributes_t;
# 456 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef uint16_t psa_key_derivation_step_t;
# 480 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_types.h"
typedef struct psa_key_production_parameters_s psa_key_production_parameters_t;
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h" 2
# 60 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_values.h" 1
# 2447 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_values.h"
static inline mbedtls_svc_key_id_t mbedtls_svc_key_id_make(
    unsigned int unused, psa_key_id_t key_id)
{
    (void) unused;

    return key_id;
}
# 2462 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_values.h"
static inline int mbedtls_svc_key_id_equal(mbedtls_svc_key_id_t id1,
                                           mbedtls_svc_key_id_t id2)
{
    return id1 == id2;
}







static inline int mbedtls_svc_key_id_is_null(mbedtls_svc_key_id_t key)
{
    return key == 0;
}
# 61 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h" 2
# 94 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_crypto_init(void);
# 110 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static psa_key_attributes_t psa_key_attributes_init(void);
# 133 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static void psa_set_key_id(psa_key_attributes_t *attributes,
                           mbedtls_svc_key_id_t key);
# 181 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static void psa_set_key_lifetime(psa_key_attributes_t *attributes,
                                 psa_key_lifetime_t lifetime);
# 196 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static mbedtls_svc_key_id_t psa_get_key_id(
    const psa_key_attributes_t *attributes);
# 209 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static psa_key_lifetime_t psa_get_key_lifetime(
    const psa_key_attributes_t *attributes);
# 228 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static void psa_set_key_usage_flags(psa_key_attributes_t *attributes,
                                    psa_key_usage_t usage_flags);
# 241 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static psa_key_usage_t psa_get_key_usage_flags(
    const psa_key_attributes_t *attributes);
# 274 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static void psa_set_key_algorithm(psa_key_attributes_t *attributes,
                                  psa_algorithm_t alg);
# 288 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static psa_algorithm_t psa_get_key_algorithm(
    const psa_key_attributes_t *attributes);
# 305 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static void psa_set_key_type(psa_key_attributes_t *attributes,
                             psa_key_type_t type);
# 323 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static void psa_set_key_bits(psa_key_attributes_t *attributes,
                             size_t bits);
# 336 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static psa_key_type_t psa_get_key_type(const psa_key_attributes_t *attributes);
# 348 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static size_t psa_get_key_bits(const psa_key_attributes_t *attributes);
# 378 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_get_key_attributes(mbedtls_svc_key_id_t key,
                                    psa_key_attributes_t *attributes);
# 393 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
void psa_reset_key_attributes(psa_key_attributes_t *attributes);
# 422 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_purge_key(mbedtls_svc_key_id_t key);
# 512 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_copy_key(mbedtls_svc_key_id_t source_key,
                          const psa_key_attributes_t *attributes,
                          mbedtls_svc_key_id_t *target_key);
# 567 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_destroy_key(mbedtls_svc_key_id_t key);
# 646 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_import_key(const psa_key_attributes_t *attributes,
                            const uint8_t *data,
                            size_t data_length,
                            mbedtls_svc_key_id_t *key);
# 741 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_export_key(mbedtls_svc_key_id_t key,
                            uint8_t *data,
                            size_t data_size,
                            size_t *data_length);
# 816 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_export_public_key(mbedtls_svc_key_id_t key,
                                   uint8_t *data,
                                   size_t data_size,
                                   size_t *data_length);
# 860 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_hash_compute(psa_algorithm_t alg,
                              const uint8_t *input,
                              size_t input_length,
                              uint8_t *hash,
                              size_t hash_size,
                              size_t *hash_length);
# 895 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_hash_compare(psa_algorithm_t alg,
                              const uint8_t *input,
                              size_t input_length,
                              const uint8_t *hash,
                              size_t hash_length);
# 929 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
typedef struct psa_hash_operation_s psa_hash_operation_t;
# 939 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static psa_hash_operation_t psa_hash_operation_init(void);
# 989 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_hash_setup(psa_hash_operation_t *operation,
                            psa_algorithm_t alg);
# 1015 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_hash_update(psa_hash_operation_t *operation,
                             const uint8_t *input,
                             size_t input_length);
# 1061 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_hash_finish(psa_hash_operation_t *operation,
                             uint8_t *hash,
                             size_t hash_size,
                             size_t *hash_length);
# 1102 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_hash_verify(psa_hash_operation_t *operation,
                             const uint8_t *hash,
                             size_t hash_length);
# 1131 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_hash_abort(psa_hash_operation_t *operation);
# 1160 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_hash_clone(const psa_hash_operation_t *source_operation,
                            psa_hash_operation_t *target_operation);
# 1211 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_mac_compute(mbedtls_svc_key_id_t key,
                             psa_algorithm_t alg,
                             const uint8_t *input,
                             size_t input_length,
                             uint8_t *mac,
                             size_t mac_size,
                             size_t *mac_length);
# 1252 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_mac_verify(mbedtls_svc_key_id_t key,
                            psa_algorithm_t alg,
                            const uint8_t *input,
                            size_t input_length,
                            const uint8_t *mac,
                            size_t mac_length);
# 1288 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
typedef struct psa_mac_operation_s psa_mac_operation_t;
# 1298 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static psa_mac_operation_t psa_mac_operation_init(void);
# 1358 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_mac_sign_setup(psa_mac_operation_t *operation,
                                mbedtls_svc_key_id_t key,
                                psa_algorithm_t alg);
# 1420 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_mac_verify_setup(psa_mac_operation_t *operation,
                                  mbedtls_svc_key_id_t key,
                                  psa_algorithm_t alg);
# 1450 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_mac_update(psa_mac_operation_t *operation,
                            const uint8_t *input,
                            size_t input_length);
# 1499 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_mac_sign_finish(psa_mac_operation_t *operation,
                                 uint8_t *mac,
                                 size_t mac_size,
                                 size_t *mac_length);
# 1542 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_mac_verify_finish(psa_mac_operation_t *operation,
                                   const uint8_t *mac,
                                   size_t mac_length);
# 1571 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_mac_abort(psa_mac_operation_t *operation);
# 1618 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_cipher_encrypt(mbedtls_svc_key_id_t key,
                                psa_algorithm_t alg,
                                const uint8_t *input,
                                size_t input_length,
                                uint8_t *output,
                                size_t output_size,
                                size_t *output_length);
# 1665 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_cipher_decrypt(mbedtls_svc_key_id_t key,
                                psa_algorithm_t alg,
                                const uint8_t *input,
                                size_t input_length,
                                uint8_t *output,
                                size_t output_size,
                                size_t *output_length);
# 1701 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
typedef struct psa_cipher_operation_s psa_cipher_operation_t;
# 1711 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static psa_cipher_operation_t psa_cipher_operation_init(void);
# 1772 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_cipher_encrypt_setup(psa_cipher_operation_t *operation,
                                      mbedtls_svc_key_id_t key,
                                      psa_algorithm_t alg);
# 1835 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_cipher_decrypt_setup(psa_cipher_operation_t *operation,
                                      mbedtls_svc_key_id_t key,
                                      psa_algorithm_t alg);
# 1873 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_cipher_generate_iv(psa_cipher_operation_t *operation,
                                    uint8_t *iv,
                                    size_t iv_size,
                                    size_t *iv_length);
# 1914 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_cipher_set_iv(psa_cipher_operation_t *operation,
                               const uint8_t *iv,
                               size_t iv_length);
# 1955 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_cipher_update(psa_cipher_operation_t *operation,
                               const uint8_t *input,
                               size_t input_length,
                               uint8_t *output,
                               size_t output_size,
                               size_t *output_length);
# 2007 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_cipher_finish(psa_cipher_operation_t *operation,
                               uint8_t *output,
                               size_t output_size,
                               size_t *output_length);
# 2037 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_cipher_abort(psa_cipher_operation_t *operation);
# 2106 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_aead_encrypt(mbedtls_svc_key_id_t key,
                              psa_algorithm_t alg,
                              const uint8_t *nonce,
                              size_t nonce_length,
                              const uint8_t *additional_data,
                              size_t additional_data_length,
                              const uint8_t *plaintext,
                              size_t plaintext_length,
                              uint8_t *ciphertext,
                              size_t ciphertext_size,
                              size_t *ciphertext_length);
# 2179 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_aead_decrypt(mbedtls_svc_key_id_t key,
                              psa_algorithm_t alg,
                              const uint8_t *nonce,
                              size_t nonce_length,
                              const uint8_t *additional_data,
                              size_t additional_data_length,
                              const uint8_t *ciphertext,
                              size_t ciphertext_length,
                              uint8_t *plaintext,
                              size_t plaintext_size,
                              size_t *plaintext_length);
# 2219 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
typedef struct psa_aead_operation_s psa_aead_operation_t;
# 2229 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static psa_aead_operation_t psa_aead_operation_init(void);
# 2297 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_aead_encrypt_setup(psa_aead_operation_t *operation,
                                    mbedtls_svc_key_id_t key,
                                    psa_algorithm_t alg);
# 2363 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_aead_decrypt_setup(psa_aead_operation_t *operation,
                                    mbedtls_svc_key_id_t key,
                                    psa_algorithm_t alg);
# 2402 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_aead_generate_nonce(psa_aead_operation_t *operation,
                                     uint8_t *nonce,
                                     size_t nonce_size,
                                     size_t *nonce_length);
# 2442 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_aead_set_nonce(psa_aead_operation_t *operation,
                                const uint8_t *nonce,
                                size_t nonce_length);
# 2487 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_aead_set_lengths(psa_aead_operation_t *operation,
                                  size_t ad_length,
                                  size_t plaintext_length);
# 2535 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_aead_update_ad(psa_aead_operation_t *operation,
                                const uint8_t *input,
                                size_t input_length);
# 2619 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_aead_update(psa_aead_operation_t *operation,
                             const uint8_t *input,
                             size_t input_length,
                             uint8_t *output,
                             size_t output_size,
                             size_t *output_length);
# 2705 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_aead_finish(psa_aead_operation_t *operation,
                             uint8_t *ciphertext,
                             size_t ciphertext_size,
                             size_t *ciphertext_length,
                             uint8_t *tag,
                             size_t tag_size,
                             size_t *tag_length);
# 2788 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_aead_verify(psa_aead_operation_t *operation,
                             uint8_t *plaintext,
                             size_t plaintext_size,
                             size_t *plaintext_length,
                             const uint8_t *tag,
                             size_t tag_length);
# 2820 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_aead_abort(psa_aead_operation_t *operation);
# 2886 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_sign_message(mbedtls_svc_key_id_t key,
                              psa_algorithm_t alg,
                              const uint8_t *input,
                              size_t input_length,
                              uint8_t *signature,
                              size_t signature_size,
                              size_t *signature_length);
# 2938 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_verify_message(mbedtls_svc_key_id_t key,
                                psa_algorithm_t alg,
                                const uint8_t *input,
                                size_t input_length,
                                const uint8_t *signature,
                                size_t signature_length);
# 2991 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_sign_hash(mbedtls_svc_key_id_t key,
                           psa_algorithm_t alg,
                           const uint8_t *hash,
                           size_t hash_length,
                           uint8_t *signature,
                           size_t signature_size,
                           size_t *signature_length);
# 3042 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_verify_hash(mbedtls_svc_key_id_t key,
                             psa_algorithm_t alg,
                             const uint8_t *hash,
                             size_t hash_length,
                             const uint8_t *signature,
                             size_t signature_length);
# 3100 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_asymmetric_encrypt(mbedtls_svc_key_id_t key,
                                    psa_algorithm_t alg,
                                    const uint8_t *input,
                                    size_t input_length,
                                    const uint8_t *salt,
                                    size_t salt_length,
                                    uint8_t *output,
                                    size_t output_size,
                                    size_t *output_length);
# 3161 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_asymmetric_decrypt(mbedtls_svc_key_id_t key,
                                    psa_algorithm_t alg,
                                    const uint8_t *input,
                                    size_t input_length,
                                    const uint8_t *salt,
                                    size_t salt_length,
                                    uint8_t *output,
                                    size_t output_size,
                                    size_t *output_length);
# 3206 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
typedef struct psa_key_derivation_s psa_key_derivation_operation_t;
# 3216 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
static psa_key_derivation_operation_t psa_key_derivation_operation_init(void);
# 3277 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_key_derivation_setup(
    psa_key_derivation_operation_t *operation,
    psa_algorithm_t alg);
# 3300 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_key_derivation_get_capacity(
    const psa_key_derivation_operation_t *operation,
    size_t *capacity);
# 3328 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_key_derivation_set_capacity(
    psa_key_derivation_operation_t *operation,
    size_t capacity);
# 3381 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_key_derivation_input_bytes(
    psa_key_derivation_operation_t *operation,
    psa_key_derivation_step_t step,
    const uint8_t *data,
    size_t data_length);
# 3424 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_key_derivation_input_integer(
    psa_key_derivation_operation_t *operation,
    psa_key_derivation_step_t step,
    uint64_t value);
# 3492 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_key_derivation_input_key(
    psa_key_derivation_operation_t *operation,
    psa_key_derivation_step_t step,
    mbedtls_svc_key_id_t key);
# 3560 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_key_derivation_key_agreement(
    psa_key_derivation_operation_t *operation,
    psa_key_derivation_step_t step,
    mbedtls_svc_key_id_t private_key,
    const uint8_t *peer_key,
    size_t peer_key_length);
# 3607 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_key_derivation_output_bytes(
    psa_key_derivation_operation_t *operation,
    uint8_t *output,
    size_t output_length);
# 3762 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_key_derivation_output_key(
    const psa_key_attributes_t *attributes,
    psa_key_derivation_operation_t *operation,
    mbedtls_svc_key_id_t *key);
# 3837 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_key_derivation_output_key_ext(
    const psa_key_attributes_t *attributes,
    psa_key_derivation_operation_t *operation,
    const psa_key_production_parameters_t *params,
    size_t params_data_length,
    mbedtls_svc_key_id_t *key);
# 3897 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_key_derivation_verify_bytes(
    psa_key_derivation_operation_t *operation,
    const uint8_t *expected_output,
    size_t output_length);
# 3962 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_key_derivation_verify_key(
    psa_key_derivation_operation_t *operation,
    psa_key_id_t expected);
# 3989 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_key_derivation_abort(
    psa_key_derivation_operation_t *operation);
# 4042 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_raw_key_agreement(psa_algorithm_t alg,
                                   mbedtls_svc_key_id_t private_key,
                                   const uint8_t *peer_key,
                                   size_t peer_key_length,
                                   uint8_t *output,
                                   size_t output_size,
                                   size_t *output_length);
# 4080 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_generate_random(uint8_t *output,
                                 size_t output_size);
# 4131 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_generate_key(const psa_key_attributes_t *attributes,
                              mbedtls_svc_key_id_t *key);
# 4183 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_generate_key_ext(const psa_key_attributes_t *attributes,
                                  const psa_key_production_parameters_t *params,
                                  size_t params_data_length,
                                  mbedtls_svc_key_id_t *key);
# 4225 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
typedef struct psa_sign_hash_interruptible_operation_s psa_sign_hash_interruptible_operation_t;
# 4258 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
typedef struct psa_verify_hash_interruptible_operation_s psa_verify_hash_interruptible_operation_t;
# 4332 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
void psa_interruptible_set_max_ops(uint32_t max_ops);
# 4351 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
uint32_t psa_interruptible_get_max_ops(void);
# 4379 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
uint32_t psa_sign_hash_get_num_ops(
    const psa_sign_hash_interruptible_operation_t *operation);
# 4406 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
uint32_t psa_verify_hash_get_num_ops(
    const psa_verify_hash_interruptible_operation_t *operation);
# 4480 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_sign_hash_start(
    psa_sign_hash_interruptible_operation_t *operation,
    mbedtls_svc_key_id_t key, psa_algorithm_t alg,
    const uint8_t *hash, size_t hash_length);
# 4573 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_sign_hash_complete(
    psa_sign_hash_interruptible_operation_t *operation,
    uint8_t *signature, size_t signature_size,
    size_t *signature_length);
# 4615 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_sign_hash_abort(
    psa_sign_hash_interruptible_operation_t *operation);
# 4692 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_verify_hash_start(
    psa_verify_hash_interruptible_operation_t *operation,
    mbedtls_svc_key_id_t key, psa_algorithm_t alg,
    const uint8_t *hash, size_t hash_length,
    const uint8_t *signature, size_t signature_length);
# 4769 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_verify_hash_complete(
    psa_verify_hash_interruptible_operation_t *operation);
# 4809 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
psa_status_t psa_verify_hash_abort(
    psa_verify_hash_interruptible_operation_t *operation);
# 4821 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_sizes.h" 1
# 4822 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h" 2






# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h" 1
# 68 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_contexts_primitives.h" 1
# 36 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_contexts_primitives.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_common.h" 1
# 51 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_common.h"
typedef enum {
    PSA_CRYPTO_DRIVER_DECRYPT,
    PSA_CRYPTO_DRIVER_ENCRYPT
} psa_encrypt_or_decrypt_t;
# 37 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_contexts_primitives.h" 2


# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_primitives.h" 1
# 31 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_primitives.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md5.h" 1
# 51 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md5.h"
typedef struct mbedtls_md5_context {
    uint32_t private_total[2];
    uint32_t private_state[4];
    unsigned char private_buffer[64];
}
mbedtls_md5_context;
# 72 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md5.h"
void mbedtls_md5_init(mbedtls_md5_context *ctx);
# 84 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md5.h"
void mbedtls_md5_free(mbedtls_md5_context *ctx);
# 97 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md5.h"
void mbedtls_md5_clone(mbedtls_md5_context *dst,
                       const mbedtls_md5_context *src);
# 112 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md5.h"
int mbedtls_md5_starts(mbedtls_md5_context *ctx);
# 128 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md5.h"
int mbedtls_md5_update(mbedtls_md5_context *ctx,
                       const unsigned char *input,
                       size_t ilen);
# 145 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md5.h"
int mbedtls_md5_finish(mbedtls_md5_context *ctx,
                       unsigned char output[16]);
# 161 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md5.h"
int mbedtls_internal_md5_process(mbedtls_md5_context *ctx,
                                 const unsigned char data[64]);
# 178 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md5.h"
int mbedtls_md5(const unsigned char *input,
                size_t ilen,
                unsigned char output[16]);
# 32 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_primitives.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ripemd160.h" 1
# 42 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ripemd160.h"
typedef struct mbedtls_ripemd160_context {
    uint32_t private_total[2];
    uint32_t private_state[5];
    unsigned char private_buffer[64];
}
mbedtls_ripemd160_context;
# 58 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ripemd160.h"
void mbedtls_ripemd160_init(mbedtls_ripemd160_context *ctx);






void mbedtls_ripemd160_free(mbedtls_ripemd160_context *ctx);







void mbedtls_ripemd160_clone(mbedtls_ripemd160_context *dst,
                             const mbedtls_ripemd160_context *src);
# 83 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ripemd160.h"
int mbedtls_ripemd160_starts(mbedtls_ripemd160_context *ctx);
# 94 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ripemd160.h"
int mbedtls_ripemd160_update(mbedtls_ripemd160_context *ctx,
                             const unsigned char *input,
                             size_t ilen);
# 106 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ripemd160.h"
int mbedtls_ripemd160_finish(mbedtls_ripemd160_context *ctx,
                             unsigned char output[20]);
# 117 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ripemd160.h"
int mbedtls_internal_ripemd160_process(mbedtls_ripemd160_context *ctx,
                                       const unsigned char data[64]);
# 129 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ripemd160.h"
int mbedtls_ripemd160(const unsigned char *input,
                      size_t ilen,
                      unsigned char output[20]);
# 33 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_primitives.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha1.h" 1
# 57 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha1.h"
typedef struct mbedtls_sha1_context {
    uint32_t private_total[2];
    uint32_t private_state[5];
    unsigned char private_buffer[64];
}
mbedtls_sha1_context;
# 79 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha1.h"
void mbedtls_sha1_init(mbedtls_sha1_context *ctx);
# 94 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha1.h"
void mbedtls_sha1_free(mbedtls_sha1_context *ctx);
# 107 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha1.h"
void mbedtls_sha1_clone(mbedtls_sha1_context *dst,
                        const mbedtls_sha1_context *src);
# 123 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha1.h"
int mbedtls_sha1_starts(mbedtls_sha1_context *ctx);
# 142 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha1.h"
int mbedtls_sha1_update(mbedtls_sha1_context *ctx,
                        const unsigned char *input,
                        size_t ilen);
# 162 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha1.h"
int mbedtls_sha1_finish(mbedtls_sha1_context *ctx,
                        unsigned char output[20]);
# 180 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha1.h"
int mbedtls_internal_sha1_process(mbedtls_sha1_context *ctx,
                                  const unsigned char data[64]);
# 206 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha1.h"
int mbedtls_sha1(const unsigned char *input,
                 size_t ilen,
                 unsigned char output[20]);
# 34 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_primitives.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha256.h" 1
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha256.h"
typedef struct mbedtls_sha256_context {
    unsigned char private_buffer[64];
    uint32_t private_total[2];
    uint32_t private_state[8];

    int private_is224;


}
mbedtls_sha256_context;
# 60 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha256.h"
void mbedtls_sha256_init(mbedtls_sha256_context *ctx);
# 69 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha256.h"
void mbedtls_sha256_free(mbedtls_sha256_context *ctx);







void mbedtls_sha256_clone(mbedtls_sha256_context *dst,
                          const mbedtls_sha256_context *src);
# 95 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha256.h"
int mbedtls_sha256_starts(mbedtls_sha256_context *ctx, int is224);
# 110 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha256.h"
int mbedtls_sha256_update(mbedtls_sha256_context *ctx,
                          const unsigned char *input,
                          size_t ilen);
# 127 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha256.h"
int mbedtls_sha256_finish(mbedtls_sha256_context *ctx,
                          unsigned char *output);
# 142 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha256.h"
int mbedtls_internal_sha256_process(mbedtls_sha256_context *ctx,
                                    const unsigned char data[64]);
# 167 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha256.h"
int mbedtls_sha256(const unsigned char *input,
                   size_t ilen,
                   unsigned char *output,
                   int is224);
# 35 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_primitives.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha512.h" 1
# 51 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha512.h"
typedef struct mbedtls_sha512_context {
    uint64_t private_total[2];
    uint64_t private_state[8];
    unsigned char private_buffer[128];

    int private_is384;


}
mbedtls_sha512_context;
# 72 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha512.h"
void mbedtls_sha512_init(mbedtls_sha512_context *ctx);
# 82 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha512.h"
void mbedtls_sha512_free(mbedtls_sha512_context *ctx);







void mbedtls_sha512_clone(mbedtls_sha512_context *dst,
                          const mbedtls_sha512_context *src);
# 108 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha512.h"
int mbedtls_sha512_starts(mbedtls_sha512_context *ctx, int is384);
# 123 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha512.h"
int mbedtls_sha512_update(mbedtls_sha512_context *ctx,
                          const unsigned char *input,
                          size_t ilen);
# 140 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha512.h"
int mbedtls_sha512_finish(mbedtls_sha512_context *ctx,
                          unsigned char *output);
# 155 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha512.h"
int mbedtls_internal_sha512_process(mbedtls_sha512_context *ctx,
                                    const unsigned char data[128]);
# 187 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha512.h"
int mbedtls_sha512(const unsigned char *input,
                   size_t ilen,
                   unsigned char *output,
                   int is384);
# 36 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_primitives.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha3.h" 1
# 37 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha3.h"
typedef enum {
    MBEDTLS_SHA3_NONE = 0,
    MBEDTLS_SHA3_224,
    MBEDTLS_SHA3_256,
    MBEDTLS_SHA3_384,
    MBEDTLS_SHA3_512,
} mbedtls_sha3_id;






typedef struct {
    uint64_t private_state[25];
    uint32_t private_index;
    uint16_t private_olen;
    uint16_t private_max_block_size;
}
mbedtls_sha3_context;






void mbedtls_sha3_init(mbedtls_sha3_context *ctx);
# 72 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha3.h"
void mbedtls_sha3_free(mbedtls_sha3_context *ctx);







void mbedtls_sha3_clone(mbedtls_sha3_context *dst,
                        const mbedtls_sha3_context *src);
# 93 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha3.h"
int mbedtls_sha3_starts(mbedtls_sha3_context *ctx, mbedtls_sha3_id id);
# 108 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha3.h"
int mbedtls_sha3_update(mbedtls_sha3_context *ctx,
                        const uint8_t *input,
                        size_t ilen);
# 127 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha3.h"
int mbedtls_sha3_finish(mbedtls_sha3_context *ctx,
                        uint8_t *output, size_t olen);
# 153 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/sha3.h"
int mbedtls_sha3(mbedtls_sha3_id id, const uint8_t *input,
                 size_t ilen,
                 uint8_t *output,
                 size_t olen);
# 37 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_primitives.h" 2
# 52 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_primitives.h"
typedef struct {
    psa_algorithm_t private_alg;
    union {
        unsigned dummy;

        mbedtls_md5_context md5;





        mbedtls_sha1_context sha1;



        mbedtls_sha256_context sha256;



        mbedtls_sha512_context sha512;







    } private_ctx;
} mbedtls_psa_hash_operation_t;







# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h" 1
# 66 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
typedef enum {
    MBEDTLS_CIPHER_ID_NONE = 0,
    MBEDTLS_CIPHER_ID_NULL,
    MBEDTLS_CIPHER_ID_AES,
    MBEDTLS_CIPHER_ID_DES,
    MBEDTLS_CIPHER_ID_3DES,
    MBEDTLS_CIPHER_ID_CAMELLIA,
    MBEDTLS_CIPHER_ID_ARIA,
    MBEDTLS_CIPHER_ID_CHACHA20,
} mbedtls_cipher_id_t;
# 84 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
typedef enum {
    MBEDTLS_CIPHER_NONE = 0,
    MBEDTLS_CIPHER_NULL,
    MBEDTLS_CIPHER_AES_128_ECB,
    MBEDTLS_CIPHER_AES_192_ECB,
    MBEDTLS_CIPHER_AES_256_ECB,
    MBEDTLS_CIPHER_AES_128_CBC,
    MBEDTLS_CIPHER_AES_192_CBC,
    MBEDTLS_CIPHER_AES_256_CBC,
    MBEDTLS_CIPHER_AES_128_CFB128,
    MBEDTLS_CIPHER_AES_192_CFB128,
    MBEDTLS_CIPHER_AES_256_CFB128,
    MBEDTLS_CIPHER_AES_128_CTR,
    MBEDTLS_CIPHER_AES_192_CTR,
    MBEDTLS_CIPHER_AES_256_CTR,
    MBEDTLS_CIPHER_AES_128_GCM,
    MBEDTLS_CIPHER_AES_192_GCM,
    MBEDTLS_CIPHER_AES_256_GCM,
    MBEDTLS_CIPHER_CAMELLIA_128_ECB,
    MBEDTLS_CIPHER_CAMELLIA_192_ECB,
    MBEDTLS_CIPHER_CAMELLIA_256_ECB,
    MBEDTLS_CIPHER_CAMELLIA_128_CBC,
    MBEDTLS_CIPHER_CAMELLIA_192_CBC,
    MBEDTLS_CIPHER_CAMELLIA_256_CBC,
    MBEDTLS_CIPHER_CAMELLIA_128_CFB128,
    MBEDTLS_CIPHER_CAMELLIA_192_CFB128,
    MBEDTLS_CIPHER_CAMELLIA_256_CFB128,
    MBEDTLS_CIPHER_CAMELLIA_128_CTR,
    MBEDTLS_CIPHER_CAMELLIA_192_CTR,
    MBEDTLS_CIPHER_CAMELLIA_256_CTR,
    MBEDTLS_CIPHER_CAMELLIA_128_GCM,
    MBEDTLS_CIPHER_CAMELLIA_192_GCM,
    MBEDTLS_CIPHER_CAMELLIA_256_GCM,
    MBEDTLS_CIPHER_DES_ECB,
    MBEDTLS_CIPHER_DES_CBC,
    MBEDTLS_CIPHER_DES_EDE_ECB,
    MBEDTLS_CIPHER_DES_EDE_CBC,
    MBEDTLS_CIPHER_DES_EDE3_ECB,
    MBEDTLS_CIPHER_DES_EDE3_CBC,
    MBEDTLS_CIPHER_AES_128_CCM,
    MBEDTLS_CIPHER_AES_192_CCM,
    MBEDTLS_CIPHER_AES_256_CCM,
    MBEDTLS_CIPHER_AES_128_CCM_STAR_NO_TAG,
    MBEDTLS_CIPHER_AES_192_CCM_STAR_NO_TAG,
    MBEDTLS_CIPHER_AES_256_CCM_STAR_NO_TAG,
    MBEDTLS_CIPHER_CAMELLIA_128_CCM,
    MBEDTLS_CIPHER_CAMELLIA_192_CCM,
    MBEDTLS_CIPHER_CAMELLIA_256_CCM,
    MBEDTLS_CIPHER_CAMELLIA_128_CCM_STAR_NO_TAG,
    MBEDTLS_CIPHER_CAMELLIA_192_CCM_STAR_NO_TAG,
    MBEDTLS_CIPHER_CAMELLIA_256_CCM_STAR_NO_TAG,
    MBEDTLS_CIPHER_ARIA_128_ECB,
    MBEDTLS_CIPHER_ARIA_192_ECB,
    MBEDTLS_CIPHER_ARIA_256_ECB,
    MBEDTLS_CIPHER_ARIA_128_CBC,
    MBEDTLS_CIPHER_ARIA_192_CBC,
    MBEDTLS_CIPHER_ARIA_256_CBC,
    MBEDTLS_CIPHER_ARIA_128_CFB128,
    MBEDTLS_CIPHER_ARIA_192_CFB128,
    MBEDTLS_CIPHER_ARIA_256_CFB128,
    MBEDTLS_CIPHER_ARIA_128_CTR,
    MBEDTLS_CIPHER_ARIA_192_CTR,
    MBEDTLS_CIPHER_ARIA_256_CTR,
    MBEDTLS_CIPHER_ARIA_128_GCM,
    MBEDTLS_CIPHER_ARIA_192_GCM,
    MBEDTLS_CIPHER_ARIA_256_GCM,
    MBEDTLS_CIPHER_ARIA_128_CCM,
    MBEDTLS_CIPHER_ARIA_192_CCM,
    MBEDTLS_CIPHER_ARIA_256_CCM,
    MBEDTLS_CIPHER_ARIA_128_CCM_STAR_NO_TAG,
    MBEDTLS_CIPHER_ARIA_192_CCM_STAR_NO_TAG,
    MBEDTLS_CIPHER_ARIA_256_CCM_STAR_NO_TAG,
    MBEDTLS_CIPHER_AES_128_OFB,
    MBEDTLS_CIPHER_AES_192_OFB,
    MBEDTLS_CIPHER_AES_256_OFB,
    MBEDTLS_CIPHER_AES_128_XTS,
    MBEDTLS_CIPHER_AES_256_XTS,
    MBEDTLS_CIPHER_CHACHA20,
    MBEDTLS_CIPHER_CHACHA20_POLY1305,
    MBEDTLS_CIPHER_AES_128_KW,
    MBEDTLS_CIPHER_AES_192_KW,
    MBEDTLS_CIPHER_AES_256_KW,
    MBEDTLS_CIPHER_AES_128_KWP,
    MBEDTLS_CIPHER_AES_192_KWP,
    MBEDTLS_CIPHER_AES_256_KWP,
} mbedtls_cipher_type_t;


typedef enum {
    MBEDTLS_MODE_NONE = 0,
    MBEDTLS_MODE_ECB,
    MBEDTLS_MODE_CBC,
    MBEDTLS_MODE_CFB,
    MBEDTLS_MODE_OFB,
    MBEDTLS_MODE_CTR,
    MBEDTLS_MODE_GCM,
    MBEDTLS_MODE_STREAM,
    MBEDTLS_MODE_CCM,
    MBEDTLS_MODE_CCM_STAR_NO_TAG,
    MBEDTLS_MODE_XTS,
    MBEDTLS_MODE_CHACHAPOLY,
    MBEDTLS_MODE_KW,
    MBEDTLS_MODE_KWP,
} mbedtls_cipher_mode_t;


typedef enum {
    MBEDTLS_PADDING_PKCS7 = 0,
    MBEDTLS_PADDING_ONE_AND_ZEROS,
    MBEDTLS_PADDING_ZEROS_AND_LEN,
    MBEDTLS_PADDING_ZEROS,
    MBEDTLS_PADDING_NONE,
} mbedtls_cipher_padding_t;


typedef enum {
    MBEDTLS_OPERATION_NONE = -1,
    MBEDTLS_DECRYPT = 0,
    MBEDTLS_ENCRYPT,
} mbedtls_operation_t;

enum {

    MBEDTLS_KEY_LENGTH_NONE = 0,

    MBEDTLS_KEY_LENGTH_DES = 64,

    MBEDTLS_KEY_LENGTH_DES_EDE = 128,

    MBEDTLS_KEY_LENGTH_DES_EDE3 = 192,
};
# 244 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
typedef struct mbedtls_cipher_base_t mbedtls_cipher_base_t;




typedef struct mbedtls_cmac_context_t mbedtls_cmac_context_t;
# 266 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
typedef struct mbedtls_cipher_info_t {

    const char *private_name;


    unsigned int private_block_size : 5;





    unsigned int private_iv_size : 3;





    unsigned int private_key_bitlen : 4;




    unsigned int private_mode : 4;







    unsigned int private_type : 8;





    unsigned int private_flags : 2;


    unsigned int private_base_idx : 5;

} mbedtls_cipher_info_t;
# 316 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
typedef struct mbedtls_cipher_context_t {

    const mbedtls_cipher_info_t *private_cipher_info;


    int private_key_bitlen;




    mbedtls_operation_t private_operation;





    void(*private_add_padding)(unsigned char *output, size_t olen, size_t data_len);
    int(*private_get_padding)(unsigned char *input, size_t ilen, size_t *data_len);



    unsigned char private_unprocessed_data[16];


    size_t private_unprocessed_len;



    unsigned char private_iv[16];


    size_t private_iv_size;


    void *private_cipher_ctx;



    mbedtls_cmac_context_t *private_cmac_ctx;
# 368 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
} mbedtls_cipher_context_t;
# 383 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
const int *mbedtls_cipher_list(void);
# 396 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
const mbedtls_cipher_info_t *mbedtls_cipher_info_from_string(const char *cipher_name);
# 408 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
const mbedtls_cipher_info_t *mbedtls_cipher_info_from_type(const mbedtls_cipher_type_t cipher_type);
# 424 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
const mbedtls_cipher_info_t *mbedtls_cipher_info_from_values(const mbedtls_cipher_id_t cipher_id,
                                                             int key_bitlen,
                                                             const mbedtls_cipher_mode_t mode);
# 437 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline mbedtls_cipher_type_t mbedtls_cipher_info_get_type(
    const mbedtls_cipher_info_t *info)
{
    if (info == ((void*)0)) {
        return MBEDTLS_CIPHER_NONE;
    } else {
        return (mbedtls_cipher_type_t) info->private_type;
    }
}
# 456 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline mbedtls_cipher_mode_t mbedtls_cipher_info_get_mode(
    const mbedtls_cipher_info_t *info)
{
    if (info == ((void*)0)) {
        return MBEDTLS_MODE_NONE;
    } else {
        return (mbedtls_cipher_mode_t) info->private_mode;
    }
}
# 477 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline size_t mbedtls_cipher_info_get_key_bitlen(
    const mbedtls_cipher_info_t *info)
{
    if (info == ((void*)0)) {
        return 0;
    } else {
        return ((size_t) info->private_key_bitlen) << 6;
    }
}
# 498 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline const char *mbedtls_cipher_info_get_name(
    const mbedtls_cipher_info_t *info)
{
    if (info == ((void*)0)) {
        return ((void*)0);
    } else {
        return info->private_name;
    }
}
# 518 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline size_t mbedtls_cipher_info_get_iv_size(
    const mbedtls_cipher_info_t *info)
{
    if (info == ((void*)0)) {
        return 0;
    }

    return ((size_t) info->private_iv_size) << 2;
}
# 538 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline size_t mbedtls_cipher_info_get_block_size(
    const mbedtls_cipher_info_t *info)
{
    if (info == ((void*)0)) {
        return 0;
    }

    return (size_t) (info->private_block_size);
}
# 557 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline int mbedtls_cipher_info_has_variable_key_bitlen(
    const mbedtls_cipher_info_t *info)
{
    if (info == ((void*)0)) {
        return 0;
    }

    return info->private_flags & 0x02;
}
# 576 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline int mbedtls_cipher_info_has_variable_iv_size(
    const mbedtls_cipher_info_t *info)
{
    if (info == ((void*)0)) {
        return 0;
    }

    return info->private_flags & 0x01;
}






void mbedtls_cipher_init(mbedtls_cipher_context_t *ctx);
# 602 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
void mbedtls_cipher_free(mbedtls_cipher_context_t *ctx);
# 631 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
int mbedtls_cipher_setup(mbedtls_cipher_context_t *ctx,
                         const mbedtls_cipher_info_t *cipher_info);
# 678 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline unsigned int mbedtls_cipher_get_block_size(
    const mbedtls_cipher_context_t *ctx)
{
    if (ctx->private_cipher_info == ((void*)0)) {
        return 0;
    }

    return (unsigned int) ctx->private_cipher_info->private_block_size;
}
# 697 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline mbedtls_cipher_mode_t mbedtls_cipher_get_cipher_mode(
    const mbedtls_cipher_context_t *ctx)
{
    if (ctx->private_cipher_info == ((void*)0)) {
        return MBEDTLS_MODE_NONE;
    }

    return (mbedtls_cipher_mode_t) ctx->private_cipher_info->private_mode;
}
# 717 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline int mbedtls_cipher_get_iv_size(
    const mbedtls_cipher_context_t *ctx)
{
    if (ctx->private_cipher_info == ((void*)0)) {
        return 0;
    }

    if (ctx->private_iv_size != 0) {
        return (int) ctx->private_iv_size;
    }

    return (int) (((int) ctx->private_cipher_info->private_iv_size) <<
                  2);
}
# 740 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline mbedtls_cipher_type_t mbedtls_cipher_get_type(
    const mbedtls_cipher_context_t *ctx)
{
    if (ctx->private_cipher_info == ((void*)0)) {
        return MBEDTLS_CIPHER_NONE;
    }

    return (mbedtls_cipher_type_t) ctx->private_cipher_info->private_type;
}
# 759 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline const char *mbedtls_cipher_get_name(
    const mbedtls_cipher_context_t *ctx)
{
    if (ctx->private_cipher_info == ((void*)0)) {
        return 0;
    }

    return ctx->private_cipher_info->private_name;
}
# 778 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline int mbedtls_cipher_get_key_bitlen(
    const mbedtls_cipher_context_t *ctx)
{
    if (ctx->private_cipher_info == ((void*)0)) {
        return MBEDTLS_KEY_LENGTH_NONE;
    }

    return (int) ctx->private_cipher_info->private_key_bitlen <<
           6;
}
# 797 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
static inline mbedtls_operation_t mbedtls_cipher_get_operation(
    const mbedtls_cipher_context_t *ctx)
{
    if (ctx->private_cipher_info == ((void*)0)) {
        return MBEDTLS_OPERATION_NONE;
    }

    return ctx->private_operation;
}
# 823 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
int mbedtls_cipher_setkey(mbedtls_cipher_context_t *ctx,
                          const unsigned char *key,
                          int key_bitlen,
                          const mbedtls_operation_t operation);
# 844 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
int mbedtls_cipher_set_padding_mode(mbedtls_cipher_context_t *ctx,
                                    mbedtls_cipher_padding_t mode);
# 872 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
int mbedtls_cipher_set_iv(mbedtls_cipher_context_t *ctx,
                          const unsigned char *iv,
                          size_t iv_len);
# 908 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
int mbedtls_cipher_reset(mbedtls_cipher_context_t *ctx);
# 923 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
int mbedtls_cipher_update_ad(mbedtls_cipher_context_t *ctx,
                             const unsigned char *ad, size_t ad_len);
# 956 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
int mbedtls_cipher_update(mbedtls_cipher_context_t *ctx,
                          const unsigned char *input,
                          size_t ilen, unsigned char *output,
                          size_t *olen);
# 983 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
int mbedtls_cipher_finish(mbedtls_cipher_context_t *ctx,
                          unsigned char *output, size_t *olen);
# 1003 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
int mbedtls_cipher_write_tag(mbedtls_cipher_context_t *ctx,
                             unsigned char *tag, size_t tag_len);
# 1019 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
int mbedtls_cipher_check_tag(mbedtls_cipher_context_t *ctx,
                             const unsigned char *tag, size_t tag_len);
# 1056 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
int mbedtls_cipher_crypt(mbedtls_cipher_context_t *ctx,
                         const unsigned char *iv, size_t iv_len,
                         const unsigned char *input, size_t ilen,
                         unsigned char *output, size_t *olen);
# 1106 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
int mbedtls_cipher_auth_encrypt_ext(mbedtls_cipher_context_t *ctx,
                                    const unsigned char *iv, size_t iv_len,
                                    const unsigned char *ad, size_t ad_len,
                                    const unsigned char *input, size_t ilen,
                                    unsigned char *output, size_t output_len,
                                    size_t *olen, size_t tag_len);
# 1162 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cipher.h"
int mbedtls_cipher_auth_decrypt_ext(mbedtls_cipher_context_t *ctx,
                                    const unsigned char *iv, size_t iv_len,
                                    const unsigned char *ad, size_t ad_len,
                                    const unsigned char *input, size_t ilen,
                                    unsigned char *output, size_t output_len,
                                    size_t *olen, size_t tag_len);
# 89 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_primitives.h" 2
# 101 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_primitives.h"
typedef struct {

    psa_algorithm_t private_alg;
    uint8_t private_iv_length;
    uint8_t private_block_length;
    union {
        unsigned int private_dummy;
        mbedtls_cipher_context_t private_cipher;
    } private_ctx;
} mbedtls_psa_cipher_operation_t;
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_contexts_primitives.h" 2
# 99 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_contexts_primitives.h"
typedef union {
    unsigned dummy;
    mbedtls_psa_hash_operation_t mbedtls_ctx;



} psa_driver_hash_context_t;

typedef union {
    unsigned dummy;
    mbedtls_psa_cipher_operation_t mbedtls_ctx;




} psa_driver_cipher_context_t;
# 69 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h" 2

struct psa_hash_operation_s {
# 80 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h"
    unsigned int private_id;
    psa_driver_hash_context_t private_ctx;

};





static inline struct psa_hash_operation_s psa_hash_operation_init(void)
{
    const struct psa_hash_operation_s v = { 0, { 0 } };
    return v;
}

struct psa_cipher_operation_s {
# 105 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h"
    unsigned int private_id;

    unsigned int private_iv_required : 1;
    unsigned int private_iv_set : 1;

    uint8_t private_default_iv_length;

    psa_driver_cipher_context_t private_ctx;

};






static inline struct psa_cipher_operation_s psa_cipher_operation_init(void)
{
    const struct psa_cipher_operation_s v = { 0, 0, 0, 0, { 0 } };
    return v;
}



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_contexts_composites.h" 1
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_contexts_composites.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_composites.h" 1
# 27 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_composites.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cmac.h" 1
# 59 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cmac.h"
struct mbedtls_cmac_context_t {

    unsigned char private_state[16];



    unsigned char private_unprocessed_block[16];


    size_t private_unprocessed_len;
};
# 105 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cmac.h"
int mbedtls_cipher_cmac_starts(mbedtls_cipher_context_t *ctx,
                               const unsigned char *key, size_t keybits);
# 130 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cmac.h"
int mbedtls_cipher_cmac_update(mbedtls_cipher_context_t *ctx,
                               const unsigned char *input, size_t ilen);
# 149 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cmac.h"
int mbedtls_cipher_cmac_finish(mbedtls_cipher_context_t *ctx,
                               unsigned char *output);
# 168 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cmac.h"
int mbedtls_cipher_cmac_reset(mbedtls_cipher_context_t *ctx);
# 197 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cmac.h"
int mbedtls_cipher_cmac(const mbedtls_cipher_info_t *cipher_info,
                        const unsigned char *key, size_t keylen,
                        const unsigned char *input, size_t ilen,
                        unsigned char *output);
# 220 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/cmac.h"
int mbedtls_aes_cmac_prf_128(const unsigned char *key, size_t key_len,
                             const unsigned char *input, size_t in_len,
                             unsigned char output[16]);
# 28 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_composites.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/gcm.h" 1
# 58 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/gcm.h"
typedef struct mbedtls_gcm_context {



    mbedtls_cipher_context_t private_cipher_ctx;

    uint64_t private_H[16][2];
    uint64_t private_len;
    uint64_t private_add_len;
    unsigned char private_base_ectr[16];
    unsigned char private_y[16];
    unsigned char private_buf[16];
    unsigned char private_mode;


    unsigned char private_acceleration;
}
mbedtls_gcm_context;
# 92 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/gcm.h"
void mbedtls_gcm_init(mbedtls_gcm_context *ctx);
# 110 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/gcm.h"
int mbedtls_gcm_setkey(mbedtls_gcm_context *ctx,
                       mbedtls_cipher_id_t cipher,
                       const unsigned char *key,
                       unsigned int keybits);
# 166 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/gcm.h"
int mbedtls_gcm_crypt_and_tag(mbedtls_gcm_context *ctx,
                              int mode,
                              size_t length,
                              const unsigned char *iv,
                              size_t iv_len,
                              const unsigned char *add,
                              size_t add_len,
                              const unsigned char *input,
                              unsigned char *output,
                              size_t tag_len,
                              unsigned char *tag);
# 211 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/gcm.h"
int mbedtls_gcm_auth_decrypt(mbedtls_gcm_context *ctx,
                             size_t length,
                             const unsigned char *iv,
                             size_t iv_len,
                             const unsigned char *add,
                             size_t add_len,
                             const unsigned char *tag,
                             size_t tag_len,
                             const unsigned char *input,
                             unsigned char *output);
# 235 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/gcm.h"
int mbedtls_gcm_starts(mbedtls_gcm_context *ctx,
                       int mode,
                       const unsigned char *iv,
                       size_t iv_len);
# 260 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/gcm.h"
int mbedtls_gcm_update_ad(mbedtls_gcm_context *ctx,
                          const unsigned char *add,
                          size_t add_len);
# 315 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/gcm.h"
int mbedtls_gcm_update(mbedtls_gcm_context *ctx,
                       const unsigned char *input, size_t input_length,
                       unsigned char *output, size_t output_size,
                       size_t *output_length);
# 353 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/gcm.h"
int mbedtls_gcm_finish(mbedtls_gcm_context *ctx,
                       unsigned char *output, size_t output_size,
                       size_t *output_length,
                       unsigned char *tag, size_t tag_len);
# 365 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/gcm.h"
void mbedtls_gcm_free(mbedtls_gcm_context *ctx);
# 30 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_composites.h" 2




# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h" 1
# 39 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/poly1305.h" 1
# 50 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/poly1305.h"
typedef struct mbedtls_poly1305_context {
    uint32_t private_r[4];
    uint32_t private_s[4];
    uint32_t private_acc[5];
    uint8_t private_queue[16];
    size_t private_queue_len;
}
mbedtls_poly1305_context;
# 78 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/poly1305.h"
void mbedtls_poly1305_init(mbedtls_poly1305_context *ctx);
# 88 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/poly1305.h"
void mbedtls_poly1305_free(mbedtls_poly1305_context *ctx);
# 103 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/poly1305.h"
int mbedtls_poly1305_starts(mbedtls_poly1305_context *ctx,
                            const unsigned char key[32]);
# 124 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/poly1305.h"
int mbedtls_poly1305_update(mbedtls_poly1305_context *ctx,
                            const unsigned char *input,
                            size_t ilen);
# 140 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/poly1305.h"
int mbedtls_poly1305_finish(mbedtls_poly1305_context *ctx,
                            unsigned char mac[16]);
# 161 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/poly1305.h"
int mbedtls_poly1305_mac(const unsigned char key[32],
                         const unsigned char *input,
                         size_t ilen,
                         unsigned char mac[16]);
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h" 2
# 50 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h"
typedef enum {
    MBEDTLS_CHACHAPOLY_ENCRYPT,
    MBEDTLS_CHACHAPOLY_DECRYPT
}
mbedtls_chachapoly_mode_t;



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chacha20.h" 1
# 50 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chacha20.h"
typedef struct mbedtls_chacha20_context {
    uint32_t private_state[16];
    uint8_t private_keystream8[64];
    size_t private_keystream_bytes_used;
}
mbedtls_chacha20_context;
# 76 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chacha20.h"
void mbedtls_chacha20_init(mbedtls_chacha20_context *ctx);
# 87 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chacha20.h"
void mbedtls_chacha20_free(mbedtls_chacha20_context *ctx);
# 105 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chacha20.h"
int mbedtls_chacha20_setkey(mbedtls_chacha20_context *ctx,
                            const unsigned char key[32]);
# 127 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chacha20.h"
int mbedtls_chacha20_starts(mbedtls_chacha20_context *ctx,
                            const unsigned char nonce[12],
                            uint32_t counter);
# 160 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chacha20.h"
int mbedtls_chacha20_update(mbedtls_chacha20_context *ctx,
                            size_t size,
                            const unsigned char *input,
                            unsigned char *output);
# 193 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chacha20.h"
int mbedtls_chacha20_crypt(const unsigned char key[32],
                           const unsigned char nonce[12],
                           uint32_t counter,
                           size_t size,
                           const unsigned char *input,
                           unsigned char *output);
# 59 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h" 2

typedef struct mbedtls_chachapoly_context {
    mbedtls_chacha20_context private_chacha20_ctx;
    mbedtls_poly1305_context private_poly1305_ctx;
    uint64_t private_aad_len;
    uint64_t private_ciphertext_len;
    int private_state;
    mbedtls_chachapoly_mode_t private_mode;
}
mbedtls_chachapoly_context;
# 116 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h"
void mbedtls_chachapoly_init(mbedtls_chachapoly_context *ctx);
# 125 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h"
void mbedtls_chachapoly_free(mbedtls_chachapoly_context *ctx);
# 138 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h"
int mbedtls_chachapoly_setkey(mbedtls_chachapoly_context *ctx,
                              const unsigned char key[32]);
# 166 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h"
int mbedtls_chachapoly_starts(mbedtls_chachapoly_context *ctx,
                              const unsigned char nonce[12],
                              mbedtls_chachapoly_mode_t mode);
# 209 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h"
int mbedtls_chachapoly_update_aad(mbedtls_chachapoly_context *ctx,
                                  const unsigned char *aad,
                                  size_t aad_len);
# 244 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h"
int mbedtls_chachapoly_update(mbedtls_chachapoly_context *ctx,
                              size_t len,
                              const unsigned char *input,
                              unsigned char *output);
# 265 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h"
int mbedtls_chachapoly_finish(mbedtls_chachapoly_context *ctx,
                              unsigned char mac[16]);
# 297 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h"
int mbedtls_chachapoly_encrypt_and_tag(mbedtls_chachapoly_context *ctx,
                                       size_t length,
                                       const unsigned char nonce[12],
                                       const unsigned char *aad,
                                       size_t aad_len,
                                       const unsigned char *input,
                                       unsigned char *output,
                                       unsigned char tag[16]);
# 331 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/chachapoly.h"
int mbedtls_chachapoly_auth_decrypt(mbedtls_chachapoly_context *ctx,
                                    size_t length,
                                    const unsigned char nonce[12],
                                    const unsigned char *aad,
                                    size_t aad_len,
                                    const unsigned char tag[16],
                                    const unsigned char *input,
                                    unsigned char *output);
# 35 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_composites.h" 2
# 45 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_composites.h"
typedef struct {

    psa_algorithm_t private_alg;

    struct psa_hash_operation_s hash_ctx;

    uint8_t private_opad[128u];
} mbedtls_psa_hmac_operation_t;




typedef struct {
    psa_algorithm_t private_alg;
    union {
        unsigned private_dummy;

        mbedtls_psa_hmac_operation_t private_hmac;


        mbedtls_cipher_context_t private_cmac;

    } private_ctx;
} mbedtls_psa_mac_operation_t;
# 79 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_composites.h"
typedef struct {
    psa_algorithm_t private_alg;
    psa_key_type_t private_key_type;

    unsigned int private_is_encrypt : 1;

    uint8_t private_tag_length;

    union {
        unsigned dummy;




        mbedtls_gcm_context private_gcm;


        mbedtls_chachapoly_context private_chachapoly;


    } ctx;

} mbedtls_psa_aead_operation_t;






typedef struct {



    mbedtls_ecdsa_context *private_ctx;
    mbedtls_ecdsa_restart_ctx private_restart_ctx;

    uint32_t private_num_ops;

    size_t private_coordinate_bytes;
    psa_algorithm_t private_alg;
    mbedtls_md_type_t private_md_alg;
    uint8_t private_hash[(((521u) + 7u) / 8u)];
    size_t private_hash_length;
# 130 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_composites.h"
} mbedtls_psa_sign_hash_interruptible_operation_t;
# 142 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_composites.h"
typedef struct {




    mbedtls_ecdsa_context *private_ctx;
    mbedtls_ecdsa_restart_ctx private_restart_ctx;

    uint32_t private_num_ops;

    uint8_t private_hash[(((521u) + 7u) / 8u)];
    size_t private_hash_length;

    mbedtls_mpi private_r;
    mbedtls_mpi private_s;
# 166 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_composites.h"
} mbedtls_psa_verify_hash_interruptible_operation_t;
# 180 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_composites.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h" 1
# 42 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h"
typedef enum {
    MBEDTLS_ECJPAKE_CLIENT = 0,
    MBEDTLS_ECJPAKE_SERVER,
    MBEDTLS_ECJPAKE_NONE,
} mbedtls_ecjpake_role;
# 60 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h"
typedef struct mbedtls_ecjpake_context {
    mbedtls_md_type_t private_md_type;
    mbedtls_ecp_group private_grp;
    mbedtls_ecjpake_role private_role;
    int private_point_format;

    mbedtls_ecp_point private_Xm1;
    mbedtls_ecp_point private_Xm2;
    mbedtls_ecp_point private_Xp1;
    mbedtls_ecp_point private_Xp2;
    mbedtls_ecp_point private_Xp;

    mbedtls_mpi private_xm1;
    mbedtls_mpi private_xm2;

    mbedtls_mpi private_s;
} mbedtls_ecjpake_context;
# 88 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h"
void mbedtls_ecjpake_init(mbedtls_ecjpake_context *ctx);
# 111 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h"
int mbedtls_ecjpake_setup(mbedtls_ecjpake_context *ctx,
                          mbedtls_ecjpake_role role,
                          mbedtls_md_type_t hash,
                          mbedtls_ecp_group_id curve,
                          const unsigned char *secret,
                          size_t len);
# 130 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h"
int mbedtls_ecjpake_set_point_format(mbedtls_ecjpake_context *ctx,
                                     int point_format);
# 142 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h"
int mbedtls_ecjpake_check(const mbedtls_ecjpake_context *ctx);
# 163 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h"
int mbedtls_ecjpake_write_round_one(mbedtls_ecjpake_context *ctx,
                                    unsigned char *buf, size_t len, size_t *olen,
                                    int (*f_rng)(void *, unsigned char *, size_t),
                                    void *p_rng);
# 182 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h"
int mbedtls_ecjpake_read_round_one(mbedtls_ecjpake_context *ctx,
                                   const unsigned char *buf,
                                   size_t len);
# 204 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h"
int mbedtls_ecjpake_write_round_two(mbedtls_ecjpake_context *ctx,
                                    unsigned char *buf, size_t len, size_t *olen,
                                    int (*f_rng)(void *, unsigned char *, size_t),
                                    void *p_rng);
# 222 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h"
int mbedtls_ecjpake_read_round_two(mbedtls_ecjpake_context *ctx,
                                   const unsigned char *buf,
                                   size_t len);
# 244 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h"
int mbedtls_ecjpake_derive_secret(mbedtls_ecjpake_context *ctx,
                                  unsigned char *buf, size_t len, size_t *olen,
                                  int (*f_rng)(void *, unsigned char *, size_t),
                                  void *p_rng);
# 267 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h"
int mbedtls_ecjpake_write_shared_key(mbedtls_ecjpake_context *ctx,
                                     unsigned char *buf, size_t len, size_t *olen,
                                     int (*f_rng)(void *, unsigned char *, size_t),
                                     void *p_rng);
# 280 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/ecjpake.h"
void mbedtls_ecjpake_free(mbedtls_ecjpake_context *ctx);
# 181 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_composites.h" 2
# 191 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_composites.h"
typedef struct {
    psa_algorithm_t private_alg;

    uint8_t *private_password;
    size_t private_password_len;

    mbedtls_ecjpake_role private_role;
    uint8_t private_buffer[((3 + 1 + 65 + 1 + 65 + 1 + 32) * 2)];
    size_t private_buffer_length;
    size_t private_buffer_offset;


    union {
        unsigned int private_dummy;

        mbedtls_ecjpake_context private_jpake;

    } private_ctx;

} mbedtls_psa_pake_operation_t;
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_contexts_composites.h" 2
# 126 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_contexts_composites.h"
typedef union {
    unsigned dummy;
    mbedtls_psa_mac_operation_t mbedtls_ctx;




} psa_driver_mac_context_t;

typedef union {
    unsigned dummy;
    mbedtls_psa_aead_operation_t mbedtls_ctx;



} psa_driver_aead_context_t;

typedef union {
    unsigned dummy;
    mbedtls_psa_sign_hash_interruptible_operation_t mbedtls_ctx;
} psa_driver_sign_hash_interruptible_context_t;

typedef union {
    unsigned dummy;
    mbedtls_psa_verify_hash_interruptible_operation_t mbedtls_ctx;
} psa_driver_verify_hash_interruptible_context_t;

typedef union {
    unsigned dummy;
    mbedtls_psa_pake_operation_t mbedtls_ctx;




} psa_driver_pake_context_t;
# 130 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h" 2

struct psa_mac_operation_s {
# 141 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h"
    unsigned int private_id;
    uint8_t private_mac_size;
    unsigned int private_is_sign : 1;
    psa_driver_mac_context_t private_ctx;

};






static inline struct psa_mac_operation_s psa_mac_operation_init(void)
{
    const struct psa_mac_operation_s v = { 0, 0, 0, { 0 } };
    return v;
}

struct psa_aead_operation_s {
# 169 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h"
    unsigned int private_id;

    psa_algorithm_t private_alg;
    psa_key_type_t private_key_type;

    size_t private_ad_remaining;
    size_t private_body_remaining;

    unsigned int private_nonce_set : 1;
    unsigned int private_lengths_set : 1;
    unsigned int private_ad_started : 1;
    unsigned int private_body_started : 1;
    unsigned int private_is_encrypt : 1;

    psa_driver_aead_context_t private_ctx;

};






static inline struct psa_aead_operation_s psa_aead_operation_init(void)
{
    const struct psa_aead_operation_s v = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, { 0 } };
    return v;
}



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_contexts_key_derivation.h" 1
# 27 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_contexts_key_derivation.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_key_derivation.h" 1
# 30 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_builtin_key_derivation.h"
typedef struct {
    uint8_t *private_info;
    size_t private_info_length;



    uint8_t private_offset_in_block;
    uint8_t private_block_number;
    unsigned int private_state : 2;
    unsigned int private_info_set : 1;
    uint8_t private_output_block[64u];
    uint8_t private_prk[64u];
    struct psa_mac_operation_s private_hmac;
} psa_hkdf_key_derivation_t;




typedef struct {
    uint8_t private_data[32u];
} psa_tls12_ecjpake_to_pms_t;




typedef enum {
    PSA_TLS12_PRF_STATE_INIT,
    PSA_TLS12_PRF_STATE_SEED_SET,
    PSA_TLS12_PRF_STATE_OTHER_KEY_SET,
    PSA_TLS12_PRF_STATE_KEY_SET,
    PSA_TLS12_PRF_STATE_LABEL_SET,
    PSA_TLS12_PRF_STATE_OUTPUT
} psa_tls12_prf_key_derivation_state_t;

typedef struct psa_tls12_prf_key_derivation_s {






    uint8_t private_left_in_block;


    uint8_t private_block_number;

    psa_tls12_prf_key_derivation_state_t private_state;

    uint8_t *private_secret;
    size_t private_secret_length;
    uint8_t *private_seed;
    size_t private_seed_length;
    uint8_t *private_label;
    size_t private_label_length;

    uint8_t *private_other_secret;
    size_t private_other_secret_length;


    uint8_t private_Ai[64u];


    uint8_t private_output_block[64u];
} psa_tls12_prf_key_derivation_t;
# 28 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_driver_contexts_key_derivation.h" 2




typedef union {
    unsigned dummy;



    psa_hkdf_key_derivation_t private_hkdf;



    psa_tls12_prf_key_derivation_t private_tls12_prf;


    psa_tls12_ecjpake_to_pms_t private_tls12_ecjpake_to_pms;




} psa_driver_key_derivation_context_t;
# 201 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h" 2

struct psa_key_derivation_s {



    psa_algorithm_t private_alg;
    unsigned int private_can_output_key : 1;
    size_t private_capacity;
    psa_driver_key_derivation_context_t private_ctx;

};







static inline struct psa_key_derivation_s psa_key_derivation_operation_init(
    void)
{
    const struct psa_key_derivation_s v = { 0, 0, 0, { 0 } };
    return v;
}

struct psa_key_production_parameters_s {

    uint32_t flags;
    uint8_t data[];
};
# 242 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h"
struct psa_key_policy_s {
    psa_key_usage_t private_usage;
    psa_algorithm_t private_alg;
    psa_algorithm_t private_alg2;
};
typedef struct psa_key_policy_s psa_key_policy_t;


static inline struct psa_key_policy_s psa_key_policy_init(void)
{
    const struct psa_key_policy_s v = { 0, 0, 0 };
    return v;
}



typedef uint16_t psa_key_bits_t;
# 269 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h"
struct psa_key_attributes_s {




    psa_key_type_t private_type;
    psa_key_bits_t private_bits;
    psa_key_lifetime_t private_lifetime;
    psa_key_policy_t private_policy;
# 289 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h"
    mbedtls_svc_key_id_t private_id;
};
# 303 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h"
static inline struct psa_key_attributes_s psa_key_attributes_init(void)
{
    const struct psa_key_attributes_s v = { ((psa_key_type_t) 0x0000), 0, ((psa_key_lifetime_t) 0x00000000), { 0, 0, 0 }, ((psa_key_id_t) 0) };
    return v;
}

static inline void psa_set_key_id(psa_key_attributes_t *attributes,
                                  mbedtls_svc_key_id_t key)
{
    psa_key_lifetime_t lifetime = attributes->private_lifetime;

    attributes->private_id = key;

    if ((((psa_key_persistence_t) ((lifetime) & 0x000000ff)) == ((psa_key_persistence_t) 0x00))) {
        attributes->private_lifetime =
            ((((psa_key_location_t) ((lifetime) >> 8))) << 8 | (((psa_key_lifetime_t) 0x00000001)));


    }
}

static inline mbedtls_svc_key_id_t psa_get_key_id(
    const psa_key_attributes_t *attributes)
{
    return attributes->private_id;
}
# 338 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h"
static inline void psa_set_key_lifetime(psa_key_attributes_t *attributes,
                                        psa_key_lifetime_t lifetime)
{
    attributes->private_lifetime = lifetime;
    if ((((psa_key_persistence_t) ((lifetime) & 0x000000ff)) == ((psa_key_persistence_t) 0x00))) {



        attributes->private_id = 0;

    }
}

static inline psa_key_lifetime_t psa_get_key_lifetime(
    const psa_key_attributes_t *attributes)
{
    return attributes->private_lifetime;
}

static inline void psa_extend_key_usage_flags(psa_key_usage_t *usage_flags)
{
    if (*usage_flags & ((psa_key_usage_t) 0x00001000)) {
        *usage_flags |= ((psa_key_usage_t) 0x00000400);
    }

    if (*usage_flags & ((psa_key_usage_t) 0x00002000)) {
        *usage_flags |= ((psa_key_usage_t) 0x00000800);
    }
}

static inline void psa_set_key_usage_flags(psa_key_attributes_t *attributes,
                                           psa_key_usage_t usage_flags)
{
    psa_extend_key_usage_flags(&usage_flags);
    attributes->private_policy.private_usage = usage_flags;
}

static inline psa_key_usage_t psa_get_key_usage_flags(
    const psa_key_attributes_t *attributes)
{
    return attributes->private_policy.private_usage;
}

static inline void psa_set_key_algorithm(psa_key_attributes_t *attributes,
                                         psa_algorithm_t alg)
{
    attributes->private_policy.private_alg = alg;
}

static inline psa_algorithm_t psa_get_key_algorithm(
    const psa_key_attributes_t *attributes)
{
    return attributes->private_policy.private_alg;
}

static inline void psa_set_key_type(psa_key_attributes_t *attributes,
                                    psa_key_type_t type)
{
    attributes->private_type = type;
}

static inline psa_key_type_t psa_get_key_type(
    const psa_key_attributes_t *attributes)
{
    return attributes->private_type;
}

static inline void psa_set_key_bits(psa_key_attributes_t *attributes,
                                    size_t bits)
{
    if (bits > 0xfff8) {
        attributes->private_bits = ((psa_key_bits_t) -1);
    } else {
        attributes->private_bits = (psa_key_bits_t) bits;
    }
}

static inline size_t psa_get_key_bits(
    const psa_key_attributes_t *attributes)
{
    return attributes->private_bits;
}




struct psa_sign_hash_interruptible_operation_s {
# 434 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h"
    unsigned int private_id;

    psa_driver_sign_hash_interruptible_context_t private_ctx;

    unsigned int private_error_occurred : 1;

    uint32_t private_num_ops;

};







static inline struct psa_sign_hash_interruptible_operation_s
psa_sign_hash_interruptible_operation_init(void)
{
    const struct psa_sign_hash_interruptible_operation_s v =
        { 0, { 0 }, 0, 0 };

    return v;
}




struct psa_verify_hash_interruptible_operation_s {
# 472 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_struct.h"
    unsigned int private_id;

    psa_driver_verify_hash_interruptible_context_t private_ctx;

    unsigned int private_error_occurred : 1;

    uint32_t private_num_ops;

};







static inline struct psa_verify_hash_interruptible_operation_s
psa_verify_hash_interruptible_operation_init(void)
{
    const struct psa_verify_hash_interruptible_operation_s v =
        { 0, { 0 }, 0, 0 };

    return v;
}
# 4829 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h" 2




# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h" 1
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_compat.h" 1
# 31 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_compat.h"
typedef mbedtls_svc_key_id_t psa_key_handle_t;
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_compat.h"
static inline int psa_key_handle_is_null(psa_key_handle_t handle)
{
    return mbedtls_svc_key_id_is_null(handle);
}
# 106 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_compat.h"
psa_status_t psa_open_key(mbedtls_svc_key_id_t key,
                          psa_key_handle_t *handle);
# 147 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_compat.h"
psa_status_t psa_close_key(psa_key_handle_t handle);
# 180 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_compat.h"
static inline psa_status_t psa_set_key_domain_parameters(
    psa_key_attributes_t *attributes,
    psa_key_type_t type, const uint8_t *data, size_t data_length)
{
    (void) data;
    if (data_length != 0) {
        return ((psa_status_t)-134);
    }
    psa_set_key_type(attributes, type);
    return ((psa_status_t)0);
}
# 206 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_compat.h"
static inline psa_status_t psa_get_key_domain_parameters(
    const psa_key_attributes_t *attributes,
    uint8_t *data, size_t data_size, size_t *data_length)
{
    (void) attributes;
    (void) data;
    (void) data_size;
    *data_length = 0;
    return ((psa_status_t)0);
}
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h" 2
# 58 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
static inline void psa_set_key_enrollment_algorithm(
    psa_key_attributes_t *attributes,
    psa_algorithm_t alg2)
{
    attributes->private_policy.private_alg2 = alg2;
}







static inline psa_algorithm_t psa_get_key_enrollment_algorithm(
    const psa_key_attributes_t *attributes)
{
    return attributes->private_policy.private_alg2;
}
# 205 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
void mbedtls_psa_crypto_free(void);







typedef struct mbedtls_psa_stats_s {

    size_t private_volatile_slots;


    size_t private_persistent_slots;


    size_t private_external_slots;


    size_t private_half_filled_slots;

    size_t private_cache_slots;

    size_t private_empty_slots;

    size_t private_locked_slots;

    psa_key_id_t private_max_open_internal_key_id;

    psa_key_id_t private_max_open_external_key_id;
} mbedtls_psa_stats_t;
# 244 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
void mbedtls_psa_get_stats(mbedtls_psa_stats_t *stats);
# 315 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t mbedtls_psa_inject_entropy(const uint8_t *seed,
                                        size_t seed_size);
# 498 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
typedef uint64_t psa_drv_slot_number_t;
# 723 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
typedef uint8_t psa_pake_role_t;







typedef uint8_t psa_pake_step_t;
# 741 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
typedef uint8_t psa_pake_primitive_type_t;






typedef uint8_t psa_pake_family_t;





typedef uint32_t psa_pake_primitive_t;
# 914 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
typedef struct psa_pake_cipher_suite_s psa_pake_cipher_suite_t;



static psa_pake_cipher_suite_t psa_pake_cipher_suite_init(void);







static psa_algorithm_t psa_pake_cs_get_algorithm(
    const psa_pake_cipher_suite_t *cipher_suite);
# 941 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
static void psa_pake_cs_set_algorithm(psa_pake_cipher_suite_t *cipher_suite,
                                      psa_algorithm_t algorithm);







static psa_pake_primitive_t psa_pake_cs_get_primitive(
    const psa_pake_cipher_suite_t *cipher_suite);
# 962 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
static void psa_pake_cs_set_primitive(psa_pake_cipher_suite_t *cipher_suite,
                                      psa_pake_primitive_t primitive);







static psa_pake_family_t psa_pake_cs_get_family(
    const psa_pake_cipher_suite_t *cipher_suite);







static uint16_t psa_pake_cs_get_bits(
    const psa_pake_cipher_suite_t *cipher_suite);
# 991 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
static psa_algorithm_t psa_pake_cs_get_hash(
    const psa_pake_cipher_suite_t *cipher_suite);
# 1010 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
static void psa_pake_cs_set_hash(psa_pake_cipher_suite_t *cipher_suite,
                                 psa_algorithm_t hash);
# 1041 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
typedef struct psa_pake_operation_s psa_pake_operation_t;


typedef struct psa_crypto_driver_pake_inputs_s psa_crypto_driver_pake_inputs_t;


typedef struct psa_jpake_computation_stage_s psa_jpake_computation_stage_t;



static psa_pake_operation_t psa_pake_operation_init(void);
# 1063 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_crypto_driver_pake_get_password_len(
    const psa_crypto_driver_pake_inputs_t *inputs,
    size_t *password_len);
# 1079 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_crypto_driver_pake_get_password(
    const psa_crypto_driver_pake_inputs_t *inputs,
    uint8_t *buffer, size_t buffer_size, size_t *buffer_length);
# 1093 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_crypto_driver_pake_get_user_len(
    const psa_crypto_driver_pake_inputs_t *inputs,
    size_t *user_len);
# 1107 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_crypto_driver_pake_get_peer_len(
    const psa_crypto_driver_pake_inputs_t *inputs,
    size_t *peer_len);
# 1125 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_crypto_driver_pake_get_user(
    const psa_crypto_driver_pake_inputs_t *inputs,
    uint8_t *user_id, size_t user_id_size, size_t *user_id_len);
# 1143 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_crypto_driver_pake_get_peer(
    const psa_crypto_driver_pake_inputs_t *inputs,
    uint8_t *peer_id, size_t peer_id_size, size_t *peer_id_length);
# 1157 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_crypto_driver_pake_get_cipher_suite(
    const psa_crypto_driver_pake_inputs_t *inputs,
    psa_pake_cipher_suite_t *cipher_suite);
# 1231 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_pake_setup(psa_pake_operation_t *operation,
                            const psa_pake_cipher_suite_t *cipher_suite);
# 1279 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_pake_set_password_key(psa_pake_operation_t *operation,
                                       mbedtls_svc_key_id_t password);
# 1319 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_pake_set_user(psa_pake_operation_t *operation,
                               const uint8_t *user_id,
                               size_t user_id_len);
# 1361 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_pake_set_peer(psa_pake_operation_t *operation,
                               const uint8_t *peer_id,
                               size_t peer_id_len);
# 1403 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_pake_set_role(psa_pake_operation_t *operation,
                               psa_pake_role_t role);
# 1461 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_pake_output(psa_pake_operation_t *operation,
                             psa_pake_step_t step,
                             uint8_t *output,
                             size_t output_size,
                             size_t *output_length);
# 1516 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_pake_input(psa_pake_operation_t *operation,
                            psa_pake_step_t step,
                            const uint8_t *input,
                            size_t input_length);
# 1579 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_pake_get_implicit_key(psa_pake_operation_t *operation,
                                       psa_key_derivation_operation_t *output);
# 1606 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
psa_status_t psa_pake_abort(psa_pake_operation_t *operation);
# 1710 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
struct psa_pake_cipher_suite_s {
    psa_algorithm_t algorithm;
    psa_pake_primitive_type_t type;
    psa_pake_family_t family;
    uint16_t bits;
    psa_algorithm_t hash;
};

static inline psa_algorithm_t psa_pake_cs_get_algorithm(
    const psa_pake_cipher_suite_t *cipher_suite)
{
    return cipher_suite->algorithm;
}

static inline void psa_pake_cs_set_algorithm(
    psa_pake_cipher_suite_t *cipher_suite,
    psa_algorithm_t algorithm)
{
    if (!(((algorithm) & ((psa_algorithm_t) 0x7f000000)) == ((psa_algorithm_t) 0x0a000000))) {
        cipher_suite->algorithm = 0;
    } else {
        cipher_suite->algorithm = algorithm;
    }
}

static inline psa_pake_primitive_t psa_pake_cs_get_primitive(
    const psa_pake_cipher_suite_t *cipher_suite)
{
    return ((cipher_suite->bits & 0xFFFF) != cipher_suite->bits) ? 0 : ((psa_pake_primitive_t) (((cipher_suite->type) << 24 | (cipher_suite->family) << 16) | (cipher_suite->bits)));

}

static inline void psa_pake_cs_set_primitive(
    psa_pake_cipher_suite_t *cipher_suite,
    psa_pake_primitive_t primitive)
{
    cipher_suite->type = (psa_pake_primitive_type_t) (primitive >> 24);
    cipher_suite->family = (psa_pake_family_t) (0xFF & (primitive >> 16));
    cipher_suite->bits = (uint16_t) (0xFFFF & primitive);
}

static inline psa_pake_family_t psa_pake_cs_get_family(
    const psa_pake_cipher_suite_t *cipher_suite)
{
    return cipher_suite->family;
}

static inline uint16_t psa_pake_cs_get_bits(
    const psa_pake_cipher_suite_t *cipher_suite)
{
    return cipher_suite->bits;
}

static inline psa_algorithm_t psa_pake_cs_get_hash(
    const psa_pake_cipher_suite_t *cipher_suite)
{
    return cipher_suite->hash;
}

static inline void psa_pake_cs_set_hash(psa_pake_cipher_suite_t *cipher_suite,
                                        psa_algorithm_t hash)
{
    if (!(((hash) & ((psa_algorithm_t) 0x7f000000)) == ((psa_algorithm_t) 0x02000000))) {
        cipher_suite->hash = 0;
    } else {
        cipher_suite->hash = hash;
    }
}

struct psa_crypto_driver_pake_inputs_s {
    uint8_t *private_password;
    size_t private_password_len;
    uint8_t *private_user;
    size_t private_user_len;
    uint8_t *private_peer;
    size_t private_peer_len;
    psa_key_attributes_t private_attributes;
    psa_pake_cipher_suite_t private_cipher_suite;
};

typedef enum psa_crypto_driver_pake_step {
    PSA_JPAKE_STEP_INVALID = 0,
    PSA_JPAKE_X1_STEP_KEY_SHARE = 1,
    PSA_JPAKE_X1_STEP_ZK_PUBLIC = 2,
    PSA_JPAKE_X1_STEP_ZK_PROOF = 3,
    PSA_JPAKE_X2_STEP_KEY_SHARE = 4,
    PSA_JPAKE_X2_STEP_ZK_PUBLIC = 5,
    PSA_JPAKE_X2_STEP_ZK_PROOF = 6,
    PSA_JPAKE_X2S_STEP_KEY_SHARE = 7,
    PSA_JPAKE_X2S_STEP_ZK_PUBLIC = 8,
    PSA_JPAKE_X2S_STEP_ZK_PROOF = 9,
    PSA_JPAKE_X4S_STEP_KEY_SHARE = 10,
    PSA_JPAKE_X4S_STEP_ZK_PUBLIC = 11,
    PSA_JPAKE_X4S_STEP_ZK_PROOF = 12
} psa_crypto_driver_pake_step_t;

typedef enum psa_jpake_round {
    PSA_JPAKE_FIRST = 0,
    PSA_JPAKE_SECOND = 1,
    PSA_JPAKE_FINISHED = 2
} psa_jpake_round_t;

typedef enum psa_jpake_io_mode {
    PSA_JPAKE_INPUT = 0,
    PSA_JPAKE_OUTPUT = 1
} psa_jpake_io_mode_t;

struct psa_jpake_computation_stage_s {

    psa_jpake_round_t private_round;

    psa_jpake_io_mode_t private_io_mode;

    uint8_t private_inputs;

    uint8_t private_outputs;

    psa_pake_step_t private_step;
};






struct psa_pake_operation_s {
# 1845 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto_extra.h"
    unsigned int private_id;

    psa_algorithm_t private_alg;

    psa_pake_primitive_t private_primitive;


    uint8_t private_stage;

    union {
        uint8_t private_dummy;

        psa_jpake_computation_stage_t private_jpake;

    } private_computation_stage;
    union {
        psa_driver_pake_context_t private_ctx;
        psa_crypto_driver_pake_inputs_t private_inputs;
    } private_data;

};

static inline struct psa_pake_cipher_suite_s psa_pake_cipher_suite_init(void)
{
    const struct psa_pake_cipher_suite_s v = { ((psa_algorithm_t)0), 0, 0, 0, ((psa_algorithm_t)0) };
    return v;
}

static inline struct psa_pake_operation_s psa_pake_operation_init(void)
{
    const struct psa_pake_operation_s v = { 0, ((psa_algorithm_t)0), 0, 0, { 0 }, { { 0 } } };
    return v;
}
# 4834 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/psa/crypto.h" 2
# 33 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h" 2
# 73 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
typedef enum {
    MBEDTLS_PK_NONE=0,
    MBEDTLS_PK_RSA,
    MBEDTLS_PK_ECKEY,
    MBEDTLS_PK_ECKEY_DH,
    MBEDTLS_PK_ECDSA,
    MBEDTLS_PK_RSA_ALT,
    MBEDTLS_PK_RSASSA_PSS,
    MBEDTLS_PK_OPAQUE,
} mbedtls_pk_type_t;





typedef struct mbedtls_pk_rsassa_pss_options {
# 97 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
    mbedtls_md_type_t mgf1_hash_id;
# 106 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
    int expected_salt_len;

} mbedtls_pk_rsassa_pss_options;
# 187 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
typedef enum {
    MBEDTLS_PK_DEBUG_NONE = 0,
    MBEDTLS_PK_DEBUG_MPI,
    MBEDTLS_PK_DEBUG_ECP,
    MBEDTLS_PK_DEBUG_PSA_EC,
} mbedtls_pk_debug_type;




typedef struct mbedtls_pk_debug_item {
    mbedtls_pk_debug_type private_type;
    const char *private_name;
    void *private_value;
} mbedtls_pk_debug_item;
# 213 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
typedef struct mbedtls_pk_info_t mbedtls_pk_info_t;






typedef struct mbedtls_pk_context {
    const mbedtls_pk_info_t *private_pk_info;
    void *private_pk_ctx;
# 265 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
} mbedtls_pk_context;





typedef struct {
    const mbedtls_pk_info_t *private_pk_info;
    void *private_rs_ctx;
} mbedtls_pk_restart_ctx;
# 284 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
typedef int (*mbedtls_pk_rsa_alt_decrypt_func)(void *ctx, size_t *olen,
                                               const unsigned char *input, unsigned char *output,
                                               size_t output_max_len);
typedef int (*mbedtls_pk_rsa_alt_sign_func)(void *ctx,
                                            int (*f_rng)(void *, unsigned char *, size_t),
                                            void *p_rng,
                                            mbedtls_md_type_t md_alg, unsigned int hashlen,
                                            const unsigned char *hash, unsigned char *sig);
typedef size_t (*mbedtls_pk_rsa_alt_key_len_func)(void *ctx);
# 302 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
const mbedtls_pk_info_t *mbedtls_pk_info_from_type(mbedtls_pk_type_t pk_type);







void mbedtls_pk_init(mbedtls_pk_context *ctx);
# 323 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
void mbedtls_pk_free(mbedtls_pk_context *ctx);
# 332 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
void mbedtls_pk_restart_init(mbedtls_pk_restart_ctx *ctx);







void mbedtls_pk_restart_free(mbedtls_pk_restart_ctx *ctx);
# 358 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_setup(mbedtls_pk_context *ctx, const mbedtls_pk_info_t *info);
# 409 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_setup_rsa_alt(mbedtls_pk_context *ctx, void *key,
                             mbedtls_pk_rsa_alt_decrypt_func decrypt_func,
                             mbedtls_pk_rsa_alt_sign_func sign_func,
                             mbedtls_pk_rsa_alt_key_len_func key_len_func);
# 422 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
size_t mbedtls_pk_get_bitlen(const mbedtls_pk_context *ctx);
# 431 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
static inline size_t mbedtls_pk_get_len(const mbedtls_pk_context *ctx)
{
    return (mbedtls_pk_get_bitlen(ctx) + 7) / 8;
}
# 448 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_can_do(const mbedtls_pk_context *ctx, mbedtls_pk_type_t type);
# 592 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_get_psa_attributes(const mbedtls_pk_context *pk,
                                  psa_key_usage_t usage,
                                  psa_key_attributes_t *attributes);
# 639 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_import_into_psa(const mbedtls_pk_context *pk,
                               const psa_key_attributes_t *attributes,
                               mbedtls_svc_key_id_t *key_id);
# 677 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_copy_from_psa(mbedtls_svc_key_id_t key_id, mbedtls_pk_context *pk);
# 710 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_copy_public_from_psa(mbedtls_svc_key_id_t key_id, mbedtls_pk_context *pk);
# 743 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_verify(mbedtls_pk_context *ctx, mbedtls_md_type_t md_alg,
                      const unsigned char *hash, size_t hash_len,
                      const unsigned char *sig, size_t sig_len);
# 767 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_verify_restartable(mbedtls_pk_context *ctx,
                                  mbedtls_md_type_t md_alg,
                                  const unsigned char *hash, size_t hash_len,
                                  const unsigned char *sig, size_t sig_len,
                                  mbedtls_pk_restart_ctx *rs_ctx);
# 804 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_verify_ext(mbedtls_pk_type_t type, const void *options,
                          mbedtls_pk_context *ctx, mbedtls_md_type_t md_alg,
                          const unsigned char *hash, size_t hash_len,
                          const unsigned char *sig, size_t sig_len);
# 841 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_sign(mbedtls_pk_context *ctx, mbedtls_md_type_t md_alg,
                    const unsigned char *hash, size_t hash_len,
                    unsigned char *sig, size_t sig_size, size_t *sig_len,
                    int (*f_rng)(void *, unsigned char *, size_t), void *p_rng);
# 875 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_sign_ext(mbedtls_pk_type_t pk_type,
                        mbedtls_pk_context *ctx,
                        mbedtls_md_type_t md_alg,
                        const unsigned char *hash, size_t hash_len,
                        unsigned char *sig, size_t sig_size, size_t *sig_len,
                        int (*f_rng)(void *, unsigned char *, size_t),
                        void *p_rng);
# 912 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_sign_restartable(mbedtls_pk_context *ctx,
                                mbedtls_md_type_t md_alg,
                                const unsigned char *hash, size_t hash_len,
                                unsigned char *sig, size_t sig_size, size_t *sig_len,
                                int (*f_rng)(void *, unsigned char *, size_t), void *p_rng,
                                mbedtls_pk_restart_ctx *rs_ctx);
# 939 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_decrypt(mbedtls_pk_context *ctx,
                       const unsigned char *input, size_t ilen,
                       unsigned char *output, size_t *olen, size_t osize,
                       int (*f_rng)(void *, unsigned char *, size_t), void *p_rng);
# 965 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_encrypt(mbedtls_pk_context *ctx,
                       const unsigned char *input, size_t ilen,
                       unsigned char *output, size_t *olen, size_t osize,
                       int (*f_rng)(void *, unsigned char *, size_t), void *p_rng);
# 984 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_check_pair(const mbedtls_pk_context *pub,
                          const mbedtls_pk_context *prv,
                          int (*f_rng)(void *, unsigned char *, size_t),
                          void *p_rng);
# 997 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_debug(const mbedtls_pk_context *ctx, mbedtls_pk_debug_item *items);
# 1006 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
const char *mbedtls_pk_get_name(const mbedtls_pk_context *ctx);
# 1016 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
mbedtls_pk_type_t mbedtls_pk_get_type(const mbedtls_pk_context *ctx);
# 1029 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
static inline mbedtls_rsa_context *mbedtls_pk_rsa(const mbedtls_pk_context pk)
{
    switch (mbedtls_pk_get_type(&pk)) {
        case MBEDTLS_PK_RSA:
            return (mbedtls_rsa_context *) (pk).private_pk_ctx;
        default:
            return ((void*)0);
    }
}
# 1052 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
static inline mbedtls_ecp_keypair *mbedtls_pk_ec(const mbedtls_pk_context pk)
{
    switch (mbedtls_pk_get_type(&pk)) {
        case MBEDTLS_PK_ECKEY:
        case MBEDTLS_PK_ECKEY_DH:
        case MBEDTLS_PK_ECDSA:
            return (mbedtls_ecp_keypair *) (pk).private_pk_ctx;
        default:
            return ((void*)0);
    }
}
# 1101 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_parse_key(mbedtls_pk_context *ctx,
                         const unsigned char *key, size_t keylen,
                         const unsigned char *pwd, size_t pwdlen,
                         int (*f_rng)(void *, unsigned char *, size_t), void *p_rng);
# 1135 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_parse_public_key(mbedtls_pk_context *ctx,
                                const unsigned char *key, size_t keylen);
# 1166 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_parse_keyfile(mbedtls_pk_context *ctx,
                             const char *path, const char *password,
                             int (*f_rng)(void *, unsigned char *, size_t), void *p_rng);
# 1187 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_parse_public_keyfile(mbedtls_pk_context *ctx, const char *path);
# 1205 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_write_key_der(const mbedtls_pk_context *ctx, unsigned char *buf, size_t size);
# 1220 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_write_pubkey_der(const mbedtls_pk_context *ctx, unsigned char *buf, size_t size);
# 1233 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_write_pubkey_pem(const mbedtls_pk_context *ctx, unsigned char *buf, size_t size);
# 1245 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_write_key_pem(const mbedtls_pk_context *ctx, unsigned char *buf, size_t size);
# 1265 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_parse_subpubkey(unsigned char **p, const unsigned char *end,
                               mbedtls_pk_context *pk);
# 1280 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
int mbedtls_pk_write_pubkey(unsigned char **p, unsigned char *start,
                            const mbedtls_pk_context *key);
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_centraldirectory.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_verify_pub.h" 1
# 28 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_verify_pub.h"
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
# 23 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_centraldirectory.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_common.h" 1
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_common.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/ipcamera/app_verify_base.h" 1
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/ipcamera/app_verify_base.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_verify_hal.h" 1
# 29 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_verify_hal.h"
typedef int32_t (*GetDeviceUdid)(unsigned char *udid, int32_t size);

typedef struct {
    GetDeviceUdid devUdidFunc;
} ProductDiff;

void RegistHalFunc();
int32_t InquiryDeviceUdid(unsigned char *udid, int32_t size);
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/ipcamera/app_verify_base.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/log.h" 1
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/log.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/hilog_cp.h" 1
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/hilog_cp.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/hiview_log.h" 1
# 63 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/hiview_log.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdarg.h" 1
# 10 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdarg.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 11 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdarg.h" 2
# 64 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/hiview_log.h" 2
# 78 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/hiview_log.h"
typedef enum {

    HILOG_MODULE_HIVIEW = 0,

    HILOG_MODULE_SAMGR,

    HILOG_MODULE_UPDATE,

    HILOG_MODULE_ACE,

    HILOG_MODULE_APP,

    HILOG_MODULE_MAX
} HiLogModuleType;
# 128 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/hiview_log.h"
typedef enum {
    LOG_TYPE_MIN = 0,

    LOG_INIT = 1,

    LOG_CORE = 3,
    LOG_TYPE_MAX
} LogType;
# 154 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/hiview_log.h"
typedef enum {

    LOG_DEBUG = 3,

    LOG_INFO = 4,

    LOG_WARN = 5,

    LOG_ERROR = 6,

    LOG_FATAL = 7,
} LogLevel;
# 191 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/hiview_log.h"
int HiLogPrint(LogType type, LogLevel level, unsigned int domain, const char* tag, const char* fmt, ...)
    __attribute__((format(os_log, 5, 6)));
# 210 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/hiview_log.h"
int HiLogPrintArgs(LogType bufID, LogLevel prio,
    unsigned int domain, const char* tag, const char* fmt, va_list ap);
# 313 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/hiview_log.h"
int FlushHilog(void);



struct HiLogEntry {
    unsigned int len;
    unsigned int hdrSize;
    unsigned int pid : 16;
    unsigned int taskId : 16;
    unsigned int sec;
    unsigned int nsec;
    unsigned int reserved;
    char msg[0];
};
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/hilog_cp.h" 2
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/innerkits/hilog/log.h" 2
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/ipcamera/app_verify_base.h" 2
# 38 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/products/ipcamera/app_verify_base.h"
void RegistProductFunc(ProductDiff *productFunc);
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_common.h" 2
# 106 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_common.h"
long long HapGetInt64(const unsigned char *buf, int32_t len);
int32_t HapGetInt(const unsigned char *buf, int32_t len);
uint32_t HapGetUnsignedInt(const unsigned char *buf, int32_t len);
short HapGetShort(const unsigned char *buf, int32_t len);
void HapPutInt32(unsigned char *buf, int32_t len, int32_t value);
# 25 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_centraldirectory.h" 2
# 43 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_centraldirectory.h"
typedef struct {
    void *buffer;
    int32_t len;
} HapBuf;

#pragma pack(4)

typedef struct {
    uint32_t blockNum;
    unsigned long long size;
    unsigned long long magicLow;
    unsigned long long magicHigh;
    uint32_t version;
} HwSignHead;
#pragma pack()

#pragma pack(2)
typedef struct {
    int32_t magic;
    short diskNum;
    short startNum;
    short coreDirNumOnDisk;
    short coreDirNum;
    int32_t coreDirSize;
    int32_t coreDirOffset;
    short commentLen;
} MinEocd;
#pragma pack()

typedef struct {
    MinEocd eocdHead;
    char *comment;
} HapEocd;

typedef struct {
    HwSignHead *signHead;
    int32_t fullSignBlockOffset;
    int32_t hapCoreDirOffset;
    int32_t hapEocdOffset;
    int32_t hapEocdSize;
    int32_t fileSize;
    int32_t version;
    int32_t certType;
} SignatureInfo;

_Bool FindSignature(const FileRead *hapFile, SignatureInfo *signInfo);
_Bool CreateHapBuffer(HapBuf *hapBuffer, int32_t len);
int32_t ReadFileFullyFromOffset(const HapBuf *buffer, int32_t offset, const FileRead *file);
void HapSetInt32(const HapBuf *buffer, int32_t offset, int32_t value);
void ClearHapBuffer(HapBuf *hapBuffer);
void HapPutByte(const HapBuf *hapBuffer, int32_t offset, char value);
void HapPutData(const HapBuf *hapBuffer, int32_t offset, const unsigned char *data, int32_t len);
# 26 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/app_file.c" 2


static int32_t g_memoryPageSize = 0;
int32_t InitVerify(FileRead *file, const char *filePath, int32_t *handle)
{
    if (handle == ((void*)0) || file == ((void*)0) || filePath == ((void*)0)) {
        ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""file open error", __FUNCTION__, 32));
        return V_ERR_FILE_OPEN;
    }
    RegistHalFunc();
    char *path = malloc(256 + 1);
    if (path == ((void*)0)) {
        ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""path malloc error", __FUNCTION__, 38));
        return V_ERR_MALLOC;
    }
    if ((strlen(filePath) > 256) || (((void*)0) == realpath(filePath, path))) {
        do { if ((path) != ((void*)0)) { free(path); (path) = ((void*)0); } } while (0);
        ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""file path error", __FUNCTION__, 43));
        return V_ERR_FILE_OPEN;
    }
    *handle = open(path, 00, 0);
    if (*handle < 0) {
        do { if ((path) != ((void*)0)) { free(path); (path) = ((void*)0); } } while (0);
        ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""file open error", __FUNCTION__, 49));
        return V_ERR_FILE_OPEN;
    }
    if (g_memoryPageSize == 0) {
        g_memoryPageSize = sysconf(30);
    }
    if (g_memoryPageSize <= 0) {
        ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""MAP_FAILED %d", __FUNCTION__, 56, g_memoryPageSize));
        do { if ((path) != ((void*)0)) { free(path); (path) = ((void*)0); } } while (0);
        return V_ERR_FILE_STAT;
    }
    file->len = lseek(*handle, 0, 2);
    file->fp = *handle;
    do { if ((path) != ((void*)0)) { free(path); (path) = ((void*)0); } } while (0);
    return V_OK;
}

int32_t HapMMap(int32_t bufCapacity, int32_t offset, MmapInfo *mmapInfo, const FileRead *file)
{
    if (mmapInfo == ((void*)0) || file == ((void*)0) || bufCapacity <= 0) {
        return MMAP_FAILED;
    }
    mmapInfo->mapAddr = (char*)(((void *) -1));
    if (file->fp == (-1)) {
        return FILE_IS_CLOSE;
    }
    if (offset < 0 || offset > file->len - bufCapacity) {
        return READ_OFFSET_OUT_OF_RANGE;
    }
    lseek(file->fp, offset, 0);
    if (g_memoryPageSize == 0) {
        return MMAP_FAILED;
    }
    mmapInfo->mmapPosition = (offset / g_memoryPageSize) * g_memoryPageSize;
    mmapInfo->readMoreLen = (int)(offset - mmapInfo->mmapPosition);
    mmapInfo->mmapSize = bufCapacity + mmapInfo->readMoreLen;
    mmapInfo->mapAddr = (char*)(mmap(((void*)0), mmapInfo->mmapSize, 1,
        0x01, file->fp, mmapInfo->mmapPosition));
    if (mmapInfo->mapAddr == ((void *) -1)) {
        ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""MAP_FAILED", __FUNCTION__, 88));
        return MMAP_FAILED;
    }
    return V_OK;
}

void HapMUnMap(char *mapAddr, int32_t mmapSize)
{
    if (mapAddr == ((void*)0) || mmapSize <= 0) {
        return;
    }
    munmap(mapAddr, mmapSize);
}
