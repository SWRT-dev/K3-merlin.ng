#!/bin/sh

24ssid=`nvram get wl0_ssid`
24pd=`nvram get wl0_wpa_psk`
24en=`nvram get wl0_bss_enabled`
24cc=`wl eth1 authe_sta_list | wc -l`
5ssid=`nvram get wl1_ssid`
5pd=`nvram get wl1_wpa_psk`
5en=`nvram get wl1_bss_enabled`
5cc=`wl eth2 authe_sta_list | wc -l`
echo 0
echo ${24ssid}
echo ${24pd}
echo $24en
echo $24cc
echo ${5ssid}
echo ${5pd}
echo $5en
echo $5cc
echo
echo
echo 0
echo 0
