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
    pub fn open(_: *const core::ffi::c_char, _: core::ffi::c_int, ...) -> core::ffi::c_int;
    pub fn RegistHalFunc();
    pub fn malloc(_: size_t) -> *mut core::ffi::c_void;
    pub fn free(_: *mut core::ffi::c_void);
    pub fn lseek(_: core::ffi::c_int, _: off_t, _: core::ffi::c_int) -> off_t;
    pub fn strlen(_: *const core::ffi::c_char) -> size_t;
    pub fn realpath(
        _: *const core::ffi::c_char,
        _: *mut core::ffi::c_char,
    ) -> *mut core::ffi::c_char;
    pub fn mmap(
        _: *mut core::ffi::c_void,
        _: size_t,
        _: core::ffi::c_int,
        _: core::ffi::c_int,
        _: core::ffi::c_int,
        _: off_t,
    ) -> *mut core::ffi::c_void;
    pub fn munmap(_: *mut core::ffi::c_void, _: size_t) -> core::ffi::c_int;
    pub fn sysconf(_: core::ffi::c_int) -> core::ffi::c_long;
    pub fn HiLogPrint(
        type_0: LogType,
        level: LogLevel,
        domain: core::ffi::c_uint,
        tag: *const core::ffi::c_char,
        fmt: *const core::ffi::c_char,
        ...
    ) -> core::ffi::c_int;
}
pub type int32_t = core::ffi::c_int;
pub type ReadFileErrorCode = core::ffi::c_int;
pub const MMAP_PARAM_INVALID: ReadFileErrorCode = -6;
pub const MMAP_FAILED: ReadFileErrorCode = -5;
pub const READ_OFFSET_OUT_OF_RANGE: ReadFileErrorCode = -4;
pub const MMAP_COPY_FAILED: ReadFileErrorCode = -3;
pub const FILE_IS_CLOSE: ReadFileErrorCode = -2;
pub const DEST_BUFFER_IS_NULL: ReadFileErrorCode = -1;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct MmapInfo {
    pub mmapPosition: int32_t,
    pub readMoreLen: int32_t,
    pub mmapSize: int32_t,
    pub mapAddr: *mut core::ffi::c_char,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct FileRead {
    pub fp: int32_t,
    pub offset: int32_t,
    pub len: int32_t,
}
pub const V_OK: C2RustUnnamed = 0;
pub type size_t = core::ffi::c_uint;
pub type off_t = core::ffi::c_longlong;
pub const V_ERR_FILE_STAT: C2RustUnnamed = 4009754652;
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
pub const V_ERR_FILE_OPEN: C2RustUnnamed = 4009754651;
pub const V_ERR_MALLOC: C2RustUnnamed = 4009754656;
pub type C2RustUnnamed = core::ffi::c_uint;
pub const V_ERR: C2RustUnnamed = 4294967295;
pub const V_ERR_MEMCPY: C2RustUnnamed = 4009754655;
pub const V_ERR_MEMSET: C2RustUnnamed = 4009754654;
pub const V_ERR_FILE_LENGTH: C2RustUnnamed = 4009754653;
pub const V_ERR_INVALID_DEVID: C2RustUnnamed = 4009754650;
pub const V_ERR_INVALID_DATE: C2RustUnnamed = 4009754649;
pub const V_ERR_INVALID_APP_BUNDLE: C2RustUnnamed = 4009754648;
pub const V_ERR_INVALID_DISP_TYPE: C2RustUnnamed = 4009754647;
pub const V_ERR_GET_APPID: C2RustUnnamed = 4009754646;
pub const V_ERR_GET_CERT_PK: C2RustUnnamed = 4009754645;
pub const V_ERR_VERFIY_PROF_CERT: C2RustUnnamed = 4009754644;
pub const V_ERR_PROF_CONTENT_INVALID: C2RustUnnamed = 4009754643;
pub const V_ERR_GET_PARSE_PROFILE: C2RustUnnamed = 4009754642;
pub const V_ERR_GET_PROFILE_DATA: C2RustUnnamed = 4009754641;
pub const V_ERR_GET_CERT_TYPE: C2RustUnnamed = 4009754640;
pub const V_ERR_VERIFY_SIGNATURE: C2RustUnnamed = 4009754639;
pub const V_ERR_VERIFY_CERT_CHAIN: C2RustUnnamed = 4009754638;
pub const V_ERR_PARSE_PKC7_DATA: C2RustUnnamed = 4009754637;
pub const V_ERR_CALC_BLOCK_HASH: C2RustUnnamed = 4009754636;
pub const V_ERR_GET_ROOT_HASH: C2RustUnnamed = 4009754634;
pub const V_ERR_INVALID_HASH_ALG: C2RustUnnamed = 4009754633;
pub const V_ERR_INVALID_CONTENT_TAG: C2RustUnnamed = 4009754632;
pub const V_ERR_GET_HASH_DIFF: C2RustUnnamed = 4009754631;
pub const V_ERR_GET_SIGN_BLOCK: C2RustUnnamed = 4009754630;
pub const V_ERR_GET_SIGNHEAD: C2RustUnnamed = 4009754629;
pub const V_ERR_INTEGRITY: C2RustUnnamed = 4009754628;
pub const V_ERR_UNTRUSTED_CERT: C2RustUnnamed = 4009754627;
pub const V_ERR_GET_CERT_INFO: C2RustUnnamed = 4009754626;
static mut g_memoryPageSize: int32_t = 0 as int32_t;
pub unsafe extern "C" fn InitVerify(
    mut file: *mut FileRead,
    mut filePath: *const core::ffi::c_char,
    mut handle: *mut int32_t,
) -> int32_t {
    if handle.is_null() || file.is_null() || filePath.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: file open error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 11],
                [core::ffi::c_char; 11],
            >(*b"InitVerify\0"))
                .as_ptr(),
            32 as core::ffi::c_int,
        );
        return V_ERR_FILE_OPEN as core::ffi::c_uint as int32_t;
    }
    RegistHalFunc();
    let mut path: *mut core::ffi::c_char = malloc(
        (256 as core::ffi::c_int + 1 as core::ffi::c_int) as size_t,
    ) as *mut core::ffi::c_char;
    if path.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: path malloc error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 11],
                [core::ffi::c_char; 11],
            >(*b"InitVerify\0"))
                .as_ptr(),
            38 as core::ffi::c_int,
        );
        return V_ERR_MALLOC as core::ffi::c_uint as int32_t;
    }
    if strlen(filePath) > 256 as core::ffi::c_uint
        || (realpath(filePath, path)).is_null()
    {
        if !path.is_null() {
            free(path as *mut core::ffi::c_void);
            path = 0 as *mut core::ffi::c_char;
        }
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: file path error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 11],
                [core::ffi::c_char; 11],
            >(*b"InitVerify\0"))
                .as_ptr(),
            43 as core::ffi::c_int,
        );
        return V_ERR_FILE_OPEN as core::ffi::c_uint as int32_t;
    }
    *handle = open(path, 0 as core::ffi::c_int, 0 as core::ffi::c_int) as int32_t;
    if *handle < 0 as core::ffi::c_int {
        if !path.is_null() {
            free(path as *mut core::ffi::c_void);
            path = 0 as *mut core::ffi::c_char;
        }
        HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: file open error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 11],
                [core::ffi::c_char; 11],
            >(*b"InitVerify\0"))
                .as_ptr(),
            49 as core::ffi::c_int,
        );
        return V_ERR_FILE_OPEN as core::ffi::c_uint as int32_t;
    }
    if g_memoryPageSize == 0 as core::ffi::c_int {
        g_memoryPageSize = sysconf(30 as core::ffi::c_int) as int32_t;
    }
    if g_memoryPageSize <= 0 as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: MAP_FAILED %d\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 11],
                [core::ffi::c_char; 11],
            >(*b"InitVerify\0"))
                .as_ptr(),
            56 as core::ffi::c_int,
            g_memoryPageSize,
        );
        if !path.is_null() {
            free(path as *mut core::ffi::c_void);
            path = 0 as *mut core::ffi::c_char;
        }
        return V_ERR_FILE_STAT as core::ffi::c_uint as int32_t;
    }
    (*file).len = lseek(*handle, 0 as off_t, 2 as core::ffi::c_int) as int32_t;
    (*file).fp = *handle;
    if !path.is_null() {
        free(path as *mut core::ffi::c_void);
        path = 0 as *mut core::ffi::c_char;
    }
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn HapMMap(
    mut bufCapacity: int32_t,
    mut offset: int32_t,
    mut mmapInfo: *mut MmapInfo,
    mut file: *const FileRead,
) -> int32_t {
    if mmapInfo.is_null() || file.is_null() || bufCapacity <= 0 as core::ffi::c_int {
        return MMAP_FAILED as core::ffi::c_int as int32_t;
    }
    (*mmapInfo).mapAddr = -(1 as core::ffi::c_int) as *mut core::ffi::c_void
        as *mut core::ffi::c_char;
    if (*file).fp == -(1 as core::ffi::c_int) {
        return FILE_IS_CLOSE as core::ffi::c_int as int32_t;
    }
    if offset < 0 as core::ffi::c_int || offset > (*file).len - bufCapacity {
        return READ_OFFSET_OUT_OF_RANGE as core::ffi::c_int as int32_t;
    }
    lseek((*file).fp as core::ffi::c_int, offset as off_t, 0 as core::ffi::c_int);
    if g_memoryPageSize == 0 as core::ffi::c_int {
        return MMAP_FAILED as core::ffi::c_int as int32_t;
    }
    (*mmapInfo).mmapPosition = offset / g_memoryPageSize * g_memoryPageSize;
    (*mmapInfo).readMoreLen = (offset - (*mmapInfo).mmapPosition) as int32_t;
    (*mmapInfo).mmapSize = bufCapacity + (*mmapInfo).readMoreLen;
    (*mmapInfo).mapAddr = mmap(
        0 as *mut core::ffi::c_void,
        (*mmapInfo).mmapSize as size_t,
        1 as core::ffi::c_int,
        0x1 as core::ffi::c_int,
        (*file).fp as core::ffi::c_int,
        (*mmapInfo).mmapPosition as off_t,
    ) as *mut core::ffi::c_char;
    if (*mmapInfo).mapAddr
        == -(1 as core::ffi::c_int) as *mut core::ffi::c_void as *mut core::ffi::c_char
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: MAP_FAILED\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"HapMMap\0"))
                .as_ptr(),
            88 as core::ffi::c_int,
        );
        return MMAP_FAILED as core::ffi::c_int as int32_t;
    }
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn HapMUnMap(
    mut mapAddr: *mut core::ffi::c_char,
    mut mmapSize: int32_t,
) {
    if mapAddr.is_null() || mmapSize <= 0 as core::ffi::c_int {
        return;
    }
    munmap(mapAddr as *mut core::ffi::c_void, mmapSize as size_t);
}
