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
pub struct mbedtls_md_info_t {
    _unused: [u8; 0],
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct mbedtls_pk_info_t {
    _unused: [u8; 0],
}

// === C2R_C2RUST_EXTERN_TYPES_END ===

extern "C" {
    pub fn memcmp(
        _: *const core::ffi::c_void,
        _: *const core::ffi::c_void,
        _: size_t,
    ) -> core::ffi::c_int;
    pub fn ParseProfile(
        buf: *const core::ffi::c_char,
        len: int32_t,
        pf: *mut ProfileProf,
    ) -> int32_t;
    pub fn ProfFreeData(pf: *mut ProfileProf);
    pub fn strcmp(
        _: *const core::ffi::c_char,
        _: *const core::ffi::c_char,
    ) -> core::ffi::c_int;
    pub fn malloc(_: size_t) -> *mut core::ffi::c_void;
    pub fn VerifyProfileContent(pf: *const ProfileProf) -> int32_t;
    pub fn close(_: core::ffi::c_int) -> core::ffi::c_int;
    pub fn free(_: *mut core::ffi::c_void);
    pub fn lseek(_: core::ffi::c_int, _: off_t, _: core::ffi::c_int) -> off_t;
    pub fn read(_: core::ffi::c_int, _: *mut core::ffi::c_void, _: size_t) -> ssize_t;
    pub fn VerifyIntegrityChunk(
        digestAlgorithm: int32_t,
        fp: int32_t,
        signInfo: *const SignatureInfo,
        actualDigest: *const HapBuf,
    ) -> bool;
    pub fn InitVerify(
        file: *mut FileRead,
        filePath: *const core::ffi::c_char,
        handle: *mut int32_t,
    ) -> int32_t;
    pub fn GetDigestAlgorithmId(signAlgorithm: uint32_t) -> int32_t;
    pub fn strlen(_: *const core::ffi::c_char) -> size_t;
    pub fn mbedtls_base64_encode(
        dst: *mut core::ffi::c_uchar,
        dlen: size_t,
        olen: *mut size_t,
        src: *const core::ffi::c_uchar,
        slen: size_t,
    ) -> core::ffi::c_int;
    pub fn fstat(_: core::ffi::c_int, _: *mut stat) -> core::ffi::c_int;
    pub fn FindSignature(hapFile: *const FileRead, signInfo: *mut SignatureInfo) -> bool;
    pub fn CreateHapBuffer(hapBuffer: *mut HapBuf, len: int32_t) -> bool;
    pub fn ClearHapBuffer(hapBuffer: *mut HapBuf);
    pub fn HapGetInt64(
        buf: *const core::ffi::c_uchar,
        len: int32_t,
    ) -> core::ffi::c_longlong;
    pub fn HapGetInt(buf: *const core::ffi::c_uchar, len: int32_t) -> int32_t;
    pub fn HapGetUnsignedInt(buf: *const core::ffi::c_uchar, len: int32_t) -> uint32_t;
    pub fn memset_s(
        dest: *mut core::ffi::c_void,
        destMax: size_t,
        c: core::ffi::c_int,
        count: size_t,
    ) -> errno_t;
    pub fn mbedtls_md_info_from_type(md_type: mbedtls_md_type_t) -> *const mbedtls_md_info_t;
    pub fn PKCS7_ParseSignedData(
        buf: *const core::ffi::c_uchar,
        bufLen: size_t,
        pkcs7: *mut Pkcs7,
    ) -> int32_t;
    pub fn memcpy_s(
        dest: *mut core::ffi::c_void,
        destMax: size_t,
        src: *const core::ffi::c_void,
        count: size_t,
    ) -> errno_t;
    pub fn PKCS7_VerifyCertsChain(pkcs7: *const Pkcs7) -> int32_t;
    pub fn PKCS7_FreeRes(pkcs7: *mut Pkcs7);
    pub fn HiLogPrint(
        type_0: LogType,
        level: LogLevel,
        domain: core::ffi::c_uint,
        tag: *const core::ffi::c_char,
        fmt: *const core::ffi::c_char,
        ...
    ) -> core::ffi::c_int;
    pub fn PKCS7_GetContentData(
        pkcs7: *const Pkcs7,
        data: *mut *mut core::ffi::c_uchar,
        dataLen: *mut size_t,
    ) -> int32_t;
    pub fn PKCS7_GetDigestInSignerAuthAttr(
        signer: *const SignerInfo,
        dig: *mut *mut core::ffi::c_uchar,
        digLen: *mut size_t,
    ) -> int32_t;
    pub fn PKCS7_GetSignerAuthAttr(
        signer: *const SignerInfo,
        data: *mut *mut core::ffi::c_uchar,
        dataLen: *mut size_t,
    ) -> int32_t;
    pub fn PKCS7_VerifySignerSignature(
        pkcs7: *const Pkcs7,
        calcDigest: PKCS7_CalcDigest,
    ) -> int32_t;
    pub fn mbedtls_md_get_size(md_info: *const mbedtls_md_info_t) -> core::ffi::c_uchar;
    pub fn PKCS7_GetAllSignersResolvedInfo(pkcs7: *const Pkcs7) -> *mut SignersResovedInfo;
    pub fn PKCS7_FreeAllSignersResolvedInfo(sri: *mut SignersResovedInfo);
    pub fn PKCS7_EnableDebugMode(mode: bool) -> int32_t;
    pub fn snprintf_s(
        strDest: *mut core::ffi::c_char,
        destMax: size_t,
        count: size_t,
        format: *const core::ffi::c_char,
        ...
    ) -> core::ffi::c_int;
    pub fn mbedtls_md(
        md_info: *const mbedtls_md_info_t,
        input: *const core::ffi::c_uchar,
        ilen: size_t,
        output: *mut core::ffi::c_uchar,
    ) -> core::ffi::c_int;
    pub fn mbedtls_x509_crt_parse(
        chain: *mut mbedtls_x509_crt,
        buf: *const core::ffi::c_uchar,
        buflen: size_t,
    ) -> core::ffi::c_int;
    pub fn mbedtls_ecp_point_write_binary(
        grp: *const mbedtls_ecp_group,
        P: *const mbedtls_ecp_point,
        format: core::ffi::c_int,
        olen: *mut size_t,
        buf: *mut core::ffi::c_uchar,
        buflen: size_t,
    ) -> core::ffi::c_int;
    pub fn mbedtls_x509_crt_init(crt: *mut mbedtls_x509_crt);
    pub fn mbedtls_x509_crt_free(crt: *mut mbedtls_x509_crt);
    pub fn mbedtls_pk_get_type(ctx: *const mbedtls_pk_context) -> mbedtls_pk_type_t;
    pub fn mbedtls_pk_write_pubkey(
        p: *mut *mut core::ffi::c_uchar,
        start: *mut core::ffi::c_uchar,
        key: *const mbedtls_pk_context,
    ) -> core::ffi::c_int;
}
pub type int32_t = core::ffi::c_int;
pub type uint32_t = core::ffi::c_uint;
pub type size_t = core::ffi::c_uint;
pub type ssize_t = core::ffi::c_int;
pub type off_t = core::ffi::c_longlong;
pub type mbedtls_md_type_t = core::ffi::c_uint;
pub const MBEDTLS_MD_SHA3_512: mbedtls_md_type_t = 19;
pub const MBEDTLS_MD_SHA3_384: mbedtls_md_type_t = 18;
pub const MBEDTLS_MD_SHA3_256: mbedtls_md_type_t = 17;
pub const MBEDTLS_MD_SHA3_224: mbedtls_md_type_t = 16;
pub const MBEDTLS_MD_SHA512: mbedtls_md_type_t = 11;
pub const MBEDTLS_MD_SHA384: mbedtls_md_type_t = 10;
pub const MBEDTLS_MD_SHA256: mbedtls_md_type_t = 9;
pub const MBEDTLS_MD_SHA224: mbedtls_md_type_t = 8;
pub const MBEDTLS_MD_SHA1: mbedtls_md_type_t = 5;
pub const MBEDTLS_MD_RIPEMD160: mbedtls_md_type_t = 4;
pub const MBEDTLS_MD_MD5: mbedtls_md_type_t = 1;
pub const MBEDTLS_MD_NONE: mbedtls_md_type_t = 0;
pub type mbedtls_mpi_uint = uint32_t;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_mpi {
    pub private_p: *mut mbedtls_mpi_uint,
    pub private_s: core::ffi::c_short,
    pub private_n: core::ffi::c_ushort,
}
pub type mbedtls_ecp_group_id = core::ffi::c_uint;
pub const MBEDTLS_ECP_DP_CURVE448: mbedtls_ecp_group_id = 13;
pub const MBEDTLS_ECP_DP_SECP256K1: mbedtls_ecp_group_id = 12;
pub const MBEDTLS_ECP_DP_SECP224K1: mbedtls_ecp_group_id = 11;
pub const MBEDTLS_ECP_DP_SECP192K1: mbedtls_ecp_group_id = 10;
pub const MBEDTLS_ECP_DP_CURVE25519: mbedtls_ecp_group_id = 9;
pub const MBEDTLS_ECP_DP_BP512R1: mbedtls_ecp_group_id = 8;
pub const MBEDTLS_ECP_DP_BP384R1: mbedtls_ecp_group_id = 7;
pub const MBEDTLS_ECP_DP_BP256R1: mbedtls_ecp_group_id = 6;
pub const MBEDTLS_ECP_DP_SECP521R1: mbedtls_ecp_group_id = 5;
pub const MBEDTLS_ECP_DP_SECP384R1: mbedtls_ecp_group_id = 4;
pub const MBEDTLS_ECP_DP_SECP256R1: mbedtls_ecp_group_id = 3;
pub const MBEDTLS_ECP_DP_SECP224R1: mbedtls_ecp_group_id = 2;
pub const MBEDTLS_ECP_DP_SECP192R1: mbedtls_ecp_group_id = 1;
pub const MBEDTLS_ECP_DP_NONE: mbedtls_ecp_group_id = 0;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_ecp_point {
    pub private_X: mbedtls_mpi,
    pub private_Y: mbedtls_mpi,
    pub private_Z: mbedtls_mpi,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_ecp_group {
    pub id: mbedtls_ecp_group_id,
    pub P: mbedtls_mpi,
    pub A: mbedtls_mpi,
    pub B: mbedtls_mpi,
    pub G: mbedtls_ecp_point,
    pub N: mbedtls_mpi,
    pub pbits: size_t,
    pub nbits: size_t,
    pub private_h: core::ffi::c_uint,
    pub private_modp: Option<unsafe extern "C" fn(*mut mbedtls_mpi) -> core::ffi::c_int>,
    pub private_t_pre: Option<
        unsafe extern "C" fn(
            *mut mbedtls_ecp_point,
            *mut core::ffi::c_void,
        ) -> core::ffi::c_int,
    >,
    pub private_t_post: Option<
        unsafe extern "C" fn(
            *mut mbedtls_ecp_point,
            *mut core::ffi::c_void,
        ) -> core::ffi::c_int,
    >,
    pub private_t_data: *mut core::ffi::c_void,
    pub private_T: *mut mbedtls_ecp_point,
    pub private_T_size: size_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_ecp_keypair {
    pub private_grp: mbedtls_ecp_group,
    pub private_d: mbedtls_mpi,
    pub private_Q: mbedtls_ecp_point,
}
pub type mbedtls_pk_type_t = core::ffi::c_uint;
pub const MBEDTLS_PK_OPAQUE: mbedtls_pk_type_t = 7;
pub const MBEDTLS_PK_RSASSA_PSS: mbedtls_pk_type_t = 6;
pub const MBEDTLS_PK_RSA_ALT: mbedtls_pk_type_t = 5;
pub const MBEDTLS_PK_ECDSA: mbedtls_pk_type_t = 4;
pub const MBEDTLS_PK_ECKEY_DH: mbedtls_pk_type_t = 3;
pub const MBEDTLS_PK_ECKEY: mbedtls_pk_type_t = 2;
pub const MBEDTLS_PK_RSA: mbedtls_pk_type_t = 1;
pub const MBEDTLS_PK_NONE: mbedtls_pk_type_t = 0;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_pk_context {
    pub private_pk_info: *const mbedtls_pk_info_t,
    pub private_pk_ctx: *mut core::ffi::c_void,
}
pub type C2RustUnnamed = core::ffi::c_uint;
pub const V_ERR: C2RustUnnamed = 4294967295;
pub const V_ERR_MALLOC: C2RustUnnamed = 4009754656;
pub const V_ERR_MEMCPY: C2RustUnnamed = 4009754655;
pub const V_ERR_MEMSET: C2RustUnnamed = 4009754654;
pub const V_ERR_FILE_LENGTH: C2RustUnnamed = 4009754653;
pub const V_ERR_FILE_STAT: C2RustUnnamed = 4009754652;
pub const V_ERR_FILE_OPEN: C2RustUnnamed = 4009754651;
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
pub const V_OK: C2RustUnnamed = 0;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct ProfValidity {
    pub notBefore: int32_t,
    pub notAfter: int32_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct ProfBundleInfo {
    pub developerId: *mut core::ffi::c_char,
    pub devCert: *mut core::ffi::c_uchar,
    pub releaseCert: *mut core::ffi::c_uchar,
    pub bundleName: *mut core::ffi::c_char,
    pub appFeature: *mut core::ffi::c_char,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct ProfPermission {
    pub restricNum: int32_t,
    pub restricPermission: *mut *mut core::ffi::c_char,
    pub permissionNum: int32_t,
    pub permission: *mut *mut core::ffi::c_char,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct ProfDebugInfo {
    pub devIdType: *mut core::ffi::c_char,
    pub devidNum: int32_t,
    pub deviceId: *mut *mut core::ffi::c_char,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct ProfileProf {
    pub versionCode: int32_t,
    pub versionName: *mut core::ffi::c_char,
    pub uuid: *mut core::ffi::c_char,
    pub type_0: *mut core::ffi::c_char,
    pub appDistType: *mut core::ffi::c_char,
    pub validity: ProfValidity,
    pub bundleInfo: ProfBundleInfo,
    pub permission: ProfPermission,
    pub debugInfo: ProfDebugInfo,
    pub issuer: *mut core::ffi::c_char,
    pub appid: *mut core::ffi::c_char,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct AppSignPk {
    pub pk: *mut core::ffi::c_char,
    pub len: int32_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct VfyRst {
    pub profile: ProfileProf,
}
pub type VerifyResult = VfyRst;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct SignatureInfo {
    pub signHead: *mut HwSignHead,
    pub fullSignBlockOffset: int32_t,
    pub hapCoreDirOffset: int32_t,
    pub hapEocdOffset: int32_t,
    pub hapEocdSize: int32_t,
    pub fileSize: int32_t,
    pub version: int32_t,
    pub certType: int32_t,
}
#[derive(Copy, Clone)]
#[repr(C, packed(4))]
pub struct HwSignHead {
    pub blockNum: uint32_t,
    pub size: core::ffi::c_ulonglong,
    pub magicLow: core::ffi::c_ulonglong,
    pub magicHigh: core::ffi::c_ulonglong,
    pub version: uint32_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct FileRead {
    pub fp: int32_t,
    pub offset: int32_t,
    pub len: int32_t,
}
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
#[derive(Copy, Clone)]
#[repr(C)]
pub struct stat {
    pub st_dev: dev_t,
    pub __st_dev_padding: core::ffi::c_int,
    pub __st_ino_truncated: core::ffi::c_long,
    pub st_mode: mode_t,
    pub st_nlink: nlink_t,
    pub st_uid: uid_t,
    pub st_gid: gid_t,
    pub st_rdev: dev_t,
    pub __st_rdev_padding: core::ffi::c_int,
    pub st_size: off_t,
    pub st_blksize: blksize_t,
    pub st_blocks: blkcnt_t,
    pub __st_atim32: C2RustUnnamed_0,
    pub __st_mtim32: C2RustUnnamed_0,
    pub __st_ctim32: C2RustUnnamed_0,
    pub st_ino: ino_t,
    pub st_atim: timespec,
    pub st_mtim: timespec,
    pub st_ctim: timespec,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct timespec {
    pub tv_sec: time_t,
    pub tv_nsec: core::ffi::c_long,
}
pub type time_t = core::ffi::c_longlong;
pub type ino_t = core::ffi::c_ulonglong;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct C2RustUnnamed_0 {
    pub tv_sec: core::ffi::c_long,
    pub tv_nsec: core::ffi::c_long,
}
pub type blkcnt_t = core::ffi::c_longlong;
pub type blksize_t = core::ffi::c_long;
pub type dev_t = core::ffi::c_ulonglong;
pub type gid_t = core::ffi::c_uint;
pub type uid_t = core::ffi::c_uint;
pub type nlink_t = core::ffi::c_uint;
pub type mode_t = core::ffi::c_uint;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct CertInfo {
    pub issuerLen: int32_t,
    pub issuer: *mut core::ffi::c_char,
    pub subjectLen: int32_t,
    pub subject: *mut core::ffi::c_char,
    pub pkType: mbedtls_pk_type_t,
    pub pkLen: int32_t,
    pub pkBuf: *mut core::ffi::c_char,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct Pkcs7 {
    pub contentTypeOid: mbedtls_asn1_buf,
    pub signedData: SignedData,
    pub pem: mbedtls_pem_context,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_pem_context {
    pub private_buf: *mut core::ffi::c_uchar,
    pub private_buflen: size_t,
    pub private_info: *mut core::ffi::c_uchar,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct SignedData {
    pub version: int32_t,
    pub digestAlgIds: DigestAlgId,
    pub content: Content,
    pub certs: *mut mbedtls_x509_crt,
    pub crl: mbedtls_x509_crl,
    pub signers: SignerInfo,
}
pub type SignerInfo = tagSignerInfo;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct tagSignerInfo {
    pub version: int32_t,
    pub serial: mbedtls_x509_buf,
    pub issuer: mbedtls_x509_name,
    pub rootCert: *mut mbedtls_x509_crt,
    pub issuerRaw: mbedtls_x509_buf,
    pub digestAlgId: mbedtls_x509_buf,
    pub authAttr: mbedtls_x509_buf,
    pub authAttrRaw: mbedtls_x509_buf,
    pub digestEncAlgId: mbedtls_x509_buf,
    pub signature: mbedtls_x509_buf,
    pub unAuthAttr: mbedtls_x509_buf,
    pub certPath: SignerCertPath,
    pub next: *mut tagSignerInfo,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct SignerCertPath {
    pub depth: int32_t,
    pub crt: *mut mbedtls_x509_crt,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_x509_crt {
    pub private_own_buffer: core::ffi::c_int,
    pub raw: mbedtls_x509_buf,
    pub tbs: mbedtls_x509_buf,
    pub version: core::ffi::c_int,
    pub serial: mbedtls_x509_buf,
    pub sig_oid: mbedtls_x509_buf,
    pub issuer_raw: mbedtls_x509_buf,
    pub subject_raw: mbedtls_x509_buf,
    pub issuer: mbedtls_x509_name,
    pub subject: mbedtls_x509_name,
    pub valid_from: mbedtls_x509_time,
    pub valid_to: mbedtls_x509_time,
    pub pk_raw: mbedtls_x509_buf,
    pub pk: mbedtls_pk_context,
    pub issuer_id: mbedtls_x509_buf,
    pub subject_id: mbedtls_x509_buf,
    pub v3_ext: mbedtls_x509_buf,
    pub subject_alt_names: mbedtls_x509_sequence,
    pub subject_key_id: mbedtls_x509_buf,
    pub authority_key_id: mbedtls_x509_authority,
    pub certificate_policies: mbedtls_x509_sequence,
    pub private_ext_types: core::ffi::c_int,
    pub private_ca_istrue: core::ffi::c_int,
    pub private_max_pathlen: core::ffi::c_int,
    pub private_key_usage: core::ffi::c_uint,
    pub ext_key_usage: mbedtls_x509_sequence,
    pub private_ns_cert_type: core::ffi::c_uchar,
    pub private_sig: mbedtls_x509_buf,
    pub private_sig_md: mbedtls_md_type_t,
    pub private_sig_pk: mbedtls_pk_type_t,
    pub private_sig_opts: *mut core::ffi::c_void,
    pub next: *mut mbedtls_x509_crt,
}
pub type mbedtls_x509_buf = mbedtls_asn1_buf;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_asn1_buf {
    pub tag: core::ffi::c_int,
    pub len: size_t,
    pub p: *mut core::ffi::c_uchar,
}
pub type mbedtls_x509_sequence = mbedtls_asn1_sequence;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_asn1_sequence {
    pub buf: mbedtls_asn1_buf,
    pub next: *mut mbedtls_asn1_sequence,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_x509_authority {
    pub keyIdentifier: mbedtls_x509_buf,
    pub authorityCertIssuer: mbedtls_x509_sequence,
    pub authorityCertSerialNumber: mbedtls_x509_buf,
    pub raw: mbedtls_x509_buf,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_x509_time {
    pub year: core::ffi::c_int,
    pub mon: core::ffi::c_int,
    pub day: core::ffi::c_int,
    pub hour: core::ffi::c_int,
    pub min: core::ffi::c_int,
    pub sec: core::ffi::c_int,
}
pub type mbedtls_x509_name = mbedtls_asn1_named_data;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_asn1_named_data {
    pub oid: mbedtls_asn1_buf,
    pub val: mbedtls_asn1_buf,
    pub next: *mut mbedtls_asn1_named_data,
    pub private_next_merged: core::ffi::c_uchar,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_x509_crl {
    pub raw: mbedtls_x509_buf,
    pub tbs: mbedtls_x509_buf,
    pub version: core::ffi::c_int,
    pub sig_oid: mbedtls_x509_buf,
    pub issuer_raw: mbedtls_x509_buf,
    pub issuer: mbedtls_x509_name,
    pub this_update: mbedtls_x509_time,
    pub next_update: mbedtls_x509_time,
    pub entry: mbedtls_x509_crl_entry,
    pub crl_ext: mbedtls_x509_buf,
    pub private_sig_oid2: mbedtls_x509_buf,
    pub private_sig: mbedtls_x509_buf,
    pub private_sig_md: mbedtls_md_type_t,
    pub private_sig_pk: mbedtls_pk_type_t,
    pub private_sig_opts: *mut core::ffi::c_void,
    pub next: *mut mbedtls_x509_crl,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct mbedtls_x509_crl_entry {
    pub raw: mbedtls_x509_buf,
    pub serial: mbedtls_x509_buf,
    pub revocation_date: mbedtls_x509_time,
    pub entry_ext: mbedtls_x509_buf,
    pub next: *mut mbedtls_x509_crl_entry,
}
pub type Content = tagContent;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct tagContent {
    pub oid: mbedtls_asn1_buf,
    pub data: mbedtls_asn1_buf,
}
pub type DigestAlgId = tagDigestAlgId;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct tagDigestAlgId {
    pub algBuf: mbedtls_asn1_buf,
    pub next: *mut tagDigestAlgId,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct BlockHead {
    pub type_0: uint32_t,
    pub length: uint32_t,
    pub offset: uint32_t,
}
pub const SIGNATURE_BLOCK_TYPE: C2RustUnnamed_1 = 536870912;
pub type errno_t = core::ffi::c_int;
pub type PKCS7_CalcDigest = Option<
    unsafe extern "C" fn(
        *const Pkcs7,
        *const SignerInfo,
        mbedtls_md_type_t,
        *mut core::ffi::c_uchar,
        *mut size_t,
    ) -> int32_t,
>;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct HapBuf {
    pub buffer: *mut core::ffi::c_void,
    pub len: int32_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct ContentInfo {
    pub version: int32_t,
    pub blockNum: int32_t,
    pub size: int32_t,
    pub algId: int32_t,
    pub length: int32_t,
    pub hash: [core::ffi::c_char; 32],
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct SignersResovedInfo {
    pub signers: *mut SignerResovledInfo,
    pub nrOfSigners: int32_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct SignerResovledInfo {
    pub issuer: [core::ffi::c_char; 512],
    pub subject: [core::ffi::c_char; 512],
    pub depth: int32_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct TrustAppCert {
    pub maxCertPath: int32_t,
    pub name: *mut core::ffi::c_char,
    pub appSignCert: *mut core::ffi::c_char,
    pub profileSignCert: *mut core::ffi::c_char,
    pub profileDebugSignCert: *mut core::ffi::c_char,
    pub issueCA: *mut core::ffi::c_char,
}
pub const PROFILE_BLOCK_WITHSIGN_TYPE: C2RustUnnamed_1 = 536870914;
pub type C2RustUnnamed_1 = core::ffi::c_uint;
pub const PROPERTY_BLOCK_TYPE: C2RustUnnamed_1 = 536870915;
pub const KEY_ROTATION_BLOCK_TYPE: C2RustUnnamed_1 = 536870913;
static mut g_trustAppList: [TrustAppCert; 3] = [
    {
        let mut init = TrustAppCert {
            maxCertPath: 3 as int32_t,
            name: b"huawei app gallary\0" as *const u8 as *const core::ffi::c_char
                as *mut core::ffi::c_char,
            appSignCert: b"C=CN, O=Huawei, OU=HOS AppGallery, CN=HOS AppGallery Application Release\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            profileSignCert: b"C=CN, O=Huawei, OU=HOS AppGallery, CN=HOS Profile Management\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            profileDebugSignCert: b"C=CN, O=Huawei, OU=HOS AppGallery, CN=HOS Profile Management Debug\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            issueCA: b"C=CN, O=Huawei, OU=Huawei CBG, CN=Huawei CBG Software Signing Service CA\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
        };
        init
    },
    {
        let mut init = TrustAppCert {
            maxCertPath: 3 as int32_t,
            name: b"huawei system apps\0" as *const u8 as *const core::ffi::c_char
                as *mut core::ffi::c_char,
            appSignCert: b"C=CN, O=Huawei CBG, OU=HOS Development Team, CN=HOS Application Provision Release\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            profileSignCert: b"C=CN, O=Huawei CBG, OU=HOS Development Team, CN=HOS Application Provision Profile Release\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            profileDebugSignCert: b"C=CN, O=Huawei CBG, OU=HOS Development Team, CN=HOS Application Provision Profile Release_Debug\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            issueCA: b"C=CN, O=Huawei, OU=Huawei CBG, CN=Huawei CBG Software Signing Service CA\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
        };
        init
    },
    {
        let mut init = TrustAppCert {
            maxCertPath: 3 as int32_t,
            name: b"OpenHarmony apps\0" as *const u8 as *const core::ffi::c_char
                as *mut core::ffi::c_char,
            appSignCert: b"C=CN, O=OpenHarmony, OU=OpenHarmony Team, CN=OpenHarmony Application Release\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            profileSignCert: b"C=CN, O=OpenHarmony, OU=OpenHarmony Team, CN=OpenHarmony Application Profile Release\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            profileDebugSignCert: b"C=CN, O=OpenHarmony, OU=OpenHarmony Team, CN=OpenHarmony Application Profile Debug\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            issueCA: b"C=CN, O=OpenHarmony, OU=OpenHarmony Team, CN=OpenHarmony Application CA\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
        };
        init
    },
];
static mut g_trustAppListTest: [TrustAppCert; 2] = [
    {
        let mut init = TrustAppCert {
            maxCertPath: 3 as int32_t,
            name: b"huawei app gallary\0" as *const u8 as *const core::ffi::c_char
                as *mut core::ffi::c_char,
            appSignCert: b"C=CN, O=Huawei, OU=HOS AppGallery, CN=HOS AppGallery Application Release\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            profileSignCert: b"C=CN, O=Huawei, OU=HOS AppGallery, CN=HOS Profile Management\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            profileDebugSignCert: b"C=CN, O=Huawei, OU=HOS AppGallery, CN=HOS Profile Management Debug\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            issueCA: b"C=CN, O=Huawei, OU=Huawei CBG, CN=Huawei CBG Software Signing Service CA Test\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
        };
        init
    },
    {
        let mut init = TrustAppCert {
            maxCertPath: 3 as int32_t,
            name: b"huawei system apps\0" as *const u8 as *const core::ffi::c_char
                as *mut core::ffi::c_char,
            appSignCert: b"C=CN, O=Huawei CBG, OU=HOS Development Team, CN=HOS Application Provision Dev\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            profileSignCert: b"C=CN, O=Huawei CBG, OU=HOS Development Team, CN=HOS Application Provision Profile Dev\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            profileDebugSignCert: b"C=CN, O=Huawei CBG, OU=HOS Development Team, CN=HOS Application Provision Profile Dev_Debug\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
            issueCA: b"C=CN, O=Huawei, OU=Huawei CBG, CN=Huawei CBG Software Signing Service CA Test\0"
                as *const u8 as *const core::ffi::c_char as *mut core::ffi::c_char,
        };
        init
    },
];
static mut g_isDebugMode: bool = 0 as core::ffi::c_int != 0;
static mut g_isActsMode: bool = 0 as core::ffi::c_int != 0;
pub unsafe extern "C" fn SignHeadN2H(mut signHead: *mut HwSignHead) {
    (*signHead).blockNum = HapGetInt(
        &mut (*signHead).blockNum as *mut uint32_t as *mut core::ffi::c_uchar,
        ::core::mem::size_of::<uint32_t>() as int32_t,
    ) as uint32_t;
    (*signHead).size = HapGetInt64(
        &mut (*signHead).size as *mut core::ffi::c_ulonglong as *mut core::ffi::c_uchar,
        ::core::mem::size_of::<core::ffi::c_ulonglong>() as int32_t,
    ) as core::ffi::c_ulonglong;
    (*signHead).magicLow = HapGetInt64(
        &mut (*signHead).magicLow as *mut core::ffi::c_ulonglong
            as *mut core::ffi::c_uchar,
        ::core::mem::size_of::<core::ffi::c_ulonglong>() as int32_t,
    ) as core::ffi::c_ulonglong;
    (*signHead).magicHigh = HapGetInt64(
        &mut (*signHead).magicHigh as *mut core::ffi::c_ulonglong
            as *mut core::ffi::c_uchar,
        ::core::mem::size_of::<core::ffi::c_ulonglong>() as int32_t,
    ) as core::ffi::c_ulonglong;
    (*signHead).version = HapGetInt(
        &mut (*signHead).version as *mut uint32_t as *mut core::ffi::c_uchar,
        ::core::mem::size_of::<uint32_t>() as int32_t,
    ) as uint32_t;
}
pub unsafe extern "C" fn BlockHeadN2H(mut blockHead: *mut BlockHead) {
    (*blockHead).type_0 = HapGetUnsignedInt(
        &mut (*blockHead).type_0 as *mut uint32_t as *mut core::ffi::c_uchar,
        ::core::mem::size_of::<uint32_t>() as int32_t,
    );
    (*blockHead).length = HapGetUnsignedInt(
        &mut (*blockHead).length as *mut uint32_t as *mut core::ffi::c_uchar,
        ::core::mem::size_of::<uint32_t>() as int32_t,
    );
    (*blockHead).offset = HapGetUnsignedInt(
        &mut (*blockHead).offset as *mut uint32_t as *mut core::ffi::c_uchar,
        ::core::mem::size_of::<uint32_t>() as int32_t,
    );
}
pub unsafe extern "C" fn ContentN2H(mut content: *mut ContentInfo) {
    (*content).blockNum = HapGetInt(
        &mut (*content).blockNum as *mut int32_t as *mut core::ffi::c_uchar,
        ::core::mem::size_of::<int32_t>() as int32_t,
    );
    (*content).size = HapGetInt(
        &mut (*content).size as *mut int32_t as *mut core::ffi::c_uchar,
        ::core::mem::size_of::<int32_t>() as int32_t,
    );
    (*content).algId = HapGetInt(
        &mut (*content).algId as *mut int32_t as *mut core::ffi::c_uchar,
        ::core::mem::size_of::<int32_t>() as int32_t,
    );
    (*content).length = HapGetInt(
        &mut (*content).length as *mut int32_t as *mut core::ffi::c_uchar,
        ::core::mem::size_of::<int32_t>() as int32_t,
    );
}
pub unsafe extern "C" fn GetSignHead(
    mut file: *const FileRead,
    mut signInfo: *mut SignatureInfo,
) -> int32_t {
    let mut fileSt: stat = stat {
        st_dev: 0,
        __st_dev_padding: 0,
        __st_ino_truncated: 0,
        st_mode: 0,
        st_nlink: 0,
        st_uid: 0,
        st_gid: 0,
        st_rdev: 0,
        __st_rdev_padding: 0,
        st_size: 0,
        st_blksize: 0,
        st_blocks: 0,
        __st_atim32: C2RustUnnamed_0 {
            tv_sec: 0,
            tv_nsec: 0,
        },
        __st_mtim32: C2RustUnnamed_0 {
            tv_sec: 0,
            tv_nsec: 0,
        },
        __st_ctim32: C2RustUnnamed_0 {
            tv_sec: 0,
            tv_nsec: 0,
        },
        st_ino: 0,
        st_atim: timespec { tv_sec: 0, tv_nsec: 0 },
        st_mtim: timespec { tv_sec: 0, tv_nsec: 0 },
        st_ctim: timespec { tv_sec: 0, tv_nsec: 0 },
    };
    let mut ret: int32_t = fstat((*file).fp as core::ffi::c_int, &mut fileSt) as int32_t;
    if ret != 0 as core::ffi::c_int
        || (fileSt.st_size as core::ffi::c_ulonglong)
            < ::core::mem::size_of::<HwSignHead>() as core::ffi::c_ulonglong
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: fstat error, %d, filelen: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 12],
                [core::ffi::c_char; 12],
            >(*b"GetSignHead\0"))
                .as_ptr(),
            121 as core::ffi::c_int,
            ret,
            fileSt.st_size as core::ffi::c_int,
        );
        return V_ERR_GET_SIGNHEAD as core::ffi::c_uint as int32_t;
    }
    if !FindSignature(file, signInfo) {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: find signature error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 12],
                [core::ffi::c_char; 12],
            >(*b"GetSignHead\0"))
                .as_ptr(),
            125 as core::ffi::c_int,
        );
        return V_ERR_GET_SIGNHEAD as core::ffi::c_uint as int32_t;
    }
    if ((*signInfo).hapCoreDirOffset as usize)
        < ::core::mem::size_of::<HwSignHead>() as usize
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: hapCoreDirOffset error, %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 12],
                [core::ffi::c_char; 12],
            >(*b"GetSignHead\0"))
                .as_ptr(),
            129 as core::ffi::c_int,
            (*signInfo).hapCoreDirOffset,
        );
        return V_ERR_GET_SIGNHEAD as core::ffi::c_uint as int32_t;
    }
    ret = lseek(
        (*file).fp as core::ffi::c_int,
        ((*signInfo).hapCoreDirOffset as usize)
            .wrapping_sub(::core::mem::size_of::<HwSignHead>() as usize) as off_t,
        0 as core::ffi::c_int,
    ) as int32_t;
    if ret < 0 as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: lseek error, %d\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 12],
                [core::ffi::c_char; 12],
            >(*b"GetSignHead\0"))
                .as_ptr(),
            134 as core::ffi::c_int,
            ret,
        );
        return V_ERR_GET_SIGNHEAD as core::ffi::c_uint as int32_t;
    }
    let mut signHead: *mut HwSignHead = malloc(
        ::core::mem::size_of::<HwSignHead>() as size_t,
    ) as *mut HwSignHead;
    if signHead.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: signHead is null\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 12],
                [core::ffi::c_char; 12],
            >(*b"GetSignHead\0"))
                .as_ptr(),
            138 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    let mut readLen: int32_t = read(
        (*file).fp as core::ffi::c_int,
        signHead as *mut core::ffi::c_void,
        ::core::mem::size_of::<HwSignHead>() as size_t,
    ) as int32_t;
    if readLen as usize != ::core::mem::size_of::<HwSignHead>() as usize {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: readLen %d, %d\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 12],
                [core::ffi::c_char; 12],
            >(*b"GetSignHead\0"))
                .as_ptr(),
            141 as core::ffi::c_int,
            readLen,
            ::core::mem::size_of::<HwSignHead>() as core::ffi::c_int,
        );
        if !signHead.is_null() {
            free(signHead as *mut core::ffi::c_void);
            signHead = 0 as *mut HwSignHead;
        }
        return V_ERR_GET_SIGNHEAD as core::ffi::c_uint as int32_t;
    }
    SignHeadN2H(signHead);
    let mut magicLow: core::ffi::c_ulonglong = 7451613641622775868
        as core::ffi::c_ulonglong;
    let mut magicHigh: core::ffi::c_ulonglong = 4497797983070462062
        as core::ffi::c_ulonglong;
    if (*signHead).version < 3 as core::ffi::c_uint {
        magicLow = 2334950737560224072 as core::ffi::c_ulonglong;
        magicHigh = 3617552046287187010 as core::ffi::c_ulonglong;
    }
    if (*signHead).magicLow != magicLow || (*signHead).magicHigh != magicHigh {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: sign head magic invalid\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 12],
                [core::ffi::c_char; 12],
            >(*b"GetSignHead\0"))
                .as_ptr(),
            153 as core::ffi::c_int,
        );
        if !signHead.is_null() {
            free(signHead as *mut core::ffi::c_void);
            signHead = 0 as *mut HwSignHead;
        }
        return V_ERR_GET_SIGNHEAD as core::ffi::c_uint as int32_t;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: sign head: size: %llu, blockNum:0x%x\0" as *const u8
            as *const core::ffi::c_char,
        (::core::mem::transmute::<[u8; 12], [core::ffi::c_char; 12]>(*b"GetSignHead\0"))
            .as_ptr(),
        157 as core::ffi::c_int,
        (*signHead).size,
        (*signHead).blockNum,
    );
    (*signInfo).signHead = signHead;
    (*signInfo).fullSignBlockOffset = ((*signInfo).hapCoreDirOffset as core::ffi::c_int
        - (*signHead).size as core::ffi::c_int) as int32_t;
    (*signInfo).fileSize = fileSt.st_size as int32_t;
    if (*signInfo).fullSignBlockOffset <= 0 as core::ffi::c_int
        || (*signInfo).fullSignBlockOffset >= (*signInfo).hapCoreDirOffset
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: fullSignBlockOffset invalid\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 12],
                [core::ffi::c_char; 12],
            >(*b"GetSignHead\0"))
                .as_ptr(),
            162 as core::ffi::c_int,
        );
        if !signHead.is_null() {
            free(signHead as *mut core::ffi::c_void);
            signHead = 0 as *mut HwSignHead;
        }
        return V_ERR_GET_SIGNHEAD as core::ffi::c_uint as int32_t;
    }
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn FindBlockHead(
    mut signInfo: *const SignatureInfo,
    mut fp: int32_t,
    mut blockType: int32_t,
    mut block: *mut BlockHead,
) -> int32_t {
    let mut signH: *mut HwSignHead = (*signInfo).signHead;
    lseek(
        fp as core::ffi::c_int,
        (*signInfo).fullSignBlockOffset as off_t,
        0 as core::ffi::c_int,
    );
    let mut num: int32_t = (*signH).blockNum as int32_t;
    if num > 1024 as core::ffi::c_int {
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    loop {
        let fresh0 = num;
        num = num - 1;
        if !(fresh0 > 0 as core::ffi::c_int) {
            break;
        }
        let mut readLen: int32_t = read(
            fp as core::ffi::c_int,
            block as *mut core::ffi::c_void,
            ::core::mem::size_of::<BlockHead>() as size_t,
        ) as int32_t;
        if readLen as usize != ::core::mem::size_of::<BlockHead>() as usize {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xd001100 as core::ffi::c_uint,
                b"appverify\0" as *const u8 as *const core::ffi::c_char,
                b"[%s:%d]: find block head , read err %d, %d\0" as *const u8
                    as *const core::ffi::c_char,
                (::core::mem::transmute::<
                    [u8; 14],
                    [core::ffi::c_char; 14],
                >(*b"FindBlockHead\0"))
                    .as_ptr(),
                181 as core::ffi::c_int,
                readLen,
                ::core::mem::size_of::<BlockHead>() as core::ffi::c_int,
            );
            return V_ERR as core::ffi::c_uint as int32_t;
        }
        let mut type_0: int32_t = HapGetInt(
            &mut (*block).type_0 as *mut uint32_t as *mut core::ffi::c_uchar,
            ::core::mem::size_of::<uint32_t>() as int32_t,
        );
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: find block type: %0x\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 14],
                [core::ffi::c_char; 14],
            >(*b"FindBlockHead\0"))
                .as_ptr(),
            185 as core::ffi::c_int,
            type_0,
        );
        if type_0 == blockType {
            BlockHeadN2H(block);
            return V_OK as core::ffi::c_int as int32_t;
        }
    }
    HiLogPrint(
        LOG_CORE,
        LOG_ERROR,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: get sign block by type failed, type: %d\0" as *const u8
            as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 14],
            [core::ffi::c_char; 14],
        >(*b"FindBlockHead\0"))
            .as_ptr(),
        191 as core::ffi::c_int,
        blockType,
    );
    return V_ERR as core::ffi::c_uint as int32_t;
}
pub unsafe extern "C" fn GetSignBlockByType(
    mut signInfo: *const SignatureInfo,
    mut fp: int32_t,
    mut blockType: int32_t,
    mut len: *mut int32_t,
    mut blockHead: *mut BlockHead,
) -> *mut core::ffi::c_char {
    if signInfo.is_null() || blockHead.is_null() {
        return 0 as *mut core::ffi::c_char;
    }
    let mut ret: int32_t = FindBlockHead(signInfo, fp, blockType, blockHead);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: find block head error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 19],
                [core::ffi::c_char; 19],
            >(*b"GetSignBlockByType\0"))
                .as_ptr(),
            203 as core::ffi::c_int,
        );
        return 0 as *mut core::ffi::c_char;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: type: %u, len: %u, offset: %u signoffset: %d\0" as *const u8
            as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 19],
            [core::ffi::c_char; 19],
        >(*b"GetSignBlockByType\0"))
            .as_ptr(),
        207 as core::ffi::c_int,
        (*blockHead).type_0,
        (*blockHead).length,
        (*blockHead).offset,
        (*signInfo).fullSignBlockOffset,
    );
    if (*blockHead).length == 0 as core::ffi::c_uint
        || (*blockHead).length
            > ((*signInfo).hapCoreDirOffset - (*signInfo).fullSignBlockOffset)
                as core::ffi::c_uint
    {
        return 0 as *mut core::ffi::c_char;
    }
    if ((*blockHead).length as core::ffi::c_uint).wrapping_add(1 as core::ffi::c_uint)
        >= (*signInfo).fileSize as core::ffi::c_uint
    {
        return 0 as *mut core::ffi::c_char;
    }
    let mut buf: *mut core::ffi::c_char = malloc(
        ((*blockHead).length as size_t).wrapping_add(1 as size_t),
    ) as *mut core::ffi::c_char;
    if buf.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: malloc error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 19],
                [core::ffi::c_char; 19],
            >(*b"GetSignBlockByType\0"))
                .as_ptr(),
            222 as core::ffi::c_int,
        );
        return 0 as *mut core::ffi::c_char;
    }
    *buf.offset((*blockHead).length as isize) = '\0' as i32 as core::ffi::c_char;
    let mut fileSt: stat = stat {
        st_dev: 0,
        __st_dev_padding: 0,
        __st_ino_truncated: 0,
        st_mode: 0,
        st_nlink: 0,
        st_uid: 0,
        st_gid: 0,
        st_rdev: 0,
        __st_rdev_padding: 0,
        st_size: 0,
        st_blksize: 0,
        st_blocks: 0,
        __st_atim32: C2RustUnnamed_0 {
            tv_sec: 0,
            tv_nsec: 0,
        },
        __st_mtim32: C2RustUnnamed_0 {
            tv_sec: 0,
            tv_nsec: 0,
        },
        __st_ctim32: C2RustUnnamed_0 {
            tv_sec: 0,
            tv_nsec: 0,
        },
        st_ino: 0,
        st_atim: timespec { tv_sec: 0, tv_nsec: 0 },
        st_mtim: timespec { tv_sec: 0, tv_nsec: 0 },
        st_ctim: timespec { tv_sec: 0, tv_nsec: 0 },
    };
    ret = fstat(fp as core::ffi::c_int, &mut fileSt) as int32_t;
    if ret != 0 as core::ffi::c_int
        || fileSt.st_size
            < ((*signInfo).fullSignBlockOffset as uint32_t)
                .wrapping_add((*blockHead).offset)
                .wrapping_add((*blockHead).length) as core::ffi::c_longlong
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: fstat error, %d, filelen: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 19],
                [core::ffi::c_char; 19],
            >(*b"GetSignBlockByType\0"))
                .as_ptr(),
            229 as core::ffi::c_int,
            ret,
            fileSt.st_size as core::ffi::c_int,
        );
        if !buf.is_null() {
            free(buf as *mut core::ffi::c_void);
            buf = 0 as *mut core::ffi::c_char;
        }
        return 0 as *mut core::ffi::c_char;
    }
    lseek(
        fp as core::ffi::c_int,
        ((*signInfo).fullSignBlockOffset as uint32_t).wrapping_add((*blockHead).offset)
            as off_t,
        0 as core::ffi::c_int,
    );
    let mut readLen: int32_t = read(
        fp as core::ffi::c_int,
        buf as *mut core::ffi::c_void,
        (*blockHead).length as size_t,
    ) as int32_t;
    if readLen as core::ffi::c_uint != (*blockHead).length {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: read error: %d, %d\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 19],
                [core::ffi::c_char; 19],
            >(*b"GetSignBlockByType\0"))
                .as_ptr(),
            236 as core::ffi::c_int,
            readLen,
            (*blockHead).length,
        );
        if !buf.is_null() {
            free(buf as *mut core::ffi::c_void);
            buf = 0 as *mut core::ffi::c_char;
        }
        return 0 as *mut core::ffi::c_char;
    }
    *len = readLen;
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: buf begin\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 19],
            [core::ffi::c_char; 19],
        >(*b"GetSignBlockByType\0"))
            .as_ptr(),
        241 as core::ffi::c_int,
    );
    return buf;
}
pub unsafe extern "C" fn GetHashUnitLen(mut hashAlg: int32_t) -> int32_t {
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: algId: %d\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 15],
            [core::ffi::c_char; 15],
        >(*b"GetHashUnitLen\0"))
            .as_ptr(),
        247 as core::ffi::c_int,
        hashAlg,
    );
    return mbedtls_md_get_size(mbedtls_md_info_from_type(hashAlg as mbedtls_md_type_t))
        as int32_t;
}
pub unsafe extern "C" fn CalcCmpContHash(
    mut pkcs7: *const Pkcs7,
    mut signer: *const SignerInfo,
    mut algType: mbedtls_md_type_t,
    mut hash: *mut core::ffi::c_uchar,
    mut hashLen: *mut size_t,
) -> int32_t {
    let mut rc: int32_t = 0;
    let mut input: *mut core::ffi::c_uchar = 0 as *mut core::ffi::c_uchar;
    let mut inputLen: size_t = 0;
    rc = PKCS7_GetContentData(pkcs7 as *mut Pkcs7, &mut input, &mut inputLen);
    if rc != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: rc not ok\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 16],
                [core::ffi::c_char; 16],
            >(*b"CalcCmpContHash\0"))
                .as_ptr(),
            260 as core::ffi::c_int,
        );
        return rc;
    }
    rc = mbedtls_md(mbedtls_md_info_from_type(algType), input, inputLen, hash)
        as int32_t;
    if rc != 0 {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: Error: calc digest failed\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 16],
                [core::ffi::c_char; 16],
            >(*b"CalcCmpContHash\0"))
                .as_ptr(),
            264 as core::ffi::c_int,
        );
        return rc;
    }
    *hashLen = mbedtls_md_get_size(mbedtls_md_info_from_type(algType)) as size_t;
    let mut digInAttr: *mut core::ffi::c_uchar = 0 as *mut core::ffi::c_uchar;
    let mut digInAttrLen: size_t = 0;
    rc = PKCS7_GetDigestInSignerAuthAttr(
        signer as *mut SignerInfo,
        &mut digInAttr,
        &mut digInAttrLen,
    );
    if rc != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: PKCS7_GetDigestInSignerAuthAttr error: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 16],
                [core::ffi::c_char; 16],
            >(*b"CalcCmpContHash\0"))
                .as_ptr(),
            274 as core::ffi::c_int,
            rc,
        );
        return rc;
    }
    if digInAttrLen != *hashLen {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: Error: content hash len is not equal with attr's hash len\0"
                as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 16],
                [core::ffi::c_char; 16],
            >(*b"CalcCmpContHash\0"))
                .as_ptr(),
            278 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    if memcmp(
        hash as *const core::ffi::c_void,
        digInAttr as *const core::ffi::c_void,
        digInAttrLen,
    ) != 0 as core::ffi::c_int
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: Error: content hash not equal with attr hash\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 16],
                [core::ffi::c_char; 16],
            >(*b"CalcCmpContHash\0"))
                .as_ptr(),
            282 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn CalcDigest(
    mut pkcs7: *const Pkcs7,
    mut signer: *const SignerInfo,
    mut algType: mbedtls_md_type_t,
    mut hash: *mut core::ffi::c_uchar,
    mut hashLen: *mut size_t,
) -> int32_t {
    let mut rc: int32_t = 0;
    let mut input: *mut core::ffi::c_uchar = 0 as *mut core::ffi::c_uchar;
    let mut inputLen: size_t = 0;
    rc = CalcCmpContHash(pkcs7, signer, algType, hash, hashLen);
    if rc != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: Error: content hash not equal with attr hash\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 11],
                [core::ffi::c_char; 11],
            >(*b"CalcDigest\0"))
                .as_ptr(),
            296 as core::ffi::c_int,
        );
        return rc;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: signer context hash equal with attr hash\0" as *const u8
            as *const core::ffi::c_char,
        (::core::mem::transmute::<[u8; 11], [core::ffi::c_char; 11]>(*b"CalcDigest\0"))
            .as_ptr(),
        299 as core::ffi::c_int,
    );
    rc = PKCS7_GetSignerAuthAttr(signer, &mut input, &mut inputLen);
    if rc != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: Error: PKCS7_GetSignerAuthAttr failed ret: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 11],
                [core::ffi::c_char; 11],
            >(*b"CalcDigest\0"))
                .as_ptr(),
            304 as core::ffi::c_int,
            rc,
        );
        return rc;
    }
    rc = mbedtls_md(mbedtls_md_info_from_type(algType), input, inputLen, hash)
        as int32_t;
    if rc != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: Error: calc digest failed ret: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 11],
                [core::ffi::c_char; 11],
            >(*b"CalcDigest\0"))
                .as_ptr(),
            309 as core::ffi::c_int,
            rc,
        );
        return rc;
    }
    *hashLen = mbedtls_md_get_size(mbedtls_md_info_from_type(algType)) as size_t;
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn VerifyRawHash(
    mut signInfo: *const SignatureInfo,
    mut fileRead: *const FileRead,
    mut pkcs7Handle: *const Pkcs7,
) -> int32_t {
    let mut input: *mut core::ffi::c_uchar = 0 as *mut core::ffi::c_uchar;
    let mut inputLen: size_t = 0 as size_t;
    let mut ret: int32_t = PKCS7_GetContentData(
        pkcs7Handle as *mut Pkcs7,
        &mut input,
        &mut inputLen,
    );
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: get content info error: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 14],
                [core::ffi::c_char; 14],
            >(*b"VerifyRawHash\0"))
                .as_ptr(),
            324 as core::ffi::c_int,
            ret,
        );
        return ret;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: content: len: %d\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 14],
            [core::ffi::c_char; 14],
        >(*b"VerifyRawHash\0"))
            .as_ptr(),
        327 as core::ffi::c_int,
        inputLen as core::ffi::c_int,
    );
    let mut content: *mut ContentInfo = malloc(
        ::core::mem::size_of::<ContentInfo>() as size_t,
    ) as *mut ContentInfo;
    if content.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: content is null\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 14],
                [core::ffi::c_char; 14],
            >(*b"VerifyRawHash\0"))
                .as_ptr(),
            330 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    ret = memcpy_s(
        content as *mut core::ffi::c_void,
        ::core::mem::size_of::<ContentInfo>() as size_t,
        input as *const core::ffi::c_void,
        inputLen,
    ) as int32_t;
    if ret != 0 as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: mem cpy error, ret: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 14],
                [core::ffi::c_char; 14],
            >(*b"VerifyRawHash\0"))
                .as_ptr(),
            334 as core::ffi::c_int,
            ret,
        );
        if !content.is_null() {
            free(content as *mut core::ffi::c_void);
            content = 0 as *mut ContentInfo;
        }
        return ret;
    }
    ContentN2H(content);
    (*content).algId = GetDigestAlgorithmId((*content).algId as uint32_t);
    if (*content).algId != MBEDTLS_MD_SHA256 as core::ffi::c_int
        && (*content).algId != MBEDTLS_MD_SHA384 as core::ffi::c_int
        && (*content).algId != MBEDTLS_MD_SHA512 as core::ffi::c_int
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: hash alg invalid\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 14],
                [core::ffi::c_char; 14],
            >(*b"VerifyRawHash\0"))
                .as_ptr(),
            341 as core::ffi::c_int,
        );
        if !content.is_null() {
            free(content as *mut core::ffi::c_void);
            content = 0 as *mut ContentInfo;
        }
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    let mut actualDigest: HapBuf = {
        let mut init = HapBuf {
            buffer: 0 as *mut core::ffi::c_void,
            len: 0,
        };
        init
    };
    let mut rootHashLen: int32_t = GetHashUnitLen((*content).algId);
    if !CreateHapBuffer(&mut actualDigest, rootHashLen) {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: create buf fail\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 14],
                [core::ffi::c_char; 14],
            >(*b"VerifyRawHash\0"))
                .as_ptr(),
            348 as core::ffi::c_int,
        );
        if !content.is_null() {
            free(content as *mut core::ffi::c_void);
            content = 0 as *mut ContentInfo;
        }
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    if !VerifyIntegrityChunk(
        (*content).algId,
        (*fileRead).fp,
        signInfo,
        &mut actualDigest,
    ) {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: get raw hash failed\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 14],
                [core::ffi::c_char; 14],
            >(*b"VerifyRawHash\0"))
                .as_ptr(),
            353 as core::ffi::c_int,
        );
        ClearHapBuffer(&mut actualDigest);
        if !content.is_null() {
            free(content as *mut core::ffi::c_void);
            content = 0 as *mut ContentInfo;
        }
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    if actualDigest.len != (*content).length
        || memcmp(
            actualDigest.buffer,
            ((*content).hash).as_mut_ptr() as *const core::ffi::c_void,
            actualDigest.len as size_t,
        ) != 0 as core::ffi::c_int
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: hash diff\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 14],
                [core::ffi::c_char; 14],
            >(*b"VerifyRawHash\0"))
                .as_ptr(),
            359 as core::ffi::c_int,
        );
        if !content.is_null() {
            free(content as *mut core::ffi::c_void);
            content = 0 as *mut ContentInfo;
        }
        ClearHapBuffer(&mut actualDigest);
        return V_ERR_GET_HASH_DIFF as core::ffi::c_uint as int32_t;
    }
    if !content.is_null() {
        free(content as *mut core::ffi::c_void);
        content = 0 as *mut ContentInfo;
    }
    ClearHapBuffer(&mut actualDigest);
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn GetCertTypeBySourceName(mut cert: *const TrustAppCert) -> int32_t {
    if cert.is_null() {
        return 2 as int32_t
    } else if strcmp(
        (*cert).name,
        b"huawei app gallary\0" as *const u8 as *const core::ffi::c_char,
    ) == 0 as core::ffi::c_int
    {
        return 0 as int32_t
    } else if strcmp(
        (*cert).name,
        b"huawei system apps\0" as *const u8 as *const core::ffi::c_char,
    ) == 0 as core::ffi::c_int
    {
        return 1 as int32_t
    } else if strcmp(
        (*cert).name,
        b"OpenHarmony apps\0" as *const u8 as *const core::ffi::c_char,
    ) == 0 as core::ffi::c_int
    {
        return 1 as int32_t
    } else {
        return 2 as int32_t
    };
}
pub unsafe extern "C" fn GetProfSourceBySigningCert(
    mut signer: *const SignerResovledInfo,
    mut trustList: *const TrustAppCert,
    mut num: int32_t,
) -> *const TrustAppCert {
    let mut i: int32_t = 0 as int32_t;
    while i < num {
        if strcmp((*trustList.offset(i as isize)).issueCA, ((*signer).issuer).as_ptr())
            == 0 as core::ffi::c_int
        {
            if strcmp(
                (*trustList.offset(i as isize)).profileSignCert,
                ((*signer).subject).as_ptr(),
            ) == 0 as core::ffi::c_int
                || strcmp(
                    (*trustList.offset(i as isize)).profileDebugSignCert,
                    ((*signer).subject).as_ptr(),
                ) == 0 as core::ffi::c_int
            {
                HiLogPrint(
                    LOG_CORE,
                    LOG_INFO,
                    0xd001100 as core::ffi::c_uint,
                    b"appverify\0" as *const u8 as *const core::ffi::c_char,
                    b"[%s:%d]: profile source name : %s\0" as *const u8
                        as *const core::ffi::c_char,
                    (::core::mem::transmute::<
                        [u8; 27],
                        [core::ffi::c_char; 27],
                    >(*b"GetProfSourceBySigningCert\0"))
                        .as_ptr(),
                    393 as core::ffi::c_int,
                    g_trustAppList[i as usize].name,
                );
                return &*trustList.offset(i as isize) as *const TrustAppCert;
            }
        }
        i += 1;
    }
    return 0 as *const TrustAppCert;
}
pub unsafe extern "C" fn GetProfileCertTypeBySignInfo(
    mut signer: *mut SignerResovledInfo,
    mut certType: *mut int32_t,
) -> int32_t {
    let mut trustCert: *const TrustAppCert = GetProfSourceBySigningCert(
        signer,
        g_trustAppList.as_ptr(),
        (::core::mem::size_of::<[TrustAppCert; 3]>() as usize)
            .wrapping_div(::core::mem::size_of::<TrustAppCert>() as usize) as int32_t,
    );
    if g_isDebugMode as core::ffi::c_int != 0 && trustCert.is_null() {
        trustCert = GetProfSourceBySigningCert(
            signer,
            g_trustAppListTest.as_ptr(),
            (::core::mem::size_of::<[TrustAppCert; 2]>() as usize)
                .wrapping_div(::core::mem::size_of::<TrustAppCert>() as usize) as int32_t,
        );
    }
    if !trustCert.is_null() && (*trustCert).maxCertPath < (*signer).depth {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: cert maxdepth error: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 29],
                [core::ffi::c_char; 29],
            >(*b"GetProfileCertTypeBySignInfo\0"))
                .as_ptr(),
            412 as core::ffi::c_int,
            (*signer).depth,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    *certType = GetCertTypeBySourceName(trustCert);
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn GetAppSourceBySigningCert(
    mut signer: *const SignerResovledInfo,
    mut trustList: *const TrustAppCert,
    mut num: int32_t,
) -> *const TrustAppCert {
    let mut i: int32_t = 0 as int32_t;
    while i < num {
        if strcmp(
            (*trustList.offset(i as isize)).appSignCert,
            ((*signer).subject).as_ptr(),
        ) == 0 as core::ffi::c_int
            && strcmp(
                (*trustList.offset(i as isize)).issueCA,
                ((*signer).issuer).as_ptr(),
            ) == 0 as core::ffi::c_int
        {
            return &*trustList.offset(i as isize) as *const TrustAppCert;
        }
        i += 1;
    }
    return 0 as *const TrustAppCert;
}
pub unsafe extern "C" fn GetAppCertTypeBySignInfo(
    mut signer: *mut SignerResovledInfo,
    mut certType: *mut int32_t,
) -> int32_t {
    let mut trustCert: *const TrustAppCert = GetAppSourceBySigningCert(
        signer,
        g_trustAppList.as_ptr(),
        (::core::mem::size_of::<[TrustAppCert; 3]>() as usize)
            .wrapping_div(::core::mem::size_of::<TrustAppCert>() as usize) as int32_t,
    );
    if g_isDebugMode as core::ffi::c_int != 0 && trustCert.is_null() {
        trustCert = GetAppSourceBySigningCert(
            signer,
            g_trustAppListTest.as_ptr(),
            (::core::mem::size_of::<[TrustAppCert; 2]>() as usize)
                .wrapping_div(::core::mem::size_of::<TrustAppCert>() as usize) as int32_t,
        );
    }
    if !trustCert.is_null() && (*trustCert).maxCertPath < (*signer).depth {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: cert maxdepth error: %d %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 25],
                [core::ffi::c_char; 25],
            >(*b"GetAppCertTypeBySignInfo\0"))
                .as_ptr(),
            443 as core::ffi::c_int,
            (*trustCert).maxCertPath,
            (*signer).depth,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    *certType = GetCertTypeBySourceName(trustCert);
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn GetAppSingerCertType(
    mut pkcs7Handle: *mut Pkcs7,
    mut certType: *mut int32_t,
) -> int32_t {
    let mut sri: *mut SignersResovedInfo = PKCS7_GetAllSignersResolvedInfo(pkcs7Handle);
    if sri.is_null() || (*sri).nrOfSigners == 0 as core::ffi::c_int {
        PKCS7_FreeAllSignersResolvedInfo(sri);
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: Get all signer's resolved info failed\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 21],
                [core::ffi::c_char; 21],
            >(*b"GetAppSingerCertType\0"))
                .as_ptr(),
            456 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    let mut ret: int32_t = GetAppCertTypeBySignInfo(
        &mut *((*sri).signers).offset(0 as core::ffi::c_int as isize),
        certType,
    );
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: get cert type by sign info failed: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 21],
                [core::ffi::c_char; 21],
            >(*b"GetAppSingerCertType\0"))
                .as_ptr(),
            461 as core::ffi::c_int,
            ret,
        );
        PKCS7_FreeAllSignersResolvedInfo(sri);
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    PKCS7_FreeAllSignersResolvedInfo(sri);
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn GetProfileSingerCertType(
    mut pkcs7Handle: *mut Pkcs7,
    mut certType: *mut int32_t,
) -> int32_t {
    let mut sri: *mut SignersResovedInfo = PKCS7_GetAllSignersResolvedInfo(pkcs7Handle);
    if sri.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: Get all signer's resolved info failed\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 25],
                [core::ffi::c_char; 25],
            >(*b"GetProfileSingerCertType\0"))
                .as_ptr(),
            474 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    let mut ret: int32_t = GetProfileCertTypeBySignInfo(
        &mut *((*sri).signers).offset(0 as core::ffi::c_int as isize),
        certType,
    );
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: get cert type by sign info failed: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 25],
                [core::ffi::c_char; 25],
            >(*b"GetProfileSingerCertType\0"))
                .as_ptr(),
            479 as core::ffi::c_int,
            ret,
        );
        PKCS7_FreeAllSignersResolvedInfo(sri);
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    PKCS7_FreeAllSignersResolvedInfo(sri);
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn VerifyProfileSignGetRaw(
    mut buf: *const core::ffi::c_char,
    mut len: int32_t,
    mut profileContent: *mut *mut core::ffi::c_char,
    mut contentLen: *mut int32_t,
) -> int32_t {
    let mut profileData: *mut core::ffi::c_char = 0 as *mut core::ffi::c_char;
    let mut certType: int32_t = 0;
    let mut input: *mut core::ffi::c_uchar = 0 as *mut core::ffi::c_uchar;
    let mut inputLen: size_t = 0;
    let mut pkcs7: *mut Pkcs7 = malloc(::core::mem::size_of::<Pkcs7>() as size_t)
        as *mut Pkcs7;
    if pkcs7.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: pkcs7 is null\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 24],
                [core::ffi::c_char; 24],
            >(*b"VerifyProfileSignGetRaw\0"))
                .as_ptr(),
            496 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    let mut ret: int32_t = PKCS7_ParseSignedData(
        buf as *mut core::ffi::c_uchar,
        len as size_t,
        pkcs7,
    );
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: ret not ok\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 24],
                [core::ffi::c_char; 24],
            >(*b"VerifyProfileSignGetRaw\0"))
                .as_ptr(),
            499 as core::ffi::c_int,
        );
    } else {
        HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: pkcs7 parse message success\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 24],
                [core::ffi::c_char; 24],
            >(*b"VerifyProfileSignGetRaw\0"))
                .as_ptr(),
            501 as core::ffi::c_int,
        );
        ret = PKCS7_VerifyCertsChain(pkcs7);
        if ret != V_OK as core::ffi::c_int {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xd001100 as core::ffi::c_uint,
                b"appverify\0" as *const u8 as *const core::ffi::c_char,
                b"[%s:%d]: ret not ok\0" as *const u8 as *const core::ffi::c_char,
                (::core::mem::transmute::<
                    [u8; 24],
                    [core::ffi::c_char; 24],
                >(*b"VerifyProfileSignGetRaw\0"))
                    .as_ptr(),
                505 as core::ffi::c_int,
            );
        } else {
            HiLogPrint(
                LOG_CORE,
                LOG_INFO,
                0xd001100 as core::ffi::c_uint,
                b"appverify\0" as *const u8 as *const core::ffi::c_char,
                b"[%s:%d]: Verify certs success\0" as *const u8
                    as *const core::ffi::c_char,
                (::core::mem::transmute::<
                    [u8; 24],
                    [core::ffi::c_char; 24],
                >(*b"VerifyProfileSignGetRaw\0"))
                    .as_ptr(),
                507 as core::ffi::c_int,
            );
            ret = GetProfileSingerCertType(pkcs7, &mut certType);
            if ret != V_OK as core::ffi::c_int {
                HiLogPrint(
                    LOG_CORE,
                    LOG_ERROR,
                    0xd001100 as core::ffi::c_uint,
                    b"appverify\0" as *const u8 as *const core::ffi::c_char,
                    b"[%s:%d]: ret not ok\0" as *const u8 as *const core::ffi::c_char,
                    (::core::mem::transmute::<
                        [u8; 24],
                        [core::ffi::c_char; 24],
                    >(*b"VerifyProfileSignGetRaw\0"))
                        .as_ptr(),
                    510 as core::ffi::c_int,
                );
            } else if certType == 2 as core::ffi::c_int {
                HiLogPrint(
                    LOG_CORE,
                    LOG_ERROR,
                    0xd001100 as core::ffi::c_uint,
                    b"appverify\0" as *const u8 as *const core::ffi::c_char,
                    b"[%s:%d]: cert type invalid\0" as *const u8
                        as *const core::ffi::c_char,
                    (::core::mem::transmute::<
                        [u8; 24],
                        [core::ffi::c_char; 24],
                    >(*b"VerifyProfileSignGetRaw\0"))
                        .as_ptr(),
                    513 as core::ffi::c_int,
                );
                ret = V_ERR as core::ffi::c_uint as int32_t;
            } else {
                ret = PKCS7_VerifySignerSignature(
                    pkcs7,
                    Some(
                        CalcDigest
                            as unsafe extern "C" fn(
                                *const Pkcs7,
                                *const SignerInfo,
                                mbedtls_md_type_t,
                                *mut core::ffi::c_uchar,
                                *mut size_t,
                            ) -> int32_t,
                    ),
                );
                if ret != V_OK as core::ffi::c_int {
                    HiLogPrint(
                        LOG_CORE,
                        LOG_ERROR,
                        0xd001100 as core::ffi::c_uint,
                        b"appverify\0" as *const u8 as *const core::ffi::c_char,
                        b"[%s:%d]: ret not ok\0" as *const u8
                            as *const core::ffi::c_char,
                        (::core::mem::transmute::<
                            [u8; 24],
                            [core::ffi::c_char; 24],
                        >(*b"VerifyProfileSignGetRaw\0"))
                            .as_ptr(),
                        518 as core::ffi::c_int,
                    );
                } else {
                    HiLogPrint(
                        LOG_CORE,
                        LOG_INFO,
                        0xd001100 as core::ffi::c_uint,
                        b"appverify\0" as *const u8 as *const core::ffi::c_char,
                        b"[%s:%d]: verify profile ok\0" as *const u8
                            as *const core::ffi::c_char,
                        (::core::mem::transmute::<
                            [u8; 24],
                            [core::ffi::c_char; 24],
                        >(*b"VerifyProfileSignGetRaw\0"))
                            .as_ptr(),
                        519 as core::ffi::c_int,
                    );
                    ret = PKCS7_GetContentData(pkcs7, &mut input, &mut inputLen);
                    if ret != V_OK as core::ffi::c_int {
                        HiLogPrint(
                            LOG_CORE,
                            LOG_ERROR,
                            0xd001100 as core::ffi::c_uint,
                            b"appverify\0" as *const u8 as *const core::ffi::c_char,
                            b"[%s:%d]: ret not ok\0" as *const u8
                                as *const core::ffi::c_char,
                            (::core::mem::transmute::<
                                [u8; 24],
                                [core::ffi::c_char; 24],
                            >(*b"VerifyProfileSignGetRaw\0"))
                                .as_ptr(),
                            523 as core::ffi::c_int,
                        );
                    } else {
                        HiLogPrint(
                            LOG_CORE,
                            LOG_INFO,
                            0xd001100 as core::ffi::c_uint,
                            b"appverify\0" as *const u8 as *const core::ffi::c_char,
                            b"[%s:%d]: get profile sign content ok\0" as *const u8
                                as *const core::ffi::c_char,
                            (::core::mem::transmute::<
                                [u8; 24],
                                [core::ffi::c_char; 24],
                            >(*b"VerifyProfileSignGetRaw\0"))
                                .as_ptr(),
                            525 as core::ffi::c_int,
                        );
                        if inputLen
                            > (1024 as core::ffi::c_int * 1024 as core::ffi::c_int)
                                as core::ffi::c_uint || inputLen == 0 as core::ffi::c_uint
                        {
                            ret = V_ERR as core::ffi::c_uint as int32_t;
                        } else {
                            profileData = malloc(
                                (inputLen as size_t).wrapping_add(1 as size_t),
                            ) as *mut core::ffi::c_char;
                            if profileData.is_null() {
                                HiLogPrint(
                                    LOG_CORE,
                                    LOG_ERROR,
                                    0xd001100 as core::ffi::c_uint,
                                    b"appverify\0" as *const u8 as *const core::ffi::c_char,
                                    b"[%s:%d]: profileData is null\0" as *const u8
                                        as *const core::ffi::c_char,
                                    (::core::mem::transmute::<
                                        [u8; 24],
                                        [core::ffi::c_char; 24],
                                    >(*b"VerifyProfileSignGetRaw\0"))
                                        .as_ptr(),
                                    532 as core::ffi::c_int,
                                );
                            } else {
                                ret = memcpy_s(
                                    profileData as *mut core::ffi::c_void,
                                    inputLen,
                                    input as *const core::ffi::c_void,
                                    inputLen,
                                ) as int32_t;
                                *profileData.offset(inputLen as isize) = '\0' as i32
                                    as core::ffi::c_char;
                                if ret != V_OK as core::ffi::c_int {
                                    HiLogPrint(
                                        LOG_CORE,
                                        LOG_ERROR,
                                        0xd001100 as core::ffi::c_uint,
                                        b"appverify\0" as *const u8 as *const core::ffi::c_char,
                                        b"[%s:%d]: ret not ok\0" as *const u8
                                            as *const core::ffi::c_char,
                                        (::core::mem::transmute::<
                                            [u8; 24],
                                            [core::ffi::c_char; 24],
                                        >(*b"VerifyProfileSignGetRaw\0"))
                                            .as_ptr(),
                                        536 as core::ffi::c_int,
                                    );
                                } else {
                                    PKCS7_FreeRes(pkcs7);
                                    if !pkcs7.is_null() {
                                        free(pkcs7 as *mut core::ffi::c_void);
                                        pkcs7 = 0 as *mut Pkcs7;
                                    }
                                    *profileContent = profileData;
                                    *contentLen = inputLen as core::ffi::c_int as int32_t;
                                    HiLogPrint(
                                        LOG_CORE,
                                        LOG_INFO,
                                        0xd001100 as core::ffi::c_uint,
                                        b"appverify\0" as *const u8 as *const core::ffi::c_char,
                                        b"[%s:%d]: verify profile get raw data ok\0" as *const u8
                                            as *const core::ffi::c_char,
                                        (::core::mem::transmute::<
                                            [u8; 24],
                                            [core::ffi::c_char; 24],
                                        >(*b"VerifyProfileSignGetRaw\0"))
                                            .as_ptr(),
                                        542 as core::ffi::c_int,
                                    );
                                    return V_OK as core::ffi::c_int as int32_t;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    PKCS7_FreeRes(pkcs7);
    if !pkcs7.is_null() {
        free(pkcs7 as *mut core::ffi::c_void);
        pkcs7 = 0 as *mut Pkcs7;
    }
    if !profileData.is_null() {
        free(profileData as *mut core::ffi::c_void);
        profileData = 0 as *mut core::ffi::c_char;
    }
    return V_ERR as core::ffi::c_uint as int32_t;
}
pub unsafe extern "C" fn GetRsaPk(
    mut pk: *const mbedtls_pk_context,
    mut len: *mut int32_t,
) -> *mut core::ffi::c_uchar {
    let mut buf: *mut core::ffi::c_uchar = malloc(
        (1024 as core::ffi::c_int * 2 as core::ffi::c_int + 20 as core::ffi::c_int)
            as size_t,
    ) as *mut core::ffi::c_uchar;
    if buf.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: malloc error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetRsaPk\0"))
                .as_ptr(),
            554 as core::ffi::c_int,
        );
        return 0 as *mut core::ffi::c_uchar;
    }
    let mut ret: int32_t = memset_s(
        buf as *mut core::ffi::c_void,
        (1024 as core::ffi::c_int * 2 as core::ffi::c_int + 20 as core::ffi::c_int)
            as size_t,
        0 as core::ffi::c_int,
        (1024 as core::ffi::c_int * 2 as core::ffi::c_int + 20 as core::ffi::c_int)
            as size_t,
    ) as int32_t;
    if ret != 0 as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: memset error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetRsaPk\0"))
                .as_ptr(),
            559 as core::ffi::c_int,
        );
        if !buf.is_null() {
            free(buf as *mut core::ffi::c_void);
            buf = 0 as *mut core::ffi::c_uchar;
        }
        return 0 as *mut core::ffi::c_uchar;
    }
    let mut c: *mut core::ffi::c_uchar = buf
        .offset(
            (1024 as core::ffi::c_int * 2 as core::ffi::c_int + 20 as core::ffi::c_int)
                as isize,
        );
    let mut pkLen: int32_t = mbedtls_pk_write_pubkey(&mut c, buf, pk) as int32_t;
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: GetRsaPk pkLen %d\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetRsaPk\0"))
            .as_ptr(),
        565 as core::ffi::c_int,
        pkLen,
    );
    if pkLen < 0 as core::ffi::c_int
        || pkLen
            > 1024 as core::ffi::c_int * 2 as core::ffi::c_int + 20 as core::ffi::c_int
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: get pk buf error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetRsaPk\0"))
                .as_ptr(),
            567 as core::ffi::c_int,
        );
        memset_s(
            buf as *mut core::ffi::c_void,
            (1024 as core::ffi::c_int * 2 as core::ffi::c_int + 20 as core::ffi::c_int)
                as size_t,
            0 as core::ffi::c_int,
            (1024 as core::ffi::c_int * 2 as core::ffi::c_int + 20 as core::ffi::c_int)
                as size_t,
        );
        if !buf.is_null() {
            free(buf as *mut core::ffi::c_void);
            buf = 0 as *mut core::ffi::c_uchar;
        }
        return 0 as *mut core::ffi::c_uchar;
    }
    let mut pkBuf: *mut core::ffi::c_uchar = malloc(pkLen as size_t)
        as *mut core::ffi::c_uchar;
    if pkBuf.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: malloc error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetRsaPk\0"))
                .as_ptr(),
            574 as core::ffi::c_int,
        );
        memset_s(
            buf as *mut core::ffi::c_void,
            (1024 as core::ffi::c_int * 2 as core::ffi::c_int + 20 as core::ffi::c_int)
                as size_t,
            0 as core::ffi::c_int,
            (1024 as core::ffi::c_int * 2 as core::ffi::c_int + 20 as core::ffi::c_int)
                as size_t,
        );
        if !buf.is_null() {
            free(buf as *mut core::ffi::c_void);
            buf = 0 as *mut core::ffi::c_uchar;
        }
        return 0 as *mut core::ffi::c_uchar;
    }
    ret = memcpy_s(
        pkBuf as *mut core::ffi::c_void,
        pkLen as size_t,
        c as *const core::ffi::c_void,
        pkLen as size_t,
    ) as int32_t;
    if ret != 0 as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: mem copy error: %d\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetRsaPk\0"))
                .as_ptr(),
            581 as core::ffi::c_int,
            ret,
        );
        memset_s(
            buf as *mut core::ffi::c_void,
            (1024 as core::ffi::c_int * 2 as core::ffi::c_int + 20 as core::ffi::c_int)
                as size_t,
            0 as core::ffi::c_int,
            (1024 as core::ffi::c_int * 2 as core::ffi::c_int + 20 as core::ffi::c_int)
                as size_t,
        );
        if !buf.is_null() {
            free(buf as *mut core::ffi::c_void);
            buf = 0 as *mut core::ffi::c_uchar;
        }
        if !pkBuf.is_null() {
            free(pkBuf as *mut core::ffi::c_void);
            pkBuf = 0 as *mut core::ffi::c_uchar;
        }
        return 0 as *mut core::ffi::c_uchar;
    }
    *len = pkLen;
    memset_s(
        buf as *mut core::ffi::c_void,
        (1024 as core::ffi::c_int * 2 as core::ffi::c_int + 20 as core::ffi::c_int)
            as size_t,
        0 as core::ffi::c_int,
        (1024 as core::ffi::c_int * 2 as core::ffi::c_int + 20 as core::ffi::c_int)
            as size_t,
    );
    if !buf.is_null() {
        free(buf as *mut core::ffi::c_void);
        buf = 0 as *mut core::ffi::c_uchar;
    }
    return pkBuf;
}
pub unsafe extern "C" fn GetEcPk(
    mut pk: *const mbedtls_pk_context,
    mut len: *mut int32_t,
) -> *mut core::ffi::c_uchar {
    let mut ecCtx: *mut mbedtls_ecp_keypair = mbedtls_pk_ec(*pk);
    if ecCtx.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: get ec pk error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"GetEcPk\0"))
                .as_ptr(),
            597 as core::ffi::c_int,
        );
        return 0 as *mut core::ffi::c_uchar;
    }
    let mut buf: *mut core::ffi::c_uchar = malloc(
        (2 as core::ffi::c_int
            * ((521 as core::ffi::c_int + 7 as core::ffi::c_int) / 8 as core::ffi::c_int)
            + 1 as core::ffi::c_int) as size_t,
    ) as *mut core::ffi::c_uchar;
    if buf.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: malloc error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"GetEcPk\0"))
                .as_ptr(),
            602 as core::ffi::c_int,
        );
        return 0 as *mut core::ffi::c_uchar;
    }
    let mut ret: int32_t = memset_s(
        buf as *mut core::ffi::c_void,
        (2 as core::ffi::c_int
            * ((521 as core::ffi::c_int + 7 as core::ffi::c_int) / 8 as core::ffi::c_int)
            + 1 as core::ffi::c_int) as size_t,
        0 as core::ffi::c_int,
        (2 as core::ffi::c_int
            * ((521 as core::ffi::c_int + 7 as core::ffi::c_int) / 8 as core::ffi::c_int)
            + 1 as core::ffi::c_int) as size_t,
    ) as int32_t;
    if ret != 0 as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: memset error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"GetEcPk\0"))
                .as_ptr(),
            607 as core::ffi::c_int,
        );
        if !buf.is_null() {
            free(buf as *mut core::ffi::c_void);
            buf = 0 as *mut core::ffi::c_uchar;
        }
        return 0 as *mut core::ffi::c_uchar;
    }
    ret = mbedtls_ecp_point_write_binary(
        &mut (*ecCtx).private_grp,
        &mut (*ecCtx).private_Q,
        0 as core::ffi::c_int,
        len as *mut size_t,
        buf,
        (2 as core::ffi::c_int
            * ((521 as core::ffi::c_int + 7 as core::ffi::c_int) / 8 as core::ffi::c_int)
            + 1 as core::ffi::c_int) as size_t,
    ) as int32_t;
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: get ecc pk key error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"GetEcPk\0"))
                .as_ptr(),
            614 as core::ffi::c_int,
        );
        memset_s(
            buf as *mut core::ffi::c_void,
            (2 as core::ffi::c_int
                * ((521 as core::ffi::c_int + 7 as core::ffi::c_int)
                    / 8 as core::ffi::c_int) + 1 as core::ffi::c_int) as size_t,
            0 as core::ffi::c_int,
            (2 as core::ffi::c_int
                * ((521 as core::ffi::c_int + 7 as core::ffi::c_int)
                    / 8 as core::ffi::c_int) + 1 as core::ffi::c_int) as size_t,
        );
        if !buf.is_null() {
            free(buf as *mut core::ffi::c_void);
            buf = 0 as *mut core::ffi::c_uchar;
        }
        return 0 as *mut core::ffi::c_uchar;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: GetEcPk *len %d\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"GetEcPk\0"))
            .as_ptr(),
        619 as core::ffi::c_int,
        *len,
    );
    if *len <= 0 as core::ffi::c_int
        || *len
            > 2 as core::ffi::c_int
                * ((521 as core::ffi::c_int + 7 as core::ffi::c_int)
                    / 8 as core::ffi::c_int) + 1 as core::ffi::c_int
    {
        if !buf.is_null() {
            free(buf as *mut core::ffi::c_void);
            buf = 0 as *mut core::ffi::c_uchar;
        }
        return 0 as *mut core::ffi::c_uchar;
    }
    let mut pkBuf: *mut core::ffi::c_uchar = malloc(*len as size_t)
        as *mut core::ffi::c_uchar;
    if pkBuf.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: malloc error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"GetEcPk\0"))
                .as_ptr(),
            626 as core::ffi::c_int,
        );
        memset_s(
            buf as *mut core::ffi::c_void,
            (2 as core::ffi::c_int
                * ((521 as core::ffi::c_int + 7 as core::ffi::c_int)
                    / 8 as core::ffi::c_int) + 1 as core::ffi::c_int) as size_t,
            0 as core::ffi::c_int,
            (2 as core::ffi::c_int
                * ((521 as core::ffi::c_int + 7 as core::ffi::c_int)
                    / 8 as core::ffi::c_int) + 1 as core::ffi::c_int) as size_t,
        );
        if !buf.is_null() {
            free(buf as *mut core::ffi::c_void);
            buf = 0 as *mut core::ffi::c_uchar;
        }
        return 0 as *mut core::ffi::c_uchar;
    }
    ret = memcpy_s(
        pkBuf as *mut core::ffi::c_void,
        *len as size_t,
        buf as *const core::ffi::c_void,
        *len as size_t,
    ) as int32_t;
    if ret != 0 as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: mem copy error: %d\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"GetEcPk\0"))
                .as_ptr(),
            633 as core::ffi::c_int,
            ret,
        );
        memset_s(
            buf as *mut core::ffi::c_void,
            (2 as core::ffi::c_int
                * ((521 as core::ffi::c_int + 7 as core::ffi::c_int)
                    / 8 as core::ffi::c_int) + 1 as core::ffi::c_int) as size_t,
            0 as core::ffi::c_int,
            (2 as core::ffi::c_int
                * ((521 as core::ffi::c_int + 7 as core::ffi::c_int)
                    / 8 as core::ffi::c_int) + 1 as core::ffi::c_int) as size_t,
        );
        if !buf.is_null() {
            free(buf as *mut core::ffi::c_void);
            buf = 0 as *mut core::ffi::c_uchar;
        }
        if !pkBuf.is_null() {
            free(pkBuf as *mut core::ffi::c_void);
            pkBuf = 0 as *mut core::ffi::c_uchar;
        }
        return 0 as *mut core::ffi::c_uchar;
    }
    if !buf.is_null() {
        free(buf as *mut core::ffi::c_void);
        buf = 0 as *mut core::ffi::c_uchar;
    }
    return pkBuf;
}
pub unsafe extern "C" fn GetPkBuf(
    mut pk: *const mbedtls_pk_context,
    mut len: *mut int32_t,
) -> *mut core::ffi::c_uchar {
    let mut bufA: *mut core::ffi::c_uchar = 0 as *mut core::ffi::c_uchar;
    if mbedtls_pk_get_type(pk) as core::ffi::c_uint
        == MBEDTLS_PK_RSA as core::ffi::c_int as core::ffi::c_uint
        || mbedtls_pk_get_type(pk) as core::ffi::c_uint
            == MBEDTLS_PK_RSASSA_PSS as core::ffi::c_int as core::ffi::c_uint
    {
        bufA = GetRsaPk(pk, len);
    } else if mbedtls_pk_get_type(pk) as core::ffi::c_uint
        == MBEDTLS_PK_ECDSA as core::ffi::c_int as core::ffi::c_uint
        || mbedtls_pk_get_type(pk) as core::ffi::c_uint
            == MBEDTLS_PK_ECKEY as core::ffi::c_int as core::ffi::c_uint
    {
        bufA = GetEcPk(pk, len);
    }
    return bufA;
}
pub unsafe extern "C" fn ParseCertGetPk(
    mut certEncoded: *const core::ffi::c_char,
    mut pk: *mut AppSignPk,
) -> int32_t {
    let mut cert: *mut mbedtls_x509_crt = malloc(
        ::core::mem::size_of::<mbedtls_x509_crt>() as size_t,
    ) as *mut mbedtls_x509_crt;
    if cert.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: cert is null\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 15],
                [core::ffi::c_char; 15],
            >(*b"ParseCertGetPk\0"))
                .as_ptr(),
            657 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    mbedtls_x509_crt_init(cert);
    let mut ret: int32_t = mbedtls_x509_crt_parse(
        cert,
        certEncoded as *mut core::ffi::c_uchar,
        (strlen(certEncoded)).wrapping_add(1 as size_t),
    ) as int32_t;
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: load cert failed, ret: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 15],
                [core::ffi::c_char; 15],
            >(*b"ParseCertGetPk\0"))
                .as_ptr(),
            662 as core::ffi::c_int,
            ret,
        );
        if !cert.is_null() {
            free(cert as *mut core::ffi::c_void);
            cert = 0 as *mut mbedtls_x509_crt;
        }
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    let mut len: int32_t = 0 as int32_t;
    let mut pkBuf: *mut core::ffi::c_uchar = GetPkBuf(&mut (*cert).pk, &mut len);
    if pkBuf.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: get pk error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 15],
                [core::ffi::c_char; 15],
            >(*b"ParseCertGetPk\0"))
                .as_ptr(),
            669 as core::ffi::c_int,
        );
        mbedtls_x509_crt_free(cert);
        if !cert.is_null() {
            free(cert as *mut core::ffi::c_void);
            cert = 0 as *mut mbedtls_x509_crt;
        }
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    (*pk).pk = pkBuf as *mut core::ffi::c_char;
    (*pk).len = len;
    mbedtls_x509_crt_free(cert);
    if !cert.is_null() {
        free(cert as *mut core::ffi::c_void);
        cert = 0 as *mut mbedtls_x509_crt;
    }
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn GetAppSignPublicKey(
    mut profile: *const ProfileProf,
    mut pk: *mut AppSignPk,
) -> int32_t {
    let mut ret: int32_t = 0;
    if !((*profile).bundleInfo.releaseCert).is_null()
        && strlen((*profile).bundleInfo.releaseCert as *mut core::ffi::c_char)
            != 0 as core::ffi::c_uint
    {
        ret = ParseCertGetPk(
            (*profile).bundleInfo.releaseCert as *mut core::ffi::c_char,
            pk,
        );
    } else {
        ret = ParseCertGetPk(
            (*profile).bundleInfo.devCert as *mut core::ffi::c_char,
            pk,
        );
    }
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: GetSignCertpk failed, ret: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 20],
                [core::ffi::c_char; 20],
            >(*b"GetAppSignPublicKey\0"))
                .as_ptr(),
            692 as core::ffi::c_int,
            ret,
        );
        return V_ERR_GET_CERT_PK as core::ffi::c_uint as int32_t;
    }
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn FreeAppSignPublicKey(mut pk: *mut AppSignPk) {
    if !((*pk).pk).is_null() {
        if !((*pk).pk).is_null() {
            free((*pk).pk as *mut core::ffi::c_void);
            (*pk).pk = 0 as *mut core::ffi::c_char;
        }
    }
}
pub unsafe extern "C" fn GetAppid(mut profile: *mut ProfileProf) -> int32_t {
    if profile.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: profile is null\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetAppid\0"))
                .as_ptr(),
            708 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    let mut pk: AppSignPk = {
        let mut init = AppSignPk {
            pk: 0 as *mut core::ffi::c_char,
            len: 0,
        };
        init
    };
    let mut ret: int32_t = GetAppSignPublicKey(profile, &mut pk);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: get sign pk failed\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetAppid\0"))
                .as_ptr(),
            712 as core::ffi::c_int,
        );
        return ret;
    }
    let mut useLen: size_t = 0 as size_t;
    mbedtls_base64_encode(
        0 as *mut core::ffi::c_uchar,
        0 as size_t,
        &mut useLen,
        pk.pk as *mut core::ffi::c_uchar,
        pk.len as size_t,
    );
    let mut bundleNameLen: int32_t = strlen((*profile).bundleInfo.bundleName) as int32_t;
    let mut appidLen: int32_t = (bundleNameLen as core::ffi::c_uint)
        .wrapping_add(useLen as core::ffi::c_uint)
        .wrapping_add(1 as core::ffi::c_uint)
        .wrapping_add(1 as core::ffi::c_uint) as int32_t;
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: GetAppid %d\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetAppid\0"))
            .as_ptr(),
        721 as core::ffi::c_int,
        appidLen,
    );
    if useLen > 4096 as core::ffi::c_uint {
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    let mut appid: *mut core::ffi::c_char = malloc(appidLen as size_t)
        as *mut core::ffi::c_char;
    if appid.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: malloc failed\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetAppid\0"))
                .as_ptr(),
            727 as core::ffi::c_int,
        );
        FreeAppSignPublicKey(&mut pk);
        return V_ERR_MALLOC as core::ffi::c_uint as int32_t;
    }
    *appid.offset((appidLen as core::ffi::c_int - 1 as core::ffi::c_int) as isize) = '\0'
        as i32 as core::ffi::c_char;
    ret = snprintf_s(
        appid,
        appidLen as size_t,
        (bundleNameLen as core::ffi::c_int + 1 as core::ffi::c_int) as size_t,
        b"%s_\0" as *const u8 as *const core::ffi::c_char,
        (*profile).bundleInfo.bundleName,
    ) as int32_t;
    if ret < 0 as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: snprintf error ret: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetAppid\0"))
                .as_ptr(),
            734 as core::ffi::c_int,
            ret,
        );
        if !appid.is_null() {
            free(appid as *mut core::ffi::c_void);
            appid = 0 as *mut core::ffi::c_char;
        }
        FreeAppSignPublicKey(&mut pk);
        return V_ERR_GET_APPID as core::ffi::c_uint as int32_t;
    }
    ret = mbedtls_base64_encode(
        (appid as *mut core::ffi::c_uchar)
            .offset(bundleNameLen as isize)
            .offset(1 as core::ffi::c_int as isize),
        (appidLen as core::ffi::c_int - bundleNameLen as core::ffi::c_int
            - 1 as core::ffi::c_int) as size_t,
        &mut useLen,
        pk.pk as *mut core::ffi::c_uchar,
        pk.len as size_t,
    ) as int32_t;
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: base 64 encode error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetAppid\0"))
                .as_ptr(),
            742 as core::ffi::c_int,
        );
        if !appid.is_null() {
            free(appid as *mut core::ffi::c_void);
            appid = 0 as *mut core::ffi::c_char;
        }
        FreeAppSignPublicKey(&mut pk);
        return V_ERR_GET_APPID as core::ffi::c_uint as int32_t;
    }
    (*profile).appid = appid;
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: appid len: %d, bL len: %d, base64: %d\0" as *const u8
            as *const core::ffi::c_char,
        (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetAppid\0"))
            .as_ptr(),
        748 as core::ffi::c_int,
        appidLen,
        bundleNameLen,
        useLen as core::ffi::c_int,
    );
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: %s\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<[u8; 9], [core::ffi::c_char; 9]>(*b"GetAppid\0"))
            .as_ptr(),
        749 as core::ffi::c_int,
        appid,
    );
    FreeAppSignPublicKey(&mut pk);
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn VerifyProfGetContent(
    mut fp: int32_t,
    mut signInfo: *const SignatureInfo,
    mut certType: int32_t,
    mut pf: *mut ProfileProf,
) -> int32_t {
    let mut profBuf: *mut core::ffi::c_char = 0 as *mut core::ffi::c_char;
    let mut len: int32_t = 0 as int32_t;
    let mut blockHead: BlockHead = {
        let mut init = BlockHead {
            type_0: 0 as uint32_t,
            length: 0,
            offset: 0,
        };
        init
    };
    let mut ret: int32_t = 0;
    let mut rawLen: int32_t = 0 as int32_t;
    let mut rawBuf: *mut core::ffi::c_char = GetSignBlockByType(
        signInfo,
        fp,
        PROFILE_BLOCK_WITHSIGN_TYPE as core::ffi::c_int as int32_t,
        &mut rawLen,
        &mut blockHead,
    );
    if rawBuf.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: rawBuf is null\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 21],
                [core::ffi::c_char; 21],
            >(*b"VerifyProfGetContent\0"))
                .as_ptr(),
            762 as core::ffi::c_int,
        );
        return V_ERR_GET_PROFILE_DATA as core::ffi::c_uint as int32_t;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: certType %d\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 21],
            [core::ffi::c_char; 21],
        >(*b"VerifyProfGetContent\0"))
            .as_ptr(),
        763 as core::ffi::c_int,
        certType,
    );
    if certType == 0 as core::ffi::c_int {
        profBuf = rawBuf;
        len = rawLen;
    } else {
        ret = VerifyProfileSignGetRaw(rawBuf, rawLen, &mut profBuf, &mut len);
        if !rawBuf.is_null() {
            free(rawBuf as *mut core::ffi::c_void);
            rawBuf = 0 as *mut core::ffi::c_char;
        }
        if ret != V_OK as core::ffi::c_int {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xd001100 as core::ffi::c_uint,
                b"appverify\0" as *const u8 as *const core::ffi::c_char,
                b"[%s:%d]: ret not ok\0" as *const u8 as *const core::ffi::c_char,
                (::core::mem::transmute::<
                    [u8; 21],
                    [core::ffi::c_char; 21],
                >(*b"VerifyProfGetContent\0"))
                    .as_ptr(),
                772 as core::ffi::c_int,
            );
            return ret;
        }
    }
    ret = ParseProfile(profBuf, len, pf);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: GetSignBlock error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 21],
                [core::ffi::c_char; 21],
            >(*b"VerifyProfGetContent\0"))
                .as_ptr(),
            777 as core::ffi::c_int,
        );
        if !profBuf.is_null() {
            free(profBuf as *mut core::ffi::c_void);
            profBuf = 0 as *mut core::ffi::c_char;
        }
        return V_ERR_GET_PARSE_PROFILE as core::ffi::c_uint as int32_t;
    }
    if !profBuf.is_null() {
        free(profBuf as *mut core::ffi::c_void);
        profBuf = 0 as *mut core::ffi::c_char;
    }
    ret = VerifyProfileContent(pf);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: ret not ok\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 21],
                [core::ffi::c_char; 21],
            >(*b"VerifyProfGetContent\0"))
                .as_ptr(),
            784 as core::ffi::c_int,
        );
    } else {
        ret = GetAppid(pf);
        if ret != V_OK as core::ffi::c_int {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xd001100 as core::ffi::c_uint,
                b"appverify\0" as *const u8 as *const core::ffi::c_char,
                b"[%s:%d]: ret not ok\0" as *const u8 as *const core::ffi::c_char,
                (::core::mem::transmute::<
                    [u8; 21],
                    [core::ffi::c_char; 21],
                >(*b"VerifyProfGetContent\0"))
                    .as_ptr(),
                787 as core::ffi::c_int,
            );
        } else {
            return V_OK as core::ffi::c_int as int32_t
        }
    }
    ProfFreeData(pf);
    return ret;
}
pub unsafe extern "C" fn CmpCert(
    mut certA: *const mbedtls_x509_crt,
    mut binSignCert: *const CertInfo,
) -> int32_t {
    if certA.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: certA is null\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"CmpCert\0"))
                .as_ptr(),
            797 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    if binSignCert.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: binSignCert is null\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"CmpCert\0"))
                .as_ptr(),
            798 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    if (*certA).subject_raw.len != (*binSignCert).subjectLen as core::ffi::c_uint
        || memcmp(
            (*certA).subject_raw.p as *const core::ffi::c_void,
            (*binSignCert).subject as *const core::ffi::c_void,
            (*certA).subject_raw.len,
        ) != 0
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: cert subject diff\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"CmpCert\0"))
                .as_ptr(),
            802 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    if (*certA).issuer_raw.len != (*binSignCert).issuerLen as core::ffi::c_uint
        || memcmp(
            (*certA).issuer_raw.p as *const core::ffi::c_void,
            (*binSignCert).issuer as *const core::ffi::c_void,
            (*certA).issuer_raw.len,
        ) != 0
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: cert issuer diff\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"CmpCert\0"))
                .as_ptr(),
            808 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    if mbedtls_pk_get_type(&(*certA).pk) as core::ffi::c_uint
        != (*binSignCert).pkType as core::ffi::c_uint
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: pk type diff\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"CmpCert\0"))
                .as_ptr(),
            814 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    let mut lenA: int32_t = 0 as int32_t;
    let mut bufA: *mut core::ffi::c_uchar = GetPkBuf(&(*certA).pk, &mut lenA);
    if bufA.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: bufA is null\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"CmpCert\0"))
                .as_ptr(),
            819 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    if lenA != (*binSignCert).pkLen {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: pkA len diff %d, %d\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"CmpCert\0"))
                .as_ptr(),
            822 as core::ffi::c_int,
            lenA,
            (*binSignCert).pkLen,
        );
        if !bufA.is_null() {
            free(bufA as *mut core::ffi::c_void);
            bufA = 0 as *mut core::ffi::c_uchar;
        }
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    if memcmp(
        bufA as *const core::ffi::c_void,
        (*binSignCert).pkBuf as *const core::ffi::c_void,
        lenA as size_t,
    ) != 0
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: pk content different\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"CmpCert\0"))
                .as_ptr(),
            828 as core::ffi::c_int,
        );
        if !bufA.is_null() {
            free(bufA as *mut core::ffi::c_void);
            bufA = 0 as *mut core::ffi::c_uchar;
        }
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    if !bufA.is_null() {
        free(bufA as *mut core::ffi::c_void);
        bufA = 0 as *mut core::ffi::c_uchar;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: compare cert consistent\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<[u8; 8], [core::ffi::c_char; 8]>(*b"CmpCert\0"))
            .as_ptr(),
        833 as core::ffi::c_int,
    );
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn LoadCertAndCmpDest(
    mut certBase64: *const core::ffi::c_uchar,
    mut binSignCert: *const CertInfo,
) -> int32_t {
    if certBase64.is_null() || binSignCert.is_null() {
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    let mut cert: mbedtls_x509_crt = mbedtls_x509_crt {
        private_own_buffer: 0,
        raw: mbedtls_x509_buf {
            tag: 0,
            len: 0,
            p: 0 as *mut core::ffi::c_uchar,
        },
        tbs: mbedtls_x509_buf {
            tag: 0,
            len: 0,
            p: 0 as *mut core::ffi::c_uchar,
        },
        version: 0,
        serial: mbedtls_x509_buf {
            tag: 0,
            len: 0,
            p: 0 as *mut core::ffi::c_uchar,
        },
        sig_oid: mbedtls_x509_buf {
            tag: 0,
            len: 0,
            p: 0 as *mut core::ffi::c_uchar,
        },
        issuer_raw: mbedtls_x509_buf {
            tag: 0,
            len: 0,
            p: 0 as *mut core::ffi::c_uchar,
        },
        subject_raw: mbedtls_x509_buf {
            tag: 0,
            len: 0,
            p: 0 as *mut core::ffi::c_uchar,
        },
        issuer: mbedtls_x509_name {
            oid: mbedtls_x509_buf {
                tag: 0,
                len: 0,
                p: 0 as *mut core::ffi::c_uchar,
            },
            val: mbedtls_x509_buf {
                tag: 0,
                len: 0,
                p: 0 as *mut core::ffi::c_uchar,
            },
            next: 0 as *mut mbedtls_asn1_named_data,
            private_next_merged: 0,
        },
        subject: mbedtls_x509_name {
            oid: mbedtls_x509_buf {
                tag: 0,
                len: 0,
                p: 0 as *mut core::ffi::c_uchar,
            },
            val: mbedtls_x509_buf {
                tag: 0,
                len: 0,
                p: 0 as *mut core::ffi::c_uchar,
            },
            next: 0 as *mut mbedtls_asn1_named_data,
            private_next_merged: 0,
        },
        valid_from: mbedtls_x509_time {
            year: 0,
            mon: 0,
            day: 0,
            hour: 0,
            min: 0,
            sec: 0,
        },
        valid_to: mbedtls_x509_time {
            year: 0,
            mon: 0,
            day: 0,
            hour: 0,
            min: 0,
            sec: 0,
        },
        pk_raw: mbedtls_x509_buf {
            tag: 0,
            len: 0,
            p: 0 as *mut core::ffi::c_uchar,
        },
        pk: mbedtls_pk_context {
            private_pk_info: 0 as *const mbedtls_pk_info_t,
            private_pk_ctx: 0 as *mut core::ffi::c_void,
        },
        issuer_id: mbedtls_x509_buf {
            tag: 0,
            len: 0,
            p: 0 as *mut core::ffi::c_uchar,
        },
        subject_id: mbedtls_x509_buf {
            tag: 0,
            len: 0,
            p: 0 as *mut core::ffi::c_uchar,
        },
        v3_ext: mbedtls_x509_buf {
            tag: 0,
            len: 0,
            p: 0 as *mut core::ffi::c_uchar,
        },
        subject_alt_names: mbedtls_x509_sequence {
            buf: mbedtls_x509_buf {
                tag: 0,
                len: 0,
                p: 0 as *mut core::ffi::c_uchar,
            },
            next: 0 as *mut mbedtls_asn1_sequence,
        },
        subject_key_id: mbedtls_x509_buf {
            tag: 0,
            len: 0,
            p: 0 as *mut core::ffi::c_uchar,
        },
        authority_key_id: mbedtls_x509_authority {
            keyIdentifier: mbedtls_x509_buf {
                tag: 0,
                len: 0,
                p: 0 as *mut core::ffi::c_uchar,
            },
            authorityCertIssuer: mbedtls_x509_sequence {
                buf: mbedtls_x509_buf {
                    tag: 0,
                    len: 0,
                    p: 0 as *mut core::ffi::c_uchar,
                },
                next: 0 as *mut mbedtls_asn1_sequence,
            },
            authorityCertSerialNumber: mbedtls_x509_buf {
                tag: 0,
                len: 0,
                p: 0 as *mut core::ffi::c_uchar,
            },
            raw: mbedtls_x509_buf {
                tag: 0,
                len: 0,
                p: 0 as *mut core::ffi::c_uchar,
            },
        },
        certificate_policies: mbedtls_x509_sequence {
            buf: mbedtls_x509_buf {
                tag: 0,
                len: 0,
                p: 0 as *mut core::ffi::c_uchar,
            },
            next: 0 as *mut mbedtls_asn1_sequence,
        },
        private_ext_types: 0,
        private_ca_istrue: 0,
        private_max_pathlen: 0,
        private_key_usage: 0,
        ext_key_usage: mbedtls_x509_sequence {
            buf: mbedtls_x509_buf {
                tag: 0,
                len: 0,
                p: 0 as *mut core::ffi::c_uchar,
            },
            next: 0 as *mut mbedtls_asn1_sequence,
        },
        private_ns_cert_type: 0,
        private_sig: mbedtls_x509_buf {
            tag: 0,
            len: 0,
            p: 0 as *mut core::ffi::c_uchar,
        },
        private_sig_md: MBEDTLS_MD_NONE,
        private_sig_pk: MBEDTLS_PK_NONE,
        private_sig_opts: 0 as *mut core::ffi::c_void,
        next: 0 as *mut mbedtls_x509_crt,
    };
    mbedtls_x509_crt_init(&mut cert);
    let mut ret: int32_t = mbedtls_x509_crt_parse(
        &mut cert,
        certBase64,
        (strlen(certBase64 as *mut core::ffi::c_char)).wrapping_add(1 as size_t),
    ) as int32_t;
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: load release cert failed\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 19],
                [core::ffi::c_char; 19],
            >(*b"LoadCertAndCmpDest\0"))
                .as_ptr(),
            846 as core::ffi::c_int,
        );
        HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: %s\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 19],
                [core::ffi::c_char; 19],
            >(*b"LoadCertAndCmpDest\0"))
                .as_ptr(),
            847 as core::ffi::c_int,
            certBase64,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    if CmpCert(&mut cert, binSignCert) == V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: cert consistent\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 19],
                [core::ffi::c_char; 19],
            >(*b"LoadCertAndCmpDest\0"))
                .as_ptr(),
            852 as core::ffi::c_int,
        );
        mbedtls_x509_crt_free(&mut cert);
        return V_OK as core::ffi::c_int as int32_t;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_ERROR,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: cert inconsistent\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 19],
            [core::ffi::c_char; 19],
        >(*b"LoadCertAndCmpDest\0"))
            .as_ptr(),
        856 as core::ffi::c_int,
    );
    mbedtls_x509_crt_free(&mut cert);
    return V_ERR as core::ffi::c_uint as int32_t;
}
pub unsafe extern "C" fn CheckReleaseAppSign(
    mut binSignCert: *const CertInfo,
    mut pf: *const ProfileProf,
) -> int32_t {
    if strcmp(
        (*pf).appDistType,
        b"app_gallery\0" as *const u8 as *const core::ffi::c_char,
    ) == 0 as core::ffi::c_int
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: app release, distribution type is app_gallery, return error\0"
                as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 20],
                [core::ffi::c_char; 20],
            >(*b"CheckReleaseAppSign\0"))
                .as_ptr(),
            865 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    if strlen((*pf).bundleInfo.releaseCert as *mut core::ffi::c_char)
        == 0 as core::ffi::c_uint
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: release app, release Cert null\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 20],
                [core::ffi::c_char; 20],
            >(*b"CheckReleaseAppSign\0"))
                .as_ptr(),
            870 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    let mut ret: int32_t = LoadCertAndCmpDest((*pf).bundleInfo.releaseCert, binSignCert);
    if ret == V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: dev cert consistent\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 20],
                [core::ffi::c_char; 20],
            >(*b"CheckReleaseAppSign\0"))
                .as_ptr(),
            875 as core::ffi::c_int,
        );
        return V_OK as core::ffi::c_int as int32_t;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_ERROR,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: app sign cert not consistent with profile cert\0" as *const u8
            as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 20],
            [core::ffi::c_char; 20],
        >(*b"CheckReleaseAppSign\0"))
            .as_ptr(),
        878 as core::ffi::c_int,
    );
    return V_ERR as core::ffi::c_uint as int32_t;
}
pub unsafe extern "C" fn CheckDebugAppSign(
    mut binSignCert: *mut CertInfo,
    mut pf: *const ProfileProf,
) -> int32_t {
    if strlen((*pf).bundleInfo.devCert as *mut core::ffi::c_char)
        == 0 as core::ffi::c_uint
    {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: debug app, devCert null\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 18],
                [core::ffi::c_char; 18],
            >(*b"CheckDebugAppSign\0"))
                .as_ptr(),
            885 as core::ffi::c_int,
        );
        return V_ERR as core::ffi::c_uint as int32_t;
    }
    let mut ret: int32_t = LoadCertAndCmpDest((*pf).bundleInfo.devCert, binSignCert);
    if ret == V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: dev cert consistent\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 18],
                [core::ffi::c_char; 18],
            >(*b"CheckDebugAppSign\0"))
                .as_ptr(),
            890 as core::ffi::c_int,
        );
        return V_OK as core::ffi::c_int as int32_t;
    }
    if strlen((*pf).bundleInfo.releaseCert as *mut core::ffi::c_char)
        != 0 as core::ffi::c_uint
    {
        ret = LoadCertAndCmpDest((*pf).bundleInfo.releaseCert, binSignCert);
        if ret == V_OK as core::ffi::c_int {
            HiLogPrint(
                LOG_CORE,
                LOG_INFO,
                0xd001100 as core::ffi::c_uint,
                b"appverify\0" as *const u8 as *const core::ffi::c_char,
                b"[%s:%d]: release cert consistent\0" as *const u8
                    as *const core::ffi::c_char,
                (::core::mem::transmute::<
                    [u8; 18],
                    [core::ffi::c_char; 18],
                >(*b"CheckDebugAppSign\0"))
                    .as_ptr(),
                896 as core::ffi::c_int,
            );
            return V_OK as core::ffi::c_int as int32_t;
        }
    }
    HiLogPrint(
        LOG_CORE,
        LOG_ERROR,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: app sign cert not consistent with profile cert\0" as *const u8
            as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 18],
            [core::ffi::c_char; 18],
        >(*b"CheckDebugAppSign\0"))
            .as_ptr(),
        900 as core::ffi::c_int,
    );
    return V_ERR as core::ffi::c_uint as int32_t;
}
pub unsafe extern "C" fn CheckAppSignCertWithProfile(
    mut appCertType: int32_t,
    mut binSignCert: *mut CertInfo,
    mut pf: *mut ProfileProf,
) -> int32_t {
    if appCertType == 0 as core::ffi::c_int || appCertType == 1 as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: app type : %d, return OK\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 28],
                [core::ffi::c_char; 28],
            >(*b"CheckAppSignCertWithProfile\0"))
                .as_ptr(),
            908 as core::ffi::c_int,
            appCertType,
        );
        return V_OK as core::ffi::c_int as int32_t;
    }
    let mut ret: int32_t = V_ERR as core::ffi::c_uint as int32_t;
    if strcmp(b"debug\0" as *const u8 as *const core::ffi::c_char, (*pf).type_0)
        == 0 as core::ffi::c_int
    {
        ret = CheckDebugAppSign(binSignCert, pf);
    } else if strcmp(b"release\0" as *const u8 as *const core::ffi::c_char, (*pf).type_0)
        == 0 as core::ffi::c_int
    {
        ret = CheckReleaseAppSign(binSignCert, pf);
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: check app sign cert ret : %d\0" as *const u8
            as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 28],
            [core::ffi::c_char; 28],
        >(*b"CheckAppSignCertWithProfile\0"))
            .as_ptr(),
        920 as core::ffi::c_int,
        ret,
    );
    return ret;
}
pub unsafe extern "C" fn CertInfoInit(mut certInfo: *mut CertInfo) -> int32_t {
    let mut ret: int32_t = memset_s(
        certInfo as *mut core::ffi::c_void,
        ::core::mem::size_of::<CertInfo>() as size_t,
        0 as core::ffi::c_int,
        ::core::mem::size_of::<CertInfo>() as size_t,
    ) as int32_t;
    if ret != 0 as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: memset error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 13],
                [core::ffi::c_char; 13],
            >(*b"CertInfoInit\0"))
                .as_ptr(),
            928 as core::ffi::c_int,
        );
    }
    return ret;
}
pub unsafe extern "C" fn FreeCertInfo(mut certInfo: *mut CertInfo) {
    if certInfo.is_null() {
        return;
    }
    if !((*certInfo).issuer).is_null() {
        if !((*certInfo).issuer).is_null() {
            free((*certInfo).issuer as *mut core::ffi::c_void);
            (*certInfo).issuer = 0 as *mut core::ffi::c_char;
        }
        (*certInfo).issuerLen = 0 as core::ffi::c_int as int32_t;
    }
    if !((*certInfo).subject).is_null() {
        if !((*certInfo).subject).is_null() {
            free((*certInfo).subject as *mut core::ffi::c_void);
            (*certInfo).subject = 0 as *mut core::ffi::c_char;
        }
        (*certInfo).subjectLen = 0 as core::ffi::c_int as int32_t;
    }
    if !((*certInfo).pkBuf).is_null() {
        if !((*certInfo).pkBuf).is_null() {
            free((*certInfo).pkBuf as *mut core::ffi::c_void);
            (*certInfo).pkBuf = 0 as *mut core::ffi::c_char;
        }
        (*certInfo).pkLen = 0 as core::ffi::c_int as int32_t;
    }
}
pub unsafe extern "C" fn GetCertInfo(
    mut ctr: *const mbedtls_x509_crt,
    mut binSignCert: *mut *mut CertInfo,
) -> int32_t {
    let mut certInfo: *mut CertInfo = malloc(
        ::core::mem::size_of::<CertInfo>() as size_t,
    ) as *mut CertInfo;
    if certInfo.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: certInfo is null\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 12],
                [core::ffi::c_char; 12],
            >(*b"GetCertInfo\0"))
                .as_ptr(),
            958 as core::ffi::c_int,
        );
        return V_ERR_MALLOC as core::ffi::c_uint as int32_t;
    }
    let mut ret: int32_t = CertInfoInit(certInfo);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: cert info init\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 12],
                [core::ffi::c_char; 12],
            >(*b"GetCertInfo\0"))
                .as_ptr(),
            962 as core::ffi::c_int,
        );
        ret = V_ERR_MEMSET as core::ffi::c_uint as int32_t;
    } else {
        (*certInfo).issuerLen = (*ctr).issuer_raw.len as int32_t;
        (*certInfo).subjectLen = (*ctr).subject_raw.len as int32_t;
        if (*certInfo).issuerLen == 0 as core::ffi::c_int
            || (*certInfo).issuerLen
                > 1024 as core::ffi::c_int * 1024 as core::ffi::c_int
            || (*certInfo).subjectLen == 0 as core::ffi::c_int
            || (*certInfo).subjectLen
                > 1024 as core::ffi::c_int * 1024 as core::ffi::c_int
        {
            ret = V_ERR_MALLOC as core::ffi::c_uint as int32_t;
        } else {
            (*certInfo).issuer = malloc(
                ((*certInfo).issuerLen as core::ffi::c_int + 1 as core::ffi::c_int)
                    as size_t,
            ) as *mut core::ffi::c_char;
            if ((*certInfo).issuer).is_null() {
                ret = V_ERR_MALLOC as core::ffi::c_uint as int32_t;
            } else {
                *((*certInfo).issuer).offset((*certInfo).issuerLen as isize) = '\0'
                    as i32 as core::ffi::c_char;
                ret = memcpy_s(
                    (*certInfo).issuer as *mut core::ffi::c_void,
                    (*certInfo).issuerLen as size_t,
                    (*ctr).issuer_raw.p as *const core::ffi::c_void,
                    (*ctr).issuer_raw.len,
                ) as int32_t;
                if ret != 0 as core::ffi::c_int {
                    ret = V_ERR_MEMCPY as core::ffi::c_uint as int32_t;
                } else {
                    (*certInfo).subject = malloc(
                        ((*certInfo).subjectLen as core::ffi::c_int
                            + 1 as core::ffi::c_int) as size_t,
                    ) as *mut core::ffi::c_char;
                    if ((*certInfo).subject).is_null() {
                        ret = V_ERR_MALLOC as core::ffi::c_uint as int32_t;
                    } else {
                        *((*certInfo).subject).offset((*certInfo).subjectLen as isize) = '\0'
                            as i32 as core::ffi::c_char;
                        ret = memcpy_s(
                            (*certInfo).subject as *mut core::ffi::c_void,
                            (*certInfo).subjectLen as size_t,
                            (*ctr).subject_raw.p as *const core::ffi::c_void,
                            (*ctr).subject_raw.len,
                        ) as int32_t;
                        if ret != 0 as core::ffi::c_int {
                            ret = V_ERR_MEMCPY as core::ffi::c_uint as int32_t;
                        } else {
                            (*certInfo).pkType = mbedtls_pk_get_type(&(*ctr).pk);
                            (*certInfo).pkBuf = GetPkBuf(
                                &(*ctr).pk,
                                &mut (*certInfo).pkLen,
                            ) as *mut core::ffi::c_char;
                            if ((*certInfo).pkBuf).is_null() {
                                HiLogPrint(
                                    LOG_CORE,
                                    LOG_ERROR,
                                    0xd001100 as core::ffi::c_uint,
                                    b"appverify\0" as *const u8 as *const core::ffi::c_char,
                                    b"[%s:%d]: get pk error\0" as *const u8
                                        as *const core::ffi::c_char,
                                    (::core::mem::transmute::<
                                        [u8; 12],
                                        [core::ffi::c_char; 12],
                                    >(*b"GetCertInfo\0"))
                                        .as_ptr(),
                                    998 as core::ffi::c_int,
                                );
                                ret = V_ERR as core::ffi::c_uint as int32_t;
                            } else {
                                *binSignCert = certInfo;
                                return V_OK as core::ffi::c_int as int32_t;
                            }
                        }
                    }
                }
            }
        }
    }
    FreeCertInfo(certInfo);
    if !certInfo.is_null() {
        free(certInfo as *mut core::ffi::c_void);
        certInfo = 0 as *mut CertInfo;
    }
    return ret;
}
pub unsafe extern "C" fn VerfiyAppSourceGetProfile(
    mut fp: int32_t,
    mut signInfo: *const SignatureInfo,
    mut certType: int32_t,
    mut binSignCert: *mut CertInfo,
    mut pf: *mut ProfileProf,
) -> int32_t {
    let mut ret: int32_t = VerifyProfGetContent(fp, signInfo, certType, pf);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: VerifyProfGetContent error: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 26],
                [core::ffi::c_char; 26],
            >(*b"VerfiyAppSourceGetProfile\0"))
                .as_ptr(),
            1015 as core::ffi::c_int,
            ret,
        );
        return ret;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: verify prof get content success\0" as *const u8
            as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 26],
            [core::ffi::c_char; 26],
        >(*b"VerfiyAppSourceGetProfile\0"))
            .as_ptr(),
        1018 as core::ffi::c_int,
    );
    ret = CheckAppSignCertWithProfile(certType, binSignCert, pf);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: CheckAppSignCertWithProfile error: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 26],
                [core::ffi::c_char; 26],
            >(*b"VerfiyAppSourceGetProfile\0"))
                .as_ptr(),
            1023 as core::ffi::c_int,
            ret,
        );
        ProfFreeData(pf);
        return V_ERR_VERFIY_PROF_CERT as core::ffi::c_uint as int32_t;
    }
    if !((*pf).bundleInfo.devCert).is_null() {
        free((*pf).bundleInfo.devCert as *mut core::ffi::c_void);
        (*pf).bundleInfo.devCert = 0 as *mut core::ffi::c_uchar;
    }
    if !((*pf).bundleInfo.releaseCert).is_null() {
        free((*pf).bundleInfo.releaseCert as *mut core::ffi::c_void);
        (*pf).bundleInfo.releaseCert = 0 as *mut core::ffi::c_uchar;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: verfiy app source success\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 26],
            [core::ffi::c_char; 26],
        >(*b"VerfiyAppSourceGetProfile\0"))
            .as_ptr(),
        1032 as core::ffi::c_int,
    );
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn VerifyAppSignPkcsData(
    mut fileRead: *const FileRead,
    mut signInfo: *const SignatureInfo,
    mut pkcs7Handle: *const Pkcs7,
) -> int32_t {
    let mut ret: int32_t = PKCS7_VerifyCertsChain(pkcs7Handle);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: Verify certs failed, ret: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 22],
                [core::ffi::c_char; 22],
            >(*b"VerifyAppSignPkcsData\0"))
                .as_ptr(),
            1041 as core::ffi::c_int,
            ret,
        );
        return V_ERR_VERIFY_CERT_CHAIN as core::ffi::c_uint as int32_t;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: Verify certs success\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 22],
            [core::ffi::c_char; 22],
        >(*b"VerifyAppSignPkcsData\0"))
            .as_ptr(),
        1044 as core::ffi::c_int,
    );
    ret = VerifyRawHash(signInfo, fileRead, pkcs7Handle);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: VerifyRawHash failed : %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 22],
                [core::ffi::c_char; 22],
            >(*b"VerifyAppSignPkcsData\0"))
                .as_ptr(),
            1048 as core::ffi::c_int,
            ret,
        );
        return ret;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: VerifyRawHash success\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 22],
            [core::ffi::c_char; 22],
        >(*b"VerifyAppSignPkcsData\0"))
            .as_ptr(),
        1051 as core::ffi::c_int,
    );
    ret = PKCS7_VerifySignerSignature(
        pkcs7Handle,
        Some(
            CalcDigest
                as unsafe extern "C" fn(
                    *const Pkcs7,
                    *const SignerInfo,
                    mbedtls_md_type_t,
                    *mut core::ffi::c_uchar,
                    *mut size_t,
                ) -> int32_t,
        ),
    );
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: pkcs7 verify signer signature failed : %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 22],
                [core::ffi::c_char; 22],
            >(*b"VerifyAppSignPkcsData\0"))
                .as_ptr(),
            1055 as core::ffi::c_int,
            ret,
        );
        return V_ERR_VERIFY_SIGNATURE as core::ffi::c_uint as int32_t;
    }
    return V_OK as core::ffi::c_int as int32_t;
}
#[inline]
pub unsafe extern "C" fn mbedtls_pk_ec(pk: mbedtls_pk_context) -> *mut mbedtls_ecp_keypair {
    match mbedtls_pk_get_type(&pk) as core::ffi::c_uint {
        2 | 3 | 4 => return pk.private_pk_ctx as *mut mbedtls_ecp_keypair,
        _ => return 0 as *mut mbedtls_ecp_keypair,
    };
}
pub unsafe extern "C" fn GetBinSignPkcs(
    mut signBuf: *const core::ffi::c_char,
    mut len: int32_t,
) -> *mut Pkcs7 {
    let mut pkcs7: *mut Pkcs7 = malloc(::core::mem::size_of::<Pkcs7>() as size_t)
        as *mut Pkcs7;
    if pkcs7.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: malloc error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 15],
                [core::ffi::c_char; 15],
            >(*b"GetBinSignPkcs\0"))
                .as_ptr(),
            1066 as core::ffi::c_int,
        );
        return 0 as *mut Pkcs7;
    }
    let mut ret: int32_t = PKCS7_ParseSignedData(
        signBuf as *mut core::ffi::c_uchar,
        len as size_t,
        pkcs7,
    );
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: pkcs7parse message failed, ret: %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 15],
                [core::ffi::c_char; 15],
            >(*b"GetBinSignPkcs\0"))
                .as_ptr(),
            1071 as core::ffi::c_int,
            ret,
        );
        PKCS7_FreeRes(pkcs7);
        if !pkcs7.is_null() {
            free(pkcs7 as *mut core::ffi::c_void);
            pkcs7 = 0 as *mut Pkcs7;
        }
        return 0 as *mut Pkcs7;
    }
    return pkcs7;
}
pub unsafe extern "C" fn GetFileRead(
    mut fp: int32_t,
    mut offset: int32_t,
    mut size: int32_t,
) -> *mut FileRead {
    let mut fileRead: *mut FileRead = malloc(
        ::core::mem::size_of::<FileRead>() as size_t,
    ) as *mut FileRead;
    if fileRead.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: malloc error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 12],
                [core::ffi::c_char; 12],
            >(*b"GetFileRead\0"))
                .as_ptr(),
            1084 as core::ffi::c_int,
        );
        return 0 as *mut FileRead;
    }
    (*fileRead).fp = fp;
    (*fileRead).offset = offset;
    (*fileRead).len = size;
    return fileRead;
}
pub unsafe extern "C" fn VerifyBinSign(
    mut signInfo: *mut SignatureInfo,
    mut fp: int32_t,
    mut signCert: *mut *mut CertInfo,
    mut certType: *mut int32_t,
) -> int32_t {
    let mut blockLen: int32_t = 0;
    let mut blockHead: BlockHead = {
        let mut init = BlockHead {
            type_0: 0 as uint32_t,
            length: 0,
            offset: 0,
        };
        init
    };
    let mut fileRead: *mut FileRead = 0 as *mut FileRead;
    let mut ret: int32_t = 0;
    let mut signBuf: *mut core::ffi::c_char = GetSignBlockByType(
        signInfo,
        fp,
        SIGNATURE_BLOCK_TYPE as core::ffi::c_int as int32_t,
        &mut blockLen,
        &mut blockHead,
    );
    if signBuf.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: signBuf is null\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 14],
                [core::ffi::c_char; 14],
            >(*b"VerifyBinSign\0"))
                .as_ptr(),
            1100 as core::ffi::c_int,
        );
        return V_ERR_GET_SIGN_BLOCK as core::ffi::c_uint as int32_t;
    }
    let mut pkcs7: *mut Pkcs7 = GetBinSignPkcs(signBuf, blockLen as size_t as int32_t);
    if pkcs7.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: GetBinSignPkcs failed\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 14],
                [core::ffi::c_char; 14],
            >(*b"VerifyBinSign\0"))
                .as_ptr(),
            1104 as core::ffi::c_int,
        );
        if !signBuf.is_null() {
            free(signBuf as *mut core::ffi::c_void);
            signBuf = 0 as *mut core::ffi::c_char;
        }
        return V_ERR_PARSE_PKC7_DATA as core::ffi::c_uint as int32_t;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: pkcs7 parse message success\0" as *const u8
            as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 14],
            [core::ffi::c_char; 14],
        >(*b"VerifyBinSign\0"))
            .as_ptr(),
        1109 as core::ffi::c_int,
    );
    fileRead = GetFileRead(fp, 0 as int32_t, blockHead.offset as int32_t);
    if fileRead.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: malloc error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 14],
                [core::ffi::c_char; 14],
            >(*b"VerifyBinSign\0"))
                .as_ptr(),
            1114 as core::ffi::c_int,
        );
        ret = V_ERR_MALLOC as core::ffi::c_uint as int32_t;
    } else {
        ret = GetAppSingerCertType(pkcs7, certType);
        if ret != V_OK as core::ffi::c_int {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xd001100 as core::ffi::c_uint,
                b"appverify\0" as *const u8 as *const core::ffi::c_char,
                b"[%s:%d]: cert source invalid: %d\0" as *const u8
                    as *const core::ffi::c_char,
                (::core::mem::transmute::<
                    [u8; 14],
                    [core::ffi::c_char; 14],
                >(*b"VerifyBinSign\0"))
                    .as_ptr(),
                1120 as core::ffi::c_int,
                ret,
            );
            ret = V_ERR_GET_CERT_TYPE as core::ffi::c_uint as int32_t;
        } else {
            HiLogPrint(
                LOG_CORE,
                LOG_INFO,
                0xd001100 as core::ffi::c_uint,
                b"appverify\0" as *const u8 as *const core::ffi::c_char,
                b"[%s:%d]: get cert Type : %d\0" as *const u8
                    as *const core::ffi::c_char,
                (::core::mem::transmute::<
                    [u8; 14],
                    [core::ffi::c_char; 14],
                >(*b"VerifyBinSign\0"))
                    .as_ptr(),
                1124 as core::ffi::c_int,
                *certType,
            );
            (*signInfo).certType = *certType;
            ret = VerifyAppSignPkcsData(fileRead, signInfo, pkcs7);
            if ret != V_OK as core::ffi::c_int {
                HiLogPrint(
                    LOG_CORE,
                    LOG_ERROR,
                    0xd001100 as core::ffi::c_uint,
                    b"appverify\0" as *const u8 as *const core::ffi::c_char,
                    b"[%s:%d]: intergrity failed\0" as *const u8
                        as *const core::ffi::c_char,
                    (::core::mem::transmute::<
                        [u8; 14],
                        [core::ffi::c_char; 14],
                    >(*b"VerifyBinSign\0"))
                        .as_ptr(),
                    1128 as core::ffi::c_int,
                );
                ret = V_ERR_VERIFY_CERT_CHAIN as core::ffi::c_uint as int32_t;
            } else {
                HiLogPrint(
                    LOG_CORE,
                    LOG_INFO,
                    0xd001100 as core::ffi::c_uint,
                    b"appverify\0" as *const u8 as *const core::ffi::c_char,
                    b"[%s:%d]: pkcs7 verify signer signature success\0" as *const u8
                        as *const core::ffi::c_char,
                    (::core::mem::transmute::<
                        [u8; 14],
                        [core::ffi::c_char; 14],
                    >(*b"VerifyBinSign\0"))
                        .as_ptr(),
                    1132 as core::ffi::c_int,
                );
                ret = GetCertInfo((*pkcs7).signedData.signers.certPath.crt, signCert);
                if ret != V_OK as core::ffi::c_int {
                    HiLogPrint(
                        LOG_CORE,
                        LOG_ERROR,
                        0xd001100 as core::ffi::c_uint,
                        b"appverify\0" as *const u8 as *const core::ffi::c_char,
                        b"[%s:%d]: get bin cert info  error: %d\0" as *const u8
                            as *const core::ffi::c_char,
                        (::core::mem::transmute::<
                            [u8; 14],
                            [core::ffi::c_char; 14],
                        >(*b"VerifyBinSign\0"))
                            .as_ptr(),
                        1136 as core::ffi::c_int,
                        ret,
                    );
                    ret = V_ERR_GET_CERT_INFO as core::ffi::c_uint as int32_t;
                }
            }
        }
    }
    if !signBuf.is_null() {
        free(signBuf as *mut core::ffi::c_void);
        signBuf = 0 as *mut core::ffi::c_char;
    }
    PKCS7_FreeRes(pkcs7);
    if !pkcs7.is_null() {
        free(pkcs7 as *mut core::ffi::c_void);
        pkcs7 = 0 as *mut Pkcs7;
    }
    if !fileRead.is_null() {
        free(fileRead as *mut core::ffi::c_void);
        fileRead = 0 as *mut FileRead;
    }
    return ret;
}
pub unsafe extern "C" fn VerifyIntegrity(
    mut signInfo: *mut SignatureInfo,
    mut fp: int32_t,
    mut pf: *mut ProfileProf,
) -> int32_t {
    let mut binSignCert: *mut CertInfo = 0 as *mut CertInfo;
    let mut certType: int32_t = 0 as int32_t;
    let mut ret: int32_t = VerifyBinSign(signInfo, fp, &mut binSignCert, &mut certType);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: verify bin sign error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 16],
                [core::ffi::c_char; 16],
            >(*b"VerifyIntegrity\0"))
                .as_ptr(),
            1158 as core::ffi::c_int,
        );
        return ret;
    }
    ret = VerfiyAppSourceGetProfile(fp, signInfo, certType, binSignCert, pf);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: verify app source failed : %d\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 16],
                [core::ffi::c_char; 16],
            >(*b"VerifyIntegrity\0"))
                .as_ptr(),
            1164 as core::ffi::c_int,
            ret,
        );
        FreeCertInfo(binSignCert);
        if !binSignCert.is_null() {
            free(binSignCert as *mut core::ffi::c_void);
            binSignCert = 0 as *mut CertInfo;
        }
        return ret;
    }
    FreeCertInfo(binSignCert);
    if !binSignCert.is_null() {
        free(binSignCert as *mut core::ffi::c_void);
        binSignCert = 0 as *mut CertInfo;
    }
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn APPVERI_AppVerify(
    mut filePath: *const core::ffi::c_char,
    mut verifyRst: *mut VerifyResult,
) -> int32_t {
    if filePath.is_null() || verifyRst.is_null() {
        return V_ERR_FILE_OPEN as core::ffi::c_uint as int32_t;
    }
    let mut handle: int32_t = 0 as int32_t;
    let mut file: FileRead = {
        let mut init = FileRead {
            fp: 0 as int32_t,
            offset: 0,
            len: 0,
        };
        init
    };
    if InitVerify(&mut file, filePath, &mut handle) != V_OK as core::ffi::c_int {
        close(handle as core::ffi::c_int);
        return V_ERR_FILE_OPEN as core::ffi::c_uint as int32_t;
    }
    let mut signInfo: SignatureInfo = {
        let mut init = SignatureInfo {
            signHead: 0 as *mut HwSignHead,
            fullSignBlockOffset: 0,
            hapCoreDirOffset: 0,
            hapEocdOffset: 0,
            hapEocdSize: 0,
            fileSize: 0,
            version: 0,
            certType: 0,
        };
        init
    };
    let mut ret: int32_t = GetSignHead(&mut file, &mut signInfo);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: get sign head error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 18],
                [core::ffi::c_char; 18],
            >(*b"APPVERI_AppVerify\0"))
                .as_ptr(),
            1188 as core::ffi::c_int,
        );
        close(handle as core::ffi::c_int);
        return ret;
    }
    let mut signHead: *mut HwSignHead = signInfo.signHead;
    ret = VerifyIntegrity(&mut signInfo, handle, &mut (*verifyRst).profile);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: verify integrity failed\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 18],
                [core::ffi::c_char; 18],
            >(*b"APPVERI_AppVerify\0"))
                .as_ptr(),
            1195 as core::ffi::c_int,
        );
        close(handle as core::ffi::c_int);
        if !signHead.is_null() {
            free(signHead as *mut core::ffi::c_void);
            signHead = 0 as *mut HwSignHead;
        }
        return ret;
    }
    let mut fileSt: *mut stat = malloc(::core::mem::size_of::<stat>() as size_t)
        as *mut stat;
    if fileSt.is_null() {
        HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: malloc error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 18],
                [core::ffi::c_char; 18],
            >(*b"APPVERI_AppVerify\0"))
                .as_ptr(),
            1202 as core::ffi::c_int,
        );
        close(handle as core::ffi::c_int);
        if !signHead.is_null() {
            free(signHead as *mut core::ffi::c_void);
            signHead = 0 as *mut HwSignHead;
        }
        ProfFreeData(&mut (*verifyRst).profile);
        return V_ERR_MALLOC as core::ffi::c_uint as int32_t;
    }
    ret = fstat(handle as core::ffi::c_int, fileSt) as int32_t;
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: fstat error\0" as *const u8 as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 18],
                [core::ffi::c_char; 18],
            >(*b"APPVERI_AppVerify\0"))
                .as_ptr(),
            1210 as core::ffi::c_int,
        );
        close(handle as core::ffi::c_int);
        if !signHead.is_null() {
            free(signHead as *mut core::ffi::c_void);
            signHead = 0 as *mut HwSignHead;
        }
        ProfFreeData(&mut (*verifyRst).profile);
        if !fileSt.is_null() {
            free(fileSt as *mut core::ffi::c_void);
            fileSt = 0 as *mut stat;
        }
        return V_ERR_FILE_STAT as core::ffi::c_uint as int32_t;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: file len: %d\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 18],
            [core::ffi::c_char; 18],
        >(*b"APPVERI_AppVerify\0"))
            .as_ptr(),
        1217 as core::ffi::c_int,
        (*fileSt).st_size as core::ffi::c_int,
    );
    close(handle as core::ffi::c_int);
    if !signHead.is_null() {
        free(signHead as *mut core::ffi::c_void);
        signHead = 0 as *mut HwSignHead;
    }
    if !fileSt.is_null() {
        free(fileSt as *mut core::ffi::c_void);
        fileSt = 0 as *mut stat;
    }
    return ret;
}
pub unsafe extern "C" fn APPVERI_SetDebugMode(mut mode: bool) -> int32_t {
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: set debug mode: %d\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 21],
            [core::ffi::c_char; 21],
        >(*b"APPVERI_SetDebugMode\0"))
            .as_ptr(),
        1227 as core::ffi::c_int,
        mode as core::ffi::c_int,
    );
    if g_isDebugMode as core::ffi::c_int == mode as core::ffi::c_int {
        return V_OK as core::ffi::c_int as int32_t;
    }
    let mut ret: int32_t = PKCS7_EnableDebugMode(mode);
    if ret != V_OK as core::ffi::c_int {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xd001100 as core::ffi::c_uint,
            b"appverify\0" as *const u8 as *const core::ffi::c_char,
            b"[%s:%d]: enable pcks7 debug mode failed\0" as *const u8
                as *const core::ffi::c_char,
            (::core::mem::transmute::<
                [u8; 21],
                [core::ffi::c_char; 21],
            >(*b"APPVERI_SetDebugMode\0"))
                .as_ptr(),
            1233 as core::ffi::c_int,
        );
        return ret;
    }
    g_isDebugMode = mode;
    return V_OK as core::ffi::c_int as int32_t;
}
pub unsafe extern "C" fn APPVERI_SetActsMode(mut mode: bool) {
    g_isActsMode = mode;
}
pub unsafe extern "C" fn APPVERI_IsActsMode() -> int32_t {
    return g_isActsMode as int32_t;
}
pub unsafe extern "C" fn APPVERI_FreeVerifyRst(mut verifyRst: *mut VerifyResult) {
    if verifyRst.is_null() {
        return;
    }
    HiLogPrint(
        LOG_CORE,
        LOG_INFO,
        0xd001100 as core::ffi::c_uint,
        b"appverify\0" as *const u8 as *const core::ffi::c_char,
        b"[%s:%d]: free verify rst data\0" as *const u8 as *const core::ffi::c_char,
        (::core::mem::transmute::<
            [u8; 22],
            [core::ffi::c_char; 22],
        >(*b"APPVERI_FreeVerifyRst\0"))
            .as_ptr(),
        1256 as core::ffi::c_int,
    );
    ProfFreeData(&mut (*verifyRst).profile);
}
