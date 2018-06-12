
#include "mount.h"
#include "super.h"

struct dentry*
fatx_mount(struct file_system_type *type, int flags, char const *dev, void *data)
{
  struct dentry *entry = mount_bdev(type, flags, dev, data, fatx_fill_super);

  if (IS_ERR(entry))
    pr_err("failed: mount_bdev\n");

  return entry;
}

