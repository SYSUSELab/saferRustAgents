# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/mbedtls_pkcs7.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 389 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/mbedtls_pkcs7.c" 2
# 16 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/mbedtls_pkcs7.c"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h" 1
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdbool.h" 1
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h" 2
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
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h" 1
# 12 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/private_access.h" 1
# 13 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/build_info.h" 1
# 108 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/build_info.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/../port/config/config_liteos_a.h" 1
# 43 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/../port/config/config_liteos_a.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdlib.h" 1







# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/features.h" 1
# 9 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdlib.h" 2
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdlib.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned wchar_t;
# 75 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned int size_t;
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
# 126 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef int ssize_t;
# 213 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef long long off_t;
typedef long long loff_t;
typedef off_t off64_t;
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
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/check_config.h"
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
# 59 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef struct { long long __ll; long double __ld; } max_align_t;
# 121 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef int ptrdiff_t;
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stddef.h" 2
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h" 2


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
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/check_config.h" 2
# 1124 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/check_config.h"
typedef int mbedtls_iso_c_forbids_empty_translation_units;
# 179 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/build_info.h" 2
# 15 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform_util.h" 1
# 170 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform_util.h"
void mbedtls_platform_zeroize(void *buf, size_t len);
# 16 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h" 2




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
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h" 2
# 141 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
typedef struct mbedtls_asn1_buf {
    int tag;
    size_t len;
    unsigned char *p;
}
mbedtls_asn1_buf;




typedef struct mbedtls_asn1_bitstring {
    size_t len;
    unsigned char unused_bits;
    unsigned char *p;
}
mbedtls_asn1_bitstring;




typedef struct mbedtls_asn1_sequence {
    mbedtls_asn1_buf buf;
# 171 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
    struct mbedtls_asn1_sequence *next;
}
mbedtls_asn1_sequence;




typedef struct mbedtls_asn1_named_data {
    mbedtls_asn1_buf oid;
    mbedtls_asn1_buf val;
# 189 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
    struct mbedtls_asn1_named_data *next;






    unsigned char private_next_merged;
}
mbedtls_asn1_named_data;
# 220 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
int mbedtls_asn1_get_len(unsigned char **p,
                         const unsigned char *end,
                         size_t *len);
# 245 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
int mbedtls_asn1_get_tag(unsigned char **p,
                         const unsigned char *end,
                         size_t *len, int tag);
# 266 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
int mbedtls_asn1_get_bool(unsigned char **p,
                          const unsigned char *end,
                          int *val);
# 287 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
int mbedtls_asn1_get_int(unsigned char **p,
                         const unsigned char *end,
                         int *val);
# 308 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
int mbedtls_asn1_get_enum(unsigned char **p,
                          const unsigned char *end,
                          int *val);
# 329 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
int mbedtls_asn1_get_bitstring(unsigned char **p, const unsigned char *end,
                               mbedtls_asn1_bitstring *bs);
# 350 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
int mbedtls_asn1_get_bitstring_null(unsigned char **p,
                                    const unsigned char *end,
                                    size_t *len);
# 401 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
int mbedtls_asn1_get_sequence_of(unsigned char **p,
                                 const unsigned char *end,
                                 mbedtls_asn1_sequence *cur,
                                 int tag);
# 426 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
void mbedtls_asn1_sequence_free(mbedtls_asn1_sequence *seq);
# 513 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
int mbedtls_asn1_traverse_sequence_of(
    unsigned char **p,
    const unsigned char *end,
    unsigned char tag_must_mask, unsigned char tag_must_val,
    unsigned char tag_may_mask, unsigned char tag_may_val,
    int (*cb)(void *ctx, int tag,
              unsigned char *start, size_t len),
    void *ctx);
# 541 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
int mbedtls_asn1_get_mpi(unsigned char **p,
                         const unsigned char *end,
                         mbedtls_mpi *X);
# 562 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
int mbedtls_asn1_get_alg(unsigned char **p,
                         const unsigned char *end,
                         mbedtls_asn1_buf *alg, mbedtls_asn1_buf *params);
# 581 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
int mbedtls_asn1_get_alg_null(unsigned char **p,
                              const unsigned char *end,
                              mbedtls_asn1_buf *alg);
# 595 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
const mbedtls_asn1_named_data *mbedtls_asn1_find_named_data(const mbedtls_asn1_named_data *list,
                                                            const char *oid, size_t len);
# 611 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
void mbedtls_asn1_free_named_data(mbedtls_asn1_named_data *entry);
# 622 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
void mbedtls_asn1_free_named_data_list(mbedtls_asn1_named_data **head);
# 631 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/asn1.h"
void mbedtls_asn1_free_named_data_list_shallow(mbedtls_asn1_named_data *name);
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h" 1
# 17 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h" 1
# 17 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pk.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/md.h" 1
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
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h" 2
# 216 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h"
typedef mbedtls_asn1_buf mbedtls_x509_buf;




typedef mbedtls_asn1_bitstring mbedtls_x509_bitstring;





typedef mbedtls_asn1_named_data mbedtls_x509_name;




typedef mbedtls_asn1_sequence mbedtls_x509_sequence;




typedef struct mbedtls_x509_authority {
    mbedtls_x509_buf keyIdentifier;
    mbedtls_x509_sequence authorityCertIssuer;
    mbedtls_x509_buf authorityCertSerialNumber;
    mbedtls_x509_buf raw;
}
mbedtls_x509_authority;


typedef struct mbedtls_x509_time {
    int year, mon, day;
    int hour, min, sec;
}
mbedtls_x509_time;
# 261 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h"
typedef struct mbedtls_x509_san_other_name {





    mbedtls_x509_buf type_id;
    union {






        struct {
            mbedtls_x509_buf oid;
            mbedtls_x509_buf val;
        }
        hardware_module_name;
    }
    value;
}
mbedtls_x509_san_other_name;
# 292 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h"
typedef struct mbedtls_x509_subject_alternative_name {
    int type;
    union {
        mbedtls_x509_san_other_name other_name;
        mbedtls_x509_name directory_name;
        mbedtls_x509_buf unstructured_name;
    }
    san;
}
mbedtls_x509_subject_alternative_name;

typedef struct mbedtls_x509_san_list {
    mbedtls_x509_subject_alternative_name node;
    struct mbedtls_x509_san_list *next;
}
mbedtls_x509_san_list;
# 323 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h"
int mbedtls_x509_dn_gets(char *buf, size_t size, const mbedtls_x509_name *dn);
# 340 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h"
int mbedtls_x509_string_to_names(mbedtls_asn1_named_data **head, const char *name);
# 353 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h"
static inline mbedtls_x509_name *mbedtls_x509_dn_get_next(
    mbedtls_x509_name *dn)
{
    while (dn->private_next_merged && dn->next != ((void*)0)) {
        dn = dn->next;
    }
    return dn->next;
}
# 373 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h"
int mbedtls_x509_serial_gets(char *buf, size_t size, const mbedtls_x509_buf *serial);
# 385 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h"
int mbedtls_x509_time_cmp(const mbedtls_x509_time *t1, const mbedtls_x509_time *t2);
# 412 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h"
int mbedtls_x509_time_is_past(const mbedtls_x509_time *to);
# 426 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h"
int mbedtls_x509_time_is_future(const mbedtls_x509_time *from);
# 460 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h"
int mbedtls_x509_parse_subject_alt_name(const mbedtls_x509_buf *san_buf,
                                        mbedtls_x509_subject_alternative_name *san);





void mbedtls_x509_free_subject_alt_name(mbedtls_x509_subject_alternative_name *san);
# 484 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509.h"
size_t mbedtls_x509_crt_parse_cn_inet_pton(const char *cn, void *dst);
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h" 1
# 17 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crl.h" 1
# 51 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crl.h"
typedef struct mbedtls_x509_crl_entry {

    mbedtls_x509_buf raw;

    mbedtls_x509_buf serial;

    mbedtls_x509_time revocation_date;





    mbedtls_x509_buf entry_ext;




    struct mbedtls_x509_crl_entry *next;
}
mbedtls_x509_crl_entry;





typedef struct mbedtls_x509_crl {
    mbedtls_x509_buf raw;
    mbedtls_x509_buf tbs;

    int version;
    mbedtls_x509_buf sig_oid;

    mbedtls_x509_buf issuer_raw;

    mbedtls_x509_name issuer;

    mbedtls_x509_time this_update;
    mbedtls_x509_time next_update;

    mbedtls_x509_crl_entry entry;

    mbedtls_x509_buf crl_ext;

    mbedtls_x509_buf private_sig_oid2;
    mbedtls_x509_buf private_sig;
    mbedtls_md_type_t private_sig_md;
    mbedtls_pk_type_t private_sig_pk;
    void *private_sig_opts;




    struct mbedtls_x509_crl *next;
}
mbedtls_x509_crl;
# 121 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crl.h"
int mbedtls_x509_crl_parse_der(mbedtls_x509_crl *chain,
                               const unsigned char *buf, size_t buflen);
# 139 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crl.h"
int mbedtls_x509_crl_parse(mbedtls_x509_crl *chain, const unsigned char *buf, size_t buflen);
# 156 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crl.h"
int mbedtls_x509_crl_parse_file(mbedtls_x509_crl *chain, const char *path);
# 171 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crl.h"
int mbedtls_x509_crl_info(char *buf, size_t size, const char *prefix,
                          const mbedtls_x509_crl *crl);







void mbedtls_x509_crl_init(mbedtls_x509_crl *crl);






void mbedtls_x509_crl_free(mbedtls_x509_crl *crl);
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h" 2
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
typedef struct mbedtls_x509_crt {
    int private_own_buffer;

    mbedtls_x509_buf raw;
    mbedtls_x509_buf tbs;

    int version;
    mbedtls_x509_buf serial;
    mbedtls_x509_buf sig_oid;

    mbedtls_x509_buf issuer_raw;
    mbedtls_x509_buf subject_raw;

    mbedtls_x509_name issuer;
    mbedtls_x509_name subject;

    mbedtls_x509_time valid_from;
    mbedtls_x509_time valid_to;

    mbedtls_x509_buf pk_raw;
    mbedtls_pk_context pk;

    mbedtls_x509_buf issuer_id;
    mbedtls_x509_buf subject_id;
    mbedtls_x509_buf v3_ext;
    mbedtls_x509_sequence subject_alt_names;
    mbedtls_x509_buf subject_key_id;
    mbedtls_x509_authority authority_key_id;

    mbedtls_x509_sequence certificate_policies;

    int private_ext_types;
    int private_ca_istrue;
    int private_max_pathlen;

    unsigned int private_key_usage;

    mbedtls_x509_sequence ext_key_usage;

    unsigned char private_ns_cert_type;

    mbedtls_x509_buf private_sig;
    mbedtls_md_type_t private_sig_md;
    mbedtls_pk_type_t private_sig_pk;
    void *private_sig_opts;




    struct mbedtls_x509_crt *next;
}
mbedtls_x509_crt;
# 125 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
typedef struct mbedtls_x509_crt_profile {
    uint32_t allowed_mds;
    uint32_t allowed_pks;


    uint32_t allowed_curves;
    uint32_t rsa_min_bitlen;
}
mbedtls_x509_crt_profile;
# 217 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
typedef struct mbedtls_x509write_cert {
    int private_version;
    unsigned char private_serial[20];
    size_t private_serial_len;
    mbedtls_pk_context *private_subject_key;
    mbedtls_pk_context *private_issuer_key;
    mbedtls_asn1_named_data *private_subject;
    mbedtls_asn1_named_data *private_issuer;
    mbedtls_md_type_t private_md_alg;
    char private_not_before[15 + 1];
    char private_not_after[15 + 1];
    mbedtls_asn1_named_data *private_extensions;
}
mbedtls_x509write_cert;
# 244 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509write_crt_set_subject_alternative_name(mbedtls_x509write_cert *ctx,
                                                       const mbedtls_x509_san_list *san_list);




typedef struct {
    mbedtls_x509_crt *private_crt;
    uint32_t private_flags;
} mbedtls_x509_crt_verify_chain_item;
# 263 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
typedef struct {
    mbedtls_x509_crt_verify_chain_item private_items[(8 + 2)];
    unsigned private_len;
# 274 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
} mbedtls_x509_crt_verify_chain;






typedef struct {

    mbedtls_pk_restart_ctx private_pk;


    mbedtls_x509_crt *private_parent;
    mbedtls_x509_crt *private_fallback_parent;
    int private_fallback_signature_is_good;


    int private_parent_is_trusted;


    enum {
        x509_crt_rs_none,
        x509_crt_rs_find_parent,
    } private_in_progress;
    int private_self_cnt;
    mbedtls_x509_crt_verify_chain private_ver_chain;

} mbedtls_x509_crt_restart_ctx;
# 324 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
extern const mbedtls_x509_crt_profile mbedtls_x509_crt_profile_default;






extern const mbedtls_x509_crt_profile mbedtls_x509_crt_profile_next;




extern const mbedtls_x509_crt_profile mbedtls_x509_crt_profile_suiteb;





extern const mbedtls_x509_crt_profile mbedtls_x509_crt_profile_none;
# 368 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_parse_der(mbedtls_x509_crt *chain,
                               const unsigned char *buf,
                               size_t buflen);
# 402 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
typedef int (*mbedtls_x509_crt_ext_cb_t)(void *p_ctx,
                                         mbedtls_x509_crt const *crt,
                                         mbedtls_x509_buf const *oid,
                                         int critical,
                                         const unsigned char *p,
                                         const unsigned char *end);
# 453 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_parse_der_with_ext_cb(mbedtls_x509_crt *chain,
                                           const unsigned char *buf,
                                           size_t buflen,
                                           int make_copy,
                                           mbedtls_x509_crt_ext_cb_t cb,
                                           void *p_ctx);
# 491 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_parse_der_nocopy(mbedtls_x509_crt *chain,
                                      const unsigned char *buf,
                                      size_t buflen);
# 529 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_parse(mbedtls_x509_crt *chain, const unsigned char *buf, size_t buflen);
# 549 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_parse_file(mbedtls_x509_crt *chain, const char *path);
# 564 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_parse_path(mbedtls_x509_crt *chain, const char *path);
# 581 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_info(char *buf, size_t size, const char *prefix,
                          const mbedtls_x509_crt *crt);
# 596 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_verify_info(char *buf, size_t size, const char *prefix,
                                 uint32_t flags);
# 670 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_verify(mbedtls_x509_crt *crt,
                            mbedtls_x509_crt *trust_ca,
                            mbedtls_x509_crl *ca_crl,
                            const char *cn, uint32_t *flags,
                            int (*f_vrfy)(void *, mbedtls_x509_crt *, int, uint32_t *),
                            void *p_vrfy);
# 711 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_verify_with_profile(mbedtls_x509_crt *crt,
                                         mbedtls_x509_crt *trust_ca,
                                         mbedtls_x509_crl *ca_crl,
                                         const mbedtls_x509_crt_profile *profile,
                                         const char *cn, uint32_t *flags,
                                         int (*f_vrfy)(void *, mbedtls_x509_crt *, int, uint32_t *),
                                         void *p_vrfy);
# 745 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_verify_restartable(mbedtls_x509_crt *crt,
                                        mbedtls_x509_crt *trust_ca,
                                        mbedtls_x509_crl *ca_crl,
                                        const mbedtls_x509_crt_profile *profile,
                                        const char *cn, uint32_t *flags,
                                        int (*f_vrfy)(void *, mbedtls_x509_crt *, int, uint32_t *),
                                        void *p_vrfy,
                                        mbedtls_x509_crt_restart_ctx *rs_ctx);
# 784 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
typedef int (*mbedtls_x509_crt_ca_cb_t)(void *p_ctx,
                                        mbedtls_x509_crt const *child,
                                        mbedtls_x509_crt **candidate_cas);
# 842 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_check_key_usage(const mbedtls_x509_crt *crt,
                                     unsigned int usage);
# 858 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_check_extended_key_usage(const mbedtls_x509_crt *crt,
                                              const char *usage_oid,
                                              size_t usage_len);
# 872 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_is_revoked(const mbedtls_x509_crt *crt, const mbedtls_x509_crl *crl);







void mbedtls_x509_crt_init(mbedtls_x509_crt *crt);






void mbedtls_x509_crt_free(mbedtls_x509_crt *crt);





void mbedtls_x509_crt_restart_init(mbedtls_x509_crt_restart_ctx *ctx);




void mbedtls_x509_crt_restart_free(mbedtls_x509_crt_restart_ctx *ctx);
# 913 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
static inline int mbedtls_x509_crt_has_ext_type(const mbedtls_x509_crt *ctx,
                                                int ext_type)
{
    return ctx->private_ext_types & ext_type;
}
# 929 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/x509_crt.h"
int mbedtls_x509_crt_get_ca_istrue(const mbedtls_x509_crt *crt);
# 23 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pem.h" 1
# 64 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pem.h"
typedef struct mbedtls_pem_context {
    unsigned char *private_buf;
    size_t private_buflen;
    unsigned char *private_info;
}
mbedtls_pem_context;






void mbedtls_pem_init(mbedtls_pem_context *ctx);
# 104 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pem.h"
int mbedtls_pem_read_buffer(mbedtls_pem_context *ctx, const char *header, const char *footer,
                            const unsigned char *data,
                            const unsigned char *pwd,
                            size_t pwdlen, size_t *use_len);
# 121 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pem.h"
static inline const unsigned char *mbedtls_pem_get_buffer(mbedtls_pem_context *ctx, size_t *buflen)
{
    *buflen = ctx->private_buflen;
    return ctx->private_buf;
}







void mbedtls_pem_free(mbedtls_pem_context *ctx);
# 163 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/pem.h"
int mbedtls_pem_write_buffer(const char *header, const char *footer,
                             const unsigned char *der_data, size_t der_len,
                             unsigned char *buf, size_t buf_len, size_t *olen);
# 25 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h" 1
# 476 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
typedef struct mbedtls_oid_descriptor_t {
    const char *private_asn1;
    size_t private_asn1_len;

    const char *private_name;
    const char *private_description;

} mbedtls_oid_descriptor_t;
# 496 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_numeric_string(char *buf, size_t size, const mbedtls_asn1_buf *oid);
# 515 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_from_numeric_string(mbedtls_asn1_buf *oid, const char *oid_str, size_t size);
# 525 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_x509_ext_type(const mbedtls_asn1_buf *oid, int *ext_type);
# 536 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_attr_short_name(const mbedtls_asn1_buf *oid, const char **short_name);
# 546 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_pk_alg(const mbedtls_asn1_buf *oid, mbedtls_pk_type_t *pk_alg);
# 557 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_oid_by_pk_alg(mbedtls_pk_type_t pk_alg,
                                  const char **oid, size_t *olen);
# 569 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_ec_grp(const mbedtls_asn1_buf *oid, mbedtls_ecp_group_id *grp_id);
# 580 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_oid_by_ec_grp(mbedtls_ecp_group_id grp_id,
                                  const char **oid, size_t *olen);
# 592 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_ec_grp_algid(const mbedtls_asn1_buf *oid, mbedtls_ecp_group_id *grp_id);
# 604 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_oid_by_ec_grp_algid(mbedtls_ecp_group_id grp_id,
                                        const char **oid, size_t *olen);
# 617 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_sig_alg(const mbedtls_asn1_buf *oid,
                            mbedtls_md_type_t *md_alg, mbedtls_pk_type_t *pk_alg);
# 628 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_sig_alg_desc(const mbedtls_asn1_buf *oid, const char **desc);
# 640 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_oid_by_sig_alg(mbedtls_pk_type_t pk_alg, mbedtls_md_type_t md_alg,
                                   const char **oid, size_t *olen);
# 651 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_md_hmac(const mbedtls_asn1_buf *oid, mbedtls_md_type_t *md_hmac);
# 661 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_md_alg(const mbedtls_asn1_buf *oid, mbedtls_md_type_t *md_alg);
# 672 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_extended_key_usage(const mbedtls_asn1_buf *oid, const char **desc);
# 683 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_certificate_policies(const mbedtls_asn1_buf *oid, const char **desc);
# 694 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_oid_by_md(mbedtls_md_type_t md_alg, const char **oid, size_t *olen);
# 705 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/oid.h"
int mbedtls_oid_get_cipher_alg(const mbedtls_asn1_buf *oid, mbedtls_cipher_type_t *cipher_alg);
# 26 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h" 2
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h"
typedef enum {
    PKCS7_SUCC = 0,
    PKCS7_PARSING_ERROR,
    PKCS7_INVALID_PARAM,
    PKCS7_INVALID_VALUE,
    PKCS7_INVALID_CONTENT_TYPE_OR_NO_CONTENT,
    PKCS7_CERTIFICATE_NOT_FOUND,
    PKCS7_INVALID_VERSION,
    PKCS7_INVALID_DIGEST_ALG,
    PKCS7_INVALID_SIGNING_ALG,
    PKCS7_MEMORY_EXHAUST,
    PKCS7_ROOT_CA_NOT_VALID,
    PKCS7_BUILD_CERT_PATH_FAIL,
    PKCS7_HAS_NO_AUTH_ATTR_IN_SIGNER,
    PKCS7_HAS_NO_SIGNER_INFO,
    PKCS7_HAS_NO_SIGNER_CRT,
    PKCS7_IS_REVOKED,
    PKCS7_VERIFY_FAIL,
} PKCS7_RetCode;

typedef struct {
    char issuer[512];
    char subject[512];
    int32_t depth;
} SignerResovledInfo;

typedef struct {
    SignerResovledInfo *signers;
    int32_t nrOfSigners;
} SignersResovedInfo;
# 79 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h"
typedef struct {
    int32_t depth;
    mbedtls_x509_crt *crt;
} SignerCertPath;







typedef struct tagSignerInfo {
    int32_t version;
    mbedtls_x509_buf serial;
    mbedtls_x509_name issuer;
    mbedtls_x509_crt *rootCert;
    mbedtls_x509_buf issuerRaw;
    mbedtls_x509_buf digestAlgId;
    mbedtls_x509_buf authAttr;
    mbedtls_x509_buf authAttrRaw;
    mbedtls_x509_buf digestEncAlgId;
    mbedtls_x509_buf signature;
    mbedtls_x509_buf unAuthAttr;
    SignerCertPath certPath;
    struct tagSignerInfo *next;
} SignerInfo;




typedef struct tagContent {
    mbedtls_asn1_buf oid;
    mbedtls_asn1_buf data;
} Content;




typedef struct tagDigestAlgId {
    mbedtls_asn1_buf algBuf;
    struct tagDigestAlgId *next;
} DigestAlgId;




typedef struct {
    int32_t version;
    DigestAlgId digestAlgIds;
    Content content;
    mbedtls_x509_crt *certs;
    mbedtls_x509_crl crl;
    SignerInfo signers;
} SignedData;





typedef struct {
    mbedtls_asn1_buf contentTypeOid;
    SignedData signedData;

    mbedtls_pem_context pem;

} Pkcs7;
# 159 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h"
int32_t PKCS7_ParseSignedData(const unsigned char *buf, size_t bufLen, Pkcs7 *pkcs7);







int32_t PKCS7_VerifyCertsChain(const Pkcs7 *pkcs7);
# 177 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h"
void PKCS7_FreeRes(Pkcs7 *pkcs7);
# 191 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h"
typedef int32_t (*PKCS7_CalcDigest)(const Pkcs7 *pkcs7, const SignerInfo *signer,
    mbedtls_md_type_t algType, unsigned char *hash, size_t *hashLen);
# 203 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h"
int32_t PKCS7_GetContentData(const Pkcs7 *pkcs7, unsigned char **data, size_t *dataLen);
# 214 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h"
int32_t PKCS7_GetDigestInSignerAuthAttr(const SignerInfo *signer, unsigned char **dig, size_t *digLen);
# 227 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h"
int32_t PKCS7_GetSignerAuthAttr(const SignerInfo *signer, unsigned char **data, size_t *dataLen);
# 238 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h"
int32_t PKCS7_VerifySignerSignature(const Pkcs7 *pkcs7, PKCS7_CalcDigest calcDigest);
# 249 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h"
SignersResovedInfo *PKCS7_GetAllSignersResolvedInfo(const Pkcs7 *pkcs7);
# 258 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h"
void PKCS7_FreeAllSignersResolvedInfo(SignersResovedInfo *sri);
# 268 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/mbedtls_pkcs7.h"
int32_t PKCS7_EnableDebugMode(_Bool mode);
# 17 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/mbedtls_pkcs7.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/ctype.h" 1
# 10 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/ctype.h"
int isalnum(int);
int isalpha(int);
int isblank(int);
int iscntrl(int);
int isdigit(int);
int isgraph(int);
int islower(int);
int isprint(int);
int ispunct(int);
int isspace(int);
int isupper(int);
int isxdigit(int);
int tolower(int);
int toupper(int);


static inline int __isspace(int _c)
{
 return _c == ' ' || (unsigned)_c-'\t' < 5;
}
# 46 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/ctype.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 345 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef struct __locale_struct *locale_t;
# 47 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/ctype.h" 2

int isalnum_l(int, locale_t);
int isalpha_l(int, locale_t);
int isblank_l(int, locale_t);
int iscntrl_l(int, locale_t);
int isdigit_l(int, locale_t);
int isgraph_l(int, locale_t);
int islower_l(int, locale_t);
int isprint_l(int, locale_t);
int ispunct_l(int, locale_t);
int isspace_l(int, locale_t);
int isupper_l(int, locale_t);
int isxdigit_l(int, locale_t);
int tolower_l(int, locale_t);
int toupper_l(int, locale_t);

int isascii(int);
int toascii(int);
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/mbedtls_pkcs7.c" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/string.h" 1
# 25 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/string.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
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
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/mbedtls_pkcs7.c" 2
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
# 23 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_common.h" 2
# 106 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/include/app_common.h"
long long HapGetInt64(const unsigned char *buf, int32_t len);
int32_t HapGetInt(const unsigned char *buf, int32_t len);
uint32_t HapGetUnsignedInt(const unsigned char *buf, int32_t len);
short HapGetShort(const unsigned char *buf, int32_t len);
void HapPutInt32(unsigned char *buf, int32_t len, int32_t value);
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/mbedtls_pkcs7.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform.h" 1
# 33 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform_time.h" 1
# 26 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform_time.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/time.h" 1
# 35 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/time.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 65 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef long long time_t;




typedef long long suseconds_t;
# 262 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef void * timer_t;




typedef int clockid_t;




typedef long clock_t;




struct timeval { time_t tv_sec; suseconds_t tv_usec; };

struct timeval64 { long long tv_sec; long long tv_usec; };





struct timespec { time_t tv_sec; long tv_nsec; };

struct timespec64 { long long tv_sec; long long tv_nsec; };






typedef int pid_t;
# 36 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/time.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/time.h" 1
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/time.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/time.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/select.h" 1
# 16 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/select.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 365 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned long long sigset_t;
# 17 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/select.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h" 1
# 31 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/signal.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
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
# 304 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned uid_t;
# 325 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef long pthread_t;
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
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/sys/time.h" 2


struct timezone {
 int tz_minuteswest;
 int tz_dsttime;
};


int settimeofday64(const struct timeval64 *, const struct timezone *restrict);
int gettimeofday64(struct timeval64 *, struct timezone *restrict);


int gettimeofday (struct timeval *restrict, struct timezone *restrict);





struct itimerval {
 struct timeval it_interval;
 struct timeval it_value;
};


struct itimerval64 {
  struct timeval64 it_interval;
  struct timeval64 it_value;
};




int getitimer (int, struct itimerval *);
int setitimer (int, const struct itimerval *restrict, struct itimerval *restrict);
int utimes (const char *, const struct timeval [2]);


int futimes(int, const struct timeval [2]);
int futimesat(int, const char *, const struct timeval [2]);
int lutimes(const char *, const struct timeval [2]);
int settimeofday(const struct timeval *, const struct timezone *);
int adjtime (const struct timeval *, struct timeval *);
# 37 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/time.h" 2






struct tm {
 int tm_sec;
 int tm_min;
 int tm_hour;
 int tm_mday;
 int tm_mon;
 int tm_year;
 int tm_wday;
 int tm_yday;
 int tm_isdst;
 long tm_gmtoff;
 const char *tm_zone;
};

clock_t clock (void);
time_t time (time_t *);
double difftime (time_t, time_t);
time_t mktime (struct tm *);
size_t strftime (char *restrict, size_t, const char *restrict, const struct tm *restrict);
struct tm *gmtime (const time_t *);
struct tm *localtime (const time_t *);
char *asctime (const struct tm *);
char *ctime (const time_t *);
int timespec_get(struct timespec *, int);
# 76 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/time.h"
size_t strftime_l (char * restrict, size_t, const char * restrict, const struct tm * restrict, locale_t);

struct tm *gmtime_r (const time_t *restrict, struct tm *restrict);
struct tm *localtime_r (const time_t *restrict, struct tm *restrict);
char *asctime_r (const struct tm *restrict, char *restrict);
char *ctime_r (const time_t *, char *);

void tzset (void);

struct itimerspec {
 struct timespec it_interval;
 struct timespec it_value;
};


struct itimerspec64 {
  struct timespec64 it_interval;
  struct timespec64 it_value;
};
# 116 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/time.h"
int nanosleep (const struct timespec *, struct timespec *);
int clock_getres (clockid_t, struct timespec *);
int clock_gettime (clockid_t, struct timespec *);
int clock_settime (clockid_t, const struct timespec *);
int clock_nanosleep (clockid_t, int, const struct timespec *, struct timespec *);
int clock_getcpuclockid (pid_t, clockid_t *);

struct sigevent;
int timer_create (clockid_t, struct sigevent *restrict, timer_t *restrict);
int timer_delete (timer_t);
int timer_settime (timer_t, int, const struct itimerspec *restrict, struct itimerspec *restrict);
int timer_gettime (timer_t, struct itimerspec *);
int timer_getoverrun (timer_t);

extern char *tzname[2];





char *strptime (const char *restrict, const char *restrict, struct tm *restrict);
extern int daylight;
extern long timezone;
extern int getdate_err;
struct tm *getdate (const char *);




int stime(const time_t *);
time_t timegm(struct tm *);
# 27 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform_time.h" 2
typedef time_t mbedtls_time_t;






# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/inttypes.h" 1
# 12 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/inttypes.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 13 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/inttypes.h" 2

typedef struct { intmax_t quot, rem; } imaxdiv_t;

intmax_t imaxabs(intmax_t);
imaxdiv_t imaxdiv(intmax_t, intmax_t);

intmax_t strtoimax(const char *restrict, char **restrict, int);
uintmax_t strtoumax(const char *restrict, char **restrict, int);

intmax_t wcstoimax(const wchar_t *restrict, wchar_t **restrict, int);
uintmax_t wcstoumax(const wchar_t *restrict, wchar_t **restrict, int);
# 35 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform_time.h" 2
typedef int64_t mbedtls_ms_time_t;
# 51 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform_time.h"
mbedtls_ms_time_t mbedtls_ms_time(void);





extern mbedtls_time_t (*mbedtls_time)(mbedtls_time_t *time);
# 66 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform_time.h"
int mbedtls_platform_set_time(mbedtls_time_t (*time_func)(mbedtls_time_t *time));
# 34 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform.h" 2
# 148 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform.h"
extern void *mbedtls_calloc(size_t n, size_t size);
extern void mbedtls_free(void *ptr);
# 160 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform.h"
int mbedtls_platform_set_calloc_free(void *(*calloc_func)(size_t, size_t),
                                     void (*free_func)(void *));
# 238 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform.h"
extern int (*mbedtls_snprintf)(char *s, size_t n, const char *format, ...);
# 248 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform.h"
int mbedtls_platform_set_snprintf(int (*snprintf_func)(char *s, size_t n,
                                                       const char *format, ...));
# 440 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform.h"
typedef struct mbedtls_platform_context {
    char private_dummy;
}
mbedtls_platform_context;
# 464 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform.h"
int mbedtls_platform_setup(mbedtls_platform_context *ctx);
# 479 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/mbedtls/include/mbedtls/platform.h"
void mbedtls_platform_teardown(mbedtls_platform_context *ctx);
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/mbedtls_pkcs7.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h" 1
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securectype.h" 1
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h" 2
# 39 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/errno.h" 1
# 10 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/errno.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/errno.h" 1
# 11 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/errno.h" 2


__attribute__((const))

int *__errno_location(void);






extern char *program_invocation_short_name, *program_invocation_name;
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h" 2
# 50 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
typedef int errno_t;
# 122 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern const char *GetHwSecureCVersion(unsigned short *verNumber);
# 134 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern errno_t memset_s(void *dest, size_t destMax, int c, size_t count);
# 153 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern errno_t memmove_s(void *dest, size_t destMax, const void *src, size_t count);
# 166 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern errno_t memcpy_s(void *dest, size_t destMax, const void *src, size_t count);
# 178 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern errno_t strcpy_s(char *strDest, size_t destMax, const char *strSrc);
# 191 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern errno_t strncpy_s(char *strDest, size_t destMax, const char *strSrc, size_t count);
# 203 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern errno_t strcat_s(char *strDest, size_t destMax, const char *strSrc);
# 217 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern errno_t strncat_s(char *strDest, size_t destMax, const char *strSrc, size_t count);
# 231 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int vsprintf_s(char *strDest, size_t destMax, const char *format,
                           va_list argList) ;
# 245 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int sprintf_s(char *strDest, size_t destMax, const char *format, ...) ;
# 260 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int vsnprintf_s(char *strDest, size_t destMax, size_t count, const char *format,
                            va_list argList) ;
# 275 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int snprintf_s(char *strDest, size_t destMax, size_t count, const char *format,
                           ...) ;
# 290 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int vsnprintf_truncated_s(char *strDest, size_t destMax, const char *format,
                                      va_list argList) ;
# 302 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int snprintf_truncated_s(char *strDest, size_t destMax,
                                     const char *format, ...) ;
# 313 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int scanf_s(const char *format, ...);
# 323 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int vscanf_s(const char *format, va_list argList);
# 334 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int sscanf_s(const char *buffer, const char *format, ...);
# 346 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int vsscanf_s(const char *buffer, const char *format, va_list argList);
# 357 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int fscanf_s(FILE *stream, const char *format, ...);
# 369 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int vfscanf_s(FILE *stream, const char *format, va_list argList);
# 385 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern char *strtok_s(char *strToken, const char *strDelimit, char **context);
# 396 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern char *gets_s(char *buffer, size_t destMax);
# 410 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern errno_t wmemcpy_s(wchar_t *dest, size_t destMax, const wchar_t *src, size_t count);
# 423 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern errno_t wmemmove_s(wchar_t *dest, size_t destMax, const wchar_t *src, size_t count);
# 435 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern errno_t wcscpy_s(wchar_t *strDest, size_t destMax, const wchar_t *strSrc);
# 448 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern errno_t wcsncpy_s(wchar_t *strDest, size_t destMax, const wchar_t *strSrc, size_t count);
# 460 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern errno_t wcscat_s(wchar_t *strDest, size_t destMax, const wchar_t *strSrc);
# 474 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern errno_t wcsncat_s(wchar_t *strDest, size_t destMax, const wchar_t *strSrc, size_t count);
# 486 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern wchar_t *wcstok_s(wchar_t *strToken, const wchar_t *strDelimit, wchar_t **context);
# 499 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int vswprintf_s(wchar_t *strDest, size_t destMax, const wchar_t *format, va_list argList);
# 511 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int swprintf_s(wchar_t *strDest, size_t destMax, const wchar_t *format, ...);
# 521 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int fwscanf_s(FILE *stream, const wchar_t *format, ...);
# 532 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int vfwscanf_s(FILE *stream, const wchar_t *format, va_list argList);
# 541 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int wscanf_s(const wchar_t *format, ...);
# 551 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int vwscanf_s(const wchar_t *format, va_list argList);
# 561 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int swscanf_s(const wchar_t *buffer, const wchar_t *format, ...);
# 572 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
extern int vswscanf_s(const wchar_t *buffer, const wchar_t *format, va_list argList);





extern errno_t strncpy_error(char *strDest, size_t destMax, const char *strSrc, size_t count);
extern errno_t strcpy_error(char *strDest, size_t destMax, const char *strSrc);



extern errno_t memset_sOptAsm(void *dest, size_t destMax, int c, size_t count);
extern errno_t memset_sOptTc(void *dest, size_t destMax, int c, size_t count);
extern errno_t memcpy_sOptAsm(void *dest, size_t destMax, const void *src, size_t count);
extern errno_t memcpy_sOptTc(void *dest, size_t destMax, const void *src, size_t count);
# 23 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/mbedtls_pkcs7.c" 2
# 56 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/security/appverify/interfaces/innerkits/appverify_lite/src/mbedtls_pkcs7.c"
static mbedtls_x509_crt g_rootCaG2Cert;
static _Bool g_rootCertLoaded;
static const unsigned char ROOT_CA_G2_CERT_IN_PEM[] =
    "-----BEGIN CERTIFICATE-----\r\n"
    "MIICGjCCAaGgAwIBAgIIShhpn519jNAwCgYIKoZIzj0EAwMwUzELMAkGA1UEBhMC\r\n"
    "Q04xDzANBgNVBAoMBkh1YXdlaTETMBEGA1UECwwKSHVhd2VpIENCRzEeMBwGA1UE\r\n"
    "AwwVSHVhd2VpIENCRyBSb290IENBIEcyMB4XDTIwMDMxNjAzMDQzOVoXDTQ5MDMx\r\n"
    "NjAzMDQzOVowUzELMAkGA1UEBhMCQ04xDzANBgNVBAoMBkh1YXdlaTETMBEGA1UE\r\n"
    "CwwKSHVhd2VpIENCRzEeMBwGA1UEAwwVSHVhd2VpIENCRyBSb290IENBIEcyMHYw\r\n"
    "EAYHKoZIzj0CAQYFK4EEACIDYgAEWidkGnDSOw3/HE2y2GHl+fpWBIa5S+IlnNrs\r\n"
    "GUvwC1I2QWvtqCHWmwFlFK95zKXiM8s9yV3VVXh7ivN8ZJO3SC5N1TCrvB2lpHMB\r\n"
    "wcz4DA0kgHCMm/wDec6kOHx1xvCRo0IwQDAOBgNVHQ8BAf8EBAMCAQYwDwYDVR0T\r\n"
    "AQH/BAUwAwEB/zAdBgNVHQ4EFgQUo45a9Vq8cYwqaiVyfkiS4pLcIAAwCgYIKoZI\r\n"
    "zj0EAwMDZwAwZAIwMypeB7P0IbY7c6gpWcClhRznOJFj8uavrNu2PIoz9KIqr3jn\r\n"
    "BlBHJs0myI7ntYpEAjBbm8eDMZY5zq5iMZUC6H7UzYSix4Uy1YlsLVV738PtKP9h\r\n"
    "FTjgDHctXJlC5L7+ZDY=\r\n"
    "-----END CERTIFICATE-----\r\n";

static mbedtls_x509_crt g_debugModeRootCert;
static _Bool g_debugModeEnabled;
static const unsigned char DEBUG_MODE_ROOT_CERT_IN_PEM[] =
    "-----BEGIN CERTIFICATE-----\r\n"
    "MIICJTCCAaugAwIBAgIIb/9KnVieVTgwCgYIKoZIzj0EAwMwWDELMAkGA1UEBhMC\r\n"
    "Q04xDzANBgNVBAoMBkh1YXdlaTETMBEGA1UECwwKSHVhd2VpIENCRzEjMCEGA1UE\r\n"
    "AwwaSHVhd2VpIENCRyBSb290IENBIEcyIFRlc3QwHhcNMjAwMzEyMTI0NDAwWhcN\r\n"
    "NDkwMzEyMTI0NDAwWjBYMQswCQYDVQQGEwJDTjEPMA0GA1UECgwGSHVhd2VpMRMw\r\n"
    "EQYDVQQLDApIdWF3ZWkgQ0JHMSMwIQYDVQQDDBpIdWF3ZWkgQ0JHIFJvb3QgQ0Eg\r\n"
    "RzIgVGVzdDB2MBAGByqGSM49AgEGBSuBBAAiA2IABLS4fgvaYKKfyMZW/4nNTsSv\r\n"
    "xqVxqOEDfLySZK/fSEN0IDQj0sK/qK5hvnf0OxWhwI49P3dKGmQ+cSujXvy0me2D\r\n"
    "JTjY127XYZJrvJwwMkrT/vMrZC5kSOEJbt1qAgSmiaNCMEAwDgYDVR0PAQH/BAQD\r\n"
    "AgEGMA8GA1UdEwEB/wQFMAMBAf8wHQYDVR0OBBYEFGldwFjx9Tzm/QpA8R1gc9wc\r\n"
    "eMbFMAoGCCqGSM49BAMDA2gAMGUCMQCCUDRaglmycUGrHmF+L8owKJhbqOUqbwuX\r\n"
    "7XL/vJcp3HeHjiXu7XZmYQ+QAvHPhU0CMCiwWFbDl8ETw4VK25QbwhL/QiUfiRfC\r\n"
    "J6LzteOvjLTEV5iebQMz/nS1j7/oj3Rsqg==\r\n"
    "-----END CERTIFICATE-----\r\n";
static mbedtls_x509_crt g_ohosRootCert;
static const unsigned char OHOS_ROOT_CERT_IN_PEM[] =
    "-----BEGIN CERTIFICATE-----\r\n"
    "MIICRDCCAcmgAwIBAgIED+E4izAMBggqhkjOPQQDAwUAMGgxCzAJBgNVBAYTAkNO\r\n"
    "MRQwEgYDVQQKEwtPcGVuSGFybW9ueTEZMBcGA1UECxMQT3Blbkhhcm1vbnkgVGVh\r\n"
    "bTEoMCYGA1UEAxMfT3Blbkhhcm1vbnkgQXBwbGljYXRpb24gUm9vdCBDQTAeFw0y\r\n"
    "MTAyMDIxMjE0MThaFw00OTEyMzExMjE0MThaMGgxCzAJBgNVBAYTAkNOMRQwEgYD\r\n"
    "VQQKEwtPcGVuSGFybW9ueTEZMBcGA1UECxMQT3Blbkhhcm1vbnkgVGVhbTEoMCYG\r\n"
    "A1UEAxMfT3Blbkhhcm1vbnkgQXBwbGljYXRpb24gUm9vdCBDQTB2MBAGByqGSM49\r\n"
    "AgEGBSuBBAAiA2IABE023XmRaw2DnO8NSsb+KG/uY0FtS3u5LQucdr3qWVnRW5ui\r\n"
    "QIL6ttNZBEeLTUeYcJZCpayg9Llf+1SmDA7dY4iP2EcRo4UN3rilovtfFfsmH4ty\r\n"
    "3SApHVFzWUl+NwdH8KNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC\r\n"
    "AQYwHQYDVR0OBBYEFBc6EKGrGXzlAE+s0Zgnsphadw7NMAwGCCqGSM49BAMDBQAD\r\n"
    "ZwAwZAIwd1p3JzHN93eoPped1li0j64npgqNzwy4OrkehYAqNXpcpaEcLZ7UxW8E\r\n"
    "I2lZJ3SbAjAkqySHb12sIwdSFKSN9KCMMEo/eUT5dUXlcKR2nZz0MJdxT5F51qcX\r\n"
    "1CumzkcYhgU=\r\n"
    "-----END CERTIFICATE-----\r\n";


static _Bool InvalidDigestAlg(const mbedtls_asn1_buf *alg)
{
    return (((sizeof("\x60" "\x86\x48" "\x01" "\x65" "\x03\x04" "\x02\x01") - 1) != (alg)->len) || memcmp(("\x60" "\x86\x48" "\x01" "\x65" "\x03\x04" "\x02\x01"), (alg)->p, (alg)->len) != 0) &&
        (((sizeof("\x60" "\x86\x48" "\x01" "\x65" "\x03\x04" "\x02\x02") - 1) != (alg)->len) || memcmp(("\x60" "\x86\x48" "\x01" "\x65" "\x03\x04" "\x02\x02"), (alg)->p, (alg)->len) != 0) &&
        (((sizeof("\x60" "\x86\x48" "\x01" "\x65" "\x03\x04" "\x02\x03") - 1) != (alg)->len) || memcmp(("\x60" "\x86\x48" "\x01" "\x65" "\x03\x04" "\x02\x03"), (alg)->p, (alg)->len) != 0);
}

static int32_t GetContentInfoType(unsigned char **p, const unsigned char *end,
                              mbedtls_asn1_buf *contentType, _Bool *hasContent)
{
    size_t seqLen = 0;
    size_t len = 0;
    int32_t rc;

    rc = mbedtls_asn1_get_tag(p, end, &seqLen, 0x20 | 0x10);
    if (rc) {
        return rc;
    }
    unsigned char *start = *p;
    end = start + seqLen;
    rc = mbedtls_asn1_get_tag(p, end, &len, 0x06);
    if (rc) {
        return rc;
    }
    contentType->tag = 0x06;
    contentType->len = len;
    contentType->p = *p;
    *hasContent = (seqLen != len + (*p - start));
    *p += len;

    return PKCS7_SUCC;
}

static int32_t GetContentLenOfContentInfo(unsigned char **p, const unsigned char *end, size_t *len)
{
    return mbedtls_asn1_get_tag(p, end, len, 0x20 | 0x80);
}

static int32_t ParseSignerVersion(unsigned char **p, const unsigned char *end, SignerInfo *signer)
{
    return mbedtls_asn1_get_int(p, end, &signer->version);
}

static int32_t ParseSignerIssuerAndSerialNum(unsigned char **p, const unsigned char *end, SignerInfo *signer)
{
    int32_t rc;
    size_t len;

    rc = mbedtls_asn1_get_tag(p, end, &len, 0x20 | 0x10);
    if (rc) {
        return rc;
    }

    signer->issuerRaw.p = *p;
    rc = mbedtls_asn1_get_tag(p, end, &len, 0x20 | 0x10);
    if (rc) {
        return rc;
    }

    rc = mbedtls_x509_get_name(p, *p + len, &signer->issuer);
    if (rc) {
        return rc;
    }
    signer->issuerRaw.len = *p - signer->issuerRaw.p;

    rc = mbedtls_x509_get_serial(p, end, &signer->serial);

    return rc;
}

static int32_t ParseSignerDigestAlg(unsigned char **p, const unsigned char *end, SignerInfo *signer)
{
    int32_t rc = mbedtls_asn1_get_alg_null(p, end, &signer->digestAlgId);
    if (rc) {
        return rc;
    }
    if (InvalidDigestAlg(&signer->digestAlgId)) {
        return PKCS7_INVALID_DIGEST_ALG;
    }
    return PKCS7_SUCC;
}

static int32_t ParseSignerAuthAttr(unsigned char **p, const unsigned char *end, SignerInfo *signer)
{
    int32_t rc;
    size_t len = 0;
    unsigned char *raw = *p;

    rc = mbedtls_asn1_get_tag(p, end, &len, 0x20 | 0x80);
    if (rc) {
        return PKCS7_SUCC;
    }
    signer->authAttr.tag = 0x20 | 0x80;
    signer->authAttr.p = *p;
    signer->authAttr.len = len;
    size_t tlLen = *p - raw;
    *p += len;

    signer->authAttrRaw.p = raw;
    signer->authAttrRaw.len = len + tlLen;
    return PKCS7_SUCC;
}




static _Bool InvalidDigestEncAlg(const mbedtls_x509_buf *alg)
{
    return (((sizeof("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x01" "\x0b") - 1) != (alg)->len) || memcmp(("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x01" "\x0b"), (alg)->p, (alg)->len) != 0) &&
        (((sizeof("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x01" "\x0c") - 1) != (alg)->len) || memcmp(("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x01" "\x0c"), (alg)->p, (alg)->len) != 0) &&
        (((sizeof("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x01" "\x0d") - 1) != (alg)->len) || memcmp(("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x01" "\x0d"), (alg)->p, (alg)->len) != 0) &&
        (((sizeof("\x2a" "\x86\x48" "\xce\x3d" "\x04" "\x03" "\x02") - 1) != (alg)->len) || memcmp(("\x2a" "\x86\x48" "\xce\x3d" "\x04" "\x03" "\x02"), (alg)->p, (alg)->len) != 0) &&
        (((sizeof("\x2a" "\x86\x48" "\xce\x3d" "\x04" "\x03" "\x03") - 1) != (alg)->len) || memcmp(("\x2a" "\x86\x48" "\xce\x3d" "\x04" "\x03" "\x03"), (alg)->p, (alg)->len) != 0) &&
        (((sizeof("\x2a" "\x86\x48" "\xce\x3d" "\x04" "\x03" "\x04") - 1) != (alg)->len) || memcmp(("\x2a" "\x86\x48" "\xce\x3d" "\x04" "\x03" "\x04"), (alg)->p, (alg)->len) != 0) &&
        (((sizeof("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x01" "\x0a") - 1) != (alg)->len) || memcmp(("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x01" "\x0a"), (alg)->p, (alg)->len) != 0);
}

static int32_t ParseSignerEncAlg(unsigned char **p, const unsigned char *end, SignerInfo *signer)
{
    int32_t rc;
    mbedtls_asn1_buf params = {0};

    rc = mbedtls_asn1_get_alg(p, end, &signer->digestEncAlgId, &params);
    if (rc) {
        return rc;
    }
    if (InvalidDigestEncAlg(&signer->digestEncAlgId)) {
        return PKCS7_INVALID_SIGNING_ALG;
    }
    return PKCS7_SUCC;
}





static int32_t ParseSignerSignature(unsigned char **p, const unsigned char *end, SignerInfo *signer)
{
    int32_t rc;
    size_t len = 0;

    rc = mbedtls_asn1_get_tag(p, end, &len, 0x04);
    if (rc) {
        return rc;
    }
    signer->signature.tag = 0x04;
    signer->signature.len = len;
    signer->signature.p = *p;
    *p += len;
    return PKCS7_SUCC;
}

static int32_t GetSignerSignature(const SignerInfo *signer, unsigned char **sig, size_t *sigLen)
{
    size_t len = signer->signature.len;
    unsigned char *buf = signer->signature.p;
    *sig = buf;
    *sigLen = len;
    return PKCS7_SUCC;
}

static int32_t ParseSignerUnAuthAttr(unsigned char **p, const unsigned char *end, SignerInfo *signer)
{
    int32_t rc;
    size_t len = 0;


    if (end - *p < 1) {
        return PKCS7_SUCC;
    }
    rc = mbedtls_asn1_get_tag(p, end, &len, (0x20 | 0x80) + 1);
    if (rc) {
        return rc;
    }
    signer->unAuthAttr.tag = (0x20 | 0x80) + 1;
    signer->unAuthAttr.len = len;
    signer->unAuthAttr.p = *p;
    *p += len;
    return PKCS7_SUCC;
}

static int32_t SerialCmp(const mbedtls_x509_buf *a, const mbedtls_x509_buf *b)
{
    if (a->len == b->len && memcmp(a->p, b->p, a->len) == 0) {
        return 0;
    }
    return -1;
}


static _Bool IsLegitString(int32_t tag)
{
    if (tag == 0x0C || tag == 0x13) {
        return 1;
    }
    return 0;
}

static int32_t CompareX509String(const mbedtls_x509_buf *first, const mbedtls_x509_buf *second)
{
    if (IsLegitString(first->tag) && IsLegitString(second->tag)) {
        for (int32_t i = 0; i < first->len; i++) {
            if (first->p[i] == second->p[i] ||
                (((0 ? islower(first->p[i]) : ((unsigned)(first->p[i])-'a') < 26) != 0) && (first->p[i] - 32 == second->p[i])) ||
                (((0 ? isupper(first->p[i]) : ((unsigned)(first->p[i])-'A') < 26) != 0) && (first->p[i] + 32 == second->p[i]))) {
                continue;
            }
            return -1;
        }
        return 0;
    }
    return -1;
}

static int32_t GetDeps(const mbedtls_x509_name *nameList)
{
    int32_t deps = 0;
    while (nameList != ((void*)0)) {
        nameList = nameList->next;
        deps++;
    }
    return deps;
}

static int32_t CompareX509NameList(const mbedtls_x509_name *first, const mbedtls_x509_name *second)
{
    if (first == ((void*)0) || second == ((void*)0)) {
        return -1;
    }
    int32_t firstDeps = GetDeps(first);
    int32_t secondDeps = GetDeps(second);
    if (firstDeps != secondDeps) {
        return -1;
    }
    for (int32_t i = 0; i < firstDeps; i++) {
        if (first->oid.tag != second->oid.tag ||
            first->oid.len != second->oid.len ||
            memcmp(first->oid.p, second->oid.p, second->oid.len) != 0 ||
            first->private_next_merged != second->private_next_merged ||
            first->val.len != second->val.len) {
            return -1;
        }
        if (CompareX509String(&first->val, &second->val) != 0) {
            return -1;
        }
        first = first->next;
        second = second->next;
    }
    return 0;
}

static void *Pkcs7Calloc(size_t nmemb, size_t size)
{
    return calloc(nmemb, size);
}

static void Pkcs7Free(void *ptr)
{
    free(ptr);
}

static int32_t ParseSignedDataSignerInfos(unsigned char **p, const unsigned char *end, SignerInfo *signers)
{
    int32_t rc;
    size_t len = 0;

    rc = mbedtls_asn1_get_tag(p, end, &len, 0x20 | 0x11);
    if (rc || len == 0) {
        return PKCS7_HAS_NO_SIGNER_INFO;
    }
    end = *p + len;

    while (*p < end) {
        size_t oneSignerLen;
        unsigned char *oneSignerEnd = ((void*)0);

        rc = mbedtls_asn1_get_tag(p, end, &oneSignerLen, 0x20 | 0x10);
        do { if ((rc) != PKCS7_SUCC) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""%s:%u, error occurred, ret:%d", __FUNCTION__, 387, __FUNCTION__, 387, (rc))); return rc; } } while (0);

        oneSignerEnd = *p + oneSignerLen;

        rc = ParseSignerVersion(p, oneSignerEnd, signers);
        do { if ((rc) != PKCS7_SUCC) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""%s:%u, error occurred, ret:%d", __FUNCTION__, 392, __FUNCTION__, 392, (rc))); return rc; } } while (0);


        rc = ParseSignerIssuerAndSerialNum(p, oneSignerEnd, signers);
        do { if ((rc) != PKCS7_SUCC) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""%s:%u, error occurred, ret:%d", __FUNCTION__, 396, __FUNCTION__, 396, (rc))); return rc; } } while (0);


        rc = ParseSignerDigestAlg(p, oneSignerEnd, signers);
        do { if ((rc) != PKCS7_SUCC) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""%s:%u, error occurred, ret:%d", __FUNCTION__, 400, __FUNCTION__, 400, (rc))); return rc; } } while (0);


        rc = ParseSignerAuthAttr(p, oneSignerEnd, signers);
        do { if ((rc) != PKCS7_SUCC) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""%s:%u, error occurred, ret:%d", __FUNCTION__, 404, __FUNCTION__, 404, (rc))); return rc; } } while (0);


        rc = ParseSignerEncAlg(p, oneSignerEnd, signers);
        do { if ((rc) != PKCS7_SUCC) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""%s:%u, error occurred, ret:%d", __FUNCTION__, 408, __FUNCTION__, 408, (rc))); return rc; } } while (0);


        rc = ParseSignerSignature(p, oneSignerEnd, signers);
        do { if ((rc) != PKCS7_SUCC) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""%s:%u, error occurred, ret:%d", __FUNCTION__, 412, __FUNCTION__, 412, (rc))); return rc; } } while (0);


        rc = ParseSignerUnAuthAttr(p, oneSignerEnd, signers);
        do { if ((rc) != PKCS7_SUCC) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""%s:%u, error occurred, ret:%d", __FUNCTION__, 416, __FUNCTION__, 416, (rc))); return rc; } } while (0);

        if (*p < end) {
            signers->next = Pkcs7Calloc(1, sizeof(*signers));
            if (signers->next == ((void*)0)) {

                return PKCS7_MEMORY_EXHAUST;
            }
            signers = signers->next;
        }
    }
    return rc;
}

static int32_t ParseSignedDataVersion(unsigned char **p, const unsigned char *end, int32_t *ver)
{
    int32_t rc = mbedtls_asn1_get_int(p, end, ver);
    if (rc) {
        return rc;
    }

    if (*ver != 1) {
        ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""Invalid version : %d\n", __FUNCTION__, 438, *ver));
        return PKCS7_INVALID_VERSION;
    }
    ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""Parse signed data version success\n", __FUNCTION__, 441));
    return PKCS7_SUCC;
}

static int32_t ParseSignedDataDigestAlgs(unsigned char **p, const unsigned char *end, DigestAlgId *algIds)
{
    int32_t rc;
    size_t len = 0;


    rc = mbedtls_asn1_get_tag(p, end, &len, 0x20 | 0x11);
    if (rc) {
        return rc;
    }
    end = *p + len;


    DigestAlgId *id = algIds;
    while (*p < end) {
        mbedtls_asn1_buf params = {0};

        rc = mbedtls_asn1_get_alg(p, end, &id->algBuf, &params);
        if (rc) {
            return rc;
        }
        if (InvalidDigestAlg(&id->algBuf)) {
            return PKCS7_INVALID_DIGEST_ALG;
        }
        if (*p < end) {
            id->next = Pkcs7Calloc(1, sizeof(DigestAlgId));
            if (id->next == ((void*)0)) {

                return PKCS7_MEMORY_EXHAUST;
            }
            id = id->next;
        }
    }
    return PKCS7_SUCC;
}

static void DlogContentInfo(const Content *content)
{
    int32_t len = content->data.len;
    if (len <= 0) {
        return;
    }
    char *info = Pkcs7Calloc(len + 1, sizeof(char));
    if (info == ((void*)0)) {
        return;
    }
    if (strncpy_s(info, len + 1, (char *)content->data.p, len) != 0) {
        Pkcs7Free(info);
        return;
    }
    Pkcs7Free(info);
}

static int32_t ParseSignedDataContentInfo(unsigned char **p, const unsigned char *end, Content *content)
{
    int32_t rc;
    size_t len = 0;
    _Bool hasContent = 0;

    rc = GetContentInfoType(p, end, &content->oid, &hasContent);
    if (rc) {
        return rc;
    }

    if ((((sizeof("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x07" "\x01") - 1) != (&content->oid)->len) || memcmp(("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x07" "\x01"), (&content->oid)->p, (&content->oid)->len) != 0) || !hasContent) {
        ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""Invalid content type or has no real content", __FUNCTION__, 510));
        return PKCS7_INVALID_CONTENT_TYPE_OR_NO_CONTENT;
    }
    rc = GetContentLenOfContentInfo(p, end, &len);
    if (rc) {
        return rc;
    }
    content->data.tag = 0x20 | 0x80;
    content->data.p = *p;
    content->data.len = len;
    DlogContentInfo(content);
    *p += len;
    return PKCS7_SUCC;
}

static int32_t ParseSignedDataCerts(unsigned char **p, const unsigned char *end, mbedtls_x509_crt **certs)
{
    int32_t rc;
    size_t len = 0;

    rc = mbedtls_asn1_get_tag(p, end, &len, 0x20 | 0x80);
    if (rc) {
        ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""Has no certificates in signed data.", __FUNCTION__, 532));
        return PKCS7_SUCC;
    }
    *certs = mbedtls_calloc(1, sizeof(**certs));
    if (*certs == ((void*)0)) {
        return PKCS7_MEMORY_EXHAUST;
    }
    mbedtls_x509_crt_init(*certs);

    unsigned char *certsEnd = *p + len;
    int32_t cnt = 0;
    while (*p < certsEnd) {

        size_t oneCertLen;
        unsigned char *seqBegin = *p;
        rc = mbedtls_asn1_get_tag(p, end, &oneCertLen, 0x20 | 0x10);
        if (rc) {
            return rc;
        }
        if (oneCertLen + (*p - seqBegin) > (certsEnd - seqBegin)) {
            return PKCS7_PARSING_ERROR;
        }
        rc = mbedtls_x509_crt_parse(*certs, seqBegin, oneCertLen + (*p - seqBegin));
        if (rc) {
            return rc;
        }
        *p += oneCertLen;
        cnt++;
    }
    ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""Parse signed data certs success", __FUNCTION__, 561));
    return rc;
}

static int32_t ParseSignedDataCrl(unsigned char **p, const unsigned char *end, mbedtls_x509_crl *crl)
{
    int32_t rc;
    size_t len = 0;

    rc = mbedtls_asn1_get_tag(p, end, &len, (0x20 | 0x80) + 1);
    if (rc) {
        ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""Has no crl in signed data.", __FUNCTION__, 572));
        return PKCS7_SUCC;
    }
    mbedtls_x509_crl_init(crl);
    rc = mbedtls_x509_crl_parse(crl, *p, len);
    *p += len;
    return rc;
}

static int32_t ParseSignedData(unsigned char *buf, size_t bufLen, SignedData *signedData)
{
    unsigned char *p = buf;
    unsigned char *end = buf + bufLen;
    size_t len = 0;
    int32_t rc;


    rc = mbedtls_asn1_get_tag(&p, end, &len, 0x20 | 0x10);
    if (rc) {
        return rc;
    }


    rc = ParseSignedDataVersion(&p, end, &signedData->version);
    if (rc) {
        return rc;
    }


    rc = ParseSignedDataDigestAlgs(&p, end, &signedData->digestAlgIds);
    if (rc) {
        return rc;
    }


    rc = ParseSignedDataContentInfo(&p, end, &signedData->content);
    if (rc) {
        return rc;
    }

    if (p >= end) {
        return PKCS7_PARSING_ERROR;
    }

    rc = ParseSignedDataCerts(&p, end, &signedData->certs);
    if (rc) {
        return rc;
    }


    rc = ParseSignedDataCrl(&p, end, &signedData->crl);
    if (rc) {
        return rc;
    }


    rc = ParseSignedDataSignerInfos(&p, end, &signedData->signers);
    ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""ParseSignedData %d", __FUNCTION__, 629, rc));
    return rc;
}

static _Bool IsSigedDataOid(const Pkcs7 *pkcs7)
{
    return !(((sizeof("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x07" "\x02") - 1) != (&pkcs7->contentTypeOid)->len) || memcmp(("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x07" "\x02"), (&pkcs7->contentTypeOid)->p, (&pkcs7->contentTypeOid)->len) != 0);
}

static void FreeSignedDataDigestAlgs(Pkcs7 *pkcs7)
{
    DigestAlgId *alg = pkcs7->signedData.digestAlgIds.next;
    DigestAlgId *next = ((void*)0);

    while (alg != ((void*)0)) {
        next = alg->next;
        Pkcs7Free(alg);
        alg = next;
    }
    pkcs7->signedData.digestAlgIds.next = ((void*)0);
}

static void FreeSignerCerts(SignerInfo *signer)
{
    if (signer->certPath.crt != ((void*)0)) {
        mbedtls_x509_crt_free(signer->certPath.crt);
        mbedtls_free(signer->certPath.crt);
        signer->certPath.crt = ((void*)0);
    }
}

static void FreeSignerIssuer(SignerInfo *signer)
{
    mbedtls_x509_name *name_cur = ((void*)0);
    mbedtls_x509_name *name_prv = ((void*)0);
    name_cur = signer->issuer.next;
    while (name_cur != ((void*)0)) {
        name_prv = name_cur;
        name_cur = name_cur->next;
        mbedtls_free(name_prv);
    }
    signer->issuer.next = ((void*)0);
}

static void FreeSignersInfo(Pkcs7 *pkcs7)
{
    SignerInfo *signer = pkcs7->signedData.signers.next;
    SignerInfo *next = ((void*)0);

    while (signer != ((void*)0)) {
        next = signer->next;
        FreeSignerCerts(signer);
        FreeSignerIssuer(signer);
        Pkcs7Free(signer);
        signer = next;
    }
    pkcs7->signedData.signers.next = ((void*)0);
    FreeSignerCerts(&pkcs7->signedData.signers);
    FreeSignerIssuer(&pkcs7->signedData.signers);
}

static void FreeSignedDataCerts(Pkcs7 *pkcs7)
{
    if (pkcs7->signedData.certs != ((void*)0)) {
        mbedtls_x509_crt_free(pkcs7->signedData.certs);
        mbedtls_free(pkcs7->signedData.certs);
        pkcs7->signedData.certs = ((void*)0);
    }
}

static void FreeSignedDataCrl(Pkcs7 *pkcs7)
{
    mbedtls_x509_crl_free(&pkcs7->signedData.crl);
    return;
}

static int32_t GetCertsNumOfSignedData(const mbedtls_x509_crt *crts)
{
    int32_t cnt = 0;
    while (crts != ((void*)0)) {
        crts = crts->next;
        cnt++;
    }
    return cnt;
}

static mbedtls_x509_crt *FindSuperCert(mbedtls_x509_crt *cur, mbedtls_x509_crt *certsList)
{

    while (certsList != ((void*)0)) {
        if (CompareX509NameList(&cur->issuer, &certsList->subject) == 0) {
            break;
        }
        certsList = certsList->next;
    }
    return certsList;
}

static void DelCertOfSignedData(SignedData *signedData, mbedtls_x509_crt *crt)
{
    mbedtls_x509_crt *head = signedData->certs;
    if (crt == head) {
        signedData->certs = crt->next;
        crt->next = ((void*)0);
    } else {
        mbedtls_x509_crt *prev = head;
        while (head != ((void*)0)) {
            if (head == crt) {
                prev->next = crt->next;
                crt->next = ((void*)0);
                break;
            }
            prev = head;
            head = head->next;
        }
    }
}

static void AddCertToSignerCertPath(SignerInfo *signer, mbedtls_x509_crt *crt)
{
    mbedtls_x509_crt *prev = signer->certPath.crt;
    mbedtls_x509_crt *cur = prev;
    if (prev == ((void*)0)) {
        signer->certPath.crt = crt;
        crt->next = ((void*)0);
    } else {
        while (cur != ((void*)0)) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = crt;
        crt->next = ((void*)0);
    }

    signer->certPath.depth++;
}

static int32_t BuildSignerCertPath(SignerInfo *signer, mbedtls_x509_crt *lowerCrt, SignedData *signeData)
{
    int32_t scanCnt = 0;
    int32_t rc = PKCS7_SUCC;
    if (!g_rootCertLoaded) {
        return PKCS7_ROOT_CA_NOT_VALID;
    }
    signer->rootCert = &g_rootCaG2Cert;

    mbedtls_x509_crt *certs = signeData->certs;


    mbedtls_x509_crt *cur = lowerCrt;
    mbedtls_x509_crt *next = ((void*)0);
    int32_t certsCnt = GetCertsNumOfSignedData(certs);
    DelCertOfSignedData(signeData, cur);
    AddCertToSignerCertPath(signer, cur);
    while (1) {
        next = FindSuperCert(cur, signeData->certs);
        if (next == ((void*)0)) {
            break;
        } else {
            DelCertOfSignedData(signeData, next);
            AddCertToSignerCertPath(signer, next);
        }
        scanCnt++;
        if (scanCnt > certsCnt) {
            rc = PKCS7_BUILD_CERT_PATH_FAIL;
            break;
        }
        cur = next;
    }
    return rc;
}

static int32_t ConstructSignerCerts(SignedData *signedData)
{

    SignerInfo *signer = &signedData->signers;
    while (signer != ((void*)0)) {
        mbedtls_x509_buf *signerSerial = &signer->serial;
        mbedtls_x509_name *signerIssuer = &signer->issuer;
        mbedtls_x509_crt *cert = signedData->certs;
        ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""To filter one signer's cert", __FUNCTION__, 809));
        while (cert != ((void*)0)) {
            if (SerialCmp(signerSerial, &cert->serial) == 0 &&
                CompareX509NameList(signerIssuer, &cert->issuer) == 0) {
                ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""Found signer's low level cert", __FUNCTION__, 813));
                break;
            }
            cert = cert->next;
        }
        if (cert == ((void*)0)) {
            ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""Could not found signer's lowest cert", __FUNCTION__, 819));
            return PKCS7_INVALID_VALUE;
        }
        int32_t rc = BuildSignerCertPath(signer, cert, signedData);
        if (rc != 0) {
            return rc;
        }
        signer = signer->next;
    }
    return 0;
}


static int32_t GetSignerDigestAlg(const SignerInfo *signer, mbedtls_md_type_t *algType)
{
    const mbedtls_x509_buf *alg = &signer->digestAlgId;
    if (!(((sizeof("\x60" "\x86\x48" "\x01" "\x65" "\x03\x04" "\x02\x01") - 1) != (alg)->len) || memcmp(("\x60" "\x86\x48" "\x01" "\x65" "\x03\x04" "\x02\x01"), (alg)->p, (alg)->len) != 0)) {
        *algType = MBEDTLS_MD_SHA256;
        return PKCS7_SUCC;
    }
    if (!(((sizeof("\x60" "\x86\x48" "\x01" "\x65" "\x03\x04" "\x02\x02") - 1) != (alg)->len) || memcmp(("\x60" "\x86\x48" "\x01" "\x65" "\x03\x04" "\x02\x02"), (alg)->p, (alg)->len) != 0)) {
        *algType = MBEDTLS_MD_SHA384;
        return PKCS7_SUCC;
    }
    if (!(((sizeof("\x60" "\x86\x48" "\x01" "\x65" "\x03\x04" "\x02\x03") - 1) != (alg)->len) || memcmp(("\x60" "\x86\x48" "\x01" "\x65" "\x03\x04" "\x02\x03"), (alg)->p, (alg)->len) != 0)) {
        *algType = MBEDTLS_MD_SHA512;
        return PKCS7_SUCC;
    }
    return PKCS7_INVALID_DIGEST_ALG;
}


static int32_t GetSignerPubKeyOfSignature(const SignerInfo *signer, mbedtls_pk_context **pk)
{

    if (signer == ((void*)0) || pk == ((void*)0)) {
        return PKCS7_INVALID_PARAM;
    }
    if (signer->certPath.crt != ((void*)0)) {
        *pk = &signer->certPath.crt->pk;
        return PKCS7_SUCC;
    }
    return PKCS7_INVALID_VALUE;
}

int32_t PKCS7_VerifySignerSignature(const Pkcs7 *pkcs7, PKCS7_CalcDigest calcDigest)
{
    int32_t rc;
    if (pkcs7 == ((void*)0) || calcDigest == ((void*)0)) {
        return PKCS7_INVALID_PARAM;
    }
    const SignerInfo *signer = &pkcs7->signedData.signers;
    unsigned char *sig = ((void*)0);
    size_t sigLen;
    while (signer != ((void*)0)) {
        rc = GetSignerSignature(signer, &sig, &sigLen);
        if (rc) {
            return rc;
        }
        ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""get signer signature len : %zu", __FUNCTION__, 878, sigLen));

        mbedtls_pk_context *pk = ((void*)0);
        rc = GetSignerPubKeyOfSignature(signer, &pk);
        if (rc) {
            return rc;
        }
        mbedtls_md_type_t digAlg;
        rc = GetSignerDigestAlg(signer, &digAlg);
        if (rc) {
            return rc;
        }
        unsigned char hash[64];
        (void)memset_s(hash, 64, 0, 64);
        size_t hashLen = 0;
        rc = calcDigest(pkcs7, signer, digAlg, hash, &hashLen);
        if (rc) {
            ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""Calculate content hash failed by calling callback", __FUNCTION__, 895));
            return rc;
        }

        if (!(((sizeof("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x01" "\x0a") - 1) != (&signer->digestEncAlgId)->len) || memcmp(("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x01" "\x0a"), (&signer->digestEncAlgId)->p, (&signer->digestEncAlgId)->len) != 0)) {
            mbedtls_rsa_set_padding(pk->private_pk_ctx, 1, (mbedtls_md_type_t)0);
        }
        rc = mbedtls_pk_verify(pk, digAlg, hash, hashLen, sig, sigLen);
        (void)memset_s(hash, 64, 0, 64);
        if (rc) {
            ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""Verify signature failed, returned -0x%04x", __FUNCTION__, 905, rc));
            return rc;
        } else {
            ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""Verify signer signature success\n", __FUNCTION__, 908));
        }
        signer = signer->next;
    }
    return rc;
}

static int32_t LoadRootCert(void)
{
    int32_t rc = 0;
    if (!g_rootCertLoaded) {
        mbedtls_x509_crt_init(&g_rootCaG2Cert);
        rc = mbedtls_x509_crt_parse(&g_rootCaG2Cert, ROOT_CA_G2_CERT_IN_PEM, sizeof(ROOT_CA_G2_CERT_IN_PEM));
        if (rc) {
            ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""load root ca failed", __FUNCTION__, 922));
            return rc;
        } else {
            ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""load root ca success", __FUNCTION__, 925));
        }
        g_rootCertLoaded = 1;
    }
    return rc;
}

static void UnLoadRootCert(void)
{
    if (g_rootCertLoaded) {
        mbedtls_x509_crt_free(&g_rootCaG2Cert);
        g_rootCertLoaded = 0;
    }
}

static int32_t LoadDebugModeRootCert(void)
{
    mbedtls_x509_crt_init(&g_debugModeRootCert);
    int32_t rc = mbedtls_x509_crt_parse(&g_debugModeRootCert, DEBUG_MODE_ROOT_CERT_IN_PEM,
        sizeof(DEBUG_MODE_ROOT_CERT_IN_PEM));
    if (rc) {
        ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""load debug mode root ca failed %d", __FUNCTION__, 946, rc));
        return rc;
    } else {
        ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""load debug mode root ca success", __FUNCTION__, 949));
    }
    return rc;
}
static int32_t UnLoadDebugModeRootCert(void)
{
    mbedtls_x509_crt_free(&g_debugModeRootCert);
    return PKCS7_SUCC;
}

static int32_t LoadSelfSignedCert(void)
{
    mbedtls_x509_crt_init(&g_ohosRootCert);
    int32_t rc = mbedtls_x509_crt_parse(&g_ohosRootCert, OHOS_ROOT_CERT_IN_PEM, sizeof(OHOS_ROOT_CERT_IN_PEM));
    if (rc) {
        ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""load self signed ca failed %d", __FUNCTION__, 964, rc));
        return rc;
    } else {
        ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""load self signed root ca success", __FUNCTION__, 967));
    }
    return rc;
}

static void UnLoadSelfSignedCert(void)
{
    mbedtls_x509_crt_free(&g_ohosRootCert);
}
static void DLogCrtVerifyInfo(uint32_t flags)
{
    char vrfyBuf[512];
    (void)memset_s(vrfyBuf, 512, 0, 512);
    mbedtls_x509_crt_verify_info(vrfyBuf, sizeof(vrfyBuf), " ! ", flags);
    ((void)HiLogPrint(LOG_CORE, LOG_DEBUG, 0xD001100, "appverify", "[%s:%d]: ""%s", __FUNCTION__, 981, vrfyBuf));
}

static int32_t IsRevoked(const mbedtls_x509_crt *crt, const mbedtls_x509_crl *crl)
{
    mbedtls_x509_crl_entry *cur = (mbedtls_x509_crl_entry *)(&crl->entry);
    while (cur != ((void*)0)) {
        if (cur->serial.len == 0) {
            return PKCS7_SUCC;
        }
        if (crt->serial.len != cur->serial.len) {
            cur = cur->next;
            continue;
        }
        if (memcmp(crt->serial.p, cur->serial.p, cur->serial.len) == 0) {
            return PKCS7_IS_REVOKED;
        }
        cur = cur->next;
    }
    return PKCS7_SUCC;
}

static int32_t VerifyCrl(const mbedtls_x509_crt *crt, const mbedtls_x509_crl *crl)
{
    const mbedtls_x509_crl *crlList = crl;
    while (crlList != ((void*)0)) {
        if (crlList->version == 0 ||
            CompareX509NameList(&crlList->issuer, &crt->issuer) != 0) {
            crlList = crlList->next;
            continue;
        }
        ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""find crl", __FUNCTION__, 1012));
        if (IsRevoked(crt, crlList)) {
            return PKCS7_IS_REVOKED;
        }
        crlList = crlList->next;
    }
    return PKCS7_SUCC;
}

static int32_t VerifyClicert(mbedtls_x509_crt *clicert, mbedtls_x509_crt *rootCert, const Pkcs7 *pkcs7)
{
    uint32_t flags;
    int32_t rc = mbedtls_x509_crt_verify(clicert, rootCert,
        (mbedtls_x509_crl *)&pkcs7->signedData.crl, ((void*)0), &flags, ((void*)0), ((void*)0));
    if (rc) {
        DLogCrtVerifyInfo(flags);
    } else {
        ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""Verify signers cert chain root cert success", __FUNCTION__, 1029));
        if (VerifyCrl(clicert, (mbedtls_x509_crl *)&pkcs7->signedData.crl) != PKCS7_SUCC) {
            ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""cert crl verify failed", __FUNCTION__, 1031));
            return PKCS7_IS_REVOKED;
        }
        return PKCS7_SUCC;
    }
    return rc;
}

int32_t PKCS7_VerifyCertsChain(const Pkcs7 *pkcs7)
{
    if (pkcs7 == ((void*)0)) {
        return PKCS7_INVALID_PARAM;
    }
    int32_t cnt = 0;
    const SignerInfo *signer = &pkcs7->signedData.signers;
    while (signer != ((void*)0)) {
        mbedtls_x509_crt *clicert = signer->certPath.crt;
        if (clicert == ((void*)0)) {
            ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""Signer has no certs", __FUNCTION__, 1049));
            return PKCS7_HAS_NO_SIGNER_CRT;
        }
        int32_t rc;
        cnt++;
        ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""signer : %d", __FUNCTION__, 1054, cnt));
        if (g_debugModeEnabled) {
            rc = VerifyClicert(clicert, &g_debugModeRootCert, pkcs7);
            ((void)HiLogPrint(LOG_CORE, LOG_DEBUG, 0xD001100, "appverify", "[%s:%d]: ""Verify inner: %d", __FUNCTION__, 1057, rc));
            if (rc == PKCS7_SUCC) {
                signer = signer->next;
                continue;
            }
            if (rc == PKCS7_IS_REVOKED) {
                return PKCS7_IS_REVOKED;
            }
        }
        rc = VerifyClicert(clicert, signer->rootCert, pkcs7);
        ((void)HiLogPrint(LOG_CORE, LOG_DEBUG, 0xD001100, "appverify", "[%s:%d]: ""Verify : %d", __FUNCTION__, 1067, rc));
        if (rc == PKCS7_SUCC) {
            signer = signer->next;
            continue;
        }
        if (rc == PKCS7_IS_REVOKED) {
            return PKCS7_IS_REVOKED;
        }

        rc = VerifyClicert(clicert, &g_ohosRootCert, pkcs7);
        ((void)HiLogPrint(LOG_CORE, LOG_DEBUG, 0xD001100, "appverify", "[%s:%d]: ""Verify self : %d", __FUNCTION__, 1077, rc));
        if (rc == PKCS7_SUCC) {
            signer = signer->next;
            continue;
        }

        return rc;
    }
    return PKCS7_SUCC;
}

int32_t PKCS7_GetSignerSignningCertSubject(const SignerInfo *signer, char *subject, size_t subjectLen)
{
    int32_t rc;
    if (signer == ((void*)0) || subject == ((void*)0)) {
        return PKCS7_INVALID_PARAM;
    }
    const mbedtls_x509_crt *crt = signer->certPath.crt;
    rc = mbedtls_x509_dn_gets(subject, subjectLen, &crt->subject);
    if (rc < 0) {
        return rc;
    }
    return PKCS7_SUCC;
}

int32_t PKCS7_GetSignerSignningCertIssuer(const SignerInfo *signer, char *issuer, size_t issuerLen)
{
    int32_t rc;
    if (signer == ((void*)0) || issuer == ((void*)0)) {
        return PKCS7_INVALID_PARAM;
    }
    const mbedtls_x509_crt *crt = signer->certPath.crt;
    rc = mbedtls_x509_dn_gets(issuer, issuerLen, &crt->issuer);
    if (rc < 0) {
        return rc;
    }
    return PKCS7_SUCC;
}

static size_t GetSignersCnt(const SignerInfo *signers)
{
    size_t cnt = 0;
    while (signers != ((void*)0)) {
        cnt++;
        signers = signers->next;
    }
    return cnt;
}

static _Bool IsIncludeRoot(const SignerInfo *signer)
{
    mbedtls_x509_crt *pre = signer->certPath.crt;
    mbedtls_x509_crt *cur = pre;
    int32_t i = 0;
    while (i < signer->certPath.depth && cur != ((void*)0)) {
        pre = cur;
        cur = cur->next;
        i++;
    }

    if (pre == ((void*)0)) {
        return 0;
    }


    if (CompareX509NameList(&pre->issuer, &pre->subject) == 0) {
        ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""Include root cert", __FUNCTION__, 1143));
        return 1;
    }
    ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""Not include root cert", __FUNCTION__, 1146));
    return 0;
}

static int32_t GetSignerSignningCertDepth(const SignerInfo *signer)
{
    if (IsIncludeRoot(signer)) {
        return signer->certPath.depth;
    }


    return signer->certPath.depth + 1;
}

void PKCS7_FreeAllSignersResolvedInfo(SignersResovedInfo *sri)
{
    if (sri == ((void*)0)) {
        return;
    }
    if (sri->signers != ((void*)0)) {
        Pkcs7Free(sri->signers);
        sri->signers = ((void*)0);
    }
    Pkcs7Free(sri);
}

SignersResovedInfo *PKCS7_GetAllSignersResolvedInfo(const Pkcs7 *pkcs7)
{
    SignersResovedInfo *sri = ((void*)0);
    if (pkcs7 == ((void*)0)) {
        return ((void*)0);
    }
    size_t signersCnt = GetSignersCnt(&pkcs7->signedData.signers);
    if (signersCnt == 0) {
        return ((void*)0);
    }
    sri = Pkcs7Calloc(1, sizeof(*sri));
    if (sri == ((void*)0)) {
        return ((void*)0);
    }
    sri->nrOfSigners = signersCnt;
    sri->signers = Pkcs7Calloc(signersCnt, sizeof(SignerResovledInfo));
    if (sri->signers == ((void*)0)) {
        Pkcs7Free(sri);
        return ((void*)0);
    }
    int32_t rc;
    const SignerInfo *signer = &pkcs7->signedData.signers;
    int32_t idx = 0;
    while (signer != ((void*)0) && idx < signersCnt) {
        rc = PKCS7_GetSignerSignningCertSubject(signer, sri->signers[idx].subject, sizeof(sri->signers[idx].subject));
        if (rc) {
            goto OUT;
        }
        rc = PKCS7_GetSignerSignningCertIssuer(signer, sri->signers[idx].issuer, sizeof(sri->signers[idx].issuer));
        if (rc) {
            goto OUT;
        }
        sri->signers[idx].depth = GetSignerSignningCertDepth(signer);

        signer = signer->next;
        idx++;
    }
    return sri;
OUT:
    PKCS7_FreeAllSignersResolvedInfo(sri);
    return ((void*)0);
}

int32_t PKCS7_GetDigestInSignerAuthAttr(const SignerInfo *signer, unsigned char **dig, size_t *digLen)
{
    if (signer == ((void*)0) || dig == ((void*)0) || digLen == ((void*)0)) {
        return PKCS7_INVALID_VALUE;
    }
    unsigned char *p = signer->authAttr.p;
    if (p == ((void*)0)) {
        return PKCS7_HAS_NO_AUTH_ATTR_IN_SIGNER;
    }
    unsigned char *end = p + signer->authAttr.len;
    size_t tmpLen = 0;


    while (p < end) {
        size_t seqLen;
        unsigned char *seqEnd = ((void*)0);
        int32_t rc = mbedtls_asn1_get_tag(&p, end, &seqLen, 0x10 | 0x20);
        if (rc) {
            return rc;
        }
        seqEnd = p + seqLen;

        size_t oidLen;
        rc = mbedtls_asn1_get_tag(&p, seqEnd, &oidLen, 0x06);
        if (rc) {
            return rc;
        }
        if (oidLen == (sizeof("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x09" "\x04") - 1) &&
            memcmp(p, "\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x09" "\x04", (sizeof("\x2a" "\x86\x48" "\x86\xf7\x0d" "\x01" "\x09" "\x04") - 1)) == 0) {
            p += oidLen;
            rc = mbedtls_asn1_get_tag(&p, seqEnd, &tmpLen, 0x11 | 0x20);
            if (rc) {
                return rc;
            }

            rc = mbedtls_asn1_get_tag(&p, seqEnd, &tmpLen, 0x04);
            if (rc) {
                return rc;
            }
            *dig = p;
            *digLen = tmpLen;
            return PKCS7_SUCC;
        } else {
            p = seqEnd;
        }
    }
    return PKCS7_INVALID_VALUE;
}

int32_t PKCS7_GetSignerAuthAttr(const SignerInfo *signer, unsigned char **data, size_t *dataLen)
{
    if (signer == ((void*)0) || signer->authAttrRaw.p == ((void*)0) || data == ((void*)0) || dataLen == ((void*)0)) {
        return PKCS7_INVALID_VALUE;
    }
    *dataLen = signer->authAttrRaw.len;
    *data = signer->authAttrRaw.p;
    *(unsigned char *)signer->authAttrRaw.p = 0x20 | 0x11;
    return PKCS7_SUCC;
}

int32_t PKCS7_GetContentData(const Pkcs7 *pkcs7, unsigned char **data, size_t *dataLen)
{
    if (pkcs7 == ((void*)0) || data == ((void*)0) || dataLen == ((void*)0)) {
        return PKCS7_INVALID_PARAM;
    }

    unsigned char *p = pkcs7->signedData.content.data.p;
    size_t len = pkcs7->signedData.content.data.len;
    unsigned char *end = p + len;
    size_t octetLen;
    int32_t rc = mbedtls_asn1_get_tag(&p, end, &octetLen, 0x04);
    if (rc != 0) {
        return rc;
    }
    *data = p;
    *dataLen = octetLen;
    return PKCS7_SUCC;
}

int32_t PKCS7_EnableDebugMode(_Bool mode)
{
    if (g_debugModeEnabled == mode) {
        return PKCS7_SUCC;
    }
    int32_t rc = ((mode == 1) ? LoadDebugModeRootCert() : UnLoadDebugModeRootCert());
    if (rc) {
        return rc;
    }
    g_debugModeEnabled = mode;
    return PKCS7_SUCC;
}


static int32_t ParsePemFormatSignedData(const unsigned char *buf, size_t bufLen, mbedtls_pem_context *pem, char *format)
{
    if (bufLen != 0 && strstr((const char *)buf, "-----BEGIN PKCS7-----") != ((void*)0)) {
        int32_t ret;
        size_t useLen = 0;
        mbedtls_pem_init(pem);
        ret = mbedtls_pem_read_buffer(pem, "-----BEGIN PKCS7-----", "-----END PKCS7-----",
                                      buf, ((void*)0), 0, &useLen);
        if (ret == 0 && useLen == bufLen) {
            *format = 1;
            return PKCS7_SUCC;
        }
        mbedtls_pem_free(pem);
    } else {
        *format = 2;
        return PKCS7_SUCC;
    }
    return PKCS7_INVALID_PARAM;
}


int32_t PKCS7_ParseSignedData(const unsigned char *buf, size_t bufLen, Pkcs7 *pkcs7)
{
    int32_t rc;
    size_t len = 0;
    _Bool hasContent = 0;
    unsigned char *start = ((void*)0);
    unsigned char *end = ((void*)0);
    if (buf == ((void*)0) || bufLen == 0 || pkcs7 == ((void*)0)) {
        return PKCS7_INVALID_PARAM;
    }
    (void)memset_s(pkcs7, sizeof(*pkcs7), 0, sizeof(*pkcs7));
    start = (unsigned char *)buf;

    char format = 0;
    rc = ParsePemFormatSignedData(buf, bufLen, &pkcs7->pem, &format);
    if (rc) {
        goto EXIT;
    }
    if (format == 1) {
        start = pkcs7->pem.private_buf;
        bufLen = pkcs7->pem.private_buflen;
    }

    end = start + bufLen;

    rc = LoadRootCert();
    do { if ((rc) != V_OK) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""rc"" not ok", __FUNCTION__, 1355)); goto EXIT; } } while (0);

    rc = LoadSelfSignedCert();
    do { if ((rc) != V_OK) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""rc"" not ok", __FUNCTION__, 1358)); goto EXIT; } } while (0);

    ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""Begin to parse pkcs#7 signed data", __FUNCTION__, 1360));

    rc = GetContentInfoType(&start, end, &(pkcs7->contentTypeOid), &hasContent);
    do { if ((rc) != V_OK) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""rc"" not ok", __FUNCTION__, 1363)); goto EXIT; } } while (0);
    if (!IsSigedDataOid(pkcs7) || !hasContent) {
        rc = PKCS7_INVALID_CONTENT_TYPE_OR_NO_CONTENT;
        ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""Input data is not pkcs#7 signed data format or has no content info", __FUNCTION__, 1366));
        goto EXIT;
    }
    rc = GetContentLenOfContentInfo(&start, end, &len);
    do { if ((rc) != V_OK) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""rc"" not ok", __FUNCTION__, 1370)); goto EXIT; } } while (0);
    if (start + len > end) {
        rc = PKCS7_INVALID_CONTENT_TYPE_OR_NO_CONTENT;
        ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""The length of input data is invalid", __FUNCTION__, 1373));
        goto EXIT;
    }
    rc = ParseSignedData(start, len, &(pkcs7->signedData));
    do { if ((rc) != V_OK) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""rc"" not ok", __FUNCTION__, 1377)); goto EXIT; } } while (0);
    ((void)HiLogPrint(LOG_CORE, LOG_INFO, 0xD001100, "appverify", "[%s:%d]: ""Parse pkcs#7 signed data success", __FUNCTION__, 1378));
    rc = ConstructSignerCerts(&pkcs7->signedData);
    do { if ((rc) != V_OK) { ((void)HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, "appverify", "[%s:%d]: ""rc"" not ok", __FUNCTION__, 1380)); goto EXIT; } } while (0);
    return rc;
EXIT:
    return rc;
}

void PKCS7_FreeRes(Pkcs7 *pkcs7)
{
    if (pkcs7 == ((void*)0)) {
        return;
    }
    FreeSignedDataDigestAlgs(pkcs7);
    FreeSignersInfo(pkcs7);
    FreeSignedDataCerts(pkcs7);
    FreeSignedDataCrl(pkcs7);
    UnLoadRootCert();

    UnLoadSelfSignedCert();

}
