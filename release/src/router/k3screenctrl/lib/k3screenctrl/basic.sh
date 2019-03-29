#!/bin/sh
if [ -n `nvram get et2macaddr` ]; then
    MAC_ADDR=$(nvram get et2macaddr)
else
    MAC_ADDR=$(nvram get k3macaddr)
fi
BUILD_NO=`nvram get buildno`
EXTEND_NO=`nvram get extendno`
swmode=`nvram get sw_mode`
if [ "$swmode" == "1" ]; then
FW_VERSION="$BUILD_NO"_"$EXTEND_NO"
else
FW_VERSION=AP:$(nvram get lan_ipaddr)
fi
echo K3
echo A1/A2
echo ${FW_VERSION}
echo $MAC_ADDR

