
#include <linux/init.h>
#include <linux/module.h>

#include "super.h"
#include "mount.h"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A toy FAT derivative File System");
MODULE_AUTHOR("Andreas Grapentin");

static struct file_system_type fatx_fs_type = {
    .owner = THIS_MODULE,
    .name = "fatx",
    .mount = fatx_mount,
    .kill_sb = kill_block_super,
    .fs_flags = FS_REQUIRES_DEV,
};
MODULE_ALIAS_FS("fatx");

static int __init fatx_init(void)
{
  int res;

  res = register_filesystem(&fatx_fs_type);
  if (res)
    pr_err("failed: register_filesystem\n");

  return res;
}

static void __exit fatx_exit(void)
{
  int res;

  res = unregister_filesystem(&fatx_fs_type);
  if (res)
    pr_err("failed: unregister_filesystem\n");
}

module_init(fatx_init);
module_exit(fatx_exit);
