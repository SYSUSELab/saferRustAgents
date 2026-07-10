#![allow(deref_nullptr)]
#![allow(
    dead_code,
    non_camel_case_types,
    non_snake_case,
    non_upper_case_globals,
    unused_assignments,
    unused_mut
)]
// === C2R_C2RUST_EXTERN_TYPES_BEGIN ===
// Auto-generated: downgraded c2rust `extern type` to stable-safe opaque structs.
#[repr(C)]
#[derive(Copy, Clone)]
pub struct DeviceResourceNode {
    _unused: [u8; 0],
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct HdfSBuf {
    _unused: [u8; 0],
}

// === C2R_C2RUST_EXTERN_TYPES_END ===

extern "C" {
    pub fn HdfServiceSubscriberDelete(listEntry: *mut HdfSListNode);
    pub fn HdfSListInit(list: *mut HdfSList);
    pub fn OsalMemCalloc(size: size_t) -> *mut core::ffi::c_void;
    pub fn OsalMutexInit(mutex: *mut OsalMutex) -> int32_t;
    pub fn OsalMemFree(mem: *mut core::ffi::c_void);
    pub fn OsalMutexDestroy(mutex: *mut OsalMutex) -> int32_t;
    pub fn OsalMutexLock(mutex: *mut OsalMutex) -> int32_t;
    pub fn HdfSListFlush(list: *mut HdfSList, deleter: HdfSListDeleter);
    pub fn OsalMutexUnlock(mutex: *mut OsalMutex) -> int32_t;
    pub fn HdfSListIteratorInit(iterator: *mut HdfSListIterator, list: *const HdfSList);
    pub fn HdfSListIteratorHasNext(iterator: *const HdfSListIterator) -> bool;
    pub fn HdfSListIteratorNext(iterator: *mut HdfSListIterator) -> *mut HdfSListNode;
    pub fn HiLogPrint(
        type_0: LogType,
        level: LogLevel,
        domain: core::ffi::c_uint,
        tag: *const core::ffi::c_char,
        fmt: *const core::ffi::c_char,
        ...
    ) -> core::ffi::c_int;
}
pub type size_t = core::ffi::c_uint;
pub type int32_t = core::ffi::c_int;
pub type uint16_t = core::ffi::c_ushort;
pub type uint32_t = core::ffi::c_uint;
pub type C2RustUnnamed = core::ffi::c_int;
pub const HDF_DEV_ERR_NETDOWN: C2RustUnnamed = -211;
pub const HDF_DEV_ERR_OP: C2RustUnnamed = -210;
pub const HDF_DEV_ERR_NORANGE: C2RustUnnamed = -208;
pub const HDF_DEV_ERR_NODATA: C2RustUnnamed = -207;
pub const HDF_DEV_ERR_ATTACHDEV_FAIL: C2RustUnnamed = -206;
pub const HDF_DEV_ERR_PUBLISH_FAIL: C2RustUnnamed = -205;
pub const HDF_DEV_ERR_DEV_INIT_FAIL: C2RustUnnamed = -204;
pub const HDF_DEV_ERR_NO_DEVICE_SERVICE: C2RustUnnamed = -203;
pub const HDF_DEV_ERR_NO_DEVICE: C2RustUnnamed = -202;
pub const HDF_DEV_ERR_NO_MEMORY: C2RustUnnamed = -201;
pub const HDF_PAL_ERR_INNER: C2RustUnnamed = -104;
pub const HDF_PAL_ERR_DEV_CREATE: C2RustUnnamed = -103;
pub const HDF_ERR_BSP_PLT_API_ERR: C2RustUnnamed = -102;
pub const HDF_BSP_ERR_OP: C2RustUnnamed = -101;
pub const HDF_ERR_OUT_OF_RANGE: C2RustUnnamed = -20;
pub const HDF_ERR_NOPERM: C2RustUnnamed = -19;
pub const HDF_ERR_BAD_FD: C2RustUnnamed = -18;
pub const HDF_ERR_IO: C2RustUnnamed = -17;
pub const HDF_ERR_DEVICE_BUSY: C2RustUnnamed = -16;
pub const HDF_ERR_QUEUE_FULL: C2RustUnnamed = -15;
pub const HDF_ERR_THREAD_CREATE_FAIL: C2RustUnnamed = -10;
pub const HDF_ERR_TIMEOUT: C2RustUnnamed = -7;
pub const HDF_ERR_MALLOC_FAIL: C2RustUnnamed = -6;
pub const HDF_ERR_INVALID_OBJECT: C2RustUnnamed = -4;
pub const HDF_ERR_INVALID_PARAM: C2RustUnnamed = -3;
pub const HDF_ERR_NOT_SUPPORT: C2RustUnnamed = -2;
pub const HDF_FAILURE: C2RustUnnamed = -1;
pub const HDF_SUCCESS: C2RustUnnamed = 0;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct HdfObject {
    pub objectId: int32_t,
}
pub type devid_t = uint32_t;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct HdfSListNode {
    pub next: *mut HdfSListNode,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct HdfSList {
    pub root: *mut HdfSListNode,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct HdfSListIterator {
    pub stepOnNext: core::ffi::c_int,
    pub prev: *mut HdfSListNode,
    pub curr: *mut HdfSListNode,
}
pub type HdfSListDeleter = Option<unsafe extern "C" fn(*mut HdfSListNode) -> ()>;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct OsalMutex {
    pub realMutex: *mut core::ffi::c_void,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct HdfServiceObserverRecord {
    pub entry: HdfSListNode,
    pub serviceKey: uint32_t,
    pub policy: uint16_t,
    pub devId: devid_t,
    pub obsRecMutex: OsalMutex,
    pub subscribers: HdfSList,
    pub publisher: *mut HdfObject,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct HdfDeviceObject {
    pub service: *mut IDeviceIoService,
    pub property: *const DeviceResourceNode,
    pub deviceClass: DeviceClass,
    pub priv_0: *mut core::ffi::c_void,
}
pub type DeviceClass = core::ffi::c_uint;
pub const DEVICE_CLASS_MAX: DeviceClass = 1024;
pub const DEVICE_CLASS_HIMEDIACOMM: DeviceClass = 512;
pub const DEVICE_CLASS_USERAUTH: DeviceClass = 256;
pub const DEVICE_CLASS_USB: DeviceClass = 128;
pub const DEVICE_CLASS_CAMERA: DeviceClass = 64;
pub const DEVICE_CLASS_AUDIO: DeviceClass = 32;
pub const DEVICE_CLASS_DISPLAY: DeviceClass = 16;
pub const DEVICE_CLASS_INPUT: DeviceClass = 8;
pub const DEVICE_CLASS_SENSOR: DeviceClass = 4;
pub const DEVICE_CLASS_PLAT: DeviceClass = 2;
pub const DEVICE_CLASS_DEFAULT: DeviceClass = 1;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct IDeviceIoService {
    pub object: HdfObject,
    pub Open: Option<unsafe extern "C" fn(*mut HdfDeviceIoClient) -> int32_t>,
    pub Dispatch: Option<
        unsafe extern "C" fn(
            *mut HdfDeviceIoClient,
            core::ffi::c_int,
            *mut HdfSBuf,
            *mut HdfSBuf,
        ) -> int32_t,
    >,
    pub Release: Option<unsafe extern "C" fn(*mut HdfDeviceIoClient) -> ()>,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct HdfDeviceIoClient {
    pub device: *mut HdfDeviceObject,
    pub priv_0: *mut core::ffi::c_void,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct SubscriberCallback {
    pub deviceObject: *mut HdfDeviceObject,
    pub OnServiceConnected: Option<
        unsafe extern "C" fn(*mut HdfDeviceObject, *const HdfObject) -> int32_t,
    >,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct HdfServiceSubscriber {
    pub entry: HdfSListNode,
    pub state: uint32_t,
    pub devId: uint32_t,
    pub callback: SubscriberCallback,
}
pub const HDF_SUBSCRIBER_STATE_READY: C2RustUnnamed_1 = 1;
pub const SERVICE_POLICY_PRIVATE: C2RustUnnamed_0 = 4;
pub type LogLevel = core::ffi::c_uint;
pub const LOG_FATAL: LogLevel = 7;
pub const LOG_ERROR: LogLevel = 6;
pub const LOG_WARN: LogLevel = 5;
pub const LOG_INFO: LogLevel = 4;
pub const LOG_DEBUG: LogLevel = 3;
pub type LogType = core::ffi::c_uint;
pub const LOG_TYPE_MAX: LogType = 4;
pub const LOG_CORE: LogType = 3;
pub const LOG_INIT: LogType = 1;
pub const LOG_TYPE_MIN: LogType = 0;
pub type C2RustUnnamed_0 = core::ffi::c_uint;
pub const SERVICE_POLICY_INVALID: C2RustUnnamed_0 = 5;
pub const SERVICE_POLICY_FRIENDLY: C2RustUnnamed_0 = 3;
pub const SERVICE_POLICY_CAPACITY: C2RustUnnamed_0 = 2;
pub const SERVICE_POLICY_PUBLIC: C2RustUnnamed_0 = 1;
pub const SERVICE_POLICY_NONE: C2RustUnnamed_0 = 0;
pub type C2RustUnnamed_1 = core::ffi::c_uint;
pub const HDF_SUBSCRIBER_STATE_PENDING: C2RustUnnamed_1 = 0;
pub unsafe extern "C" fn HdfServiceObserverRecordObtain(
    mut serviceKey: uint32_t,
) -> *mut HdfServiceObserverRecord {
    let mut observerRecord: *mut HdfServiceObserverRecord = OsalMemCalloc(
        ::core::mem::size_of::<HdfServiceObserverRecord>() as size_t,
    ) as *mut HdfServiceObserverRecord;
    if !observerRecord.is_null() {
        (*observerRecord).serviceKey = serviceKey;
        (*observerRecord).publisher = 0 as *mut HdfObject;
        if OsalMutexInit(&mut (*observerRecord).obsRecMutex)
            != HDF_SUCCESS as core::ffi::c_int
        {
            OsalMemFree(observerRecord as *mut core::ffi::c_void);
            return 0 as *mut HdfServiceObserverRecord;
        }
        HdfSListInit(&mut (*observerRecord).subscribers);
    }
    return observerRecord;
}
pub unsafe extern "C" fn HdfServiceObserverRecordRecycle(
    mut observerRecord: *mut HdfServiceObserverRecord,
) {
    if !observerRecord.is_null() {
        HdfSListFlush(
            &mut (*observerRecord).subscribers,
            Some(
                HdfServiceSubscriberDelete
                    as unsafe extern "C" fn(*mut HdfSListNode) -> (),
            ),
        );
        OsalMutexDestroy(&mut (*observerRecord).obsRecMutex);
        (*observerRecord).obsRecMutex.realMutex = 0 as *mut core::ffi::c_void;
        OsalMemFree(observerRecord as *mut core::ffi::c_void);
    }
}
pub unsafe extern "C" fn HdfServiceObserverRecordCompare(
    mut listEntry: *mut HdfSListNode,
    mut serviceKey: uint32_t,
) -> bool {
    let mut record: *mut HdfServiceObserverRecord = 0 as *mut HdfServiceObserverRecord;
    if listEntry.is_null() {
        return 0 as core::ffi::c_int != 0;
    }
    record = listEntry as *mut HdfServiceObserverRecord;
    if (*record).serviceKey == serviceKey {
        return 1 as core::ffi::c_int != 0;
    }
    return 0 as core::ffi::c_int != 0;
}
pub unsafe extern "C" fn HdfServiceObserverRecordNotifySubscribers(
    mut record: *mut HdfServiceObserverRecord,
    mut deviceId: devid_t,
    mut policy: uint16_t,
) {
    let mut it: HdfSListIterator = HdfSListIterator {
        stepOnNext: 0,
        prev: 0 as *mut HdfSListNode,
        curr: 0 as *mut HdfSListNode,
    };
    if record.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd002510 as core::ffi::c_uint,
            b"observer_record\0" as *const u8 as *const core::ffi::c_char,
            b"%{public}s: record is null\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 42],
                [core::ffi::c_char; 42],
            >(*b"HdfServiceObserverRecordNotifySubscribers\0"))
                .as_ptr(),
        );
        return;
    }
    OsalMutexLock(&mut (*record).obsRecMutex);
    HdfSListIteratorInit(&mut it, &mut (*record).subscribers);
    while HdfSListIteratorHasNext(&mut it) {
        let mut subscriber: *mut HdfServiceSubscriber = HdfSListIteratorNext(&mut it)
            as *mut HdfServiceSubscriber;
        if deviceId == (*subscriber).devId
            || policy as core::ffi::c_int != SERVICE_POLICY_PRIVATE as core::ffi::c_int
        {
            (*subscriber).state = HDF_SUBSCRIBER_STATE_READY as core::ffi::c_int
                as uint32_t;
            if ((*subscriber).callback.OnServiceConnected).is_some() {
                ((*subscriber).callback.OnServiceConnected)
                    .expect(
                        "non-null function pointer",
                    )((*subscriber).callback.deviceObject, (*record).publisher);
            }
        }
    }
    OsalMutexUnlock(&mut (*record).obsRecMutex);
}
pub unsafe extern "C" fn HdfServiceObserverRecordDelete(
    mut listEntry: *mut HdfSListNode,
) {
    let mut observerRecord: *mut HdfServiceObserverRecord = listEntry
        as *mut HdfServiceObserverRecord;
    if !observerRecord.is_null() {
        HdfServiceObserverRecordRecycle(observerRecord);
    }
}
