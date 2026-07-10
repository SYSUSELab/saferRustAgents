//! Module: src_hdf_device_object
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

pub extern "C" fn HdfDeviceSubscribeService(deviceObject: *mut crate::types::HdfDeviceObject, serviceName: *const ::core::ffi::c_char, callback: crate::types::SubscriberCallback) -> i32 {
    if deviceObject.is_null() || serviceName.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"device_object\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to subscribe service, serviceName is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return crate::types::HDF_FAILURE;
    }
    
    // HDF_SLIST_CONTAINER_OF macro expansion: get HdfDeviceNode from deviceObject field
    let devNode: *mut crate::types::HdfDeviceNode = unsafe {
        let offset = core::mem::offset_of!(crate::types::HdfDeviceNode, deviceObject);
        (deviceObject as *mut u8).sub(offset) as *mut crate::types::HdfDeviceNode
    };
    
    let hostService: *mut crate::types::DevHostService = unsafe { (*devNode).hostService };
    
    if hostService.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"device_object\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to subscribe service, hostService is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return crate::types::HDF_FAILURE;
    }
    
    let devId = unsafe { (*devNode).devId };
    let observer = unsafe { &mut (*hostService).observer as *mut crate::types::HdfServiceObserver };
    
    crate::src_hdf_service_observer::HdfServiceObserverSubscribeService(observer, serviceName, devId, callback)
}

pub extern "C" fn HdfDeviceGetServiceName(deviceObject: *const crate::types::HdfDeviceObject) -> *const ::core::ffi::c_char {
    use crate::types::*;
    
    if deviceObject.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD002510,
                b"device_object\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to get service name, deviceObject is invalid\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return std::ptr::null();
    }
    
    // Calculate offset of deviceObject field within HdfDeviceNode using offset_of approach
    // Use MaybeUninit to avoid null pointer dereference error
    let offset = {
        let dummy = std::mem::MaybeUninit::<HdfDeviceNode>::uninit();
        let base_ptr = dummy.as_ptr();
        unsafe {
            let field_ptr = std::ptr::addr_of!((*base_ptr).deviceObject);
            (field_ptr as *const u8).offset_from(base_ptr as *const u8) as usize
        }
    };
    
    let devNode = unsafe {
        (deviceObject as *const u8).sub(offset) as *mut HdfDeviceNode
    };
    
    // Return servName from the device node
    unsafe { (*devNode).servName as *const ::core::ffi::c_char }
}

pub extern "C" fn HdfPmRegisterPowerListener(deviceObject: *mut crate::types::HdfDeviceObject, listener: *const crate::types::IPowerEventListener) -> ::core::ffi::c_int {
    if deviceObject.is_null() {
        return crate::types::HDF_ERR_INVALID_PARAM;
    }
    
    // HDF_SLIST_CONTAINER_OF macro expansion:
    // Get the HdfDeviceNode from the embedded deviceObject field
    // offset = offsetof(HdfDeviceNode, deviceObject)
    let offset = std::mem::offset_of!(crate::types::HdfDeviceNode, deviceObject);
    let devNode = unsafe {
        (deviceObject as *mut u8).sub(offset) as *mut crate::types::HdfDeviceNode
    };
    
    crate::src_hdf_device_node::HdfDeviceNodeAddPowerStateListener(devNode, listener)
}

pub extern "C" fn HdfPmUnregisterPowerListener(deviceObject: *mut crate::types::HdfDeviceObject, listener: *const crate::types::IPowerEventListener) {
    if deviceObject.is_null() {
        return;
    }
    
    // Calculate offset of deviceObject field within HdfDeviceNode using offset_of
    let offset = std::mem::offset_of!(crate::types::HdfDeviceNode, deviceObject);
    
    let devNode = unsafe {
        (deviceObject as *mut u8).sub(offset) as *mut crate::types::HdfDeviceNode
    };
    
    crate::src_hdf_device_node::HdfDeviceNodeRemovePowerStateListener(devNode, listener);
}

pub extern "C" fn HdfPmAcquireDevice(deviceObject: *mut crate::types::HdfDeviceObject) {
    let mut devNode: *mut crate::types::HdfDeviceNode = std::ptr::null_mut();
    let mut tokenIf: *mut crate::types::IPowerStateToken = std::ptr::null_mut();
    
    if deviceObject.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"device_object\0".as_ptr() as *const ::core::ffi::c_char,
                b"HdfPmAcquireDevice input param is invalid\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return;
    }
    
    // HDF_SLIST_CONTAINER_OF macro expansion: get HdfDeviceNode from embedded deviceObject
    // offsetof(HdfDeviceNode, deviceObject) calculation
    let offset = std::mem::offset_of!(crate::types::HdfDeviceNode, deviceObject);
    devNode = unsafe {
        ((deviceObject as *mut u8).sub(offset)) as *mut crate::types::HdfDeviceNode
    };
    
    if devNode.is_null() {
        return;
    }
    
    // Get powerToken from devNode
    let power_token = unsafe { (*devNode).powerToken };
    if power_token.is_null() {
        return;
    }
    
    // Get the IPowerStateToken interface (super_ field)
    tokenIf = unsafe { &mut (*power_token).super_ as *mut crate::types::IPowerStateToken };
    
    // Call AcquireWakeLock if available
    if !tokenIf.is_null() {
        unsafe {
            if let Some(acquire_fn) = (*tokenIf).AcquireWakeLock {
                acquire_fn(tokenIf);
            }
        }
    }
}

pub extern "C" fn HdfPmReleaseDevice(deviceObject: *mut crate::types::HdfDeviceObject) {
    let mut devNode: *mut crate::types::HdfDeviceNode = std::ptr::null_mut();
    let mut tokenIf: *mut crate::types::IPowerStateToken = std::ptr::null_mut();
    
    if deviceObject.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"device_object\0".as_ptr() as *const ::core::ffi::c_char,
                b"HdfPmReleaseDevice input param is invalid\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return;
    }
    
    // Calculate offset of deviceObject field within HdfDeviceNode using mem::offset_of equivalent
    // We use a dummy aligned allocation approach to avoid null pointer dereference
    let offset = std::mem::offset_of!(crate::types::HdfDeviceNode, deviceObject);
    devNode = unsafe {
        (deviceObject as *mut u8).sub(offset) as *mut crate::types::HdfDeviceNode
    };
    
    if !devNode.is_null() {
        let powerToken = unsafe { (*devNode).powerToken };
        if !powerToken.is_null() {
            tokenIf = powerToken as *mut crate::types::IPowerStateToken;
            if !tokenIf.is_null() {
                let release_fn = unsafe { (*tokenIf).ReleaseWakeLock };
                if let Some(f) = release_fn {
                    unsafe { f(tokenIf) };
                }
            }
        }
    }
}

pub extern "C" fn HdfPmAcquireDeviceAsync(deviceObject: *mut crate::types::HdfDeviceObject) {
    let mut devNode: *mut crate::types::HdfDeviceNode = std::ptr::null_mut();

    if deviceObject.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"device_object\0".as_ptr() as *const ::core::ffi::c_char,
                b"%{public}s: input param is invalid\0".as_ptr() as *const ::core::ffi::c_char,
                b"HdfPmAcquireDeviceAsync\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return;
    }

    // HDF_SLIST_CONTAINER_OF macro expansion:
    // devNode = (struct HdfDeviceNode *)((char *)deviceObject - offsetof(struct HdfDeviceNode, deviceObject))
    let offset = std::mem::offset_of!(crate::types::HdfDeviceNode, deviceObject);
    devNode = unsafe {
        (deviceObject as *mut u8).sub(offset) as *mut crate::types::HdfDeviceNode
    };

    unsafe {
        crate::src_hdf_power_manager::HdfPmTaskPut(
            (*devNode).powerToken,
            crate::types::HDF_PM_REQUEST_ACQUIRE,
        );
    }
}

pub extern "C" fn HdfPmReleaseDeviceAsync(deviceObject: *mut crate::types::HdfDeviceObject) {
    if deviceObject.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"device_object\0".as_ptr() as *const ::core::ffi::c_char,
                b"%{public}s: input param is invalid\0".as_ptr() as *const ::core::ffi::c_char,
                b"HdfPmReleaseDeviceAsync\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return;
    }

    // container_of macro: get HdfDeviceNode from embedded deviceObject field
    // Use offset_of pattern without null pointer dereference
    let offset = core::mem::offset_of!(crate::types::HdfDeviceNode, deviceObject);
    let devNode: *mut crate::types::HdfDeviceNode = 
        ((deviceObject as *mut u8).wrapping_sub(offset)) as *mut crate::types::HdfDeviceNode;

    unsafe {
        crate::src_hdf_power_manager::HdfPmTaskPut(
            (*devNode).powerToken,
            crate::types::HDF_PM_REQUEST_RELEASE,
        );
    }
}

pub extern "C" fn HdfPmSetMode(deviceObject: *mut crate::types::HdfDeviceObject, mode: u32) {
    let mut devNode: *mut crate::types::HdfDeviceNode = std::ptr::null_mut();
    let mut token: *mut crate::types::PowerStateToken = std::ptr::null_mut();
    
    if deviceObject.is_null() || mode > crate::types::HDF_POWER_MODE_MAX {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"device_object\0".as_ptr() as *const ::core::ffi::c_char,
                b"%{public}s: input param is invalid\0".as_ptr() as *const ::core::ffi::c_char,
                b"HdfPmSetMode\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return;
    }
    
    // HDF_SLIST_CONTAINER_OF macro expansion: get HdfDeviceNode from deviceObject field
    // offsetof(HdfDeviceNode, deviceObject) calculation
    let offset = std::mem::offset_of!(crate::types::HdfDeviceNode, deviceObject);
    devNode = unsafe {
        ((deviceObject as *mut u8).sub(offset)) as *mut crate::types::HdfDeviceNode
    };
    
    if devNode.is_null() {
        return;
    }
    
    token = unsafe { (*devNode).powerToken };
    
    if token.is_null() {
        return;
    }
    
    unsafe {
        (*token).mode = mode;
    }
}

pub extern "C" fn HdfDeviceSetClass(deviceObject: *mut crate::types::HdfDeviceObject, deviceClass: crate::types::DeviceClass) -> bool {
    if deviceObject.is_null() || deviceClass >= crate::types::DEVICE_CLASS_MAX {
        return false;
    }
    unsafe {
        (*deviceObject).deviceClass = deviceClass;
    }
    true
}

pub extern "C" fn HdfDeviceObjectConstruct(deviceObject: *mut crate::types::HdfDeviceObject) {
    if !deviceObject.is_null() {
        unsafe {
            (*deviceObject).property = std::ptr::null();
            (*deviceObject).service = std::ptr::null_mut();
            (*deviceObject).deviceClass = crate::types::DEVICE_CLASS_DEFAULT;
        }
    }
}

pub extern "C" fn HdfDeviceObjectAlloc(parent: *mut crate::types::HdfDeviceObject, driverName: *const ::core::ffi::c_char) -> *mut crate::types::HdfDeviceObject {
    use crate::types::*;
    use crate::compat::*;
    
    if parent.is_null() {
        unsafe {
            HiLogPrint(
                LOG_CORE as u32,
                LOG_ERROR as u32,
                0xD002510,
                b"device_object\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to alloc device, parent invalid\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return std::ptr::null_mut();
    }
    
    // Calculate offset of deviceObject field in HdfDeviceNode using a dummy allocation
    // We use offset_of pattern without dereferencing null
    let offset = std::mem::offset_of!(HdfDeviceNode, deviceObject);
    let parentDevNode = unsafe {
        (parent as *mut u8).sub(offset) as *mut HdfDeviceNode
    };
    
    if unsafe { (*parentDevNode).devStatus } != DEVNODE_LAUNCHED as u8 {
        unsafe {
            HiLogPrint(
                LOG_CORE as u32,
                LOG_ERROR as u32,
                0xD002510,
                b"device_object\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to alloc device, parent status invalid %u\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return std::ptr::null_mut();
    }
    
    let newNode = unsafe {
        HdfObjectManagerGetObject(HDF_OBJECT_ID_DEVICE_SERVICE as i32) as *mut HdfDeviceNode
    };
    if newNode.is_null() {
        return std::ptr::null_mut();
    }
    
    unsafe {
        (*newNode).driverName = HdfStringCopy(driverName);
        if (*newNode).driverName.is_null() {
            crate::src_hdf_device_node::HdfDeviceNodeFreeInstance(newNode);
            return std::ptr::null_mut();
        }
        
        (*newNode).hostService = (*parentDevNode).hostService;
        (*newNode).device = (*parentDevNode).device;
        
        &mut (*newNode).deviceObject as *mut HdfDeviceObject
    }
}

pub extern "C" fn HdfDeviceObjectRelease(dev: *mut crate::types::HdfDeviceObject) {
    if dev.is_null() {
        return;
    }
    
    // CONTAINER_OF macro: devNode = (struct HdfDeviceNode *)((char *)(dev) - (char *)&((struct HdfDeviceNode *)0)->deviceObject)
    // Calculate offset of deviceObject field in HdfDeviceNode
    let offset = std::mem::offset_of!(crate::types::HdfDeviceNode, deviceObject);
    let devNode: *mut crate::types::HdfDeviceNode = unsafe {
        (dev as *mut u8).sub(offset) as *mut crate::types::HdfDeviceNode
    };
    
    unsafe {
        let device = (*devNode).device;
        if !device.is_null() {
            let detach_fn = (*device).super_.Detach;
            if let Some(detach) = detach_fn {
                detach(
                    &mut (*device).super_ as *mut crate::types::IHdfDevice,
                    devNode,
                );
            }
        }
        crate::src_hdf_device_node::HdfDeviceNodeFreeInstance(devNode);
    }
}

pub extern "C" fn HdfDeviceObjectRegister(dev: *mut crate::types::HdfDeviceObject) -> ::core::ffi::c_int {
    use crate::types::*;
    
    let mut ret: ::core::ffi::c_int = HDF_FAILURE;
    
    // CONTAINER_OF: compute offset using memoffset-style calculation
    let offset = std::mem::offset_of!(HdfDeviceNode, deviceObject);
    let devNode: *mut HdfDeviceNode = unsafe {
        (dev as *mut u8).sub(offset) as *mut HdfDeviceNode
    };
    
    let driverLoader: *mut IDriverLoader = crate::src_hdf_driver_loader::HdfDriverLoaderGetInstance();
    
    if dev.is_null() {
        unsafe {
            crate::compat::HiLogPrint(LOG_CORE, LOG_ERROR, 0xD002510, b"device_object\0".as_ptr() as *const ::core::ffi::c_char, b"failed to add device, param invalid\0".as_ptr() as *const ::core::ffi::c_char);
        }
        return HDF_ERR_INVALID_PARAM;
    }
    
    let driver_name = unsafe { (*devNode).driverName };
    let device = unsafe { (*devNode).device };
    
    if driver_name.is_null() || device.is_null() || driverLoader.is_null() {
        unsafe {
            crate::compat::HiLogPrint(LOG_CORE, LOG_ERROR, 0xD002510, b"device_object\0".as_ptr() as *const ::core::ffi::c_char, b"failed to add device, param invalid\0".as_ptr() as *const ::core::ffi::c_char);
        }
        return HDF_ERR_INVALID_PARAM;
    }
    
    let get_driver_fn = unsafe { (*driverLoader).GetDriver };
    if get_driver_fn.is_none() {
        unsafe {
            crate::compat::HiLogPrint(LOG_CORE, LOG_ERROR, 0xD002510, b"device_object\0".as_ptr() as *const ::core::ffi::c_char, b"failed to add device, param invalid\0".as_ptr() as *const ::core::ffi::c_char);
        }
        return HDF_ERR_INVALID_PARAM;
    }
    
    let driver = unsafe { get_driver_fn.unwrap()(driver_name) };
    unsafe { (*devNode).driver = driver; }
    
    if driver.is_null() {
        unsafe {
            crate::compat::HiLogPrint(LOG_CORE, LOG_ERROR, 0xD002510, b"device_object\0".as_ptr() as *const ::core::ffi::c_char, b"can not found driver %{public}s\0".as_ptr() as *const ::core::ffi::c_char, driver_name);
        }
        return HDF_DEV_ERR_NO_DEVICE;
    }
    
    let attach_fn = unsafe { (*device).super_.Attach };
    if let Some(attach) = attach_fn {
        ret = unsafe { attach(&mut (*device).super_ as *mut IHdfDevice, devNode) };
    }
    
    if ret != HDF_SUCCESS {
        unsafe {
            crate::compat::HiLogPrint(LOG_CORE, LOG_ERROR, 0xD002510, b"device_object\0".as_ptr() as *const ::core::ffi::c_char, b"failed to attach device %{public}s\0".as_ptr() as *const ::core::ffi::c_char, driver_name);
        }
        return HDF_DEV_ERR_ATTACHDEV_FAIL;
    }
    
    ret
}

pub extern "C" fn HdfDeviceObjectUnRegister(dev: *mut crate::types::HdfDeviceObject) -> ::core::ffi::c_int {
    unsafe {
        // Calculate offset of deviceObject field within HdfDeviceNode using memoffset-style calculation
        // We need to compute the offset without dereferencing a null pointer
        let dummy: std::mem::MaybeUninit<crate::types::HdfDeviceNode> = std::mem::MaybeUninit::uninit();
        let base_ptr = dummy.as_ptr();
        let field_ptr = std::ptr::addr_of!((*base_ptr).deviceObject);
        let offset = (field_ptr as *const u8).offset_from(base_ptr as *const u8) as usize;
        
        let devNode = (dev as *mut u8).sub(offset) as *mut crate::types::HdfDeviceNode;
        
        if devNode.is_null() || (*devNode).device.is_null() {
            return crate::types::HDF_ERR_INVALID_OBJECT;
        }
        
        let device = (*devNode).device;
        let detach_fn = (*device).super_.Detach;
        
        if let Some(detach) = detach_fn {
            detach(&mut (*device).super_ as *mut crate::types::IHdfDevice, devNode)
        } else {
            crate::types::HDF_ERR_INVALID_OBJECT
        }
    }
}

pub extern "C" fn HdfDeviceObjectPublishService(dev: *mut crate::types::HdfDeviceObject, servName: *const ::core::ffi::c_char, policy: u8, perm: u32) -> ::core::ffi::c_int {
    use crate::types::*;
    
    if dev.is_null() || servName.is_null() {
        return HDF_ERR_INVALID_PARAM;
    }
    
    if policy <= SERVICE_POLICY_NONE as u8 || policy >= SERVICE_POLICY_INVALID as u8 {
        return HDF_DEV_ERR_NO_DEVICE_SERVICE;
    }
    
    // CONTAINER_OF: devNode = (HdfDeviceNode*)((char*)dev - offsetof(HdfDeviceNode, deviceObject))
    let offset = core::mem::offset_of!(HdfDeviceNode, deviceObject);
    let devNode: *mut HdfDeviceNode = unsafe {
        (dev as *mut u8).sub(offset) as *mut HdfDeviceNode
    };
    
    unsafe {
        if (*devNode).servStatus {
            let _ = crate::compat::HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD002510,
                b"device_object\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to publish public service, repeat publish\0".as_ptr() as *const ::core::ffi::c_char,
            );
            return HDF_FAILURE;
        }
        
        (*devNode).servName = crate::compat::HdfStringCopy(servName);
        if (*devNode).servName.is_null() {
            return HDF_DEV_ERR_NO_MEMORY;
        }
        
        (*devNode).policy = policy as u16;
        (*devNode).permission = perm as u16;
        
        let ret = crate::src_hdf_device_node::DeviceDriverBind(devNode);
        if ret != HDF_SUCCESS {
            return ret;
        }
        
        if let Some(publish_fn) = (*devNode).super_.PublishService {
            publish_fn(devNode)
        } else {
            HDF_FAILURE
        }
    }
}

pub extern "C" fn HdfDeviceObjectRemoveService(dev: *mut crate::types::HdfDeviceObject) -> ::core::ffi::c_int {
    if dev.is_null() {
        return crate::types::HDF_ERR_INVALID_PARAM;
    }
    
    // CONTAINER_OF macro: devNode = (struct HdfDeviceNode *)((char *)(dev) - (char *)&((struct HdfDeviceNode *)0)->deviceObject)
    // Calculate offset of deviceObject field in HdfDeviceNode
    let offset = std::mem::offset_of!(crate::types::HdfDeviceNode, deviceObject);
    let devNode: *mut crate::types::HdfDeviceNode = unsafe {
        (dev as *mut u8).sub(offset) as *mut crate::types::HdfDeviceNode
    };
    
    unsafe {
        if let Some(remove_service) = (*devNode).super_.RemoveService {
            remove_service(devNode)
        } else {
            crate::types::HDF_ERR_INVALID_PARAM
        }
    }
}

pub extern "C" fn HdfDeviceObjectSetServInfo(dev: *mut crate::types::HdfDeviceObject, info: *const ::core::ffi::c_char) -> ::core::ffi::c_int {
    use crate::types::*;
    use crate::compat::*;
    
    const SERVICE_INFO_LEN_MAX: usize = 128;
    
    if dev.is_null() || info.is_null() {
        return HDF_ERR_INVALID_PARAM;
    }
    
    let info_len = unsafe { libc::strlen(info) };
    if info_len > SERVICE_INFO_LEN_MAX {
        return HDF_ERR_INVALID_PARAM;
    }
    
    // Calculate offset using memoffset-style approach without null deref
    let offset = {
        let base: usize = 0;
        let field_ptr = unsafe {
            &(*((base as *const u8) as *const HdfDeviceNode)).deviceObject as *const _ as usize
        };
        field_ptr - base
    };
    let devNode = unsafe {
        (dev as *mut u8).sub(offset) as *mut HdfDeviceNode
    };
    
    unsafe {
        if !(*devNode).servInfo.is_null() {
            OsalMemFree((*devNode).servInfo as *mut ::core::ffi::c_void);
        }
        (*devNode).servInfo = HdfStringCopy(info);
        if (*devNode).servInfo.is_null() {
            return HDF_ERR_MALLOC_FAIL;
        }
    }
    
    HDF_SUCCESS
}

pub extern "C" fn HdfDeviceObjectUpdate(dev: *mut crate::types::HdfDeviceObject) -> ::core::ffi::c_int {
    if dev.is_null() {
        return crate::types::HDF_ERR_INVALID_PARAM;
    }
    
    // CONTAINER_OF macro: devNode = (struct HdfDeviceNode *)((char *)(dev) - (char *)&((struct HdfDeviceNode *)0)->deviceObject)
    // Use offset_of pattern without dereferencing null pointer
    let offset = std::mem::offset_of!(crate::types::HdfDeviceNode, deviceObject);
    let devNode = unsafe {
        (dev as *mut u8).sub(offset) as *mut crate::types::HdfDeviceNode
    };
    
    // Initialize HdfServiceInfo from devNode (inline HdfServiceInfoInit)
    let mut servInfo: crate::types::HdfServiceInfo = unsafe { std::mem::zeroed() };
    unsafe {
        servInfo.servName = (*devNode).servName as *const ::core::ffi::c_char;
        servInfo.servInfo = (*devNode).servInfo;
        servInfo.devClass = (*devNode).deviceObject.deviceClass as u16;
        servInfo.devId = (*devNode).devId;
        servInfo.interfaceDesc = (*devNode).interfaceDesc as *const ::core::ffi::c_char;
    }
    
    unsafe {
        crate::src_devsvc_manager_clnt::DevSvcManagerClntUpdateService(
            &mut (*devNode).deviceObject as *mut crate::types::HdfDeviceObject,
            &servInfo as *const crate::types::HdfServiceInfo
        )
    }
}

pub extern "C" fn HdfDeviceObjectSetInterfaceDesc(dev: *mut crate::types::HdfDeviceObject, interfaceDesc: *const ::core::ffi::c_char) -> ::core::ffi::c_int {
    use crate::types::*;
    use crate::compat::*;
    
    if dev.is_null() || interfaceDesc.is_null() {
        return HDF_ERR_INVALID_PARAM;
    }
    
    // CONTAINER_OF macro: devNode = (struct HdfDeviceNode *)((char *)(dev) - (char *)&((struct HdfDeviceNode *)0)->deviceObject)
    // Calculate offset of deviceObject field in HdfDeviceNode using offset_of approach
    let offset = std::mem::offset_of!(HdfDeviceNode, deviceObject);
    let devNode = unsafe {
        (dev as *mut u8).sub(offset) as *mut HdfDeviceNode
    };
    
    unsafe {
        (*devNode).interfaceDesc = HdfStringCopy(interfaceDesc);
        if (*devNode).interfaceDesc.is_null() {
            HDF_ERR_MALLOC_FAIL
        } else {
            HDF_SUCCESS
        }
    }
}

pub extern "C" fn HdfDeviceObjectCheckInterfaceDesc(dev: *mut crate::types::HdfDeviceObject, data: *mut crate::types::HdfSBuf) -> bool {
    let _ = dev;
    let _ = data;
    true
}
