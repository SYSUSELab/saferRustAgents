# Function-Level Unsafe Report

Generated from `function_level_unsafe_report.tsv`.

Columns: `UID | 所在轮次 | 状态 | 原 unsafe 数 | 重写后 unsafe 数 | 是否编译通过 | 主要残留原因`

## Project Summary

| Project | Rows | Processed | Skipped Fallback | Skipped No Unsafe | Missing From Summary |
| --- | ---: | ---: | ---: | ---: | ---: |
| `appverify_lite__e5ebe91a98b9` | 163 | 138 | 3 | 7 | 15 |
| `host__25c1898e1626` | 118 | 111 | 1 | 6 | 0 |
| `osal__0bc4f21396ad` | 7 | 7 | 0 | 0 | 0 |
| `shared__12e38ea922f7` | 7 | 4 | 3 | 0 | 0 |
| `shared__541f4e547bdb` | 26 | 23 | 0 | 3 | 0 |

## appverify_lite__e5ebe91a98b9

| UID | 所在轮次 | 状态 | 原 unsafe 数 | 重写后 unsafe 数 | 是否编译通过 | 主要残留原因 |
| --- | --- | --- | ---: | ---: | --- | --- |
| `products_default_app_verify_default:15:GetUdid` | `20260326_210816` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `products_default_app_verify_default:38:RegistBaseDefaultFunc` | `20260326_210816` | `skipped_fallback` | 1 | - | `-` | fallback_or_context_gap |
| `products_ipcamera_app_verify_base:15:RegistProductFunc` | `20260326_210816` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_app_centraldirectory:131:ClearHapBuffer` | `20260326_210816` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_centraldirectory:154:GetEocd` | `20260326_210816` | `processed` | 2 | 10 | `True` | raw_ptr_deref<br>manual_alloc_free<br>c_string_buffer |
| `src_app_centraldirectory:15:HapPutByte` | `20260326_210816` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_app_centraldirectory:224:FindSignature` | `20260326_210816` | `processed` | 3 | 2 | `True` | raw_ptr_deref |
| `src_app_centraldirectory:277:ReadFileFullyFromOffset` | `20260326_210816` | `processed` | 1 | 5 | `True` | raw_ptr_deref<br>ffi_call |
| `src_app_centraldirectory:32:HapPutData` | `20260326_210816` | `processed` | 5 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_app_centraldirectory:64:HapSetInt32` | `20260326_210816` | `processed` | 2 | 4 | `True` | raw_ptr_deref<br>ffi_call |
| `src_app_centraldirectory:97:CreateHapBuffer` | `20260326_210816` | `processed` | 2 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_common:15:HapGetInt64` | `20260326_210816` | `processed` | 1 | 0 | `True` | fully_safe_or_no_residual_pattern |
| `src_app_common:33:HapGetInt` | `20260326_210816` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_app_common:38:HapGetUnsignedInt` | `20260326_210816` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_app_common:59:HapGetShort` | `20260326_210816` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_app_common:80:HapPutInt32` | `20260326_210816` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_app_file:120:HapMMap` | `20260326_210816` | `processed` | 1 | 5 | `True` | raw_ptr_deref<br>ffi_call<br>static_mut_global<br>manual_alloc_free<br>c_string_buffer |
| `src_app_file:172:HapMUnMap` | `20260326_210816` | `processed` | 1 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_file:41:InitVerify` | `20260326_210816` | `skipped_fallback` | 1 | - | `-` | fallback_or_context_gap |
| `src_app_provision:15:ProfInit` | `20260326_210816` | `processed` | 2 | 0 | `True` | raw_ptr_deref |
| `src_app_provision:211:GetProfValidity` | `20260326_210816` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_app_provision:261:GetProfBundleInfo` | `20260326_210816` | `processed` | 1 | 5 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_provision:377:GetProfPermission` | `20260326_210816` | `processed` | 3 | 5 | `False` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_provision:408:GetProfDebugInfo` | `20260326_210816` | `processed` | 5 | 3 | `True` | raw_ptr_deref<br>c_string_buffer |
| `src_app_provision:41:GetStringTag` | `20260326_210816` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_provision:454:GetProfIssuerInfo` | `20260326_210816` | `processed` | 1 | 6 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_provision:490:FreeProfBundle` | `20260326_210816` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_provision:515:FreeProfPerssion` | `20260326_210816` | `processed` | 1 | 1 | `True` | raw_ptr_deref |
| `src_app_provision:530:FreeProfDebuginfo` | `20260326_210816` | `processed` | 1 | 6 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_provision:543:ProfFreeData` | `20260326_210816` | `processed` | 1 | 7 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_provision:578:ParseProfile` | `20260326_210816` | `processed` | 30 | 20 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_provision:611:VerifyAppTypeAndDistribution` | `20260326_210816` | `processed` | 1 | 9 | `True` | raw_ptr_deref<br>static_mut_global<br>c_string_buffer |
| `src_app_provision:659:VerifyAppBundleInfo` | `20260326_210816` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>c_string_buffer |
| `src_app_provision:66:FreeStringAttay` | `20260326_210816` | `processed` | 2 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_provision:84:GetStringArrayTag` | `20260326_210816` | `processed` | 1 | 16 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_provision:708:VerifyUdid` | `20260327_191951` | `processed` | 1 | 5 | `True` | raw_ptr_deref<br>manual_alloc_free<br>c_string_buffer |
| `src_app_provision:790:VerifyDebugInfo` | `20260327_191951` | `processed` | 1 | 4 | `True` | raw_ptr_deref<br>c_string_buffer |
| `src_app_provision:841:VerifyProfileContent` | `20260327_191951` | `processed` | 4 | 5 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_app_verify:1122:ParseCertGetPk` | `20260327_191951` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_verify:1168:GetAppSignPublicKey` | `20260327_191951` | `processed` | 2 | 2 | `True` | raw_ptr_deref<br>c_string_buffer |
| `src_app_verify:1199:FreeAppSignPublicKey` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_verify:1210:GetAppid` | `20260327_191951` | `processed` | 14 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_verify:1385:VerifyProfGetContent` | `20260327_191951` | `processed` | 10 | 12 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_verify:1463:CmpCert` | `20260327_191951` | `processed` | 1 | 9 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_verify:1528:LoadCertAndCmpDest` | `20260327_191951` | `processed` | 7 | 6 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_verify:1599:CheckReleaseAppSign` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_app_verify:1656:CheckDebugAppSign` | `20260327_191951` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>c_string_buffer |
| `src_app_verify:1716:CheckAppSignCertWithProfile` | `20260327_191951` | `processed` | 2 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_app_verify:1758:CertInfoInit` | `20260327_191951` | `processed` | 2 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_app_verify:1783:FreeCertInfo` | `20260327_191951` | `processed` | 1 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_verify:1809:GetCertInfo` | `20260327_191951` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_verify:1892:VerfiyAppSourceGetProfile` | `20260327_191951` | `processed` | 6 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_verify:1960:VerifyAppSignPkcsData` | `20260327_191951` | `processed` | 6 | 0 | `True` | fully_safe_or_no_residual_pattern |
| `src_app_verify:2043:GetBinSignPkcs` | `20260327_191951` | `processed` | 2 | 3 | `False` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_verify:2065:GetFileRead` | `20260327_191951` | `processed` | 3 | 0 | `True` | manual_alloc_free |
| `src_app_verify:2089:VerifyBinSign` | `20260327_191951` | `processed` | 6 | 3 | `False` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_verify:2165:VerifyIntegrity` | `20260327_191951` | `processed` | 4 | 1 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_verify:2212:APPVERI_AppVerify` | `20260327_191951` | `processed` | 26 | 7 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_verify:2281:APPVERI_SetDebugMode` | `20260327_191951` | `processed` | 1 | 3 | `True` | ffi_call<br>static_mut_global |
| `src_app_verify:2318:APPVERI_SetActsMode` | `20260327_191951` | `processed` | 1 | 2 | `True` | ffi_call |
| `src_app_verify:2324:APPVERI_IsActsMode` | `20260327_191951` | `processed` | 1 | 1 | `True` | ffi_call<br>static_mut_global |
| `src_app_verify:2328:APPVERI_FreeVerifyRst` | `20260327_191951` | `processed` | 2 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_verify:373:CalcCmpContHash` | `20260327_191951` | `processed` | 9 | 10 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_app_verify:438:CalcDigest` | `20260327_191951` | `processed` | 7 | 4 | `True` | raw_ptr_deref<br>ffi_call |
| `src_app_verify:518:VerifyRawHash` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_app_verify:782:GetAppSingerCertType` | `20260327_191951` | `processed` | 2 | 2 | `True` | raw_ptr_deref<br>manual_alloc_free |
| `src_app_verify:798:GetProfileSingerCertType` | `20260327_191951` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>manual_alloc_free |
| `src_app_verify:815:VerifyProfileSignGetRaw` | `20260327_191951` | `processed` | 1 | 11 | `True` | raw_ptr_deref<br>manual_alloc_free<br>c_string_buffer<br>callback_fn_ptr |
| `src_app_verify_hal:23:RegistHalFunc` | `20260327_191951` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>static_mut_global |
| `src_app_verify_hal:34:InquiryDeviceUdid` | `20260327_191951` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_app_verify_hap:139:GetChunkSumCount` | `20260327_191951` | `processed` | 2 | 0 | `True` | fully_safe_or_no_residual_pattern |
| `src_app_verify_hap:15:GetDigestAlgorithmId` | `20260327_191951` | `processed` | 1 | 1 | `True` | ffi_call |
| `src_app_verify_hap:184:ComputeDigestsWithOptionalBlock` | `20260327_191951` | `processed` | 17 | 19 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_verify_hap:270:HapUpdateDigistHead` | `20260327_191951` | `processed` | 1 | 6 | `True` | raw_ptr_deref<br>c_string_buffer |
| `src_app_verify_hap:303:UpdateSmallBlock` | `20260327_191951` | `processed` | 5 | 7 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_verify_hap:326:ComputerFileHash` | `20260327_191951` | `processed` | 27 | 9 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_app_verify_hap:396:ComputerCoreDirHash` | `20260327_191951` | `processed` | 1 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_app_verify_hap:40:ComputeBlockHash` | `20260327_191951` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_app_verify_hap:451:ComputerEocdHash` | `20260327_191951` | `processed` | 1 | 1 | `False` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_app_verify_hap:480:VerifyIntegrityChunk` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:1016:AddCertToSignerCertPath` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:1056:BuildSignerCertPath` | `20260327_191951` | `skipped_fallback` | 0 | - | `-` | fallback_or_context_gap |
| `src_mbedtls_pkcs7:108:GetContentLenOfContentInfo` | `20260327_191951` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:1105:ConstructSignerCerts` | `20260327_191951` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>c_string_buffer |
| `src_mbedtls_pkcs7:1164:GetSignerDigestAlg` | `20260327_191951` | `processed` | 1 | 1 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:119:ParseSignerVersion` | `20260327_191951` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:1205:GetSignerPubKeyOfSignature` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:1221:PKCS7_VerifySignerSignature` | `20260327_191951` | `processed` | 12 | 9 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer<br>callback_fn_ptr |
| `src_mbedtls_pkcs7:125:ParseSignerIssuerAndSerialNum` | `20260327_191951` | `processed` | 7 | 8 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:1354:LoadRootCert` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>static_mut_global |
| `src_mbedtls_pkcs7:1405:UnLoadRootCert` | `20260327_191951` | `processed` | 1 | 2 | `True` | static_mut_global<br>manual_alloc_free |
| `src_mbedtls_pkcs7:1414:LoadDebugModeRootCert` | `20260327_191951` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_mbedtls_pkcs7:1421:UnLoadDebugModeRootCert` | `20260327_191951` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>static_mut_global<br>manual_alloc_free |
| `src_mbedtls_pkcs7:1430:LoadSelfSignedCert` | `20260327_191951` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_mbedtls_pkcs7:1438:UnLoadSelfSignedCert` | `20260327_191951` | `processed` | 1 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>static_mut_global<br>manual_alloc_free |
| `src_mbedtls_pkcs7:1444:DLogCrtVerifyInfo` | `20260327_191951` | `processed` | 1 | 5 | `True` | raw_ptr_deref<br>c_string_buffer |
| `src_mbedtls_pkcs7:1472:IsRevoked` | `20260327_191951` | `processed` | 1 | 5 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:1498:VerifyCrl` | `20260327_191951` | `processed` | 1 | 3 | `False` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_mbedtls_pkcs7:1531:VerifyClicert` | `20260327_191951` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:1575:PKCS7_VerifyCertsChain` | `20260327_191951` | `processed` | 14 | 10 | `True` | raw_ptr_deref<br>ffi_call<br>static_mut_global<br>c_string_buffer |
| `src_mbedtls_pkcs7:1693:PKCS7_GetSignerSignningCertSubject` | `20260327_191951` | `processed` | 2 | 5 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_mbedtls_pkcs7:169:ParseSignerDigestAlg` | `20260327_191951` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:1715:PKCS7_GetSignerSignningCertIssuer` | `20260327_191951` | `processed` | 2 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_mbedtls_pkcs7:1737:GetSignersCnt` | `20260327_191951` | `processed` | 1 | 1 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:1747:IsIncludeRoot` | `20260327_191951` | `processed` | 1 | 1 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:1796:GetSignerSignningCertDepth` | `20260327_191951` | `processed` | 2 | 0 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:1804:PKCS7_FreeAllSignersResolvedInfo` | `20260327_191951` | `processed` | 1 | 1 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:1817:PKCS7_GetAllSignersResolvedInfo` | `20260327_191951` | `processed` | 9 | 10 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_mbedtls_pkcs7:182:ParseSignerAuthAttr` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:1896:PKCS7_GetDigestInSignerAuthAttr` | `20260327_191951` | `processed` | 11 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:1956:PKCS7_GetSignerAuthAttr` | `20260327_191951` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:1968:PKCS7_GetContentData` | `20260327_191951` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:1998:PKCS7_EnableDebugMode` | `20260327_191951` | `processed` | 1 | 3 | `True` | ffi_call |
| `src_mbedtls_pkcs7:2017:ParsePemFormatSignedData` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>c_string_buffer |
| `src_mbedtls_pkcs7:2044:PKCS7_ParseSignedData` | `20260327_191951` | `processed` | 18 | 21 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_mbedtls_pkcs7:208:InvalidDigestEncAlg` | `20260327_191951` | `processed` | 1 | 1 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:2238:PKCS7_FreeRes` | `20260327_191951` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_mbedtls_pkcs7:240:ParseSignerEncAlg` | `20260327_191951` | `processed` | 2 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:267:ParseSignerSignature` | `20260327_191951` | `processed` | 2 | 3 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:287:GetSignerSignature` | `20260327_191951` | `processed` | 1 | 0 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:297:ParseSignerUnAuthAttr` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:325:SerialCmp` | `20260327_191951` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:334:IsLegitString` | `20260327_191951` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_mbedtls_pkcs7:341:CompareX509String` | `20260327_191951` | `processed` | 1 | 4 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:371:GetDeps` | `20260327_191951` | `processed` | 1 | 3 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:383:CompareX509NameList` | `20260327_191951` | `processed` | 1 | 4 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:415:Pkcs7Calloc` | `20260327_191951` | `processed` | 1 | 0 | `True` | raw_ptr_deref<br>manual_alloc_free |
| `src_mbedtls_pkcs7:421:Pkcs7Free` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_mbedtls_pkcs7:427:ParseSignedDataSignerInfos` | `20260327_191951` | `processed` | 15 | 22 | `True` | raw_ptr_deref<br>c_string_buffer |
| `src_mbedtls_pkcs7:44:InvalidDigestAlg` | `20260327_191951` | `processed` | 1 | 1 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:517:ParseSignedDataVersion` | `20260327_191951` | `processed` | 4 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_mbedtls_pkcs7:555:ParseSignedDataDigestAlgs` | `20260327_191951` | `processed` | 8 | 2 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:592:DlogContentInfo` | `20260327_191951` | `processed` | 2 | 1 | `True` | raw_ptr_deref<br>manual_alloc_free |
| `src_mbedtls_pkcs7:619:ParseSignedDataContentInfo` | `20260327_191951` | `processed` | 3 | 5 | `True` | raw_ptr_deref<br>c_string_buffer |
| `src_mbedtls_pkcs7:678:ParseSignedDataCerts` | `20260327_191951` | `processed` | 1 | 4 | `True` | raw_ptr_deref<br>manual_alloc_free |
| `src_mbedtls_pkcs7:748:ParseSignedDataCrl` | `20260327_191951` | `processed` | 3 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:782:ParseSignedData` | `20260327_191951` | `processed` | 9 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_mbedtls_pkcs7:80:GetContentInfoType` | `20260327_191951` | `processed` | 5 | 4 | `False` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:871:IsSigedDataOid` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_mbedtls_pkcs7:894:FreeSignedDataDigestAlgs` | `20260327_191951` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>manual_alloc_free |
| `src_mbedtls_pkcs7:908:FreeSignerCerts` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_mbedtls_pkcs7:918:FreeSignerIssuer` | `20260327_191951` | `processed` | 1 | 3 | `False` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_mbedtls_pkcs7:933:FreeSignersInfo` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>manual_alloc_free |
| `src_mbedtls_pkcs7:951:FreeSignedDataCerts` | `20260327_191951` | `processed` | 1 | 1 | `False` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_mbedtls_pkcs7:961:FreeSignedDataCrl` | `20260327_191951` | `processed` | 1 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_mbedtls_pkcs7:967:GetCertsNumOfSignedData` | `20260327_191951` | `processed` | 1 | 2 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:979:FindSuperCert` | `20260327_191951` | `processed` | 1 | 3 | `True` | raw_ptr_deref |
| `src_mbedtls_pkcs7:994:DelCertOfSignedData` | `20260327_191951` | `processed` | 1 | 4 | `True` | raw_ptr_deref |
| `src_app_verify:1032:GetEcPk` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:104:GetSignHead` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:1106:GetPkBuf` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:242:FindBlockHead` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:304:GetSignBlockByType` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:32:SignHeadN2H` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:356:GetHashUnitLen` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:599:GetCertTypeBySourceName` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:619:GetProfSourceBySigningCert` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:634:GetProfileCertTypeBySignInfo` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:66:BlockHeadN2H` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:683:GetAppSourceBySigningCert` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:719:GetAppCertTypeBySignInfo` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:83:ContentN2H` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |
| `src_app_verify:916:GetRsaPk` | `not_in_summary` | `missing_from_summary` | - | - | `-` | not_reached_or_not_recorded |

## host__25c1898e1626

| UID | 所在轮次 | 状态 | 原 unsafe 数 | 重写后 unsafe 数 | 是否编译通过 | 主要残留原因 |
| --- | --- | --- | ---: | ---: | --- | --- |
| `src_devhost_service:15:DevHostServiceFindDevice` | `20260327_192044` | `processed` | 2 | 1 | `True` | raw_ptr_deref |
| `src_devhost_service:186:DevHostServiceDelDevice` | `20260327_192044` | `processed` | 6 | 6 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_devhost_service:276:DevHostServiceStartService` | `20260327_192044` | `processed` | 2 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_devhost_service:294:ApplyDevicesPowerState` | `20260327_192044` | `processed` | 1 | 1 | `True` | raw_ptr_deref |
| `src_devhost_service:345:DevHostServicePmNotify` | `20260327_192044` | `processed` | 5 | 8 | `True` | raw_ptr_deref<br>c_string_buffer |
| `src_devhost_service:418:DevHostServiceConstruct` | `20260327_192044` | `processed` | 3 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_devhost_service:439:DevHostServiceDestruct` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_devhost_service:471:DevHostServiceCreate` | `20260327_192044` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_devhost_service:483:DevHostServiceRelease` | `20260327_192044` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_devhost_service:493:DevHostServiceNewInstance` | `20260327_192044` | `processed` | 2 | 6 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_devhost_service:504:DevHostServiceFreeInstance` | `20260327_192044` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_devhost_service:52:DevHostServiceFreeDevice` | `20260327_192044` | `processed` | 1 | 3 | `True` | raw_ptr_deref |
| `src_devhost_service:66:DevHostServiceQueryOrAddDevice` | `20260327_192044` | `processed` | 2 | 4 | `True` | raw_ptr_deref |
| `src_devhost_service:89:DevHostServiceAddDevice` | `20260327_192044` | `processed` | 25 | 17 | `True` | raw_ptr_deref<br>ffi_call<br>callback_fn_ptr |
| `src_devmgr_service_clnt:104:DevmgrServiceClntGetInstance` | `20260327_192044` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call<br>static_mut_global |
| `src_devmgr_service_clnt:119:DevmgrServiceClntFreeInstance` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_devmgr_service_clnt:15:DevmgrServiceClntAttachDeviceHost` | `20260327_192044` | `processed` | 3 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_devmgr_service_clnt:34:DevmgrServiceClntAttachDevice` | `20260327_192044` | `processed` | 6 | 4 | `True` | raw_ptr_deref<br>ffi_call |
| `src_devmgr_service_clnt:67:DevmgrServiceClntDetachDevice` | `20260327_192044` | `processed` | 5 | 7 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_devsvc_manager_clnt:117:DevSvcManagerClntGetDeviceObject` | `20260327_192044` | `processed` | 5 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_devsvc_manager_clnt:158:DevSvcManagerClntSubscribeService` | `20260327_192044` | `processed` | 6 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_devsvc_manager_clnt:15:DevSvcManagerClntAddService` | `20260327_192044` | `processed` | 1 | 5 | `True` | raw_ptr_deref<br>ffi_call |
| `src_devsvc_manager_clnt:209:DevSvcManagerClntUnsubscribeService` | `20260327_192044` | `processed` | 6 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_devsvc_manager_clnt:258:DevSvcManagerClntRemoveService` | `20260327_192044` | `processed` | 4 | 8 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_devsvc_manager_clnt:291:DevSvcManagerClntConstruct` | `20260327_192044` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_devsvc_manager_clnt:299:DevSvcManagerClntGetInstance` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref |
| `src_devsvc_manager_clnt:314:DevSvcManagerClntFreeInstance` | `20260327_192044` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_devsvc_manager_clnt:46:DevSvcManagerClntUpdateService` | `20260327_192044` | `processed` | 1 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>callback_fn_ptr |
| `src_devsvc_manager_clnt:76:DevSvcManagerClntGetService` | `20260327_192044` | `processed` | 5 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device:117:HdfDeviceAttach` | `20260327_192044` | `processed` | 4 | 4 | `True` | raw_ptr_deref |
| `src_hdf_device:15:UpdateDeivceNodeIdIndex` | `20260327_192044` | `processed` | 1 | 0 | `True` | fully_safe_or_no_residual_pattern |
| `src_hdf_device:181:HdfDeviceDetach` | `20260327_192044` | `processed` | 6 | 5 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device:238:HdfDeviceGetDeviceNode` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref |
| `src_hdf_device:259:HdfDeviceDetachWithDevid` | `20260327_192044` | `processed` | 2 | 3 | `True` | raw_ptr_deref |
| `src_hdf_device:282:HdfDeviceConstruct` | `20260327_192044` | `processed` | 5 | 5 | `True` | raw_ptr_deref<br>ffi_call<br>callback_fn_ptr |
| `src_hdf_device:295:HdfDeviceDestruct` | `20260327_192044` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_hdf_device:30:FindUsableDevNodeId` | `20260327_192044` | `processed` | 1 | 3 | `True` | raw_ptr_deref |
| `src_hdf_device:329:HdfDeviceCreate` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device:339:HdfDeviceRelease` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_hdf_device:349:HdfDeviceNewInstance` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device:355:HdfDeviceFreeInstance` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device:74:AcquireNodeDeivceId` | `20260327_192044` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_node:140:HdfDeviceLaunchNode` | `20260327_192044` | `processed` | 9 | 5 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_node:15:HdfDeviceNodePublishLocalService` | `20260327_192044` | `processed` | 2 | 2 | `True` | raw_ptr_deref |
| `src_hdf_device_node:242:HdfDeviceNodeAddPowerStateListener` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_node:261:HdfDeviceNodeRemovePowerStateListener` | `20260327_192044` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_node:278:HdfDeviceNodePublishPublicService` | `20260327_192044` | `processed` | 1 | 0 | `False` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_node:313:HdfDeviceNodeRemoveService` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_node:325:HdfDeviceUnlaunchNode` | `20260327_192044` | `processed` | 1 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer<br>callback_fn_ptr |
| `src_hdf_device_node:376:HdfDeviceNodeConstruct` | `20260327_192044` | `processed` | 5 | 5 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_node:404:HdfDeviceNodeDestruct` | `20260327_192044` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_node:450:HdfDeviceNodeNewInstance` | `20260327_192044` | `processed` | 4 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_node:495:HdfDeviceNodeFreeInstance` | `20260327_192044` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_node:58:HdfDeviceNodePublishService` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>c_string_buffer<br>callback_fn_ptr |
| `src_hdf_device_node:85:DeviceDriverBind` | `20260327_192044` | `processed` | 1 | 8 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_object:107:HdfPmUnregisterPowerListener` | `20260327_192044` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_object:122:HdfPmAcquireDevice` | `20260327_192044` | `processed` | 5 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>callback_fn_ptr |
| `src_hdf_device_object:15:HdfDeviceSubscribeService` | `20260327_192044` | `processed` | 6 | 6 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_object:169:HdfPmReleaseDevice` | `20260327_192044` | `processed` | 5 | 4 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_object:207:HdfPmAcquireDeviceAsync` | `20260327_192044` | `processed` | 3 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_object:239:HdfPmReleaseDeviceAsync` | `20260327_192044` | `processed` | 2 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_object:268:HdfPmSetMode` | `20260327_192044` | `processed` | 4 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_object:308:HdfDeviceSetClass` | `20260327_192044` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_object:318:HdfDeviceObjectConstruct` | `20260327_192044` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_object:328:HdfDeviceObjectAlloc` | `20260327_192044` | `processed` | 6 | 6 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_object:386:HdfDeviceObjectRelease` | `20260327_192044` | `processed` | 2 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_hdf_device_object:413:HdfDeviceObjectRegister` | `20260327_192044` | `processed` | 13 | 10 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_object:476:HdfDeviceObjectUnRegister` | `20260327_192044` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_object:502:HdfDeviceObjectPublishService` | `20260327_192044` | `processed` | 2 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer<br>callback_fn_ptr |
| `src_hdf_device_object:552:HdfDeviceObjectRemoveService` | `20260327_192044` | `processed` | 2 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_object:56:HdfDeviceGetServiceName` | `20260327_192044` | `processed` | 4 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_object:573:HdfDeviceObjectSetServInfo` | `20260327_192044` | `processed` | 4 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_object:613:HdfDeviceObjectUpdate` | `20260327_192044` | `processed` | 4 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_object:643:HdfDeviceObjectSetInterfaceDesc` | `20260327_192044` | `processed` | 2 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_object:668:HdfDeviceObjectCheckInterfaceDesc` | `20260327_192044` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_hdf_device_object:91:HdfPmRegisterPowerListener` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_token:15:HdfDeviceTokenConstruct` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref |
| `src_hdf_device_token:21:HdfDeviceTokenCreate` | `20260327_192044` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_token:33:HdfDeviceTokenRelease` | `20260327_192044` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_token:44:HdfDeviceTokenNewInstance` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>static_mut_global |
| `src_hdf_device_token:50:HdfDeviceTokenFreeInstance` | `20260327_192044` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_driver_loader:100:HdfDriverLoaderCreate` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>static_mut_global |
| `src_hdf_driver_loader:122:HdfDriverLoaderGetInstance` | `20260327_192044` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_driver_loader:15:HdfDriverEntryConstruct` | `20260327_192044` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_driver_loader:69:HdfDriverLoaderGetDriver` | `20260327_192044` | `processed` | 2 | 1 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_driver_loader:87:HdfDriverLoaderReclaimDriver` | `20260327_192044` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_hdf_driver_loader:91:HdfDriverLoaderConstruct` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref |
| `src_hdf_load_vdi:15:HdfLoadVdi` | `20260327_192044` | `processed` | 1 | 13 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer<br>callback_fn_ptr |
| `src_hdf_load_vdi:82:HdfGetVdiVersion` | `20260327_192044` | `processed` | 2 | 5 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_load_vdi:95:HdfCloseVdi` | `20260327_192044` | `processed` | 1 | 11 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer<br>callback_fn_ptr |
| `src_hdf_observer_record:137:HdfServiceObserverRecordDelete` | `20260327_192044` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_hdf_observer_record:15:HdfServiceObserverRecordObtain` | `20260327_192044` | `processed` | 2 | 1 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_hdf_observer_record:55:HdfServiceObserverRecordRecycle` | `20260327_192044` | `skipped_fallback` | 1 | - | `-` | fallback_or_context_gap |
| `src_hdf_observer_record:84:HdfServiceObserverRecordCompare` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_observer_record:97:HdfServiceObserverRecordNotifySubscribers` | `20260327_192044` | `processed` | 3 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_power_manager:115:HdfPowerManagerInit` | `20260327_192044` | `processed` | 1 | 1 | `True` | ffi_call |
| `src_hdf_power_manager:123:HdfPowerManagerExit` | `20260327_192044` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_hdf_power_manager:15:HdfPmTaskQueueInstance` | `20260327_192044` | `processed` | 1 | 0 | `True` | fully_safe_or_no_residual_pattern |
| `src_hdf_power_manager:20:HdfPmTaskQueueInit` | `20260327_192044` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_hdf_power_manager:30:HdfPmTaskQueueDestroy` | `20260327_192044` | `processed` | 1 | 1 | `True` | ffi_call |
| `src_hdf_power_manager:42:PmTaskFunc` | `20260327_192044` | `processed` | 3 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free<br>callback_fn_ptr |
| `src_hdf_power_manager:76:HdfPmTaskPut` | `20260327_192044` | `processed` | 4 | 5 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_service_observer:133:HdfServiceObserverPublishService` | `20260327_192044` | `processed` | 6 | 3 | `False` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_service_observer:15:HdfServiceObserverConstruct` | `20260327_192044` | `processed` | 2 | 7 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_service_observer:195:HdfServiceObserverRemoveRecord` | `20260327_192044` | `processed` | 4 | 7 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_service_observer:37:HdfServiceObserverDestruct` | `20260327_192044` | `processed` | 1 | 4 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_service_observer:51:HdfServiceObserverSubscribeService` | `20260327_192044` | `processed` | 8 | 5 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_service_subscriber:15:HdfServiceSubscriberObtain` | `20260327_192044` | `processed` | 2 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_service_subscriber:29:HdfServiceSubscriberRecycle` | `20260327_192044` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_service_subscriber:37:HdfServiceSubscriberDelete` | `20260327_192044` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_power_state_token:103:PowerStateTokenAcquireWakeLock` | `20260327_192044` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>callback_fn_ptr |
| `src_power_state_token:121:PowerStateTokenReleaseWakeLock` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>callback_fn_ptr |
| `src_power_state_token:154:PowerStateTokenConstruct` | `20260327_192044` | `processed` | 5 | 5 | `True` | raw_ptr_deref<br>ffi_call<br>callback_fn_ptr |
| `src_power_state_token:15:PowerStateTokenOnFirstAcquire` | `20260327_192044` | `processed` | 1 | 4 | `True` | raw_ptr_deref |
| `src_power_state_token:180:PowerStateTokenNewInstance` | `20260327_192044` | `processed` | 2 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>manual_alloc_free |
| `src_power_state_token:199:PowerStateTokenFreeInstance` | `20260327_192044` | `processed` | 1 | 4 | `True` | raw_ptr_deref<br>ffi_call |
| `src_power_state_token:32:PowerStateTokenOnLastRelease` | `20260327_192044` | `processed` | 2 | 5 | `True` | raw_ptr_deref<br>callback_fn_ptr |
| `src_power_state_token:58:PowerStateChange` | `20260327_192044` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>callback_fn_ptr |

## osal__0bc4f21396ad

| UID | 所在轮次 | 状态 | 原 unsafe 数 | 重写后 unsafe 数 | 是否编译通过 | 主要残留原因 |
| --- | --- | --- | ---: | ---: | --- | --- |
| `src_osal_sysevent:15:HdfSysEventNotifierGetInstance` | `20260327_192134` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call<br>static_mut_global |
| `src_osal_sysevent:181:InitKeventIoServiceListenerLocked` | `20260327_192134` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_osal_sysevent:235:DeInitKeventIoServiceListenerLocked` | `20260327_192134` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_osal_sysevent:254:HdfSysEventNotifyRegister` | `20260327_192134` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_osal_sysevent:296:HdfSysEventNotifyUnregister` | `20260327_192134` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_osal_sysevent:49:FinishEvent` | `20260327_192134` | `processed` | 10 | 9 | `True` | raw_ptr_deref<br>ffi_call |
| `src_osal_sysevent:91:OnKEventReceived` | `20260327_192134` | `processed` | 9 | 10 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |

## shared__12e38ea922f7

| UID | 所在轮次 | 状态 | 原 unsafe 数 | 重写后 unsafe 数 | 是否编译通过 | 主要残留原因 |
| --- | --- | --- | ---: | ---: | --- | --- |
| `src_dev_attribute_serialize:155:DeviceAttributeDeserialize` | `20260327_192208` | `skipped_fallback` | 1 | - | `-` | fallback_or_context_gap |
| `src_dev_attribute_serialize:219:DeviceSerializedAttributeRelease` | `20260327_192208` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_dev_attribute_serialize:33:DeviceAttributeSerialize` | `20260327_192208` | `skipped_fallback` | 1 | - | `-` | fallback_or_context_gap |
| `src_dev_attribute_serialize:89:DeviceAttributeSet` | `20260327_192208` | `processed` | 1 | 5 | `True` | ffi_call<br>c_string_buffer |
| `src_hcb_config_entry:15:GetProductName` | `20260327_192208` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hcb_config_entry:21:GetConfigFilePath` | `20260327_192208` | `processed` | 4 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hcb_config_entry:97:HdfGetHcsRootNode` | `20260327_192208` | `skipped_fallback` | 1 | - | `-` | fallback_or_context_gap |

## shared__541f4e547bdb

| UID | 所在轮次 | 状态 | 原 unsafe 数 | 重写后 unsafe 数 | 是否编译通过 | 主要残留原因 |
| --- | --- | --- | ---: | ---: | --- | --- |
| `src_hdf_device_info:15:HdfDeviceInfoConstruct` | `20260327_192217` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_info:35:HdfDeviceInfoNewInstance` | `20260327_192217` | `processed` | 2 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_device_info:58:HdfDeviceInfoFreeInstance` | `20260327_192217` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_device_info:66:HdfDeviceInfoDelete` | `20260327_192217` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_hdf_io_service:15:HdfIoServiceBind` | `20260327_192217` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_io_service:19:HdfIoServiceRecycle` | `20260327_192217` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_io_service:25:HdfIoServicePublish` | `20260327_192217` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_hdf_io_service:31:HdfIoServiceRemove` | `20260327_192217` | `processed` | 2 | 2 | `True` | raw_ptr_deref<br>ffi_call<br>callback_fn_ptr |
| `src_hdf_io_service:43:HdfIoServiceDispatch` | `20260327_192217` | `processed` | 1 | 1 | `True` | raw_ptr_deref<br>ffi_call<br>callback_fn_ptr |
| `src_hdf_object_manager:15:HdfObjectManagerGetObject` | `20260327_192217` | `processed` | 2 | 0 | `True` | raw_ptr_deref<br>ffi_call<br>callback_fn_ptr |
| `src_hdf_object_manager:31:HdfObjectManagerFreeObject` | `20260327_192217` | `processed` | 2 | 5 | `True` | raw_ptr_deref<br>ffi_call<br>callback_fn_ptr |
| `src_hdf_service_record:15:DevSvcRecordNewInstance` | `20260327_192217` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_hdf_service_record:21:DevSvcRecordFreeInstance` | `20260327_192217` | `processed` | 1 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_ioserstat_listener:15:OnIoServiceEventReceive` | `20260327_192217` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>c_string_buffer |
| `src_ioserstat_listener:47:IoServiceStatusListenerNewInstance` | `20260327_192217` | `processed` | 3 | 1 | `True` | raw_ptr_deref<br>ffi_call |
| `src_ioserstat_listener:67:IoServiceStatusListenerFree` | `20260327_192217` | `processed` | 3 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_service_status:15:ServiceStatusMarshalling` | `20260327_192217` | `processed` | 1 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_service_status:46:ServiceStatusUnMarshalling` | `20260327_192217` | `processed` | 1 | 4 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_svcmgr_ioservice:104:SvcMgrIoserviceUnRegSvcStatListener` | `20260327_192217` | `processed` | 2 | 6 | `True` | raw_ptr_deref<br>ffi_call |
| `src_svcmgr_ioservice:137:SvcMgrIoserviceConstruct` | `20260327_192217` | `processed` | 1 | 0 | `True` | fully_safe_or_no_residual_pattern |
| `src_svcmgr_ioservice:144:SvcMgrIoserviceGet` | `20260327_192217` | `processed` | 3 | 3 | `True` | raw_ptr_deref<br>ffi_call<br>c_string_buffer |
| `src_svcmgr_ioservice:15:ProcessListenClass` | `20260327_192217` | `processed` | 3 | 4 | `True` | raw_ptr_deref<br>ffi_call |
| `src_svcmgr_ioservice:180:SvcMgrIoserviceRelease` | `20260327_192217` | `processed` | 2 | 2 | `True` | raw_ptr_deref<br>ffi_call |
| `src_svcmgr_ioservice:57:SetListenClass` | `20260327_192217` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_svcmgr_ioservice:61:UnSetListenClass` | `20260327_192217` | `skipped_no_unsafe` | 0 | - | `-` | no_unsafe_in_original |
| `src_svcmgr_ioservice:65:SvcMgrIoserviceRegSvcStatListener` | `20260327_192217` | `processed` | 3 | 3 | `True` | raw_ptr_deref<br>ffi_call |

