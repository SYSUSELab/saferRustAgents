//! Global and Static Variable Declarations (Scheme A: bindgen-truth static storage)
//!
//! - No safe wrappers (Mutex/RwLock).
//! - Types are derived from bindgen on the exact preprocessed `.i` TU.
//! - Storage is real Rust `static mut`, zero-initialized (C-like).
//! - NOTE: file-scope `static` (internal linkage) variables are emitted in each module file (Scheme B).

#![allow(non_upper_case_globals)]
#![allow(non_snake_case)]
#![allow(dead_code)]
#![allow(unused)]

use core::mem::MaybeUninit;
use crate::types::*;

// ==========================================
// Global Variables (top-level)
// ==========================================

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: DevHostServiceClntNewInstance

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: DeviceAttributeDeserialize

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: DeviceResourceGetIfaceInstance

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: GetLastFatalMessage

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HcsGetChildNode

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HcsGetNodeByMatchAttr

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HcsGetNodeByRefAttr

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HcsGetRootNode

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfDeviceCreate

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfDeviceInfoNewInstance

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfDeviceNewInstance

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfGetHcsRootNode

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSListGetLast

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSListIteratorNext

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSListNext

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSListPeek

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSListPop

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSListSearch

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufBind

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufCopy

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufGetData

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufGetImpl

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufMove

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufObtain

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufObtainDefaultSize

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufReadRemoteService

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufReadString

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufReadString16

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufReadUnpadBuffer

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufTypedBind

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufTypedObtain

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufTypedObtainCapacity

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfSbufTypedObtainInplace

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: MapGet

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: OsalMemAlloc

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: OsalMemAllocAlign

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: OsalMemCalloc

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: ___errno_location

// Source: bindgen on preprocessed TU
pub static mut __environ: *mut *mut ::core::ffi::c_char = unsafe { MaybeUninit::<*mut *mut ::core::ffi::c_char>::zeroed().assume_init() };

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __errno_location

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __libc_calloc

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __libc_malloc

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __libc_malloc_impl

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __libc_realloc

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __memchr_chk

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __memrchr

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __memrchr_chk

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __randname

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __stpcpy

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __stpncpy

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __strchr_chk

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __strchrnul

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: __strrchr_chk

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: aligned_alloc

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: alloca

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: basename

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: bsearch

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: calloc

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: crypt

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: ctermid

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: cuserid

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: ecvt

// Source: bindgen on preprocessed TU
pub static mut environ: *mut *mut ::core::ffi::c_char = unsafe { MaybeUninit::<*mut *mut ::core::ffi::c_char>::zeroed().assume_init() };

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: fcvt

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: fdopen

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: fdsan_get_fd_table

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: fdsan_get_tag_type

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: fgetln

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: fgets

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: fgets_unlocked

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: fmemopen

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: fopen

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: fopencookie

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: freopen

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: gcvt

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: get_current_dir_name

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: getcwd

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: getenv

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: getlogin

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: getpass

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: getusershell

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: initstate

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: l64a

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: malloc

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: memalign

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: memccpy

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: memchr

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: memcpy

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: memmem

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: memmove

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: mempcpy

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: memrchr

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: memset

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: mkdtemp

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: mktemp

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: open_memstream

// Source: bindgen on preprocessed TU
pub static mut optarg: *mut ::core::ffi::c_char = unsafe { MaybeUninit::<*mut ::core::ffi::c_char>::zeroed().assume_init() };

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: popen

// Source: bindgen on preprocessed TU
pub static mut program_invocation_name: *mut ::core::ffi::c_char = unsafe { MaybeUninit::<*mut ::core::ffi::c_char>::zeroed().assume_init() };

// Source: bindgen on preprocessed TU
pub static mut program_invocation_short_name: *mut ::core::ffi::c_char = unsafe { MaybeUninit::<*mut ::core::ffi::c_char>::zeroed().assume_init() };

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: ptsname

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: realloc

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: reallocarray

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: realpath

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: sbrk

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: secure_getenv

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: seed48

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: setstate

// Source: bindgen on preprocessed TU
pub static mut stderr: *mut crate::types::FILE = unsafe { MaybeUninit::<*mut crate::types::FILE>::zeroed().assume_init() };

// Source: bindgen on preprocessed TU
pub static mut stdin: *mut crate::types::FILE = unsafe { MaybeUninit::<*mut crate::types::FILE>::zeroed().assume_init() };

// Source: bindgen on preprocessed TU
pub static mut stdout: *mut crate::types::FILE = unsafe { MaybeUninit::<*mut crate::types::FILE>::zeroed().assume_init() };

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: stpcpy

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: stpncpy

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strcasestr

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strcat

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strchr

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strchrnul

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strcpy

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strdup

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strerror

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strerror_l

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strncat

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strncpy

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strndup

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strpbrk

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strrchr

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strsep

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strsignal

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strstr

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strtok

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: strtok_r

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: tempnam

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: tmpfile

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: tmpnam

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: ttyname

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: valloc

// ==========================================
// Lifted Static Variables (from functions)
// ==========================================

// From function: GetConfigFilePath()
/// Originally: static const char adapterConfigPath
pub static mut GetConfigFilePath_adapterConfigPath: *const std::ffi::c_char = unsafe { MaybeUninit::<*const std::ffi::c_char>::zeroed().assume_init() };
