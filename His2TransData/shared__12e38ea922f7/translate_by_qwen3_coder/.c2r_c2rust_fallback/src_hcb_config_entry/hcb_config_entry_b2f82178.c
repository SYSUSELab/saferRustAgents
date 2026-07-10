# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/uhdf2/shared/src/hcb_config_entry.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 391 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/uhdf2/shared/src/hcb_config_entry.c" 2
# 16 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/uhdf2/shared/src/hcb_config_entry.c"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/unistd.h" 1



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/unistd.h" 1







# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/features.h" 1



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/features.h" 1
# 5 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/features.h" 2
# 9 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/unistd.h" 2
# 47 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/unistd.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 75 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned int size_t;
# 126 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef int ssize_t;




typedef int intptr_t;
# 213 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef long long off_t;
typedef long long loff_t;
typedef off_t off64_t;
# 294 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef int pid_t;
# 304 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned uid_t;




typedef unsigned gid_t;
# 319 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned useconds_t;
# 48 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/unistd.h" 2

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
# 115 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/unistd.h"
int chdir(const char *);
int fchdir(int);
char *getcwd(char *, size_t);

unsigned alarm(unsigned);
unsigned sleep(unsigned);
int pause(void);

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
# 145 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/unistd.h"
pid_t getprocpid(void);
# 156 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/unistd.h"
pid_t getproctid(void);
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
# 320 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/unistd.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/posix.h" 1
# 321 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/unistd.h" 2
# 549 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/unistd.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/linux/user/include/fortify/unistd.h" 1
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/linux/user/include/fortify/unistd.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/linux/user/include/fortify/fortify.h" 1
# 131 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/linux/user/include/fortify/fortify.h"
void __fortify_error(const char* info, ...);
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/linux/user/include/fortify/unistd.h" 2
# 550 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/unistd.h" 2
# 5 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/unistd.h" 2

extern char **__environ;

__attribute__((__visibility__("hidden"))) int __dup3(int, int, int);
__attribute__((__visibility__("hidden"))) int __mkostemps(char *, int, int);
__attribute__((__visibility__("hidden"))) int __execvpe(const char *, char *const *, char *const *);
__attribute__((__visibility__("hidden"))) off_t __lseek(int, off_t, int);
# 17 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/uhdf2/shared/src/hcb_config_entry.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h" 1
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securectype.h" 1
# 312 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securectype.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/stdio.h" 1





# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdio.h" 1








# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdint.h" 1
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdint.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 116 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned int uintptr_t;
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
# 10 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdio.h" 2
# 27 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdio.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 29 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef __builtin_va_list va_list;




typedef __builtin_va_list __isoc_va_list;
# 355 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef struct _IO_FILE FILE;
# 28 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdio.h" 2
# 57 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdio.h"
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
# 225 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdio.h"
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


# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/linux/user/include/fortify/stdio.h" 1
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/linux/user/include/fortify/stdio.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdarg.h" 1
# 10 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdarg.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 11 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdarg.h" 2
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/linux/user/include/fortify/stdio.h" 2
# 270 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdio.h" 2
# 7 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/stdio.h" 2





extern __attribute__((__visibility__("hidden"))) FILE __stdin_FILE;
extern __attribute__((__visibility__("hidden"))) FILE __stdout_FILE;
extern __attribute__((__visibility__("hidden"))) FILE __stderr_FILE;
# 313 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securectype.h" 2


# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/string.h" 1



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/string.h" 1
# 25 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/string.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 345 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef struct __locale_struct *locale_t;
# 26 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/string.h" 2

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
# 60 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/string.h" 2





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




int strverscmp (const char *, const char *);
char *strchrnul(const char *, int);
char *strcasestr(const char *, const char *);
void *memrchr(const void *, int, size_t);
void *mempcpy(void *, const void *, size_t);

char *basename();




# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/linux/user/include/fortify/string.h" 1
# 26 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/linux/user/include/fortify/string.h"
void *__memchr_chk(const void* s, int c, size_t n, size_t actual_size);
void *__memrchr_chk(const void*, int, size_t, size_t);
size_t __strlcpy_chk(char*, const char*, size_t, size_t);
size_t __strlcat_chk(char*, const char*, size_t, size_t);
char *__strchr_chk(const char* p, int ch, size_t s_len);
char *__strrchr_chk(const char *p, int ch, size_t s_len);
size_t __strlen_chk(const char* s, size_t s_len);
# 105 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/string.h" 2
# 5 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/string.h" 2

__attribute__((__visibility__("hidden"))) void *__memrchr(const void *, int, size_t);
__attribute__((__visibility__("hidden"))) char *__stpcpy(char *, const char *);
__attribute__((__visibility__("hidden"))) char *__stpncpy(char *, const char *, size_t);
__attribute__((__visibility__("hidden"))) char *__strchrnul(const char *, int);
# 316 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securectype.h" 2


# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/stdlib.h" 1



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdlib.h" 1
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdlib.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 41 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef unsigned wchar_t;
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdlib.h" 2

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
# 106 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdlib.h"
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
# 146 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdlib.h" 2
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
float strtof_l(const char *restrict, char **restrict, struct __locale_struct *);
double strtod_l(const char *restrict, char **restrict, struct __locale_struct *);
long double strtold_l(const char *restrict, char **restrict, struct __locale_struct *);
# 181 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdlib.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/linux/user/include/fortify/stdlib.h" 1
# 182 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/stdlib.h" 2
# 5 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/stdlib.h" 2

__attribute__((__visibility__("hidden"))) int __putenv(char *, size_t, char *);
__attribute__((__visibility__("hidden"))) void __env_rm_add(char *, char *);
__attribute__((__visibility__("hidden"))) int __mkostemps(char *, int, int);
__attribute__((__visibility__("hidden"))) int __ptsname_r(int, char *, size_t);
__attribute__((__visibility__("hidden"))) char *__randname(char *);
__attribute__((__visibility__("hidden"))) void __qsort_r (void *, size_t, size_t, int (*)(const void *, const void *, void *), void *);

__attribute__((__visibility__("hidden"))) void *__libc_malloc(size_t);
__attribute__((__visibility__("hidden"))) void *__libc_malloc_impl(size_t);
__attribute__((__visibility__("hidden"))) void *__libc_calloc(size_t, size_t);
__attribute__((__visibility__("hidden"))) void *__libc_realloc(void *, size_t);
__attribute__((__visibility__("hidden"))) void __libc_free(void *);
# 319 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securectype.h" 2
# 371 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securectype.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stddef.h" 1
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stddef.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h" 1
# 59 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef struct { long long __ll; long double __ld; } max_align_t;
# 121 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/alltypes.h"
typedef int ptrdiff_t;
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stddef.h" 2
# 372 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securectype.h" 2
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h" 2
# 39 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/errno.h" 1



# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/errno.h" 1
# 10 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/errno.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/bits/errno.h" 1
# 11 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/../../include/errno.h" 2


__attribute__((const))

int *__errno_location(void);



extern char *program_invocation_short_name, *program_invocation_name;
# 5 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/src/include/errno.h" 2


__attribute__((const))

__attribute__((__visibility__("hidden"))) int *___errno_location(void);
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
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/uhdf2/shared/src/hcb_config_entry.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hcs_dm_parser.h" 1
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hcs_dm_parser.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h" 1
# 36 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h" 1
# 33 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/uhdf/hdf_types.h" 1
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/uhdf/hdf_types.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/porting/liteos_a/kernel/include/stdbool.h" 1
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/uhdf/hdf_types.h" 2



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
# 42 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/kernel/liteos_a/kernel/include/los_typedef.h"
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
# 24 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/uhdf/hdf_types.h" 2
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
# 37 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h" 2
# 47 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
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
# 88 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
struct DeviceResourceIface {
# 100 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    const struct DeviceResourceNode *(*GetRootNode)(void);
# 112 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    _Bool (*GetBool)(const struct DeviceResourceNode *node, const char *attrName);
# 126 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetUint8)(const struct DeviceResourceNode *node, const char *attrName, uint8_t *value, uint8_t def);
# 142 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetUint8ArrayElem)(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
        uint8_t *value, uint8_t def);
# 162 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetUint8Array)(const struct DeviceResourceNode *node, const char *attrName, uint8_t *value, uint32_t len,
        uint8_t def);
# 177 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetUint16)(const struct DeviceResourceNode *node, const char *attrName, uint16_t *value, uint16_t def);
# 192 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetUint16ArrayElem)(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
        uint16_t *value, uint16_t def);
# 211 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetUint16Array)(const struct DeviceResourceNode *node, const char *attrName, uint16_t *value,
        uint32_t len, uint16_t def);
# 226 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetUint32)(const struct DeviceResourceNode *node, const char *attrName, uint32_t *value, uint32_t def);
# 241 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetUint32ArrayElem)(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
        uint32_t *value, uint32_t def);
# 260 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetUint32Array)(const struct DeviceResourceNode *node, const char *attrName, uint32_t *value,
        uint32_t len, uint32_t def);
# 275 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetUint64)(const struct DeviceResourceNode *node, const char *attrName, uint64_t *value, uint64_t def);
# 290 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetUint64ArrayElem)(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
        uint64_t *value, uint64_t def);
# 306 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetUint64Array)(const struct DeviceResourceNode *node, const char *attrName, uint64_t *value,
        uint32_t len, uint64_t def);
# 322 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetString)(const struct DeviceResourceNode *node, const char *attrName, const char **value,
        const char *def);
# 339 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetStringArrayElem)(const struct DeviceResourceNode *node, const char *attrName, uint32_t index,
        const char **value, const char *def);
# 352 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    int32_t (*GetElemNum)(const struct DeviceResourceNode *node, const char *attrName);
# 370 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    const struct DeviceResourceNode *(*GetNodeByMatchAttr)(const struct DeviceResourceNode *node,
        const char *attrValue);
# 382 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    const struct DeviceResourceNode *(*GetChildNode)(const struct DeviceResourceNode *node, const char *nodeName);
# 398 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
    const struct DeviceResourceNode *(*GetNodeByRefAttr)(const struct DeviceResourceNode *node, const char *attrName);
};
# 412 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/device_resource_if.h"
struct DeviceResourceIface *DeviceResourceGetIfaceInstance(DeviceResourceType type);
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hcs_dm_parser.h" 2







void SetHcsBlobPath(const char *path);
void ReleaseHcsTree(void);
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/uhdf2/shared/src/hcb_config_entry.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hcs_tree_if.h" 1
# 23 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hcs_tree_if.h"
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
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/uhdf2/shared/src/hcb_config_entry.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/shared/include/hdf_attribute_manager.h" 1
# 12 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/shared/include/hdf_attribute_manager.h"
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
# 13 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/shared/include/hdf_attribute_manager.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/manager/include/devhost_service_clnt.h" 1
# 12 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/manager/include/devhost_service_clnt.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/shared/include/devhost_service_if.h" 1
# 12 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/shared/include/devhost_service_if.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device.h" 1
# 12 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_dlist.h" 1
# 44 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_dlist.h"
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
# 13 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/shared/include/devhost_service_if.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_info.h" 1
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_info.h"
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
# 14 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/shared/include/devhost_service_if.h" 2

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
# 16 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/shared/include/devhost_service_if.h" 2

struct IDevHostService {
    struct HdfObject object;
    int (*AddDevice)(struct IDevHostService *hostService, const struct HdfDeviceInfo *devInfo);
    int (*DelDevice)(struct IDevHostService *hostService, devid_t devId);
    int (*StartService)(struct IDevHostService *hostService);
    int (*PmNotify)(struct IDevHostService *service, uint32_t powerState);
    int (*Dump)(struct IDevHostService *hostService, struct HdfSBuf *data, struct HdfSBuf *reply);
};
# 13 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/manager/include/devhost_service_clnt.h" 2

# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_map.h" 1
# 18 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_map.h"
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
# 15 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/manager/include/devhost_service_clnt.h" 2
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
# 16 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/manager/include/devhost_service_clnt.h" 2

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
# 14 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/shared/include/hdf_attribute_manager.h" 2

const struct DeviceResourceNode *HdfGetHcsRootNode(void);
_Bool HdfAttributeManagerGetHostList(struct HdfSList *hostList);
int HdfAttributeManagerGetDeviceList(struct DevHostServiceClnt *hostClnt);
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/uhdf2/shared/src/hcb_config_entry.c" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_log.h" 1
# 48 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_log.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/uhdf/hdf_log_adapter.h" 1
# 39 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/uhdf/hdf_log_adapter.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog/interfaces/native/innerkits/include/hilog/log.h" 1
# 19 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog/interfaces/native/innerkits/include/hilog/log.h"
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog/interfaces/native/innerkits/include/hilog/log_c.h" 1
# 43 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog/interfaces/native/innerkits/include/hilog/log_c.h"
typedef enum {

    LOG_TYPE_MIN = 0,

    LOG_APP = 0,

    LOG_INIT = 1,

    LOG_CORE = 3,

    LOG_KMSG = 4,

    LOG_ONLY_PRERELEASE = 5,

    LOG_TYPE_MAX
} LogType;


typedef enum {

    LOG_LEVEL_MIN = 0,

    LOG_DEBUG = 3,

    LOG_INFO = 4,

    LOG_WARN = 5,

    LOG_ERROR = 6,

    LOG_FATAL = 7,

    LOG_LEVEL_MAX,
} LogLevel;




const char* GetLastFatalMessage(void);







int HiLogPrint(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...)
    __attribute__((__format__(os_log, 5, 6)));
# 124 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog/interfaces/native/innerkits/include/hilog/log_c.h"
_Bool HiLogIsLoggable(unsigned int domain, const char *tag, LogLevel level);
# 137 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog/interfaces/native/innerkits/include/hilog/log_c.h"
typedef void (*LogCallback)(const LogType type, const LogLevel level, const unsigned int domain, const char *tag,
    const char *msg);
# 152 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog/interfaces/native/innerkits/include/hilog/log_c.h"
void LOG_SetCallback(LogCallback callback);
# 20 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog/interfaces/native/innerkits/include/hilog/log.h" 2
# 1 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog/interfaces/native/innerkits/include/hilog/log_cpp.h" 1
# 21 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/base/hiviewdfx/hilog/interfaces/native/innerkits/include/hilog/log.h" 2
# 40 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/uhdf/hdf_log_adapter.h" 2
# 49 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_log.h" 2
# 22 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/uhdf2/shared/src/hcb_config_entry.c" 2
# 34 "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/adapter/uhdf2/shared/src/hcb_config_entry.c"
static int GetProductName(char *name, int maxLen)
{
    return strcpy_s(name, maxLen, "default");
}

static _Bool GetConfigFilePath(const char *productName, char *configPath, size_t configPathLen)
{
    static const char *adapterConfigPath[] = {
        "/vendor/etc/hdfconfig",
        "/chip_prod/etc/hdfconfig",
    };

    size_t pathNum = sizeof(adapterConfigPath) / sizeof(adapterConfigPath[0]);
    for (size_t i = 0; i < pathNum; ++i) {
        if (sprintf_s(configPath, configPathLen - 1, "%s/hdf_%s.hcb", adapterConfigPath[i], productName) < 0) {
            ((void)HiLogPrint((LOG_CORE), LOG_ERROR, 0xD002510, "attribute_manager", "failed to generate file path"));
            continue;
        }

        if (access(configPath, 0 | 4) == 0) {
            return 1;
        }
        ((void)HiLogPrint((LOG_CORE), LOG_DEBUG, 0xD002510, "attribute_manager", "invalid config file path or permission:%{public}s", configPath));
    }
    return 0;
}

const struct DeviceResourceNode *HdfGetHcsRootNode(void)
{
    char productName[128] = { 0 };
    char configPath[256] = { 0 };

    int ret = GetProductName(productName, 128);
    if (ret != HDF_SUCCESS) {
        return ((void*)0);
    }

    if (!GetConfigFilePath(productName, configPath, 256)) {
        ((void)HiLogPrint((LOG_CORE), LOG_ERROR, 0xD002510, "attribute_manager", "failed to get config file path"));
        return ((void*)0);
    }

    SetHcsBlobPath(configPath);
    const struct DeviceResourceNode *mgrRoot = HcsGetRootNode();
    return mgrRoot;
}
