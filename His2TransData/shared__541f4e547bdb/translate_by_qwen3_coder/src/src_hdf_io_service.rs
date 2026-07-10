//! Module: src_hdf_io_service
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

pub extern "C" fn HdfIoServiceBind(serviceName: *const ::core::ffi::c_char) -> *mut crate::types::HdfIoService {
    unsafe { crate::compat::HdfIoServiceAdapterObtain(serviceName) }
}

pub extern "C" fn HdfIoServiceRecycle(service: *mut crate::types::HdfIoService) {
    unsafe {
        crate::compat::HdfIoServiceAdapterRecycle(service);
    }
}

pub extern "C" fn HdfIoServicePublish(serviceName: *const ::core::ffi::c_char, mode: u32) -> *mut crate::types::HdfIoService {
    unsafe {
        crate::compat::HdfIoServiceAdapterPublish(serviceName, mode)
    }
}

pub extern "C" fn HdfIoServiceRemove(service: *mut crate::types::HdfIoService) {
    extern "C" {
        static HdfIoServiceAdapterRemove: Option<unsafe extern "C" fn(service: *mut crate::types::HdfIoService)>;
    }
    
    unsafe {
        if let Some(f) = HdfIoServiceAdapterRemove {
            f(service);
        }
    }
}

pub extern "C" fn HdfIoServiceDispatch(ioService: *mut crate::types::HdfIoService, cmdId: ::core::ffi::c_int, data: *mut crate::types::HdfSBuf, reply: *mut crate::types::HdfSBuf) -> i32 {
    unsafe {
        if ioService.is_null() || (*ioService).dispatcher.is_null() || (*(*ioService).dispatcher).Dispatch.is_none() {
            return crate::types::HDF_ERR_INVALID_OBJECT;
        }
        
        let dispatch_fn = (*(*ioService).dispatcher).Dispatch.unwrap();
        dispatch_fn(&mut (*ioService).object as *mut crate::types::HdfObject, cmdId, data, reply)
    }
}
