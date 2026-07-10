//! Module: src_hdf_load_vdi
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

pub extern "C" fn HdfLoadVdi(libName: *const ::core::ffi::c_char) -> *mut crate::types::HdfVdiObject {
    use crate::types::{HdfVdiObject, HdfVdiBase, LOG_CORE, LOG_ERROR};
    
    let mut path: [::core::ffi::c_char; 4097] = [0; 4097];
    let mut resolvedPath: [::core::ffi::c_char; 4097] = [0; 4097];
    
    if libName.is_null() {
        return std::ptr::null_mut();
    }
    
    let vendor_lib = b"/vendor/lib/\0".as_ptr() as *const ::core::ffi::c_char;
    let format = b"%s/%s\0".as_ptr() as *const ::core::ffi::c_char;
    
    unsafe {
        let ret = crate::compat::snprintf_s(
            path.as_mut_ptr(),
            std::mem::size_of_val(&path) as crate::types::size_t,
            (std::mem::size_of_val(&path) - 1) as crate::types::size_t,
            format,
            vendor_lib,
            libName,
        );
        if ret < 0 {
            return std::ptr::null_mut();
        }
        
        let real_result = libc::realpath(path.as_ptr(), resolvedPath.as_mut_ptr());
        if real_result.is_null() {
            return std::ptr::null_mut();
        }
        
        let vendor_lib_len = libc::strlen(vendor_lib);
        if libc::strncmp(resolvedPath.as_ptr(), vendor_lib, vendor_lib_len) != 0 {
            return std::ptr::null_mut();
        }
        
        let vdiObj = crate::compat::OsalMemCalloc(std::mem::size_of::<HdfVdiObject>() as u32) as *mut HdfVdiObject;
        if vdiObj.is_null() {
            return std::ptr::null_mut();
        }
        
        let handler = libc::dlopen(resolvedPath.as_ptr(), 1);
        if handler.is_null() {
            crate::compat::OsalMemFree(vdiObj as *mut ::core::ffi::c_void);
            return std::ptr::null_mut();
        }
        
        let symbol_name = b"hdfVdiDesc\0".as_ptr() as *const ::core::ffi::c_char;
        let vdiBase = libc::dlsym(handler, symbol_name) as *mut *mut HdfVdiBase;
        if vdiBase.is_null() || (*vdiBase).is_null() {
            libc::dlclose(handler);
            crate::compat::OsalMemFree(vdiObj as *mut ::core::ffi::c_void);
            return std::ptr::null_mut();
        }
        
        let base_ptr = *vdiBase;
        if let Some(create_fn) = (*base_ptr).CreateVdiInstance {
            create_fn(base_ptr);
        }
        
        (*vdiObj).dlHandler = handler as usize;
        (*vdiObj).vdiBase = base_ptr;
        
        vdiObj
    }
}

pub extern "C" fn HdfGetVdiVersion(vdiObj: *const crate::types::HdfVdiObject) -> u32 {
    if vdiObj.is_null() {
        return 0xFFFFFFFF;
    }
    
    let vdi_base = unsafe { (*vdiObj).vdiBase };
    if vdi_base.is_null() {
        return 0xFFFFFFFF;
    }
    
    unsafe { (*vdi_base).moduleVersion }
}

pub extern "C" fn HdfCloseVdi(vdiObj: *mut crate::types::HdfVdiObject) {
    unsafe {
        if vdiObj.is_null() || (*vdiObj).dlHandler == 0 || (*vdiObj).vdiBase.is_null() {
            HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"dev_load_vdi\0".as_ptr() as *const ::core::ffi::c_char,
                b"%{public}s para invalid\0".as_ptr() as *const ::core::ffi::c_char,
                b"HdfCloseVdi\0".as_ptr() as *const ::core::ffi::c_char,
            );
            return;
        }

        let vdiBase: *mut crate::types::HdfVdiBase = (*vdiObj).vdiBase;
        if let Some(destroy_fn) = (*vdiBase).DestoryVdiInstance {
            destroy_fn(vdiBase);
        }

        dlclose((*vdiObj).dlHandler as *mut ::core::ffi::c_void);
        (*vdiObj).dlHandler = 0;
        (*vdiObj).vdiBase = std::ptr::null_mut();
        OsalMemFree(vdiObj as *mut ::core::ffi::c_void);
    }
}
