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

// Source: bindgen on preprocessed TU
pub static mut APP_GALLERY: [::core::ffi::c_char; 12usize] = unsafe { MaybeUninit::<[::core::ffi::c_char; 12usize]>::zeroed().assume_init() };

// Source: bindgen on preprocessed TU
pub static mut ENTERPRISE: [::core::ffi::c_char; 11usize] = unsafe { MaybeUninit::<[::core::ffi::c_char; 11usize]>::zeroed().assume_init() };

// Source: bindgen on preprocessed TU
pub static mut ENTERPRISE_MDM: [::core::ffi::c_char; 15usize] = unsafe { MaybeUninit::<[::core::ffi::c_char; 15usize]>::zeroed().assume_init() };

// Source: bindgen on preprocessed TU
pub static mut ENTERPRISE_NORMAL: [::core::ffi::c_char; 18usize] = unsafe { MaybeUninit::<[::core::ffi::c_char; 18usize]>::zeroed().assume_init() };

// Source: bindgen on preprocessed TU
pub static mut INTERNALTESTING: [::core::ffi::c_char; 16usize] = unsafe { MaybeUninit::<[::core::ffi::c_char; 16usize]>::zeroed().assume_init() };

// Source: bindgen on preprocessed TU
pub static mut OS_INTEGRATION: [::core::ffi::c_char; 15usize] = unsafe { MaybeUninit::<[::core::ffi::c_char; 15usize]>::zeroed().assume_init() };
// === C2R_AUTO_MISSING_GLOBALS_BEGIN ===
/// C2R_AUTO_GLOBAL: placeholder for `g_memoryPageSize`
pub static mut g_memoryPageSize: i32 = 0;


/// C2R_AUTO_GLOBAL: placeholder for `g_trustAppList`
pub static mut g_trustAppList: i32 = 0;


/// C2R_AUTO_GLOBAL: placeholder for `g_isActsMode`
pub static mut g_isActsMode: i32 = 0;


/// C2R_AUTO_GLOBAL: placeholder for `g_productDiffFunc`
pub static mut g_productDiffFunc: i32 = 0;


/// C2R_AUTO_GLOBAL: placeholder for `g_rootCaG2Cert`
pub static mut g_rootCaG2Cert: i32 = 0;

/// C2R_AUTO_GLOBAL: placeholder for `g_rootCertLoaded`
pub static mut g_rootCertLoaded: i32 = 0;


/// C2R_AUTO_GLOBAL: placeholder for `g_debugModeRootCert`
pub static mut g_debugModeRootCert: i32 = 0;


/// C2R_AUTO_GLOBAL: placeholder for `g_ohosRootCert`
pub static mut g_ohosRootCert: i32 = 0;


/// C2R_AUTO_GLOBAL: placeholder for `g_isDebugMode`
pub static mut g_isDebugMode: i32 = 0;

/// C2R_AUTO_GLOBAL: placeholder for `g_trustAppListTest`
pub static mut g_trustAppListTest: i32 = 0;


/// C2R_AUTO_GLOBAL: placeholder for `g_debugModeEnabled`
pub static mut g_debugModeEnabled: i32 = 0;

// === C2R_AUTO_MISSING_GLOBALS_END ===
