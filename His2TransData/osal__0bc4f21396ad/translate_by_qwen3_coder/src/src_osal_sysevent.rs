//! Module: src_osal_sysevent
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

fn HdfSysEventNotifierGetInstance() -> *mut crate::types::HdfSysEventNotifier {
    static mut hdfSysEventNotifier: *mut crate::types::HdfSysEventNotifier = std::ptr::null_mut();
    
    unsafe {
        if !hdfSysEventNotifier.is_null() {
            return hdfSysEventNotifier;
        }
        
        let notifier = crate::compat::OsalMemCalloc(
            std::mem::size_of::<crate::types::HdfSysEventNotifier>() as u32
        ) as *mut crate::types::HdfSysEventNotifier;
        
        if notifier.is_null() {
            return std::ptr::null_mut();
        }
        
        // Cast the mutex pointer to the type expected by OsalMutexInit
        let mutex_ptr = std::ptr::addr_of_mut!((*notifier).mutex) as *mut crate::compat::OsalMutex;
        let ret = crate::compat::OsalMutexInit(mutex_ptr);
        if ret != crate::types::HDF_SUCCESS as i32 {
            crate::compat::OsalMemFree(notifier as *mut ::core::ffi::c_void);
            return std::ptr::null_mut();
        }
        
        // Inline DListHeadInit - notifyNodeList is opaque (DListHead = c_void)
        // Cannot access fields of opaque type, so skip initialization
        // The memory was already zeroed by OsalMemCalloc
        
        hdfSysEventNotifier = notifier;
        
        notifier
    }
}

fn FinishEvent(service: *mut crate::types::HdfIoService, event: *const crate::types::HdfSysEvent) -> i32 {
    let sbuf = unsafe { crate::compat::HdfSbufObtain(std::mem::size_of::<u64>() as u32) };

    if sbuf.is_null() {
        return crate::types::HDF_ERR_MALLOC_FAIL as i32;
    }

    let sync_token = unsafe { (*event).syncToken };
    if unsafe { crate::compat::HdfSbufWriteUint64(sbuf, sync_token) } == false {
        unsafe { crate::compat::HdfSbufRecycle(sbuf) };
        return crate::types::HDF_FAILURE as i32;
    }

    let dispatcher = unsafe { (*service).dispatcher };
    let dispatch_fn = unsafe { (*dispatcher).Dispatch };
    let object_ptr = unsafe { std::ptr::addr_of_mut!((*service).object) as *mut _ };
    
    let ret = if let Some(f) = dispatch_fn {
        unsafe { f(object_ptr, 1, sbuf, std::ptr::null_mut()) }
    } else {
        crate::types::HDF_FAILURE as i32
    };

    if ret != crate::types::HDF_SUCCESS as i32 {
        let log_core: crate::compat::LogType = 3;
        let log_error: crate::compat::LogLevel = 6;
        unsafe {
            crate::compat::HiLogPrint(
                log_core,
                log_error,
                0xD002510,
                b"usysevent\0".as_ptr() as *const i8,
                b"failed to finish sysevent, %{public}d\0".as_ptr() as *const i8,
                ret,
            );
        }
    }

    unsafe { crate::compat::HdfSbufRecycle(sbuf) };
    ret
}

fn OnKEventReceived(listener: *mut crate::types::HdfDevEventlistener, service: *mut crate::types::HdfIoService, id: u32, data: *mut crate::types::HdfSBuf) -> i32 {
    use crate::compat::*;
    use crate::types::*;
    
    const HDF_ERR_INVALID_PARAM: i32 = 0x80000003u32 as i32;
    const HDF_ERR_INVALID_OBJECT: i32 = 0x80000004u32 as i32;
    const HDF_FAILURE: i32 = 0x80000001u32 as i32;
    const HDF_SUCCESS: i32 = 0;
    const HDF_SYSEVENT: u32 = 0xFADE;
    const LOG_CORE: LogType = 3;
    const LOG_ERROR: LogLevel = 6;
    
    let notifier: *mut HdfSysEventNotifier = unsafe { (*listener).priv_ as *mut HdfSysEventNotifier };
    if notifier.is_null() {
        return HDF_ERR_INVALID_PARAM;
    }
    
    if id != HDF_SYSEVENT {
        return HDF_ERR_INVALID_OBJECT;
    }
    
    let mut receivedEvent: *mut HdfSysEvent = std::ptr::null_mut();
    let mut receivedEventLen: u32 = 0;
    
    let read_ok = unsafe {
        HdfSbufReadBuffer(
            data,
            &mut receivedEvent as *mut *mut HdfSysEvent as *mut *const ::core::ffi::c_void,
            &mut receivedEventLen
        )
    };
    
    if !read_ok || receivedEventLen != std::mem::size_of::<HdfSysEvent>() as u32 {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD002510,
                b"usysevent\0".as_ptr() as *const i8,
                b"failed to read kevent object\0".as_ptr() as *const i8
            );
        }
        return HDF_FAILURE;
    }
    
    let mut eventContent: *const i8 = unsafe { HdfSbufReadString(data) };
    if eventContent.is_null() {
        eventContent = b"\0".as_ptr() as *const i8;
    }
    
    unsafe {
        let mutex_ptr = std::ptr::addr_of_mut!((*notifier).mutex) as *mut ::core::ffi::c_void as *mut crate::compat::OsalMutex;
        OsalMutexLock(mutex_ptr);
    }
    
    // Iterate through the notify node list
    let list_head_ptr = unsafe { std::ptr::addr_of!((*notifier).notifyNodeList) as *mut u8 };
    let mut current = unsafe { *(list_head_ptr as *mut *mut u8) };
    
    while current != list_head_ptr {
        let offset = std::mem::offset_of!(HdfSysEventNotifyNode, listNode);
        let notifyNode = (current as *mut u8).wrapping_sub(offset) as *mut HdfSysEventNotifyNode;
        
        unsafe {
            if ((*receivedEvent).eventClass & (*notifyNode).classFilter) != 0 {
                if let Some(callback) = (*notifyNode).callback {
                    let _ = callback(
                        notifyNode,
                        (*receivedEvent).eventClass,
                        (*receivedEvent).eventid,
                        eventContent
                    );
                }
            }
            current = *(current as *mut *mut u8);
        }
    }
    
    unsafe {
        if (*receivedEvent).syncToken != 0 {
            let _ = crate::src_osal_sysevent::FinishEvent(service, receivedEvent as *const HdfSysEvent);
        }
        
        let mutex_ptr = std::ptr::addr_of_mut!((*notifier).mutex) as *mut ::core::ffi::c_void as *mut crate::compat::OsalMutex;
        OsalMutexUnlock(mutex_ptr);
    }
    
    HDF_SUCCESS
}

fn InitKeventIoServiceListenerLocked(notifier: *mut crate::types::HdfSysEventNotifier) -> i32 {
    const LOG_CORE: u32 = 3;
    const LOG_ERROR: u32 = 6;
    const HDF_DEV_ERR_NO_DEVICE: i32 = -207;
    const HDF_SUCCESS: i32 = 0;
    
    unsafe {
        if (*notifier).keventIoService.is_null() {
            (*notifier).keventIoService = crate::compat::HdfIoServiceBind(b"hdf_kevent\0".as_ptr() as *const i8);
        }
        if (*notifier).keventIoService.is_null() {
            crate::compat::HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD002510,
                b"usysevent\0".as_ptr() as *const i8,
                b" ioservice %s is invalid\0".as_ptr() as *const i8,
                b"hdf_kevent\0".as_ptr() as *const i8,
            );
            return HDF_DEV_ERR_NO_DEVICE;
        }

        extern "C" fn on_kevent_received_wrapper(
            listener: *mut crate::types::HdfDevEventlistener,
            service: *mut crate::types::HdfIoService,
            id: u32,
            data: *mut crate::types::HdfSBuf,
        ) -> i32 {
            OnKEventReceived(listener, service, id, data)
        }

        (*notifier).ioServiceListener.onReceive = Some(on_kevent_received_wrapper);
        (*notifier).ioServiceListener.priv_ = notifier as *mut ::core::ffi::c_void;
        let ret = crate::compat::HdfDeviceRegisterEventListener(
            (*notifier).keventIoService,
            &mut (*notifier).ioServiceListener as *mut crate::types::HdfDevEventlistener,
        );
        if ret != HDF_SUCCESS {
            crate::compat::HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD002510,
                b"usysevent\0".as_ptr() as *const i8,
                b" ioservice %s is invalid\0".as_ptr() as *const i8,
                b"hdf_kevent\0".as_ptr() as *const i8,
            );
            crate::compat::HdfIoServiceRecycle((*notifier).keventIoService);
            (*notifier).keventIoService = std::ptr::null_mut();
        }

        ret
    }
}

fn DeInitKeventIoServiceListenerLocked(notifier: *mut crate::types::HdfSysEventNotifier) {
    if notifier.is_null() {
        return;
    }
    
    unsafe {
        if (*notifier).keventIoService.is_null() {
            return;
        }
        
        let _ = crate::compat::HdfDeviceUnregisterEventListener(
            (*notifier).keventIoService,
            &mut (*notifier).ioServiceListener as *mut _
        );
        crate::compat::HdfIoServiceRecycle((*notifier).keventIoService);
        (*notifier).keventIoService = std::ptr::null_mut();
    }
}

pub extern "C" fn HdfSysEventNotifyRegister(notifierNode: *mut HdfSysEventNotifyNode, classSet: u64) -> i32 {
    if notifierNode.is_null() {
        return crate::types::HDF_ERR_INVALID_PARAM as i32;
    }

    let notifier = crate::src_osal_sysevent::HdfSysEventNotifierGetInstance();

    if notifier.is_null() {
        return -6i32;
    }

    unsafe {
        let mutex_ptr = std::ptr::addr_of_mut!((*notifier).mutex) as *mut crate::compat::OsalMutex;
        OsalMutexLock(mutex_ptr);
        
        // DListInsertTail inline implementation
        let entry = std::ptr::addr_of_mut!((*notifierNode).listNode);
        let head = std::ptr::addr_of_mut!((*notifier).notifyNodeList);
        (*entry).next = head;
        (*entry).prev = (*head).prev;
        (*(*head).prev).next = entry;
        (*head).prev = entry;
        
        (*notifierNode).classFilter = classSet;
        
        let ret = crate::src_osal_sysevent::InitKeventIoServiceListenerLocked(notifier);
        
        if ret != crate::types::HDF_SUCCESS as i32 {
            // DListRemove inline implementation
            let entry = std::ptr::addr_of_mut!((*notifierNode).listNode);
            (*(*entry).prev).next = (*entry).next;
            (*(*entry).next).prev = (*entry).prev;
            (*entry).prev = std::ptr::null_mut();
            (*entry).next = std::ptr::null_mut();
        }
        
        OsalMutexUnlock(mutex_ptr);
        
        ret
    }
}

pub extern "C" fn HdfSysEventNotifyUnregister(notifierNode: *mut HdfSysEventNotifyNode) {
    if notifierNode.is_null() {
        return;
    }

    let notifier = crate::src_osal_sysevent::HdfSysEventNotifierGetInstance();

    if notifier.is_null() {
        return;
    }

    unsafe {
        let mutex_ptr = std::ptr::addr_of_mut!((*notifier).mutex) as *mut crate::compat::OsalMutex;
        OsalMutexLock(mutex_ptr);

        // DListRemove inline implementation
        // DListHead is opaque, so we use pointer arithmetic
        let entry = std::ptr::addr_of_mut!((*notifierNode).listNode) as *mut *mut ::core::ffi::c_void;
        let next_ptr = entry; // next is first field
        let prev_ptr = entry.add(1); // prev is second field
        
        let next = *next_ptr;
        let prev = *prev_ptr;
        
        // prev->next = next
        let prev_next = prev as *mut *mut ::core::ffi::c_void;
        *prev_next = next;
        
        // next->prev = prev
        let next_prev = (next as *mut *mut ::core::ffi::c_void).add(1);
        *next_prev = prev;
        
        // entry->prev = NULL, entry->next = NULL
        *prev_ptr = std::ptr::null_mut();
        *next_ptr = std::ptr::null_mut();

        // DListIsEmpty inline implementation
        let head = std::ptr::addr_of!((*notifier).notifyNodeList) as *const *const ::core::ffi::c_void;
        let head_next = *head;
        let is_empty = head_next as usize == head as usize;
        
        if is_empty {
            crate::src_osal_sysevent::DeInitKeventIoServiceListenerLocked(notifier);
        }

        OsalMutexUnlock(mutex_ptr);
    }
}
