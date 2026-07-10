//! Module: src_hdf_device_token
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

fn HdfDeviceTokenConstruct(inst: *mut crate::types::HdfDeviceToken) {
    unsafe {
        (*inst).super_.object.objectId = crate::types::HDF_OBJECT_ID_DEVICE_TOKEN as i32;
    }
}

pub extern "C" fn HdfDeviceTokenCreate() -> *mut crate::types::HdfObject {
    let token = unsafe {
        crate::compat::OsalMemCalloc(std::mem::size_of::<crate::types::HdfDeviceToken>() as u32)
    } as *mut crate::types::HdfDeviceToken;
    
    if !token.is_null() {
        crate::src_hdf_device_token::HdfDeviceTokenConstruct(token);
    }
    
    token as *mut crate::types::HdfObject
}

pub extern "C" fn HdfDeviceTokenRelease(object: *mut crate::types::HdfObject) {
    let deviceToken = object as *mut crate::types::HdfDeviceToken;
    if !deviceToken.is_null() {
        unsafe {
            OsalMemFree((*deviceToken).super_.servName as *mut ::core::ffi::c_void);
            OsalMemFree((*deviceToken).super_.deviceName as *mut ::core::ffi::c_void);
            OsalMemFree(deviceToken as *mut ::core::ffi::c_void);
        }
    }
}

pub extern "C" fn HdfDeviceTokenNewInstance() -> *mut crate::types::IHdfDeviceToken {
    unsafe {
        crate::compat::HdfObjectManagerGetObject(crate::types::HDF_OBJECT_ID_DEVICE_TOKEN as i32) as *mut crate::types::IHdfDeviceToken
    }
}

pub extern "C" fn HdfDeviceTokenFreeInstance(token: *mut crate::types::IHdfDeviceToken) {
    if !token.is_null() {
        unsafe {
            crate::compat::HdfObjectManagerFreeObject(&mut (*token).object as *mut crate::types::HdfObject);
        }
    }
}
