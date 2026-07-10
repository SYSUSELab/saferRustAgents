//! Module: src_devmgr_service_clnt
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

pub extern "C" fn DevmgrServiceClntAttachDeviceHost(hostId: u16, hostService: *mut crate::types::IDevHostService) -> ::core::ffi::c_int {
    let inst = crate::src_devmgr_service_clnt::DevmgrServiceClntGetInstance();
    if inst.is_null() {
        return crate::types::HDF_FAILURE;
    }
    
    let dev_mgr_svc_if = unsafe { (*inst).devMgrSvcIf };
    if dev_mgr_svc_if.is_null() {
        return crate::types::HDF_FAILURE;
    }
    
    let attach_device_host = unsafe { (*dev_mgr_svc_if).AttachDeviceHost };
    if attach_device_host.is_none() {
        return crate::types::HDF_FAILURE;
    }
    
    unsafe { attach_device_host.unwrap()(dev_mgr_svc_if, hostId, hostService) }
}

pub extern "C" fn DevmgrServiceClntAttachDevice(deviceToken: *mut crate::types::IHdfDeviceToken) -> ::core::ffi::c_int {
    let inst = crate::src_devmgr_service_clnt::DevmgrServiceClntGetInstance();
    if inst.is_null() || unsafe { (*inst).devMgrSvcIf.is_null() } {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devmgr_service_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"devmgr client failed to attach device, inst is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return crate::types::HDF_FAILURE;
    }

    let devMgrSvcIf = unsafe { (*inst).devMgrSvcIf };
    let attach_device = unsafe { (*devMgrSvcIf).AttachDevice };
    if attach_device.is_none() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devmgr_service_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"devmgr client failed to attach device, dmsOps->AttachDevice is nul\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return crate::types::HDF_FAILURE;
    }

    unsafe { attach_device.unwrap()(devMgrSvcIf, deviceToken) }
}

pub extern "C" fn DevmgrServiceClntDetachDevice(devid: crate::types::devid_t) -> ::core::ffi::c_int {
    let inst = crate::src_devmgr_service_clnt::DevmgrServiceClntGetInstance();
    if inst.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devmgr_service_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"devmgr client failed to deatch device, inst is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return crate::types::HDF_FAILURE;
    }
    
    let dev_mgr_svc_if = unsafe { (*inst).devMgrSvcIf };
    if dev_mgr_svc_if.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devmgr_service_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"devmgr client failed to deatch device, inst is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return crate::types::HDF_FAILURE;
    }
    
    let detach_device = unsafe { (*dev_mgr_svc_if).DetachDevice };
    if detach_device.is_none() {
        return crate::types::HDF_FAILURE;
    }
    
    unsafe { detach_device.unwrap()(dev_mgr_svc_if, devid) }
}

pub extern "C" fn DevmgrServiceClntGetInstance() -> *mut crate::types::DevmgrServiceClnt {
    static mut INSTANCE: crate::types::DevmgrServiceClnt = crate::types::DevmgrServiceClnt {
        devMgrSvcIf: std::ptr::null_mut(),
    };
    
    unsafe {
        if INSTANCE.devMgrSvcIf.is_null() {
            INSTANCE.devMgrSvcIf = crate::compat::HdfObjectManagerGetObject(
                crate::types::HDF_OBJECT_ID_DEVMGR_SERVICE as i32
            ) as *mut crate::types::IDevmgrService;
        }
        &mut INSTANCE as *mut crate::types::DevmgrServiceClnt
    }
}

pub extern "C" fn DevmgrServiceClntFreeInstance(inst: *mut crate::types::DevmgrServiceClnt) {
    if !inst.is_null() {
        unsafe {
            if !(*inst).devMgrSvcIf.is_null() {
                crate::compat::HdfObjectManagerFreeObject((*inst).devMgrSvcIf as *mut crate::types::HdfObject);
                (*inst).devMgrSvcIf = std::ptr::null_mut();
            }
        }
    }
}
