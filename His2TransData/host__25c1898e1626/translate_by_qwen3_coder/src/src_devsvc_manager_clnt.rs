//! Module: src_devsvc_manager_clnt
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

pub extern "C" fn DevSvcManagerClntAddService(service: *mut crate::types::HdfDeviceObject, servinfo: *const crate::types::HdfServiceInfo) -> ::core::ffi::c_int {
    let devSvcMgrClnt = crate::src_devsvc_manager_clnt::DevSvcManagerClntGetInstance();
    let mut serviceManager: *mut crate::types::IDevSvcManager = std::ptr::null_mut();
    
    if devSvcMgrClnt.is_null() {
        return crate::types::HDF_FAILURE;
    }
    
    unsafe {
        if (*servinfo).devClass as u32 >= crate::types::DEVICE_CLASS_MAX {
            return crate::types::HDF_FAILURE;
        }
        
        serviceManager = (*devSvcMgrClnt).devSvcMgrIf;
        if serviceManager.is_null() {
            return crate::types::HDF_FAILURE;
        }
        
        let add_service_fn = (*serviceManager).AddService;
        if add_service_fn.is_none() {
            return crate::types::HDF_FAILURE;
        }
        
        if let Some(f) = add_service_fn {
            return f(serviceManager, service, servinfo);
        }
    }
    
    crate::types::HDF_FAILURE
}

pub extern "C" fn DevSvcManagerClntUpdateService(service: *mut crate::types::HdfDeviceObject, servinfo: *const crate::types::HdfServiceInfo) -> ::core::ffi::c_int {
    let devSvcMgrClnt = crate::src_devsvc_manager_clnt::DevSvcManagerClntGetInstance();
    let mut serviceManager: *mut crate::types::IDevSvcManager = std::ptr::null_mut();
    
    if devSvcMgrClnt.is_null() {
        return crate::types::HDF_FAILURE;
    }
    
    unsafe {
        if (*servinfo).devClass as u32 >= crate::types::DEVICE_CLASS_MAX {
            return crate::types::HDF_FAILURE;
        }
        
        serviceManager = (*devSvcMgrClnt).devSvcMgrIf;
        if serviceManager.is_null() {
            return crate::types::HDF_FAILURE;
        }
        
        if (*serviceManager).UpdateService.is_none() {
            return crate::types::HDF_FAILURE;
        }
        
        if let Some(update_fn) = (*serviceManager).UpdateService {
            return update_fn(serviceManager, service, servinfo);
        }
    }
    
    crate::types::HDF_FAILURE
}

pub extern "C" fn DevSvcManagerClntGetService(svcName: *const ::core::ffi::c_char) -> *const crate::types::HdfObject {
    let devSvcMgrClnt = crate::src_devsvc_manager_clnt::DevSvcManagerClntGetInstance();
    let mut serviceManager: *mut crate::types::IDevSvcManager = std::ptr::null_mut();
    
    if devSvcMgrClnt.is_null() {
        unsafe {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devsvc_manager_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to get service, client is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return std::ptr::null();
    }
    
    serviceManager = unsafe { (*devSvcMgrClnt).devSvcMgrIf };
    
    if serviceManager.is_null() || unsafe { (*serviceManager).GetService.is_none() } {
        unsafe {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devsvc_manager_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"serviceManager GetService function is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return std::ptr::null();
    }
    
    unsafe {
        if let Some(get_service) = (*serviceManager).GetService {
            get_service(serviceManager, svcName) as *const crate::types::HdfObject
        } else {
            std::ptr::null()
        }
    }
}

pub extern "C" fn DevSvcManagerClntGetDeviceObject(svcName: *const ::core::ffi::c_char) -> *mut crate::types::HdfDeviceObject {
    let devSvcMgrClnt = crate::src_devsvc_manager_clnt::DevSvcManagerClntGetInstance();
    let mut serviceManager: *mut crate::types::IDevSvcManager = std::ptr::null_mut();
    
    if devSvcMgrClnt.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devsvc_manager_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to get device object, client is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return std::ptr::null_mut();
    }
    
    serviceManager = unsafe { (*devSvcMgrClnt).devSvcMgrIf };
    
    if serviceManager.is_null() || unsafe { (*serviceManager).GetObject.is_none() } {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devsvc_manager_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to get device object, method not implement\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return std::ptr::null_mut();
    }
    
    unsafe {
        if let Some(get_object) = (*serviceManager).GetObject {
            get_object(serviceManager, svcName)
        } else {
            std::ptr::null_mut()
        }
    }
}

pub extern "C" fn DevSvcManagerClntSubscribeService(svcName: *const ::core::ffi::c_char, callback: crate::types::SubscriberCallback) -> ::core::ffi::c_int {
    let devSvcMgrClnt = crate::src_devsvc_manager_clnt::DevSvcManagerClntGetInstance();
    
    if devSvcMgrClnt.is_null() || svcName.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devsvc_manager_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to subscribe service, client or svcName is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return crate::types::HDF_FAILURE;
    }
    
    let serviceManager = unsafe { (*devSvcMgrClnt).devSvcMgrIf };
    
    if serviceManager.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devsvc_manager_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to subscribe service, method not implement\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return crate::types::HDF_FAILURE;
    }
    
    let subscribe_fn = unsafe { (*serviceManager).SubscribeService };
    
    if subscribe_fn.is_none() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devsvc_manager_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to subscribe service, method not implement\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return crate::types::HDF_FAILURE;
    }
    
    unsafe {
        (subscribe_fn.unwrap())(serviceManager, svcName, callback)
    }
}

pub extern "C" fn DevSvcManagerClntUnsubscribeService(svcName: *const ::core::ffi::c_char) -> ::core::ffi::c_int {
    let devSvcMgrClnt = crate::src_devsvc_manager_clnt::DevSvcManagerClntGetInstance();
    let mut serviceManager: *mut crate::types::IDevSvcManager = std::ptr::null_mut();
    
    if devSvcMgrClnt.is_null() || svcName.is_null() {
        let _ = unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devsvc_manager_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to unsubscribe service, client or svcName is null\0".as_ptr() as *const ::core::ffi::c_char,
            )
        };
        return crate::types::HDF_FAILURE;
    }
    
    serviceManager = unsafe { (*devSvcMgrClnt).devSvcMgrIf };
    
    if serviceManager.is_null() {
        let _ = unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devsvc_manager_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to unsubscribe service, method not implement\0".as_ptr() as *const ::core::ffi::c_char,
            )
        };
        return crate::types::HDF_FAILURE;
    }
    
    let unsubscribe_fn = unsafe { (*serviceManager).UnsubscribeService };
    if unsubscribe_fn.is_none() {
        let _ = unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devsvc_manager_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to unsubscribe service, method not implement\0".as_ptr() as *const ::core::ffi::c_char,
            )
        };
        return crate::types::HDF_FAILURE;
    }
    
    unsafe { unsubscribe_fn.unwrap()(serviceManager, svcName) }
}

pub extern "C" fn DevSvcManagerClntRemoveService(svcName: *const ::core::ffi::c_char) {
    let devSvcMgrClnt = crate::src_devsvc_manager_clnt::DevSvcManagerClntGetInstance();
    let mut serviceManager: *mut crate::types::IDevSvcManager = std::ptr::null_mut();
    
    if devSvcMgrClnt.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devsvc_manager_clnt\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to remove service, devSvcMgrClnt is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return;
    }
    
    serviceManager = unsafe { (*devSvcMgrClnt).devSvcMgrIf };
    
    if serviceManager.is_null() {
        return;
    }
    
    let remove_service = unsafe { (*serviceManager).RemoveService };
    if remove_service.is_none() {
        return;
    }
    
    unsafe {
        (remove_service.unwrap())(serviceManager, svcName, std::ptr::null());
    }
}

fn DevSvcManagerClntConstruct(inst: *mut crate::types::DevSvcManagerClnt) {
    unsafe {
        (*inst).devSvcMgrIf = crate::compat::HdfObjectManagerGetObject(
            crate::types::HDF_OBJECT_ID_DEVSVC_MANAGER as i32
        ) as *mut crate::types::IDevSvcManager;
    }
}

pub extern "C" fn DevSvcManagerClntGetInstance() -> *mut crate::types::DevSvcManagerClnt {
    static mut INSTANCE: *mut crate::types::DevSvcManagerClnt = std::ptr::null_mut();
    static mut SINGLETON_INSTANCE: crate::types::DevSvcManagerClnt = crate::types::DevSvcManagerClnt {
        devSvcMgrIf: std::ptr::null_mut(),
    };
    
    unsafe {
        if INSTANCE.is_null() {
            crate::src_devsvc_manager_clnt::DevSvcManagerClntConstruct(&mut SINGLETON_INSTANCE as *mut crate::types::DevSvcManagerClnt);
            INSTANCE = &mut SINGLETON_INSTANCE as *mut crate::types::DevSvcManagerClnt;
        }
        INSTANCE
    }
}

pub extern "C" fn DevSvcManagerClntFreeInstance(instance: *mut crate::types::DevSvcManagerClnt) {
    if !instance.is_null() {
        unsafe {
            crate::compat::HdfObjectManagerFreeObject((*instance).devSvcMgrIf as *mut crate::types::HdfObject);
        }
    }
}
