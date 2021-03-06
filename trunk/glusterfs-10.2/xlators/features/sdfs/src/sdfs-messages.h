/*
 Copyright (c) 2016 Red Hat, Inc. <http://www.redhat.com>
 This file is part of GlusterFS.

 This file is licensed to you under your choice of the GNU Lesser
 General Public License, version 3 or any later version (LGPLv3 or
 later), or the GNU General Public License, version 2 (GPLv2), in all
 cases as published by the Free Software Foundation.
 */

#ifndef _DFS_MESSAGES_H_
#define _DFS_MESSAGES_H_

#include <glusterfs/glfs-message-id.h>

/* file bit-rot-bitd-messages.h
 * brief SDFS log-message IDs and their descriptions
 */

/* NOTE: Rules for message additions
 * 1) Each instance of a message is _better_ left with a unique message ID, even
 *    if the message format is the same. Reasoning is that, if the message
 *    format needs to change in one instance, the other instances are not
 *    impacted or the new change does not change the ID of the instance being
 *    modified.
 * 2) Addition of a message,
 *       - Should increment the GLFS_NUM_MESSAGES
 *       - Append to the list of messages defined, towards the end
 *       - Retain macro naming as glfs_msg_X (for redability across developers)
 * NOTE: Rules for message format modifications
 * 3) Check acorss the code if the message ID macro in question is reused
 *    anywhere. If reused then then the modifications should ensure correctness
 *    everywhere, or needs a new message ID as (1) above was not adhered to. If
 *    not used anywhere, proceed with the required modification.
 * NOTE: Rules for message deletion
 * 4) Check (3) and if used anywhere else, then cannot be deleted. If not used
 *    anywhere, then can be deleted, but will leave a hole by design, as
 *    addition rules specify modification to the end of the list and not filling
 *    holes.
 */

#define GLFS_SDFS_BASE GLFS_MSGID_COMP_SDFS
#define GLFS_SDFS_NUM_MESSAGES 2
#define GLFS_MSGID_END (GLFS_SDFS_BASE + GLFS_SDFS_NUM_MESSAGES + 1)
/* Messaged with message IDs */
#define glfs_msg_start_x GLFS_DFS_BASE, "Invalid: Start of messages"
/*------------*/

#define SDFS_MSG_ENTRYLK_ERROR (GLFS_SDFS_BASE + 1)
/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */

#define SDFS_MSG_MKDIR_ERROR (GLFS_SDFS_BASE + 2)
/*!
 * @messageid
 * @diagnosis
 * @recommendedaction
 *
 */
/*------------*/

#define glfs_msg_end_x GLFS_MSGID_END, "Invalid: End of messages"
#endif /* !_SDFS_MESSAGES_H_ */
