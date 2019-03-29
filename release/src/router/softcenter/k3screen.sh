#!/bin/sh

BUILD_NO=`nvram get buildno`
EXTEND_NO=`nvram get extendno`
FW_VERSION="$BUILD_NO"_"$EXTEND_NO"
nvram set hd_version=A1/A2
nvram set product=K3
nvram set fw_version=$FW_VERSION
nvram set wan_pppoe_ifname=ppp0
nvram set wan_ifname=vlan2
nvram set bsd_role=0
nvram set pingcheck=1
nvram set get_wan_port_status=1
devmem 0x1800c1c1 32 0x00001f0f
phi_speed & 
wl_cr &
uhmi &
while [ 1 ]
do
weather update_weather
sleep 3600
done;
