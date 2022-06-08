/*
  Copyright (c) 2018 Red Hat, Inc. <http://www.redhat.com>
  This file is part of GlusterFS.

  This file is licensed to you under your choice of the GNU Lesser
  General Public License, version 3 or any later version (LGPLv3 or
  later), or the GNU General Public License, version 2 (GPLv2), in all
  cases as published by the Free Software Foundation.
*/

/* File: utime-autogen-fops-tmpl.c
 * This file contains the utime autogenerated FOPs. This is run through
 * the code generator, generator.py to generate the required FOPs.
 */

#ifndef _CONFIG_H
#define _CONFIG_H
#include "config.h"
#endif

#include <glusterfs/glusterfs.h>
#include <glusterfs/xlator.h>
#include <glusterfs/logging.h>
#include <glusterfs/statedump.h>
#include "utime-helpers.h"
#include <glusterfs/timespec.h>

#pragma generate
