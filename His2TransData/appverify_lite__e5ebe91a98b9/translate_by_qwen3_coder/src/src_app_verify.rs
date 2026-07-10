//! Module: src_app_verify
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

// === C2R_FILE_STATICS_BEGIN ===
// File-scope `static` variables (internal linkage) from the original C TU.
// These are module-local by design (Scheme B).
/// C: static _Bool g_isActsMode
static mut g_isActsMode: bool = false;

/// C: static _Bool g_isDebugMode
static mut g_isDebugMode: bool = false;

/// C: static const TrustAppCert[3] g_trustAppList
static mut g_trustAppList: [crate::types::TrustAppCert; 3usize] = unsafe { core::mem::MaybeUninit::<[crate::types::TrustAppCert; 3usize]>::zeroed().assume_init() };

/// C: static const TrustAppCert[2] g_trustAppListTest
static mut g_trustAppListTest: [crate::types::TrustAppCert; 2usize] = unsafe { core::mem::MaybeUninit::<[crate::types::TrustAppCert; 2usize]>::zeroed().assume_init() };

// === C2R_FILE_STATICS_END ===

fn SignHeadN2H(signHead: *mut crate::types::HwSignHead) {
    unsafe {
        let block_num_ptr = std::ptr::addr_of!((*signHead).blockNum) as *const ::core::ffi::c_uchar;
        (*signHead).blockNum = crate::src_app_common::HapGetInt(
            block_num_ptr,
            std::mem::size_of::<u32>() as i32,
        ) as u32;
        
        let size_ptr = std::ptr::addr_of!((*signHead).size) as *const ::core::ffi::c_uchar;
        (*signHead).size = crate::src_app_common::HapGetInt64(
            size_ptr,
            std::mem::size_of::<::core::ffi::c_ulonglong>() as i32,
        ) as ::core::ffi::c_ulonglong;
        
        let magic_low_ptr = std::ptr::addr_of!((*signHead).magicLow) as *const ::core::ffi::c_uchar;
        (*signHead).magicLow = crate::src_app_common::HapGetInt64(
            magic_low_ptr,
            std::mem::size_of::<::core::ffi::c_ulonglong>() as i32,
        ) as ::core::ffi::c_ulonglong;
        
        let magic_high_ptr = std::ptr::addr_of!((*signHead).magicHigh) as *const ::core::ffi::c_uchar;
        (*signHead).magicHigh = crate::src_app_common::HapGetInt64(
            magic_high_ptr,
            std::mem::size_of::<::core::ffi::c_ulonglong>() as i32,
        ) as ::core::ffi::c_ulonglong;
        
        let version_ptr = std::ptr::addr_of!((*signHead).version) as *const ::core::ffi::c_uchar;
        (*signHead).version = crate::src_app_common::HapGetInt(
            version_ptr,
            std::mem::size_of::<u32>() as i32,
        ) as u32;
    }
}

fn BlockHeadN2H(blockHead: *mut crate::types::BlockHead) {
    unsafe {
        (*blockHead).type_ = crate::src_app_common::HapGetUnsignedInt(
            &(*blockHead).type_ as *const u32 as *const ::core::ffi::c_uchar,
            std::mem::size_of::<u32>() as i32,
        );
        (*blockHead).length = crate::src_app_common::HapGetUnsignedInt(
            &(*blockHead).length as *const u32 as *const ::core::ffi::c_uchar,
            std::mem::size_of::<u32>() as i32,
        );
        (*blockHead).offset = crate::src_app_common::HapGetUnsignedInt(
            &(*blockHead).offset as *const u32 as *const ::core::ffi::c_uchar,
            std::mem::size_of::<u32>() as i32,
        );
    }
}

fn ContentN2H(content: *mut crate::types::ContentInfo) {
    unsafe {
        (*content).blockNum = crate::src_app_common::HapGetInt(
            &(*content).blockNum as *const i32 as *const ::core::ffi::c_uchar,
            std::mem::size_of::<i32>() as i32,
        );
        (*content).size = crate::src_app_common::HapGetInt(
            &(*content).size as *const i32 as *const ::core::ffi::c_uchar,
            std::mem::size_of::<i32>() as i32,
        );
        (*content).algId = crate::src_app_common::HapGetInt(
            &(*content).algId as *const i32 as *const ::core::ffi::c_uchar,
            std::mem::size_of::<i32>() as i32,
        );
        (*content).length = crate::src_app_common::HapGetInt(
            &(*content).length as *const i32 as *const ::core::ffi::c_uchar,
            std::mem::size_of::<i32>() as i32,
        );
    }
}

fn GetSignHead(file: *const crate::types::FileRead, signInfo: *mut crate::types::SignatureInfo) -> i32 {
    unsafe {
        let mut fileSt: crate::compat::stat = std::mem::zeroed();
        let ret = libc::fstat((*file).fp, &mut fileSt as *mut crate::compat::stat as *mut libc::stat);
        if ret != 0 || fileSt.st_size < std::mem::size_of::<crate::types::HwSignHead>() as i64 {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: fstat error, %d, filelen: %d\0".as_ptr() as *const i8,
                b"GetSignHead\0".as_ptr() as *const i8,
                121i32,
                ret,
                fileSt.st_size as i32,
            );
            return crate::types::V_ERR_GET_SIGNHEAD as i32;
        }
        if !crate::src_app_centraldirectory::FindSignature(file, signInfo) {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: find signature error\0".as_ptr() as *const i8,
                b"GetSignHead\0".as_ptr() as *const i8,
                125i32,
            );
            return crate::types::V_ERR_GET_SIGNHEAD as i32;
        }
        if ((*signInfo).hapCoreDirOffset as usize) < std::mem::size_of::<crate::types::HwSignHead>() {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: hapCoreDirOffset error, %d\0".as_ptr() as *const i8,
                b"GetSignHead\0".as_ptr() as *const i8,
                129i32,
                (*signInfo).hapCoreDirOffset,
            );
            return crate::types::V_ERR_GET_SIGNHEAD as i32;
        }
        let seek_offset = (*signInfo).hapCoreDirOffset - std::mem::size_of::<crate::types::HwSignHead>() as i32;
        let ret = libc::lseek((*file).fp, seek_offset as i64, crate::types::SEEK_SET as i32);
        if ret < 0 {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: lseek error, %d\0".as_ptr() as *const i8,
                b"GetSignHead\0".as_ptr() as *const i8,
                134i32,
                ret as i32,
            );
            return crate::types::V_ERR_GET_SIGNHEAD as i32;
        }
        let signHead = libc::malloc(std::mem::size_of::<crate::types::HwSignHead>()) as *mut crate::types::HwSignHead;
        if signHead.is_null() {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: signHead is null\0".as_ptr() as *const i8,
                b"GetSignHead\0".as_ptr() as *const i8,
                138i32,
            );
            return crate::types::V_ERR as i32;
        }
        let readLen = libc::read((*file).fp, signHead as *mut core::ffi::c_void, std::mem::size_of::<crate::types::HwSignHead>()) as i32;
        if readLen != std::mem::size_of::<crate::types::HwSignHead>() as i32 {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: readLen %d, %d\0".as_ptr() as *const i8,
                b"GetSignHead\0".as_ptr() as *const i8,
                141i32,
                readLen,
                std::mem::size_of::<crate::types::HwSignHead>() as i32,
            );
            libc::free(signHead as *mut core::ffi::c_void);
            return crate::types::V_ERR_GET_SIGNHEAD as i32;
        }
        crate::src_app_verify::SignHeadN2H(signHead);
        let mut magicLow: u64 = crate::types::HAP_SIG_BLOCK_MAGIC_LO;
        let mut magicHigh: u64 = crate::types::HAP_SIG_BLOCK_MAGIC_HI;
        if (*signHead).version < crate::types::VERSION_FOR_NEW_MAGIC_NUM {
            magicLow = crate::types::HAP_SIG_BLOCK_MAGIC_LO_OLD;
            magicHigh = crate::types::HAP_SIG_BLOCK_MAGIC_HI_OLD;
        }
        if (*signHead).magicLow != magicLow || (*signHead).magicHigh != magicHigh {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: sign head magic invalid\0".as_ptr() as *const i8,
                b"GetSignHead\0".as_ptr() as *const i8,
                153i32,
            );
            libc::free(signHead as *mut core::ffi::c_void);
            return crate::types::V_ERR_GET_SIGNHEAD as i32;
        }
        crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const i8,
            b"[%s:%d]: sign head: size: %llu, blockNum:0x%x\0".as_ptr() as *const i8,
            b"GetSignHead\0".as_ptr() as *const i8,
            157i32,
            (*signHead).size,
            (*signHead).blockNum,
        );
        (*signInfo).signHead = signHead;
        (*signInfo).fullSignBlockOffset = (*signInfo).hapCoreDirOffset - (*signHead).size as i32;
        (*signInfo).fileSize = fileSt.st_size as i32;
        if (*signInfo).fullSignBlockOffset <= 0 || (*signInfo).fullSignBlockOffset >= (*signInfo).hapCoreDirOffset {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: fullSignBlockOffset invalid\0".as_ptr() as *const i8,
                b"GetSignHead\0".as_ptr() as *const i8,
                162i32,
            );
            libc::free(signHead as *mut core::ffi::c_void);
            return crate::types::V_ERR_GET_SIGNHEAD as i32;
        }
        crate::types::V_OK as i32
    }
}

fn FindBlockHead(signInfo: *const crate::types::SignatureInfo, fp: i32, blockType: i32, block: *mut crate::types::BlockHead) -> i32 {
    unsafe {
        let signH: *mut crate::types::HwSignHead = (*signInfo).signHead;
        
        libc::lseek(fp, (*signInfo).fullSignBlockOffset as libc::off_t, crate::types::SEEK_SET as i32);
        let mut num: i32 = (*signH).blockNum as i32;
        if num > (crate::types::MAX_BLOCK_NUM as i32) {
            return crate::types::V_ERR as i32;
        }
        while {
            let old_num = num;
            num -= 1;
            old_num > 0
        } {
            let readLen: isize = libc::read(fp, block as *mut ::core::ffi::c_void, std::mem::size_of::<crate::types::BlockHead>());
            if readLen != std::mem::size_of::<crate::types::BlockHead>() as isize {
                let _ = crate::compat::HiLogPrint(
                    crate::types::LOG_CORE,
                    crate::types::LOG_ERROR,
                    0xD001100,
                    b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                    b"[%s:%d]: find block head , read err %d, %d\0".as_ptr() as *const ::core::ffi::c_char,
                    b"FindBlockHead\0".as_ptr() as *const ::core::ffi::c_char,
                    181i32,
                    readLen as i32,
                    std::mem::size_of::<crate::types::BlockHead>() as i32,
                );
                return crate::types::V_ERR as i32;
            }
            let type_val: i32 = crate::src_app_common::HapGetInt(
                &(*block).type_ as *const u32 as *const ::core::ffi::c_uchar,
                std::mem::size_of::<u32>() as i32,
            );
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: find block type: %0x\0".as_ptr() as *const ::core::ffi::c_char,
                b"FindBlockHead\0".as_ptr() as *const ::core::ffi::c_char,
                185i32,
                type_val,
            );
            if type_val == blockType {
                crate::src_app_verify::BlockHeadN2H(block);
                return crate::types::V_OK as i32;
            }
        }
        let _ = crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_ERROR,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: get sign block by type failed, type: %d\0".as_ptr() as *const ::core::ffi::c_char,
            b"FindBlockHead\0".as_ptr() as *const ::core::ffi::c_char,
            191i32,
            blockType,
        );
        crate::types::V_ERR as i32
    }
}

pub extern "C" fn GetSignBlockByType(signInfo: *const crate::types::SignatureInfo, fp: i32, blockType: i32, len: *mut i32, blockHead: *mut crate::types::BlockHead) -> *mut ::core::ffi::c_char {
    if signInfo.is_null() || blockHead.is_null() {
        return std::ptr::null_mut();
    }
    
    let ret = FindBlockHead(signInfo, fp, blockType, blockHead);
    if ret != crate::types::V_OK as i32 {
        return std::ptr::null_mut();
    }
    
    unsafe {
        let block_length = (*blockHead).length;
        let sign_info_ref = &*signInfo;
        
        if block_length == 0 || block_length > ((sign_info_ref.hapCoreDirOffset - sign_info_ref.fullSignBlockOffset) as u32) {
            return std::ptr::null_mut();
        }
        
        if (block_length + 1) >= (sign_info_ref.fileSize as u32) {
            return std::ptr::null_mut();
        }
        
        let buf = libc::malloc((block_length + 1) as usize) as *mut ::core::ffi::c_char;
        if buf.is_null() {
            return std::ptr::null_mut();
        }
        
        *buf.offset(block_length as isize) = 0;
        
        let mut fileSt: crate::compat::stat = std::mem::zeroed();
        let fstat_ret = libc::fstat(fp, &mut fileSt as *mut crate::compat::stat as *mut libc::stat);
        
        let required_size = (sign_info_ref.fullSignBlockOffset as i64) + ((*blockHead).offset as i64) + (block_length as i64);
        if (fstat_ret != 0) || (fileSt.st_size < required_size) {
            libc::free(buf as *mut ::core::ffi::c_void);
            return std::ptr::null_mut();
        }
        
        libc::lseek(fp, (sign_info_ref.fullSignBlockOffset + (*blockHead).offset as i32) as libc::off_t, 0);
        
        let readLen = libc::read(fp, buf as *mut ::core::ffi::c_void, block_length as usize) as i32;
        if readLen != block_length as i32 {
            libc::free(buf as *mut ::core::ffi::c_void);
            return std::ptr::null_mut();
        }
        
        *len = readLen;
        
        buf
    }
}

pub extern "C" fn GetHashUnitLen(hashAlg: i32) -> i32 {
    unsafe {
        let _ = crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: algId: %d\0".as_ptr() as *const ::core::ffi::c_char,
            b"GetHashUnitLen\0".as_ptr() as *const ::core::ffi::c_char,
            247i32,
            hashAlg,
        );
        let md_info = crate::compat::mbedtls_md_info_from_type(hashAlg as crate::types::mbedtls_md_type_t);
        crate::compat::mbedtls_md_get_size(md_info) as i32
    }
}

fn CalcCmpContHash(pkcs7: *const crate::types::Pkcs7, signer: *const crate::types::SignerInfo, algType: crate::types::mbedtls_md_type_t, hash: *mut ::core::ffi::c_uchar, hashLen: *mut ::core::ffi::c_uint) -> i32 {
    use crate::types::*;
    use crate::compat::*;
    
    let mut rc: i32;
    let mut input: *mut ::core::ffi::c_uchar = std::ptr::null_mut();
    let mut inputLen: size_t = 0;
    
    rc = crate::src_mbedtls_pkcs7::PKCS7_GetContentData(pkcs7, &mut input, &mut inputLen);
    if rc != V_OK as i32 {
        unsafe {
            HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: rc not ok\0".as_ptr() as *const ::core::ffi::c_char,
                b"CalcCmpContHash\0".as_ptr() as *const ::core::ffi::c_char, 260i32);
        }
        return rc;
    }
    
    rc = unsafe { mbedtls_md(mbedtls_md_info_from_type(algType), input, inputLen as u32, hash) };
    if rc != 0 {
        unsafe {
            HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Error: calc digest failed\0".as_ptr() as *const ::core::ffi::c_char,
                b"CalcCmpContHash\0".as_ptr() as *const ::core::ffi::c_char, 264i32);
        }
        return rc;
    }
    unsafe {
        *hashLen = mbedtls_md_get_size(mbedtls_md_info_from_type(algType)) as ::core::ffi::c_uint;
    }
    
    let mut digInAttr: *mut ::core::ffi::c_uchar = std::ptr::null_mut();
    let mut digInAttrLen: size_t = 0;
    rc = crate::src_mbedtls_pkcs7::PKCS7_GetDigestInSignerAuthAttr(signer, &mut digInAttr, &mut digInAttrLen);
    if rc != V_OK as i32 {
        unsafe {
            HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: PKCS7_GetDigestInSignerAuthAttr error: %d\0".as_ptr() as *const ::core::ffi::c_char,
                b"CalcCmpContHash\0".as_ptr() as *const ::core::ffi::c_char, 274i32, rc);
        }
        return rc;
    }
    
    let hashLenVal = unsafe { *hashLen } as size_t;
    if digInAttrLen != hashLenVal {
        unsafe {
            HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Error: content hash len is not equal with attr's hash len\0".as_ptr() as *const ::core::ffi::c_char,
                b"CalcCmpContHash\0".as_ptr() as *const ::core::ffi::c_char, 278i32);
        }
        return V_ERR as i32;
    }
    
    if unsafe { libc::memcmp(hash as *const ::core::ffi::c_void, digInAttr as *const ::core::ffi::c_void, digInAttrLen as usize) } != 0 {
        unsafe {
            HiLogPrint(LOG_CORE, LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Error: content hash not equal with attr hash\0".as_ptr() as *const ::core::ffi::c_char,
                b"CalcCmpContHash\0".as_ptr() as *const ::core::ffi::c_char, 282i32);
        }
        return V_ERR as i32;
    }
    
    V_OK as i32
}

fn CalcDigest(pkcs7: *const crate::types::Pkcs7, signer: *const crate::types::SignerInfo, algType: crate::types::mbedtls_md_type_t, hash: *mut ::core::ffi::c_uchar, hashLen: *mut ::core::ffi::c_uint) -> i32 {
    let mut rc: i32;
    let mut input: *mut ::core::ffi::c_uchar = std::ptr::null_mut();
    let mut inputLen: crate::types::size_t = 0;

    rc = crate::src_app_verify::CalcCmpContHash(pkcs7, signer, algType, hash, hashLen);
    if rc != crate::types::V_OK as i32 {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Error: content hash not equal with attr hash\0".as_ptr() as *const ::core::ffi::c_char,
                b"CalcDigest\0".as_ptr() as *const ::core::ffi::c_char,
                296 as ::core::ffi::c_int,
            );
        }
        return rc;
    }
    unsafe {
        crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: signer context hash equal with attr hash\0".as_ptr() as *const ::core::ffi::c_char,
            b"CalcDigest\0".as_ptr() as *const ::core::ffi::c_char,
            299 as ::core::ffi::c_int,
        );
    }

    rc = unsafe { crate::src_mbedtls_pkcs7::PKCS7_GetSignerAuthAttr(signer, &mut input, &mut inputLen) };
    if rc != crate::types::V_OK as i32 {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Error: PKCS7_GetSignerAuthAttr failed ret: %d\0".as_ptr() as *const ::core::ffi::c_char,
                b"CalcDigest\0".as_ptr() as *const ::core::ffi::c_char,
                304 as ::core::ffi::c_int,
                rc,
            );
        }
        return rc;
    }

    rc = unsafe {
        crate::compat::mbedtls_md(
            crate::compat::mbedtls_md_info_from_type(algType),
            input,
            inputLen as u32,
            hash,
        )
    };
    if rc != crate::types::V_OK as i32 {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Error: calc digest failed ret: %d\0".as_ptr() as *const ::core::ffi::c_char,
                b"CalcDigest\0".as_ptr() as *const ::core::ffi::c_char,
                309 as ::core::ffi::c_int,
                rc,
            );
        }
        return rc;
    }

    unsafe {
        *hashLen = crate::compat::mbedtls_md_get_size(crate::compat::mbedtls_md_info_from_type(algType)) as ::core::ffi::c_uint;
    }

    crate::types::V_OK as i32
}

fn VerifyRawHash(signInfo: *const crate::types::SignatureInfo, fileRead: *const crate::types::FileRead, pkcs7Handle: *const crate::types::Pkcs7) -> i32 {
    unsafe {
        let mut input: *mut ::core::ffi::c_uchar = std::ptr::null_mut();
        let mut inputLen: crate::types::size_t = 0;

        let ret = crate::src_mbedtls_pkcs7::PKCS7_GetContentData(
            pkcs7Handle,
            &mut input,
            &mut inputLen,
        );
        if ret != crate::types::V_OK as i32 {
            return ret;
        }

        let content = libc::malloc(std::mem::size_of::<crate::types::ContentInfo>()) as *mut crate::types::ContentInfo;
        if content.is_null() {
            return crate::types::V_ERR as i32;
        }

        let ret = crate::compat::memcpy_s(
            content as *mut ::core::ffi::c_void,
            std::mem::size_of::<crate::types::ContentInfo>() as crate::types::size_t,
            input as *const ::core::ffi::c_void,
            inputLen,
        );
        if ret != 0 {
            libc::free(content as *mut ::core::ffi::c_void);
            return ret;
        }

        crate::src_app_verify::ContentN2H(content);
        (*content).algId = crate::src_app_verify_hap::GetDigestAlgorithmId((*content).algId as u32);

        if (*content).algId != crate::types::MBEDTLS_MD_SHA256 as i32
            && (*content).algId != crate::types::MBEDTLS_MD_SHA384 as i32
            && (*content).algId != crate::types::MBEDTLS_MD_SHA512 as i32
        {
            libc::free(content as *mut ::core::ffi::c_void);
            return crate::types::V_ERR as i32;
        }

        let mut actualDigest = crate::types::HapBuf {
            buffer: std::ptr::null_mut(),
            len: 0,
        };
        let rootHashLen = crate::src_app_verify::GetHashUnitLen((*content).algId);

        if !crate::src_app_centraldirectory::CreateHapBuffer(&mut actualDigest, rootHashLen) {
            libc::free(content as *mut ::core::ffi::c_void);
            return crate::types::V_ERR as i32;
        }

        if !crate::src_app_verify_hap::VerifyIntegrityChunk(
            (*content).algId,
            (*fileRead).fp,
            signInfo,
            &actualDigest,
        ) {
            crate::src_app_centraldirectory::ClearHapBuffer(&mut actualDigest);
            libc::free(content as *mut ::core::ffi::c_void);
            return crate::types::V_ERR as i32;
        }

        if actualDigest.len != (*content).length
            || libc::memcmp(
                actualDigest.buffer,
                (*content).hash.as_ptr() as *const ::core::ffi::c_void,
                actualDigest.len as usize,
            ) != 0
        {
            libc::free(content as *mut ::core::ffi::c_void);
            crate::src_app_centraldirectory::ClearHapBuffer(&mut actualDigest);
            return crate::types::V_ERR_GET_HASH_DIFF as i32;
        }

        libc::free(content as *mut ::core::ffi::c_void);
        crate::src_app_centraldirectory::ClearHapBuffer(&mut actualDigest);
        crate::types::V_OK as i32
    }
}

fn GetCertTypeBySourceName(cert: *const crate::types::TrustAppCert) -> i32 {
    if cert.is_null() {
        return crate::types::CERT_TYPE_OTHER as i32;
    }
    
    unsafe {
        let name = (*cert).name;
        
        if libc::strcmp(name, b"huawei app gallary\0".as_ptr() as *const i8) == 0 {
            return crate::types::CERT_TYPE_APPGALLARY as i32;
        } else if libc::strcmp(name, b"huawei system apps\0".as_ptr() as *const i8) == 0 {
            return crate::types::CERT_TYPE_SYETEM as i32;
        } else if libc::strcmp(name, b"OpenHarmony apps\0".as_ptr() as *const i8) == 0 {
            return crate::types::CERT_TYPE_SYETEM as i32;
        } else {
            return crate::types::CERT_TYPE_OTHER as i32;
        }
    }
}

fn GetProfSourceBySigningCert(signer: *const crate::types::SignerResovledInfo, trustList: *const crate::types::TrustAppCert, num: i32) -> *const crate::types::TrustAppCert {
    unsafe {
        for i in 0..num {
            let trust_item = trustList.offset(i as isize);
            if libc::strcmp((*trust_item).issueCA, (*signer).issuer.as_ptr()) == 0 {
                if libc::strcmp((*trust_item).profileSignCert, (*signer).subject.as_ptr()) == 0 ||
                   libc::strcmp((*trust_item).profileDebugSignCert, (*signer).subject.as_ptr()) == 0 {
                    return trust_item;
                }
            }
        }
        std::ptr::null()
    }
}

fn GetProfileCertTypeBySignInfo(signer: *mut crate::types::SignerResovledInfo, certType: *mut i32) -> i32 {
    use crate::types::*;
    
    // Based on globals.rs, g_trustAppList and g_trustAppListTest are i32, not arrays
    // The C code uses sizeof(g_trustAppList) / sizeof(TrustAppCert) which suggests they are arrays
    // But in our skeleton they're declared as i32, so we need to treat them as pointers
    // For now, use a reasonable default or cast appropriately
    
    let mut trustCert = crate::src_app_verify::GetProfSourceBySigningCert(
        signer as *const SignerResovledInfo,
        unsafe { &crate::globals::g_trustAppList as *const i32 as *const TrustAppCert },
        1i32
    );
    
    if unsafe { crate::globals::g_isDebugMode != 0 } && trustCert.is_null() {
        trustCert = crate::src_app_verify::GetProfSourceBySigningCert(
            signer as *const SignerResovledInfo,
            unsafe { &crate::globals::g_trustAppListTest as *const i32 as *const TrustAppCert },
            1i32
        );
    }
    
    if !trustCert.is_null() {
        let max_cert_path = unsafe { (*trustCert).maxCertPath };
        let depth = unsafe { (*signer).depth };
        if max_cert_path < depth {
            unsafe {
                crate::compat::HiLogPrint(
                    LOG_CORE,
                    LOG_ERROR,
                    0xD001100,
                    b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                    b"[%s:%d]: cert maxdepth error: %d\0".as_ptr() as *const ::core::ffi::c_char,
                    b"GetProfileCertTypeBySignInfo\0".as_ptr() as *const ::core::ffi::c_char,
                    412i32,
                    depth
                );
            }
            return V_ERR as i32;
        }
    }
    
    unsafe {
        *certType = crate::src_app_verify::GetCertTypeBySourceName(trustCert);
    }
    
    V_OK as i32
}

fn GetAppSourceBySigningCert(signer: *const crate::types::SignerResovledInfo, trustList: *const crate::types::TrustAppCert, num: i32) -> *const crate::types::TrustAppCert {
    unsafe {
        for i in 0..num {
            let trust_item = trustList.offset(i as isize);
            let app_sign_cert = (*trust_item).appSignCert;
            let issue_ca = (*trust_item).issueCA;
            let subject_ptr = (*signer).subject.as_ptr();
            let issuer_ptr = (*signer).issuer.as_ptr();
            
            if libc::strcmp(app_sign_cert, subject_ptr) == 0 &&
               libc::strcmp(issue_ca, issuer_ptr) == 0 {
                return trust_item;
            }
        }
        std::ptr::null()
    }
}

// === C2R MANUAL FIX REQUIRED ===
// reason: repair_failed_after_5
// func_key: src_app_verify_15
// c_function: GetAppCertTypeBySignInfo
// rust_file: src_app_verify.rs
// rust_signature: fn GetAppCertTypeBySignInfo(signer: *const crate::types::SignerResovledInfo, certType: *mut i32) -> i32
// c_first_line: static int32_t GetAppCertTypeBySignInfo(SignerResovledInfo *signer, int32_t *certType)
// saved_translation: /data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5_reuseS1_topk1/intermediate/appverify_lite__e5ebe91a98b9/workspace/repair_history/appverify_lite__e5ebe91a98b9/translate_by_qwen3_coder/_manual_fix/src_app_verify_15/translated_rust.rs
// last_error_truncated:
//   error: expected one of `!`, `(`, `+`, `::`, or `<`, found `.`
//      --> src/src_app_verify.rs:264:70
//       |
//       |                                                     ---              ^ expected one of `!`, `(`, `+`, `::`, or `<`
//       |                                                     |
//       |                                                     while parsing this parenthesized list of type arguments starting here
//       |
//   help: consider removing the `::` here to call the expression
// =================================
fn GetAppCertTypeBySignInfo(signer: *const crate::types::SignerResovledInfo, certType: *mut i32) -> i32 {
    unimplemented!()
}
/* === C2R_LLM_FAILED_OUTPUT_BEGIN ===
 * func_key: src_app_verify_15
 * reason: repair_failed_after_5
 * saved_translation: /data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5_reuseS1_topk1/intermediate/appverify_lite__e5ebe91a98b9/workspace/repair_history/appverify_lite__e5ebe91a98b9/translate_by_qwen3_coder/_manual_fix/src_app_verify_15/translated_rust.rs
 * ------------------------------------------------------------
fn GetAppCertTypeBySignInfo(signer: *const crate::types::SignerResovledInfo, certType: *mut i32) -> i32 {
    use crate::types::*;
    
    let trust_app_list_ptr = unsafe { crate::globals::(g_trustAppList.as_ptr)() };
    let trust_app_list_len = unsafe {
        std::mem::size_of_val(&crate::globals::g_trustAppList) / std::mem::size_of::<TrustAppCert>()
    };
    
    let mut trustCert = crate::src_app_verify::GetAppSourceBySigningCert(
        signer,
        trust_app_list_ptr,
        trust_app_list_len as i32,
    );
    
    let is_debug = unsafe { crate::globals::g_isDebugMode != 0 };
    if is_debug && trustCert.is_null() {
        let trust_app_list_test_ptr = unsafe { crate::globals::(g_trustAppListTest.as_ptr)() };
        let trust_app_list_test_len = unsafe {
            std::mem::size_of_val(&crate::globals::g_trustAppListTest) / std::mem::size_of::<TrustAppCert>()
        };
        trustCert = crate::src_app_verify::GetAppSourceBySigningCert(
            signer,
            trust_app_list_test_ptr,
            trust_app_list_test_len as i32,
        );
    }
    
    if !trustCert.is_null() && unsafe { (*trustCert).maxCertPath < (*signer).depth } {
        unsafe {
            crate::compat::HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: cert maxdepth error: %d %d\0".as_ptr() as *const ::core::ffi::c_char,
                b"GetAppCertTypeBySignInfo\0".as_ptr() as *const ::core::ffi::c_char,
                443i32,
                (*trustCert).maxCertPath,
                (*signer).depth,
            );
        }
        return V_ERR as i32;
    }
    
    unsafe {
        *certType = crate::src_app_verify::GetCertTypeBySourceName(trustCert);
    }
    
    V_OK as i32
}
 * ------------------------------------------------------------
 * C2R_LLM_FAILED_OUTPUT_BEGIN func_key: src_app_verify_15
 * === C2R_LLM_FAILED_OUTPUT_END === */


fn GetAppSingerCertType(pkcs7Handle: *mut crate::types::Pkcs7, certType: *mut i32) -> i32 {
    let sri = crate::src_mbedtls_pkcs7::PKCS7_GetAllSignersResolvedInfo(pkcs7Handle as *const crate::types::Pkcs7);
    if sri.is_null() || unsafe { (*sri).nrOfSigners } == 0 {
        crate::src_mbedtls_pkcs7::PKCS7_FreeAllSignersResolvedInfo(sri);
        return crate::types::V_ERR as i32;
    }
    let signer_ptr = unsafe { (*sri).signers };
    let ret = crate::src_app_verify::GetAppCertTypeBySignInfo(signer_ptr as *const crate::types::SignerResovledInfo, certType);
    if ret != crate::types::V_OK as i32 {
        crate::src_mbedtls_pkcs7::PKCS7_FreeAllSignersResolvedInfo(sri);
        return crate::types::V_ERR as i32;
    }
    crate::src_mbedtls_pkcs7::PKCS7_FreeAllSignersResolvedInfo(sri);
    crate::types::V_OK as i32
}

fn GetProfileSingerCertType(pkcs7Handle: *mut crate::types::Pkcs7, certType: *mut i32) -> i32 {
    let sri = crate::src_mbedtls_pkcs7::PKCS7_GetAllSignersResolvedInfo(pkcs7Handle as *const crate::types::Pkcs7);
    if sri.is_null() {
        return crate::types::V_ERR as i32;
    }
    
    let signer_ptr = unsafe { (*sri).signers };
    let ret = crate::src_app_verify::GetProfileCertTypeBySignInfo(signer_ptr, certType);
    if ret != crate::types::V_OK as i32 {
        crate::src_mbedtls_pkcs7::PKCS7_FreeAllSignersResolvedInfo(sri);
        return crate::types::V_ERR as i32;
    }
    
    crate::src_mbedtls_pkcs7::PKCS7_FreeAllSignersResolvedInfo(sri);
    crate::types::V_OK as i32
}

fn VerifyProfileSignGetRaw(buf: *const std::ffi::c_char, len: i32, profileContent: *mut *mut std::ffi::c_char, contentLen: *mut i32) -> i32 {
    unsafe {
        let mut profileData: *mut std::ffi::c_char = std::ptr::null_mut();
        let mut certType: i32 = 0;
        let mut input: *mut ::core::ffi::c_uchar = std::ptr::null_mut();
        let mut inputLen: crate::types::size_t = 0;
        
        let pkcs7: *mut crate::types::Pkcs7 = libc::malloc(std::mem::size_of::<crate::types::Pkcs7>()) as *mut crate::types::Pkcs7;
        if pkcs7.is_null() {
            return crate::types::V_ERR as i32;
        }
        
        let mut ret = crate::src_mbedtls_pkcs7::PKCS7_ParseSignedData(
            buf as *const ::core::ffi::c_uchar,
            len as crate::types::size_t,
            pkcs7
        );
        if ret != crate::types::V_OK as i32 {
            crate::src_mbedtls_pkcs7::PKCS7_FreeRes(pkcs7);
            libc::free(pkcs7 as *mut ::core::ffi::c_void);
            return crate::types::V_ERR as i32;
        }
        
        ret = crate::src_mbedtls_pkcs7::PKCS7_VerifyCertsChain(pkcs7 as *const crate::types::Pkcs7);
        if ret != crate::types::V_OK as i32 {
            crate::src_mbedtls_pkcs7::PKCS7_FreeRes(pkcs7);
            libc::free(pkcs7 as *mut ::core::ffi::c_void);
            return crate::types::V_ERR as i32;
        }
        
        ret = GetProfileSingerCertType(pkcs7, &mut certType);
        if ret != crate::types::V_OK as i32 {
            crate::src_mbedtls_pkcs7::PKCS7_FreeRes(pkcs7);
            libc::free(pkcs7 as *mut ::core::ffi::c_void);
            return crate::types::V_ERR as i32;
        }
        
        if certType == crate::types::CERT_TYPE_OTHER as i32 {
            crate::src_mbedtls_pkcs7::PKCS7_FreeRes(pkcs7);
            libc::free(pkcs7 as *mut ::core::ffi::c_void);
            return crate::types::V_ERR as i32;
        }
        
        let calc_digest_fn: crate::types::PKCS7_CalcDigest = std::mem::transmute(CalcDigest as usize);
        ret = crate::src_mbedtls_pkcs7::PKCS7_VerifySignerSignature(
            pkcs7 as *const crate::types::Pkcs7,
            calc_digest_fn
        );
        if ret != crate::types::V_OK as i32 {
            crate::src_mbedtls_pkcs7::PKCS7_FreeRes(pkcs7);
            libc::free(pkcs7 as *mut ::core::ffi::c_void);
            return crate::types::V_ERR as i32;
        }
        
        ret = crate::src_mbedtls_pkcs7::PKCS7_GetContentData(
            pkcs7 as *const crate::types::Pkcs7,
            &mut input,
            &mut inputLen
        );
        if ret != crate::types::V_OK as i32 {
            crate::src_mbedtls_pkcs7::PKCS7_FreeRes(pkcs7);
            libc::free(pkcs7 as *mut ::core::ffi::c_void);
            return crate::types::V_ERR as i32;
        }
        
        if inputLen > crate::types::MAX_PROFILE_SIZE || inputLen == 0 {
            crate::src_mbedtls_pkcs7::PKCS7_FreeRes(pkcs7);
            libc::free(pkcs7 as *mut ::core::ffi::c_void);
            return crate::types::V_ERR as i32;
        }
        
        profileData = libc::malloc((inputLen as usize) + 1) as *mut std::ffi::c_char;
        if profileData.is_null() {
            crate::src_mbedtls_pkcs7::PKCS7_FreeRes(pkcs7);
            libc::free(pkcs7 as *mut ::core::ffi::c_void);
            return crate::types::V_ERR as i32;
        }
        
        ret = memcpy_s(
            profileData as *mut ::core::ffi::c_void,
            inputLen,
            input as *const ::core::ffi::c_void,
            inputLen
        ) as i32;
        *profileData.add(inputLen as usize) = 0;
        if ret != crate::types::V_OK as i32 {
            crate::src_mbedtls_pkcs7::PKCS7_FreeRes(pkcs7);
            libc::free(pkcs7 as *mut ::core::ffi::c_void);
            libc::free(profileData as *mut ::core::ffi::c_void);
            return crate::types::V_ERR as i32;
        }
        
        crate::src_mbedtls_pkcs7::PKCS7_FreeRes(pkcs7);
        libc::free(pkcs7 as *mut ::core::ffi::c_void);
        *profileContent = profileData;
        *contentLen = inputLen as i32;
        
        crate::types::V_OK as i32
    }
}

fn GetRsaPk(pk: *const crate::types::mbedtls_pk_context, len: *mut i32) -> *const u8 {
    const BUF_SIZE: usize = 1024 * 2 + 20;
    
    let buf: *mut u8 = unsafe { libc::malloc(BUF_SIZE) as *mut u8 };
    if buf.is_null() {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: malloc error\0".as_ptr() as *const i8,
                b"GetRsaPk\0".as_ptr() as *const i8,
                554i32,
            );
        }
        return std::ptr::null();
    }
    
    let ret = unsafe { memset_s(buf as *mut ::core::ffi::c_void, BUF_SIZE as crate::types::size_t, 0, BUF_SIZE as crate::types::size_t) };
    if ret != 0 {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: memset error\0".as_ptr() as *const i8,
                b"GetRsaPk\0".as_ptr() as *const i8,
                559i32,
            );
            libc::free(buf as *mut ::core::ffi::c_void);
        }
        return std::ptr::null();
    }
    
    let mut c: *mut u8 = unsafe { buf.add(BUF_SIZE) };
    let pk_len = unsafe { mbedtls_pk_write_pubkey(&mut c, buf, pk) };
    
    unsafe {
        HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const i8,
            b"[%s:%d]: GetRsaPk pkLen %d\0".as_ptr() as *const i8,
            b"GetRsaPk\0".as_ptr() as *const i8,
            565i32,
            pk_len,
        );
    }
    
    if pk_len < 0 || pk_len > BUF_SIZE as i32 {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: get pk buf error\0".as_ptr() as *const i8,
                b"GetRsaPk\0".as_ptr() as *const i8,
                567i32,
            );
            let _ = memset_s(buf as *mut ::core::ffi::c_void, BUF_SIZE as crate::types::size_t, 0, BUF_SIZE as crate::types::size_t);
            libc::free(buf as *mut ::core::ffi::c_void);
        }
        return std::ptr::null();
    }
    
    let pk_buf: *mut u8 = unsafe { libc::malloc(pk_len as usize) as *mut u8 };
    if pk_buf.is_null() {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: malloc error\0".as_ptr() as *const i8,
                b"GetRsaPk\0".as_ptr() as *const i8,
                574i32,
            );
            let _ = memset_s(buf as *mut ::core::ffi::c_void, BUF_SIZE as crate::types::size_t, 0, BUF_SIZE as crate::types::size_t);
            libc::free(buf as *mut ::core::ffi::c_void);
        }
        return std::ptr::null();
    }
    
    let ret = unsafe { memcpy_s(pk_buf as *mut ::core::ffi::c_void, pk_len as crate::types::size_t, c as *const ::core::ffi::c_void, pk_len as crate::types::size_t) };
    if ret != 0 {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: mem copy error: %d\0".as_ptr() as *const i8,
                b"GetRsaPk\0".as_ptr() as *const i8,
                581i32,
                ret,
            );
            let _ = memset_s(buf as *mut ::core::ffi::c_void, BUF_SIZE as crate::types::size_t, 0, BUF_SIZE as crate::types::size_t);
            libc::free(buf as *mut ::core::ffi::c_void);
            libc::free(pk_buf as *mut ::core::ffi::c_void);
        }
        return std::ptr::null();
    }
    
    unsafe {
        *len = pk_len;
        let _ = memset_s(buf as *mut ::core::ffi::c_void, BUF_SIZE as crate::types::size_t, 0, BUF_SIZE as crate::types::size_t);
        libc::free(buf as *mut ::core::ffi::c_void);
    }
    
    pk_buf as *const u8
}

fn GetEcPk(pk: *const crate::types::mbedtls_pk_context, len: *mut i32) -> *mut u8 {
    use crate::compat::*;
    
    const MAX_EC_PK_SIZE: usize = 2 * ((521 + 7) / 8) + 1;
    
    // Inline mbedtls_pk_ec logic
    let ecCtx: *mut crate::types::mbedtls_ecp_keypair = unsafe {
        let pk_type = mbedtls_pk_get_type(pk);
        if pk_type == crate::types::MBEDTLS_PK_ECKEY 
            || pk_type == crate::types::MBEDTLS_PK_ECKEY_DH 
            || pk_type == crate::types::MBEDTLS_PK_ECDSA {
            (*pk).private_pk_ctx as *mut crate::types::mbedtls_ecp_keypair
        } else {
            std::ptr::null_mut()
        }
    };
    
    if ecCtx.is_null() {
        return std::ptr::null_mut();
    }
    
    let buf: *mut u8 = unsafe { libc::malloc(MAX_EC_PK_SIZE) as *mut u8 };
    if buf.is_null() {
        return std::ptr::null_mut();
    }
    
    let ret = unsafe { memset_s(buf as *mut ::core::ffi::c_void, MAX_EC_PK_SIZE as crate::types::size_t, 0, MAX_EC_PK_SIZE as crate::types::size_t) };
    if ret != 0 {
        unsafe { libc::free(buf as *mut ::core::ffi::c_void); }
        return std::ptr::null_mut();
    }
    
    let ret = unsafe {
        mbedtls_ecp_point_write_binary(
            &mut (*ecCtx).private_grp as *mut crate::types::mbedtls_ecp_group,
            &mut (*ecCtx).private_Q as *mut crate::types::mbedtls_ecp_point,
            0,
            len as *mut crate::types::size_t,
            buf,
            MAX_EC_PK_SIZE as crate::types::size_t
        )
    };
    
    if ret != crate::types::V_OK as i32 {
        let _ = unsafe { memset_s(buf as *mut ::core::ffi::c_void, MAX_EC_PK_SIZE as crate::types::size_t, 0, MAX_EC_PK_SIZE as crate::types::size_t) };
        unsafe { libc::free(buf as *mut ::core::ffi::c_void); }
        return std::ptr::null_mut();
    }
    
    let len_val = unsafe { *len };
    if len_val <= 0 || len_val > MAX_EC_PK_SIZE as i32 {
        unsafe { libc::free(buf as *mut ::core::ffi::c_void); }
        return std::ptr::null_mut();
    }
    
    let pkBuf: *mut u8 = unsafe { libc::malloc(len_val as usize) as *mut u8 };
    if pkBuf.is_null() {
        let _ = unsafe { memset_s(buf as *mut ::core::ffi::c_void, MAX_EC_PK_SIZE as crate::types::size_t, 0, MAX_EC_PK_SIZE as crate::types::size_t) };
        unsafe { libc::free(buf as *mut ::core::ffi::c_void); }
        return std::ptr::null_mut();
    }
    
    let ret = unsafe { memcpy_s(pkBuf as *mut ::core::ffi::c_void, len_val as crate::types::size_t, buf as *const ::core::ffi::c_void, len_val as crate::types::size_t) };
    if ret != 0 {
        let _ = unsafe { memset_s(buf as *mut ::core::ffi::c_void, MAX_EC_PK_SIZE as crate::types::size_t, 0, MAX_EC_PK_SIZE as crate::types::size_t) };
        unsafe { libc::free(buf as *mut ::core::ffi::c_void); }
        unsafe { libc::free(pkBuf as *mut ::core::ffi::c_void); }
        return std::ptr::null_mut();
    }
    
    unsafe { libc::free(buf as *mut ::core::ffi::c_void); }
    pkBuf
}

fn GetPkBuf(pk: *const crate::types::mbedtls_pk_context, len: *mut i32) -> *mut u8 {
    let mut bufA: *mut u8 = std::ptr::null_mut();
    
    unsafe {
        let pk_type = crate::compat::mbedtls_pk_get_type(pk);
        
        if pk_type == crate::types::MBEDTLS_PK_RSA || pk_type == crate::types::MBEDTLS_PK_RSASSA_PSS {
            bufA = crate::src_app_verify::GetRsaPk(pk, len) as *mut u8;
        } else if pk_type == crate::types::MBEDTLS_PK_ECDSA || pk_type == crate::types::MBEDTLS_PK_ECKEY {
            bufA = crate::src_app_verify::GetEcPk(pk, len);
        }
    }
    
    bufA
}

fn ParseCertGetPk(certEncoded: *const std::ffi::c_char, pk: *mut crate::types::AppSignPk) -> i32 {
    unsafe {
        let cert: *mut crate::types::mbedtls_x509_crt = libc::malloc(
            std::mem::size_of::<crate::types::mbedtls_x509_crt>()
        ) as *mut crate::types::mbedtls_x509_crt;
        
        if cert.is_null() {
            return crate::types::V_ERR as i32;
        }
        
        crate::compat::mbedtls_x509_crt_init(cert);
        
        let cert_len = (libc::strlen(certEncoded) + 1) as crate::types::size_t;
        let ret = crate::compat::mbedtls_x509_crt_parse(
            cert,
            certEncoded as *const u8,
            cert_len
        );
        
        if ret != crate::types::V_OK as i32 {
            libc::free(cert as *mut std::ffi::c_void);
            return crate::types::V_ERR as i32;
        }
        
        let mut len: i32 = 0;
        let pkBuf = crate::src_app_verify::GetPkBuf(
            &(*cert).pk as *const crate::types::mbedtls_pk_context,
            &mut len
        );
        
        if pkBuf.is_null() {
            crate::compat::mbedtls_x509_crt_free(cert);
            libc::free(cert as *mut std::ffi::c_void);
            return crate::types::V_ERR as i32;
        }
        
        (*pk).pk = pkBuf as *mut std::ffi::c_char;
        (*pk).len = len;
        
        crate::compat::mbedtls_x509_crt_free(cert);
        libc::free(cert as *mut std::ffi::c_void);
        
        crate::types::V_OK as i32
    }
}

fn GetAppSignPublicKey(profile: *const crate::types::ProfileProf, pk: *mut crate::types::AppSignPk) -> i32 {
    let ret: i32;

    unsafe {
        let release_cert = (*profile).bundleInfo.releaseCert;
        if !release_cert.is_null() && libc::strlen(release_cert as *const i8) != 0 {
            ret = crate::src_app_verify::ParseCertGetPk(release_cert as *const std::ffi::c_char, pk);
        } else {
            let dev_cert = (*profile).bundleInfo.devCert;
            ret = crate::src_app_verify::ParseCertGetPk(dev_cert as *const std::ffi::c_char, pk);
        }
    }

    if ret != crate::types::V_OK as i32 {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const std::ffi::c_char,
                b"[%s:%d]: GetSignCertpk failed, ret: %d\0".as_ptr() as *const std::ffi::c_char,
                b"GetAppSignPublicKey\0".as_ptr() as *const std::ffi::c_char,
                692i32,
                ret,
            );
        }
        return crate::types::V_ERR_GET_CERT_PK as i32;
    }
    crate::types::V_OK as i32
}

fn FreeAppSignPublicKey(pk: *mut crate::types::AppSignPk) {
    unsafe {
        if (*pk).pk != std::ptr::null_mut() {
            if (*pk).pk != std::ptr::null_mut() {
                libc::free((*pk).pk as *mut core::ffi::c_void);
                (*pk).pk = std::ptr::null_mut();
            }
        }
    }
}

pub extern "C" fn GetAppid(profile: *mut crate::types::ProfileProf) -> i32 {
    use crate::types::*;
    
    if profile.is_null() {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: profile is null\0".as_ptr() as *const ::core::ffi::c_char,
                b"GetAppid\0".as_ptr() as *const ::core::ffi::c_char,
                708i32,
            );
        }
        return V_ERR as i32;
    }
    
    let mut pk = AppSignPk {
        pk: std::ptr::null_mut(),
        len: 0,
    };
    
    let ret = crate::src_app_verify::GetAppSignPublicKey(profile as *const ProfileProf, &mut pk);
    if ret != V_OK as i32 {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: get sign pk failed\0".as_ptr() as *const ::core::ffi::c_char,
                b"GetAppid\0".as_ptr() as *const ::core::ffi::c_char,
                712i32,
            );
        }
        return ret;
    }
    
    let mut useLen: size_t = 0;
    unsafe {
        mbedtls_base64_encode(
            std::ptr::null_mut(),
            0,
            &mut useLen,
            pk.pk as *const ::core::ffi::c_uchar,
            pk.len as size_t,
        );
    }
    
    let bundleNameLen: i32 = unsafe { libc::strlen((*profile).bundleInfo.bundleName) as i32 };
    let appidLen: i32 = bundleNameLen + useLen as i32 + 1 + 1;
    
    unsafe {
        HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: GetAppid %d\0".as_ptr() as *const ::core::ffi::c_char,
            b"GetAppid\0".as_ptr() as *const ::core::ffi::c_char,
            721i32,
            appidLen,
        );
    }
    
    if useLen > MAX_KEY_PAIR_SIZE {
        return V_ERR as i32;
    }
    
    let appid: *mut ::core::ffi::c_char = unsafe { libc::malloc(appidLen as usize) as *mut ::core::ffi::c_char };
    if appid.is_null() {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: malloc failed\0".as_ptr() as *const ::core::ffi::c_char,
                b"GetAppid\0".as_ptr() as *const ::core::ffi::c_char,
                727i32,
            );
        }
        crate::src_app_verify::FreeAppSignPublicKey(&mut pk);
        return V_ERR_MALLOC as i32;
    }
    
    unsafe { *appid.offset((appidLen - 1) as isize) = 0; }
    
    let ret = unsafe {
        snprintf_s(
            appid,
            appidLen as size_t,
            (bundleNameLen + 1) as size_t,
            b"%s_\0".as_ptr() as *const ::core::ffi::c_char,
            (*profile).bundleInfo.bundleName,
        )
    };
    
    if ret < 0 {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: snprintf error ret: %d\0".as_ptr() as *const ::core::ffi::c_char,
                b"GetAppid\0".as_ptr() as *const ::core::ffi::c_char,
                734i32,
                ret,
            );
            libc::free(appid as *mut ::core::ffi::c_void);
        }
        crate::src_app_verify::FreeAppSignPublicKey(&mut pk);
        return V_ERR_GET_APPID as i32;
    }
    
    let ret = unsafe {
        mbedtls_base64_encode(
            appid.offset((bundleNameLen + 1) as isize) as *mut ::core::ffi::c_uchar,
            (appidLen - bundleNameLen - 1) as size_t,
            &mut useLen,
            pk.pk as *const ::core::ffi::c_uchar,
            pk.len as size_t,
        )
    };
    
    if ret != V_OK as i32 {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: base 64 encode error\0".as_ptr() as *const ::core::ffi::c_char,
                b"GetAppid\0".as_ptr() as *const ::core::ffi::c_char,
                742i32,
            );
            libc::free(appid as *mut ::core::ffi::c_void);
        }
        crate::src_app_verify::FreeAppSignPublicKey(&mut pk);
        return V_ERR_GET_APPID as i32;
    }
    
    unsafe { (*profile).appid = appid; }
    
    unsafe {
        HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: appid len: %d, bL len: %d, base64: %d\0".as_ptr() as *const ::core::ffi::c_char,
            b"GetAppid\0".as_ptr() as *const ::core::ffi::c_char,
            748i32,
            appidLen,
            bundleNameLen,
            useLen as i32,
        );
        HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: %s\0".as_ptr() as *const ::core::ffi::c_char,
            b"GetAppid\0".as_ptr() as *const ::core::ffi::c_char,
            749i32,
            appid,
        );
    }
    
    crate::src_app_verify::FreeAppSignPublicKey(&mut pk);
    V_OK as i32
}

fn VerifyProfGetContent(fp: i32, signInfo: *const crate::types::SignatureInfo, certType: i32, pf: *mut crate::types::ProfileProf) -> i32 {
    let mut profBuf: *mut std::ffi::c_char = std::ptr::null_mut();
    let mut len: i32 = 0;
    let mut blockHead: crate::types::BlockHead = unsafe { std::mem::zeroed() };
    let ret: i32;
    let mut rawLen: i32 = 0;
    
    let rawBuf = unsafe {
        crate::src_app_verify::GetSignBlockByType(
            signInfo,
            fp,
            crate::types::PROFILE_BLOCK_WITHSIGN_TYPE as i32,
            &mut rawLen,
            &mut blockHead,
        )
    };
    
    if rawBuf.is_null() {
        return crate::types::V_ERR_GET_PROFILE_DATA as i32;
    }
    
    let mut rawBuf_mut = rawBuf;
    
    if certType == 0 {
        profBuf = rawBuf_mut;
        len = rawLen;
    } else {
        let ret_sign = crate::src_app_verify::VerifyProfileSignGetRaw(
            rawBuf_mut as *const std::ffi::c_char,
            rawLen,
            &mut profBuf,
            &mut len,
        );
        
        if !rawBuf_mut.is_null() {
            unsafe { libc::free(rawBuf_mut as *mut std::ffi::c_void) };
            rawBuf_mut = std::ptr::null_mut();
        }
        
        if ret_sign != crate::types::V_OK as i32 {
            return ret_sign;
        }
    }
    
    let ret_parse = unsafe {
        crate::src_app_provision::ParseProfile(profBuf as *const std::ffi::c_char, len, pf)
    };
    
    if ret_parse != crate::types::V_OK as i32 {
        if !profBuf.is_null() {
            unsafe { libc::free(profBuf as *mut std::ffi::c_void) };
        }
        return crate::types::V_ERR_GET_PARSE_PROFILE as i32;
    }
    
    if !profBuf.is_null() {
        unsafe { libc::free(profBuf as *mut std::ffi::c_void) };
    }
    
    let ret_content = unsafe {
        crate::src_app_provision::VerifyProfileContent(pf as *const crate::types::ProfileProf)
    };
    
    if ret_content != crate::types::V_OK as i32 {
        unsafe { crate::src_app_provision::ProfFreeData(pf) };
        return ret_content;
    }
    
    let ret_appid = unsafe { crate::src_app_verify::GetAppid(pf) };
    
    if ret_appid != crate::types::V_OK as i32 {
        unsafe { crate::src_app_provision::ProfFreeData(pf) };
        return ret_appid;
    }
    
    crate::types::V_OK as i32
}

fn CmpCert(certA: *const crate::types::mbedtls_x509_crt, binSignCert: *const crate::types::CertInfo) -> i32 {
    use crate::types::{V_ERR, V_OK};
    
    if certA.is_null() {
        return V_ERR as i32;
    }
    if binSignCert.is_null() {
        return V_ERR as i32;
    }
    
    unsafe {
        // Compare subject
        if (*certA).subject_raw.len != (*binSignCert).subjectLen as u32 ||
           libc::memcmp(
               (*certA).subject_raw.p as *const core::ffi::c_void,
               (*binSignCert).subject as *const core::ffi::c_void,
               (*certA).subject_raw.len as usize
           ) != 0 {
            return V_ERR as i32;
        }
        
        // Compare issuer
        if (*certA).issuer_raw.len != (*binSignCert).issuerLen as u32 ||
           libc::memcmp(
               (*certA).issuer_raw.p as *const core::ffi::c_void,
               (*binSignCert).issuer as *const core::ffi::c_void,
               (*certA).issuer_raw.len as usize
           ) != 0 {
            return V_ERR as i32;
        }
        
        // Compare pk type
        if crate::compat::mbedtls_pk_get_type(&(*certA).pk) != (*binSignCert).pkType {
            return V_ERR as i32;
        }
        
        // Get pk buffer
        let mut lenA: i32 = 0;
        let bufA = GetPkBuf(&(*certA).pk, &mut lenA);
        if bufA.is_null() {
            return V_ERR as i32;
        }
        
        // Compare pk length
        if lenA != (*binSignCert).pkLen {
            libc::free(bufA as *mut core::ffi::c_void);
            return V_ERR as i32;
        }
        
        // Compare pk content
        if libc::memcmp(
            bufA as *const core::ffi::c_void,
            (*binSignCert).pkBuf as *const core::ffi::c_void,
            lenA as usize
        ) != 0 {
            libc::free(bufA as *mut core::ffi::c_void);
            return V_ERR as i32;
        }
        
        libc::free(bufA as *mut core::ffi::c_void);
    }
    
    V_OK as i32
}

pub extern "C" fn LoadCertAndCmpDest(certBase64: *const ::core::ffi::c_uchar, binSignCert: *const crate::types::CertInfo) -> i32 {
    use crate::types::*;
    use crate::compat::*;
    
    if certBase64.is_null() || binSignCert.is_null() {
        return V_ERR as i32;
    }
    
    let mut cert: mbedtls_x509_crt = unsafe { std::mem::zeroed() };
    unsafe { mbedtls_x509_crt_init(&mut cert) };
    
    let cert_len = unsafe { libc::strlen(certBase64 as *const i8) + 1 };
    let ret = unsafe { mbedtls_x509_crt_parse(&mut cert, certBase64, cert_len as size_t) };
    
    if ret != V_OK as i32 {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: load release cert failed\0".as_ptr() as *const i8,
                b"LoadCertAndCmpDest\0".as_ptr() as *const i8,
                846 as i32,
            );
            HiLogPrint(
                LOG_CORE,
                LOG_INFO,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: %s\0".as_ptr() as *const i8,
                b"LoadCertAndCmpDest\0".as_ptr() as *const i8,
                847 as i32,
                certBase64,
            );
        }
        return V_ERR as i32;
    }
    
    if crate::src_app_verify::CmpCert(&cert as *const mbedtls_x509_crt, binSignCert) == V_OK as i32 {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_INFO,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: cert consistent\0".as_ptr() as *const i8,
                b"LoadCertAndCmpDest\0".as_ptr() as *const i8,
                852 as i32,
            );
            mbedtls_x509_crt_free(&mut cert);
        }
        return V_OK as i32;
    }
    
    unsafe {
        HiLogPrint(
            LOG_CORE,
            LOG_ERROR,
            0xD001100,
            b"appverify\0".as_ptr() as *const i8,
            b"[%s:%d]: cert inconsistent\0".as_ptr() as *const i8,
            b"LoadCertAndCmpDest\0".as_ptr() as *const i8,
            856 as i32,
        );
        mbedtls_x509_crt_free(&mut cert);
    }
    
    V_ERR as i32
}

fn CheckReleaseAppSign(binSignCert: *const crate::types::CertInfo, pf: *const crate::types::ProfileProf) -> i32 {
    unsafe {
        let app_gallery_str = b"app_gallery\0".as_ptr() as *const ::core::ffi::c_char;
        
        if libc::strcmp((*pf).appDistType, app_gallery_str) == 0 {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: app release, distribution type is app_gallery, return error\0".as_ptr() as *const ::core::ffi::c_char,
                b"CheckReleaseAppSign\0".as_ptr() as *const ::core::ffi::c_char,
                865 as ::core::ffi::c_int,
            );
            return crate::types::V_ERR as i32;
        }
        
        if libc::strlen((*pf).bundleInfo.releaseCert as *const ::core::ffi::c_char) == 0 {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: release app, release Cert null\0".as_ptr() as *const ::core::ffi::c_char,
                b"CheckReleaseAppSign\0".as_ptr() as *const ::core::ffi::c_char,
                870 as ::core::ffi::c_int,
            );
            return crate::types::V_ERR as i32;
        }
        
        let ret = crate::src_app_verify::LoadCertAndCmpDest((*pf).bundleInfo.releaseCert, binSignCert);
        if ret == crate::types::V_OK as i32 {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_INFO,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: dev cert consistent\0".as_ptr() as *const ::core::ffi::c_char,
                b"CheckReleaseAppSign\0".as_ptr() as *const ::core::ffi::c_char,
                875 as ::core::ffi::c_int,
            );
            return crate::types::V_OK as i32;
        }
        
        let _ = crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_ERROR,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: app sign cert not consistent with profile cert\0".as_ptr() as *const ::core::ffi::c_char,
            b"CheckReleaseAppSign\0".as_ptr() as *const ::core::ffi::c_char,
            878 as ::core::ffi::c_int,
        );
        crate::types::V_ERR as i32
    }
}

fn CheckDebugAppSign(binSignCert: *mut crate::types::CertInfo, pf: *const crate::types::ProfileProf) -> i32 {
    unsafe {
        let dev_cert = (*pf).bundleInfo.devCert;
        if libc::strlen(dev_cert as *const i8) == 0 {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: debug app, devCert null\0".as_ptr() as *const i8,
                b"CheckDebugAppSign\0".as_ptr() as *const i8,
                885i32,
            );
            return crate::types::V_ERR as i32;
        }
        
        let ret = crate::src_app_verify::LoadCertAndCmpDest(dev_cert, binSignCert as *const crate::types::CertInfo);
        if ret == crate::types::V_OK as i32 {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_INFO,
                0xD001100,
                b"appverify\0".as_ptr() as *const i8,
                b"[%s:%d]: dev cert consistent\0".as_ptr() as *const i8,
                b"CheckDebugAppSign\0".as_ptr() as *const i8,
                890i32,
            );
            return crate::types::V_OK as i32;
        }
        
        let release_cert = (*pf).bundleInfo.releaseCert;
        if libc::strlen(release_cert as *const i8) != 0 {
            let ret2 = crate::src_app_verify::LoadCertAndCmpDest(release_cert, binSignCert as *const crate::types::CertInfo);
            if ret2 == crate::types::V_OK as i32 {
                let _ = crate::compat::HiLogPrint(
                    crate::types::LOG_CORE,
                    crate::types::LOG_INFO,
                    0xD001100,
                    b"appverify\0".as_ptr() as *const i8,
                    b"[%s:%d]: release cert consistent\0".as_ptr() as *const i8,
                    b"CheckDebugAppSign\0".as_ptr() as *const i8,
                    896i32,
                );
                return crate::types::V_OK as i32;
            }
        }
        
        let _ = crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_ERROR,
            0xD001100,
            b"appverify\0".as_ptr() as *const i8,
            b"[%s:%d]: app sign cert not consistent with profile cert\0".as_ptr() as *const i8,
            b"CheckDebugAppSign\0".as_ptr() as *const i8,
            900i32,
        );
        crate::types::V_ERR as i32
    }
}

fn CheckAppSignCertWithProfile(appCertType: i32, binSignCert: *const crate::types::CertInfo, pf: *const crate::types::ProfileProf) -> i32 {
    if appCertType == crate::types::CERT_TYPE_APPGALLARY as i32 || appCertType == crate::types::CERT_TYPE_SYETEM as i32 {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_INFO,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: app type : %d, return OK\0".as_ptr() as *const ::core::ffi::c_char,
                b"CheckAppSignCertWithProfile\0".as_ptr() as *const ::core::ffi::c_char,
                908i32,
                appCertType,
            );
        }
        return crate::types::V_OK as i32;
    }

    let mut ret: i32 = crate::types::V_ERR as i32;

    unsafe {
        let pf_type = (*pf).type_;
        if libc::strcmp(b"debug\0".as_ptr() as *const ::core::ffi::c_char, pf_type as *const ::core::ffi::c_char) == 0 {
            ret = crate::src_app_verify::CheckDebugAppSign(binSignCert as *mut crate::types::CertInfo, pf);
        } else if libc::strcmp(b"release\0".as_ptr() as *const ::core::ffi::c_char, pf_type as *const ::core::ffi::c_char) == 0 {
            ret = crate::src_app_verify::CheckReleaseAppSign(binSignCert, pf);
        }

        crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: check app sign cert ret : %d\0".as_ptr() as *const ::core::ffi::c_char,
            b"CheckAppSignCertWithProfile\0".as_ptr() as *const ::core::ffi::c_char,
            920i32,
            ret,
        );
    }

    ret
}

fn CertInfoInit(certInfo: *mut crate::types::CertInfo) -> i32 {
    let ret = unsafe {
        crate::compat::memset_s(
            certInfo as *mut ::core::ffi::c_void,
            std::mem::size_of::<crate::types::CertInfo>() as crate::types::size_t,
            0,
            std::mem::size_of::<crate::types::CertInfo>() as crate::types::size_t,
        )
    };
    if ret != 0 {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: memset error\0".as_ptr() as *const ::core::ffi::c_char,
                b"CertInfoInit\0".as_ptr() as *const ::core::ffi::c_char,
                928i32,
            );
        }
    }
    ret as i32
}

pub extern "C" fn FreeCertInfo(certInfo: *mut crate::types::CertInfo) {
    if certInfo.is_null() {
        return;
    }
    
    unsafe {
        if !(*certInfo).issuer.is_null() {
            libc::free((*certInfo).issuer as *mut ::core::ffi::c_void);
            (*certInfo).issuer = std::ptr::null_mut();
            (*certInfo).issuerLen = 0;
        }
        
        if !(*certInfo).subject.is_null() {
            libc::free((*certInfo).subject as *mut ::core::ffi::c_void);
            (*certInfo).subject = std::ptr::null_mut();
            (*certInfo).subjectLen = 0;
        }
        
        if !(*certInfo).pkBuf.is_null() {
            libc::free((*certInfo).pkBuf as *mut ::core::ffi::c_void);
            (*certInfo).pkBuf = std::ptr::null_mut();
            (*certInfo).pkLen = 0;
        }
    }
}

fn GetCertInfo(ctr: *const crate::types::mbedtls_x509_crt, binSignCert: *mut *mut crate::types::CertInfo) -> i32 {
    unsafe {
        let certInfo = libc::malloc(core::mem::size_of::<crate::types::CertInfo>()) as *mut crate::types::CertInfo;
        if certInfo.is_null() {
            return crate::types::V_ERR_MALLOC as i32;
        }

        let mut ret = crate::src_app_verify::CertInfoInit(certInfo);
        if ret != crate::types::V_OK as i32 {
            ret = crate::types::V_ERR_MEMSET as i32;
            crate::src_app_verify::FreeCertInfo(certInfo);
            libc::free(certInfo as *mut core::ffi::c_void);
            return ret;
        }

        (*certInfo).issuerLen = (*ctr).issuer_raw.len as i32;
        (*certInfo).subjectLen = (*ctr).subject_raw.len as i32;

        if (*certInfo).issuerLen == 0 || (*certInfo).issuerLen > (1024 * 1024) ||
           (*certInfo).subjectLen == 0 || (*certInfo).subjectLen > (1024 * 1024) {
            ret = crate::types::V_ERR_MALLOC as i32;
            crate::src_app_verify::FreeCertInfo(certInfo);
            libc::free(certInfo as *mut core::ffi::c_void);
            return ret;
        }

        (*certInfo).issuer = libc::malloc(((*certInfo).issuerLen + 1) as usize) as *mut core::ffi::c_char;
        if (*certInfo).issuer.is_null() {
            ret = crate::types::V_ERR_MALLOC as i32;
            crate::src_app_verify::FreeCertInfo(certInfo);
            libc::free(certInfo as *mut core::ffi::c_void);
            return ret;
        }
        *(*certInfo).issuer.offset((*certInfo).issuerLen as isize) = 0;
        ret = memcpy_s(
            (*certInfo).issuer as *mut core::ffi::c_void,
            (*certInfo).issuerLen as u32,
            (*ctr).issuer_raw.p as *const core::ffi::c_void,
            (*ctr).issuer_raw.len as u32
        ) as i32;
        if ret != 0 {
            ret = crate::types::V_ERR_MEMCPY as i32;
            crate::src_app_verify::FreeCertInfo(certInfo);
            libc::free(certInfo as *mut core::ffi::c_void);
            return ret;
        }

        (*certInfo).subject = libc::malloc(((*certInfo).subjectLen + 1) as usize) as *mut core::ffi::c_char;
        if (*certInfo).subject.is_null() {
            ret = crate::types::V_ERR_MALLOC as i32;
            crate::src_app_verify::FreeCertInfo(certInfo);
            libc::free(certInfo as *mut core::ffi::c_void);
            return ret;
        }
        *(*certInfo).subject.offset((*certInfo).subjectLen as isize) = 0;
        ret = memcpy_s(
            (*certInfo).subject as *mut core::ffi::c_void,
            (*certInfo).subjectLen as u32,
            (*ctr).subject_raw.p as *const core::ffi::c_void,
            (*ctr).subject_raw.len as u32
        ) as i32;
        if ret != 0 {
            ret = crate::types::V_ERR_MEMCPY as i32;
            crate::src_app_verify::FreeCertInfo(certInfo);
            libc::free(certInfo as *mut core::ffi::c_void);
            return ret;
        }

        (*certInfo).pkType = mbedtls_pk_get_type(&(*ctr).pk as *const crate::types::mbedtls_pk_context);
        let pk_buf = crate::src_app_verify::GetPkBuf(&(*ctr).pk as *const crate::types::mbedtls_pk_context, &mut (*certInfo).pkLen as *mut i32);
        (*certInfo).pkBuf = pk_buf as *mut core::ffi::c_char;
        if (*certInfo).pkBuf.is_null() {
            ret = crate::types::V_ERR as i32;
            crate::src_app_verify::FreeCertInfo(certInfo);
            libc::free(certInfo as *mut core::ffi::c_void);
            return ret;
        }

        *binSignCert = certInfo;
        crate::types::V_OK as i32
    }
}

fn VerfiyAppSourceGetProfile(fp: i32, signInfo: *const crate::types::SignatureInfo, certType: i32, binSignCert: *mut crate::types::CertInfo, pf: *mut crate::types::ProfileProf) -> i32 {
    let mut ret = crate::src_app_verify::VerifyProfGetContent(fp, signInfo, certType, pf);
    if ret != crate::types::V_OK as i32 {
        let _ = unsafe { crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_ERROR,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: VerifyProfGetContent error: %d\0".as_ptr() as *const ::core::ffi::c_char,
            b"VerfiyAppSourceGetProfile\0".as_ptr() as *const ::core::ffi::c_char,
            1015i32,
            ret
        ) };
        return ret;
    }
    let _ = unsafe { crate::compat::HiLogPrint(
        crate::types::LOG_CORE,
        crate::types::LOG_INFO,
        0xD001100,
        b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
        b"[%s:%d]: verify prof get content success\0".as_ptr() as *const ::core::ffi::c_char,
        b"VerfiyAppSourceGetProfile\0".as_ptr() as *const ::core::ffi::c_char,
        1018i32
    ) };

    ret = crate::src_app_verify::CheckAppSignCertWithProfile(certType, binSignCert as *const crate::types::CertInfo, pf as *const crate::types::ProfileProf);
    if ret != crate::types::V_OK as i32 {
        let _ = unsafe { crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_ERROR,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: CheckAppSignCertWithProfile error: %d\0".as_ptr() as *const ::core::ffi::c_char,
            b"VerfiyAppSourceGetProfile\0".as_ptr() as *const ::core::ffi::c_char,
            1023i32,
            ret
        ) };
        crate::src_app_provision::ProfFreeData(pf);
        return crate::types::V_ERR_VERFIY_PROF_CERT as i32;
    }

    // FREE_IF_NOT_NULL(pf->bundleInfo.devCert)
    unsafe {
        if !(*pf).bundleInfo.devCert.is_null() {
            libc::free((*pf).bundleInfo.devCert as *mut ::core::ffi::c_void);
            (*pf).bundleInfo.devCert = std::ptr::null_mut();
        }
    }
    // FREE_IF_NOT_NULL(pf->bundleInfo.releaseCert)
    unsafe {
        if !(*pf).bundleInfo.releaseCert.is_null() {
            libc::free((*pf).bundleInfo.releaseCert as *mut ::core::ffi::c_void);
            (*pf).bundleInfo.releaseCert = std::ptr::null_mut();
        }
    }

    let _ = unsafe { crate::compat::HiLogPrint(
        crate::types::LOG_CORE,
        crate::types::LOG_INFO,
        0xD001100,
        b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
        b"[%s:%d]: verfiy app source success\0".as_ptr() as *const ::core::ffi::c_char,
        b"VerfiyAppSourceGetProfile\0".as_ptr() as *const ::core::ffi::c_char,
        1032i32
    ) };
    crate::types::V_OK as i32
}

fn VerifyAppSignPkcsData(fileRead: *const crate::types::FileRead, signInfo: *const crate::types::SignatureInfo, pkcs7Handle: *const crate::types::Pkcs7) -> i32 {
    let mut ret = crate::src_mbedtls_pkcs7::PKCS7_VerifyCertsChain(pkcs7Handle);
    if ret != crate::types::V_OK as i32 {
        let _ = unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Verify certs failed, ret: %d\0".as_ptr() as *const ::core::ffi::c_char,
                b"VerifyAppSignPkcsData\0".as_ptr() as *const ::core::ffi::c_char,
                1041i32,
                ret,
            )
        };
        return crate::types::V_ERR_VERIFY_CERT_CHAIN as i32;
    }
    let _ = unsafe {
        crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: Verify certs success\0".as_ptr() as *const ::core::ffi::c_char,
            b"VerifyAppSignPkcsData\0".as_ptr() as *const ::core::ffi::c_char,
            1044i32,
        )
    };

    ret = crate::src_app_verify::VerifyRawHash(signInfo, fileRead, pkcs7Handle);
    if ret != crate::types::V_OK as i32 {
        let _ = unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: VerifyRawHash failed : %d\0".as_ptr() as *const ::core::ffi::c_char,
                b"VerifyAppSignPkcsData\0".as_ptr() as *const ::core::ffi::c_char,
                1048i32,
                ret,
            )
        };
        return ret;
    }
    let _ = unsafe {
        crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: VerifyRawHash success\0".as_ptr() as *const ::core::ffi::c_char,
            b"VerifyAppSignPkcsData\0".as_ptr() as *const ::core::ffi::c_char,
            1051i32,
        )
    };

    let calc_digest_fn: crate::types::PKCS7_CalcDigest = unsafe {
        std::mem::transmute::<
            fn(*const crate::types::Pkcs7, *const crate::types::SignerInfo, crate::types::mbedtls_md_type_t, *mut ::core::ffi::c_uchar, *mut ::core::ffi::c_uint) -> i32,
            crate::types::PKCS7_CalcDigest
        >(crate::src_app_verify::CalcDigest)
    };
    ret = crate::src_mbedtls_pkcs7::PKCS7_VerifySignerSignature(pkcs7Handle, calc_digest_fn);
    if ret != crate::types::V_OK as i32 {
        let _ = unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: pkcs7 verify signer signature failed : %d\0".as_ptr() as *const ::core::ffi::c_char,
                b"VerifyAppSignPkcsData\0".as_ptr() as *const ::core::ffi::c_char,
                1055i32,
                ret,
            )
        };
        return crate::types::V_ERR_VERIFY_SIGNATURE as i32;
    }

    crate::types::V_OK as i32
}

fn GetBinSignPkcs(signBuf: *const std::ffi::c_char, len: i32) -> *mut crate::types::Pkcs7 {
    let pkcs7 = unsafe { libc::malloc(std::mem::size_of::<crate::types::Pkcs7>()) } as *mut crate::types::Pkcs7;
    if pkcs7.is_null() {
        return std::ptr::null_mut();
    }
    let ret = crate::src_mbedtls_pkcs7::PKCS7_ParseSignedData(
        signBuf as *const ::core::ffi::c_uchar,
        len as crate::types::size_t,
        pkcs7,
    );
    if ret != crate::types::V_OK as i32 {
        crate::src_mbedtls_pkcs7::PKCS7_FreeRes(pkcs7);
        unsafe {
            if !pkcs7.is_null() {
                libc::free(pkcs7 as *mut ::core::ffi::c_void);
            }
        }
        return std::ptr::null_mut();
    }
    pkcs7
}

fn GetFileRead(fp: i32, offset: i32, size: i32) -> *mut crate::types::FileRead {
    let fileRead = unsafe { libc::malloc(std::mem::size_of::<crate::types::FileRead>()) } as *mut crate::types::FileRead;
    if fileRead.is_null() {
        unsafe {
            HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: malloc error\0".as_ptr() as *const ::core::ffi::c_char,
                b"GetFileRead\0".as_ptr() as *const ::core::ffi::c_char,
                1084i32,
            );
        }
        return std::ptr::null_mut();
    }
    unsafe {
        (*fileRead).fp = fp;
        (*fileRead).offset = offset;
        (*fileRead).len = size;
    }
    fileRead
}

fn VerifyBinSign(signInfo: *mut crate::types::SignatureInfo, fp: i32, signCert: *mut *mut crate::types::CertInfo, certType: *mut i32) -> i32 {
    let mut blockLen: i32 = 0;
    let mut blockHead: crate::types::BlockHead = crate::types::BlockHead {
        type_: 0,
        length: 0,
        offset: 0,
    };
    let mut fileRead: *mut crate::types::FileRead = std::ptr::null_mut();
    let mut ret: i32;

    let signBuf = crate::src_app_verify::GetSignBlockByType(
        signInfo as *const crate::types::SignatureInfo,
        fp,
        crate::types::SIGNATURE_BLOCK_TYPE as i32,
        &mut blockLen,
        &mut blockHead,
    );

    if signBuf.is_null() {
        return crate::types::V_ERR_GET_SIGN_BLOCK as i32;
    }

    let pkcs7 = crate::src_app_verify::GetBinSignPkcs(signBuf as *const std::ffi::c_char, blockLen);
    if pkcs7.is_null() {
        if !signBuf.is_null() {
            unsafe { libc::free(signBuf as *mut ::core::ffi::c_void); }
        }
        return crate::types::V_ERR_PARSE_PKC7_DATA as i32;
    }

    fileRead = crate::src_app_verify::GetFileRead(fp, 0, blockHead.offset as i32);
    if fileRead.is_null() {
        ret = crate::types::V_ERR_MALLOC as i32;
    } else {
        ret = crate::src_app_verify::GetAppSingerCertType(pkcs7, certType);
        if ret != crate::types::V_OK as i32 {
            ret = crate::types::V_ERR_GET_CERT_TYPE as i32;
        } else {
            unsafe {
                (*signInfo).certType = *certType;
            }
            ret = crate::src_app_verify::VerifyAppSignPkcsData(
                fileRead as *const crate::types::FileRead,
                signInfo as *const crate::types::SignatureInfo,
                pkcs7 as *const crate::types::Pkcs7,
            );
            if ret != crate::types::V_OK as i32 {
                ret = crate::types::V_ERR_VERIFY_CERT_CHAIN as i32;
            } else {
                let crt = unsafe { (*pkcs7).signedData.signers.certPath.crt };
                ret = crate::src_app_verify::GetCertInfo(
                    crt as *const crate::types::mbedtls_x509_crt,
                    signCert,
                );
                if ret != crate::types::V_OK as i32 {
                    ret = crate::types::V_ERR_GET_CERT_INFO as i32;
                }
            }
        }
    }

    if !signBuf.is_null() {
        unsafe { libc::free(signBuf as *mut ::core::ffi::c_void); }
    }

    crate::src_mbedtls_pkcs7::PKCS7_FreeRes(pkcs7);
    if !pkcs7.is_null() {
        unsafe { libc::free(pkcs7 as *mut ::core::ffi::c_void); }
    }
    if !fileRead.is_null() {
        unsafe { libc::free(fileRead as *mut ::core::ffi::c_void); }
    }

    ret
}

fn VerifyIntegrity(signInfo: *mut crate::types::SignatureInfo, fp: i32, pf: *mut crate::types::ProfileProf) -> i32 {
    let mut binSignCert: *mut crate::types::CertInfo = std::ptr::null_mut();
    let mut certType: i32 = 0;

    let ret = crate::src_app_verify::VerifyBinSign(signInfo, fp, &mut binSignCert, &mut certType);
    if ret != crate::types::V_OK as i32 {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: verify bin sign error\0".as_ptr() as *const ::core::ffi::c_char,
                b"VerifyIntegrity\0".as_ptr() as *const ::core::ffi::c_char,
                1158i32,
            );
        }
        return ret;
    }

    let ret = crate::src_app_verify::VerfiyAppSourceGetProfile(fp, signInfo as *const crate::types::SignatureInfo, certType, binSignCert, pf);
    if ret != crate::types::V_OK as i32 {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: verify app source failed : %d\0".as_ptr() as *const ::core::ffi::c_char,
                b"VerifyIntegrity\0".as_ptr() as *const ::core::ffi::c_char,
                1164i32,
                ret,
            );
        }
        crate::src_app_verify::FreeCertInfo(binSignCert);
        if !binSignCert.is_null() {
            unsafe { libc::free(binSignCert as *mut ::core::ffi::c_void) };
        }
        return ret;
    }
    crate::src_app_verify::FreeCertInfo(binSignCert);
    if !binSignCert.is_null() {
        unsafe { libc::free(binSignCert as *mut ::core::ffi::c_void) };
    }
    crate::types::V_OK as i32
}

pub extern "C" fn APPVERI_AppVerify(filePath: *const ::core::ffi::c_char, verifyRst: *mut crate::types::VerifyResult) -> i32 {
    if filePath.is_null() || verifyRst.is_null() {
        return crate::types::V_ERR_FILE_OPEN as i32;
    }
    
    let mut handle: i32 = 0;
    let mut file: crate::types::FileRead = unsafe { std::mem::zeroed() };
    
    if crate::src_app_file::InitVerify(&mut file, filePath, &mut handle) != crate::types::V_OK as i32 {
        unsafe { libc::close(handle) };
        return crate::types::V_ERR_FILE_OPEN as i32;
    }
    
    let mut signInfo: crate::types::SignatureInfo = unsafe { std::mem::zeroed() };
    let mut ret = crate::src_app_verify::GetSignHead(&file as *const _, &mut signInfo);
    if ret != crate::types::V_OK as i32 {
        unsafe { crate::compat::HiLogPrint(crate::types::LOG_CORE, crate::types::LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const _, b"[%s:%d]: get sign head error\0".as_ptr() as *const _, b"APPVERI_AppVerify\0".as_ptr() as *const _, 1188i32) };
        unsafe { libc::close(handle) };
        return ret;
    }
    
    let mut signHead = unsafe { signInfo.signHead };
    ret = crate::src_app_verify::VerifyIntegrity(&mut signInfo, handle, unsafe { &mut (*verifyRst).profile });
    if ret != crate::types::V_OK as i32 {
        unsafe { crate::compat::HiLogPrint(crate::types::LOG_CORE, crate::types::LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const _, b"[%s:%d]: verify integrity failed\0".as_ptr() as *const _, b"APPVERI_AppVerify\0".as_ptr() as *const _, 1195i32) };
        unsafe { libc::close(handle) };
        if !signHead.is_null() {
            unsafe { libc::free(signHead as *mut _) };
        }
        return ret;
    }
    
    let fileSt: *mut crate::compat::stat = unsafe { libc::malloc(std::mem::size_of::<crate::compat::stat>()) as *mut crate::compat::stat };
    if fileSt.is_null() {
        unsafe { crate::compat::HiLogPrint(crate::types::LOG_CORE, crate::types::LOG_INFO, 0xD001100, b"appverify\0".as_ptr() as *const _, b"[%s:%d]: malloc error\0".as_ptr() as *const _, b"APPVERI_AppVerify\0".as_ptr() as *const _, 1202i32) };
        unsafe { libc::close(handle) };
        if !signHead.is_null() {
            unsafe { libc::free(signHead as *mut _) };
        }
        crate::src_app_provision::ProfFreeData(unsafe { &mut (*verifyRst).profile });
        return crate::types::V_ERR_MALLOC as i32;
    }
    
    ret = unsafe { libc::fstat(handle, fileSt as *mut libc::stat) };
    if ret != crate::types::V_OK as i32 {
        unsafe { crate::compat::HiLogPrint(crate::types::LOG_CORE, crate::types::LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const _, b"[%s:%d]: fstat error\0".as_ptr() as *const _, b"APPVERI_AppVerify\0".as_ptr() as *const _, 1210i32) };
        unsafe { libc::close(handle) };
        if !signHead.is_null() {
            unsafe { libc::free(signHead as *mut _) };
        }
        crate::src_app_provision::ProfFreeData(unsafe { &mut (*verifyRst).profile });
        if !fileSt.is_null() {
            unsafe { libc::free(fileSt as *mut _) };
        }
        return crate::types::V_ERR_FILE_STAT as i32;
    }
    
    let st_size_val = unsafe { (*fileSt).st_size } as i32;
    unsafe { crate::compat::HiLogPrint(crate::types::LOG_CORE, crate::types::LOG_INFO, 0xD001100, b"appverify\0".as_ptr() as *const _, b"[%s:%d]: file len: %d\0".as_ptr() as *const _, b"APPVERI_AppVerify\0".as_ptr() as *const _, 1217i32, st_size_val) };
    unsafe { libc::close(handle) };
    if !signHead.is_null() {
        unsafe { libc::free(signHead as *mut _) };
    }
    if !fileSt.is_null() {
        unsafe { libc::free(fileSt as *mut _) };
    }
    ret
}

pub extern "C" fn APPVERI_SetDebugMode(mode: bool) -> i32 {
    unsafe {
        let _ = crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: set debug mode: %d\0".as_ptr() as *const ::core::ffi::c_char,
            b"APPVERI_SetDebugMode\0".as_ptr() as *const ::core::ffi::c_char,
            1227i32,
            mode as i32,
        );
        
        let g_is_debug_mode_val: bool = crate::globals::g_isDebugMode != 0;
        if g_is_debug_mode_val == mode {
            return crate::types::V_OK as i32;
        }
        
        let ret = crate::src_mbedtls_pkcs7::PKCS7_EnableDebugMode(mode);
        if ret != crate::types::V_OK as i32 {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: enable pcks7 debug mode failed\0".as_ptr() as *const ::core::ffi::c_char,
                b"APPVERI_SetDebugMode\0".as_ptr() as *const ::core::ffi::c_char,
                1233i32,
            );
            return ret;
        }
        
        crate::globals::g_isDebugMode = mode as i32;
        crate::types::V_OK as i32
    }
}

pub extern "C" fn APPVERI_SetActsMode(mode: bool) {
    unsafe {
        g_isActsMode = mode;
    }
}

pub extern "C" fn APPVERI_IsActsMode() -> i32 {
    unsafe { crate::globals::g_isActsMode }
}

pub extern "C" fn APPVERI_FreeVerifyRst(verifyRst: *mut crate::types::VerifyResult) {
    if verifyRst.is_null() {
        return;
    }
    unsafe {
        crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: free verify rst data\0".as_ptr() as *const ::core::ffi::c_char,
            b"APPVERI_FreeVerifyRst\0".as_ptr() as *const ::core::ffi::c_char,
            1256i32,
        );
    }
    crate::src_app_provision::ProfFreeData(unsafe { &mut (*verifyRst).profile as *mut crate::types::ProfileProf });
}
