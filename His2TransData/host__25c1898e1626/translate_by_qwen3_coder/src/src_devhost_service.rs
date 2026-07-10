//! Module: src_devhost_service
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

fn DevHostServiceFindDevice(hostService: *mut crate::types::DevHostService, deviceId: u16) -> *mut crate::types::HdfDevice {
    if hostService.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devhost_service\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to find driver, hostService is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return std::ptr::null_mut();
    }

    unsafe {
        let devices_head = &(*hostService).devices as *const crate::types::DListHead;
        let node_offset = core::mem::offset_of!(crate::types::HdfDevice, node);
        
        let mut current_node = (*devices_head).next;
        
        while current_node != devices_head as *mut crate::types::DListHead {
            let device = (current_node as *mut u8).sub(node_offset) as *mut crate::types::HdfDevice;
            
            let dev_id = (*device).deviceId;
            let extracted_id = ((dev_id >> 8) & ((1 << 16) - 1)) as u16;
            
            if extracted_id == deviceId {
                return device;
            }
            
            current_node = (*current_node).next;
        }
    }
    
    std::ptr::null_mut()
}

fn DevHostServiceFreeDevice(hostService: *mut crate::types::DevHostService, device: *mut crate::types::HdfDevice) {
    let _ = hostService;
    if !device.is_null() {
        unsafe {
            let entry = &mut (*device).node;
            (*(*entry).prev).next = (*entry).next;
            (*(*entry).next).prev = (*entry).prev;
            (*entry).prev = std::ptr::null_mut();
            (*entry).next = std::ptr::null_mut();
        }
        crate::src_hdf_device::HdfDeviceFreeInstance(device);
    }
}

fn DevHostServiceQueryOrAddDevice(inst: *mut crate::types::DevHostService, deviceId: u16) -> *mut crate::types::HdfDevice {
    let mut device = crate::src_devhost_service::DevHostServiceFindDevice(inst, deviceId);
    if device.is_null() {
        device = unsafe { crate::src_hdf_device::HdfDeviceNewInstance() };
        if device.is_null() {
            return std::ptr::null_mut();
        }
        unsafe {
            let host_id = (*inst).hostId as u32;
            (*device).deviceId = (host_id << (16 + 8)) | ((deviceId as u32) << 8) | 0;
            
            // DListInsertHead inline implementation
            let entry = &mut (*device).node as *mut crate::types::DListHead;
            let head = &mut (*inst).devices as *mut crate::types::DListHead;
            (*entry).next = (*head).next;
            (*entry).prev = head;
            (*(*head).next).prev = entry;
            (*head).next = entry;
        }
    }
    device
}

pub extern "C" fn DevHostServiceAddDevice(inst: *mut crate::types::IDevHostService, deviceInfo: *const crate::types::HdfDeviceInfo) -> ::core::ffi::c_int {
    use crate::types::*;
    
    let mut ret: ::core::ffi::c_int = HDF_FAILURE;
    let mut device: *mut HdfDevice = std::ptr::null_mut();
    let mut devNode: *mut HdfDeviceNode = std::ptr::null_mut();
    let mut driver: *mut HdfDriver = std::ptr::null_mut();
    
    // CONTAINER_OF: hostService = (DevHostService*)((char*)inst - offsetof(DevHostService, super_))
    let hostService: *mut DevHostService = unsafe {
        let offset = core::mem::offset_of!(DevHostService, super_);
        (inst as *mut u8).sub(offset) as *mut DevHostService
    };
    
    let driverLoader: *mut IDriverLoader = crate::src_hdf_driver_loader::HdfDriverLoaderGetInstance();
    
    if inst.is_null() || deviceInfo.is_null() || driverLoader.is_null() {
        unsafe { crate::compat::HiLogPrint(LOG_CORE, LOG_ERROR, 0xD002510, b"devhost_service\0".as_ptr() as *const _, b"failed to add device, input param is null\0".as_ptr() as *const _) };
        return ret;
    }
    
    let get_driver_fn = unsafe { (*driverLoader).GetDriver };
    if get_driver_fn.is_none() {
        unsafe { crate::compat::HiLogPrint(LOG_CORE, LOG_ERROR, 0xD002510, b"devhost_service\0".as_ptr() as *const _, b"failed to add device, input param is null\0".as_ptr() as *const _) };
        return ret;
    }
    
    let device_id_raw = unsafe { (*deviceInfo).deviceId };
    let device_id_extracted: u16 = ((device_id_raw >> 8) & ((1 << 16) - 1)) as u16;
    
    device = crate::src_devhost_service::DevHostServiceQueryOrAddDevice(hostService, device_id_extracted);
    
    if device.is_null() || unsafe { (*device).super_.Attach }.is_none() {
        unsafe { crate::compat::HiLogPrint(LOG_CORE, LOG_ERROR, 0xD002510, b"devhost_service\0".as_ptr() as *const _, b"failed to add device, device or Attach func is null\0".as_ptr() as *const _) };
        return HDF_DEV_ERR_NO_DEVICE;
    }
    
    let get_device_node_fn = unsafe { (*device).super_.GetDeviceNode };
    if let Some(f) = get_device_node_fn {
        devNode = unsafe { f(&mut (*device).super_, device_id_raw) };
    }
    
    if !devNode.is_null() {
        unsafe { crate::compat::HiLogPrint(LOG_CORE, LOG_ERROR, 0xD002510, b"devhost_service\0".as_ptr() as *const _, b"failed to add device, device already exist\0".as_ptr() as *const _) };
        return HDF_ERR_DEVICE_BUSY;
    }
    
    let module_name = unsafe { (*deviceInfo).moduleName };
    if let Some(f) = get_driver_fn {
        driver = unsafe { f(module_name) };
    }
    
    if driver.is_null() {
        unsafe { crate::compat::HiLogPrint(LOG_CORE, LOG_ERROR, 0xD002510, b"devhost_service\0".as_ptr() as *const _, b"failed to add device %s, get driver failed\0".as_ptr() as *const _) };
        ret = HDF_DEV_ERR_NODATA;
        let dev_nodes_head = unsafe { &(*device).devNodes };
        let is_empty = unsafe { (*dev_nodes_head).next == dev_nodes_head as *const _ as *mut _ };
        if is_empty {
            crate::src_devhost_service::DevHostServiceFreeDevice(hostService, device);
        }
        return ret;
    }
    
    devNode = crate::src_hdf_device_node::HdfDeviceNodeNewInstance(deviceInfo, driver);
    if devNode.is_null() {
        unsafe { crate::compat::HiLogPrint(LOG_CORE, LOG_ERROR, 0xD002510, b"devhost_service\0".as_ptr() as *const _, b"failed to add device, create devNode failed\0".as_ptr() as *const _) };
        if let Some(reclaim) = unsafe { (*driverLoader).ReclaimDriver } {
            unsafe { reclaim(driver) };
        }
        return HDF_DEV_ERR_NO_MEMORY;
    }
    
    unsafe {
        (*devNode).hostService = hostService;
        (*devNode).device = device;
        (*devNode).driver = driver;
    }
    
    if let Some(attach_fn) = unsafe { (*device).super_.Attach } {
        ret = unsafe { attach_fn(&mut (*device).super_, devNode) };
    }
    
    if ret != HDF_SUCCESS {
        unsafe { crate::compat::HiLogPrint(LOG_CORE, LOG_ERROR, 0xD002510, b"devhost_service\0".as_ptr() as *const _, b"failed to add device, attach devNode failed\0".as_ptr() as *const _) };
        crate::src_hdf_device_node::HdfDeviceNodeFreeInstance(devNode);
        let dev_nodes_head = unsafe { &(*device).devNodes };
        let is_empty = unsafe { (*dev_nodes_head).next == dev_nodes_head as *const _ as *mut _ };
        if is_empty {
            crate::src_devhost_service::DevHostServiceFreeDevice(hostService, device);
        }
        return ret;
    }
    
    unsafe { crate::compat::HiLogPrint(LOG_CORE, LOG_DEBUG, 0xD002510, b"devhost_service\0".as_ptr() as *const _, b"%s add device success\0".as_ptr() as *const _) };
    HDF_SUCCESS
}

pub extern "C" fn DevHostServiceDelDevice(inst: *mut crate::types::IDevHostService, devId: crate::types::devid_t) -> ::core::ffi::c_int {
    let mut device: *mut crate::types::HdfDevice = std::ptr::null_mut();
    let hostService: *mut crate::types::DevHostService = inst as *mut crate::types::DevHostService;
    let mut devNode: *mut crate::types::HdfDeviceNode = std::ptr::null_mut();

    let deviceId: u16 = (((devId as u32) >> 8) & ((1 << 16) - 1)) as u16;
    device = crate::src_devhost_service::DevHostServiceFindDevice(hostService, deviceId);
    if device.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_WARN,
                0xD002510,
                b"devhost_service\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to del device, device is not exist\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return crate::types::HDF_SUCCESS;
    }

    unsafe {
        let get_device_node_fn = (*device).super_.GetDeviceNode;
        if let Some(f) = get_device_node_fn {
            devNode = f(&mut (*device).super_ as *mut crate::types::IHdfDevice, devId);
        }
    }
    if devNode.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_INFO,
                0xD002510,
                b"devhost_service\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to del device, not exist\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return crate::types::HDF_DEV_ERR_NO_DEVICE;
    }

    unsafe {
        let detach_fn = (*device).super_.Detach;
        if detach_fn.is_none() {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devhost_service\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to del device, invalid device\0".as_ptr() as *const ::core::ffi::c_char,
            );
            return crate::types::HDF_ERR_INVALID_OBJECT;
        }

        if let Some(f) = detach_fn {
            if f(&mut (*device).super_ as *mut crate::types::IHdfDevice, devNode) != crate::types::HDF_SUCCESS {
                crate::compat::HiLogPrint(
                    crate::types::LOG_CORE,
                    crate::types::LOG_ERROR,
                    0xD002510,
                    b"devhost_service\0".as_ptr() as *const ::core::ffi::c_char,
                    b"failed to detach device\0".as_ptr() as *const ::core::ffi::c_char,
                );
                return crate::types::HDF_FAILURE;
            }
        }
    }

    crate::src_hdf_device_node::HdfDeviceNodeFreeInstance(devNode);

    unsafe {
        let head = &(*device).devNodes as *const crate::types::DListHead;
        let is_empty = (*head).next == head as *mut crate::types::DListHead;
        if is_empty {
            crate::src_devhost_service::DevHostServiceFreeDevice(hostService, device);
        }
    }

    unsafe {
        crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_DEBUG,
            0xD002510,
            b"devhost_service\0".as_ptr() as *const ::core::ffi::c_char,
            b"%s add device success\0".as_ptr() as *const ::core::ffi::c_char,
            b"DevHostServiceDelDevice\0".as_ptr() as *const ::core::ffi::c_char,
        );
    }

    crate::types::HDF_SUCCESS
}

fn DevHostServiceStartService(service: *mut crate::types::IDevHostService) -> i32 {
    let hostService = service as *mut crate::types::DevHostService;
    if hostService.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD002510,
                b"devhost_service\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to start device service, hostService is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return crate::types::HDF_FAILURE;
    }
    let host_id = unsafe { (*hostService).hostId };
    crate::src_devmgr_service_clnt::DevmgrServiceClntAttachDeviceHost(host_id, service)
}

fn ApplyDevicesPowerState(device: *mut crate::types::HdfDevice, state: u32) -> i32 {
    use crate::types::*;
    
    // Inline IsPowerWakeState logic
    fn is_power_wake_state(state: u32) -> bool {
        state == POWER_STATE_DOZE_RESUME || state == POWER_STATE_RESUME
    }
    
    const POWER_STATE_DOZE_RESUME: u32 = 0;
    const POWER_STATE_RESUME: u32 = 2;
    
    if device.is_null() {
        return HDF_SUCCESS;
    }
    
    unsafe {
        let dev_nodes_head = &(*device).devNodes as *const DListHead;
        let entry_offset = std::mem::offset_of!(HdfDeviceNode, entry);
        
        if is_power_wake_state(state) {
            // Forward iteration
            let mut current = (*dev_nodes_head).next;
            while current != dev_nodes_head as *mut DListHead {
                let device_node = (current as *mut u8).sub(entry_offset) as *mut HdfDeviceNode;
                if !(*device_node).powerToken.is_null() {
                    let ret = crate::src_power_state_token::PowerStateChange((*device_node).powerToken, state);
                    if ret != HDF_SUCCESS {
                        // Log error - simplified, just continue
                    }
                }
                current = (*current).next;
            }
        } else {
            // Reverse iteration
            let mut current = (*dev_nodes_head).prev;
            while current != dev_nodes_head as *mut DListHead {
                let device_node = (current as *mut u8).sub(entry_offset) as *mut HdfDeviceNode;
                if !(*device_node).powerToken.is_null() {
                    let ret = crate::src_power_state_token::PowerStateChange((*device_node).powerToken, state);
                    if ret != HDF_SUCCESS {
                        // Log error - simplified, just continue
                    }
                }
                current = (*current).prev;
            }
        }
    }
    
    HDF_SUCCESS
}

fn DevHostServicePmNotify(service: *mut crate::types::IDevHostService, state: u32) -> i32 {
    use crate::types::*;
    
    let mut device: *mut HdfDevice = std::ptr::null_mut();
    let mut ret: i32 = HDF_SUCCESS;
    
    // CONTAINER_OF: hostService = (DevHostService*)((char*)service - offsetof(DevHostService, super_))
    let offset = std::mem::offset_of!(DevHostService, super_) as isize;
    let hostService: *mut DevHostService = unsafe {
        (service as *mut u8).offset(-offset) as *mut DevHostService
    };
    
    if hostService.is_null() {
        unsafe {
            crate::compat::HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD002510,
                b"devhost_service\0".as_ptr() as *const ::core::ffi::c_char,
                b"failed to start device service, hostService is null\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return HDF_FAILURE;
    }
    
    unsafe {
        crate::compat::HiLogPrint(
            LOG_CORE,
            LOG_DEBUG,
            0xD002510,
            b"devhost_service\0".as_ptr() as *const ::core::ffi::c_char,
            b"host(%s) set power state=%u\0".as_ptr() as *const ::core::ffi::c_char,
            (*hostService).hostName,
            state,
        );
    }
    
    // Inline IsPowerWakeState
    let is_wake_state = state == POWER_STATE_DOZE_RESUME || state == POWER_STATE_RESUME;
    
    let node_offset = std::mem::offset_of!(HdfDevice, node) as isize;
    
    if is_wake_state {
        // DLIST_FOR_EACH_ENTRY_REVERSE (iterate via prev)
        unsafe {
            let devices_head = &(*hostService).devices as *const DListHead;
            let mut current = (*devices_head).prev;
            while current != devices_head as *mut DListHead {
                device = (current as *mut u8).offset(-node_offset) as *mut HdfDevice;
                if crate::src_devhost_service::ApplyDevicesPowerState(device, state) != HDF_SUCCESS {
                    ret = HDF_FAILURE;
                }
                current = (*current).prev;
            }
        }
    } else {
        // DLIST_FOR_EACH_ENTRY (iterate via next)
        unsafe {
            let devices_head = &(*hostService).devices as *const DListHead;
            let mut current = (*devices_head).next;
            while current != devices_head as *mut DListHead {
                device = (current as *mut u8).offset(-node_offset) as *mut HdfDevice;
                if crate::src_devhost_service::ApplyDevicesPowerState(device, state) != HDF_SUCCESS {
                    ret = HDF_FAILURE;
                }
                current = (*current).next;
            }
        }
    }
    
    ret
}

pub extern "C" fn DevHostServiceConstruct(service: *mut crate::types::DevHostService) {
    if service.is_null() {
        return;
    }
    
    unsafe {
        let hostServiceIf: *mut crate::types::IDevHostService = &mut (*service).super_;
        (*hostServiceIf).AddDevice = Some(DevHostServiceAddDevice);
        (*hostServiceIf).DelDevice = Some(DevHostServiceDelDevice);
        (*hostServiceIf).StartService = Some(std::mem::transmute::<fn(*mut crate::types::IDevHostService) -> i32, unsafe extern "C" fn(*mut crate::types::IDevHostService) -> ::core::ffi::c_int>(DevHostServiceStartService));
        (*hostServiceIf).PmNotify = Some(std::mem::transmute::<fn(*mut crate::types::IDevHostService, u32) -> i32, unsafe extern "C" fn(*mut crate::types::IDevHostService, u32) -> ::core::ffi::c_int>(DevHostServicePmNotify));
        
        // Inline DListHeadInit
        let head: *mut crate::types::DListHead = &mut (*service).devices;
        (*head).next = head;
        (*head).prev = head;
        
        let _ = crate::src_hdf_service_observer::HdfServiceObserverConstruct(&mut (*service).observer);
    }
}

pub extern "C" fn DevHostServiceDestruct(service: *mut crate::types::DevHostService) {
    if service.is_null() {
        return;
    }

    unsafe {
        // Get the head of the devices list
        let devices_head: *mut crate::types::DListHead = &mut (*service).devices;
        
        // Calculate offset of 'node' field in HdfDevice
        let node_offset = std::mem::offset_of!(crate::types::HdfDevice, node);
        
        // Get first entry
        let mut current_node: *mut crate::types::DListHead = (*devices_head).next;
        
        while current_node != devices_head {
            // Calculate device pointer from node pointer
            let device: *mut crate::types::HdfDevice = 
                ((current_node as *mut u8).sub(node_offset)) as *mut crate::types::HdfDevice;
            
            // Save next before freeing
            let next_node: *mut crate::types::DListHead = (*current_node).next;
            
            crate::src_hdf_device::HdfDeviceFreeInstance(device);
            
            current_node = next_node;
        }
        
        crate::src_hdf_service_observer::HdfServiceObserverDestruct(&mut (*service).observer);
    }
}

pub extern "C" fn DevHostServiceCreate() -> *mut crate::types::HdfObject {
    let devHostService = unsafe {
        crate::compat::OsalMemCalloc(std::mem::size_of::<crate::types::DevHostService>() as u32)
    } as *mut crate::types::DevHostService;
    
    if !devHostService.is_null() {
        crate::src_devhost_service::DevHostServiceConstruct(devHostService);
    }
    
    devHostService as *mut crate::types::HdfObject
}

pub extern "C" fn DevHostServiceRelease(object: *mut crate::types::HdfObject) {
    let devHostService = object as *mut crate::types::DevHostService;
    if !devHostService.is_null() {
        crate::src_devhost_service::DevHostServiceDestruct(devHostService);
        unsafe {
            crate::compat::OsalMemFree(devHostService as *mut ::core::ffi::c_void);
        }
    }
}

pub extern "C" fn DevHostServiceNewInstance(hostId: u16, hostName: *const ::core::ffi::c_char) -> *mut crate::types::IDevHostService {
    let hostService = unsafe { crate::compat::HdfObjectManagerGetObject(crate::types::HDF_OBJECT_ID_DEVHOST_SERVICE as i32) } as *mut crate::types::DevHostService;
    if !hostService.is_null() && !hostName.is_null() {
        unsafe {
            (*hostService).hostId = hostId;
            (*hostService).hostName = hostName;
        }
    }
    hostService as *mut crate::types::IDevHostService
}

pub extern "C" fn DevHostServiceFreeInstance(service: *mut crate::types::IDevHostService) {
    if !service.is_null() {
        unsafe {
            crate::compat::HdfObjectManagerFreeObject(&mut (*service).object as *mut crate::types::HdfObject);
        }
    }
}
