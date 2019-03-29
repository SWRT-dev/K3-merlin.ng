#!/bin/sh

eval $(/usr/sbin/robocfg show 2>/dev/null | awk 'NR==2,NR==5{printf $3" "}' | awk '{printf("LAN2=%s; LAN1=%s; LAN3=%s; WAN1=%s;",$1,$2,$3,$4)}')
  [ "$LAN2" = "DOWN" ] && LAN2="0" || LAN2="1"
  [ "$LAN1" = "DOWN" ] && LAN1="0" || LAN1="1"
  [ "$LAN3" = "DOWN" ] && LAN3="0" || LAN3="1"
  [ "$WAN1" = "DOWN" ] && WAN1="0" || WAN1="1"

echo $LAN1
echo $LAN2
echo $LAN3
echo $WAN1
echo 0
