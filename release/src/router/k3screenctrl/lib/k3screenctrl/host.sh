#!/bin/bash
# Copyright (C) 2018 XiaoShan mivm.cn

temp_dir=/tmp/k3screenctrl
dhcp_leases="/var/lib/misc/dnsmasq.leases"
lan_ip=$(nvram get lan_ipaddr | awk -F . '{print $1"."$2"."$3"."}')
device_list_ip=($(cat $dhcp_leases | grep "$lan_ip" | awk '{print $3}'))
device_list_mac=($(cat $dhcp_leases | awk '{print $2}'))
device_list_host=($(cat $dhcp_leases | awk '{print $4}' | sed 's/*//g'))
oui_data=$(cat /lib/k3screenctrl/oui/oui.txt)
online_code_data=$(cat $temp_dir/device_online)
device_custom_data=$(cat $temp_dir/device_custom)

for ((i=0;i<${#device_list_ip[@]};i++))
do
	online_code=$(echo -e "$online_code_data" | grep ${device_list_ip[i]} | awk '{print $2}') && [ -z "$online_code" ] && online_code=0
	[ $online_code -ne 0 ] && continue
	hostmac=${device_list_mac[i]//:/}
	device_custom=($(echo -e "$device_custom_data" | grep -w -i ${device_list_mac[i]}))
	name=${device_custom[1]=${device_list_host[i]}}
	logo=${device_custom[2]=$(echo -e "$oui_data" | grep -w -i ${hostmac:0:6} | awk '{print $1}')}
	[ "$name" = "?" -o -z "$name" ] && name=${device_list_host[i]}
	[ "$name" = "*" -o -z "$name" ] && name="Unknown"
	up=0
	dp=0
	temp_data="$name\n$dp\n$up\n${logo:=0}\n"
	data=${data}${temp_data}
	x=$(($x + 1))
done
echo ${x=0}
echo -e "${data=""}"
