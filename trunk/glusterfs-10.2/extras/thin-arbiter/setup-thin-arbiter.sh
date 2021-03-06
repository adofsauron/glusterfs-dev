#!/bin/bash
#  Copyright (c) 2018-2019 Red Hat, Inc. <http://www.redhat.com>
#  This file is part of GlusterFS.
#
#  This file is licensed to you under your choice of the GNU Lesser
#  General Public License, version 3 or any later version (LGPLv3 or
#  later), or the GNU General Public License, version 2 (GPLv2), in all
#  cases as published by the Free Software Foundation.


#  This tool has been developed to setup thin-arbiter process on a node.
#  Seting up a thin arbiter process involves following files -
#  1 - thin-arbiter.vol
#  Thin-arbiter (TA) process will use the graph in this file to load the
#  required translators.
#  2 - gluster-ta-volume.service (generated by gluster-ta-volume.service.in)
#  TA process would be running as systemd service.
#
#  TA process uses a location to save TA id files for every subvolume.
#  This location can be taken as input from user. Once provided and the
#  TA process is started on a node, it can not be changed using this
#  script or by any other mean. The same location should be used in
#  the gluster CLI when creating thin-arbiter volumes.

MYPATH=`dirname $0`

volloc="/var/lib/glusterd/thin-arbiter"
mkdir -p $volloc

if [ -f /etc/glusterfs/thin-arbiter.vol ]; then
    volfile=/etc/glusterfs/thin-arbiter.vol
else
    volfile=$MYPATH/thin-arbiter.vol
fi

tafile="$volloc/thin-arbiter.vol"


help () {
    echo " "
    echo '  This tool helps to setup thin-arbiter (TA) process on a node.
  TA process uses a location to save TA id files for every subvolume.
  This location can be taken as input from user. Once provided and the
  TA process is started on a node, it can not be changed using this script
  or by any other mean. The same location should be used in gluster CLI
  when creating thin-arbiter volumes.

  usage: setup-thin-arbiter.sh [-s] [-h]
    options:
    -s - Setup thin-arbiter file path and start process
    -h - Show this help message and exit
'
}

volfile_set_brick_path () {
    while read -r line
    do
        dir=`echo "$line" | cut -d' ' -f 2`
        if [ "$dir" = "directory" ]; then
            bpath=`echo "$line" | cut -d' ' -f 3`
            sed -i -- 's?'$bpath'?'$1'?g' $tafile
            return
        fi
    done < $tafile
}

check_ta_proc () {
    pro=`ps aux | grep thin-arbiter.vol | grep "volfile-id"`
    if [ "${pro}" = '' ]; then
            echo ""
    else
        curr_loc=`cat $volloc/thin-arbiter.vol | grep option | grep directory`
        loc=`echo "${curr_loc##* }"`
        echo "******************************************************"
        echo "Error:"
        echo "Thin-arbiter process is running with thin-arbiter path = $loc"
        echo "Can not change TA path on this host now."
        echo "$pro"
        echo "******************************************************"
        exit 1
    fi
}

getpath () {
    check_ta_proc
    echo "******************************************************"
    echo "User will be required to enter a path/folder for arbiter volume."
    echo "Please note that this path will be used for ALL VOLUMES using this"
    echo "node to host thin-arbiter. After setting, if a volume"
    echo "has been created using this host and path then path for"
    echo "thin-arbiter can not be changed "
    echo "******************************************************"
    echo " "
    while true;
    do
        echo -n "Enter brick path for thin arbiter volumes: "
        echo " "
        read tapath
        if [ "${tapath}" = '' ]; then
            echo "Please enter valid path"
            continue
        else
            echo "Entered brick path : $tapath "
            echo "Please note that this brick path will be used for ALL"
            echo "VOLUMES using this node to host thin-arbiter brick"
            echo -n "Want to continue? (y/N): "
            echo " "
            read cont

            if [ "${cont}" = 'N' ] || [ "${cont}" = 'n' ]; then
                exit 0
            else
                break
            fi
        fi
    done
}

setup () {
    getpath
    mkdir -p $tapath/.glusterfs/indices
    if [ -d $tapath/.glusterfs/indices ]; then
        echo " "
    else
        echo "Could not create $tapath/.glusterfs/indices directory, check provided ta path."
        exit 1
    fi

    cp -f --backup --suffix=_old $volfile $volloc/thin-arbiter.vol
    volfile_set_brick_path "$tapath"

    echo "Directory path to be used for thin-arbiter volume is: $tapath"
    echo " "
    echo "========================================================"

    if [ -f /usr/lib/systemd/system/gluster-ta-volume.service ]; then
        echo "Starting thin-arbiter process"
    else
        cp $MYPATH/../systemd/gluster-ta-volume.service /etc/systemd/system/
        echo "Starting thin-arbiter process"
        chmod 0644 /etc/systemd/system/gluster-ta-volume.service
    fi

    systemctl daemon-reload
    systemctl enable gluster-ta-volume
    systemctl stop gluster-ta-volume
    systemctl start gluster-ta-volume

    if [ $? == 0 ]; then
        echo "thin-arbiter process has been setup and running"
    else
        echo "Failed to setup thin arbiter"
        exit 1
    fi

}

main()
{

    if [ "$#" -ne 1 ]; then
        help
        exit 0
    fi

    while getopts "sh" opt; do
        case $opt in
            h)
                help
                exit 0
                ;;
            s)
                setup
                exit 0
                ;;
            *)
                help
                exit 0
                ;;
        esac
    done
}

main "$@"
