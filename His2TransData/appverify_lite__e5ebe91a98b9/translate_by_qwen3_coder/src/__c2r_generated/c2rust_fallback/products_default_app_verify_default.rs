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
    pub fn GetDevUdid(
        udid: *mut core::ffi::c_char,
        size: core::ffi::c_int,
    ) -> core::ffi::c_int;
}
pub type int32_t = core::ffi::c_int;
pub type GetDeviceUdid = Option<
    unsafe extern "C" fn(*mut core::ffi::c_uchar, int32_t) -> int32_t,
>;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct ProductDiff {
    pub devUdidFunc: GetDeviceUdid,
}
pub unsafe extern "C" fn GetUdid(
    mut udid: *mut core::ffi::c_uchar,
    mut size: int32_t,
) -> int32_t {
    let mut ret: int32_t = GetDevUdid(
        udid as *mut core::ffi::c_char,
        size as core::ffi::c_int,
    ) as int32_t;
    return ret;
}
pub unsafe extern "C" fn RegistBaseDefaultFunc(mut productFunc: *mut ProductDiff) {
    (*productFunc).devUdidFunc = Some(
        GetUdid as unsafe extern "C" fn(*mut core::ffi::c_uchar, int32_t) -> int32_t,
    ) as GetDeviceUdid;
}
