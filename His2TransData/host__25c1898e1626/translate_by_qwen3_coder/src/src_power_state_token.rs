//! Module: src_power_state_token
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

fn PowerStateTokenOnFirstAcquire(sref: *mut crate::types::HdfSRef) {
    if sref.is_null() {
        return;
    }
    
    // Calculate offset of wakeRef field in PowerStateToken using offset_of pattern
    // that doesn't dereference null pointer
    let offset = std::mem::offset_of!(crate::types::PowerStateToken, wakeRef);
    
    // Get pointer to PowerStateToken from HdfSRef (container_of pattern)
    let stateToken: *mut crate::types::PowerStateToken = unsafe {
        (sref as *mut u8).sub(offset) as *mut crate::types::PowerStateToken
    };
    
    let _ = stateToken;
}

fn PowerStateTokenOnLastRelease(sref: *mut crate::types::HdfSRef) {
    let mut stateToken: *mut crate::types::PowerStateToken = std::ptr::null_mut();
    let mut listener: *const crate::types::IPowerEventListener = std::ptr::null();
    
    if sref.is_null() {
        return;
    }
    
    // HDF_SLIST_CONTAINER_OF macro expansion: get PowerStateToken from wakeRef field
    // offset of wakeRef in PowerStateToken
    let offset = std::mem::offset_of!(crate::types::PowerStateToken, wakeRef);
    stateToken = unsafe { (sref as *mut u8).sub(offset) as *mut crate::types::PowerStateToken };
    
    unsafe {
        listener = (*stateToken).listener;
        
        if !listener.is_null() {
            if let Some(suspend_fn) = (*listener).Suspend {
                suspend_fn((*stateToken).deviceObject);
            }
        }
        
        (*stateToken).psmState = crate::types::PSM_STATE_INACTIVE;
    }
}

pub extern "C" fn PowerStateChange(stateToken: *mut crate::types::PowerStateToken, pEvent: u32) -> ::core::ffi::c_int {
    unsafe {
        if stateToken.is_null() {
            return crate::types::HDF_SUCCESS;
        }
        
        let listener = (*stateToken).listener;
        if listener.is_null() {
            return crate::types::HDF_SUCCESS;
        }
        
        if (*stateToken).mode != crate::types::HDF_POWER_SYS_CTRL {
            return crate::types::HDF_SUCCESS;
        }
        
        let device_object = (*stateToken).deviceObject;
        
        match pEvent {
            crate::types::POWER_STATE_SUSPEND => {
                if let Some(suspend_fn) = (*listener).Suspend {
                    return suspend_fn(device_object);
                }
            }
            crate::types::POWER_STATE_RESUME => {
                if let Some(resume_fn) = (*listener).Resume {
                    return resume_fn(device_object);
                }
            }
            crate::types::POWER_STATE_DOZE_SUSPEND => {
                if let Some(doze_suspend_fn) = (*listener).DozeSuspend {
                    return doze_suspend_fn(device_object);
                }
            }
            crate::types::POWER_STATE_DOZE_RESUME => {
                if let Some(doze_resume_fn) = (*listener).DozeResume {
                    return doze_resume_fn(device_object);
                }
            }
            _ => {}
        }
        
        crate::types::HDF_SUCCESS
    }
}

fn PowerStateTokenAcquireWakeLock(token: *mut crate::types::IPowerStateToken) {
    let stateToken = token as *mut crate::types::PowerStateToken;
    if stateToken.is_null() {
        return;
    }
    unsafe {
        if (*stateToken).mode != crate::types::HDF_POWER_DYNAMIC_CTRL {
            return;
        }
        let sref: *mut crate::types::HdfSRef = &mut (*stateToken).wakeRef as *mut crate::types::HdfSRef;
        if !sref.is_null() {
            if let Some(acquire_fn) = (*sref).Acquire {
                acquire_fn(sref);
            }
        }
    }
}

fn PowerStateTokenReleaseWakeLock(token: *mut crate::types::IPowerStateToken) {
    let mut sref: *mut crate::types::HdfSRef = std::ptr::null_mut();
    let stateToken: *mut crate::types::PowerStateToken = token as *mut crate::types::PowerStateToken;
    
    if stateToken.is_null() {
        return;
    }
    
    unsafe {
        if (*stateToken).mode != crate::types::HDF_POWER_DYNAMIC_CTRL {
            return;
        }
        
        sref = &mut (*stateToken).wakeRef as *mut crate::types::HdfSRef;
        
        if sref.is_null() {
            return;
        }
        
        if (*sref).Release.is_none() {
            return;
        }
        
        if crate::compat::HdfSRefCount(sref as *const crate::types::HdfSRef) == 0 {
            crate::src_power_state_token::PowerStateTokenOnLastRelease(sref);
        } else {
            if let Some(release_fn) = (*sref).Release {
                release_fn(sref);
            }
        }
    }
}

fn PowerStateTokenConstruct(powerStateToken: *mut crate::types::PowerStateToken, deviceObject: *mut crate::types::HdfDeviceObject, listener: *const crate::types::IPowerEventListener) -> i32 {
    unsafe {
        let tokenIf: *mut crate::types::IPowerStateToken = &mut (*powerStateToken).super_;
        let srefListener: *mut crate::types::IHdfSRefListener = crate::compat::OsalMemCalloc(
            std::mem::size_of::<crate::types::IHdfSRefListener>() as u32
        ) as *mut crate::types::IHdfSRefListener;
        
        if srefListener.is_null() {
            return crate::types::HDF_ERR_MALLOC_FAIL;
        }
        
        (*tokenIf).AcquireWakeLock = Some(std::mem::transmute::<fn(*mut crate::types::IPowerStateToken), unsafe extern "C" fn(*mut crate::types::IPowerStateToken)>(PowerStateTokenAcquireWakeLock));
        (*tokenIf).ReleaseWakeLock = Some(std::mem::transmute::<fn(*mut crate::types::IPowerStateToken), unsafe extern "C" fn(*mut crate::types::IPowerStateToken)>(PowerStateTokenReleaseWakeLock));
        
        (*srefListener).OnFirstAcquire = Some(std::mem::transmute::<fn(*mut crate::types::HdfSRef), unsafe extern "C" fn(*mut crate::types::HdfSRef)>(PowerStateTokenOnFirstAcquire));
        (*srefListener).OnLastRelease = Some(std::mem::transmute::<fn(*mut crate::types::HdfSRef), unsafe extern "C" fn(*mut crate::types::HdfSRef)>(PowerStateTokenOnLastRelease));
        
        (*powerStateToken).psmState = crate::types::PSM_STATE_IDLE;
        (*powerStateToken).listener = listener;
        (*powerStateToken).deviceObject = deviceObject;
        crate::compat::HdfSRefConstruct(&mut (*powerStateToken).wakeRef, srefListener);
        
        crate::types::HDF_SUCCESS
    }
}

pub extern "C" fn PowerStateTokenNewInstance(deviceObject: *mut crate::types::HdfDeviceObject, listener: *const crate::types::IPowerEventListener) -> *mut crate::types::PowerStateToken {
    let stateToken = unsafe {
        crate::compat::OsalMemCalloc(std::mem::size_of::<crate::types::PowerStateToken>() as u32) as *mut crate::types::PowerStateToken
    };
    
    if stateToken.is_null() {
        return std::ptr::null_mut();
    }
    
    if crate::src_power_state_token::PowerStateTokenConstruct(stateToken, deviceObject, listener) != crate::types::HDF_SUCCESS {
        unsafe {
            crate::compat::OsalMemFree(stateToken as *mut ::core::ffi::c_void);
        }
        return std::ptr::null_mut();
    }
    
    stateToken
}

pub extern "C" fn PowerStateTokenFreeInstance(stateToken: *mut crate::types::PowerStateToken) {
    if !stateToken.is_null() {
        unsafe {
            if !(*stateToken).wakeRef.listener.is_null() {
                OsalMemFree((*stateToken).wakeRef.listener as *mut ::core::ffi::c_void);
                (*stateToken).wakeRef.listener = std::ptr::null_mut();
            }
            OsalMemFree(stateToken as *mut ::core::ffi::c_void);
        }
    }
}
