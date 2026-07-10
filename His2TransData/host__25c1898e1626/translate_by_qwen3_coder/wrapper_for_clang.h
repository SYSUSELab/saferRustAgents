// Auto-generated wrapper for clang -E preprocessing

#ifndef __NEED_struct_cpu_set_t
#define __NEED_struct_cpu_set_t 1
#endif

#include <sched.h>

#ifndef __must_check
#define __must_check __attribute__((warn_unused_result))
#endif
#ifndef __packed
#define __packed __attribute__((packed))
#endif
#ifndef __aligned
#define __aligned(x) __attribute__((aligned(x)))
#endif
#ifndef __user
#define __user
#endif
#ifndef __force
#define __force
#endif
#ifndef __iomem
#define __iomem
#endif

#ifndef STATIC
#define STATIC static
#endif
#ifndef INLINE
#define INLINE inline
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>

// Avoid signature conflict between musl's dprintf and LiteOS los_printf.h dprintf
#ifdef dprintf
#undef dprintf
#endif
#define dprintf c2r_liteos_dprintf

#include "/data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5/intermediate/host__25c1898e1626/workspace/projects/host__25c1898e1626/include/hdf_driver_loader.h"
#include "/data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5/intermediate/host__25c1898e1626/workspace/projects/host__25c1898e1626/include/devmgr_service_clnt.h"
#include "/data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5/intermediate/host__25c1898e1626/workspace/projects/host__25c1898e1626/include/hdf_service_observer.h"
#include "/data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5/intermediate/host__25c1898e1626/workspace/projects/host__25c1898e1626/include/hdf_pm_reg.h"
#include "/data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5/intermediate/host__25c1898e1626/workspace/projects/host__25c1898e1626/include/devsvc_manager_clnt.h"
#include "/data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5/intermediate/host__25c1898e1626/workspace/projects/host__25c1898e1626/include/devhost_service.h"
#include "/data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5/intermediate/host__25c1898e1626/workspace/projects/host__25c1898e1626/include/hdf_power_manager.h"
#include "/data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5/intermediate/host__25c1898e1626/workspace/projects/host__25c1898e1626/include/power_state_token.h"
#include "/data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5/intermediate/host__25c1898e1626/workspace/projects/host__25c1898e1626/include/hdf_device_token.h"
#include "/data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5/intermediate/host__25c1898e1626/workspace/projects/host__25c1898e1626/include/hdf_service_subscriber.h"
#include "/data/home/wangshb/c2-rust_framework/translation_outputs/deepseek-coder-ohos5/intermediate/host__25c1898e1626/workspace/projects/host__25c1898e1626/include/hdf_observer_record.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hcs_tree_if.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/shared/include/hdf_attribute_manager.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_cstring.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/uhdf/hdf_load_vdi.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_slist.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/shared/include/hdf_power_state.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_node.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/musl/include/dlfcn.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/framework/core/shared/include/hdf_object_manager.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/third_party/bounds_checking_function/include/securec.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/utils/hdf_log.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_driver.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/osal/shared/osal_mem.h"
#include "/data/home/wangshb/c2-rust_framework/SelfContained/ohos_full/OpenHarmony-v5.0.1-Release/OpenHarmony/drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_object.h"

#ifdef dprintf
#undef dprintf
#endif
