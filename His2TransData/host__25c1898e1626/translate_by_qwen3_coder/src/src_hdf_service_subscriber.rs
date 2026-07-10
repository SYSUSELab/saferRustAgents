//! Module: src_hdf_service_subscriber
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

pub extern "C" fn HdfServiceSubscriberObtain(callback: crate::types::SubscriberCallback, devid: crate::types::devid_t) -> *mut crate::types::HdfServiceSubscriber {
    let serviceSubscriber = unsafe {
        crate::compat::OsalMemCalloc(std::mem::size_of::<crate::types::HdfServiceSubscriber>() as u32) as *mut crate::types::HdfServiceSubscriber
    };
    if !serviceSubscriber.is_null() {
        unsafe {
            (*serviceSubscriber).state = crate::types::HDF_SUBSCRIBER_STATE_PENDING;
            (*serviceSubscriber).devId = devid;
            (*serviceSubscriber).callback = callback;
        }
    }
    serviceSubscriber
}

pub extern "C" fn HdfServiceSubscriberRecycle(subscriber: *mut crate::types::HdfServiceSubscriber) {
    if !subscriber.is_null() {
        unsafe {
            crate::compat::OsalMemFree(subscriber as *mut ::core::ffi::c_void);
        }
    }
}

pub extern "C" fn HdfServiceSubscriberDelete(listEntry: *mut crate::types::HdfSListNode) {
    let serviceSubscriber: *mut crate::types::HdfServiceSubscriber = listEntry as *mut crate::types::HdfServiceSubscriber;
    if !serviceSubscriber.is_null() {
        crate::src_hdf_service_subscriber::HdfServiceSubscriberRecycle(serviceSubscriber);
    }
}
