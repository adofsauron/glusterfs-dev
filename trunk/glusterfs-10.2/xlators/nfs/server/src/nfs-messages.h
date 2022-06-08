/*Copyright (c) 2015 Red Hat, Inc. <http://www.redhat.com>
  This file is part of GlusterFS.

  This file is licensed to you under your choice of the GNU Lesser
  General Public License, version 3 or any later version (LGPLv3 or
  later), or the GNU General Public License, version 2 (GPLv2), in all
  cases as published by the Free Software Foundation.
*/

#ifndef _NFS_MESSAGES_H_
#define _NFS_MESSAGES_H_

#include <glusterfs/glfs-message-id.h>

/* To add new message IDs, append new identifiers at the end of the list.
 *
 * Never remove a message ID. If it's not used anymore, you can rename it or
 * leave it as it is, but not delete it. This is to prevent reutilization of
 * IDs by other messages.
 *
 * The component name must match one of the entries defined in
 * glfs-message-id.h.
 */

GLFS_MSGID(
    NFS, NFS_MSG_UNUSED_1, NFS_MSG_UNUSED_2, NFS_MSG_INVALID_ENTRY,
    NFS_MSG_INODE_LOC_FILL_ERROR, NFS_MSG_HARD_RESOLVE_FAIL,
    NFS_MSG_ARGS_DECODE_ERROR, NFS_MSG_LOOKUP_PROC_FAIL, NFS_MSG_UNUSED_8,
    NFS_MSG_UNUSED_9, NFS_MSG_READLINK_PROC_FAIL, NFS_MSG_UNUSED_11,
    NFS_MSG_ANONYMOUS_FD_FAIL, NFS_MSG_READ_FAIL, NFS_MSG_UNUSED_14,
    NFS_MSG_UNUSED_15, NFS_MSG_STATE_WRONG, NFS_MSG_WRITE_FAIL,
    NFS_MSG_UNUSED_18, NFS_MSG_UNUSED_19, NFS_MSG_UNUSED_20,
    NFS_MSG_CREATE_FAIL, NFS_MSG_UNUSED_22, NFS_MSG_UNUSED_23,
    NFS_MSG_DIR_OP_FAIL, NFS_MSG_UNUSED_25, NFS_MSG_SYMLINK_FAIL,
    NFS_MSG_UNUSED_27, NFS_MSG_MKNOD_FAIL, NFS_MSG_OPT_INIT_FAIL,
    NFS_MSG_UNUSED_30, NFS_MSG_REMOVE_FAIL, NFS_MSG_RMDIR_CBK,
    NFS_MSG_UNUSED_33, NFS_MSG_RENAME_FAIL, NFS_MSG_UNUSED_35,
    NFS_MSG_LINK_FAIL, NFS_MSG_UNUSED_37, NFS_MSG_UNUSED_38,
    NFS_MSG_READDIR_FAIL, NFS_MSG_READDIRP_FAIL, NFS_MSG_UNUSED_41,
    NFS_MSG_UNUSED_42, NFS_MSG_FSTAT_FAIL, NFS_MSG_UNUSED_44,
    NFS_MSG_FSINFO_FAIL, NFS_MSG_UNUSED_46, NFS_MSG_PATHCONF_FAIL,
    NFS_MSG_UNUSED_48, NFS_MSG_COMMIT_FAIL, NFS_MSG_PROT_INIT_ADD_FAIL,
    NFS_MSG_FORMAT_FAIL, NFS_MSG_SNPRINTF_FAIL, NFS_MSG_VOLID_MISSING,
    NFS_MSG_PARSE_VOL_UUID_FAIL, NFS_MSG_STR2BOOL_FAIL,
    NFS_MSG_SUBVOL_INIT_FAIL, NFS_MSG_NO_MEMORY, NFS_MSG_LISTENERS_CREATE_FAIL,
    NFS_MSG_STATE_INIT_FAIL, NFS_MSG_RECONF_FAIL, NFS_MSG_RECONF_SUBVOL_FAIL,
    NFS_MSG_STR_TOO_LONG, NFS_MSG_STATE_MISSING, NFS_MSG_INDEX_NOT_FOUND,
    NFS_MSG_EXPORT_ID_FAIL, NFS_MSG_NO_RW_ACCESS, NFS_MSG_BAD_HANDLE,
    NFS_MSG_RESOLVE_FH_FAIL, NFS_MSG_RESOLVE_STAT, NFS_MSG_VOL_DISABLE,
    NFS_MSG_INIT_CALL_STAT_FAIL, NFS_MSG_ENCODE_FAIL,
    NFS_MSG_SERIALIZE_REPLY_FAIL, NFS_MSG_SUBMIT_REPLY_FAIL, NFS_MSG_UNUSED_75,
    NFS_MSG_UNUSED_76, NFS_MSG_STAT_FOP_FAIL, NFS_MSG_GETATTR_FAIL,
    NFS_MSG_UNUSED_79, NFS_MSG_UNUSED_80, NFS_MSG_TIMESTAMP_NO_SYNC,
    NFS_MSG_SETATTR_INVALID, NFS_MSG_SETATTR_FAIL, NFS_MSG_UNUSED_84,
    NFS_MSG_ACCESS_PROC_FAIL, NFS_MSG_PGM_NOT_FOUND, NFS_MSG_PGM_INIT_FAIL,
    NFS_MSG_PGM_REG_FAIL, NFS_MSG_LOOKUP_ROOT_FAIL, NFS_MSG_ROOT_LOC_INIT_FAIL,
    NFS_MSG_STARTUP_FAIL, NFS_MSG_XLATOR_INIT_FAIL, NFS_MSG_NFS_MAN_DISABLE,
    NFS_MSG_DICT_GET_FAILED, NFS_MSG_PARSE_FAIL, NFS_MSG_NLM_MAN_DISABLE,
    NFS_MSG_ACL_MAN_DISABLE, NFS_MSG_DICT_SET_FAILED,
    NFS_MSG_INIT_GRP_CACHE_FAIL, NFS_MSG_NO_PERM, NFS_MSG_REG_FILE_ERROR,
    NFS_MSG_RPC_INIT_FAIL, NFS_MSG_RPC_CONFIG_FAIL, NFS_MSG_RECONFIG_PATH,
    NFS_MSG_RECONFIG_VALUE, NFS_MSG_RECONFIG_VOL, NFS_MSG_NLM_INFO,
    NFS_MSG_ACL_INFO, NFS_MSG_INIT_FAIL, NFS_MSG_STARTED, NFS_MSG_VOL_NOT_FOUND,
    NFS_MSG_RECONFIG_ENABLE, NFS_MSG_RECONFIG_FAIL, NFS_MSG_MNT_STATE_NOT_FOUND,
    NFS_MSG_ENCODE_MSG_FAIL, NFS_MSG_REP_SUBMIT_FAIL, NFS_MSG_READ_LOCKED,
    NFS_MSG_MODIFY_LOCKED, NFS_MSG_RWTAB_OVERWRITE_FAIL, NFS_MSG_UPDATE_FAIL,
    NFS_MSG_OPEN_FAIL, NFS_MSG_LOCK_FAIL, NFS_MSG_REWRITE_ERROR,
    NFS_MSG_HASH_PATH_FAIL, NFS_MSG_LOOKUP_MNT_ERROR,
    NFS_MSG_GET_ROOT_INODE_FAIL, NFS_MSG_RESOLVE_INODE_FAIL,
    NFS_MSG_RESOLVE_SUBDIR_FAIL, NFS_MSG_RESOLVE_SYMLINK_ERROR,
    NFS_MSG_RESOLVE_ERROR, NFS_MSG_UNSUPPORTED_VERSION,
    NFS_MSG_AUTH_VERIFY_FAILED, NFS_MSG_PEER_NOT_ALLOWED,
    NFS_MSG_GET_PEER_ADDR_FAIL, NFS_MSG_BAD_PEER, NFS_MSG_PEER_TOO_LONG,
    NFS_MSG_CALLER_NOT_FOUND, NFS_MSG_GET_REMOTE_NAME_FAIL,
    NFS_MSG_UNKNOWN_MNT_TYPE, NFS_MSG_PARSE_HOSTSPEC_FAIL,
    NFS_MSG_PARSE_AUTH_PARAM_FAIL, NFS_MSG_SET_EXP_FAIL,
    NFS_MSG_INIT_DIR_EXP_FAIL, NFS_MSG_DIR_EXP_SETUP_FAIL,
    NFS_MSG_VOL_INIT_FAIL, NFS_MSG_AUTH_ERROR, NFS_MSG_UPDATING_EXP,
    NFS_MSG_SET_EXP_AUTH_PARAM_FAIL, NFS_MSG_UPDATING_NET_GRP,
    NFS_MSG_SET_NET_GRP_FAIL, NFS_MSG_PURGING_AUTH_CACHE,
    NFS_MSG_MNT_STATE_INIT_FAIL, NFS_MSG_EXP_AUTH_DISABLED,
    NFS_MSG_FH_TO_VOL_FAIL, NFS_MSG_INODE_SHARES_NOT_FOUND,
    NFS_MSG_VOLUME_ERROR, NFS_MSG_GET_USER_ACL_FAIL, NFS_MSG_GET_DEF_ACL_FAIL,
    NFS_MSG_SET_USER_ACL_FAIL, NFS_MSG_SET_DEF_ACL_FAIL, NFS_MSG_ACL_INIT_FAIL,
    NFS_MSG_LOAD_PARSE_ERROR, NFS_MSG_CLNT_CALL_ERROR,
    NFS_MSG_CLNT_CREATE_ERROR, NFS_MSG_NLM_GRACE_PERIOD, NFS_MSG_RPC_CLNT_ERROR,
    NFS_MSG_GET_PORT_ERROR, NFS_MSG_NLMCLNT_NOT_FOUND, NFS_MSG_FD_LOOKUP_NULL,
    NFS_MSG_SM_NOTIFY, NFS_MSG_NLM_INIT_FAIL, NFS_MSG_START_ERROR,
    NFS_MSG_UNLINK_ERROR, NFS_MSG_SHARE_LIST_STORE_FAIL,
    NFS_MSG_CLIENT_NOT_FOUND, NFS_MSG_SHARE_CALL_FAIL,
    NFS_MSG_UNSHARE_CALL_FAIL, NFS_MSG_GET_PID_FAIL, NFS_MSG_ARG_FREE_FAIL,
    NFS_MSG_PMAP_UNSET_FAIL, NFS_MSG_UDP_SERV_FAIL, NFS_MSG_REG_NLMCBK_FAIL,
    NFS_MSG_TCP_SERV_FAIL, NFS_MSG_SVC_RUN_RETURNED, NFS_MSG_XLATOR_SET_FAIL,
    NFS_MSG_SVC_ERROR, NFS_MSG_GET_FH_FAIL, NFS_MSG_FIND_FIRST_MATCH_FAIL,
    NFS_MSG_NETGRP_NOT_FOUND, NFS_MSG_FILE_OP_FAILED, NFS_MSG_PATH_RESOLVE_FAIL,
    NFS_MSG_LOC_FILL_RESOLVE_FAIL, NFS_MSG_INODE_NOT_FOUND,
    NFS_MSG_INODE_CTX_STORE_FAIL, NFS_MSG_GETPWUID_FAIL,
    NFS_MSG_MAP_GRP_LIST_FAIL, NFS_MSG_PARSE_DIR_FAIL, NFS_MSG_LOOKUP_FAIL,
    NFS_MSG_STAT_ERROR, NFS_MSG_GFID_DICT_CREATE_FAIL, NFS_MSG_HASH_XLATOR_FAIL,
    NFS_MSG_ENABLE_THROTTLE_FAIL);

#endif /* _NFS_MESSAGES_H_ */
