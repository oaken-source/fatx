#pragma once

#include <linux/fs.h>

struct dentry* fatx_mount(struct file_system_type *type, int flags, char const *dev, void *data);
