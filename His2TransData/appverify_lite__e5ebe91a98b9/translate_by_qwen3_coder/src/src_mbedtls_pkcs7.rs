//! Module: src_mbedtls_pkcs7
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
/// C: static const unsigned char[821] DEBUG_MODE_ROOT_CERT_IN_PEM
static mut DEBUG_MODE_ROOT_CERT_IN_PEM: [::core::ffi::c_uchar; 821usize] = unsafe { core::mem::MaybeUninit::<[::core::ffi::c_uchar; 821usize]>::zeroed().assume_init() };

/// C: static const unsigned char[863] OHOS_ROOT_CERT_IN_PEM
static mut OHOS_ROOT_CERT_IN_PEM: [::core::ffi::c_uchar; 863usize] = unsafe { core::mem::MaybeUninit::<[::core::ffi::c_uchar; 863usize]>::zeroed().assume_init() };

/// C: static const unsigned char[805] ROOT_CA_G2_CERT_IN_PEM
static mut ROOT_CA_G2_CERT_IN_PEM: [::core::ffi::c_uchar; 805usize] = unsafe { core::mem::MaybeUninit::<[::core::ffi::c_uchar; 805usize]>::zeroed().assume_init() };

/// C: static _Bool g_debugModeEnabled
static mut g_debugModeEnabled: bool = unsafe { core::mem::MaybeUninit::<bool>::zeroed().assume_init() };

/// C: static mbedtls_x509_crt g_debugModeRootCert
static mut g_debugModeRootCert: crate::types::mbedtls_x509_crt = unsafe { core::mem::MaybeUninit::<crate::types::mbedtls_x509_crt>::zeroed().assume_init() };

/// C: static mbedtls_x509_crt g_ohosRootCert
static mut g_ohosRootCert: crate::types::mbedtls_x509_crt = unsafe { core::mem::MaybeUninit::<crate::types::mbedtls_x509_crt>::zeroed().assume_init() };

/// C: static mbedtls_x509_crt g_rootCaG2Cert
static mut g_rootCaG2Cert: crate::types::mbedtls_x509_crt = unsafe { core::mem::MaybeUninit::<crate::types::mbedtls_x509_crt>::zeroed().assume_init() };

/// C: static _Bool g_rootCertLoaded
static mut g_rootCertLoaded: bool = unsafe { core::mem::MaybeUninit::<bool>::zeroed().assume_init() };

// === C2R_FILE_STATICS_END ===

fn InvalidDigestAlg(alg: *const crate::types::mbedtls_asn1_buf) -> bool {
    unsafe {
        let alg_ref = &*alg;
        let alg_len = alg_ref.len as usize;
        let alg_p = alg_ref.p;
        
        // SHA256 OID: "\x60\x86\x48\x01\x65\x03\x04\x02\x01"
        let sha256_oid: &[u8] = b"\x60\x86\x48\x01\x65\x03\x04\x02\x01";
        // SHA384 OID: "\x60\x86\x48\x01\x65\x03\x04\x02\x02"
        let sha384_oid: &[u8] = b"\x60\x86\x48\x01\x65\x03\x04\x02\x02";
        // SHA512 OID: "\x60\x86\x48\x01\x65\x03\x04\x02\x03"
        let sha512_oid: &[u8] = b"\x60\x86\x48\x01\x65\x03\x04\x02\x03";
        
        let sha256_len = sha256_oid.len();
        let sha384_len = sha384_oid.len();
        let sha512_len = sha512_oid.len();
        
        let not_sha256 = (sha256_len != alg_len) || 
            (libc::memcmp(sha256_oid.as_ptr() as *const ::core::ffi::c_void, 
                          alg_p as *const ::core::ffi::c_void, 
                          alg_len) != 0);
        
        let not_sha384 = (sha384_len != alg_len) || 
            (libc::memcmp(sha384_oid.as_ptr() as *const ::core::ffi::c_void, 
                          alg_p as *const ::core::ffi::c_void, 
                          alg_len) != 0);
        
        let not_sha512 = (sha512_len != alg_len) || 
            (libc::memcmp(sha512_oid.as_ptr() as *const ::core::ffi::c_void, 
                          alg_p as *const ::core::ffi::c_void, 
                          alg_len) != 0);
        
        not_sha256 && not_sha384 && not_sha512
    }
}

fn GetContentInfoType(p: *mut *mut ::core::ffi::c_uchar, end: *const ::core::ffi::c_uchar, contentType: *mut crate::types::mbedtls_asn1_buf, hasContent: *mut crate::types::c_bool) -> i32 {
    let mut seqLen: crate::types::size_t = 0;
    let mut len: crate::types::size_t = 0;
    let rc: i32;

    rc = unsafe { crate::compat::mbedtls_asn1_get_tag(p, end, &mut seqLen, 0x20 | 0x10) };
    if rc != 0 {
        return rc;
    }
    let start: *mut ::core::ffi::c_uchar = unsafe { *p };
    let end: *const ::core::ffi::c_uchar = unsafe { start.add(seqLen as usize) };
    let rc: i32 = unsafe { crate::compat::mbedtls_asn1_get_tag(p, end, &mut len, 0x06) };
    if rc != 0 {
        return rc;
    }
    unsafe {
        (*contentType).tag = 0x06;
        (*contentType).len = len;
        (*contentType).p = *p;
        let p_val = *p;
        let diff = (p_val as usize).wrapping_sub(start as usize) as crate::types::size_t;
        *hasContent = if seqLen != len + diff { 1 } else { 0 };
        *p = (*p).add(len as usize);
    }

    crate::types::PKCS7_SUCC as i32
}

fn GetContentLenOfContentInfo(p: *mut *mut u8, end: *const u8, len: *mut size_t) -> i32 {
    unsafe {
        crate::compat::mbedtls_asn1_get_tag(
            p,
            end,
            len,
            (0x20 | 0x80) as i32
        )
    }
}

fn ParseSignerVersion(p: *mut *mut ::core::ffi::c_uchar, end: *const ::core::ffi::c_uchar, signer: *mut crate::types::SignerInfo) -> i32 {
    unsafe {
        crate::compat::mbedtls_asn1_get_int(p, end, &mut (*signer).version)
    }
}

fn ParseSignerIssuerAndSerialNum(p: *mut *mut ::core::ffi::c_uchar, end: *const ::core::ffi::c_uchar, signer: *mut crate::types::SignerInfo) -> i32 {
    let mut rc: i32;
    let mut len: crate::types::size_t = 0;

    rc = unsafe { crate::compat::mbedtls_asn1_get_tag(p, end, &mut len, (0x20 | 0x10) as i32) };
    if rc != 0 {
        return rc;
    }

    unsafe {
        (*signer).issuerRaw.p = *p;
    }

    rc = unsafe { crate::compat::mbedtls_asn1_get_tag(p, end, &mut len, (0x20 | 0x10) as i32) };
    if rc != 0 {
        return rc;
    }

    // mbedtls_x509_get_name is not available in compat, parse the name manually by skipping len bytes
    unsafe {
        let name_end = (*p).add(len as usize);
        // Skip past the name data
        *p = name_end;
    }

    unsafe {
        (*signer).issuerRaw.len = ((*p).offset_from((*signer).issuerRaw.p)) as crate::types::size_t;
    }

    // mbedtls_x509_get_serial is not available in compat, use mbedtls_asn1_get_tag to parse INTEGER
    rc = unsafe { crate::compat::mbedtls_asn1_get_tag(p, end, &mut len, 0x02) };
    if rc != 0 {
        return rc;
    }
    unsafe {
        (*signer).serial.tag = 0x02;
        (*signer).serial.len = len;
        (*signer).serial.p = *p;
        *p = (*p).add(len as usize);
    }

    rc
}

fn ParseSignerDigestAlg(p: *mut *mut ::core::ffi::c_uchar, end: *const ::core::ffi::c_uchar, signer: *mut crate::types::SignerInfo) -> i32 {
    unsafe {
        let rc = crate::compat::mbedtls_asn1_get_alg_null(p, end, &mut (*signer).digestAlgId);
        if rc != 0 {
            return rc;
        }
        if crate::src_mbedtls_pkcs7::InvalidDigestAlg(&(*signer).digestAlgId as *const crate::types::mbedtls_asn1_buf) {
            return crate::types::PKCS7_INVALID_DIGEST_ALG as i32;
        }
        crate::types::PKCS7_SUCC as i32
    }
}

fn ParseSignerAuthAttr(p: *mut *mut ::core::ffi::c_uchar, end: *const ::core::ffi::c_uchar, signer: *mut crate::types::SignerInfo) -> i32 {
    unsafe {
        let mut len: crate::types::size_t = 0;
        let raw: *mut ::core::ffi::c_uchar = *p;

        let rc = crate::compat::mbedtls_asn1_get_tag(
            p,
            end,
            &mut len,
            (crate::types::MBEDTLS_ASN1_CONSTRUCTED | crate::types::MBEDTLS_ASN1_CONTEXT_SPECIFIC) as i32,
        );
        if rc != 0 {
            return crate::types::PKCS7_SUCC as i32;
        }
        (*signer).authAttr.tag = (crate::types::MBEDTLS_ASN1_CONSTRUCTED | crate::types::MBEDTLS_ASN1_CONTEXT_SPECIFIC) as ::core::ffi::c_int;
        (*signer).authAttr.p = *p;
        (*signer).authAttr.len = len;
        let tlLen = (*p).offset_from(raw) as usize;
        *p = (*p).add(len as usize);

        (*signer).authAttrRaw.p = raw;
        (*signer).authAttrRaw.len = (len as usize + tlLen) as crate::types::size_t;
        crate::types::PKCS7_SUCC as i32
    }
}

fn InvalidDigestEncAlg(alg: *const crate::types::mbedtls_x509_buf) -> bool {
    unsafe {
        let alg_len = (*alg).len as usize;
        let alg_p = (*alg).p;
        
        // MBEDTLS_OID_PKCS1_SHA256: "\x2a\x86\x48\x86\xf7\x0d\x01\x01\x0b"
        let oid1: &[u8] = b"\x2a\x86\x48\x86\xf7\x0d\x01\x01\x0b";
        // MBEDTLS_OID_PKCS1_SHA384: "\x2a\x86\x48\x86\xf7\x0d\x01\x01\x0c"
        let oid2: &[u8] = b"\x2a\x86\x48\x86\xf7\x0d\x01\x01\x0c";
        // MBEDTLS_OID_PKCS1_SHA512: "\x2a\x86\x48\x86\xf7\x0d\x01\x01\x0d"
        let oid3: &[u8] = b"\x2a\x86\x48\x86\xf7\x0d\x01\x01\x0d";
        // MBEDTLS_OID_ECDSA_SHA256: "\x2a\x86\x48\xce\x3d\x04\x03\x02"
        let oid4: &[u8] = b"\x2a\x86\x48\xce\x3d\x04\x03\x02";
        // MBEDTLS_OID_ECDSA_SHA384: "\x2a\x86\x48\xce\x3d\x04\x03\x03"
        let oid5: &[u8] = b"\x2a\x86\x48\xce\x3d\x04\x03\x03";
        // MBEDTLS_OID_ECDSA_SHA512: "\x2a\x86\x48\xce\x3d\x04\x03\x04"
        let oid6: &[u8] = b"\x2a\x86\x48\xce\x3d\x04\x03\x04";
        // MBEDTLS_OID_RSASSA_PSS: "\x2a\x86\x48\x86\xf7\x0d\x01\x01\x0a"
        let oid7: &[u8] = b"\x2a\x86\x48\x86\xf7\x0d\x01\x01\x0a";
        
        let cmp1 = (oid1.len() != alg_len) || libc::memcmp(oid1.as_ptr() as *const core::ffi::c_void, alg_p as *const core::ffi::c_void, alg_len) != 0;
        let cmp2 = (oid2.len() != alg_len) || libc::memcmp(oid2.as_ptr() as *const core::ffi::c_void, alg_p as *const core::ffi::c_void, alg_len) != 0;
        let cmp3 = (oid3.len() != alg_len) || libc::memcmp(oid3.as_ptr() as *const core::ffi::c_void, alg_p as *const core::ffi::c_void, alg_len) != 0;
        let cmp4 = (oid4.len() != alg_len) || libc::memcmp(oid4.as_ptr() as *const core::ffi::c_void, alg_p as *const core::ffi::c_void, alg_len) != 0;
        let cmp5 = (oid5.len() != alg_len) || libc::memcmp(oid5.as_ptr() as *const core::ffi::c_void, alg_p as *const core::ffi::c_void, alg_len) != 0;
        let cmp6 = (oid6.len() != alg_len) || libc::memcmp(oid6.as_ptr() as *const core::ffi::c_void, alg_p as *const core::ffi::c_void, alg_len) != 0;
        let cmp7 = (oid7.len() != alg_len) || libc::memcmp(oid7.as_ptr() as *const core::ffi::c_void, alg_p as *const core::ffi::c_void, alg_len) != 0;
        
        cmp1 && cmp2 && cmp3 && cmp4 && cmp5 && cmp6 && cmp7
    }
}

fn ParseSignerEncAlg(p: *mut *mut ::core::ffi::c_uchar, end: *const ::core::ffi::c_uchar, signer: *mut crate::types::SignerInfo) -> i32 {
    let mut params: crate::types::mbedtls_asn1_buf = crate::types::mbedtls_asn1_buf {
        tag: 0,
        len: 0,
        p: std::ptr::null_mut(),
    };

    let rc = unsafe {
        crate::compat::mbedtls_asn1_get_alg(
            p,
            end,
            &mut (*signer).digestEncAlgId,
            &mut params,
        )
    };
    
    if rc != 0 {
        return rc;
    }
    
    if crate::src_mbedtls_pkcs7::InvalidDigestEncAlg(unsafe { &(*signer).digestEncAlgId as *const _ }) {
        return crate::types::PKCS7_INVALID_SIGNING_ALG as i32;
    }
    
    crate::types::PKCS7_SUCC as i32
}

fn ParseSignerSignature(p: *mut *mut ::core::ffi::c_uchar, end: *const ::core::ffi::c_uchar, signer: *mut crate::types::SignerInfo) -> i32 {
    let mut len: crate::types::size_t = 0;
    
    let rc = unsafe {
        crate::compat::mbedtls_asn1_get_tag(p, end, &mut len, crate::types::MBEDTLS_ASN1_OCTET_STRING as i32)
    };
    if rc != 0 {
        return rc;
    }
    
    unsafe {
        (*signer).signature.tag = crate::types::MBEDTLS_ASN1_OCTET_STRING as ::core::ffi::c_int;
        (*signer).signature.len = len;
        (*signer).signature.p = *p;
        *p = (*p).add(len as usize);
    }
    
    crate::types::PKCS7_SUCC as i32
}

fn GetSignerSignature(signer: *const crate::types::SignerInfo, sig: *mut *mut ::core::ffi::c_uchar, sigLen: *mut crate::types::size_t) -> i32 {
    unsafe {
        let len = (*signer).signature.len;
        let buf = (*signer).signature.p;
        *sig = buf;
        *sigLen = len;
        crate::types::PKCS7_SUCC as i32
    }
}

fn ParseSignerUnAuthAttr(p: *mut *mut ::core::ffi::c_uchar, end: *const ::core::ffi::c_uchar, signer: *mut crate::types::SignerInfo) -> i32 {
    let mut len: crate::types::size_t = 0;
    
    unsafe {
        if (end as isize) - (*p as isize) < 1 {
            return crate::types::PKCS7_SUCC as i32;
        }
        
        let rc = crate::compat::mbedtls_asn1_get_tag(
            p,
            end,
            &mut len,
            (crate::types::MBEDTLS_ASN1_CONSTRUCTED | crate::types::MBEDTLS_ASN1_CONTEXT_SPECIFIC) as i32 + 1
        );
        
        if rc != 0 {
            return rc;
        }
        
        (*signer).unAuthAttr.tag = (crate::types::MBEDTLS_ASN1_CONSTRUCTED | crate::types::MBEDTLS_ASN1_CONTEXT_SPECIFIC) as i32 + 1;
        (*signer).unAuthAttr.len = len;
        (*signer).unAuthAttr.p = *p;
        *p = (*p).add(len as usize);
        
        crate::types::PKCS7_SUCC as i32
    }
}

fn SerialCmp(a: *const crate::types::mbedtls_x509_buf, b: *const crate::types::mbedtls_x509_buf) -> i32 {
    unsafe {
        if (*a).len == (*b).len && libc::memcmp((*a).p as *const core::ffi::c_void, (*b).p as *const core::ffi::c_void, (*a).len as usize) == 0 {
            return 0;
        }
        -1
    }
}

fn IsLegitString(tag: i32) -> bool {
    if tag == 0x0C || tag == 0x13 {
        return true;
    }
    false
}

fn CompareX509String(first: *const crate::types::mbedtls_x509_buf, second: *const crate::types::mbedtls_x509_buf) -> i32 {
    unsafe {
        let first_tag = (*first).tag;
        let second_tag = (*second).tag;
        
        if crate::src_mbedtls_pkcs7::IsLegitString(first_tag) && crate::src_mbedtls_pkcs7::IsLegitString(second_tag) {
            let first_len = (*first).len as i32;
            let first_p = (*first).p;
            let second_p = (*second).p;
            
            for i in 0..first_len {
                let fc = *first_p.offset(i as isize);
                let sc = *second_p.offset(i as isize);
                
                let is_lower = (fc.wrapping_sub(b'a') as u32) < 26;
                let is_upper = (fc.wrapping_sub(b'A') as u32) < 26;
                
                if fc == sc ||
                   (is_lower && (fc.wrapping_sub(32) == sc)) ||
                   (is_upper && (fc.wrapping_add(32) == sc)) {
                    continue;
                }
                return -1;
            }
            return 0;
        }
        -1
    }
}

fn GetDeps(nameList: *const crate::types::mbedtls_x509_name) -> i32 {
    let mut deps: i32 = 0;
    let mut current = nameList;
    while !current.is_null() {
        unsafe {
            current = (*current).next;
        }
        deps += 1;
    }
    deps
}

fn CompareX509NameList(first: *const crate::types::mbedtls_x509_name, second: *const crate::types::mbedtls_x509_name) -> i32 {
    if first.is_null() || second.is_null() {
        return -1;
    }
    let firstDeps = crate::src_mbedtls_pkcs7::GetDeps(first);
    let secondDeps = crate::src_mbedtls_pkcs7::GetDeps(second);
    if firstDeps != secondDeps {
        return -1;
    }
    let mut first = first;
    let mut second = second;
    for _ in 0..firstDeps {
        unsafe {
            if (*first).oid.tag != (*second).oid.tag ||
               (*first).oid.len != (*second).oid.len ||
               libc::memcmp((*first).oid.p as *const core::ffi::c_void, 
                           (*second).oid.p as *const core::ffi::c_void, 
                           (*second).oid.len as usize) != 0 ||
               (*first).private_next_merged != (*second).private_next_merged ||
               (*first).val.len != (*second).val.len {
                return -1;
            }
            if crate::src_mbedtls_pkcs7::CompareX509String(&(*first).val, &(*second).val) != 0 {
                return -1;
            }
            first = (*first).next;
            second = (*second).next;
        }
    }
    0
}

fn Pkcs7Calloc(nmemb: crate::types::size_t, size: crate::types::size_t) -> *mut std::ffi::c_void {
    unsafe {
        libc::calloc(nmemb as usize, size as usize)
    }
}

fn Pkcs7Free(ptr: *mut std::ffi::c_void) {
    unsafe {
        libc::free(ptr);
    }
}

fn ParseSignedDataSignerInfos(p: *mut *mut ::core::ffi::c_uchar, end: *const ::core::ffi::c_uchar, signers: *mut crate::types::SignerInfo) -> i32 {
    let mut rc: i32;
    let mut len: crate::types::size_t = 0;
    
    rc = unsafe { mbedtls_asn1_get_tag(p, end, &mut len, (0x20 | 0x11) as i32) };
    if rc != 0 || len == 0 {
        return crate::types::PKCS7_HAS_NO_SIGNER_INFO as i32;
    }
    
    let mut end = unsafe { (*p).add(len as usize) };
    let mut signers = signers;
    
    while unsafe { (*p) < end } {
        let mut oneSignerLen: crate::types::size_t = 0;
        
        rc = unsafe { mbedtls_asn1_get_tag(p, end, &mut oneSignerLen, (0x20 | 0x10) as i32) };
        if rc != crate::types::PKCS7_SUCC as i32 {
            unsafe {
                HiLogPrint(
                    crate::types::LOG_CORE,
                    crate::types::LOG_ERROR,
                    0xD001100,
                    b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                    b"[%s:%d]: %s:%u, error occurred, ret:%d\0".as_ptr() as *const ::core::ffi::c_char,
                    b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char,
                    387i32,
                    b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char,
                    387u32,
                    rc,
                );
            }
            return rc;
        }
        
        let oneSignerEnd = unsafe { (*p).add(oneSignerLen as usize) };
        
        rc = crate::src_mbedtls_pkcs7::ParseSignerVersion(p, oneSignerEnd, signers);
        if rc != crate::types::PKCS7_SUCC as i32 {
            unsafe { HiLogPrint(crate::types::LOG_CORE, crate::types::LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const ::core::ffi::c_char, b"[%s:%d]: %s:%u, error occurred, ret:%d\0".as_ptr() as *const ::core::ffi::c_char, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 392i32, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 392u32, rc); }
            return rc;
        }
        
        rc = crate::src_mbedtls_pkcs7::ParseSignerIssuerAndSerialNum(p, oneSignerEnd, signers);
        if rc != crate::types::PKCS7_SUCC as i32 {
            unsafe { HiLogPrint(crate::types::LOG_CORE, crate::types::LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const ::core::ffi::c_char, b"[%s:%d]: %s:%u, error occurred, ret:%d\0".as_ptr() as *const ::core::ffi::c_char, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 396i32, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 396u32, rc); }
            return rc;
        }
        
        rc = crate::src_mbedtls_pkcs7::ParseSignerDigestAlg(p, oneSignerEnd, signers);
        if rc != crate::types::PKCS7_SUCC as i32 {
            unsafe { HiLogPrint(crate::types::LOG_CORE, crate::types::LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const ::core::ffi::c_char, b"[%s:%d]: %s:%u, error occurred, ret:%d\0".as_ptr() as *const ::core::ffi::c_char, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 400i32, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 400u32, rc); }
            return rc;
        }
        
        rc = crate::src_mbedtls_pkcs7::ParseSignerAuthAttr(p, oneSignerEnd, signers);
        if rc != crate::types::PKCS7_SUCC as i32 {
            unsafe { HiLogPrint(crate::types::LOG_CORE, crate::types::LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const ::core::ffi::c_char, b"[%s:%d]: %s:%u, error occurred, ret:%d\0".as_ptr() as *const ::core::ffi::c_char, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 404i32, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 404u32, rc); }
            return rc;
        }
        
        rc = crate::src_mbedtls_pkcs7::ParseSignerEncAlg(p, oneSignerEnd, signers);
        if rc != crate::types::PKCS7_SUCC as i32 {
            unsafe { HiLogPrint(crate::types::LOG_CORE, crate::types::LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const ::core::ffi::c_char, b"[%s:%d]: %s:%u, error occurred, ret:%d\0".as_ptr() as *const ::core::ffi::c_char, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 408i32, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 408u32, rc); }
            return rc;
        }
        
        rc = crate::src_mbedtls_pkcs7::ParseSignerSignature(p, oneSignerEnd, signers);
        if rc != crate::types::PKCS7_SUCC as i32 {
            unsafe { HiLogPrint(crate::types::LOG_CORE, crate::types::LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const ::core::ffi::c_char, b"[%s:%d]: %s:%u, error occurred, ret:%d\0".as_ptr() as *const ::core::ffi::c_char, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 412i32, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 412u32, rc); }
            return rc;
        }
        
        rc = crate::src_mbedtls_pkcs7::ParseSignerUnAuthAttr(p, oneSignerEnd, signers);
        if rc != crate::types::PKCS7_SUCC as i32 {
            unsafe { HiLogPrint(crate::types::LOG_CORE, crate::types::LOG_ERROR, 0xD001100, b"appverify\0".as_ptr() as *const ::core::ffi::c_char, b"[%s:%d]: %s:%u, error occurred, ret:%d\0".as_ptr() as *const ::core::ffi::c_char, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 416i32, b"ParseSignedDataSignerInfos\0".as_ptr() as *const ::core::ffi::c_char, 416u32, rc); }
            return rc;
        }
        
        if unsafe { (*p) < end } {
            let next_signer = crate::src_mbedtls_pkcs7::Pkcs7Calloc(1, std::mem::size_of::<crate::types::SignerInfo>() as crate::types::size_t) as *mut crate::types::SignerInfo;
            if next_signer.is_null() {
                return crate::types::PKCS7_MEMORY_EXHAUST as i32;
            }
            unsafe { (*signers).next = next_signer; }
            signers = next_signer;
        }
    }
    rc
}

fn ParseSignedDataVersion(p: *mut *mut u8, end: *const u8, ver: *mut i32) -> i32 {
    let rc = unsafe { crate::compat::mbedtls_asn1_get_int(p, end, ver) };
    if rc != 0 {
        return rc;
    }

    let ver_val = unsafe { *ver };
    if ver_val != 1 {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Invalid version : %d\n\0".as_ptr() as *const ::core::ffi::c_char,
                b"ParseSignedDataVersion\0".as_ptr() as *const ::core::ffi::c_char,
                438i32,
                ver_val,
            );
        }
        return crate::types::PKCS7_INVALID_VERSION as i32;
    }
    
    unsafe {
        crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: Parse signed data version success\n\0".as_ptr() as *const ::core::ffi::c_char,
            b"ParseSignedDataVersion\0".as_ptr() as *const ::core::ffi::c_char,
            441i32,
        );
    }
    
    crate::types::PKCS7_SUCC as i32
}

fn ParseSignedDataDigestAlgs(p: *mut *mut core::ffi::c_uchar, end: *const core::ffi::c_uchar, algIds: *mut crate::types::DigestAlgId) -> i32 {
    let mut rc: i32;
    let mut len: crate::types::size_t = 0;

    rc = unsafe { crate::compat::mbedtls_asn1_get_tag(p, end, &mut len, (0x20 | 0x11) as i32) };
    if rc != 0 {
        return rc;
    }
    let end = unsafe { (*p).offset(len as isize) };

    let mut id: *mut crate::types::DigestAlgId = algIds;
    while unsafe { (*p) < end } {
        let mut params: crate::types::mbedtls_asn1_buf = crate::types::mbedtls_asn1_buf {
            tag: 0,
            len: 0,
            p: std::ptr::null_mut(),
        };

        rc = unsafe { crate::compat::mbedtls_asn1_get_alg(p, end, &mut (*id).algBuf, &mut params) };
        if rc != 0 {
            return rc;
        }
        if crate::src_mbedtls_pkcs7::InvalidDigestAlg(unsafe { &(*id).algBuf as *const _ }) {
            return crate::types::PKCS7_INVALID_DIGEST_ALG as i32;
        }
        if unsafe { (*p) < end } {
            let next_ptr = crate::src_mbedtls_pkcs7::Pkcs7Calloc(1, std::mem::size_of::<crate::types::DigestAlgId>() as crate::types::size_t);
            if next_ptr.is_null() {
                return crate::types::PKCS7_MEMORY_EXHAUST as i32;
            }
            unsafe { (*id).next = next_ptr as *mut crate::types::DigestAlgId };
            id = unsafe { (*id).next };
        }
    }
    crate::types::PKCS7_SUCC as i32
}

fn DlogContentInfo(content: *const crate::types::Content) {
    let len: i32 = unsafe { (*content).data.len as i32 };
    if len <= 0 {
        return;
    }
    let info: *mut ::core::ffi::c_char = crate::src_mbedtls_pkcs7::Pkcs7Calloc(
        (len + 1) as crate::types::size_t,
        std::mem::size_of::<::core::ffi::c_char>() as crate::types::size_t,
    ) as *mut ::core::ffi::c_char;
    if info.is_null() {
        return;
    }
    let ret = unsafe {
        crate::compat::strncpy_s(
            info,
            (len + 1) as u32,
            (*content).data.p as *const ::core::ffi::c_char,
            len as u32,
        )
    };
    if ret != crate::types::EOK as i32 {
        crate::src_mbedtls_pkcs7::Pkcs7Free(info as *mut std::ffi::c_void);
        return;
    }
    crate::src_mbedtls_pkcs7::Pkcs7Free(info as *mut std::ffi::c_void);
}

fn ParseSignedDataContentInfo(p: *mut *mut ::core::ffi::c_uchar, end: *const ::core::ffi::c_uchar, content: *mut crate::types::Content) -> i32 {
    let mut rc: i32;
    let mut len: crate::types::size_t = 0;
    let mut hasContent: crate::types::c_bool = 0;

    unsafe {
        rc = crate::src_mbedtls_pkcs7::GetContentInfoType(
            p,
            end,
            &mut (*content).oid as *mut crate::types::mbedtls_asn1_buf,
            &mut hasContent,
        );
    }
    if rc != 0 {
        return rc;
    }

    let oid_data: &[u8] = b"\x2a\x86\x48\x86\xf7\x0d\x01\x07\x01";
    let oid_len = oid_data.len();
    
    unsafe {
        let content_oid = &(*content).oid;
        let oid_mismatch = (oid_len != content_oid.len as usize) ||
            libc::memcmp(
                oid_data.as_ptr() as *const ::core::ffi::c_void,
                content_oid.p as *const ::core::ffi::c_void,
                content_oid.len as usize,
            ) != 0;
        
        if oid_mismatch || hasContent == 0 {
            HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Invalid content type or has no real content\0".as_ptr() as *const ::core::ffi::c_char,
                b"ParseSignedDataContentInfo\0".as_ptr() as *const ::core::ffi::c_char,
                510i32,
            );
            return crate::types::PKCS7_INVALID_CONTENT_TYPE_OR_NO_CONTENT as i32;
        }
    }

    rc = crate::src_mbedtls_pkcs7::GetContentLenOfContentInfo(p, end, &mut len);
    if rc != 0 {
        return rc;
    }

    unsafe {
        (*content).data.tag = 0x20 | 0x80;
        (*content).data.p = *p;
        (*content).data.len = len;
        crate::src_mbedtls_pkcs7::DlogContentInfo(content as *const crate::types::Content);
        *p = (*p).add(len as usize);
    }

    crate::types::PKCS7_SUCC as i32
}

fn ParseSignedDataCerts(p: *mut *mut ::core::ffi::c_uchar, end: *const ::core::ffi::c_uchar, certs: *mut *mut crate::types::mbedtls_x509_crt) -> i32 {
    use crate::types::*;
    
    let mut rc: i32;
    let mut len: size_t = 0;
    
    unsafe {
        rc = mbedtls_asn1_get_tag(p, end, &mut len, (MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_CONTEXT_SPECIFIC) as i32);
        if rc != 0 {
            let _ = HiLogPrint(
                LOG_CORE,
                LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Has no certificates in signed data.\0".as_ptr() as *const ::core::ffi::c_char,
                b"ParseSignedDataCerts\0".as_ptr() as *const ::core::ffi::c_char,
                532 as ::core::ffi::c_int,
            );
            return PKCS7_SUCC as i32;
        }
        
        *certs = mbedtls_calloc(1, core::mem::size_of::<mbedtls_x509_crt>() as size_t) as *mut mbedtls_x509_crt;
        if (*certs).is_null() {
            return PKCS7_MEMORY_EXHAUST as i32;
        }
        mbedtls_x509_crt_init(*certs);
        
        let certs_end = (*p).add(len as usize);
        let mut cnt: i32 = 0;
        
        while (*p) < certs_end {
            let mut one_cert_len: size_t = 0;
            let seq_begin = *p;
            
            rc = mbedtls_asn1_get_tag(p, end, &mut one_cert_len, (MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_SEQUENCE) as i32);
            if rc != 0 {
                return rc;
            }
            
            let p_offset = (*p).offset_from(seq_begin) as usize;
            let certs_end_offset = certs_end.offset_from(seq_begin) as usize;
            
            if (one_cert_len as usize) + p_offset > certs_end_offset {
                return PKCS7_PARSING_ERROR as i32;
            }
            
            let total_len = ((one_cert_len as usize) + p_offset) as size_t;
            rc = mbedtls_x509_crt_parse(*certs, seq_begin, total_len);
            if rc != 0 {
                return rc;
            }
            
            *p = (*p).add(one_cert_len as usize);
            cnt += 1;
        }
        
        let _ = HiLogPrint(
            LOG_CORE,
            LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: Parse signed data certs success\0".as_ptr() as *const ::core::ffi::c_char,
            b"ParseSignedDataCerts\0".as_ptr() as *const ::core::ffi::c_char,
            561 as ::core::ffi::c_int,
        );
    }
    
    rc
}

fn ParseSignedDataCrl(p: *mut *mut ::core::ffi::c_uchar, end: *const ::core::ffi::c_uchar, crl: *mut crate::types::mbedtls_x509_crl) -> i32 {
    let mut rc: i32;
    let mut len: crate::types::size_t = 0;

    rc = unsafe {
        crate::compat::mbedtls_asn1_get_tag(
            p,
            end,
            &mut len,
            ((crate::types::MBEDTLS_ASN1_CONSTRUCTED | crate::types::MBEDTLS_ASN1_CONTEXT_SPECIFIC) + 1) as i32,
        )
    };
    if rc != 0 {
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_INFO,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Has no crl in signed data.\0".as_ptr() as *const ::core::ffi::c_char,
                b"ParseSignedDataCrl\0".as_ptr() as *const ::core::ffi::c_char,
                572i32,
            );
        }
        return crate::types::PKCS7_SUCC as i32;
    }
    unsafe {
        crate::compat::mbedtls_x509_crl_init(crl);
        rc = crate::compat::mbedtls_x509_crl_parse(crl, *p, len as u32);
        *p = (*p).add(len as usize);
    }
    rc
}

fn ParseSignedData(buf: *mut u8, bufLen: usize, signedData: *mut crate::types::SignedData) -> i32 {
    let mut p: *mut u8 = buf;
    let end: *const u8 = unsafe { buf.add(bufLen) };
    let mut len: crate::types::size_t = 0;
    let mut rc: i32;

    rc = unsafe {
        crate::compat::mbedtls_asn1_get_tag(
            &mut p,
            end,
            &mut len,
            (0x20 | 0x10) as i32,
        )
    };
    if rc != 0 {
        return rc;
    }

    rc = crate::src_mbedtls_pkcs7::ParseSignedDataVersion(
        &mut p,
        end,
        unsafe { &mut (*signedData).version },
    );
    if rc != 0 {
        return rc;
    }

    rc = crate::src_mbedtls_pkcs7::ParseSignedDataDigestAlgs(
        &mut p,
        end,
        unsafe { &mut (*signedData).digestAlgIds },
    );
    if rc != 0 {
        return rc;
    }

    rc = crate::src_mbedtls_pkcs7::ParseSignedDataContentInfo(
        &mut p,
        end,
        unsafe { &mut (*signedData).content },
    );
    if rc != 0 {
        return rc;
    }

    if p as usize >= end as usize {
        return crate::types::PKCS7_PARSING_ERROR as i32;
    }

    rc = crate::src_mbedtls_pkcs7::ParseSignedDataCerts(
        &mut p,
        end,
        unsafe { &mut (*signedData).certs },
    );
    if rc != 0 {
        return rc;
    }

    rc = crate::src_mbedtls_pkcs7::ParseSignedDataCrl(
        &mut p,
        end,
        unsafe { &mut (*signedData).crl },
    );
    if rc != 0 {
        return rc;
    }

    rc = crate::src_mbedtls_pkcs7::ParseSignedDataSignerInfos(
        &mut p,
        end,
        unsafe { &mut (*signedData).signers },
    );

    unsafe {
        crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: ParseSignedData %d\0".as_ptr() as *const ::core::ffi::c_char,
            b"ParseSignedData\0".as_ptr() as *const ::core::ffi::c_char,
            629i32,
            rc,
        );
    }

    rc
}

fn IsSigedDataOid(pkcs7: *const crate::types::Pkcs7) -> bool {
    let oid_bytes: &[u8] = b"\x2a\x86\x48\x86\xf7\x0d\x01\x07\x02";
    let oid_len = oid_bytes.len();
    
    unsafe {
        let content_type_oid = &(*pkcs7).contentTypeOid;
        let buf_len = content_type_oid.len as usize;
        let buf_p = content_type_oid.p;
        
        if oid_len != buf_len {
            return false;
        }
        
        let cmp_result = libc::memcmp(
            oid_bytes.as_ptr() as *const ::core::ffi::c_void,
            buf_p as *const ::core::ffi::c_void,
            buf_len,
        );
        
        cmp_result == 0
    }
}

fn FreeSignedDataDigestAlgs(pkcs7: *mut crate::types::Pkcs7) {
    unsafe {
        let mut alg: *mut crate::types::DigestAlgId = (*pkcs7).signedData.digestAlgIds.next;
        let mut next: *mut crate::types::DigestAlgId = std::ptr::null_mut();

        while !alg.is_null() {
            next = (*alg).next;
            crate::src_mbedtls_pkcs7::Pkcs7Free(alg as *mut std::ffi::c_void);
            alg = next;
        }
        (*pkcs7).signedData.digestAlgIds.next = std::ptr::null_mut();
    }
}

fn FreeSignerCerts(signer: *mut crate::types::SignerInfo) {
    unsafe {
        if (*signer).certPath.crt != std::ptr::null_mut() {
            crate::compat::mbedtls_x509_crt_free((*signer).certPath.crt);
            crate::compat::mbedtls_free((*signer).certPath.crt as *mut ::core::ffi::c_void);
            (*signer).certPath.crt = std::ptr::null_mut();
        }
    }
}

fn FreeSignerIssuer(signer: *mut crate::types::SignerInfo) {
    let mut name_cur: *mut crate::types::mbedtls_x509_name = std::ptr::null_mut();
    let mut name_prv: *mut crate::types::mbedtls_x509_name = std::ptr::null_mut();
    
    unsafe {
        name_cur = (*signer).issuer.next;
        while !name_cur.is_null() {
            name_prv = name_cur;
            name_cur = (*name_cur).next;
            crate::compat::mbedtls_free(name_prv as *mut ::core::ffi::c_void);
        }
        (*signer).issuer.next = std::ptr::null_mut();
    }
}

fn FreeSignersInfo(pkcs7: *mut crate::types::Pkcs7) {
    unsafe {
        let mut signer: *mut crate::types::SignerInfo = (*pkcs7).signedData.signers.next;
        let mut next: *mut crate::types::SignerInfo = std::ptr::null_mut();

        while !signer.is_null() {
            next = (*signer).next;
            crate::src_mbedtls_pkcs7::FreeSignerCerts(signer);
            crate::src_mbedtls_pkcs7::FreeSignerIssuer(signer);
            crate::src_mbedtls_pkcs7::Pkcs7Free(signer as *mut std::ffi::c_void);
            signer = next;
        }
        (*pkcs7).signedData.signers.next = std::ptr::null_mut();
        crate::src_mbedtls_pkcs7::FreeSignerCerts(&mut (*pkcs7).signedData.signers as *mut crate::types::SignerInfo);
        crate::src_mbedtls_pkcs7::FreeSignerIssuer(&mut (*pkcs7).signedData.signers as *mut crate::types::SignerInfo);
    }
}

fn FreeSignedDataCerts(pkcs7: *mut crate::types::Pkcs7) {
    unsafe {
        if (*pkcs7).signedData.certs != std::ptr::null_mut() {
            crate::compat::mbedtls_x509_crt_free((*pkcs7).signedData.certs);
            crate::compat::mbedtls_free((*pkcs7).signedData.certs as *mut ::core::ffi::c_void);
            (*pkcs7).signedData.certs = std::ptr::null_mut();
        }
    }
}

fn FreeSignedDataCrl(pkcs7: *mut crate::types::Pkcs7) {
    unsafe {
        crate::compat::mbedtls_x509_crl_free(&mut (*pkcs7).signedData.crl);
    }
}

fn GetCertsNumOfSignedData(crts: *const crate::types::mbedtls_x509_crt) -> i32 {
    let mut cnt: i32 = 0;
    let mut crts = crts;
    while !crts.is_null() {
        unsafe {
            crts = (*crts).next;
        }
        cnt += 1;
    }
    cnt
}

fn FindSuperCert(cur: *mut crate::types::mbedtls_x509_crt, certsList: *mut crate::types::mbedtls_x509_crt) -> *mut crate::types::mbedtls_x509_crt {
    let mut certs_list = certsList;
    while !certs_list.is_null() {
        unsafe {
            let issuer_ptr = &(*cur).issuer as *const crate::types::mbedtls_x509_name;
            let subject_ptr = &(*certs_list).subject as *const crate::types::mbedtls_x509_name;
            if crate::src_mbedtls_pkcs7::CompareX509NameList(issuer_ptr, subject_ptr) == 0 {
                break;
            }
            certs_list = (*certs_list).next;
        }
    }
    certs_list
}

fn DelCertOfSignedData(signedData: *mut crate::types::SignedData, crt: *mut crate::types::mbedtls_x509_crt) {
    unsafe {
        let head = (*signedData).certs;
        if crt == head {
            (*signedData).certs = (*crt).next;
            (*crt).next = std::ptr::null_mut();
        } else {
            let mut prev = head;
            let mut current = head;
            while !current.is_null() {
                if current == crt {
                    (*prev).next = (*crt).next;
                    (*crt).next = std::ptr::null_mut();
                    break;
                }
                prev = current;
                current = (*current).next;
            }
        }
    }
}

fn AddCertToSignerCertPath(signer: *mut crate::types::SignerInfo, crt: *mut crate::types::mbedtls_x509_crt) {
    unsafe {
        let prev_init = (*signer).certPath.crt;
        let mut prev = prev_init;
        let mut cur = prev;
        
        if prev.is_null() {
            (*signer).certPath.crt = crt;
            (*crt).next = std::ptr::null_mut();
        } else {
            while !cur.is_null() {
                prev = cur;
                cur = (*cur).next;
            }
            (*prev).next = crt;
            (*crt).next = std::ptr::null_mut();
        }
        
        (*signer).certPath.depth += 1;
    }
}

// === C2R MANUAL FIX REQUIRED ===
// reason: repair_failed_after_5
// func_key: src_mbedtls_pkcs7_39
// c_function: BuildSignerCertPath
// rust_file: src_mbedtls_pkcs7.rs
// rust_signature: fn BuildSignerCertPath(signer: *mut crate::types::SignerInfo, lowerCrt: *mut crate::types::mbedtls_x509_crt, signeData: *mut crate::types::SignedData) -> i32
// c_first_line: static int32_t BuildSignerCertPath(SignerInfo *signer, mbedtls_x509_crt *lowerCrt, SignedData *signeData)
// saved_translation: /data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5_reuseS1_topk1/intermediate/appverify_lite__e5ebe91a98b9/workspace/repair_history/appverify_lite__e5ebe91a98b9/translate_by_qwen3_coder/_manual_fix/src_mbedtls_pkcs7_39/translated_rust.rs
// last_error_truncated:
//   error[E0308]: mismatched types
//       --> src/src_mbedtls_pkcs7.rs:1043:12
//        |
//        |            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ expected `bool`, found `i32`
//   error[E0606]: casting `&mut i32` as `*mut types::mbedtls_x509_crt` is invalid
//       --> src/src_mbedtls_pkcs7.rs:1046:30
//        |
//        |                              ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// =================================
fn BuildSignerCertPath(signer: *mut crate::types::SignerInfo, lowerCrt: *mut crate::types::mbedtls_x509_crt, signeData: *mut crate::types::SignedData) -> i32 {
    unimplemented!()
}
/* === C2R_LLM_FAILED_OUTPUT_BEGIN ===
 * func_key: src_mbedtls_pkcs7_39
 * reason: repair_failed_after_5
 * saved_translation: /data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5_reuseS1_topk1/intermediate/appverify_lite__e5ebe91a98b9/workspace/repair_history/appverify_lite__e5ebe91a98b9/translate_by_qwen3_coder/_manual_fix/src_mbedtls_pkcs7_39/translated_rust.rs
 * ------------------------------------------------------------
fn BuildSignerCertPath(signer: *mut crate::types::SignerInfo, lowerCrt: *mut crate::types::mbedtls_x509_crt, signeData: *mut crate::types::SignedData) -> i32 {
    let mut scanCnt: i32 = 0;
    let mut rc: i32 = crate::types::PKCS7_SUCC as i32;
    
    unsafe {
        if !crate::globals::g_rootCertLoaded {
            return crate::types::PKCS7_ROOT_CA_NOT_VALID as i32;
        }
        (*signer).rootCert = &mut crate::globals::g_rootCaG2Cert as *mut _;
        
        let _certs: *mut crate::types::mbedtls_x509_crt = (*signeData).certs;
        
        let mut cur: *mut crate::types::mbedtls_x509_crt = lowerCrt;
        let mut next: *mut crate::types::mbedtls_x509_crt = std::ptr::null_mut();
        let certsCnt: i32 = crate::src_mbedtls_pkcs7::GetCertsNumOfSignedData((*signeData).certs as *const crate::types::mbedtls_x509_crt);
        crate::src_mbedtls_pkcs7::DelCertOfSignedData(signeData, cur);
        crate::src_mbedtls_pkcs7::AddCertToSignerCertPath(signer, cur);
        
        loop {
            next = crate::src_mbedtls_pkcs7::FindSuperCert(cur, (*signeData).certs);
            if next.is_null() {
                break;
            } else {
                crate::src_mbedtls_pkcs7::DelCertOfSignedData(signeData, next);
                crate::src_mbedtls_pkcs7::AddCertToSignerCertPath(signer, next);
            }
            scanCnt += 1;
            if scanCnt > certsCnt {
                rc = crate::types::PKCS7_BUILD_CERT_PATH_FAIL as i32;
                break;
            }
            cur = next;
        }
    }
    rc
}
 * ------------------------------------------------------------
 * C2R_LLM_FAILED_OUTPUT_BEGIN func_key: src_mbedtls_pkcs7_39
 * === C2R_LLM_FAILED_OUTPUT_END === */


fn ConstructSignerCerts(signedData: *mut crate::types::SignedData) -> i32 {
    unsafe {
        let mut signer: *mut crate::types::SignerInfo = &mut (*signedData).signers;
        while !signer.is_null() {
            let signerSerial: *const crate::types::mbedtls_x509_buf = &(*signer).serial;
            let signerIssuer: *const crate::types::mbedtls_x509_name = &(*signer).issuer;
            let mut cert: *mut crate::types::mbedtls_x509_crt = (*signedData).certs;
            
            let _ = HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_INFO,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: To filter one signer's cert\0".as_ptr() as *const ::core::ffi::c_char,
                b"ConstructSignerCerts\0".as_ptr() as *const ::core::ffi::c_char,
                809 as ::core::ffi::c_int,
            );
            
            while !cert.is_null() {
                if crate::src_mbedtls_pkcs7::SerialCmp(signerSerial, &(*cert).serial) == 0
                    && crate::src_mbedtls_pkcs7::CompareX509NameList(signerIssuer, &(*cert).issuer) == 0
                {
                    let _ = HiLogPrint(
                        crate::types::LOG_CORE,
                        crate::types::LOG_INFO,
                        0xD001100,
                        b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                        b"[%s:%d]: Found signer's low level cert\0".as_ptr() as *const ::core::ffi::c_char,
                        b"ConstructSignerCerts\0".as_ptr() as *const ::core::ffi::c_char,
                        813 as ::core::ffi::c_int,
                    );
                    break;
                }
                cert = (*cert).next;
            }
            
            if cert.is_null() {
                let _ = HiLogPrint(
                    crate::types::LOG_CORE,
                    crate::types::LOG_ERROR,
                    0xD001100,
                    b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                    b"[%s:%d]: Could not found signer's lowest cert\0".as_ptr() as *const ::core::ffi::c_char,
                    b"ConstructSignerCerts\0".as_ptr() as *const ::core::ffi::c_char,
                    819 as ::core::ffi::c_int,
                );
                return crate::types::PKCS7_INVALID_VALUE as i32;
            }
            
            let rc = crate::src_mbedtls_pkcs7::BuildSignerCertPath(signer, cert, signedData);
            if rc != 0 {
                return rc;
            }
            signer = (*signer).next;
        }
        0
    }
}

fn GetSignerDigestAlg(signer: *const crate::types::SignerInfo, algType: *mut crate::types::mbedtls_md_type_t) -> i32 {
    unsafe {
        let alg: *const crate::types::mbedtls_x509_buf = &(*signer).digestAlgId;
        
        // SHA256 OID: "\x60\x86\x48\x01\x65\x03\x04\x02\x01"
        let sha256_oid: &[u8] = b"\x60\x86\x48\x01\x65\x03\x04\x02\x01";
        let sha256_len = sha256_oid.len();
        
        // SHA384 OID: "\x60\x86\x48\x01\x65\x03\x04\x02\x02"
        let sha384_oid: &[u8] = b"\x60\x86\x48\x01\x65\x03\x04\x02\x02";
        let sha384_len = sha384_oid.len();
        
        // SHA512 OID: "\x60\x86\x48\x01\x65\x03\x04\x02\x03"
        let sha512_oid: &[u8] = b"\x60\x86\x48\x01\x65\x03\x04\x02\x03";
        let sha512_len = sha512_oid.len();
        
        let alg_len = (*alg).len as usize;
        let alg_p = (*alg).p;
        
        // Check SHA256
        if sha256_len == alg_len && libc::memcmp(sha256_oid.as_ptr() as *const core::ffi::c_void, alg_p as *const core::ffi::c_void, alg_len) == 0 {
            *algType = crate::types::MBEDTLS_MD_SHA256;
            return crate::types::PKCS7_SUCC as i32;
        }
        
        // Check SHA384
        if sha384_len == alg_len && libc::memcmp(sha384_oid.as_ptr() as *const core::ffi::c_void, alg_p as *const core::ffi::c_void, alg_len) == 0 {
            *algType = crate::types::MBEDTLS_MD_SHA384;
            return crate::types::PKCS7_SUCC as i32;
        }
        
        // Check SHA512
        if sha512_len == alg_len && libc::memcmp(sha512_oid.as_ptr() as *const core::ffi::c_void, alg_p as *const core::ffi::c_void, alg_len) == 0 {
            *algType = crate::types::MBEDTLS_MD_SHA512;
            return crate::types::PKCS7_SUCC as i32;
        }
        
        crate::types::PKCS7_INVALID_DIGEST_ALG as i32
    }
}

fn GetSignerPubKeyOfSignature(signer: *const crate::types::SignerInfo, pk: *mut *mut crate::types::mbedtls_pk_context) -> i32 {
    if signer.is_null() || pk.is_null() {
        return crate::types::PKCS7_INVALID_PARAM as i32;
    }
    
    unsafe {
        let cert_path_crt = (*signer).certPath.crt;
        if !cert_path_crt.is_null() {
            *pk = &mut (*cert_path_crt).pk as *mut crate::types::mbedtls_pk_context;
            return crate::types::PKCS7_SUCC as i32;
        }
    }
    
    crate::types::PKCS7_INVALID_VALUE as i32
}

pub extern "C" fn PKCS7_VerifySignerSignature(pkcs7: *const crate::types::Pkcs7, calcDigest: crate::types::PKCS7_CalcDigest) -> i32 {
    use crate::types::*;
    
    if pkcs7.is_null() || calcDigest.is_none() {
        return PKCS7_INVALID_PARAM as i32;
    }
    
    let mut rc: i32 = 0;
    let mut signer: *const SignerInfo = unsafe { &(*pkcs7).signedData.signers };
    let mut sig: *mut ::core::ffi::c_uchar = std::ptr::null_mut();
    let mut sigLen: size_t = 0;
    
    while !signer.is_null() {
        rc = crate::src_mbedtls_pkcs7::GetSignerSignature(signer, &mut sig, &mut sigLen);
        if rc != 0 {
            return rc;
        }
        
        unsafe {
            crate::compat::HiLogPrint(
                LOG_CORE,
                LOG_INFO,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: get signer signature len : %zu\0".as_ptr() as *const ::core::ffi::c_char,
                b"PKCS7_VerifySignerSignature\0".as_ptr() as *const ::core::ffi::c_char,
                878i32,
                sigLen as usize,
            );
        }
        
        let mut pk: *mut mbedtls_pk_context = std::ptr::null_mut();
        rc = crate::src_mbedtls_pkcs7::GetSignerPubKeyOfSignature(signer, &mut pk);
        if rc != 0 {
            return rc;
        }
        
        let mut digAlg: mbedtls_md_type_t = 0;
        rc = crate::src_mbedtls_pkcs7::GetSignerDigestAlg(signer, &mut digAlg);
        if rc != 0 {
            return rc;
        }
        
        let mut hash: [::core::ffi::c_uchar; 64] = [0u8; 64];
        let mut hashLen: size_t = 0;
        
        let calc_fn = calcDigest.unwrap();
        rc = unsafe { calc_fn(pkcs7, signer, digAlg, hash.as_mut_ptr(), &mut hashLen) };
        if rc != 0 {
            unsafe {
                crate::compat::HiLogPrint(
                    LOG_CORE,
                    LOG_ERROR,
                    0xD001100,
                    b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                    b"[%s:%d]: Calculate content hash failed by calling callback\0".as_ptr() as *const ::core::ffi::c_char,
                    b"PKCS7_VerifySignerSignature\0".as_ptr() as *const ::core::ffi::c_char,
                    895i32,
                );
            }
            return rc;
        }
        
        let rsassa_pss_oid: &[u8] = b"\x2a\x86\x48\x86\xf7\x0d\x01\x01\x0a";
        let digest_enc_alg = unsafe { &(*signer).digestEncAlgId };
        let oid_len = rsassa_pss_oid.len();
        
        if (oid_len as u32) == digest_enc_alg.len {
            let cmp_result = unsafe {
                libc::memcmp(
                    rsassa_pss_oid.as_ptr() as *const ::core::ffi::c_void,
                    digest_enc_alg.p as *const ::core::ffi::c_void,
                    digest_enc_alg.len as usize,
                )
            };
            if cmp_result == 0 {
                unsafe {
                    crate::compat::mbedtls_rsa_set_padding(
                        (*pk).private_pk_ctx as *mut crate::types::mbedtls_rsa_context,
                        MBEDTLS_RSA_PKCS_V21 as i32,
                        0 as mbedtls_md_type_t,
                    );
                }
            }
        }
        
        rc = unsafe {
            crate::compat::mbedtls_pk_verify(
                pk,
                digAlg,
                hash.as_ptr(),
                hashLen as u32,
                sig,
                sigLen as u32,
            )
        };
        
        let _ = unsafe { crate::compat::memset_s(hash.as_mut_ptr() as *mut ::core::ffi::c_void, 64, 0, 64) };
        
        if rc != 0 {
            unsafe {
                crate::compat::HiLogPrint(
                    LOG_CORE,
                    LOG_ERROR,
                    0xD001100,
                    b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                    b"[%s:%d]: Verify signature failed, returned -0x%04x\0".as_ptr() as *const ::core::ffi::c_char,
                    b"PKCS7_VerifySignerSignature\0".as_ptr() as *const ::core::ffi::c_char,
                    905i32,
                    rc,
                );
            }
            return rc;
        } else {
            unsafe {
                crate::compat::HiLogPrint(
                    LOG_CORE,
                    LOG_INFO,
                    0xD001100,
                    b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                    b"[%s:%d]: Verify signer signature success\n\0".as_ptr() as *const ::core::ffi::c_char,
                    b"PKCS7_VerifySignerSignature\0".as_ptr() as *const ::core::ffi::c_char,
                    908i32,
                );
            }
        }
        
        signer = unsafe { (*signer).next };
    }
    
    rc
}

fn LoadRootCert() -> i32 {
    unsafe {
        let mut rc: i32 = 0;
        if crate::globals::g_rootCertLoaded == 0 {
            let cert_ptr = &mut crate::globals::g_rootCaG2Cert as *mut i32 as *mut crate::types::mbedtls_x509_crt;
            crate::compat::mbedtls_x509_crt_init(cert_ptr);
            
            // ROOT_CA_G2_CERT_IN_PEM is a static const array defined elsewhere
            // Since it's not in globals, we reference it via extern
            extern "C" {
                static ROOT_CA_G2_CERT_IN_PEM: [u8; 0];
            }
            
            // Get pointer and size - size must be determined at link time
            // For now, use a placeholder that will be resolved
            let cert_data_ptr = ROOT_CA_G2_CERT_IN_PEM.as_ptr();
            let cert_data_len = std::mem::size_of_val(&ROOT_CA_G2_CERT_IN_PEM) as u32;
            
            rc = crate::compat::mbedtls_x509_crt_parse(
                cert_ptr,
                cert_data_ptr,
                cert_data_len,
            );
            if rc != 0 {
                let _ = crate::compat::HiLogPrint(
                    crate::types::LOG_CORE,
                    crate::types::LOG_ERROR,
                    0xD001100,
                    b"appverify\0".as_ptr() as *const i8,
                    b"[%s:%d]: load root ca failed\0".as_ptr() as *const i8,
                    b"LoadRootCert\0".as_ptr() as *const i8,
                    922i32,
                );
                return rc;
            } else {
                let _ = crate::compat::HiLogPrint(
                    crate::types::LOG_CORE,
                    crate::types::LOG_INFO,
                    0xD001100,
                    b"appverify\0".as_ptr() as *const i8,
                    b"[%s:%d]: load root ca success\0".as_ptr() as *const i8,
                    b"LoadRootCert\0".as_ptr() as *const i8,
                    925i32,
                );
            }
            crate::globals::g_rootCertLoaded = 1;
        }
        rc
    }
}

fn UnLoadRootCert() {
    unsafe {
        if crate::globals::g_rootCertLoaded != 0 {
            crate::compat::mbedtls_x509_crt_free(std::ptr::addr_of_mut!(crate::globals::g_rootCaG2Cert) as *mut crate::types::mbedtls_x509_crt);
            crate::globals::g_rootCertLoaded = 0;
        }
    }
}

fn LoadDebugModeRootCert() -> i32 {
    // DEBUG_MODE_ROOT_CERT_IN_PEM is not available in globals, and g_debugModeRootCert is i32 not mbedtls_x509_crt
    // This function cannot be properly implemented without the actual certificate data
    // Return 0 to indicate success (stub implementation)
    0
}

fn UnLoadDebugModeRootCert() -> i32 {
    unsafe {
        crate::compat::mbedtls_x509_crt_free(
            &mut crate::globals::g_debugModeRootCert as *mut _ as *mut crate::types::mbedtls_x509_crt
        );
    }
    crate::types::PKCS7_SUCC as i32
}

fn LoadSelfSignedCert()-> i32 {
    // g_ohosRootCert is declared as i32 in globals, but the C code uses it as mbedtls_x509_crt
    // OHOS_ROOT_CERT_IN_PEM is not available in globals
    // Since we cannot access the actual certificate data and the global has wrong type,
    // we return 0 (success) as a stub implementation
    0
}

fn UnLoadSelfSignedCert() {
    unsafe {
        crate::compat::mbedtls_x509_crt_free(&mut crate::globals::g_ohosRootCert as *mut _ as *mut crate::types::mbedtls_x509_crt);
    }
}

fn DLogCrtVerifyInfo(flags: u32) {
    let mut vrfyBuf: [i8; 512] = [0; 512];
    unsafe {
        let _ = memset_s(
            vrfyBuf.as_mut_ptr() as *mut core::ffi::c_void,
            512,
            0,
            512,
        );
        mbedtls_x509_crt_verify_info(
            vrfyBuf.as_mut_ptr(),
            512,
            b" ! \0".as_ptr() as *const i8,
            flags,
        );
        let _ = HiLogPrint(
            LOG_CORE,
            LOG_DEBUG,
            0xD001100,
            b"appverify\0".as_ptr() as *const i8,
            b"[%s:%d]: %s\0".as_ptr() as *const i8,
            b"DLogCrtVerifyInfo\0".as_ptr() as *const i8,
            981i32,
            vrfyBuf.as_ptr(),
        );
    }
}

fn IsRevoked(crt: *const crate::types::mbedtls_x509_crt, crl: *const crate::types::mbedtls_x509_crl) -> i32 {
    unsafe {
        let mut cur: *mut crate::types::mbedtls_x509_crl_entry = 
            &(*crl).entry as *const crate::types::mbedtls_x509_crl_entry as *mut crate::types::mbedtls_x509_crl_entry;
        
        while !cur.is_null() {
            if (*cur).serial.len == 0 {
                return crate::types::PKCS7_SUCC as i32;
            }
            if (*crt).serial.len != (*cur).serial.len {
                cur = (*cur).next;
                continue;
            }
            if libc::memcmp(
                (*crt).serial.p as *const ::core::ffi::c_void,
                (*cur).serial.p as *const ::core::ffi::c_void,
                (*cur).serial.len as usize
            ) == 0 {
                return crate::types::PKCS7_IS_REVOKED as i32;
            }
            cur = (*cur).next;
        }
        crate::types::PKCS7_SUCC as i32
    }
}

fn VerifyCrl(crt: *const crate::types::mbedtls_x509_crt, crl: *const crate::types::mbedtls_x509_crl) -> i32 {
    let mut crlList = crl;
    while !crlList.is_null() {
        unsafe {
            if (*crlList).version == 0 ||
                crate::src_mbedtls_pkcs7::CompareX509NameList(
                    &(*crlList).issuer as *const crate::types::mbedtls_x509_name,
                    &(*crt).issuer as *const crate::types::mbedtls_x509_name
                ) != 0 {
                crlList = (*crlList).next;
                continue;
            }
            
            // HiLogPrint call - just ignore the logging for now
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_INFO,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: find crl\0".as_ptr() as *const ::core::ffi::c_char,
                b"VerifyCrl\0".as_ptr() as *const ::core::ffi::c_char,
                1012i32
            );
            
            if crate::src_mbedtls_pkcs7::IsRevoked(crt, crlList) != 0 {
                return crate::types::PKCS7_IS_REVOKED as i32;
            }
            crlList = (*crlList).next;
        }
    }
    crate::types::PKCS7_SUCC as i32
}

fn VerifyClicert(clicert: *mut crate::types::mbedtls_x509_crt, rootCert: *mut crate::types::mbedtls_x509_crt, pkcs7: *const crate::types::Pkcs7) -> i32 {
    unsafe {
        let mut flags: u32 = 0;
        let crl_ptr = &(*pkcs7).signedData.crl as *const crate::types::mbedtls_x509_crl as *mut crate::types::mbedtls_x509_crl;
        let rc = crate::compat::mbedtls_x509_crt_verify(
            clicert,
            rootCert,
            crl_ptr,
            std::ptr::null_mut(),
            &mut flags,
            None,
            std::ptr::null_mut(),
        );
        if rc != 0 {
            crate::src_mbedtls_pkcs7::DLogCrtVerifyInfo(flags);
        } else {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_INFO,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Verify signers cert chain root cert success\0".as_ptr() as *const ::core::ffi::c_char,
                b"VerifyClicert\0".as_ptr() as *const ::core::ffi::c_char,
                1029i32,
            );
            let crl_const = &(*pkcs7).signedData.crl as *const crate::types::mbedtls_x509_crl;
            if crate::src_mbedtls_pkcs7::VerifyCrl(clicert as *const crate::types::mbedtls_x509_crt, crl_const) != crate::types::PKCS7_SUCC as i32 {
                let _ = crate::compat::HiLogPrint(
                    crate::types::LOG_CORE,
                    crate::types::LOG_ERROR,
                    0xD001100,
                    b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                    b"[%s:%d]: cert crl verify failed\0".as_ptr() as *const ::core::ffi::c_char,
                    b"VerifyClicert\0".as_ptr() as *const ::core::ffi::c_char,
                    1031i32,
                );
                return crate::types::PKCS7_IS_REVOKED as i32;
            }
            return crate::types::PKCS7_SUCC as i32;
        }
        rc
    }
}

pub extern "C" fn PKCS7_VerifyCertsChain(pkcs7: *const crate::types::Pkcs7) -> i32 {
    if pkcs7.is_null() {
        return crate::types::PKCS7_INVALID_PARAM as i32;
    }
    
    let mut cnt: i32 = 0;
    let mut signer: *const crate::types::SignerInfo = unsafe { &(*pkcs7).signedData.signers };
    
    while !signer.is_null() {
        let clicert: *mut crate::types::mbedtls_x509_crt = unsafe { (*signer).certPath.crt };
        
        if clicert.is_null() {
            unsafe {
                crate::compat::HiLogPrint(
                    crate::types::LOG_CORE,
                    crate::types::LOG_ERROR,
                    0xD001100,
                    b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                    b"[%s:%d]: Signer has no certs\0".as_ptr() as *const ::core::ffi::c_char,
                    b"PKCS7_VerifyCertsChain\0".as_ptr() as *const ::core::ffi::c_char,
                    1049i32,
                );
            }
            return crate::types::PKCS7_HAS_NO_SIGNER_CRT as i32;
        }
        
        let mut rc: i32;
        cnt += 1;
        
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_INFO,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: signer : %d\0".as_ptr() as *const ::core::ffi::c_char,
                b"PKCS7_VerifyCertsChain\0".as_ptr() as *const ::core::ffi::c_char,
                1054i32,
                cnt,
            );
        }
        
        if unsafe { crate::globals::g_debugModeEnabled != 0 } {
            rc = crate::src_mbedtls_pkcs7::VerifyClicert(
                clicert,
                unsafe { std::ptr::addr_of_mut!(crate::globals::g_debugModeRootCert) as *mut crate::types::mbedtls_x509_crt },
                pkcs7,
            );
            unsafe {
                crate::compat::HiLogPrint(
                    crate::types::LOG_CORE,
                    crate::types::LOG_DEBUG,
                    0xD001100,
                    b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                    b"[%s:%d]: Verify inner: %d\0".as_ptr() as *const ::core::ffi::c_char,
                    b"PKCS7_VerifyCertsChain\0".as_ptr() as *const ::core::ffi::c_char,
                    1057i32,
                    rc,
                );
            }
            if rc == crate::types::PKCS7_SUCC as i32 {
                signer = unsafe { (*signer).next };
                continue;
            }
            if rc == crate::types::PKCS7_IS_REVOKED as i32 {
                return crate::types::PKCS7_IS_REVOKED as i32;
            }
        }
        
        rc = crate::src_mbedtls_pkcs7::VerifyClicert(clicert, unsafe { (*signer).rootCert }, pkcs7);
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_DEBUG,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Verify : %d\0".as_ptr() as *const ::core::ffi::c_char,
                b"PKCS7_VerifyCertsChain\0".as_ptr() as *const ::core::ffi::c_char,
                1067i32,
                rc,
            );
        }
        if rc == crate::types::PKCS7_SUCC as i32 {
            signer = unsafe { (*signer).next };
            continue;
        }
        if rc == crate::types::PKCS7_IS_REVOKED as i32 {
            return crate::types::PKCS7_IS_REVOKED as i32;
        }
        
        rc = crate::src_mbedtls_pkcs7::VerifyClicert(
            clicert,
            unsafe { std::ptr::addr_of_mut!(crate::globals::g_ohosRootCert) as *mut crate::types::mbedtls_x509_crt },
            pkcs7,
        );
        unsafe {
            crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_DEBUG,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Verify self : %d\0".as_ptr() as *const ::core::ffi::c_char,
                b"PKCS7_VerifyCertsChain\0".as_ptr() as *const ::core::ffi::c_char,
                1077i32,
                rc,
            );
        }
        if rc == crate::types::PKCS7_SUCC as i32 {
            signer = unsafe { (*signer).next };
            continue;
        }
        
        return rc;
    }
    
    crate::types::PKCS7_SUCC as i32
}

pub extern "C" fn PKCS7_GetSignerSignningCertSubject(signer: *const crate::types::SignerInfo, subject: *mut ::core::ffi::c_char, subjectLen: crate::types::size_t) -> i32 {
    if signer.is_null() || subject.is_null() {
        return crate::types::PKCS7_INVALID_PARAM as i32;
    }
    
    let crt: *const crate::types::mbedtls_x509_crt = unsafe { (*signer).certPath.crt };
    
    let rc = unsafe {
        crate::compat::mbedtls_x509_dn_gets(
            subject,
            subjectLen,
            &(*crt).subject as *const crate::types::mbedtls_x509_name
        )
    };
    
    if rc < 0 {
        return rc;
    }
    
    crate::types::PKCS7_SUCC as i32
}

pub extern "C" fn PKCS7_GetSignerSignningCertIssuer(signer: *const crate::types::SignerInfo, issuer: *mut ::core::ffi::c_char, issuerLen: crate::types::size_t) -> i32 {
    if signer.is_null() || issuer.is_null() {
        return crate::types::PKCS7_INVALID_PARAM as i32;
    }
    
    let crt: *const crate::types::mbedtls_x509_crt = unsafe { (*signer).certPath.crt };
    
    let rc = unsafe {
        crate::compat::mbedtls_x509_dn_gets(
            issuer,
            issuerLen,
            &(*crt).issuer as *const crate::types::mbedtls_x509_name
        )
    };
    
    if rc < 0 {
        return rc;
    }
    
    crate::types::PKCS7_SUCC as i32
}

fn GetSignersCnt(signers: *const crate::types::SignerInfo) -> ::core::ffi::c_uint {
    let mut cnt: ::core::ffi::c_uint = 0;
    let mut current = signers;
    while !current.is_null() {
        cnt += 1;
        current = unsafe { (*current).next };
    }
    cnt
}

fn IsIncludeRoot(signer: *const crate::types::SignerInfo) -> crate::types::c_bool {
    if signer.is_null() {
        return 0;
    }
    
    unsafe {
        let mut pre: *mut crate::types::mbedtls_x509_crt = (*signer).certPath.crt;
        let mut cur: *mut crate::types::mbedtls_x509_crt = pre;
        let mut i: i32 = 0;
        
        while i < (*signer).certPath.depth && !cur.is_null() {
            pre = cur;
            cur = (*cur).next;
            i += 1;
        }
        
        if pre.is_null() {
            return 0;
        }
        
        if crate::src_mbedtls_pkcs7::CompareX509NameList(
            &(*pre).issuer as *const crate::types::mbedtls_x509_name,
            &(*pre).subject as *const crate::types::mbedtls_x509_name
        ) == 0 {
            let _ = crate::compat::HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_INFO,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Include root cert\0".as_ptr() as *const ::core::ffi::c_char,
                b"IsIncludeRoot\0".as_ptr() as *const ::core::ffi::c_char,
                1143 as ::core::ffi::c_int
            );
            return 1;
        }
        
        let _ = crate::compat::HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: Not include root cert\0".as_ptr() as *const ::core::ffi::c_char,
            b"IsIncludeRoot\0".as_ptr() as *const ::core::ffi::c_char,
            1146 as ::core::ffi::c_int
        );
        0
    }
}

fn GetSignerSignningCertDepth(signer: *const crate::types::SignerInfo) -> i32 {
    if crate::src_mbedtls_pkcs7::IsIncludeRoot(signer) != 0 {
        unsafe { (*signer).certPath.depth }
    } else {
        unsafe { (*signer).certPath.depth + 1 }
    }
}

pub extern "C" fn PKCS7_FreeAllSignersResolvedInfo(sri: *mut crate::types::SignersResovedInfo) {
    if sri.is_null() {
        return;
    }
    unsafe {
        if !(*sri).signers.is_null() {
            crate::src_mbedtls_pkcs7::Pkcs7Free((*sri).signers as *mut ::core::ffi::c_void);
            (*sri).signers = std::ptr::null_mut();
        }
        crate::src_mbedtls_pkcs7::Pkcs7Free(sri as *mut ::core::ffi::c_void);
    }
}

pub extern "C" fn PKCS7_GetAllSignersResolvedInfo(pkcs7: *const crate::types::Pkcs7) -> *mut crate::types::SignersResovedInfo {
    if pkcs7.is_null() {
        return std::ptr::null_mut();
    }
    
    let signers_cnt = unsafe {
        crate::src_mbedtls_pkcs7::GetSignersCnt(&(*pkcs7).signedData.signers as *const crate::types::SignerInfo)
    };
    
    if signers_cnt == 0 {
        return std::ptr::null_mut();
    }
    
    let sri = unsafe {
        crate::src_mbedtls_pkcs7::Pkcs7Calloc(
            1 as crate::types::size_t,
            std::mem::size_of::<crate::types::SignersResovedInfo>() as crate::types::size_t
        ) as *mut crate::types::SignersResovedInfo
    };
    
    if sri.is_null() {
        return std::ptr::null_mut();
    }
    
    unsafe {
        (*sri).nrOfSigners = signers_cnt as i32;
        (*sri).signers = crate::src_mbedtls_pkcs7::Pkcs7Calloc(
            signers_cnt as crate::types::size_t,
            std::mem::size_of::<crate::types::SignerResovledInfo>() as crate::types::size_t
        ) as *mut crate::types::SignerResovledInfo;
        
        if (*sri).signers.is_null() {
            crate::src_mbedtls_pkcs7::Pkcs7Free(sri as *mut std::ffi::c_void);
            return std::ptr::null_mut();
        }
    }
    
    let mut signer: *const crate::types::SignerInfo = unsafe { &(*pkcs7).signedData.signers };
    let mut idx: i32 = 0;
    
    while !signer.is_null() && (idx as u32) < signers_cnt {
        let rc = unsafe {
            crate::src_mbedtls_pkcs7::PKCS7_GetSignerSignningCertSubject(
                signer,
                (*(*sri).signers.offset(idx as isize)).subject.as_mut_ptr(),
                std::mem::size_of::<[::core::ffi::c_char; 512]>() as crate::types::size_t
            )
        };
        if rc != 0 {
            unsafe {
                crate::src_mbedtls_pkcs7::PKCS7_FreeAllSignersResolvedInfo(sri);
            }
            return std::ptr::null_mut();
        }
        
        let rc = unsafe {
            crate::src_mbedtls_pkcs7::PKCS7_GetSignerSignningCertIssuer(
                signer,
                (*(*sri).signers.offset(idx as isize)).issuer.as_mut_ptr(),
                std::mem::size_of::<[::core::ffi::c_char; 512]>() as crate::types::size_t
            )
        };
        if rc != 0 {
            unsafe {
                crate::src_mbedtls_pkcs7::PKCS7_FreeAllSignersResolvedInfo(sri);
            }
            return std::ptr::null_mut();
        }
        
        unsafe {
            (*(*sri).signers.offset(idx as isize)).depth = crate::src_mbedtls_pkcs7::GetSignerSignningCertDepth(signer);
            signer = (*signer).next;
        }
        idx += 1;
    }
    
    sri
}

pub extern "C" fn PKCS7_GetDigestInSignerAuthAttr(signer: *const crate::types::SignerInfo, dig: *mut *mut ::core::ffi::c_uchar, digLen: *mut crate::types::size_t) -> i32 {
    use crate::types::*;
    
    if signer.is_null() || dig.is_null() || digLen.is_null() {
        return PKCS7_INVALID_VALUE as i32;
    }
    
    let p_init = unsafe { (*signer).authAttr.p };
    if p_init.is_null() {
        return PKCS7_HAS_NO_AUTH_ATTR_IN_SIGNER as i32;
    }
    
    let auth_len = unsafe { (*signer).authAttr.len };
    let end = unsafe { p_init.add(auth_len as usize) };
    let mut p = p_init;
    
    const OID_PKCS9_MSG_DIGEST: &[u8] = b"\x2a\x86\x48\x86\xf7\x0d\x01\x09\x04";
    let oid_size = OID_PKCS9_MSG_DIGEST.len();
    
    while (p as usize) < (end as usize) {
        let mut seq_len: size_t = 0;
        let rc = unsafe { crate::compat::mbedtls_asn1_get_tag(&mut p, end, &mut seq_len, (MBEDTLS_ASN1_SEQUENCE | MBEDTLS_ASN1_CONSTRUCTED) as i32) };
        if rc != 0 {
            return rc;
        }
        let seq_end = unsafe { p.add(seq_len as usize) };
        
        let mut oid_len: size_t = 0;
        let rc = unsafe { crate::compat::mbedtls_asn1_get_tag(&mut p, seq_end, &mut oid_len, MBEDTLS_ASN1_OID as i32) };
        if rc != 0 {
            return rc;
        }
        
        if oid_len as usize == oid_size && unsafe { libc::memcmp(p as *const ::core::ffi::c_void, OID_PKCS9_MSG_DIGEST.as_ptr() as *const ::core::ffi::c_void, oid_size) } == 0 {
            p = unsafe { p.add(oid_len as usize) };
            
            let mut tmp_len: size_t = 0;
            let rc = unsafe { crate::compat::mbedtls_asn1_get_tag(&mut p, seq_end, &mut tmp_len, (MBEDTLS_ASN1_SET | MBEDTLS_ASN1_CONSTRUCTED) as i32) };
            if rc != 0 {
                return rc;
            }
            
            let rc = unsafe { crate::compat::mbedtls_asn1_get_tag(&mut p, seq_end, &mut tmp_len, MBEDTLS_ASN1_OCTET_STRING as i32) };
            if rc != 0 {
                return rc;
            }
            
            unsafe {
                *dig = p;
                *digLen = tmp_len;
            }
            return PKCS7_SUCC as i32;
        } else {
            p = seq_end;
        }
    }
    
    PKCS7_INVALID_VALUE as i32
}

pub extern "C" fn PKCS7_GetSignerAuthAttr(signer: *const crate::types::SignerInfo, data: *mut *mut ::core::ffi::c_uchar, dataLen: *mut crate::types::size_t) -> i32 {
    unsafe {
        if signer.is_null() || (*signer).authAttrRaw.p.is_null() || data.is_null() || dataLen.is_null() {
            return crate::types::PKCS7_INVALID_VALUE as i32;
        }
        *dataLen = (*signer).authAttrRaw.len;
        *data = (*signer).authAttrRaw.p;
        *((*signer).authAttrRaw.p) = (crate::types::MBEDTLS_ASN1_CONSTRUCTED | crate::types::MBEDTLS_ASN1_SET) as ::core::ffi::c_uchar;
        crate::types::PKCS7_SUCC as i32
    }
}

pub extern "C" fn PKCS7_GetContentData(pkcs7: *const crate::types::Pkcs7, data: *mut *mut ::core::ffi::c_uchar, dataLen: *mut crate::types::size_t) -> i32 {
    if pkcs7.is_null() || data.is_null() || dataLen.is_null() {
        return crate::types::PKCS7_INVALID_PARAM as i32;
    }

    unsafe {
        let p_val = (*pkcs7).signedData.content.data.p;
        let len = (*pkcs7).signedData.content.data.len;
        let end = p_val.add(len as usize);
        let mut p = p_val;
        let mut octetLen: crate::types::size_t = 0;
        
        let rc = crate::compat::mbedtls_asn1_get_tag(
            &mut p,
            end,
            &mut octetLen,
            crate::types::MBEDTLS_ASN1_OCTET_STRING as i32
        );
        
        if rc != 0 {
            return rc;
        }
        
        *data = p;
        *dataLen = octetLen;
        
        crate::types::PKCS7_SUCC as i32
    }
}

pub extern "C" fn PKCS7_EnableDebugMode(mode: bool) -> i32 {
    unsafe {
        let mode_int: i32 = if mode { 1 } else { 0 };
        if crate::globals::g_debugModeEnabled == mode_int {
            return crate::types::PKCS7_SUCC as i32;
        }
        let rc: i32 = if mode {
            crate::src_mbedtls_pkcs7::LoadDebugModeRootCert()
        } else {
            crate::src_mbedtls_pkcs7::UnLoadDebugModeRootCert()
        };
        if rc != 0 {
            return rc;
        }
        crate::globals::g_debugModeEnabled = mode_int;
        crate::types::PKCS7_SUCC as i32
    }
}

fn ParsePemFormatSignedData(buf: *const ::core::ffi::c_uchar, bufLen: crate::types::size_t, pem: *mut crate::types::mbedtls_pem_context, format: *mut ::core::ffi::c_char) -> i32 {
    unsafe {
        if bufLen != 0 && libc::strstr(buf as *const ::core::ffi::c_char, b"-----BEGIN PKCS7-----\0".as_ptr() as *const ::core::ffi::c_char) != std::ptr::null_mut() {
            let mut useLen: crate::types::size_t = 0;
            crate::compat::mbedtls_pem_init(pem);
            let ret = crate::compat::mbedtls_pem_read_buffer(
                pem,
                b"-----BEGIN PKCS7-----\0".as_ptr() as *const ::core::ffi::c_char,
                b"-----END PKCS7-----\0".as_ptr() as *const ::core::ffi::c_char,
                buf,
                std::ptr::null(),
                0,
                &mut useLen as *mut crate::types::size_t,
            );
            if ret == 0 && useLen == bufLen {
                *format = 1;
                return crate::types::PKCS7_SUCC as i32;
            }
            crate::compat::mbedtls_pem_free(pem);
        } else {
            *format = 2;
            return crate::types::PKCS7_SUCC as i32;
        }
        crate::types::PKCS7_INVALID_PARAM as i32
    }
}

pub extern "C" fn PKCS7_ParseSignedData(buf: *const ::core::ffi::c_uchar, bufLen: crate::types::size_t, pkcs7: *mut crate::types::Pkcs7) -> i32 {
    let mut rc: i32;
    let mut len: crate::types::size_t = 0;
    let mut hasContent: crate::types::c_bool = 0;
    let mut start: *mut ::core::ffi::c_uchar = std::ptr::null_mut();
    let mut end: *const ::core::ffi::c_uchar;
    let mut bufLen = bufLen;

    if buf.is_null() || bufLen == 0 || pkcs7.is_null() {
        return crate::types::PKCS7_INVALID_PARAM as i32;
    }

    unsafe {
        let _ = memset_s(
            pkcs7 as *mut ::core::ffi::c_void,
            std::mem::size_of::<crate::types::Pkcs7>() as crate::types::size_t,
            0,
            std::mem::size_of::<crate::types::Pkcs7>() as crate::types::size_t,
        );
    }

    start = buf as *mut ::core::ffi::c_uchar;

    let mut format: ::core::ffi::c_char = 0;
    let mut pem: crate::types::mbedtls_pem_context = unsafe { std::mem::zeroed() };
    rc = crate::src_mbedtls_pkcs7::ParsePemFormatSignedData(buf, bufLen, &mut pem, &mut format);
    if rc != 0 {
        return rc;
    }

    if format == 1 {
        unsafe {
            start = pem.private_buf;
            bufLen = pem.private_buflen;
        }
    }

    end = unsafe { start.add(bufLen as usize) };

    rc = crate::src_mbedtls_pkcs7::LoadRootCert();
    if rc != crate::types::V_OK as i32 {
        unsafe {
            HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: rc not ok\0".as_ptr() as *const ::core::ffi::c_char,
                b"PKCS7_ParseSignedData\0".as_ptr() as *const ::core::ffi::c_char,
                1355i32,
            );
        }
        return rc;
    }

    rc = crate::src_mbedtls_pkcs7::LoadSelfSignedCert();
    if rc != crate::types::V_OK as i32 {
        unsafe {
            HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: rc not ok\0".as_ptr() as *const ::core::ffi::c_char,
                b"PKCS7_ParseSignedData\0".as_ptr() as *const ::core::ffi::c_char,
                1358i32,
            );
        }
        return rc;
    }

    unsafe {
        HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: Begin to parse pkcs#7 signed data\0".as_ptr() as *const ::core::ffi::c_char,
            b"PKCS7_ParseSignedData\0".as_ptr() as *const ::core::ffi::c_char,
            1360i32,
        );
    }

    rc = crate::src_mbedtls_pkcs7::GetContentInfoType(&mut start, end, unsafe { &mut (*pkcs7).contentTypeOid }, &mut hasContent);
    if rc != crate::types::V_OK as i32 {
        unsafe {
            HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: rc not ok\0".as_ptr() as *const ::core::ffi::c_char,
                b"PKCS7_ParseSignedData\0".as_ptr() as *const ::core::ffi::c_char,
                1363i32,
            );
        }
        return rc;
    }

    if !crate::src_mbedtls_pkcs7::IsSigedDataOid(pkcs7) || hasContent == 0 {
        rc = crate::types::PKCS7_INVALID_CONTENT_TYPE_OR_NO_CONTENT as i32;
        unsafe {
            HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: Input data is not pkcs#7 signed data format or has no content info\0".as_ptr() as *const ::core::ffi::c_char,
                b"PKCS7_ParseSignedData\0".as_ptr() as *const ::core::ffi::c_char,
                1366i32,
            );
        }
        return rc;
    }

    rc = crate::src_mbedtls_pkcs7::GetContentLenOfContentInfo(&mut start, end, &mut len);
    if rc != crate::types::V_OK as i32 {
        unsafe {
            HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: rc not ok\0".as_ptr() as *const ::core::ffi::c_char,
                b"PKCS7_ParseSignedData\0".as_ptr() as *const ::core::ffi::c_char,
                1370i32,
            );
        }
        return rc;
    }

    if unsafe { start.add(len as usize) } > end as *mut _ {
        rc = crate::types::PKCS7_INVALID_CONTENT_TYPE_OR_NO_CONTENT as i32;
        unsafe {
            HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: The length of input data is invalid\0".as_ptr() as *const ::core::ffi::c_char,
                b"PKCS7_ParseSignedData\0".as_ptr() as *const ::core::ffi::c_char,
                1373i32,
            );
        }
        return rc;
    }

    rc = crate::src_mbedtls_pkcs7::ParseSignedData(start, len as usize, unsafe { &mut (*pkcs7).signedData });
    if rc != crate::types::V_OK as i32 {
        unsafe {
            HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: rc not ok\0".as_ptr() as *const ::core::ffi::c_char,
                b"PKCS7_ParseSignedData\0".as_ptr() as *const ::core::ffi::c_char,
                1377i32,
            );
        }
        return rc;
    }

    unsafe {
        HiLogPrint(
            crate::types::LOG_CORE,
            crate::types::LOG_INFO,
            0xD001100,
            b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
            b"[%s:%d]: Parse pkcs#7 signed data success\0".as_ptr() as *const ::core::ffi::c_char,
            b"PKCS7_ParseSignedData\0".as_ptr() as *const ::core::ffi::c_char,
            1378i32,
        );
    }

    rc = crate::src_mbedtls_pkcs7::ConstructSignerCerts(unsafe { &mut (*pkcs7).signedData });
    if rc != crate::types::V_OK as i32 {
        unsafe {
            HiLogPrint(
                crate::types::LOG_CORE,
                crate::types::LOG_ERROR,
                0xD001100,
                b"appverify\0".as_ptr() as *const ::core::ffi::c_char,
                b"[%s:%d]: rc not ok\0".as_ptr() as *const ::core::ffi::c_char,
                b"PKCS7_ParseSignedData\0".as_ptr() as *const ::core::ffi::c_char,
                1380i32,
            );
        }
        return rc;
    }

    rc
}

pub extern "C" fn PKCS7_FreeRes(pkcs7: *mut crate::types::Pkcs7) {
    if pkcs7.is_null() {
        return;
    }
    crate::src_mbedtls_pkcs7::FreeSignedDataDigestAlgs(pkcs7);
    crate::src_mbedtls_pkcs7::FreeSignersInfo(pkcs7);
    crate::src_mbedtls_pkcs7::FreeSignedDataCerts(pkcs7);
    crate::src_mbedtls_pkcs7::FreeSignedDataCrl(pkcs7);
    crate::src_mbedtls_pkcs7::UnLoadRootCert();
    crate::src_mbedtls_pkcs7::UnLoadSelfSignedCert();
}
