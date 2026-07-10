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
pub struct HdfSBuf {
    _unused: [u8; 0],
}

// === C2R_C2RUST_EXTERN_TYPES_END ===

extern "C" {
    pub fn HdfDeviceInfoNewInstance() -> *mut HdfDeviceInfo;
    pub fn strdup(_: *const core::ffi::c_char) -> *mut core::ffi::c_char;
    pub fn OsalMemFree(mem: *mut core::ffi::c_void);
    pub fn HiLogPrint(
        type_0: LogType,
        level: LogLevel,
        domain: core::ffi::c_uint,
        tag: *const core::ffi::c_char,
        fmt: *const core::ffi::c_char,
        ...
    ) -> core::ffi::c_int;
    pub fn HdfSbufWriteUint32(sbuf: *mut HdfSBuf, value: uint32_t) -> bool;
    pub fn HdfSbufWriteUint16(sbuf: *mut HdfSBuf, value: uint16_t) -> bool;
    pub fn HdfSbufWriteString(sbuf: *mut HdfSBuf, value: *const core::ffi::c_char) -> bool;
    pub fn HdfSbufReadUint32(sbuf: *mut HdfSBuf, value: *mut uint32_t) -> bool;
    pub fn HdfSbufReadUint16(sbuf: *mut HdfSBuf, value: *mut uint16_t) -> bool;
    pub fn HdfSbufReadString(sbuf: *mut HdfSBuf) -> *const core::ffi::c_char;
}
pub type uint16_t = core::ffi::c_ushort;
pub type uint32_t = core::ffi::c_uint;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct HdfSListNode {
    pub next: *mut HdfSListNode,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct HdfDeviceInfo {
    pub node: HdfSListNode,
    pub isDynamic: bool,
    pub status: uint16_t,
    pub deviceType: uint16_t,
    pub deviceId: uint32_t,
    pub policy: uint16_t,
    pub priority: uint16_t,
    pub preload: uint16_t,
    pub permission: uint16_t,
    pub moduleName: *const core::ffi::c_char,
    pub svcName: *const core::ffi::c_char,
    pub deviceMatchAttr: *const core::ffi::c_char,
    pub deviceName: *const core::ffi::c_char,
}
pub type LogLevel = core::ffi::c_uint;
pub const LOG_LEVEL_MAX: LogLevel = 8;
pub const LOG_FATAL: LogLevel = 7;
pub const LOG_ERROR: LogLevel = 6;
pub const LOG_WARN: LogLevel = 5;
pub const LOG_INFO: LogLevel = 4;
pub const LOG_DEBUG: LogLevel = 3;
pub const LOG_LEVEL_MIN: LogLevel = 0;
pub type LogType = core::ffi::c_uint;
pub const LOG_TYPE_MAX: LogType = 6;
pub const LOG_ONLY_PRERELEASE: LogType = 5;
pub const LOG_KMSG: LogType = 4;
pub const LOG_CORE: LogType = 3;
pub const LOG_INIT: LogType = 1;
pub const LOG_APP: LogType = 0;
pub const LOG_TYPE_MIN: LogType = 0;
pub unsafe extern "C" fn DeviceAttributeSerialize(
    mut attribute: *const HdfDeviceInfo,
    mut sbuf: *mut HdfSBuf,
) -> bool {
    if attribute.is_null() || sbuf.is_null() {
        return 0 as core::ffi::c_int != 0;
    }
    if !HdfSbufWriteUint32(sbuf, (*attribute).deviceId)
        || !HdfSbufWriteUint16(sbuf, (*attribute).policy)
        || !HdfSbufWriteString(sbuf, (*attribute).svcName)
        || !HdfSbufWriteString(sbuf, (*attribute).moduleName)
        || !HdfSbufWriteString(sbuf, (*attribute).deviceName)
    {
        return 0 as core::ffi::c_int != 0;
    }
    if !((*attribute).deviceMatchAttr).is_null() {
        if !HdfSbufWriteUint32(sbuf, 1 as uint32_t)
            || !HdfSbufWriteString(sbuf, (*attribute).deviceMatchAttr)
        {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xd002510 as core::ffi::c_uint,
                b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
                b"failed to serialize device attribute\0" as *const u8
                    as *const core::ffi::c_char,
            );
            return 0 as core::ffi::c_int != 0;
        }
    } else if !HdfSbufWriteUint32(sbuf, 0 as uint32_t) {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd002510 as core::ffi::c_uint,
            b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
            b"failed to serialize device attribute\0" as *const u8
                as *const core::ffi::c_char,
        );
        return 0 as core::ffi::c_int != 0;
    }
    return 1 as core::ffi::c_int != 0;
}
pub unsafe extern "C" fn DeviceAttributeSet(
    mut attribute: *mut HdfDeviceInfo,
    mut sbuf: *mut HdfSBuf,
) -> bool {
    let mut svcName: *const core::ffi::c_char = HdfSbufReadString(sbuf);
    if svcName.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd002510 as core::ffi::c_uint,
            b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
            b"Read from sbuf failed, svcName is null\0" as *const u8
                as *const core::ffi::c_char,
        );
        return 0 as core::ffi::c_int != 0;
    }
    (*attribute).svcName = strdup(svcName);
    if ((*attribute).svcName).is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd002510 as core::ffi::c_uint,
            b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
            b"Read from sbuf failed, strdup svcName fail\0" as *const u8
                as *const core::ffi::c_char,
        );
        return 0 as core::ffi::c_int != 0;
    }
    let mut moduleName: *const core::ffi::c_char = HdfSbufReadString(sbuf);
    if moduleName.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd002510 as core::ffi::c_uint,
            b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
            b"Read from parcel failed, moduleName is null\0" as *const u8
                as *const core::ffi::c_char,
        );
        return 0 as core::ffi::c_int != 0;
    }
    (*attribute).moduleName = strdup(moduleName);
    if ((*attribute).moduleName).is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd002510 as core::ffi::c_uint,
            b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
            b"Read from sbuf failed, strdup moduleName fail\0" as *const u8
                as *const core::ffi::c_char,
        );
        return 0 as core::ffi::c_int != 0;
    }
    let mut deviceName: *const core::ffi::c_char = HdfSbufReadString(sbuf);
    if deviceName.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd002510 as core::ffi::c_uint,
            b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
            b"Read from sbuf failed, deviceName is null\0" as *const u8
                as *const core::ffi::c_char,
        );
        return 0 as core::ffi::c_int != 0;
    }
    (*attribute).deviceName = strdup(deviceName);
    if ((*attribute).deviceName).is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd002510 as core::ffi::c_uint,
            b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
            b"Read from sbuf failed, strdup deviceName fail\0" as *const u8
                as *const core::ffi::c_char,
        );
        return 0 as core::ffi::c_int != 0;
    }
    let mut length: uint32_t = 0;
    if !HdfSbufReadUint32(sbuf, &mut length) {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd002510 as core::ffi::c_uint,
            b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
            b"Device attribute readDeviceMatchAttr length failed\0" as *const u8
                as *const core::ffi::c_char,
        );
        return 0 as core::ffi::c_int != 0;
    }
    if length == 1 as core::ffi::c_uint {
        let mut deviceMatchAttr: *const core::ffi::c_char = HdfSbufReadString(sbuf);
        if deviceMatchAttr.is_null() {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xd002510 as core::ffi::c_uint,
                b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
                b"%s: Read from sbuf failed, deviceMatchAttr is null\0" as *const u8
                    as *const core::ffi::c_char,
                (::core::mem::transmute::<
                    [u8; 19],
                    [core::ffi::c_char; 19],
                >(*b"DeviceAttributeSet\0"))
                    .as_ptr(),
            );
            return 0 as core::ffi::c_int != 0;
        }
        (*attribute).deviceMatchAttr = strdup(deviceMatchAttr);
        if ((*attribute).deviceMatchAttr).is_null() {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xd002510 as core::ffi::c_uint,
                b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
                b"Read from sbuf failed, strdup deviceMatchAttr fail\0" as *const u8
                    as *const core::ffi::c_char,
            );
            return 0 as core::ffi::c_int != 0;
        }
    }
    return 1 as core::ffi::c_int != 0;
}
pub unsafe extern "C" fn DeviceAttributeDeserialize(
    mut sbuf: *mut HdfSBuf,
) -> *mut HdfDeviceInfo {
    if sbuf.is_null() {
        return 0 as *mut HdfDeviceInfo;
    }
    let mut attribute: *mut HdfDeviceInfo = HdfDeviceInfoNewInstance();
    if attribute.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd002510 as core::ffi::c_uint,
            b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
            b"OsalMemCalloc failed, attribute is null\0" as *const u8
                as *const core::ffi::c_char,
        );
        return 0 as *mut HdfDeviceInfo;
    }
    if ((*attribute).deviceMatchAttr).is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_WARN,
            0xd002510 as core::ffi::c_uint,
            b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
            b"OsalMemCalloc failed, attribute->deviceMatchAttr is null\0" as *const u8
                as *const core::ffi::c_char,
        );
    }
    if !HdfSbufReadUint32(sbuf, &mut (*attribute).deviceId)
        || !HdfSbufReadUint16(sbuf, &mut (*attribute).policy)
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd002510 as core::ffi::c_uint,
            b"dev_attr_serialze\0" as *const u8 as *const core::ffi::c_char,
            b"invalid deviceId or policy\0" as *const u8 as *const core::ffi::c_char,
        );
        DeviceSerializedAttributeRelease(attribute);
        return 0 as *mut HdfDeviceInfo;
    }
    if DeviceAttributeSet(attribute, sbuf) {
        return attribute;
    }
    DeviceSerializedAttributeRelease(attribute);
    return 0 as *mut HdfDeviceInfo;
}
pub unsafe extern "C" fn DeviceSerializedAttributeRelease(
    mut attribute: *mut HdfDeviceInfo,
) {
    if attribute.is_null() {
        return;
    }
    if !((*attribute).moduleName).is_null() {
        OsalMemFree((*attribute).moduleName as *mut core::ffi::c_void);
    }
    if !((*attribute).svcName).is_null() {
        OsalMemFree((*attribute).svcName as *mut core::ffi::c_void);
    }
    if !((*attribute).deviceName).is_null() {
        OsalMemFree((*attribute).deviceName as *mut core::ffi::c_void);
    }
    if !((*attribute).deviceMatchAttr).is_null() {
        OsalMemFree((*attribute).deviceMatchAttr as *mut core::ffi::c_void);
    }
    OsalMemFree(attribute as *mut core::ffi::c_void);
}
