#![allow(deref_nullptr)]
#![allow(
    dead_code,
    non_camel_case_types,
    non_snake_case,
    non_upper_case_globals,
    unused_assignments,
    unused_mut
)]
extern "C" {
    pub fn HcsGetRootNode() -> *const DeviceResourceNode;
    pub fn SetHcsBlobPath(path: *const core::ffi::c_char);
    pub fn access(_: *const core::ffi::c_char, _: core::ffi::c_int) -> core::ffi::c_int;
    pub fn HiLogPrint(
        type_0: LogType,
        level: LogLevel,
        domain: core::ffi::c_uint,
        tag: *const core::ffi::c_char,
        fmt: *const core::ffi::c_char,
        ...
    ) -> core::ffi::c_int;
    pub fn strcpy_s(
        strDest: *mut core::ffi::c_char,
        destMax: size_t,
        strSrc: *const core::ffi::c_char,
    ) -> errno_t;
    pub fn sprintf_s(
        strDest: *mut core::ffi::c_char,
        destMax: size_t,
        format: *const core::ffi::c_char,
        ...
    ) -> core::ffi::c_int;
}
pub type size_t = core::ffi::c_uint;
pub type uint32_t = core::ffi::c_uint;
pub type errno_t = core::ffi::c_int;
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
pub struct DeviceResourceAttr {
    pub name: *const core::ffi::c_char,
    pub value: *const core::ffi::c_char,
    pub next: *mut DeviceResourceAttr,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct DeviceResourceNode {
    pub name: *const core::ffi::c_char,
    pub hashValue: uint32_t,
    pub attrData: *mut DeviceResourceAttr,
    pub parent: *mut DeviceResourceNode,
    pub child: *mut DeviceResourceNode,
    pub sibling: *mut DeviceResourceNode,
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
pub unsafe extern "C" fn GetProductName(
    mut name: *mut core::ffi::c_char,
    mut maxLen: core::ffi::c_int,
) -> core::ffi::c_int {
    return strcpy_s(
        name,
        maxLen as size_t,
        b"default\0" as *const u8 as *const core::ffi::c_char,
    ) as core::ffi::c_int;
}
pub unsafe extern "C" fn GetConfigFilePath(
    mut productName: *const core::ffi::c_char,
    mut configPath: *mut core::ffi::c_char,
    mut configPathLen: size_t,
) -> bool {
    static mut adapterConfigPath: [*const core::ffi::c_char; 2] = [
        b"/vendor/etc/hdfconfig\0" as *const u8 as *const core::ffi::c_char,
        b"/chip_prod/etc/hdfconfig\0" as *const u8 as *const core::ffi::c_char,
    ];
    let mut pathNum: size_t = (::core::mem::size_of::<[*const core::ffi::c_char; 2]>()
        as usize)
        .wrapping_div(::core::mem::size_of::<*const core::ffi::c_char>() as usize)
        as size_t;
    let mut i: size_t = 0 as size_t;
    while i < pathNum {
        if sprintf_s(
            configPath,
            (configPathLen as size_t).wrapping_sub(1 as size_t),
            b"%s/hdf_%s.hcb\0" as *const u8 as *const core::ffi::c_char,
            adapterConfigPath[i as usize],
            productName,
        ) < 0 as core::ffi::c_int
        {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xd002510 as core::ffi::c_uint,
                b"attribute_manager\0" as *const u8 as *const core::ffi::c_char,
                b"failed to generate file path\0" as *const u8
                    as *const core::ffi::c_char,
            );
        } else {
            if access(configPath, 0 as core::ffi::c_int | 4 as core::ffi::c_int)
                == 0 as core::ffi::c_int
            {
                return 1 as core::ffi::c_int != 0;
            }
            HiLogPrint(
                LOG_CORE,
                LOG_DEBUG,
                0xd002510 as core::ffi::c_uint,
                b"attribute_manager\0" as *const u8 as *const core::ffi::c_char,
                b"invalid config file path or permission:%{public}s\0" as *const u8
                    as *const core::ffi::c_char,
                configPath,
            );
        }
        i = i.wrapping_add(1);
    }
    return 0 as core::ffi::c_int != 0;
}
pub unsafe extern "C" fn HdfGetHcsRootNode() -> *const DeviceResourceNode {
    let mut productName: [core::ffi::c_char; 128] = [
        0 as core::ffi::c_int as core::ffi::c_char,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    ];
    let mut configPath: [core::ffi::c_char; 256] = [
        0 as core::ffi::c_int as core::ffi::c_char,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    ];
    let mut ret: core::ffi::c_int = GetProductName(
        productName.as_mut_ptr(),
        128 as core::ffi::c_int,
    );
    if ret != HDF_SUCCESS as core::ffi::c_int {
        return 0 as *const DeviceResourceNode;
    }
    if !GetConfigFilePath(
        productName.as_mut_ptr(),
        configPath.as_mut_ptr(),
        256 as size_t,
    ) {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd002510 as core::ffi::c_uint,
            b"attribute_manager\0" as *const u8 as *const core::ffi::c_char,
            b"failed to get config file path\0" as *const u8 as *const core::ffi::c_char,
        );
        return 0 as *const DeviceResourceNode;
    }
    SetHcsBlobPath(configPath.as_mut_ptr());
    let mut mgrRoot: *const DeviceResourceNode = HcsGetRootNode();
    return mgrRoot;
}
