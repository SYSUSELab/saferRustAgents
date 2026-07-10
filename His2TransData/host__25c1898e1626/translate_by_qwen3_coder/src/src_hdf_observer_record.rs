//! Module: src_hdf_observer_record
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

pub extern "C" fn HdfServiceObserverRecordObtain(serviceKey: u32) -> *mut crate::types::HdfServiceObserverRecord {
    let observerRecord = unsafe {
        crate::compat::OsalMemCalloc(std::mem::size_of::<crate::types::HdfServiceObserverRecord>() as u32)
    } as *mut crate::types::HdfServiceObserverRecord;
    
    if !observerRecord.is_null() {
        unsafe {
            (*observerRecord).serviceKey = serviceKey;
            (*observerRecord).publisher = std::ptr::null_mut();
            
            if crate::compat::OsalMutexInit(&mut (*observerRecord).obsRecMutex) != crate::types::HDF_SUCCESS {
                crate::compat::OsalMemFree(observerRecord as *mut ::core::ffi::c_void);
                return std::ptr::null_mut();
            }
            
            crate::compat::HdfSListInit(&mut (*observerRecord).subscribers);
        }
    }
    
    observerRecord
}

// === C2R MANUAL FIX REQUIRED ===
// reason: repair_failed_after_5
// func_key: src_hdf_observer_record_2
// c_function: HdfServiceObserverRecordRecycle
// rust_file: src_hdf_observer_record.rs
// rust_signature: pub extern "C" fn HdfServiceObserverRecordRecycle(observerRecord: *mut crate::types::HdfServiceObserverRecord)
// c_first_line: void HdfServiceObserverRecordRecycle(struct HdfServiceObserverRecord *observerRecord)
// saved_translation: /data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5_reuseS1_topk1/intermediate/host__25c1898e1626/workspace/repair_history/host__25c1898e1626/translate_by_qwen3_coder/_manual_fix/src_hdf_observer_record_2/translated_rust.rs
// last_error_truncated:
//   error[E0425]: cannot find value `HdfServiceSubscriberDelete` in the crate root
//     --> src/src_hdf_observer_record.rs:42:29
//      |
//      |                             ^^^^^^^^^^^^^^^^^^^^^^^^^^ not found in the crate root
//      |
//   help: consider importing this function
//      |
//      |
// =================================
pub extern "C" fn HdfServiceObserverRecordRecycle(observerRecord: *mut crate::types::HdfServiceObserverRecord) {
    // C2R: C2Rust fallback (LLM failed; wrapper keeps skeleton signature)
    unsafe { crate::compat::__c2rust_fallback::src_hdf_observer_record::HdfServiceObserverRecordRecycle(observerRecord as _); }
}
/* === C2R_LLM_FAILED_OUTPUT_BEGIN ===
 * func_key: src_hdf_observer_record_2
 * reason: repair_failed_after_5
 * saved_translation: /data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5_reuseS1_topk1/intermediate/host__25c1898e1626/workspace/repair_history/host__25c1898e1626/translate_by_qwen3_coder/_manual_fix/src_hdf_observer_record_2/translated_rust.rs
 * ------------------------------------------------------------
pub extern "C" fn HdfServiceObserverRecordRecycle(observerRecord: *mut crate::types::HdfServiceObserverRecord) {
    if !observerRecord.is_null() {
        unsafe {
            crate::compat::HdfSListFlush(
                &mut (*observerRecord).subscribers as *mut crate::types::HdfSList,
                Some(crate::HdfServiceSubscriberDelete),
            );
            crate::compat::OsalMutexDestroy(
                &mut (*observerRecord).obsRecMutex as *mut crate::types::OsalMutex,
            );
            (*observerRecord).obsRecMutex.realMutex = std::ptr::null_mut();
            crate::compat::OsalMemFree(observerRecord as *mut ::core::ffi::c_void);
        }
    }
}
 * ------------------------------------------------------------
 * C2R_LLM_FAILED_OUTPUT_BEGIN func_key: src_hdf_observer_record_2
 * === C2R_LLM_FAILED_OUTPUT_END === */


pub extern "C" fn HdfServiceObserverRecordCompare(listEntry: *mut crate::types::HdfSListNode, serviceKey: u32) -> bool {
    if listEntry.is_null() {
        return false;
    }
    let record = listEntry as *mut crate::types::HdfServiceObserverRecord;
    unsafe {
        if (*record).serviceKey == serviceKey {
            return true;
        }
    }
    false
}

pub extern "C" fn HdfServiceObserverRecordNotifySubscribers(record: *mut crate::types::HdfServiceObserverRecord, deviceId: crate::types::devid_t, policy: u16) {
    use crate::compat::*;
    use crate::types::*;
    
    if record.is_null() {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD002510,
                b"observer_record\0".as_ptr() as *const ::core::ffi::c_char,
                b"%{public}s: record is null\0".as_ptr() as *const ::core::ffi::c_char,
                b"HdfServiceObserverRecordNotifySubscribers\0".as_ptr() as *const ::core::ffi::c_char,
            );
        }
        return;
    }
    
    let mut it: HdfSListIterator = unsafe { ::core::mem::zeroed() };
    
    unsafe {
        OsalMutexLock(&mut (*record).obsRecMutex);
        HdfSListIteratorInit(&mut it, &(*record).subscribers as *const HdfSList);
        
        while HdfSListIteratorHasNext(&it as *const HdfSListIterator) {
            let subscriber = HdfSListIteratorNext(&mut it) as *mut HdfServiceSubscriber;
            if !subscriber.is_null() {
                if deviceId == (*subscriber).devId || policy != SERVICE_POLICY_PRIVATE as u16 {
                    (*subscriber).state = HDF_SUBSCRIBER_STATE_READY;
                    if let Some(on_connected) = (*subscriber).callback.OnServiceConnected {
                        on_connected((*subscriber).callback.deviceObject, (*record).publisher);
                    }
                }
            }
        }
        
        OsalMutexUnlock(&mut (*record).obsRecMutex);
    }
}

pub extern "C" fn HdfServiceObserverRecordDelete(listEntry: *mut crate::types::HdfSListNode) {
    let observerRecord = listEntry as *mut crate::types::HdfServiceObserverRecord;
    if !observerRecord.is_null() {
        crate::src_hdf_observer_record::HdfServiceObserverRecordRecycle(observerRecord);
    }
}
