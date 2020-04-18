#!/bin/sh

source /jffs/softcenter/scripts/base.sh
nvram set jffs2_scripts=1
nvram commit

#============================================
# check start up scripts 
dbus set softcenter_firmware_version=`nvram get extendno|cut -d "_" -f2|cut -d "-" -f1|cut -c2-6`
#============================================

