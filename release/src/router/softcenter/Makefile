include ../common.mak

all:

install:
	install -d $(INSTALLDIR)/usr/sbin
	install -d $(INSTALLDIR)/usr/bin
	install -d $(INSTALLDIR)/usr/share
	install -d $(INSTALLDIR)/mcu
	install -d $(INSTALLDIR)/rom/etc/softcenter/bin
	install -d $(INSTALLDIR)/rom/etc/softcenter/res
	install -d $(INSTALLDIR)/rom/etc/softcenter/webs
	install -d $(INSTALLDIR)/rom/etc/softcenter/perp
	install -d $(INSTALLDIR)/rom/etc/softcenter/scripts
	install -d $(INSTALLDIR)/rom/etc/softcenter/perp/.boot
	install -d $(INSTALLDIR)/rom/etc/softcenter/perp/.control
	install -d $(INSTALLDIR)/rom/cfe/

# softcenter
	install -m 0755 softcenter/bin/perpboot $(INSTALLDIR)/rom/etc/softcenter/bin
	install -m 0755 softcenter/bin/perpctl $(INSTALLDIR)/rom/etc/softcenter/bin
	install -m 0755 softcenter/bin/perpd $(INSTALLDIR)/rom/etc/softcenter/bin
	install -m 0755 softcenter/bin/perphup $(INSTALLDIR)/rom/etc/softcenter/bin
	install -m 0755 softcenter/bin/perpls $(INSTALLDIR)/rom/etc/softcenter/bin
	install -m 0755 softcenter/bin/perpok $(INSTALLDIR)/rom/etc/softcenter/bin
	install -m 0755 softcenter/bin/perpstat $(INSTALLDIR)/rom/etc/softcenter/bin
	install -m 0755 softcenter/bin/sissylog $(INSTALLDIR)/rom/etc/softcenter/bin
	install -m 0755 softcenter/bin/tinylog $(INSTALLDIR)/rom/etc/softcenter/bin
	install -m 0755 softcenter/bin/versioncmp $(INSTALLDIR)/rom/etc/softcenter/bin
	install -m 0755 softcenter/res/icon-default.png $(INSTALLDIR)/rom/etc/softcenter/res
	install -m 0755 softcenter/res/softcenter.js $(INSTALLDIR)/rom/etc/softcenter/res
	install -m 0755 softcenter/webs/Main_Soft_center.asp $(INSTALLDIR)/rom/etc/softcenter/webs
	install -m 0755 softcenter/webs/Main_Soft_setting.asp $(INSTALLDIR)/rom/etc/softcenter/webs
	install -m 0755 softcenter/perp/perp.sh $(INSTALLDIR)/rom/etc/softcenter/perp
	install -m 0755 softcenter/perp/.boot/rc.log $(INSTALLDIR)/rom/etc/softcenter/perp/.boot
	install -m 0755 softcenter/perp/.boot/rc.perp $(INSTALLDIR)/rom/etc/softcenter/perp/.boot
	install -m 0755 softcenter/perp/.control/perpd.pid $(INSTALLDIR)/rom/etc/softcenter/perp/.control
	install -m 0755 softcenter/scripts/base.sh $(INSTALLDIR)/rom/etc/softcenter/scripts
	install -m 0755 softcenter/scripts/ks_app_install.sh $(INSTALLDIR)/rom/etc/softcenter/scripts
	install -m 0755 softcenter/scripts/ks_tar_intall.sh $(INSTALLDIR)/rom/etc/softcenter/scripts
	install -m 0755 softcenter/scripts/pluginbase.sh $(INSTALLDIR)/rom/etc/softcenter/scripts
	install -m 0755 jffsinit.sh $(INSTALLDIR)/usr/sbin
	install -m 0755 uhmiMsg $(INSTALLDIR)/usr/sbin
	install -m 0644 mcu/app.2.2.120.bin $(INSTALLDIR)/mcu
	install -m 0644 mcu/app.1.2.116.hex $(INSTALLDIR)/mcu
	install -m 0644 mcu/app.1.1.116.hex $(INSTALLDIR)/mcu
	install -m 0755 phi_speed $(INSTALLDIR)/usr/sbin
	install -m 0755 plugin.sh $(INSTALLDIR)/usr/sbin
	install -m 0755 uhmi $(INSTALLDIR)/usr/sbin
	install -m 0755 weather $(INSTALLDIR)/usr/sbin
	install -m 0755 wl_cr $(INSTALLDIR)/usr/sbin
	install -m 0755 helper.sh $(INSTALLDIR)/usr/sbin
	install -m 0755 libwlcr.so $(INSTALLDIR)/usr/share
	install -m 0644 cfe.bin $(INSTALLDIR)/rom/cfe/

clean:
