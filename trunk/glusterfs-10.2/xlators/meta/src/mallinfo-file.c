/*
   Copyright (c) 2014 Red Hat, Inc. <http://www.redhat.com>
   This file is part of GlusterFS.

   This file is licensed to you under your choice of the GNU Lesser
   General Public License, version 3 or any later version (LGPLv3 or
   later), or the GNU General Public License, version 2 (GPLv2), in all
   cases as published by the Free Software Foundation.
*/

#include <glusterfs/xlator.h>
#include <glusterfs/defaults.h>

#include "meta-mem-types.h"
#include "meta.h"
#include <glusterfs/statedump.h>

static int
mallinfo_file_fill(xlator_t *this, inode_t *file, strfd_t *strfd)
{
    gf_proc_dump_mallinfo(strfd);
    return strfd->size;
}

static struct meta_ops mallinfo_file_ops = {
    .file_fill = mallinfo_file_fill,
};

int
meta_mallinfo_file_hook(call_frame_t *frame, xlator_t *this, loc_t *loc,
                        dict_t *xdata)
{
    meta_ops_set(loc->inode, this, &mallinfo_file_ops);

    return 0;
}
