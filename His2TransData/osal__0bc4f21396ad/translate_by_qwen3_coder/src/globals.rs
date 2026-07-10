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
// MISSING: HdfIoServiceBind

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: HdfIoServiceGroupObtain

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
// MISSING: OsalMemAlloc

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: OsalMemAllocAlign

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: OsalMemCalloc

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: basename

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: ctermid

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: cuserid

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: fdopen

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
// MISSING: open_memstream

// Source: bindgen missing (declaration omitted; see globals_generation_report.json)
// MISSING: popen

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
