# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/src/hdf_observer_record.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 389 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/out/hispark_taurus/hispark_taurus_mini_system/config.h" 1
# 2 "<built-in>" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/src/hdf_observer_record.c" 2








# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/include/hdf_observer_record.h" 1
# 12 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/include/hdf_observer_record.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device.h" 1
# 12 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_dlist.h" 1
# 35 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_dlist.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h" 1
# 33 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/khdf/liteos/osal/include/hdf_types.h" 1
# 34 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/khdf/liteos/osal/include/hdf_types.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdbool.h" 1 3
# 35 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/khdf/liteos/osal/include/hdf_types.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stddef.h" 1 3
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stddef.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1 3
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef unsigned wchar_t;
# 59 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef struct { long long __ll; long double __ld; } max_align_t;
# 75 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef unsigned int size_t;
# 121 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef int ptrdiff_t;
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stddef.h" 2 3
# 36 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/khdf/liteos/osal/include/hdf_types.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdint.h" 1 3
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdint.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1 3
# 116 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef unsigned int uintptr_t;
# 131 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef int intptr_t;
# 147 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef signed char int8_t;




typedef signed short int16_t;




typedef signed int int32_t;




typedef signed long long int64_t;




typedef signed long long intmax_t;




typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef unsigned int uint32_t;




typedef unsigned long long uint64_t;
# 197 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdint.h" 2 3

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
# 95 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdint.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/stdint.h" 1 3
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 96 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdint.h" 2 3
# 37 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/khdf/liteos/osal/include/hdf_types.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/string.h" 1 3







# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/features.h" 1 3
# 9 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/string.h" 2 3
# 25 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/string.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1 3
# 345 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef struct __locale_struct *locale_t;
# 26 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/string.h" 2 3

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


# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/strings.h" 1 3
# 11 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/strings.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1 3
# 12 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/strings.h" 2 3




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
# 60 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/string.h" 2 3





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
# 38 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/khdf/liteos/osal/include/hdf_types.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/types.h" 1 3
# 54 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/types.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1 3
# 65 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef long long time_t;




typedef long long suseconds_t;
# 86 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
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

  cpu_set_t cpuset;

} pthread_attr_t;
# 126 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef int ssize_t;
# 141 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef int register_t;
# 192 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef unsigned long long u_int64_t;
# 203 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef unsigned mode_t;




typedef unsigned int nlink_t;




typedef long long off_t;
typedef long long loff_t;
typedef off_t off64_t;




typedef unsigned long long ino_t;




typedef unsigned long long dev_t;




typedef long blksize_t;




typedef long long blkcnt_t;




typedef unsigned long long fsblkcnt_t;




typedef unsigned long long fsfilcnt_t;
# 262 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef void * timer_t;




typedef int clockid_t;




typedef long clock_t;
# 294 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef int pid_t;




typedef unsigned id_t;




typedef unsigned uid_t;




typedef unsigned gid_t;




typedef int key_t;




typedef unsigned useconds_t;





typedef long pthread_t;




typedef int pthread_once_t;




typedef int pthread_key_t;




typedef int pthread_condattr_t;
# 55 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/types.h" 2 3


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
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/endian.h" 1 3
# 10 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/endian.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1 3
# 11 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/endian.h" 2 3
# 23 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/endian.h" 3
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
# 84 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/endian.h" 3
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
# 68 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/types.h" 2 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/select.h" 1 3
# 16 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/select.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1 3
# 277 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
struct timeval { time_t tv_sec; suseconds_t tv_usec; };

struct timeval64 { long long tv_sec; long long tv_usec; };





struct timespec { time_t tv_sec; long tv_nsec; };

struct timespec64 { long long tv_sec; long long tv_nsec; };
# 365 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef unsigned long long sigset_t;
# 17 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/select.h" 2 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 1 3
# 31 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1 3
# 32 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 2 3
# 48 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 3
typedef struct sigaltstack stack_t;



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/signal.h" 1 3
# 10 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/signal.h" 3
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
# 53 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 2 3
# 98 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 3
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
# 137 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 3
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
# 178 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 3
int pthread_sigmask(int, const sigset_t *, sigset_t *);
int sigfillset(sigset_t *);
int sigdelset(sigset_t *, int);



void (*sigset(int, void (*)(int)))(int);
# 204 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 3
typedef void (*sig_t)(int);






typedef void (*sighandler_t)(int);
void (*bsd_signal(int, void (*)(int)))(int);
# 222 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 3
typedef int sig_atomic_t;

void (*signal(int, void (*)(int)))(int);
int raise(int);
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/select.h" 2 3

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/fs/include/vfs_config.h" 1 3
# 36 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/fs/include/vfs_config.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/common/los_config.h" 1 3
# 39 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/common/los_config.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 1 3
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_err.h" 1 3
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_err.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h" 1 3
# 42 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_builddef.h" 1 3
# 43 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h" 2 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_toolchain.h" 1 3
# 44 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h" 2 3
# 55 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h" 3
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
# 83 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h" 3
typedef INT32 ssize_t;
typedef UINT32 size_t;


typedef UINTPTR AARCHPTR;
typedef size_t BOOL;
# 205 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h" 3
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
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_err.h" 2 3
# 70 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_err.h" 3
typedef void (*LOS_ERRORHANDLE_FUNC)(CHAR *fileName,
                                     UINT32 lineNo,
                                     UINT32 errorNo,
                                     UINT32 paraLen,
                                     void *para);
# 98 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_err.h" 3
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
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 2 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_errno.h" 1 3
# 42 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 2 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/arch/arm/arm/include/hal_timer.h" 1 3
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/arch/arm/arm/include/hal_timer.h" 3
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
# 43 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 2 3
# 86 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 3
extern UINT32 g_sysClock;





extern UINT32 g_tickPerSecond;
# 115 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 3
extern void LOS_GetCpuCycle(UINT32 *puwCntHi, UINT32 *puwCntLo);
# 134 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 3
extern UINT64 LOS_CurrNanosec(void);
# 153 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 3
extern void LOS_Udelay(UINT32 usecs);
# 172 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_tick.h" 3
extern void LOS_Mdelay(UINT32 usecs);
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/common/los_config.h" 2 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/base/include/los_vm_zone.h" 1 3
# 35 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/base/include/los_vm_zone.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/device/board/hisilicon/hispark_taurus/liteos_a/board/target_config.h" 1 3
# 36 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/base/include/los_vm_zone.h" 2 3
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/common/los_config.h" 2 3
# 52 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/common/los_config.h" 3
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
# 474 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/common/los_config.h" 3
extern UINT32 OsMain(void);

typedef void (*SystemRebootFunc)(void);
void OsSetRebootHook(SystemRebootFunc func);
SystemRebootFunc OsGetRebootHook(void);
# 37 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/fs/include/vfs_config.h" 2 3
# 104 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/fs/include/vfs_config.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/net/lwip-2.1/porting/include/lwip/lwipopts.h" 1 3
# 105 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/fs/include/vfs_config.h" 2 3
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/select.h" 2 3







typedef unsigned long fd_mask;

typedef struct {
 unsigned long fds_bits[((512 + 128) + (0 + 256)) / 8 / sizeof(long)];
} fd_set;






int select (int, fd_set *restrict, fd_set *restrict, fd_set *restrict, struct timeval *restrict);
int pselect (int, fd_set *restrict, fd_set *restrict, fd_set *restrict, const struct timespec *restrict, const sigset_t *restrict);
# 69 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/types.h" 2 3
# 39 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/khdf/liteos/osal/include/hdf_types.h" 2
# 34 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h" 2








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
# 36 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_dlist.h" 2








struct DListHead {
    struct DListHead *next;
    struct DListHead *prev;
};
# 56 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_dlist.h"
static inline void DListHeadInit(struct DListHead *head)
{
    head->next = head;
    head->prev = head;
}
# 69 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_dlist.h"
static inline _Bool DListIsEmpty(const struct DListHead *head)
{
    return (head->next == head) ? 1 : 0;
}
# 81 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_dlist.h"
static inline void DListRemove(struct DListHead *entry)
{
    entry->prev->next = entry->next;
    entry->next->prev = entry->prev;

    entry->prev = ((void*)0);
    entry->next = ((void*)0);
}
# 99 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_dlist.h"
static inline void DListInsertHead(struct DListHead *entry, struct DListHead *head)
{
    entry->next = head->next;
    entry->prev = head;

    head->next->prev = entry;
    head->next = entry;
}
# 117 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_dlist.h"
static inline void DListInsertTail(struct DListHead *entry, struct DListHead *head)
{
    entry->next = head;
    entry->prev = head->prev;

    head->prev->next = entry;
    head->prev = entry;
}
# 135 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_dlist.h"
static inline void DListMerge(struct DListHead *list, struct DListHead *head)
{
    list->next->prev = head;
    list->prev->next = head->next;

    head->next->prev = list->prev;
    head->next = list->next;

    DListHeadInit(list);
}
# 153 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_dlist.h"
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
# 13 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_object.h" 1
# 39 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_object.h"
struct HdfObject {
    int32_t objectId;
};
# 14 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device.h" 2
# 26 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device.h"
typedef uint32_t devid_t;
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device.h"
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
# 13 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/include/hdf_observer_record.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h" 1
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
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
# 45 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
void HdfSListInit(struct HdfSList *list);
# 57 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
struct HdfSListNode *HdfSListSearch(const struct HdfSList *list, uint32_t keyValue, HdfSListSearchComparer comparer);
# 66 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
_Bool HdfSListIsEmpty(const struct HdfSList *list);
# 75 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
struct HdfSListNode *HdfSListGetLast(const struct HdfSList *list);
# 85 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
void HdfSListAdd(struct HdfSList *list, struct HdfSListNode *link);
# 95 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
void HdfSListAddTail(struct HdfSList *list, struct HdfSListNode *link);
# 106 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
_Bool HdfSListAddOrder(struct HdfSList *list, struct HdfSListNode *link, HdfSListAddComparer comparer);
# 115 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
void HdfSListRemove(struct HdfSList *list, struct HdfSListNode *link);
# 125 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
void HdfSListFlush(struct HdfSList *list, HdfSListDeleter deleter);
# 134 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
int HdfSListCount(const struct HdfSList *list);
# 143 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
struct HdfSListNode *HdfSListPeek(const struct HdfSList *list);
# 152 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
struct HdfSListNode *HdfSListNext(const struct HdfSListNode *link);
# 161 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
struct HdfSListNode *HdfSListPop(struct HdfSList *list);
# 171 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
void HdfSListIteratorInit(struct HdfSListIterator *iterator, const struct HdfSList *list);
# 180 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
_Bool HdfSListIteratorHasNext(const struct HdfSListIterator *iterator);
# 189 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
struct HdfSListNode *HdfSListIteratorNext(struct HdfSListIterator *iterator);
# 198 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
void HdfSListIteratorRemove(struct HdfSListIterator *iterator);
# 208 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
void HdfSListIteratorInsert(struct HdfSListIterator *iterator, struct HdfSListNode *link);
# 15 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/include/hdf_observer_record.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/shared/osal_mutex.h" 1
# 46 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/shared/osal_mutex.h"
struct OsalMutex {
    void *realMutex;
};
# 70 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/shared/osal_mutex.h"
int32_t OsalMutexInit(struct OsalMutex *mutex);
# 87 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/shared/osal_mutex.h"
int32_t OsalMutexDestroy(struct OsalMutex *mutex);
# 104 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/shared/osal_mutex.h"
int32_t OsalMutexLock(struct OsalMutex *mutex);
# 123 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/shared/osal_mutex.h"
int32_t OsalMutexTimedLock(struct OsalMutex *mutex, uint32_t ms);
# 140 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/shared/osal_mutex.h"
int32_t OsalMutexUnlock(struct OsalMutex *mutex);
# 16 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/include/hdf_observer_record.h" 2

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
# 10 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/src/hdf_observer_record.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_log.h" 1
# 48 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_log.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/khdf/liteos/osal/include/hdf_log_adapter.h" 1
# 35 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/khdf/liteos/osal/include/hdf_log_adapter.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/kits/hilog/log.h" 1
# 63 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/kits/hilog/log.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdarg.h" 1 3
# 10 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdarg.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1 3
# 29 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef __builtin_va_list va_list;
# 11 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdarg.h" 2 3
# 64 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/kits/hilog/log.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdio.h" 1 3
# 26 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdio.h" 3
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1 3
# 34 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef __builtin_va_list __isoc_va_list;
# 355 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 27 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdio.h" 2 3
# 56 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdio.h" 3
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
# 65 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/kits/hilog/log.h" 2
# 78 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/kits/hilog/log.h"
typedef enum {

    HILOG_MODULE_HIVIEW = 0,

    HILOG_MODULE_SAMGR,

    HILOG_MODULE_ACE,

    HILOG_MODULE_GRAPHIC,

    HILOG_MODULE_APP,

    HILOG_MODULE_MAX
} HiLogModuleType;
# 128 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/kits/hilog/log.h"
typedef enum {
    LOG_TYPE_MIN = 0,

    LOG_INIT = 1,

    LOG_CORE = 3,
    LOG_TYPE_MAX
} LogType;
# 154 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/kits/hilog/log.h"
typedef enum {

    LOG_DEBUG = 3,

    LOG_INFO = 4,

    LOG_WARN = 5,

    LOG_ERROR = 6,

    LOG_FATAL = 7,
} LogLevel;
# 191 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog_lite/interfaces/native/kits/hilog/log.h"
int HiLogPrint(LogType type, LogLevel level, unsigned int domain, const char* tag, const char* fmt, ...)
    __attribute__((format(os_log, 5, 6)));
# 36 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/khdf/liteos/osal/include/hdf_log_adapter.h" 2
# 49 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_log.h" 2
# 11 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/src/hdf_observer_record.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/include/hdf_service_subscriber.h" 1
# 13 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/include/hdf_service_subscriber.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h" 1
# 32 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/common/include/host/hdf_device_section.h" 1
# 33 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h" 1
# 33 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_device_class.h" 1
# 35 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_device_class.h"
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
# 34 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h" 2


# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h" 1
# 38 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
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
# 67 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteBuffer(struct HdfSBuf *sbuf, const void *data, uint32_t writeSize);
# 79 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteUnpadBuffer(struct HdfSBuf *sbuf, const uint8_t *data, uint32_t writeSize);
# 90 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteUint64(struct HdfSBuf *sbuf, uint64_t value);
# 101 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteUint32(struct HdfSBuf *sbuf, uint32_t value);
# 112 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteUint16(struct HdfSBuf *sbuf, uint16_t value);
# 123 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteUint8(struct HdfSBuf *sbuf, uint8_t value);
# 134 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteInt64(struct HdfSBuf *sbuf, int64_t value);
# 145 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteInt32(struct HdfSBuf *sbuf, int32_t value);
# 156 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteInt16(struct HdfSBuf *sbuf, int16_t value);
# 167 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteInt8(struct HdfSBuf *sbuf, int8_t value);
# 178 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteString(struct HdfSBuf *sbuf, const char *value);
# 191 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteString16(struct HdfSBuf *sbuf, const char16_t *value, uint32_t size);
# 203 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteFloat(struct HdfSBuf *sbuf, float data);
# 215 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteDouble(struct HdfSBuf *sbuf, double data);
# 227 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufWriteFileDescriptor(struct HdfSBuf *sbuf, int fd);
# 238 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
int32_t HdfSbufWriteRemoteService(struct HdfSBuf *sbuf, const struct HdfRemoteService *service);
# 250 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
struct HdfRemoteService *HdfSbufReadRemoteService(struct HdfSBuf *sbuf);
# 261 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
int HdfSbufReadFileDescriptor(struct HdfSBuf *sbuf);
# 274 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufReadDouble(struct HdfSBuf *sbuf, double *data);
# 286 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufReadFloat(struct HdfSBuf *sbuf, float *data);
# 298 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
const char16_t *HdfSbufReadString16(struct HdfSBuf *sbuf);
# 312 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufReadBuffer(struct HdfSBuf *sbuf, const void **data, uint32_t *readSize);
# 323 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
const uint8_t *HdfSbufReadUnpadBuffer(struct HdfSBuf *sbuf, size_t length);
# 334 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufReadUint64(struct HdfSBuf *sbuf, uint64_t *value);
# 345 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufReadUint32(struct HdfSBuf *sbuf, uint32_t *value);
# 356 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufReadUint16(struct HdfSBuf *sbuf, uint16_t *value);
# 367 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufReadUint8(struct HdfSBuf *sbuf, uint8_t *value);
# 378 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufReadInt64(struct HdfSBuf *sbuf, int64_t *value);
# 389 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufReadInt32(struct HdfSBuf *sbuf, int32_t *value);
# 400 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufReadInt16(struct HdfSBuf *sbuf, int16_t *value);
# 411 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
_Bool HdfSbufReadInt8(struct HdfSBuf *sbuf, int8_t *value);
# 422 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
const char *HdfSbufReadString(struct HdfSBuf *sbuf);
# 433 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
uint8_t *HdfSbufGetData(const struct HdfSBuf *sbuf);
# 442 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
void HdfSbufFlush(struct HdfSBuf *sbuf);
# 452 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
size_t HdfSbufGetCapacity(const struct HdfSBuf *sbuf);
# 462 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
size_t HdfSbufGetDataSize(const struct HdfSBuf *sbuf);
# 472 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
void HdfSbufSetDataSize(struct HdfSBuf *sbuf, size_t size);
# 482 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
struct HdfSBuf *HdfSbufObtain(size_t capacity);
# 491 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
struct HdfSBuf *HdfSbufObtainDefaultSize(void);
# 504 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
struct HdfSBuf *HdfSbufBind(uintptr_t base, size_t size);
# 513 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
void HdfSbufRecycle(struct HdfSBuf *sbuf);
# 524 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
struct HdfSBuf *HdfSbufMove(struct HdfSBuf *sbuf);
# 535 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
struct HdfSBuf *HdfSbufCopy(const struct HdfSBuf *sbuf);
# 545 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
void HdfSbufTransDataOwnership(struct HdfSBuf *sbuf);
# 555 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
struct HdfSBuf *HdfSbufTypedObtain(uint32_t type);
# 566 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
struct HdfSBuf *HdfSbufTypedObtainInplace(uint32_t type, struct HdfSBufImpl *impl);
# 577 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
struct HdfSBuf *HdfSbufTypedObtainCapacity(uint32_t type, size_t capacity);
# 591 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
struct HdfSBuf *HdfSbufTypedBind(uint32_t type, uintptr_t base, size_t size);
# 601 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_sbuf.h"
struct HdfSBufImpl *HdfSbufGetImpl(struct HdfSBuf *sbuf);
# 37 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h" 2





struct HdfDevEventlistener;
struct HdfIoService;
# 57 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
typedef int (*OnEventReceived)(void *priv, uint32_t id, struct HdfSBuf *data);
# 72 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
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
# 137 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
struct HdfIoServiceGroup *HdfIoServiceGroupObtain(void);
# 146 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
void HdfIoServiceGroupRecycle(struct HdfIoServiceGroup *group);
# 158 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
int32_t HdfIoServiceGroupAddService(struct HdfIoServiceGroup *group, struct HdfIoService *service);
# 170 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
void HdfIoServiceGroupRemoveService(struct HdfIoServiceGroup *group, struct HdfIoService *service);
# 183 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
int32_t HdfIoServiceGroupRegisterListener(struct HdfIoServiceGroup *group, struct HdfDevEventlistener *listener);
# 197 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
int32_t HdfIoServiceGroupRegisterListenerWithSchedPolicy(
    struct HdfIoServiceGroup *group, struct HdfDevEventlistener *listener, int policy);
# 210 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
int32_t HdfIoServiceGroupUnregisterListener(struct HdfIoServiceGroup *group, struct HdfDevEventlistener *listener);
# 223 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
struct HdfIoService *HdfIoServiceBind(const char *serviceName);
# 232 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
void HdfIoServiceRecycle(struct HdfIoService *service);
# 245 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
int HdfDeviceRegisterEventListener(struct HdfIoService *target, struct HdfDevEventlistener *listener);
# 259 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
int32_t HdfDeviceRegisterEventListenerWithSchedPolicy(
    struct HdfIoService *target, struct HdfDevEventlistener *listener, int policy);
# 272 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
int HdfDeviceUnregisterEventListener(struct HdfIoService *target, struct HdfDevEventlistener *listener);
# 282 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
int HdfIoserviceGetListenerCount(const struct HdfIoService *service);
# 292 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
int HdfIoserviceGroupGetListenerCount(const struct HdfIoServiceGroup *group);
# 302 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
int HdfIoserviceGroupGetServiceCount(const struct HdfIoServiceGroup *group);
# 315 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/core/hdf_io_service_if.h"
int32_t HdfGetServiceNameByDeviceClass(DeviceClass deviceClass, struct HdfSBuf *reply);


int32_t HdfIoServiceDispatch(struct HdfIoService *ioService, int cmdId, struct HdfSBuf *data, struct HdfSBuf *reply);
# 34 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h" 2
# 56 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
typedef enum {

    SERVICE_POLICY_NONE = 0,

    SERVICE_POLICY_PUBLIC,

    SERVICE_POLICY_CAPACITY,

    SERVICE_POLICY_FRIENDLY,


    SERVICE_POLICY_PRIVATE,

    SERVICE_POLICY_INVALID
} ServicePolicy;
# 80 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
typedef enum {
    DEVICE_PRELOAD_ENABLE = 0,
    DEVICE_PRELOAD_ENABLE_STEP2,
    DEVICE_PRELOAD_DISABLE,
    DEVICE_PRELOAD_INVALID
} DevicePreload;
# 95 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
struct HdfDeviceObject {

    struct IDeviceIoService *service;





    const struct DeviceResourceNode *property;

    DeviceClass deviceClass;

    void *priv;





};
# 122 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
struct HdfDeviceIoClient {

    struct HdfDeviceObject *device;

    void *priv;
};
# 137 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
struct IDeviceIoService {

    struct HdfObject object;
# 148 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
    int32_t (*Open)(struct HdfDeviceIoClient *client);
# 160 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
    int32_t (*Dispatch)(struct HdfDeviceIoClient *client, int cmdId, struct HdfSBuf *data, struct HdfSBuf *reply);







    void (*Release)(struct HdfDeviceIoClient *client);
};
# 179 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
struct SubscriberCallback {

    struct HdfDeviceObject *deviceObject;
# 192 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
    int32_t (*OnServiceConnected)(struct HdfDeviceObject *deviceObject, const struct HdfObject *service);
};
# 202 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
struct HdfDriverEntry {

    int32_t moduleVersion;

    const char *moduleName;
# 218 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
    int32_t (*Bind)(struct HdfDeviceObject *deviceObject);
# 228 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
    int32_t (*Init)(struct HdfDeviceObject *deviceObject);
# 239 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
    void (*Release)(struct HdfDeviceObject *deviceObject);
};
# 262 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
const struct HdfObject *DevSvcManagerClntGetService(const char *svcName);
# 274 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
const char *HdfDeviceGetServiceName(const struct HdfDeviceObject *deviceObject);
# 290 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
int32_t HdfDeviceSubscribeService(
    struct HdfDeviceObject *deviceObject, const char *serviceName, struct SubscriberCallback callback);
# 306 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
int32_t HdfDeviceSendEvent(const struct HdfDeviceObject *deviceObject, uint32_t id, const struct HdfSBuf *data);
# 321 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
int32_t HdfDeviceSendEventToClient(const struct HdfDeviceIoClient *client, uint32_t id, const struct HdfSBuf *data);
# 335 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
_Bool HdfDeviceSetClass(struct HdfDeviceObject *deviceObject, DeviceClass deviceClass);
# 14 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/include/hdf_service_subscriber.h" 2


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
# 12 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/src/hdf_observer_record.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/shared/osal_mem.h" 1
# 49 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/shared/osal_mem.h"
void *OsalMemAlloc(size_t size);
# 60 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/shared/osal_mem.h"
void *OsalMemCalloc(size_t size);
# 72 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/shared/osal_mem.h"
void *OsalMemAllocAlign(size_t alignment, size_t size);
# 81 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/shared/osal_mem.h"
void OsalMemFree(void *mem);
# 13 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/host/src/hdf_observer_record.c" 2




struct HdfServiceObserverRecord *HdfServiceObserverRecordObtain(uint32_t serviceKey)
{
    struct HdfServiceObserverRecord *observerRecord =
        (struct HdfServiceObserverRecord *)OsalMemCalloc(sizeof(struct HdfServiceObserverRecord));
    if (observerRecord != ((void*)0)) {
        observerRecord->serviceKey = serviceKey;
        observerRecord->publisher = ((void*)0);
        if (OsalMutexInit(&observerRecord->obsRecMutex) != HDF_SUCCESS) {
            OsalMemFree(observerRecord);
            return ((void*)0);
        }
        HdfSListInit(&observerRecord->subscribers);
    }
    return observerRecord;
}

void HdfServiceObserverRecordRecycle(struct HdfServiceObserverRecord *observerRecord)
{
    if (observerRecord != ((void*)0)) {
        HdfSListFlush(&observerRecord->subscribers, HdfServiceSubscriberDelete);
        OsalMutexDestroy(&observerRecord->obsRecMutex);
        observerRecord->obsRecMutex.realMutex = ((void*)0);
        OsalMemFree(observerRecord);
    }
}

_Bool HdfServiceObserverRecordCompare(struct HdfSListNode *listEntry, uint32_t serviceKey)
{
    struct HdfServiceObserverRecord *record = ((void*)0);
    if (listEntry == ((void*)0)) {
        return 0;
    }
    record = (struct HdfServiceObserverRecord *)listEntry;
    if (record->serviceKey == serviceKey) {
        return 1;
    }
    return 0;
}

void HdfServiceObserverRecordNotifySubscribers(
    struct HdfServiceObserverRecord *record, devid_t deviceId, uint16_t policy)
{
    struct HdfSListIterator it;
    if (record == ((void*)0)) {
        ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD002510, "observer_record", "%{public}s: record is null", __func__));
        return;
    }

    OsalMutexLock(&record->obsRecMutex);
    HdfSListIteratorInit(&it, &record->subscribers);
    while (HdfSListIteratorHasNext(&it)) {
        struct HdfServiceSubscriber *subscriber =
            (struct HdfServiceSubscriber *)HdfSListIteratorNext(&it);
        if (deviceId == subscriber->devId || policy != SERVICE_POLICY_PRIVATE) {
            subscriber->state = HDF_SUBSCRIBER_STATE_READY;
            if (subscriber->callback.OnServiceConnected != ((void*)0)) {
                subscriber->callback.OnServiceConnected(subscriber->callback.deviceObject, record->publisher);
            }
        }
    }
    OsalMutexUnlock(&record->obsRecMutex);
}

void HdfServiceObserverRecordDelete(struct HdfSListNode *listEntry)
{
    struct HdfServiceObserverRecord *observerRecord = (struct HdfServiceObserverRecord *)listEntry;
    if (observerRecord != ((void*)0)) {
        HdfServiceObserverRecordRecycle(observerRecord);
    }
}
