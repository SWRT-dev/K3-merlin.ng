#!/bin/sh

VERSIONCMP=versioncmp

if [ ! -d /jffs/softcenter ]; then
	mkdir -p /jffs/softcenter
	cp -rf /rom/etc/softcenter/* /jffs/softcenter/
fi
mkdir -p /jffs/softcenter/init.d
mkdir -p /jffs/softcenter/bin
mkdir -p /jffs/softcenter/scripts
mkdir -p /jffs/softcenter/webs
mkdir -p /jffs/softcenter/res
mkdir -p /jffs/softcenter/ss
mkdir -p /jffs/softcenter/lib
mkdir -p /jffs/configs/dnsmasq.d

#check all dir version
#for d in "/rom/etc/softcenter/"* ; do
#	basedir=`basename $d`
#	cmp=`$VERSIONCMP /jffs/softcenter/$basedir/version $d/version`
#	if [ "$cmp" == "1" ]; then
#		#/rom/etc/softcenter/xx is newer, so override all exists files
#		cp -rf $d /jffs/softcenter/
#	fi
#done


if [ ! -f "/jffs/softcenter/init.d/S10softcenter.sh" ]; then
	cp /rom/etc/softcenter/scripts/* /jffs/softcenter/scripts/
	cp /rom/etc/softcenter/res/* /jffs/softcenter/res/
	cp /rom/etc/softcenter/webs/* /jffs/softcenter/webs/
	cp /rom/etc/softcenter/bin/* /jffs/softcenter/bin/
	cp -rf /rom/etc/softcenter/perp /jffs/softcenter/
	chmod 755 /jffs/softcenter/scripts/*.sh
	ln -sf /jffs/softcenter/scripts/ks_app_install.sh /jffs/softcenter/init.d/S10softcenter.sh
	ln -sf /jffs/softcenter/scripts/ks_app_install.sh /jffs/softcenter/scripts/ks_app_remove.sh
fi

if [ ! -d /jffs/softcenter/configs ]; then
	mkdir -p /jffs/softcenter/configs
	mkdir -p /jffs/softcenter/scripts
	cp /rom/etc/configs/* /jffs/softcenter/configs/

	chmod 755 /jffs/softcenter/configs/*.sh
	chmod 755 /jffs/softcenter/scripts/*.sh
fi


chmod 755 /jffs/softcenter/ss/cru/*


# creat wan-start file
mkdir -p /jffs/scripts
if [ ! -f /jffs/scripts/nat-start ]; then
cat > /jffs/scripts/nat-start <<EOF
#!/bin/sh
dbus fire onnatstart

EOF
chmod 755 /jffs/scripts/nat-start
fi

# creat nat-start file
if [ ! -f /jffs/scripts/wan-start ]; then
cat > /jffs/scripts/wan-start <<EOF
#!/bin/sh
dbus fire onwanstart

EOF
chmod 755 /jffs/scripts/wan-start
fi

# creat profile file
if [ ! -f /jffs/configs/profile.add ]; then
cat > /jffs/configs/profile.add <<EOF
alias ls='ls -Fp --color=auto'
alias ll='ls -lFp --color=auto'
alias l='ls -AlFp --color=auto'
source /jffs/softcenter/scripts/base.sh
export PERP_BASE=/softcenter/perp

EOF
fi

# fix wan and screen
i=0
while [ $i -le 20 ]; do
      success_start_service=`nvram get success_start_service`
      if [ "$success_start_service" == "1" ]; then
              break
      fi
      i=$(($i+1))
      echo "autorun APP: wait $i seconds...";
      sleep 1
done
wans_dualwan=`nvram get wans_dualwan`
if [ "$wans_dualwan" = "wan lan" ]; then
    nvram set wanports="3"
    nvram set wan1ports="2"
    nvram set lanports="0 1"
    nvram set vlan1ports="0 1 5 7 8*"
    nvram set vlan2ports="3 8t"
    nvram set vlan3ports="2 8t"
    robocfg vlans reset vlan 3 ports "2 8t" vlan 2 ports "3 8t" vlan 1 ports "0 1 5u 7 8t"
    service net_restart
else
    nvram set wanports="3"
    nvram set lanports="0 1 2"
    nvram set vlan1ports="0 1 2 5 7 8*"
    nvram set vlan2ports="3 8u"
    robocfg vlans reset vlan 2 ports "3 8u" vlan 1 ports "0 1 2 5u 7 8t"
    service net_restart
fi
