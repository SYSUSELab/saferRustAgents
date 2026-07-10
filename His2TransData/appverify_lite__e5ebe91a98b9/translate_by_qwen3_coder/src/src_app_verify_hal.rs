//! Module: src_app_verify_hal
//!
//! Auto-generated skeleton - function bodies are unimplemented.

#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(unused_variables)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

use crate::types::*;
use crate::globals::*;
use crate::compat::*;

// === C2R_FILE_STATICS_BEGIN ===
// File-scope `static` variables (internal linkage) from the original C TU.
// These are module-local by design (Scheme B).
/// C: static ProductDiff g_productDiffFunc
static mut g_productDiffFunc: crate::types::ProductDiff = unsafe { core::mem::MaybeUninit::<crate::types::ProductDiff>::zeroed().assume_init() };

// === C2R_FILE_STATICS_END ===

pub extern "C" fn RegistHalFunc() {
    unsafe {
        crate::products_default_app_verify_default::RegistBaseDefaultFunc(
            &mut crate::globals::g_productDiffFunc as *mut _ as *mut crate::types::ProductDiff
        );
        crate::products_ipcamera_app_verify_base::RegistProductFunc(
            &mut crate::globals::g_productDiffFunc as *mut _ as *mut crate::types::ProductDiff
        );
    }
}

pub extern "C" fn InquiryDeviceUdid(udid: *mut ::core::ffi::c_uchar, size: i32) -> i32 {
    crate::types::INQUIRY_UDID_ERROR
}
