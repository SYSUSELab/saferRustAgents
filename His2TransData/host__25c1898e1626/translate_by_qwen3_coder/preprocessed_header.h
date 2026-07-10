typedef long long time_t;
typedef struct cpu_set_t { unsigned long __bits[32/(8 * sizeof(unsigned long int))]; } cpu_set_t;
struct timespec { time_t tv_sec; long tv_nsec; };
struct timespec64 { long long tv_sec; long long tv_nsec; };
typedef int pid_t;
typedef unsigned wchar_t;
typedef struct { long long __ll; long double __ld; } max_align_t;
typedef unsigned int size_t;
typedef int ptrdiff_t;
struct sched_param {
    union {
        int sched_priority;
        int sched_runtime;
    };
    int sched_deadline;
    int sched_period;
};
int sched_get_priority_max(int);
int sched_get_priority_min(int);
int sched_getparam(pid_t, struct sched_param *);
int sched_getscheduler(pid_t);
int sched_rr_get_interval(pid_t, struct timespec *);
int sched_setparam(pid_t, const struct sched_param *);
int sched_setscheduler(pid_t, int, const struct sched_param *);
int sched_yield(void);
typedef unsigned int uintptr_t;
typedef int intptr_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;
typedef signed long long intmax_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef unsigned long long uintmax_t;

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
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;

typedef __builtin_va_list va_list;
typedef __builtin_va_list __isoc_va_list;
typedef int ssize_t;
typedef long long off_t;
typedef long long loff_t;
typedef off_t off64_t;
typedef struct _IO_FILE FILE;
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
int dprintf(int, const char *restrict, ...);
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
int renameat2(int, const char *, int, const char *, unsigned int);
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
enum fdsan_owner_type {
 FDSAN_OWNER_TYPE_DEFAULT = 0,
 FDSAN_OWNER_TYPE_MAX = 255,
 FDSAN_OWNER_TYPE_FILE = 1,
 FDSAN_OWNER_TYPE_DIRECTORY = 2,
 FDSAN_OWNER_TYPE_UNIQUE_FD = 3,
 FDSAN_OWNER_TYPE_ZIP_ARCHIVE = 4,
};
void* fdsan_get_fd_table();
uint64_t fdsan_create_owner_tag(enum fdsan_owner_type type, uint64_t tag);
void fdsan_exchange_owner_tag(int fd, uint64_t expected_tag, uint64_t new_tag);
int fdsan_close_with_tag(int fd, uint64_t tag);
uint64_t fdsan_get_owner_tag(int fd);
const char* fdsan_get_tag_type(uint64_t tag);
uint64_t fdsan_get_tag_value(uint64_t tag);
enum fdsan_error_level {
 FDSAN_ERROR_LEVEL_DISABLED,
 FDSAN_ERROR_LEVEL_WARN_ONCE,
 FDSAN_ERROR_LEVEL_WARN_ALWAYS,
 FDSAN_ERROR_LEVEL_FATAL,
};
enum fdsan_error_level fdsan_get_error_level();
enum fdsan_error_level fdsan_set_error_level(enum fdsan_error_level new_level);
enum fdsan_error_level fdsan_set_error_level_from_param(enum fdsan_error_level default_level);
typedef struct __locale_struct *locale_t;

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
int bcmp (const void *, const void *, size_t);
void bcopy (const void *, void *, size_t);
void bzero (void *, size_t);
char *index (const char *, int);
char *rindex (const char *, int);
int ffs (int);
int ffsl (long);
int ffsll (long long);
int strcasecmp (const char *, const char *);
int strncasecmp (const char *, const char *, size_t);
int strcasecmp_l (const char *, const char *, locale_t);
int strncasecmp_l (const char *, const char *, size_t, locale_t);
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
void *memmem(const void *, size_t, const void *, size_t);
void *memccpy (void *restrict, const void *restrict, int, size_t);
char *strsep(char **, const char *);
size_t strlcat (char *, const char *, size_t);
size_t strlcpy (char *, const char *, size_t);
void explicit_bzero (void *, size_t);
typedef long long suseconds_t;
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
  cpu_set_t cpuset;
} pthread_attr_t;
typedef int register_t;
typedef unsigned long long u_int64_t;
typedef unsigned mode_t;
typedef unsigned int nlink_t;
typedef unsigned long long ino_t;
typedef unsigned long long dev_t;
typedef long blksize_t;
typedef long long blkcnt_t;
typedef unsigned long long fsblkcnt_t;
typedef unsigned long long fsfilcnt_t;
typedef void * timer_t;
typedef int clockid_t;
typedef long clock_t;
typedef unsigned id_t;
typedef unsigned uid_t;
typedef unsigned gid_t;
typedef int key_t;
typedef unsigned useconds_t;
typedef long pthread_t;
typedef int pthread_once_t;
typedef int pthread_key_t;
typedef int pthread_condattr_t;
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
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
struct timeval64 { long long tv_sec; long long tv_usec; };
typedef unsigned long long sigset_t;
typedef unsigned long fd_mask;
typedef struct {
 unsigned long fds_bits[1024 / 8 / sizeof(long)];
} fd_set;
int select (int, fd_set *restrict, fd_set *restrict, fd_set *restrict, struct timeval *restrict);
int pselect (int, fd_set *restrict, fd_set *restrict, fd_set *restrict, const struct timespec *restrict, const sigset_t *restrict);
typedef enum {
    HDF_SUCCESS = 0,
    HDF_FAILURE = -1,
    HDF_ERR_NOT_SUPPORT = -2,
    HDF_ERR_INVALID_PARAM = -3,
    HDF_ERR_INVALID_OBJECT = -4,
    HDF_ERR_MALLOC_FAIL = -6,
    HDF_ERR_TIMEOUT = -7,
    HDF_ERR_THREAD_CREATE_FAIL = -10,
    HDF_ERR_QUEUE_FULL = -15,
    HDF_ERR_DEVICE_BUSY = -16,
    HDF_ERR_IO = -17,
    HDF_ERR_BAD_FD = -18,
    HDF_ERR_NOPERM = -19,
    HDF_ERR_OUT_OF_RANGE = -20,
    HDF_BSP_ERR_OP = ((-100) + (-1)),
    HDF_ERR_BSP_PLT_API_ERR = ((-100) + (-2)),
    HDF_PAL_ERR_DEV_CREATE = ((-100) + (-3)),
    HDF_PAL_ERR_INNER = ((-100) + (-4)),
    HDF_DEV_ERR_NO_MEMORY = ((-200) + (-1)),
    HDF_DEV_ERR_NO_DEVICE = ((-200) + (-2)),
    HDF_DEV_ERR_NO_DEVICE_SERVICE = ((-200) + (-3)),
    HDF_DEV_ERR_DEV_INIT_FAIL = ((-200) + (-4)),
    HDF_DEV_ERR_PUBLISH_FAIL = ((-200) + (-5)),
    HDF_DEV_ERR_ATTACHDEV_FAIL = ((-200) + (-6)),
    HDF_DEV_ERR_NODATA = ((-200) + (-7)),
    HDF_DEV_ERR_NORANGE = ((-200) + (-8)),
    HDF_DEV_ERR_OP = ((-200) + (-10)),
    HDF_DEV_ERR_NETDOWN = ((-200) + (-11)),
} HDF_STATUS;
struct HdfSListNode {
    struct HdfSListNode *next;
};
struct HdfSList {
    struct HdfSListNode *root;
};
struct HdfSListIterator {
    int stepOnNext;
    struct HdfSListNode *prev;
    struct HdfSListNode *curr;
};
typedef void (*HdfSListDeleter)(struct HdfSListNode *);
typedef _Bool (*HdfSListSearchComparer)(struct HdfSListNode *, uint32_t);
typedef _Bool (*HdfSListAddComparer)(struct HdfSListNode *, struct HdfSListNode *);
void HdfSListInit(struct HdfSList *list);
struct HdfSListNode *HdfSListSearch(const struct HdfSList *list, uint32_t keyValue, HdfSListSearchComparer comparer);
_Bool HdfSListIsEmpty(const struct HdfSList *list);
struct HdfSListNode *HdfSListGetLast(const struct HdfSList *list);
void HdfSListAdd(struct HdfSList *list, struct HdfSListNode *link);
void HdfSListAddTail(struct HdfSList *list, struct HdfSListNode *link);
_Bool HdfSListAddOrder(struct HdfSList *list, struct HdfSListNode *link, HdfSListAddComparer comparer);
void HdfSListRemove(struct HdfSList *list, struct HdfSListNode *link);
void HdfSListFlush(struct HdfSList *list, HdfSListDeleter deleter);
int HdfSListCount(const struct HdfSList *list);
struct HdfSListNode *HdfSListPeek(const struct HdfSList *list);
struct HdfSListNode *HdfSListNext(const struct HdfSListNode *link);
struct HdfSListNode *HdfSListPop(struct HdfSList *list);
void HdfSListIteratorInit(struct HdfSListIterator *iterator, const struct HdfSList *list);
_Bool HdfSListIteratorHasNext(const struct HdfSListIterator *iterator);
struct HdfSListNode *HdfSListIteratorNext(struct HdfSListIterator *iterator);
void HdfSListIteratorRemove(struct HdfSListIterator *iterator);
void HdfSListIteratorInsert(struct HdfSListIterator *iterator, struct HdfSListNode *link);
enum {
    HDF_SERVICE_UNUSABLE,
    HDF_SERVICE_USABLE,
};
enum {
    HDF_DEV_LOCAL_SERVICE,
    HDF_DEV_REMOTE_SERVICE,
};
struct HdfDeviceInfo {
    struct HdfSListNode node;
    _Bool isDynamic;
    uint16_t status;
    uint16_t deviceType;
    uint32_t deviceId;
    uint16_t policy;
    uint16_t priority;
    uint16_t preload;
    uint16_t permission;
    const char *moduleName;
    const char *svcName;
    const char *deviceMatchAttr;
    const char *deviceName;
};
struct HdfPrivateInfo {
    uint32_t length;
    const void *data;
};
struct HdfDeviceInfo *HdfDeviceInfoNewInstance(void);
void HdfDeviceInfoConstruct(struct HdfDeviceInfo *deviceInfo);
void HdfDeviceInfoFreeInstance(struct HdfDeviceInfo *deviceInfo);
void HdfDeviceInfoDelete(struct HdfSListNode *listEntry);
struct DListHead {
    struct DListHead *next;
    struct DListHead *prev;
};
static inline void DListHeadInit(struct DListHead *head)
{
    head->next = head;
    head->prev = head;
}
static inline _Bool DListIsEmpty(const struct DListHead *head)
{
    return (head->next == head) ? 1 : 0;
}
static inline void DListRemove(struct DListHead *entry)
{
    entry->prev->next = entry->next;
    entry->next->prev = entry->prev;
    entry->prev = ((void*)0);
    entry->next = ((void*)0);
}
static inline void DListInsertHead(struct DListHead *entry, struct DListHead *head)
{
    entry->next = head->next;
    entry->prev = head;
    head->next->prev = entry;
    head->next = entry;
}
static inline void DListInsertTail(struct DListHead *entry, struct DListHead *head)
{
    entry->next = head;
    entry->prev = head->prev;
    head->prev->next = entry;
    head->prev = entry;
}
static inline void DListMerge(struct DListHead *list, struct DListHead *head)
{
    list->next->prev = head;
    list->prev->next = head->next;
    head->next->prev = list->prev;
    head->next = list->next;
    DListHeadInit(list);
}
static inline int DListGetCount(const struct DListHead *head)
{
    struct DListHead *next = head->next;
    int count = 0;
    while (next != head) {
        next = next->next;
        count++;
    }
    return count;
}
struct HdfObject {
    int32_t objectId;
};
typedef uint32_t devid_t;
struct HdfDeviceNode;
struct IHdfDevice {
    struct HdfObject object;
    int (*Attach)(struct IHdfDevice *device, struct HdfDeviceNode *deviceNode);
    int (*Detach)(struct IHdfDevice *device, struct HdfDeviceNode *deviceNode);
    struct HdfDeviceNode *(*GetDeviceNode)(struct IHdfDevice *device, devid_t devid);
    int (*DetachWithDevid)(struct IHdfDevice *device, devid_t devid);
};
struct HdfDevice {
    struct IHdfDevice super;
    struct DListHead node;
    struct DListHead devNodes;
    devid_t deviceId;
    uint16_t devidIndex;
};
int HdfDeviceDetach(struct IHdfDevice *devInst, struct HdfDeviceNode *devNode);
void HdfDeviceConstruct(struct HdfDevice *device);
void HdfDeviceDestruct(struct HdfDevice *device);
struct HdfObject *HdfDeviceCreate(void);
void HdfDeviceRelease(struct HdfObject *object);
struct HdfDevice *HdfDeviceNewInstance(void);
void HdfDeviceFreeInstance(struct HdfDevice *device);

typedef enum {
    DEVICE_CLASS_DEFAULT = 0x1 << 0,
    DEVICE_CLASS_PLAT = 0x1 << 1,
    DEVICE_CLASS_SENSOR = 0x1 << 2,
    DEVICE_CLASS_INPUT = 0x1 << 3,
    DEVICE_CLASS_DISPLAY = 0x1 << 4,
    DEVICE_CLASS_AUDIO = 0x1 << 5,
    DEVICE_CLASS_CAMERA = 0x1 << 6,
    DEVICE_CLASS_USB = 0x1 << 7,
    DEVICE_CLASS_USERAUTH = 0x1 << 8,
    DEVICE_CLASS_HIMEDIACOMM = 0x1 << 9,
    DEVICE_CLASS_MAX = 0x1 << 10,
} DeviceClass;
typedef uint16_t char16_t;
struct HdfSBuf;
struct HdfSBufImpl;
struct HdfRemoteService;
enum HdfSbufType {
    SBUF_RAW = 0,
    SBUF_IPC,
    SBUF_IPC_HW,
    SBUF_TYPE_MAX,
};
_Bool HdfSbufWriteBuffer(struct HdfSBuf *sbuf, const void *data, uint32_t writeSize);
_Bool HdfSbufWriteUnpadBuffer(struct HdfSBuf *sbuf, const uint8_t *data, uint32_t writeSize);
_Bool HdfSbufWriteUint64(struct HdfSBuf *sbuf, uint64_t value);
_Bool HdfSbufWriteUint32(struct HdfSBuf *sbuf, uint32_t value);
_Bool HdfSbufWriteUint16(struct HdfSBuf *sbuf, uint16_t value);
_Bool HdfSbufWriteUint8(struct HdfSBuf *sbuf, uint8_t value);
_Bool HdfSbufWriteInt64(struct HdfSBuf *sbuf, int64_t value);
_Bool HdfSbufWriteInt32(struct HdfSBuf *sbuf, int32_t value);
_Bool HdfSbufWriteInt16(struct HdfSBuf *sbuf, int16_t value);
_Bool HdfSbufWriteInt8(struct HdfSBuf *sbuf, int8_t value);
_Bool HdfSbufWriteString(struct HdfSBuf *sbuf, const char *value);
_Bool HdfSbufWriteString16(struct HdfSBuf *sbuf, const char16_t *value, uint32_t size);
_Bool HdfSbufWriteFloat(struct HdfSBuf *sbuf, float data);
_Bool HdfSbufWriteDouble(struct HdfSBuf *sbuf, double data);
_Bool HdfSbufWriteFileDescriptor(struct HdfSBuf *sbuf, int fd);
int32_t HdfSbufWriteRemoteService(struct HdfSBuf *sbuf, const struct HdfRemoteService *service);
struct HdfRemoteService *HdfSbufReadRemoteService(struct HdfSBuf *sbuf);
int HdfSbufReadFileDescriptor(struct HdfSBuf *sbuf);
_Bool HdfSbufReadDouble(struct HdfSBuf *sbuf, double *data);
_Bool HdfSbufReadFloat(struct HdfSBuf *sbuf, float *data);
const char16_t *HdfSbufReadString16(struct HdfSBuf *sbuf);
_Bool HdfSbufReadBuffer(struct HdfSBuf *sbuf, const void **data, uint32_t *readSize);
const uint8_t *HdfSbufReadUnpadBuffer(struct HdfSBuf *sbuf, size_t length);
_Bool HdfSbufReadUint64(struct HdfSBuf *sbuf, uint64_t *value);
_Bool HdfSbufReadUint32(struct HdfSBuf *sbuf, uint32_t *value);
_Bool HdfSbufReadUint16(struct HdfSBuf *sbuf, uint16_t *value);
_Bool HdfSbufReadUint8(struct HdfSBuf *sbuf, uint8_t *value);
_Bool HdfSbufReadInt64(struct HdfSBuf *sbuf, int64_t *value);
_Bool HdfSbufReadInt32(struct HdfSBuf *sbuf, int32_t *value);
_Bool HdfSbufReadInt16(struct HdfSBuf *sbuf, int16_t *value);
_Bool HdfSbufReadInt8(struct HdfSBuf *sbuf, int8_t *value);
const char *HdfSbufReadString(struct HdfSBuf *sbuf);
uint8_t *HdfSbufGetData(const struct HdfSBuf *sbuf);
void HdfSbufFlush(struct HdfSBuf *sbuf);
size_t HdfSbufGetCapacity(const struct HdfSBuf *sbuf);
size_t HdfSbufGetDataSize(const struct HdfSBuf *sbuf);
void HdfSbufSetDataSize(struct HdfSBuf *sbuf, size_t size);
struct HdfSBuf *HdfSbufObtain(size_t capacity);
struct HdfSBuf *HdfSbufObtainDefaultSize(void);
struct HdfSBuf *HdfSbufBind(uintptr_t base, size_t size);
void HdfSbufRecycle(struct HdfSBuf *sbuf);
struct HdfSBuf *HdfSbufMove(struct HdfSBuf *sbuf);
struct HdfSBuf *HdfSbufCopy(const struct HdfSBuf *sbuf);
void HdfSbufTransDataOwnership(struct HdfSBuf *sbuf);
struct HdfSBuf *HdfSbufTypedObtain(uint32_t type);
struct HdfSBuf *HdfSbufTypedObtainInplace(uint32_t type, struct HdfSBufImpl *impl);
struct HdfSBuf *HdfSbufTypedObtainCapacity(uint32_t type, size_t capacity);
struct HdfSBuf *HdfSbufTypedBind(uint32_t type, uintptr_t base, size_t size);
struct HdfSBufImpl *HdfSbufGetImpl(struct HdfSBuf *sbuf);
struct HdfDevEventlistener;
struct HdfIoService;
typedef int (*OnEventReceived)(void *priv, uint32_t id, struct HdfSBuf *data);
typedef int (*OnDevEventReceive)(
    struct HdfDevEventlistener *listener, struct HdfIoService *service, uint32_t id, struct HdfSBuf *data);
struct HdfDevEventlistener {
    OnEventReceived callBack;
    OnDevEventReceive onReceive;
    struct DListHead listNode;
    void *priv;
};
struct HdfIoDispatcher {
    int (*Dispatch)(struct HdfObject *service, int cmdId, struct HdfSBuf *data, struct HdfSBuf *reply);
};
struct HdfIoService {
    struct HdfObject object;
    struct HdfObject *target;
    struct HdfIoDispatcher *dispatcher;
    void *priv;
};
struct HdfIoServiceGroup {
    struct HdfObject object;
};
struct HdfIoServiceGroup *HdfIoServiceGroupObtain(void);
void HdfIoServiceGroupRecycle(struct HdfIoServiceGroup *group);
int32_t HdfIoServiceGroupAddService(struct HdfIoServiceGroup *group, struct HdfIoService *service);
void HdfIoServiceGroupRemoveService(struct HdfIoServiceGroup *group, struct HdfIoService *service);
int32_t HdfIoServiceGroupRegisterListener(struct HdfIoServiceGroup *group, struct HdfDevEventlistener *listener);
int32_t HdfIoServiceGroupRegisterListenerWithSchedPolicy(
    struct HdfIoServiceGroup *group, struct HdfDevEventlistener *listener, int policy);
int32_t HdfIoServiceGroupUnregisterListener(struct HdfIoServiceGroup *group, struct HdfDevEventlistener *listener);
struct HdfIoService *HdfIoServiceBind(const char *serviceName);
void HdfIoServiceRecycle(struct HdfIoService *service);
int HdfDeviceRegisterEventListener(struct HdfIoService *target, struct HdfDevEventlistener *listener);
int32_t HdfDeviceRegisterEventListenerWithSchedPolicy(
    struct HdfIoService *target, struct HdfDevEventlistener *listener, int policy);
int HdfDeviceUnregisterEventListener(struct HdfIoService *target, struct HdfDevEventlistener *listener);
int HdfIoserviceGetListenerCount(const struct HdfIoService *service);
int HdfIoserviceGroupGetListenerCount(const struct HdfIoServiceGroup *group);
int HdfIoserviceGroupGetServiceCount(const struct HdfIoServiceGroup *group);
int32_t HdfGetServiceNameByDeviceClass(DeviceClass deviceClass, struct HdfSBuf *reply);
int32_t HdfIoServiceDispatch(struct HdfIoService *ioService, int cmdId, struct HdfSBuf *data, struct HdfSBuf *reply);
typedef enum {
    SERVICE_POLICY_NONE = 0,
    SERVICE_POLICY_PUBLIC,
    SERVICE_POLICY_CAPACITY,
    SERVICE_POLICY_FRIENDLY,
    SERVICE_POLICY_PRIVATE,
    SERVICE_POLICY_INVALID
} ServicePolicy;
typedef enum {
    DEVICE_PRELOAD_ENABLE = 0,
    DEVICE_PRELOAD_ENABLE_STEP2,
    DEVICE_PRELOAD_DISABLE,
    DEVICE_PRELOAD_INVALID
} DevicePreload;
struct HdfDeviceObject {
    struct IDeviceIoService *service;
    const struct DeviceResourceNode *property;
    DeviceClass deviceClass;
    void *priv;
};
struct HdfDeviceIoClient {
    struct HdfDeviceObject *device;
    void *priv;
};
struct IDeviceIoService {
    struct HdfObject object;
    int32_t (*Open)(struct HdfDeviceIoClient *client);
    int32_t (*Dispatch)(struct HdfDeviceIoClient *client, int cmdId, struct HdfSBuf *data, struct HdfSBuf *reply);
    void (*Release)(struct HdfDeviceIoClient *client);
};
struct SubscriberCallback {
    struct HdfDeviceObject *deviceObject;
    int32_t (*OnServiceConnected)(struct HdfDeviceObject *deviceObject, const struct HdfObject *service);
};
struct HdfDriverEntry {
    int32_t moduleVersion;
    const char *moduleName;
    int32_t (*Bind)(struct HdfDeviceObject *deviceObject);
    int32_t (*Init)(struct HdfDeviceObject *deviceObject);
    void (*Release)(struct HdfDeviceObject *deviceObject);
};
const struct HdfObject *DevSvcManagerClntGetService(const char *svcName);
const char *HdfDeviceGetServiceName(const struct HdfDeviceObject *deviceObject);
int32_t HdfDeviceSubscribeService(
    struct HdfDeviceObject *deviceObject, const char *serviceName, struct SubscriberCallback callback);
int32_t HdfDeviceSendEvent(const struct HdfDeviceObject *deviceObject, uint32_t id, const struct HdfSBuf *data);
int32_t HdfDeviceSendEventToClient(const struct HdfDeviceIoClient *client, uint32_t id, const struct HdfSBuf *data);
_Bool HdfDeviceSetClass(struct HdfDeviceObject *deviceObject, DeviceClass deviceClass);

struct HdfDriver {
    const struct HdfDriverEntry *entry;
    uint16_t type;
    uint16_t bus;
    struct DListHead node;
    void *priv;
};
int32_t HdfRegisterDriverEntry(const struct HdfDriverEntry *entry);
int32_t HdfUnregisterDriverEntry(const struct HdfDriverEntry *entry);
int32_t HdfRegisterDriver(struct HdfDriver *driver);
int32_t HdfUnregisterDriver(struct HdfDriver *driver);
struct HdfDriver *HdfDriverManagerGetDriver(const char *driverName);
struct DListHead *HdfDriverManagerGetDriverList(void);
enum PowerKeventId {
    KEVENT_POWER_SUSPEND,
    KEVENT_POWER_DISPLAY_OFF,
    KEVENT_POWER_RESUME,
    KEVENT_POWER_DISPLAY_ON,
    KEVENT_POWER_EVENT_MAX,
};
enum DriverModuleKeventId {
    KEVENT_MODULE_INSTALL,
    KEVENT_MODULE_REMOVE,
    KEVENT_MODULE_EVENT_MAX,
};
struct HdfSysEvent {
    uint64_t eventClass;
    uint64_t syncToken;
    uint32_t eventid;
    uint32_t reserved;
};
struct HdfSysEventNotifyNode;
typedef int32_t (*HdfSysEventNotifierFn)(
    struct HdfSysEventNotifyNode *self, uint64_t eventClass, uint32_t event, const char *content);
struct HdfSysEventNotifyNode {
    HdfSysEventNotifierFn callback;
    struct DListHead listNode;
    uint64_t classFilter;
};
int32_t HdfSysEventNotifyRegister(struct HdfSysEventNotifyNode *notifierNode, uint64_t classSet);
void HdfSysEventNotifyUnregister(struct HdfSysEventNotifyNode *notifierNode);
__attribute__((weak)) int32_t HdfSysEventSend(uint64_t eventClass, uint32_t event, const char *content, _Bool sync);

enum PowerManagementMode {
    HDF_POWER_SYS_CTRL,
    HDF_POWER_DYNAMIC_CTRL,
    HDF_POWER_MODE_MAX,
};
struct IPowerEventListener {
    int (*DozeResume)(struct HdfDeviceObject *deviceObject);
    int (*DozeSuspend)(struct HdfDeviceObject *deviceObject);
    int (*Resume)(struct HdfDeviceObject *deviceObject);
    int (*Suspend)(struct HdfDeviceObject *deviceObject);
};
int HdfPmRegisterPowerListener(struct HdfDeviceObject *deviceObject, const struct IPowerEventListener *listener);
void HdfPmUnregisterPowerListener(struct HdfDeviceObject *deviceObject, const struct IPowerEventListener *listener);
void HdfPmAcquireDevice(struct HdfDeviceObject *deviceObject);
void HdfPmReleaseDevice(struct HdfDeviceObject *deviceObject);
void HdfPmAcquireDeviceAsync(struct HdfDeviceObject *deviceObject);
void HdfPmReleaseDeviceAsync(struct HdfDeviceObject *deviceObject);
void HdfPmSetMode(struct HdfDeviceObject *deviceObject, uint32_t mode);
struct HdfDeviceNode;
struct DevHostService;
struct IDeviceNode {
    struct HdfObject object;
    int (*PublishService)(struct HdfDeviceNode *devNode);
    int (*RemoveService)(struct HdfDeviceNode *devNode);
    int (*LaunchNode)(struct HdfDeviceNode *devNode);
    void (*UnlaunchNode)(struct HdfDeviceNode *devNode);
};
struct HdfDeviceNode {
    struct IDeviceNode super;
    struct DListHead entry;
    struct PowerStateToken *powerToken;
    struct DevHostService *hostService;
    struct HdfDeviceObject deviceObject;
    struct IHdfDeviceToken *token;
    struct HdfDriver *driver;
    struct HdfDevice *device;
    char *servName;
    const char *servInfo;
    char *driverName;
    devid_t devId;
    uint16_t policy;
    uint16_t permission;
    uint8_t devStatus;
    _Bool servStatus;
    char *interfaceDesc;
};
enum DevNodeStaus {
    DEVNODE_NONE = 0,
    DEVNODE_INITED,
    DEVNODE_LAUNCHED,
};
int HdfDeviceNodeAddPowerStateListener(
    struct HdfDeviceNode *devNode, const struct IPowerEventListener *listener);
void HdfDeviceNodeRemovePowerStateListener(
    struct HdfDeviceNode *devNode, const struct IPowerEventListener *listener);
void HdfDeviceNodeConstruct(struct HdfDeviceNode *devNode);
void HdfDeviceNodeDestruct(struct HdfDeviceNode *devNode);
struct HdfDeviceNode *HdfDeviceNodeNewInstance(const struct HdfDeviceInfo *deviceInfo, struct HdfDriver *driver);
void HdfDeviceNodeFreeInstance(struct HdfDeviceNode *devNode);
void HdfDeviceNodeDelete(struct HdfDeviceNode *devNode);
int HdfDeviceNodePublishPublicService(struct HdfDeviceNode *devNode);
int HdfDeviceNodeRemoveService(struct HdfDeviceNode *devNode);
int DeviceDriverBind(struct HdfDeviceNode *devNode);
struct IDriverLoader {
    struct HdfObject object;
    struct HdfDriver *(*GetDriver)(const char *driverName);
    void (*ReclaimDriver)(struct HdfDriver *driver);
};
struct HdfDriverLoader {
    struct IDriverLoader super;
};
struct HdfObject *HdfDriverLoaderCreate(void);
void HdfDriverLoaderConstruct(struct HdfDriverLoader *inst);
void HdfDriverLoaderRelease(struct HdfObject *object);
struct IDriverLoader *HdfDriverLoaderGetInstance(void);
struct HdfDriver *HdfDriverLoaderGetDriver(const char *moduleName);
struct HdfDeviceNode *HdfDriverLoaderLoadNode(
    struct IDriverLoader *loader, const struct HdfDeviceInfo *deviceInfo);
void HdfDriverLoaderUnLoadNode(struct IDriverLoader *loader, const struct HdfDeviceInfo *deviceInfo);
struct IDevHostService {
    struct HdfObject object;
    int (*AddDevice)(struct IDevHostService *hostService, const struct HdfDeviceInfo *devInfo);
    int (*DelDevice)(struct IDevHostService *hostService, devid_t devId);
    int (*StartService)(struct IDevHostService *hostService);
    int (*PmNotify)(struct IDevHostService *service, uint32_t powerState);
    int (*Dump)(struct IDevHostService *hostService, struct HdfSBuf *data, struct HdfSBuf *reply);
};
struct IHdfDeviceToken {
    struct HdfObject object;
    devid_t devid;
    const char *servName;
    const char *deviceName;
};
enum HdfPowerState {
    POWER_STATE_DOZE_RESUME,
    POWER_STATE_DOZE_SUSPEND,
    POWER_STATE_RESUME,
    POWER_STATE_SUSPEND,
    POWER_STATE_MAX,
};
static inline _Bool IsPowerWakeState(uint32_t state)
{
    return state == POWER_STATE_DOZE_RESUME || state == POWER_STATE_RESUME;
}
static inline _Bool IsValidPowerState(uint32_t state)
{
    return state < POWER_STATE_MAX;
}

typedef enum {
    PSM_STATE_IDLE,
    PSM_STATE_ACTIVE,
    PSM_STATE_INACTIVE,
} HdfPsmState;
struct IPowerStateToken {
    void (*AcquireWakeLock)(struct IPowerStateToken *);
    void (*ReleaseWakeLock)(struct IPowerStateToken *);
};

struct IDevmgrService {
    struct HdfObject base;
    struct HdfDeviceObject object;
    int (*AttachDeviceHost)(struct IDevmgrService *, uint16_t, struct IDevHostService *);
    int (*AttachDevice)(struct IDevmgrService *, struct IHdfDeviceToken *);
    int (*DetachDevice)(struct IDevmgrService *, devid_t);
    int (*LoadDevice)(struct IDevmgrService *, const char *);
    int (*UnloadDevice)(struct IDevmgrService *, const char *);
    int (*StartService)(struct IDevmgrService *);
    int (*PowerStateChange)(struct IDevmgrService *, enum HdfPowerState pEvent);
    int (*ListAllDevice)(struct IDevmgrService *, struct HdfSBuf *);
};
struct HdfDeviceToken {
    struct IHdfDeviceToken super;
    struct HdfSListNode node;
};
struct HdfObject *HdfDeviceTokenCreate(void);
void HdfDeviceTokenRelease(struct HdfObject *object);
struct IHdfDeviceToken *HdfDeviceTokenNewInstance(void);
void HdfDeviceTokenFreeInstance(struct IHdfDeviceToken *token);
struct DevmgrServiceClnt {
    struct IDevmgrService *devMgrSvcIf;
};
struct DevmgrServiceClnt *DevmgrServiceClntGetInstance(void);
void DevmgrServiceClntFreeInstance(struct DevmgrServiceClnt *inst);
int DevmgrServiceClntAttachDevice(struct IHdfDeviceToken *deviceToken);
int DevmgrServiceClntDetachDevice(devid_t devid);
int DevmgrServiceClntAttachDeviceHost(uint16_t hostId, struct IDevHostService *hostService);
struct OsalMutex {
    void *realMutex;
};
int32_t OsalMutexInit(struct OsalMutex *mutex);
int32_t OsalMutexDestroy(struct OsalMutex *mutex);
int32_t OsalMutexLock(struct OsalMutex *mutex);
int32_t OsalMutexTimedLock(struct OsalMutex *mutex, uint32_t ms);
int32_t OsalMutexUnlock(struct OsalMutex *mutex);

struct HdfServiceObserver {
    struct HdfSList services;
    struct OsalMutex observerMutex;
};
_Bool HdfServiceObserverConstruct(struct HdfServiceObserver *observer);
void HdfServiceObserverDestruct(struct HdfServiceObserver *observer);
int HdfServiceObserverPublishService(struct HdfServiceObserver *observer,
    const char *svcName, devid_t deviceId, uint16_t policy, struct HdfObject *service);
int HdfServiceObserverSubscribeService(struct HdfServiceObserver *observer,
    const char *svcName, devid_t deviceId, struct SubscriberCallback callback);
void HdfServiceObserverRemoveRecord(struct HdfServiceObserver *observer, const char *svcName);
int DevMgrPmRegister(void);
struct ServiceStatusListener;
enum ServiceStatusType {
    SERVIE_STATUS_START,
    SERVIE_STATUS_CHANGE,
    SERVIE_STATUS_STOP,
    SERVIE_STATUS_REGISTER,
    SERVIE_STATUS_MAX,
};
struct ServiceStatus {
    const char* serviceName;
    uint16_t deviceClass;
    uint16_t status;
    const char *info;
};
typedef void (*OnServiceStatusReceived)(struct ServiceStatusListener *listener, struct ServiceStatus *status);
struct ServiceStatusListener {
    OnServiceStatusReceived callback;
    void *priv;
};
struct HdfSBuf;
enum ServiceStatusListenerCmd {
    SERVIE_STATUS_LISTENER_NOTIFY,
    SERVIE_STATUS_LISTENER_MAX,
};
int ServiceStatusMarshalling(struct ServiceStatus *status, struct HdfSBuf *buf);
int ServiceStatusUnMarshalling(struct ServiceStatus *status, struct HdfSBuf *buf);

struct ServStatListenerHolder {
    uint16_t listenClass;
    struct DListHead node;
    uint64_t index;
    int32_t (*NotifyStatus)(struct ServStatListenerHolder *holder, struct ServiceStatus *status);
    void (*Recycle)(struct ServStatListenerHolder *holder);
};
void ServStatListenerHolderinit(void);
struct ServStatListenerHolder *ServStatListenerHolderCreate(uintptr_t listener, uint16_t listenClass);
void ServStatListenerHolderRelease(struct ServStatListenerHolder *holder);
struct ServStatListenerHolder *ServStatListenerHolderGet(uint64_t index);
struct HdfServiceInfo {
    const char *servName;
    const char *servInfo;
    uint16_t devClass;
    devid_t devId;
    const char *interfaceDesc;
};
static inline void HdfServiceInfoInit(struct HdfServiceInfo *info, const struct HdfDeviceNode *devNode)
{
    info->servName = devNode->servName;
    info->servInfo = devNode->servInfo;
    info->devClass = devNode->deviceObject.deviceClass;
    info->devId = devNode->devId;
    info->interfaceDesc = devNode->interfaceDesc;
}

struct IDevSvcManager {
    struct HdfObject object;
    int (*StartService)(struct IDevSvcManager *);
    int (*AddService)(struct IDevSvcManager *, struct HdfDeviceObject *, const struct HdfServiceInfo *);
    int (*UpdateService)(struct IDevSvcManager *, struct HdfDeviceObject *, const struct HdfServiceInfo *);
    int (*SubscribeService)(struct IDevSvcManager *, const char *, struct SubscriberCallback);
    int (*UnsubscribeService)(struct IDevSvcManager *, const char *);
    struct HdfObject *(*GetService)(struct IDevSvcManager *, const char *);
    struct HdfDeviceObject *(*GetObject)(struct IDevSvcManager *, const char *);
    void (*RemoveService)(struct IDevSvcManager *, const char *, const struct HdfDeviceObject *);
    int (*RegsterServListener)(struct IDevSvcManager *, struct ServStatListenerHolder *);
    void (*UnregsterServListener)(struct IDevSvcManager *, struct ServStatListenerHolder *);
    void (*ListAllService)(struct IDevSvcManager *, struct HdfSBuf *);
    int (*ListServiceByInterfaceDesc)(struct IDevSvcManager *, const char *, struct HdfSBuf *);
};
struct DevSvcManagerClnt {
    struct IDevSvcManager *devSvcMgrIf;
};
struct DevSvcManagerClnt *DevSvcManagerClntGetInstance(void);
struct HdfDeviceObject *DevSvcManagerClntGetDeviceObject(const char *svcName);
int DevSvcManagerClntAddService(struct HdfDeviceObject *service, const struct HdfServiceInfo *servinfo);
int DevSvcManagerClntUpdateService(struct HdfDeviceObject *service, const struct HdfServiceInfo *servinfo);
void DevSvcManagerClntRemoveService(const char *svcName);
int DevSvcManagerClntSubscribeService(const char *svcName, struct SubscriberCallback callback);
int DevSvcManagerClntUnsubscribeService(const char *svcName);
struct DevHostService {
    struct IDevHostService super;
    uint16_t hostId;
    const char *hostName;
    struct DListHead devices;
    struct HdfServiceObserver observer;
    struct HdfSysEventNotifyNode sysEventNotifyNode;
};
void DevHostServiceConstruct(struct DevHostService *service);
void DevHostServiceDestruct(struct DevHostService *service);
int DevHostServiceAddDevice(struct IDevHostService *inst, const struct HdfDeviceInfo *deviceInfo);
int DevHostServiceDelDevice(struct IDevHostService *inst, devid_t devId);
struct IDevHostService *DevHostServiceNewInstance(uint16_t hostId, const char *hostName);
void DevHostServiceFreeInstance(struct IDevHostService *service);
struct HdfObject *DevHostServiceCreate(void);
void DevHostServiceRelease(struct HdfObject *object);
struct OsalSem {
    void *realSemaphore;
};
int32_t OsalSemInit(struct OsalSem *sem, uint32_t value);
int32_t OsalSemWait(struct OsalSem *sem, uint32_t ms);
int32_t OsalSemPost(struct OsalSem *sem);
int32_t OsalSemDestroy(struct OsalSem *sem);

typedef enum {
    OSAL_THREAD_PRI_LOW,
    OSAL_THREAD_PRI_DEFAULT,
    OSAL_THREAD_PRI_HIGH,
    OSAL_THREAD_PRI_HIGHEST
} OSAL_THREAD_PRIORITY;
struct OsalThreadParam {
    char *name;
    size_t stackSize;
    OSAL_THREAD_PRIORITY priority;
    int policy;
};
typedef int (*OsalThreadEntry)(void *);
struct OsalThread {
    void *realThread;
};
int32_t OsalThreadCreate(struct OsalThread *thread, OsalThreadEntry threadEntry, void *entryPara);
int32_t OsalThreadBind(struct OsalThread *thread, unsigned int cpuID);
int32_t OsalThreadStart(struct OsalThread *thread, const struct OsalThreadParam *param);
int32_t OsalThreadDestroy(struct OsalThread *thread);
int32_t OsalThreadSuspend(struct OsalThread *thread);
int32_t OsalThreadResume(struct OsalThread *thread);

struct HdfTaskType;
typedef int32_t (*HdfTaskFunc)(struct HdfTaskType *para);
struct HdfTaskType {
    struct DListHead node;
    HdfTaskFunc func;
};
struct HdfTaskQueue {
    struct OsalSem sem;
    struct OsalMutex mutex;
    struct DListHead head;
    struct OsalThread thread;
    _Bool threadRunFlag;
    HdfTaskFunc queueFunc;
    const char *queueName;
};
void HdfTaskEnqueue(struct HdfTaskQueue *queue, struct HdfTaskType *task);
struct HdfTaskQueue *HdfTaskQueueCreate(HdfTaskFunc func, const char *name);
void HdfTaskQueueDestroy(struct HdfTaskQueue *queue);
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
typedef INT32 ssize_t;
typedef UINT32 size_t;
typedef UINTPTR AARCHPTR;
typedef size_t BOOL;
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
typedef volatile INT32 Atomic;
typedef volatile INT64 Atomic64;
static inline INT32 LOS_AtomicRead(const Atomic *v)
{
    return *(volatile INT32 *)v;
}
static inline void LOS_AtomicSet(Atomic *v, INT32 setVal)
{
    *(volatile INT32 *)v = setVal;
}
static inline INT32 LOS_AtomicAdd(Atomic *v, INT32 addVal)
{
    INT32 val;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrex   %1, [%2]\n"
                             "add   %1, %1, %3\n"
                             "strex   %0, %1, [%2]"
                             : "=&r"(status), "=&r"(val)
                             : "r"(v), "r"(addVal)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return val;
}
static inline INT32 LOS_AtomicSub(Atomic *v, INT32 subVal)
{
    INT32 val;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrex   %1, [%2]\n"
                             "sub   %1, %1, %3\n"
                             "strex   %0, %1, [%2]"
                             : "=&r"(status), "=&r"(val)
                             : "r"(v), "r"(subVal)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return val;
}
static inline void LOS_AtomicInc(Atomic *v)
{
    INT32 val;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrex   %0, [%3]\n"
                             "add   %0, %0, #1\n"
                             "strex   %1, %0, [%3]"
                             : "=&r"(val), "=&r"(status), "+m"(*v)
                             : "r"(v)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
}
static inline INT32 LOS_AtomicIncRet(Atomic *v)
{
    INT32 val;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrex   %0, [%3]\n"
                             "add   %0, %0, #1\n"
                             "strex   %1, %0, [%3]"
                             : "=&r"(val), "=&r"(status), "+m"(*v)
                             : "r"(v)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return val;
}
static inline void LOS_AtomicDec(Atomic *v)
{
    INT32 val;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrex   %0, [%3]\n"
                             "sub   %0, %0, #1\n"
                             "strex   %1, %0, [%3]"
                             : "=&r"(val), "=&r"(status), "+m"(*v)
                             : "r"(v)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
}
static inline INT32 LOS_AtomicDecRet(Atomic *v)
{
    INT32 val;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrex   %0, [%3]\n"
                             "sub   %0, %0, #1\n"
                             "strex   %1, %0, [%3]"
                             : "=&r"(val), "=&r"(status), "+m"(*v)
                             : "r"(v)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return val;
}
static inline INT64 LOS_Atomic64Read(const Atomic64 *v)
{
    INT64 val;
    do {
        __asm__ __volatile__("ldrexd   %0, %H0, [%1]"
                             : "=&r"(val)
                             : "r"(v)
                             : "cc");
    } while (0);
    return val;
}
static inline void LOS_Atomic64Set(Atomic64 *v, INT64 setVal)
{
    INT64 tmp;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrexd   %1, %H1, [%2]\n"
                             "strexd   %0, %3, %H3, [%2]"
                             : "=&r"(status), "=&r"(tmp)
                             : "r"(v), "r"(setVal)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
}
static inline INT64 LOS_Atomic64Add(Atomic64 *v, INT64 addVal)
{
    INT64 val;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrexd   %1, %H1, [%2]\n"
                             "adds   %Q1, %Q1, %Q3\n"
                             "adc   %R1, %R1, %R3\n"
                             "strexd   %0, %1, %H1, [%2]"
                             : "=&r"(status), "=&r"(val)
                             : "r"(v), "r"(addVal)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return val;
}
static inline INT64 LOS_Atomic64Sub(Atomic64 *v, INT64 subVal)
{
    INT64 val;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrexd   %1, %H1, [%2]\n"
                             "subs   %Q1, %Q1, %Q3\n"
                             "sbc   %R1, %R1, %R3\n"
                             "strexd   %0, %1, %H1, [%2]"
                             : "=&r"(status), "=&r"(val)
                             : "r"(v), "r"(subVal)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return val;
}
static inline void LOS_Atomic64Inc(Atomic64 *v)
{
    INT64 val;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrexd   %0, %H0, [%3]\n"
                             "adds   %Q0, %Q0, #1\n"
                             "adc   %R0, %R0, #0\n"
                             "strexd   %1, %0, %H0, [%3]"
                             : "=&r"(val), "=&r"(status), "+m"(*v)
                             : "r"(v)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
}
static inline INT64 LOS_Atomic64IncRet(Atomic64 *v)
{
    INT64 val;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrexd   %0, %H0, [%3]\n"
                             "adds   %Q0, %Q0, #1\n"
                             "adc   %R0, %R0, #0\n"
                             "strexd   %1, %0, %H0, [%3]"
                             : "=&r"(val), "=&r"(status), "+m"(*v)
                             : "r"(v)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return val;
}
static inline void LOS_Atomic64Dec(Atomic64 *v)
{
    INT64 val;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrexd   %0, %H0, [%3]\n"
                             "subs   %Q0, %Q0, #1\n"
                             "sbc   %R0, %R0, #0\n"
                             "strexd   %1, %0, %H0, [%3]"
                             : "=&r"(val), "=&r"(status), "+m"(*v)
                             : "r"(v)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
}
static inline INT64 LOS_Atomic64DecRet(Atomic64 *v)
{
    INT64 val;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrexd   %0, %H0, [%3]\n"
                             "subs   %Q0, %Q0, #1\n"
                             "sbc   %R0, %R0, #0\n"
                             "strexd   %1, %0, %H0, [%3]"
                             : "=&r"(val), "=&r"(status), "+m"(*v)
                             : "r"(v)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return val;
}
static inline INT32 LOS_AtomicXchgByte(volatile INT8 *v, INT32 val)
{
    INT32 prevVal;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrexb   %0, [%3]\n"
                             "strexb   %1, %4, [%3]"
                             : "=&r"(prevVal), "=&r"(status), "+m"(*v)
                             : "r"(v), "r"(val)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return prevVal;
}
static inline INT32 LOS_AtomicXchg16bits(volatile INT16 *v, INT32 val)
{
    INT32 prevVal;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrexh   %0, [%3]\n"
                             "strexh   %1, %4, [%3]"
                             : "=&r"(prevVal), "=&r"(status), "+m"(*v)
                             : "r"(v), "r"(val)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return prevVal;
}
static inline INT32 LOS_AtomicXchg32bits(Atomic *v, INT32 val)
{
    INT32 prevVal;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrex   %0, [%3]\n"
                             "strex   %1, %4, [%3]"
                             : "=&r"(prevVal), "=&r"(status), "+m"(*v)
                             : "r"(v), "r"(val)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return prevVal;
}
static inline INT64 LOS_AtomicXchg64bits(Atomic64 *v, INT64 val)
{
    INT64 prevVal;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrexd   %0, %H0, [%3]\n"
                             "strexd   %1, %4, %H4, [%3]"
                             : "=&r"(prevVal), "=&r"(status), "+m"(*v)
                             : "r"(v), "r"(val)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return prevVal;
}
static inline BOOL LOS_AtomicCmpXchgByte(volatile INT8 *v, INT32 val, INT32 oldVal)
{
    INT32 prevVal;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrexb %0, [%3]\n"
                             "mov %1, #0\n"
                             "teq %0, %4\n"
                             "strexbeq %1, %5, [%3]"
                             : "=&r"(prevVal), "=&r"(status), "+m"(*v)
                             : "r"(v), "r"(oldVal), "r"(val)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return prevVal != oldVal;
}
static inline BOOL LOS_AtomicCmpXchg16bits(volatile INT16 *v, INT32 val, INT32 oldVal)
{
    INT32 prevVal;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrexh %0, [%3]\n"
                             "mov %1, #0\n"
                             "teq %0, %4\n"
                             "strexheq %1, %5, [%3]"
                             : "=&r"(prevVal), "=&r"(status), "+m"(*v)
                             : "r"(v), "r"(oldVal), "r"(val)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return prevVal != oldVal;
}
static inline BOOL LOS_AtomicCmpXchg32bits(Atomic *v, INT32 val, INT32 oldVal)
{
    INT32 prevVal;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrex %0, [%3]\n"
                             "mov %1, #0\n"
                             "teq %0, %4\n"
                             "strexeq %1, %5, [%3]"
                             : "=&r"(prevVal), "=&r"(status), "+m"(*v)
                             : "r"(v), "r"(oldVal), "r"(val)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return prevVal != oldVal;
}
static inline BOOL LOS_AtomicCmpXchg64bits(Atomic64 *v, INT64 val, INT64 oldVal)
{
    INT64 prevVal;
    UINT32 status;
    do {
        __asm__ __volatile__("ldrexd   %0, %H0, [%3]\n"
                             "mov   %1, #0\n"
                             "teq   %0, %4\n"
                             "teqeq   %H0, %H4\n"
                             "strexdeq   %1, %5, %H5, [%3]"
                             : "=&r"(prevVal), "=&r"(status), "+m"(*v)
                             : "r"(v), "r"(oldVal), "r"(val)
                             : "cc");
    } while (__builtin_expect(status != 0, 0));
    return prevVal != oldVal;
}
typedef void (*LOS_ERRORHANDLE_FUNC)(CHAR *fileName,
                                     UINT32 lineNo,
                                     UINT32 errorNo,
                                     UINT32 paraLen,
                                     void *para);
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
extern UINT32 g_sysClock;
extern UINT32 g_tickPerSecond;
extern void LOS_GetCpuCycle(UINT32 *puwCntHi, UINT32 *puwCntLo);
extern UINT64 LOS_CurrNanosec(void);
extern void LOS_Udelay(UINT32 usecs);
extern void LOS_Mdelay(UINT32 usecs);
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
extern UINT32 OsMain(void);
typedef void (*SystemRebootFunc)(void);
void OsSetRebootHook(SystemRebootFunc func);
SystemRebootFunc OsGetRebootHook(void);
extern void LOS_LkPrint(INT32 level, const CHAR *func, INT32 line, const CHAR *fmt, ...);
typedef void (*pf_OUTPUT)(const CHAR *fmt, ...);
extern void c2r_liteos_dprintf(const char *fmt, ...);
typedef enum {
    NO_OUTPUT = 0,
    UART_OUTPUT = 1,
    CONSOLE_OUTPUT = 2,
    EXC_OUTPUT = 3
} OutputType;
extern void OsVprintf(const CHAR *fmt, va_list ap, OutputType type);
extern void UartPuts(const CHAR *s, UINT32 len, BOOL isLock);
typedef struct LOS_DL_LIST {
    struct LOS_DL_LIST *pstPrev;
    struct LOS_DL_LIST *pstNext;
} LOS_DL_LIST;
                       static inline void LOS_ListInit(LOS_DL_LIST *list)
{
    list->pstNext = list;
    list->pstPrev = list;
}
                       static inline void LOS_ListAdd(LOS_DL_LIST *list, LOS_DL_LIST *node)
{
    node->pstNext = list->pstNext;
    node->pstPrev = list;
    list->pstNext->pstPrev = node;
    list->pstNext = node;
}
                       static inline void LOS_ListTailInsert(LOS_DL_LIST *list, LOS_DL_LIST *node)
{
    LOS_ListAdd(list->pstPrev, node);
}
                       static inline void LOS_ListHeadInsert(LOS_DL_LIST *list, LOS_DL_LIST *node)
{
    LOS_ListAdd(list, node);
}
                       static inline void LOS_ListDelete(LOS_DL_LIST *node)
{
    node->pstNext->pstPrev = node->pstPrev;
    node->pstPrev->pstNext = node->pstNext;
    node->pstNext = ((void*)0);
    node->pstPrev = ((void*)0);
}
                       static inline BOOL LOS_ListEmpty(LOS_DL_LIST *list)
{
    return (BOOL)(list->pstNext == list);
}
                       static inline void LOS_ListAddList(LOS_DL_LIST *oldList, LOS_DL_LIST *newList)
{
    LOS_DL_LIST *oldListHead = oldList->pstNext;
    LOS_DL_LIST *oldListTail = oldList;
    LOS_DL_LIST *newListHead = newList;
    LOS_DL_LIST *newListTail = newList->pstPrev;
    oldListTail->pstNext = newListHead;
    newListHead->pstPrev = oldListTail;
    oldListHead->pstPrev = newListTail;
    newListTail->pstNext = oldListHead;
}
                       static inline void LOS_ListTailInsertList(LOS_DL_LIST *oldList, LOS_DL_LIST *newList)
{
    LOS_ListAddList(oldList->pstPrev, newList);
}
                       static inline void LOS_ListHeadInsertList(LOS_DL_LIST *oldList, LOS_DL_LIST *newList)
{
    LOS_ListAddList(oldList, newList);
}
                       static inline void LOS_ListDelInit(LOS_DL_LIST *list)
{
    list->pstNext->pstPrev = list->pstPrev;
    list->pstPrev->pstNext = list->pstNext;
    LOS_ListInit(list);
}
static inline void *ArchCurrTaskGet(void)
{
    return (void *)(UINTPTR)({ UINT32 _val; __asm__ volatile("mrc " "p15, ""0"", %0, ""c13"",""c0"",""4" : "=r" (_val)); _val; });
}
static inline void ArchCurrTaskSet(void *val)
{
    ({ __asm__ volatile("mcr " "p15, ""0"", %0, ""c13"",""c0"",""4" :: "r" ((UINT32)(UINTPTR)val)); __asm__ volatile("isb" ::: "memory"); });
}
static inline void ArchCurrUserTaskSet(UINTPTR val)
{
    ({ __asm__ volatile("mcr " "p15, ""0"", %0, ""c13"",""c0"",""3" :: "r" ((UINT32)val)); __asm__ volatile("isb" ::: "memory"); });
}
static inline UINT32 ArchCurrCpuid(void)
{
    return ({ UINT32 _val; __asm__ volatile("mrc " "p15, ""0"", %0, ""c0"",""c0"",""5" : "=r" (_val)); _val; }) & (0xffU);
}
static inline UINT64 OsHwIDGet(void)
{
    return ({ UINT32 _val; __asm__ volatile("mrc " "p15, ""0"", %0, ""c0"",""c0"",""5" : "=r" (_val)); _val; });
}
static inline UINT32 OsMainIDGet(void)
{
    return ({ UINT32 _val; __asm__ volatile("mrc " "p15, ""0"", %0, ""c0"",""c0"",""0" : "=r" (_val)); _val; });
}
static inline UINT32 ArchIntLock(void)
{
    UINT32 intSave;
    __asm__ __volatile__(
        "mrs    %0, cpsr      \n"
        "cpsid  if              "
        : "=r"(intSave)
        :
        : "memory");
    return intSave;
}
static inline UINT32 ArchIntUnlock(void)
{
    UINT32 intSave;
    __asm__ __volatile__(
        "mrs    %0, cpsr      \n"
        "cpsie  if              "
        : "=r"(intSave)
        :
        : "memory");
    return intSave;
}
static inline void ArchIrqDisable(void)
{
    __asm__ __volatile__(
        "cpsid  i      "
        :
        :
        : "memory", "cc");
}
static inline void ArchIrqEnable(void)
{
    __asm__ __volatile__(
        "cpsie  i      "
        :
        :
        : "memory", "cc");
}
static inline void ArchIntRestore(UINT32 intSave)
{
    __asm__ __volatile__(
        "msr    cpsr_c, %0      "
        :
        : "r"(intSave)
        : "memory");
}
static inline UINT32 OsIntLocked(void)
{
    UINT32 intSave;
    __asm volatile(
        "mrs    %0, cpsr        "
        : "=r" (intSave)
        :
        : "memory", "cc");
    return intSave & 0x00000080U;
}
static inline UINT32 ArchSPGet(void)
{
    UINT32 val;
    __asm__ __volatile__("mov %0, sp" : "=r"(val));
    return val;
}
typedef struct {
    const UINT32 partNo;
    const CHAR *cpuName;
} CpuVendor;
extern CpuVendor g_cpuTable[];
extern UINT64 g_cpuMap[];
extern void FlushICache(void);
extern void DCacheFlushRange(UINTPTR start, UINTPTR end);
extern void DCacheInvRange(UINTPTR start, UINTPTR end);
static inline const CHAR *LOS_CpuInfo(void)
{
    INT32 i;
    UINT32 midr = OsMainIDGet();
    UINT32 partNo = (midr & 0xFFF0) >> 0x4;
    for (i = 0; g_cpuTable[i].partNo != 0; i++) {
        if (partNo == g_cpuTable[i].partNo) {
            return g_cpuTable[i].cpuName;
        }
    }
    return "unknown";
}

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
_Noreturn void abort (void);
_Noreturn void __cfi_fail_report (void);
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
unsigned int arc4random(void);
unsigned int arc4random_uniform(unsigned int);
void arc4random_buf(void *, size_t);
size_t __ctype_get_mb_cur_max(void);
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

void *alloca(size_t);
char *mktemp (char *);
int mkstemps (char *, int);
int mkostemps (char *, int, int);
void *valloc (size_t);
void *memalign(size_t, size_t);
int getloadavg(double *, int);
int clearenv(void);
void *reallocarray (void *, size_t, size_t);
void qsort_r (void *, size_t, size_t, int (*)(const void *, const void *, void *), void *);
__attribute__((const))
int *__errno_location(void);
typedef int errno_t;
extern const char *GetHwSecureCVersion(unsigned short *verNumber);
extern errno_t memset_s(void *dest, size_t destMax, int c, size_t count);
extern errno_t memmove_s(void *dest, size_t destMax, const void *src, size_t count);
extern errno_t memcpy_s(void *dest, size_t destMax, const void *src, size_t count);
extern errno_t strcpy_s(char *strDest, size_t destMax, const char *strSrc);
extern errno_t strncpy_s(char *strDest, size_t destMax, const char *strSrc, size_t count);
extern errno_t strcat_s(char *strDest, size_t destMax, const char *strSrc);
extern errno_t strncat_s(char *strDest, size_t destMax, const char *strSrc, size_t count);
extern int vsprintf_s(char *strDest, size_t destMax, const char *format,
                           va_list argList) ;
extern int sprintf_s(char *strDest, size_t destMax, const char *format, ...) ;
extern int vsnprintf_s(char *strDest, size_t destMax, size_t count, const char *format,
                            va_list argList) ;
extern int snprintf_s(char *strDest, size_t destMax, size_t count, const char *format,
                           ...) ;
extern int vsnprintf_truncated_s(char *strDest, size_t destMax, const char *format,
                                      va_list argList) ;
extern int snprintf_truncated_s(char *strDest, size_t destMax,
                                     const char *format, ...) ;
extern int scanf_s(const char *format, ...);
extern int vscanf_s(const char *format, va_list argList);
extern int sscanf_s(const char *buffer, const char *format, ...);
extern int vsscanf_s(const char *buffer, const char *format, va_list argList);
extern int fscanf_s(FILE *stream, const char *format, ...);
extern int vfscanf_s(FILE *stream, const char *format, va_list argList);
extern char *strtok_s(char *strToken, const char *strDelimit, char **context);
extern char *gets_s(char *buffer, size_t destMax);
extern errno_t wmemcpy_s(wchar_t *dest, size_t destMax, const wchar_t *src, size_t count);
extern errno_t wmemmove_s(wchar_t *dest, size_t destMax, const wchar_t *src, size_t count);
extern errno_t wcscpy_s(wchar_t *strDest, size_t destMax, const wchar_t *strSrc);
extern errno_t wcsncpy_s(wchar_t *strDest, size_t destMax, const wchar_t *strSrc, size_t count);
extern errno_t wcscat_s(wchar_t *strDest, size_t destMax, const wchar_t *strSrc);
extern errno_t wcsncat_s(wchar_t *strDest, size_t destMax, const wchar_t *strSrc, size_t count);
extern wchar_t *wcstok_s(wchar_t *strToken, const wchar_t *strDelimit, wchar_t **context);
extern int vswprintf_s(wchar_t *strDest, size_t destMax, const wchar_t *format, va_list argList);
extern int swprintf_s(wchar_t *strDest, size_t destMax, const wchar_t *format, ...);
extern int fwscanf_s(FILE *stream, const wchar_t *format, ...);
extern int vfwscanf_s(FILE *stream, const wchar_t *format, va_list argList);
extern int wscanf_s(const wchar_t *format, ...);
extern int vwscanf_s(const wchar_t *format, va_list argList);
extern int swscanf_s(const wchar_t *buffer, const wchar_t *format, ...);
extern int vswscanf_s(const wchar_t *buffer, const wchar_t *format, va_list argList);
extern errno_t strncpy_error(char *strDest, size_t destMax, const char *strSrc, size_t count);
extern errno_t strcpy_error(char *strDest, size_t destMax, const char *strSrc);
extern errno_t memset_sOptAsm(void *dest, size_t destMax, int c, size_t count);
extern errno_t memset_sOptTc(void *dest, size_t destMax, int c, size_t count);
extern errno_t memcpy_sOptAsm(void *dest, size_t destMax, const void *src, size_t count);
extern errno_t memcpy_sOptTc(void *dest, size_t destMax, const void *src, size_t count);
typedef struct {
    UINT32 R4;
    UINT32 R5;
    UINT32 R6;
    UINT32 R7;
    UINT32 R8;
    UINT32 R9;
    UINT32 R10;
    UINT32 R11;
    UINT32 SP;
    UINT32 reserved;
    UINT32 USP;
    UINT32 ULR;
    UINT32 R0;
    UINT32 R1;
    UINT32 R2;
    UINT32 R3;
    UINT32 R12;
    UINT32 LR;
    UINT32 PC;
    UINT32 regCPSR;
} ExcContext;
typedef struct {
    UINT16 phase;
    UINT16 type;
    UINT16 nestCnt;
    UINT16 reserved;
    ExcContext *context;
} ExcInfo;
static inline UINTPTR Get_Fp(void)
{
    UINTPTR regFp;
    __asm__ __volatile__("mov %0, fp" : "=r"(regFp));
    return regFp;
}
typedef void (*EXC_PROC_FUNC)(UINT32, ExcContext *, UINT32, UINT32);
extern UINT32 LOS_ExcRegHook(EXC_PROC_FUNC excHook);
__attribute__ ((__noreturn__)) void LOS_Panic(const CHAR *fmt, ...);
void LOS_RecordLR(UINTPTR *LR, UINT32 LRSize, UINT32 recordCount, UINT32 jumpCount);
extern void OsBackTrace(void);
extern void OsTaskBackTrace(UINT32 taskID);
extern void PrintExcInfo(const CHAR *fmt, ...);
extern UINTPTR LOS_Align(UINTPTR addr, UINT32 boundary);
extern void LOS_Msleep(UINT32 msecs);

extern void HalIrqInit(void);
extern void HalIrqInitPercpu(void);
extern void HalIrqMask(UINT32 vector);
extern void HalIrqUnmask(UINT32 vector);
extern void HalIrqPending(UINT32 vector);
extern void HalIrqClear(UINT32 vector);
extern CHAR *HalIrqVersion(void);
extern UINT32 HalCurIrqGet(void);
extern UINT32 HalIrqSetPrio(UINT32 vector, UINT8 priority);
extern void HalIrqSendIpi(UINT32 target, UINT32 ipi);
extern void HalIrqSetAffinity(UINT32 vector, UINT32 cpuMask);
extern size_t g_intCount[];
typedef UINT32 HWI_HANDLE_T;
typedef UINT16 HWI_PRIOR_T;
typedef UINT16 HWI_MODE_T;
typedef UINTPTR HWI_ARG_T;
typedef void (*HWI_PROC_FUNC)(void);
typedef struct tagHwiHandleForm {
    HWI_PROC_FUNC pfnHook;
    HWI_ARG_T uwParam;
    struct tagHwiHandleForm *pstNext;
} HwiHandleForm;
typedef struct tagIrqParam {
    int swIrq;
    void *pDevId;
    const CHAR *pName;
} HwiIrqParam;
extern HwiHandleForm g_hwiForm[128];
static inline UINT32 LOS_IntLock(void)
{
    return ArchIntLock();
}
static inline UINT32 LOS_IntUnLock(void)
{
    return ArchIntUnlock();
}
static inline void LOS_IntRestore(UINT32 intSave)
{
    ArchIntRestore(intSave);
}
extern UINT32 LOS_GetSystemHwiMaximum(void);
extern UINT32 LOS_HwiCreate(HWI_HANDLE_T hwiNum,
                            HWI_PRIOR_T hwiPrio,
                            HWI_MODE_T hwiMode,
                            HWI_PROC_FUNC hwiHandler,
                            HwiIrqParam *irqParam);
extern UINT32 LOS_HwiDelete(HWI_HANDLE_T hwiNum, HwiIrqParam *irqParam);
static inline int32_t OsalTestBitWrapper(unsigned long nr, const volatile unsigned long *addr)
{
    return (1UL & (addr[((nr) / 32)] >> (nr & (32 - 1))));
}
static inline int32_t OsalTestSetBitWrapper(unsigned long nr, volatile unsigned long *addr)
{
    uint32_t intSave = LOS_IntLock();
    const unsigned long mask = (1UL << ((nr) % 32));
    unsigned long *p = ((unsigned long *)addr) + ((nr) / 32);
    unsigned long old = *p;
    *p = old | mask;
    LOS_IntRestore(intSave);
    return ((old & mask) != 0);
}
static inline int32_t OsalTestClearBitWrapper(unsigned long nr, volatile unsigned long *addr)
{
    uint32_t intSave = LOS_IntLock();
    const unsigned long mask = (1UL << ((nr) % 32));
    unsigned long *p = ((unsigned long *)addr) + ((nr) / 32);
    unsigned long old = *p;
    *p = old & ~mask;
    LOS_IntRestore(intSave);
    return ((old & mask) != 0);
}
static inline void OsalClearBitWrapper(unsigned long nr, volatile unsigned long *addr)
{
    uint32_t intSave = LOS_IntLock();
    const unsigned long mask = (1UL << ((nr) % 32));
    unsigned long *p = ((unsigned long *)addr) + ((nr) / 32);
    *p &= ~mask;
    LOS_IntRestore(intSave);
}
typedef struct {
    volatile int32_t counter;
} OsalAtomic;
struct HdfSRef;
struct IHdfSRefListener {
    void (*OnFirstAcquire)(struct HdfSRef *);
    void (*OnLastRelease)(struct HdfSRef *);
};
struct HdfSRef {
    OsalAtomic refs;
    struct IHdfSRefListener *listener;
    void (*Acquire)(struct HdfSRef *);
    void (*Release)(struct HdfSRef *);
    int (*Count)(const struct HdfSRef *);
};
void HdfSRefAcquire(struct HdfSRef *sref);
void HdfSRefRelease(struct HdfSRef *sref);
int HdfSRefCount(const struct HdfSRef *sref);
void HdfSRefConstruct(struct HdfSRef *sref, struct IHdfSRefListener *listener);
struct PowerStateToken {
    struct IPowerStateToken super;
    const struct IPowerEventListener *listener;
    struct HdfDeviceObject *deviceObject;
    struct HdfSRef wakeRef;
    HdfPsmState psmState;
    uint32_t mode;
};
struct PowerStateToken *PowerStateTokenNewInstance(
    struct HdfDeviceObject *deviceObject, const struct IPowerEventListener *listener);
void PowerStateTokenFreeInstance(struct PowerStateToken *stateToken);
int PowerStateChange(struct PowerStateToken *stateToken, uint32_t pEvent);
typedef enum {
    HDF_PM_REQUEST_ACQUIRE,
    HDF_PM_REQUEST_RELEASE,
} HDF_PM_REQUEST_TYPE;
struct HdfPmRequest {
    struct PowerStateToken *token;
    HDF_PM_REQUEST_TYPE pmType;
    struct HdfTaskType task;
};
struct PmTaskQueue *HdfPmTaskQueueInit(HdfTaskFunc func);
int32_t HdfPowerManagerInit(void);
void HdfPmTaskPut(struct PowerStateToken *powerToken, HDF_PM_REQUEST_TYPE type);
void HdfPowerManagerExit(void);
struct HdfServiceSubscriber {
    struct HdfSListNode entry;
    uint32_t state;
    uint32_t devId;
    struct SubscriberCallback callback;
};
enum {
    HDF_SUBSCRIBER_STATE_PENDING,
    HDF_SUBSCRIBER_STATE_READY
};
struct HdfServiceSubscriber *HdfServiceSubscriberObtain(struct SubscriberCallback callback, devid_t devid);
void HdfServiceSubscriberRecycle(struct HdfServiceSubscriber *subscriber);
void HdfServiceSubscriberDelete(struct HdfSListNode *listEntry);
struct HdfServiceObserverRecord {
    struct HdfSListNode entry;
    uint32_t serviceKey;
    uint16_t policy;
    devid_t devId;
    struct OsalMutex obsRecMutex;
    struct HdfSList subscribers;
    struct HdfObject *publisher;
};
struct HdfServiceObserverRecord *HdfServiceObserverRecordObtain(uint32_t serviceKey);
void HdfServiceObserverRecordRecycle(struct HdfServiceObserverRecord *observerRecord);
_Bool HdfServiceObserverRecordCompare(struct HdfSListNode *listEntry, uint32_t serviceKey);
void HdfServiceObserverRecordNotifySubscribers(
    struct HdfServiceObserverRecord *record, devid_t deviceId, uint16_t policy);
void HdfServiceObserverRecordDelete(struct HdfSListNode *listEntry);
typedef enum {
    HDF_CONFIG_SOURCE = 0,
    INVALID,
} DeviceResourceType;
struct DeviceResourceAttr {
    const char *name;
    const char *value;
    struct DeviceResourceAttr *next;
};
struct DeviceResourceNode {
    const char *name;
    uint32_t hashValue;
    struct DeviceResourceAttr *attrData;
    struct DeviceResourceNode *parent;
    struct DeviceResourceNode *child;
    struct DeviceResourceNode *sibling;
};
struct DeviceResourceIface {
    const struct DeviceResourceNode *(*GetRootNode)(void);
    _Bool (*GetBool)(const struct DeviceResourceNode *node, const char *attrName);
    int32_t (*GetUint8)(const struct DeviceResourceNode *node, const char *attrName, uint8_t *value, uint8_t def);
    int32_t (*GetUint8ArrayElem)(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
        uint8_t *value, uint8_t def);
    int32_t (*GetUint8Array)(const struct DeviceResourceNode *node, const char *attrName, uint8_t *value, uint32_t len,
        uint8_t def);
    int32_t (*GetUint16)(const struct DeviceResourceNode *node, const char *attrName, uint16_t *value, uint16_t def);
    int32_t (*GetUint16ArrayElem)(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
        uint16_t *value, uint16_t def);
    int32_t (*GetUint16Array)(const struct DeviceResourceNode *node, const char *attrName, uint16_t *value,
        uint32_t len, uint16_t def);
    int32_t (*GetUint32)(const struct DeviceResourceNode *node, const char *attrName, uint32_t *value, uint32_t def);
    int32_t (*GetUint32ArrayElem)(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
        uint32_t *value, uint32_t def);
    int32_t (*GetUint32Array)(const struct DeviceResourceNode *node, const char *attrName, uint32_t *value,
        uint32_t len, uint32_t def);
    int32_t (*GetUint64)(const struct DeviceResourceNode *node, const char *attrName, uint64_t *value, uint64_t def);
    int32_t (*GetUint64ArrayElem)(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
        uint64_t *value, uint64_t def);
    int32_t (*GetUint64Array)(const struct DeviceResourceNode *node, const char *attrName, uint64_t *value,
        uint32_t len, uint64_t def);
    int32_t (*GetString)(const struct DeviceResourceNode *node, const char *attrName, const char **value,
        const char *def);
    int32_t (*GetStringArrayElem)(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
        const char **value, const char *def);
    int32_t (*GetElemNum)(const struct DeviceResourceNode *node, const char *attrName);
    const struct DeviceResourceNode *(*GetNodeByMatchAttr)(const struct DeviceResourceNode *node,
        const char *attrValue);
    const struct DeviceResourceNode *(*GetChildNode)(const struct DeviceResourceNode *node, const char *nodeName);
    const struct DeviceResourceNode *(*GetNodeByRefAttr)(const struct DeviceResourceNode *node, const char *attrName);
};
struct DeviceResourceIface *DeviceResourceGetIfaceInstance(DeviceResourceType type);
const struct DeviceResourceNode *HcsGetRootNode(void);
_Bool HcsGetBool(const struct DeviceResourceNode *node, const char *attrName);
int32_t HcsGetUint8(const struct DeviceResourceNode *node, const char *attrName, uint8_t *value, uint8_t def);
int32_t HcsGetUint8ArrayElem(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
    uint8_t *value, uint8_t def);
int32_t HcsGetUint8Array(const struct DeviceResourceNode *node, const char *attrName, uint8_t *value, uint32_t len,
    uint8_t def);
int32_t HcsGetUint16(const struct DeviceResourceNode *node, const char *attrName, uint16_t *value, uint16_t def);
int32_t HcsGetUint16ArrayElem(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
    uint16_t *value, uint16_t def);
int32_t HcsGetUint16Array(const struct DeviceResourceNode *node, const char *attrName, uint16_t *value, uint32_t len,
    uint16_t def);
int32_t HcsGetUint32(const struct DeviceResourceNode *node, const char *attrName, uint32_t *value, uint32_t def);
int32_t HcsGetUint32ArrayElem(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
    uint32_t *value, uint32_t def);
int32_t HcsGetUint32Array(const struct DeviceResourceNode *node, const char *attrName, uint32_t *value,
    uint32_t len, uint32_t def);
int32_t HcsGetUint64(const struct DeviceResourceNode *node, const char *attrName, uint64_t *value, uint64_t def);
int32_t HcsGetUint64ArrayElem(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
    uint64_t *value, uint64_t def);
int32_t HcsGetUint64Array(const struct DeviceResourceNode *node, const char *attrName, uint64_t *value,
    uint32_t len, uint64_t def);
int32_t HcsGetStringArrayElem(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
    const char **value, const char *def);
int32_t HcsGetString(const struct DeviceResourceNode *node, const char *attrName, const char **value, const char *def);
int32_t HcsGetElemNum(const struct DeviceResourceNode *node, const char *attrName);
const struct DeviceResourceNode *HcsGetNodeByMatchAttr(const struct DeviceResourceNode *node, const char *attrValue);
const struct DeviceResourceNode *HcsGetChildNode(const struct DeviceResourceNode *node, const char *nodeName);
const struct DeviceResourceNode *HcsGetNodeByRefAttr(const struct DeviceResourceNode *node, const char *attrName);

struct MapNode;
typedef struct {
    struct MapNode **nodes;
    uint32_t nodeSize;
    uint32_t bucketSize;
} Map;
void MapInit(Map *map);
void MapDelete(Map *map);
int32_t MapSet(Map *map, const char *key, const void *value, uint32_t valueSize);
void *MapGet(const Map *map, const char *key);
int32_t MapErase(Map *map, const char *key);
struct DevHostServiceClnt {
    struct DListHead node;
    struct HdfSList devices;
    struct HdfSList unloadDevInfos;
    struct HdfSList dynamicDevInfos;
    Map *deviceHashMap;
    struct IDevHostService *hostService;
    struct OsalMutex hostLock;
    uint16_t devCount;
    uint16_t hostId;
    int hostPid;
    const char *hostName;
    _Bool stopFlag;
};
int DevHostServiceClntInstallDriver(struct DevHostServiceClnt *hostClnt);
struct DevHostServiceClnt *DevHostServiceClntNewInstance(uint16_t hostId, const char *hostName);
void DevHostServiceClntFreeInstance(struct DevHostServiceClnt *hostClnt);
void DevHostServiceClntDelete(struct DevHostServiceClnt *hostClnt);

const struct DeviceResourceNode *HdfGetHcsRootNode(void);
_Bool HdfAttributeManagerGetHostList(struct HdfSList *hostList);
int HdfAttributeManagerGetDeviceList(struct DevHostServiceClnt *hostClnt);
struct HdfCString {
    int size;
    char value[0];
};
uint32_t HdfStringMakeHashKey(const char *key, uint32_t mask);
struct HdfCString *HdfCStringObtain(const char *str);
void HdfCStringRecycle(struct HdfCString *inst);
char *HdfStringCopy(const char *src);

struct HdfVdiBase {
    uint32_t moduleVersion;
    const char *moduleName;
    int (*CreateVdiInstance)(struct HdfVdiBase *vdiBase);
    int (*DestoryVdiInstance)(struct HdfVdiBase *vdiBase);
};
struct HdfVdiObject {
    uintptr_t dlHandler;
    struct HdfVdiBase *vdiBase;
};
struct HdfVdiObject *HdfLoadVdi(const char *libName);
uint32_t HdfGetVdiVersion(const struct HdfVdiObject *vdiObj);
void HdfCloseVdi(struct HdfVdiObject *vdiObj);
int dlclose(void *);
char *dlerror(void);
void *dlopen(const char *, int);
void *dlsym(void *restrict, const char *restrict);
typedef struct {
 char name[255 + 1];
} Dl_namespace;
void *dlvsym(void *restrict, const char *restrict, const char *restrict);
void dlns_init(Dl_namespace *, const char *);
int dlns_get(const char *, Dl_namespace *);
void *dlopen_ns(Dl_namespace *, const char *, int);
int dlns_create(Dl_namespace *, const char *);
int dlns_create2(Dl_namespace *, const char *, int);
int dlns_inherit(Dl_namespace *, Dl_namespace *, const char *);
int dlns_set_namespace_lib_path(const char *name, const char *lib_path);
int dlns_set_namespace_separated(const char *name, const _Bool separated);
int dlns_set_namespace_permitted_paths(const char *name, const char *permitted_paths);
int dlns_set_namespace_allowed_libs(const char *name, const char *allowed_libs);
typedef struct {
 const char *dli_fname;
 void *dli_fbase;
 const char *dli_sname;
 void *dli_saddr;
} Dl_info;
int dladdr(const void *, Dl_info *);
int dlinfo(void *, int, void *);
enum {
    HDF_OBJECT_ID_DEVMGR_SERVICE = 0,
    HDF_OBJECT_ID_DEVSVC_MANAGER,
    HDF_OBJECT_ID_DEVHOST_SERVICE,
    HDF_OBJECT_ID_DRIVER_INSTALLER,
    HDF_OBJECT_ID_DRIVER_LOADER,
    HDF_OBJECT_ID_DEVICE,
    HDF_OBJECT_ID_DEVICE_TOKEN,
    HDF_OBJECT_ID_DEVICE_SERVICE,
    HDF_OBJECT_ID_REMOTE_SERVICE,
    HDF_OBJECT_ID_MAX
};
struct HdfObjectCreator {
    struct HdfObject *(*Create)(void);
    void (*Release)(struct HdfObject *);
};
const struct HdfObjectCreator *HdfObjectManagerGetCreators(int objectId);
struct HdfObject *HdfObjectManagerGetObject(int objectId);
void HdfObjectManagerFreeObject(struct HdfObject *object);

typedef enum {
    HILOG_MODULE_HIVIEW = 0,
    HILOG_MODULE_SAMGR,
    HILOG_MODULE_ACE,
    HILOG_MODULE_GRAPHIC,
    HILOG_MODULE_APP,
    HILOG_MODULE_MAX
} HiLogModuleType;
typedef enum {
    LOG_TYPE_MIN = 0,
    LOG_INIT = 1,
    LOG_CORE = 3,
    LOG_TYPE_MAX
} LogType;
typedef enum {
    LOG_DEBUG = 3,
    LOG_INFO = 4,
    LOG_WARN = 5,
    LOG_ERROR = 6,
    LOG_FATAL = 7,
} LogLevel;
int HiLogPrint(LogType type, LogLevel level, unsigned int domain, const char* tag, const char* fmt, ...)
    __attribute__((format(os_log, 5, 6)));

void *OsalMemAlloc(size_t size);
void *OsalMemCalloc(size_t size);
void *OsalMemAllocAlign(size_t alignment, size_t size);
void OsalMemFree(void *mem);
void HdfDeviceObjectConstruct(struct HdfDeviceObject *deviceObject);
struct HdfDeviceObject *HdfDeviceObjectAlloc(struct HdfDeviceObject *parent, const char *driverName);
void HdfDeviceObjectRelease(struct HdfDeviceObject *dev);
int HdfDeviceObjectRegister(struct HdfDeviceObject *dev);
int HdfDeviceObjectUnRegister(struct HdfDeviceObject *dev);
int HdfDeviceObjectPublishService(struct HdfDeviceObject *dev, const char *servName, uint8_t policy, uint32_t perm);
int HdfRemoveService(struct HdfDeviceObject *deviceObject);
int HdfDeviceObjectSetServInfo(struct HdfDeviceObject *dev, const char *info);
int HdfDeviceObjectUpdate(struct HdfDeviceObject *dev);
int HdfDeviceObjectSetInterfaceDesc(struct HdfDeviceObject *dev, const char *interfaceDesc);
_Bool HdfDeviceObjectCheckInterfaceDesc(struct HdfDeviceObject *dev, struct HdfSBuf *data);

