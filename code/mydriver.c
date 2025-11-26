#include <linux/init.h>       // 模块初始化/卸载相关头文件
#include <linux/module.h>     // 核心模块头文件
#include <linux/kernel.h>     // 内核API（如printk）
#include <linux/version.h>    // 内核版本判断

// 模块许可协议（必须声明，否则编译警告）
MODULE_LICENSE("GPL");
// 模块描述、作者、版本（可选，增强可读性）
MODULE_DESCRIPTION("Android GKI AArch64 Kernel Module Template");
MODULE_AUTHOR("Your Name");
MODULE_VERSION("1.0");

// 模块加载函数（insmod 时执行）
static int __init mydriver_init(void) {
    printk(KERN_INFO "[MYDRIVER] Loaded successfully (Android GKI AArch64)\n");
    printk(KERN_INFO "[MYDRIVER] Kernel version: %s\n", UTS_RELEASE);
    return 0;  // 0 表示加载成功，非0加载失败
}

// 模块卸载函数（rmmod 时执行）
static void __exit mydriver_exit(void) {
    printk(KERN_INFO "[MYDRIVER] Unloaded successfully\n");
}

// 注册模块加载/卸载入口
module_init(mydriver_init);
module_exit(mydriver_exit);