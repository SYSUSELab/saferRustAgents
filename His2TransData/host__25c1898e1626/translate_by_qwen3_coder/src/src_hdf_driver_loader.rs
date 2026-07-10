//! Module: src_hdf_driver_loader
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

pub extern "C" fn HdfDriverEntryConstruct() -> i32 {
    use crate::types::*;
    use crate::compat::*;
    
    extern "C" {
        static _hdf_drivers_start: size_t;
        static _hdf_drivers_end: size_t;
    }
    
    unsafe {
        let start_ptr = &_hdf_drivers_start as *const size_t as *const u8;
        let end_ptr = &_hdf_drivers_end as *const size_t as *const u8;
        let count: i32 = ((end_ptr as usize - start_ptr as usize) / core::mem::size_of::<size_t>()) as i32;
        
        if count <= 0 {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD002510,
                b"driver_loader\0".as_ptr() as *const ::core::ffi::c_char,
                b"%{public}s: no hdf driver exist\0".as_ptr() as *const ::core::ffi::c_char,
                b"HdfDriverEntryConstruct\0".as_ptr() as *const ::core::ffi::c_char,
            );
            return HDF_FAILURE;
        }
        
        let mut addr_begin = &_hdf_drivers_start as *const size_t as *mut size_t;
        
        for _i in 0..count {
            let driver_entry = *addr_begin as *mut HdfDriverEntry;
            if HdfRegisterDriverEntry(driver_entry as *const HdfDriverEntry) != HDF_SUCCESS {
                let module_name = if !driver_entry.is_null() {
                    (*driver_entry).moduleName
                } else {
                    b"\0".as_ptr() as *const ::core::ffi::c_char
                };
                HiLogPrint(
                    LOG_CORE,
                    LOG_ERROR,
                    0xD002510,
                    b"driver_loader\0".as_ptr() as *const ::core::ffi::c_char,
                    b"failed to register driver %{public}s, skip and try another\0".as_ptr() as *const ::core::ffi::c_char,
                    module_name,
                );
                addr_begin = addr_begin.add(1);
                continue;
            }
            addr_begin = addr_begin.add(1);
        }
        
        HDF_SUCCESS
    }
}

pub extern "C" fn HdfDriverLoaderGetDriver(moduleName: *const ::core::ffi::c_char) -> *mut crate::types::HdfDriver {
    if moduleName.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"driver_loader\0".as_ptr() as *const ::core::ffi::c_char,
                b"%{public}s: failed to get device entry, moduleName is NULL\0".as_ptr() as *const ::core::ffi::c_char,
                b"HdfDriverLoaderGetDriver\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return std::ptr::null_mut();
    }

    unsafe { crate::compat::HdfDriverManagerGetDriver(moduleName) }
}

pub extern "C" fn HdfDriverLoaderReclaimDriver(driver: *mut crate::types::HdfDriver) {
    let _ = driver;
}

pub extern "C" fn HdfDriverLoaderConstruct(inst: *mut crate::types::HdfDriverLoader) {
    if !inst.is_null() {
        unsafe {
            (*inst).super_.GetDriver = Some(HdfDriverLoaderGetDriver);
            (*inst).super_.ReclaimDriver = Some(HdfDriverLoaderReclaimDriver);
        }
    }
}

pub extern "C" fn HdfDriverLoaderCreate() -> *mut crate::types::HdfObject {
    static mut IS_DRIVER_LOADER_INIT: bool = false;
    static mut DRIVER_LOADER: crate::types::HdfDriverLoader = crate::types::HdfDriverLoader {
        super_: crate::types::IDriverLoader {
            object: crate::types::HdfObject { objectId: 0 },
            GetDriver: None,
            ReclaimDriver: None,
        },
    };

    unsafe {
        if !IS_DRIVER_LOADER_INIT {
            if crate::src_hdf_driver_loader::HdfDriverEntryConstruct() != crate::types::HDF_SUCCESS {
                return std::ptr::null_mut();
            }
            crate::src_hdf_driver_loader::HdfDriverLoaderConstruct(&mut DRIVER_LOADER as *mut crate::types::HdfDriverLoader);
            IS_DRIVER_LOADER_INIT = true;
        }
        &mut DRIVER_LOADER as *mut crate::types::HdfDriverLoader as *mut crate::types::HdfObject
    }
}

pub extern "C" fn HdfDriverLoaderGetInstance() -> *mut crate::types::IDriverLoader {
    static mut INSTANCE: *mut crate::types::IDriverLoader = std::ptr::null_mut();
    unsafe {
        if INSTANCE.is_null() {
            INSTANCE = crate::compat::HdfObjectManagerGetObject(crate::types::HDF_OBJECT_ID_DRIVER_LOADER as i32) as *mut crate::types::IDriverLoader;
        }
        INSTANCE
    }
}
