//! Module: src_hdf_device_node
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

fn HdfDeviceNodePublishLocalService(devNode: *mut crate::types::HdfDeviceNode) -> i32 {
    if devNode.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"device_node\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to publish local service, device is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return crate::types::HDF_FAILURE;
    }
    
    unsafe {
        if (*devNode).hostService.is_null() {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"device_node\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to publish local service, host service is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
            return crate::types::HDF_FAILURE;
        }
        
        let host_service = (*devNode).hostService;
        let observer_ptr = &mut (*host_service).observer as *mut crate::types::HdfServiceObserver;
        let serv_name = (*devNode).servName as *const ::core::ffi::c_char;
        let dev_id = (*devNode).devId;
        let policy = (*devNode).policy;
        let service = (*devNode).deviceObject.service as *mut crate::types::HdfObject;
        
        crate::src_hdf_service_observer::HdfServiceObserverPublishService(
            observer_ptr,
            serv_name,
            dev_id,
            policy,
            service,
        )
    }
}

fn HdfDeviceNodePublishService(devNode: *mut crate::types::HdfDeviceNode) -> i32 {
    let mut status: i32 = crate::types::HDF_SUCCESS as i32;
    let mut nodeIf: *mut crate::types::IDeviceNode = std::ptr::null_mut();
    
    unsafe {
        if (*devNode).policy == crate::types::SERVICE_POLICY_NONE as u16 ||
           (!(*devNode).servName.is_null() && libc::strlen((*devNode).servName) == 0) {
            return status;
        }
        
        nodeIf = &mut (*devNode).super_ as *mut crate::types::IDeviceNode;
        
        if (*devNode).policy == crate::types::SERVICE_POLICY_PUBLIC as u16 || 
           (*devNode).policy == crate::types::SERVICE_POLICY_CAPACITY as u16 {
            if let Some(publish_fn) = (*nodeIf).PublishService {
                status = publish_fn(devNode);
            }
        }
        
        if status == crate::types::HDF_SUCCESS as i32 {
            status = crate::src_hdf_device_node::HdfDeviceNodePublishLocalService(devNode);
        }
    }
    
    status
}

pub extern "C" fn DeviceDriverBind(devNode: *mut crate::types::HdfDeviceNode) -> ::core::ffi::c_int {
    use crate::types::*;
    
    if devNode.is_null() {
        return HDF_ERR_INVALID_PARAM;
    }
    
    unsafe {
        let driver = (*devNode).driver;
        if driver.is_null() {
            return HDF_ERR_INVALID_PARAM;
        }
        
        let driverEntry = (*driver).entry;
        if driverEntry.is_null() {
            return HDF_ERR_INVALID_PARAM;
        }
        
        let policy = (*devNode).policy;
        
        if policy == SERVICE_POLICY_PUBLIC as u16 || policy == SERVICE_POLICY_CAPACITY as u16 {
            let bind_fn = (*driverEntry).Bind;
            if bind_fn.is_none() {
                let module_name = (*driverEntry).moduleName;
                crate::compat::HiLogPrint(
                    LOG_CORE,
                    LOG_ERROR,
                    0xD002510,
                    b"device_node\0".as_ptr() as *const ::core::ffi::c_char,
                    b"driver %{public}s bind method not implement\0".as_ptr() as *const ::core::ffi::c_char,
                    module_name,
                );
                (*devNode).devStatus = DEVNODE_NONE as u8;
                return HDF_ERR_INVALID_OBJECT;
            }
            
            let ret = bind_fn.unwrap()(&mut (*devNode).deviceObject);
            if ret != HDF_SUCCESS as i32 {
                let module_name = (*driverEntry).moduleName;
                crate::compat::HiLogPrint(
                    LOG_CORE,
                    LOG_ERROR,
                    0xD002510,
                    b"device_node\0".as_ptr() as *const ::core::ffi::c_char,
                    b"bind driver %{public}s failed\0".as_ptr() as *const ::core::ffi::c_char,
                    module_name,
                );
                return HDF_DEV_ERR_DEV_INIT_FAIL;
            }
        }
        
        HDF_SUCCESS
    }
}

pub extern "C" fn HdfDeviceLaunchNode(devNode: *mut crate::types::HdfDeviceNode) -> ::core::ffi::c_int {
    use crate::types::*;
    
    if devNode.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD002510,
                b"device_node\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to launch service, device or service is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return HDF_ERR_INVALID_PARAM;
    }

    unsafe {
        let serv_name = if (*devNode).servName.is_null() {
            b"\0".as_ptr() as *const ::core::ffi::c_char
        } else {
            (*devNode).servName as *const ::core::ffi::c_char
        };
        crate::compat::HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xD002510,
            b"device_node\0".as_ptr() as *const ::core::ffi::c_char,
            b"launch devnode %{public}s\0".as_ptr() as *const ::core::ffi::c_char,
            serv_name,
        );
    }

    let driverEntry: *const HdfDriverEntry = unsafe {
        if (*devNode).driver.is_null() {
            std::ptr::null()
        } else {
            (*(*devNode).driver).entry
        }
    };

    if driverEntry.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD002510,
                b"device_node\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to launch service, deviceEntry invalid\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return HDF_ERR_INVALID_PARAM;
    }

    let init_fn = unsafe { (*driverEntry).Init };
    if init_fn.is_none() {
        unsafe {
            crate::compat::HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD002510,
                b"device_node\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to launch service, deviceEntry invalid\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return HDF_ERR_INVALID_PARAM;
    }

    unsafe {
        (*devNode).devStatus = DEVNODE_LAUNCHED as u8;
    }

    let ret = crate::src_hdf_device_node::DeviceDriverBind(devNode);
    if ret != HDF_SUCCESS {
        return ret;
    }

    let ret = unsafe {
        if let Some(init) = init_fn {
            init(&mut (*devNode).deviceObject)
        } else {
            HDF_ERR_INVALID_PARAM
        }
    };
    if ret != HDF_SUCCESS {
        return HDF_DEV_ERR_DEV_INIT_FAIL;
    }

    let ret = crate::src_hdf_device_node::HdfDeviceNodePublishService(devNode);
    if ret != HDF_SUCCESS {
        return HDF_DEV_ERR_PUBLISH_FAIL;
    }

    let ret = unsafe {
        crate::src_devmgr_service_clnt::DevmgrServiceClntAttachDevice((*devNode).token)
    };
    if ret != HDF_SUCCESS {
        return HDF_DEV_ERR_ATTACHDEV_FAIL;
    }

    ret
}

pub extern "C" fn HdfDeviceNodeAddPowerStateListener(devNode: *mut crate::types::HdfDeviceNode, listener: *const crate::types::IPowerEventListener) -> ::core::ffi::c_int {
    unsafe {
        if !(*devNode).powerToken.is_null() {
            return crate::types::HDF_FAILURE;
        }

        (*devNode).powerToken = crate::src_power_state_token::PowerStateTokenNewInstance(
            &mut (*devNode).deviceObject as *mut crate::types::HdfDeviceObject,
            listener,
        );

        if !(*devNode).powerToken.is_null() {
            crate::types::HDF_SUCCESS
        } else {
            crate::types::HDF_FAILURE
        }
    }
}

pub extern "C" fn HdfDeviceNodeRemovePowerStateListener(devNode: *mut crate::types::HdfDeviceNode, listener: *const crate::types::IPowerEventListener) {
    let _ = listener;
    
    if devNode.is_null() {
        return;
    }
    
    unsafe {
        if (*devNode).powerToken.is_null() {
            return;
        }
        
        crate::src_power_state_token::PowerStateTokenFreeInstance((*devNode).powerToken);
        (*devNode).powerToken = std::ptr::null_mut();
    }
}

pub extern "C" fn HdfDeviceNodePublishPublicService(devNode: *mut crate::types::HdfDeviceNode) -> ::core::ffi::c_int {
    unsafe {
        if devNode.is_null() || (*devNode).deviceObject.service.is_null() {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"device_node\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to publish public service, devNode is NULL\0".as_ptr() as *const ::core::ffi::c_char,
            );
            return crate::types::HDF_FAILURE;
        }
        
        let mut servInfo: crate::types::HdfServiceInfo = std::mem::zeroed();
        
        // Inline HdfServiceInfoInit
        servInfo.servName = (*devNode).servName as *const ::core::ffi::c_char;
        servInfo.servInfo = (*devNode).servInfo;
        servInfo.devClass = (*devNode).deviceObject.deviceClass as u16;
        servInfo.devId = (*devNode).devId;
        servInfo.interfaceDesc = (*devNode).interfaceDesc as *const ::core::ffi::c_char;
        
        let ret = crate::src_devsvc_manager_clnt::DevSvcManagerClntAddService(
            &mut (*devNode).deviceObject as *mut crate::types::HdfDeviceObject,
            &servInfo as *const crate::types::HdfServiceInfo,
        );
        
        if ret == crate::types::HDF_SUCCESS {
            (*devNode).servStatus = true;
        }
        
        ret
    }
}

pub extern "C" fn HdfDeviceNodeRemoveService(devNode: *mut crate::types::HdfDeviceNode) -> ::core::ffi::c_int {
    if !devNode.is_null() {
        unsafe {
            if (*devNode).servStatus {
                crate::src_devsvc_manager_clnt::DevSvcManagerClntRemoveService((*devNode).servName as *const ::core::ffi::c_char);
                (*devNode).servStatus = false;
            }
        }
    }
    crate::types::HDF_SUCCESS
}

fn HdfDeviceUnlaunchNode(devNode: *mut crate::types::HdfDeviceNode) {
    let mut driverEntry: *const crate::types::HdfDriverEntry = std::ptr::null();
    let mut driverLoader: *mut crate::types::IDriverLoader = std::ptr::null_mut();
    
    if devNode.is_null() {
        return;
    }
    
    unsafe {
        if (*devNode).devStatus != crate::types::DEVNODE_LAUNCHED as u8 {
            return;
        }
        
        if !(*devNode).driver.is_null() {
            driverEntry = (*(*devNode).driver).entry;
        }
        
        if !driverEntry.is_null() {
            if let Some(release_fn) = (*driverEntry).Release {
                release_fn(&mut (*devNode).deviceObject);
            }
        }
        
        if (*devNode).servStatus {
            if let Some(remove_service_fn) = (*devNode).super_.RemoveService {
                remove_service_fn(devNode);
            }
        }
        
        crate::src_devmgr_service_clnt::DevmgrServiceClntDetachDevice((*devNode).devId);
        
        driverLoader = crate::src_hdf_driver_loader::HdfDriverLoaderGetInstance();
        if !driverLoader.is_null() {
            if let Some(reclaim_fn) = (*driverLoader).ReclaimDriver {
                reclaim_fn((*devNode).driver);
            }
            (*devNode).driver = std::ptr::null_mut();
        } else {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"device_node\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to get driver loader\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        
        (*devNode).devStatus = crate::types::DEVNODE_INITED as u8;
    }
}

pub extern "C" fn HdfDeviceNodeConstruct(devNode: *mut crate::types::HdfDeviceNode) {
    if !devNode.is_null() {
        unsafe {
            let nodeIf: *mut crate::types::IDeviceNode = &mut (*devNode).super_;
            crate::src_hdf_device_object::HdfDeviceObjectConstruct(&mut (*devNode).deviceObject);
            (*devNode).token = crate::src_hdf_device_token::HdfDeviceTokenNewInstance();
            
            unsafe extern "C" fn launch_node_wrapper(devNode: *mut crate::types::HdfDeviceNode) -> ::core::ffi::c_int {
                crate::src_hdf_device_node::HdfDeviceLaunchNode(devNode)
            }
            unsafe extern "C" fn publish_service_wrapper(devNode: *mut crate::types::HdfDeviceNode) -> ::core::ffi::c_int {
                crate::src_hdf_device_node::HdfDeviceNodePublishPublicService(devNode)
            }
            unsafe extern "C" fn remove_service_wrapper(devNode: *mut crate::types::HdfDeviceNode) -> ::core::ffi::c_int {
                crate::src_hdf_device_node::HdfDeviceNodeRemoveService(devNode)
            }
            unsafe extern "C" fn unlaunch_node_wrapper(devNode: *mut crate::types::HdfDeviceNode) {
                crate::src_hdf_device_node::HdfDeviceUnlaunchNode(devNode)
            }
            
            (*nodeIf).LaunchNode = Some(launch_node_wrapper);
            (*nodeIf).PublishService = Some(publish_service_wrapper);
            (*nodeIf).RemoveService = Some(remove_service_wrapper);
            (*nodeIf).UnlaunchNode = Some(unlaunch_node_wrapper);
        }
    }
}

pub extern "C" fn HdfDeviceNodeDestruct(devNode: *mut crate::types::HdfDeviceNode) {
    if devNode.is_null() {
        return;
    }
    
    unsafe {
        let _ = crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD002510,
            b"device_node\0".as_ptr() as *const ::core::ffi::c_char,
            b"release devnode %{public}s\0".as_ptr() as *const ::core::ffi::c_char,
            (*devNode).servName,
        );
        
        match (*devNode).devStatus as crate::types::DevNodeStaus {
            crate::types::DEVNODE_LAUNCHED => {
                crate::src_hdf_device_node::HdfDeviceUnlaunchNode(devNode);
                // Fall through to DEVNODE_INITED
                crate::src_hdf_device_token::HdfDeviceTokenFreeInstance((*devNode).token);
                (*devNode).token = std::ptr::null_mut();
                crate::src_power_state_token::PowerStateTokenFreeInstance((*devNode).powerToken);
                (*devNode).powerToken = std::ptr::null_mut();
                crate::compat::OsalMemFree((*devNode).servName as *mut ::core::ffi::c_void);
                crate::compat::OsalMemFree((*devNode).servInfo as *mut ::core::ffi::c_void);
                crate::compat::OsalMemFree((*devNode).driverName as *mut ::core::ffi::c_void);
                (*devNode).servName = std::ptr::null_mut();
                (*devNode).servInfo = std::ptr::null();
            }
            crate::types::DEVNODE_INITED => {
                crate::src_hdf_device_token::HdfDeviceTokenFreeInstance((*devNode).token);
                (*devNode).token = std::ptr::null_mut();
                crate::src_power_state_token::PowerStateTokenFreeInstance((*devNode).powerToken);
                (*devNode).powerToken = std::ptr::null_mut();
                crate::compat::OsalMemFree((*devNode).servName as *mut ::core::ffi::c_void);
                crate::compat::OsalMemFree((*devNode).servInfo as *mut ::core::ffi::c_void);
                crate::compat::OsalMemFree((*devNode).driverName as *mut ::core::ffi::c_void);
                (*devNode).servName = std::ptr::null_mut();
                (*devNode).servInfo = std::ptr::null();
            }
            crate::types::DEVNODE_NONE => {}
            _ => {}
        }
    }
}

pub extern "C" fn HdfDeviceNodeNewInstance(deviceInfo: *const crate::types::HdfDeviceInfo, driver: *mut crate::types::HdfDriver) -> *mut crate::types::HdfDeviceNode {
    let mut devNode: *mut crate::types::HdfDeviceNode = std::ptr::null_mut();
    if deviceInfo.is_null() {
        return std::ptr::null_mut();
    }
    devNode = unsafe { crate::compat::HdfObjectManagerGetObject(crate::types::HDF_OBJECT_ID_DEVICE_SERVICE as i32) } as *mut crate::types::HdfDeviceNode;
    if devNode.is_null() {
        return std::ptr::null_mut();
    }

    unsafe {
        (*devNode).driver = driver;
        (*devNode).devId = (*deviceInfo).deviceId;
        (*devNode).permission = (*deviceInfo).permission;
        (*devNode).policy = (*deviceInfo).policy;
        (*(*devNode).token).devid = (*deviceInfo).deviceId;
        (*devNode).servName = crate::compat::HdfStringCopy((*deviceInfo).svcName);
        (*(*devNode).token).servName = crate::compat::HdfStringCopy((*deviceInfo).svcName);
        (*(*devNode).token).deviceName = crate::compat::HdfStringCopy((*deviceInfo).deviceName);
    }

    if unsafe { (*devNode).servName.is_null() } {
        crate::src_hdf_device_node::HdfDeviceNodeFreeInstance(devNode);
        return std::ptr::null_mut();
    }

    unsafe {
        (*devNode).deviceObject.property = crate::compat::HcsGetNodeByMatchAttr(crate::compat::HdfGetHcsRootNode(), (*deviceInfo).deviceMatchAttr);
        if (*devNode).deviceObject.property.is_null() {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_DEBUG,
                0xD002510,
                b"device_node\0".as_ptr() as *const ::core::ffi::c_char,
                b"node %{public}s property empty, match attr: %{public}s\0".as_ptr() as *const ::core::ffi::c_char,
                (*deviceInfo).moduleName,
                (*deviceInfo).deviceMatchAttr,
            );
        }

        (*devNode).devStatus = crate::types::DEVNODE_INITED as u8;
    }
    devNode
}

pub extern "C" fn HdfDeviceNodeFreeInstance(devNode: *mut crate::types::HdfDeviceNode) {
    unsafe {
        crate::compat::HdfObjectManagerFreeObject(devNode as *mut crate::types::HdfObject);
    }
}
