//! Module: src_hdf_object_manager
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

pub extern "C" fn HdfObjectManagerGetObject(objectId: ::core::ffi::c_int) -> *mut crate::types::HdfObject {
    let mut object: *mut crate::types::HdfObject = std::ptr::null_mut();
    let targetCreator: *const crate::types::HdfObjectCreator = unsafe { crate::compat::HdfObjectManagerGetCreators(objectId) };
    if !targetCreator.is_null() {
        unsafe {
            if let Some(create_fn) = (*targetCreator).Create {
                object = create_fn();
                if !object.is_null() {
                    (*object).objectId = objectId;
                }
            }
        }
    }
    object
}

pub extern "C" fn HdfObjectManagerFreeObject(object: *mut crate::types::HdfObject) {
    let mut targetCreator: *const crate::types::HdfObjectCreator = std::ptr::null();
    if object.is_null() {
        return;
    }
    unsafe {
        targetCreator = crate::compat::HdfObjectManagerGetCreators((*object).objectId);
    }
    if targetCreator.is_null() {
        return;
    }
    unsafe {
        if let Some(release_fn) = (*targetCreator).Release {
            release_fn(object);
        }
    }
}
