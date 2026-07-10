//! Module: src_app_common
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

pub extern "C" fn HapGetInt64(buf: *const ::core::ffi::c_uchar, len: i32) -> ::core::ffi::c_longlong {
    if buf.is_null() {
        return 0;
    }
    let mut value: ::core::ffi::c_ulonglong = 0;
    if len != std::mem::size_of::<::core::ffi::c_longlong>() as i32 {
        return 0;
    }
    let mut len = len;
    while {
        len -= 1;
        len >= 0
    } {
        value = (value << 8) | unsafe { *buf.offset(len as isize) } as ::core::ffi::c_ulonglong;
    }
    value as ::core::ffi::c_longlong
}

pub extern "C" fn HapGetInt(buf: *const ::core::ffi::c_uchar, len: i32) -> i32 {
    let value: u32 = crate::src_app_common::HapGetUnsignedInt(buf, len);
    value as i32
}

pub extern "C" fn HapGetUnsignedInt(buf: *const ::core::ffi::c_uchar, len: i32) -> u32 {
    if buf.is_null() {
        return 0;
    }
    let mut value: u32 = 0;
    if len != std::mem::size_of::<i32>() as i32 {
        return 0;
    }
    let mut len = len;
    while {
        let old_len = len;
        len -= 1;
        old_len > 0
    } {
        unsafe {
            value = (value << 8) | (*buf.offset(len as isize) as u32);
        }
    }
    value
}

pub extern "C" fn HapGetShort(buf: *const ::core::ffi::c_uchar, len: i32) -> ::core::ffi::c_short {
    if buf.is_null() {
        return 0;
    }
    let mut value: u16 = 0;
    if len != std::mem::size_of::<i16>() as i32 {
        return 0;
    }
    let mut len = len;
    while {
        let old_len = len;
        len -= 1;
        old_len > 0
    } {
        unsafe {
            value = (value << 8) | (*buf.offset(len as isize) as u16);
        }
    }
    value as ::core::ffi::c_short
}

pub extern "C" fn HapPutInt32(buf: *mut ::core::ffi::c_uchar, len: i32, value: i32) {
    if buf.is_null() || len < (std::mem::size_of::<i32>() as i32) {
        return;
    }
    let mut var: u32 = value as u32;
    for i in 0..std::mem::size_of::<i32>() {
        unsafe {
            *buf.add(i) = var as u8;
        }
        var = var >> 8;
    }
}
