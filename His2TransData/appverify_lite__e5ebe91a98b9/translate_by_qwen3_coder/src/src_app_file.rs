//! Module: src_app_file
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
/// C: static int32_t g_memoryPageSize
static mut g_memoryPageSize: i32 = 0;

// === C2R_FILE_STATICS_END ===

// === C2R MANUAL FIX REQUIRED ===
// reason: repair_failed_after_5
// func_key: src_app_file_1
// c_function: InitVerify
// rust_file: src_app_file.rs
// rust_signature: pub extern "C" fn InitVerify(file: *mut crate::types::FileRead, filePath: *const ::core::ffi::c_char, handle: *mut i32) -> i32
// c_first_line: int32_t InitVerify(FileRead *file, const char *filePath, int32_t *handle)
// saved_translation: /data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5_reuseS1_topk1/intermediate/appverify_lite__e5ebe91a98b9/workspace/repair_history/appverify_lite__e5ebe91a98b9/translate_by_qwen3_coder/_manual_fix/src_app_file_1/translated_rust.rs
// last_error_truncated:
//   error[E0308]: mismatched types
//     --> src/src_app_file.rs:60:48
//      |
//      |                                                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ expected `i32`, found `i64`
//      |
//      |
//      |                                  --- expected due to this type
//   error: could not compile `appverify_lite__e5ebe91a98b9` (bin "appverify_lite__e5ebe91a98b9") due to 1 previous error; 5 warnings emitted
// =================================
pub extern "C" fn InitVerify(file: *mut crate::types::FileRead, filePath: *const ::core::ffi::c_char, handle: *mut i32) -> i32 {
    // C2R: C2Rust fallback (LLM failed; wrapper keeps skeleton signature)
    unsafe { crate::compat::__c2rust_fallback::src_app_file::InitVerify(file as _, filePath as _, handle as _) as _ }
}
/* === C2R_LLM_FAILED_OUTPUT_BEGIN ===
 * func_key: src_app_file_1
 * reason: repair_failed_after_5
 * saved_translation: /data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5_reuseS1_topk1/intermediate/appverify_lite__e5ebe91a98b9/workspace/repair_history/appverify_lite__e5ebe91a98b9/translate_by_qwen3_coder/_manual_fix/src_app_file_1/translated_rust.rs
 * ------------------------------------------------------------
pub extern "C" fn InitVerify(file: *mut crate::types::FileRead, filePath: *const ::core::ffi::c_char, handle: *mut i32) -> i32 {
    if handle.is_null() || file.is_null() || filePath.is_null() {
        return crate::types::V_ERR_FILE_OPEN as i32;
    }
    
    crate::src_app_verify_hal::RegistHalFunc();
    
    let path = unsafe { libc::malloc((crate::types::PATH_MAX + 1) as usize) } as *mut ::core::ffi::c_char;
    if path.is_null() {
        return crate::types::V_ERR_MALLOC as i32;
    }
    
    let file_path_len = unsafe { libc::strlen(filePath) };
    if file_path_len > crate::types::PATH_MAX as usize || unsafe { libc::realpath(filePath, path) }.is_null() {
        unsafe {
            if !path.is_null() {
                libc::free(path as *mut ::core::ffi::c_void);
            }
        }
        return crate::types::V_ERR_FILE_OPEN as i32;
    }
    
    unsafe {
        *handle = libc::open(path, libc::O_RDONLY, 0);
    }
    
    if unsafe { *handle } < 0 {
        unsafe {
            if !path.is_null() {
                libc::free(path as *mut ::core::ffi::c_void);
            }
        }
        return crate::types::V_ERR_FILE_OPEN as i32;
    }
    
    unsafe {
        if crate::globals::g_memoryPageSize == 0 {
            crate::globals::g_memoryPageSize = libc::sysconf(libc::_SC_PAGESIZE);
        }
    }
    
    if unsafe { crate::globals::g_memoryPageSize } <= 0 {
        unsafe {
            if !path.is_null() {
                libc::free(path as *mut ::core::ffi::c_void);
            }
        }
        return crate::types::V_ERR_FILE_STAT as i32;
    }
    
    unsafe {
        let handle_val: i32 = *handle;
        let len_result = libc::lseek(handle_val, 0 as libc::off_t, crate::types::SEEK_END as i32);
        (*file).len = len_result as i32;
        (*file).fp = handle_val;
    }
    
    unsafe {
        if !path.is_null() {
            libc::free(path as *mut ::core::ffi::c_void);
        }
    }
    
    crate::types::V_OK as i32
}
 * ------------------------------------------------------------
 * C2R_LLM_FAILED_OUTPUT_BEGIN func_key: src_app_file_1
 * === C2R_LLM_FAILED_OUTPUT_END === */


pub extern "C" fn HapMMap(bufCapacity: i32, offset: i32, mmapInfo: *mut crate::types::MmapInfo, file: *const crate::types::FileRead) -> i32 {
    unsafe {
        if mmapInfo.is_null() || file.is_null() || bufCapacity <= 0 {
            return crate::types::MMAP_FAILED;
        }
        
        (*mmapInfo).mapAddr = (-1isize) as *mut ::core::ffi::c_char;
        
        if (*file).fp == -1 {
            return crate::types::FILE_IS_CLOSE;
        }
        
        if offset < 0 || offset > (*file).len - bufCapacity {
            return crate::types::READ_OFFSET_OUT_OF_RANGE;
        }
        
        libc::lseek((*file).fp, offset as libc::off_t, 0);
        
        if crate::globals::g_memoryPageSize == 0 {
            return crate::types::MMAP_FAILED;
        }
        
        (*mmapInfo).mmapPosition = (offset / crate::globals::g_memoryPageSize) * crate::globals::g_memoryPageSize;
        (*mmapInfo).readMoreLen = offset - (*mmapInfo).mmapPosition;
        (*mmapInfo).mmapSize = bufCapacity + (*mmapInfo).readMoreLen;
        
        (*mmapInfo).mapAddr = libc::mmap(
            std::ptr::null_mut(),
            (*mmapInfo).mmapSize as usize,
            libc::PROT_READ,
            libc::MAP_SHARED,
            (*file).fp,
            (*mmapInfo).mmapPosition as libc::off_t
        ) as *mut ::core::ffi::c_char;
        
        if (*mmapInfo).mapAddr == (-1isize) as *mut ::core::ffi::c_char {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: MAP_FAILED\0".as_ptr() as *const ::core::ffi::c_char,
                b"HapMMap\0".as_ptr() as *const ::core::ffi::c_char,
                88i32
            );
            return crate::types::MMAP_FAILED;
        }
        
        crate::types::V_OK as i32
    }
}

pub extern "C" fn HapMUnMap(mapAddr: *mut ::core::ffi::c_char, mmapSize: i32) {
    if mapAddr.is_null() || mmapSize <= 0 {
        return;
    }
    unsafe {
        libc::munmap(mapAddr as *mut ::core::ffi::c_void, mmapSize as usize);
    }
}
