//! 构建脚本
//! 
//! 当前项目没有 C 依赖，此脚本为空。

fn main() {
    // 没有 C 代码需要编译
    println!("cargo:rerun-if-changed=build.rs");
}
