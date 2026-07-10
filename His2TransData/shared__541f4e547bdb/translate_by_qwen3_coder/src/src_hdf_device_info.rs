//! Module: src_hdf_device_info
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

pub extern "C" fn HdfDeviceInfoConstruct(deviceInfo: *mut crate::types::HdfDeviceInfo) {
    if deviceInfo.is_null() {
        return;
    }
    unsafe {
        (*deviceInfo).isDynamic = false;
        (*deviceInfo).status = crate::types::HDF_SERVICE_UNUSABLE as u16;
        (*deviceInfo).deviceType = crate::types::HDF_DEV_LOCAL_SERVICE as u16;
        (*deviceInfo).deviceId = 0;
        (*deviceInfo).policy = crate::types::SERVICE_POLICY_INVALID as u16;
        (*deviceInfo).priority = 0;
        (*deviceInfo).preload = crate::types::DEVICE_PRELOAD_ENABLE as u16;
        (*deviceInfo).permission = 0;
        (*deviceInfo).svcName = std::ptr::null();
        (*deviceInfo).moduleName = std::ptr::null();
        (*deviceInfo).deviceMatchAttr = std::ptr::null();
        (*deviceInfo).deviceName = std::ptr::null();
    }
}

pub extern "C" fn HdfDeviceInfoNewInstance() -> *mut crate::types::HdfDeviceInfo {
    let deviceInfo = unsafe {
        crate::compat::OsalMemCalloc(std::mem::size_of::<crate::types::HdfDeviceInfo>() as u32)
    } as *mut crate::types::HdfDeviceInfo;
    
    if !deviceInfo.is_null() {
        crate::src_hdf_device_info::HdfDeviceInfoConstruct(deviceInfo);
        return deviceInfo;
    }
    
    let _ = unsafe {
        crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_ERROR,
            0xD002510,
            b"device_info\0".as_ptr() as *const ::core::ffi::c_char,
            b"failed to create deviceInfo, oom\0".as_ptr() as *const ::core::ffi::c_char,
        )
    };
    
    std::ptr::null_mut()
}

pub extern "C" fn HdfDeviceInfoFreeInstance(deviceInfo: *mut crate::types::HdfDeviceInfo) {
    if !deviceInfo.is_null() {
        unsafe {
            crate::compat::OsalMemFree(deviceInfo as *mut ::core::ffi::c_void);
        }
    }
}

pub extern "C" fn HdfDeviceInfoDelete(listEntry: *mut crate::types::HdfSListNode) {
    let deviceInfo = listEntry as *mut crate::types::HdfDeviceInfo;
    crate::src_hdf_device_info::HdfDeviceInfoFreeInstance(deviceInfo);
}
