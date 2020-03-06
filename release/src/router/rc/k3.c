/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 *
 * Copyright 2018-2020, paldier<paldier@hotmail.com>.
 * All Rights Reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "rc.h"
#include <shared.h>
#include <shutils.h>
#include <siutils.h>
#include <auth_common.h>
#include "k3.h"

#include <curl/curl.h>

int k3_nvram_set(const char *name, const char *value);
void k3_nvram_patch();

void k3_init()
{
	char mac1[] = "00:90:4c:18:d2:34";
	char mac2[] = "00:90:4c:18:d2:34";
	char mac3[] = "00:90:4c:18:d2:34";
	unsigned char mac_binary[6];
	unsigned char mac_binary2[6];
	_dprintf("############################ k3 init nvram #################################\n");
	if (!nvram_get("boardrev"))
		nvram_set("boardrev", "0x1500");
	if (strcmp(nvram_safe_get("chiprev"), "0x3")){
		nvram_set("chipnum", "0x4366");
		nvram_set("chiprev", "0x3");
	}
	if (nvram_get("wl0_failed"))
		nvram_unset("wl0_failed");
	if (nvram_get("wl1_failed"))
		nvram_unset("wl1_failed");
	if (!nvram_get("watchdog"))
		nvram_set("watchdog", "2100");
	if (!nvram_get("model"))
		nvram_set("model", "RT-AC3100");
	if (!nvram_get("modelname"))
		nvram_set("modelname", "K3");
	if (!nvram_get("productid"))
		nvram_set("productid", "RT-AC3100");
	if (!nvram_get("bootflags"))
		nvram_set("bootflags", "1");
	if (!nvram_get("bl_version"))
		nvram_set("bl_version", "1.0.3.9");
	if (!nvram_get("boardflags"))
		nvram_set("boardflags", "0x00000110");
	if (!nvram_get("k3macaddr"))
		nvram_set("k3macaddr", cfe_nvram_get("et0macaddr"));
//	if (!nvram_get("il0macaddr"))
	//	nvram_set("il0macaddr", nvram_get("k3macaddr"));
	strcpy(mac1,nvram_get("k3macaddr"));
	ether_atoe(mac1, mac_binary);
	ether_atoe(mac1, mac_binary2);
	strcpy(mac2,nvram_get("k3macaddr"));
	mac_binary2[5] = mac_binary[5] +4;
	ether_etoa(mac_binary2, mac3);
	if (!nvram_get("k3macaddr0"))
		nvram_set("k3macaddr0", mac2);
	if (!nvram_get("k3macaddr1"))
		nvram_set("k3macaddr1", mac3);
	if (!nvram_get("et2macaddr"))
		nvram_set("et2macaddr", nvram_get("k3macaddr"));
	if (!nvram_get("secret_code"))
		nvram_set("secret_code", "147258369");
	if (!nvram_get("territory_code"))
		nvram_set("territory_code", "US/01");
	if (nvram_get("2:pa5g40a0") || nvram_get("2:pa5g40a1")){
		nvram_unset("2:pcieingress_war");
		nvram_unset("2:mcsbw205gx1po");
		nvram_unset("2:txchain");
		nvram_unset("2:rxchain");
		nvram_unset("2:pa5g40a0");
		nvram_unset("2:pa5g40a1");
		nvram_unset("2:pa5g40a2");
		nvram_unset("2:pa5g40a3");
		nvram_unset("2:pa5g80a3");
		nvram_unset("2:pa5ga0");
		nvram_unset("2:pa5ga1");
		nvram_unset("2:pa5ga2");
		nvram_unset("2:pa5ga3");
		nvram_unset("2:pa5g80a0");
		nvram_unset("2:pa5g80a1");
		nvram_unset("2:pa5g80a2");
		nvram_unset("2:pa5g80a3");
		nvram_unset("2:ulbpdoffs5gb2a1");
		nvram_unset("2:ulbpdoffs5gb2a2");
		nvram_unset("2:ulbpdoffs5gb2a3");
		nvram_unset("2:ulbpdoffs2ga0");
		nvram_unset("2:ulbpdoffs2ga1");
		nvram_unset("2:ulbpdoffs2ga2");
		nvram_unset("2:ulbpdoffs2ga3");
		nvram_unset("2:ulbpdoffs5gb2a0");
		nvram_unset("2:ulbpdoffs5gb2a1");
		nvram_unset("2:ulbpdoffs5gb2a2");
		nvram_unset("2:ulbpdoffs5gb2a3");
		nvram_unset("2:pdoffset20in80m5gb0");
		nvram_unset("2:pdoffset20in80m5gb1");
		nvram_unset("2:pdoffset20in80m5gb2");
		nvram_unset("2:pdoffset20in80m5gb3");
		nvram_unset("2:pdoffset20in80m5gb4");
		nvram_unset("2:maxp5gb3a0");
		nvram_unset("2:maxp5gb3a1");
		nvram_unset("2:maxp5gb3a2");
		nvram_unset("2:maxp5gb3a3");
		nvram_unset("2:maxp5gb2a0");
		nvram_unset("2:maxp5gb2a1");
		nvram_unset("2:maxp5gb2a2");
		nvram_unset("2:maxp5gb2a3");
		nvram_unset("2:maxp5gb1a0");
		nvram_unset("2:maxp5gb1a1");
		nvram_unset("2:maxp5gb1a2");
		nvram_unset("2:maxp5gb1a3");
		nvram_unset("2:maxp5gb4a0");
		nvram_unset("2:maxp5gb4a1");
		nvram_unset("2:maxp5gb4a2");
		nvram_unset("2:maxp5gb4a3");
		nvram_unset("2:maxp5gb0a0");
		nvram_unset("2:maxp5gb0a1");
		nvram_unset("2:maxp5gb0a2");
		nvram_unset("2:maxp5gb0a3");
		nvram_unset("2:pdoffsetcckma0");
		nvram_unset("2:pdoffsetcckma1");
		nvram_unset("2:pdoffsetcckma2");
		nvram_unset("2:rpcal5gb0core3");
		nvram_unset("2:sb20in80and160lr5ghpo");
		nvram_unset("2:tssiposslope5g");
		nvram_unset("2:disband5grp");
		nvram_unset("2:antswitch");
		nvram_unset("2:boardflags");
		nvram_unset("2:mcsbw805glpo");
		nvram_unset("2:mcsbw805ghpo");
		nvram_unset("2:mcsbw405gx1po");
		nvram_unset("2:mcsbw405glpo");
		nvram_unset("2:mcsbw405ghpo");
		nvram_unset("2:mcsbw205gmpo");
		nvram_unset("2:mcsbw205gx2po");
		nvram_unset("2:mcsbw805gx2po");
		nvram_unset("2:mcsbw205glpo");
		nvram_unset("2:mcsbw805gx1po");
		nvram_unset("2:mcsbw405gx2po");
		nvram_unset("2:mcsbw405gmpo");
		nvram_unset("2:tempsense_slope");
		nvram_unset("2:rxgains5ghelnagaina0");
		nvram_unset("2:rxgains5ghelnagaina1");
		nvram_unset("2:rxgains5ghelnagaina2");
		nvram_unset("2:rxgains5ghelnagaina3");
		nvram_unset("2:tempoffset");
		nvram_unset("2:sb40and80lr5gmpo");
		nvram_unset("2:sb20in40hrlrpox");
		nvram_unset("2:pdoffset40in80m5gcore3");
		nvram_unset("2:pdoffset40in80m5gcore3_1");
		nvram_unset("2:sb20in80and160hr5glpo");
		nvram_unset("2:femctrl");
		nvram_unset("2:mcs1024qam5gmpo");
		nvram_unset("2:mcs1024qam5gx2po");
		nvram_unset("2:mcs1024qam5glpo");
		nvram_unset("2:mcs1024qam5ghpo");
		nvram_unset("2:mcs1024qam5gx1po");
		nvram_unset("2:rawtempsense");
		nvram_unset("2:pdoffset20in40m5gcore3_1");
		nvram_unset("2:pdoffset20in40m5gb0");
		nvram_unset("2:pdoffset20in40m5gb1");
		nvram_unset("2:pdoffset20in40m5gb2");
		nvram_unset("2:pdoffset20in40m5gb3");
		nvram_unset("2:pdoffset20in40m5gb4");
		nvram_unset("2:sb40and80lr5gx2po");
		nvram_unset("2:sb20in80and160hr5ghpo");
		nvram_unset("2:sb20in40lrpo");
		nvram_unset("2:sb40and80hr5gmpo");
		nvram_unset("2:mcslr5glpo");
		nvram_unset("2:mcslr5ghpo");
		nvram_unset("2:rxgains5gmtrelnabypa0");
		nvram_unset("2:rxgains5gmtrelnabypa1");
		nvram_unset("2:rxgains5gmtrelnabypa2");
		nvram_unset("2:rxgains5gmtrelnabypa3");
		nvram_unset("2:mcsbw1605glpo");
		nvram_unset("2:mcsbw1605ghpo");
		nvram_unset("2:mcsbw1605gx2po");
		nvram_unset("2:mcsbw1605gx1po");
		nvram_unset("2:mcsbw1605gmpo");
		nvram_unset("2:mcsbw1605gmpo");
		nvram_unset("2:dot11agduplrpo");
		nvram_unset("2:ccode");
		nvram_unset("2:rxgains5ghtrelnabypa0");
		nvram_unset("2:rxgains5ghtrelnabypa1");
		nvram_unset("2:rxgains5ghtrelnabypa2");
		nvram_unset("2:rpcal5gb0");
		nvram_unset("2:rpcal5gb1");
		nvram_unset("2:rpcal5gb2");
		nvram_unset("2:rpcal5gb3");
		nvram_unset("2:rpcal5gb4");
		nvram_unset("2:swctrlmap4_TX5g_fem7to4");
		nvram_unset("2:swctrlmap4_RX5g_fem7to4");
		nvram_unset("2:swctrlmap4_RXByp5g_fem7to4");
		nvram_unset("2:swctrlmap4_misc5g_fem7to4");
		nvram_unset("2:swctrlmap4_TX5g_fem3to0");
		nvram_unset("2:swctrlmap4_RX5g_fem3to0");
		nvram_unset("2:swctrlmap4_RXByp5g_fem3to0");
		nvram_unset("2:swctrlmap4_misc5g_fem3to0");
		nvram_unset("2:ulbpdoffs5gb1a0");
		nvram_unset("2:ulbpdoffs5gb1a1");
		nvram_unset("2:ulbpdoffs5gb1a2");
		nvram_unset("2:ulbpdoffs5gb1a3");
		nvram_unset("2:ledbh9");
		nvram_unset("2:mcs8poexp");
		nvram_unset("2:devid");
		nvram_unset("2:eu_edthresh5g");
		nvram_unset("2:sb20in80and160lr5gx2po");
		nvram_unset("2:sb40and80lr5glpo");
		nvram_unset("2:measpower1");
		nvram_unset("2:measpower2");
		nvram_unset("2:measpower");
		nvram_unset("2:sb40and80lr5ghpo");
		nvram_unset("2:mcs10poexp");
		nvram_unset("2:paparambwver");
		nvram_unset("2:sar5g");
		nvram_unset("2:gainctrlsph");
		nvram_unset("2:rpcal5gb3core3");
		nvram_unset("2:rpcal5gb1core3");
		nvram_unset("2:aga0");
		nvram_unset("2:aga1");
		nvram_unset("2:aga2");
		nvram_unset("2:aga3");
		nvram_unset("2:subband5gver");
		nvram_unset("2:ulbpdoffs5gb4a0");
		nvram_unset("2:ulbpdoffs5gb4a1");
		nvram_unset("2:ulbpdoffs5gb4a2");
		nvram_unset("2:ulbpdoffs5gb4a3");
		nvram_unset("2:sb40and80hr5glpo");
		nvram_unset("2:sb40and80hr5gx2po");
		nvram_unset("2:sb40and80hr5ghpo");
		nvram_unset("2:sb20in40hrpo");
		nvram_unset("2:noiselvl5ga0");
		nvram_unset("2:noiselvl5ga1");
		nvram_unset("2:noiselvl5ga2");
		nvram_unset("2:noiselvl5ga3");
		nvram_unset("2:ulbpdoffs5gb0a0");
		nvram_unset("2:ulbpdoffs5gb0a1");
		nvram_unset("2:ulbpdoffs5gb0a2");
		nvram_unset("2:ulbpdoffs5gb0a3");
		nvram_unset("2:pdoffsetcck");
		nvram_unset("2:pdoffset20in40m5gcore3");
		nvram_unset("2:pdoffset20in80m5gcore3");
		nvram_unset("2:boardnum");
		nvram_unset("2:dot11agduphrpo");
		nvram_unset("2:papdcap5g");
		nvram_unset("2:regrev");
		nvram_unset("2:rxgains5gtrelnabypa0");
		nvram_unset("2:rxgains5gtrelnabypa1");
		nvram_unset("2:rxgains5gtrelnabypa2");
		nvram_unset("2:rxgains5gtrelnabypa3");
		nvram_unset("2:tempcorrx");
		nvram_unset("2:mcslr5gx2po");
		nvram_unset("2:pdoffset80ma0");
		nvram_unset("2:sb20in80and160hr5gx2po");
		nvram_unset("2:pdoffset80ma1");
		nvram_unset("2:pdoffset80ma2");
		nvram_unset("2:devpath1");
		nvram_unset("2:temps_hysteresis");
		nvram_unset("2:srom13sig");
		nvram_unset("2:rxgains5gmtrisoa0");
		nvram_unset("2:rxgains5gmtrisoa1");
		nvram_unset("2:rxgains5gmtrisoa2");
		nvram_unset("2:rxgains5gmtrisoa3");
		nvram_unset("2:tempthresh");
		nvram_unset("2:rxgains5gelnagaina0");
		nvram_unset("2:rxgains5gelnagaina1");
		nvram_unset("2:rxgains5gelnagaina2");
		nvram_unset("2:rxgains5gelnagaina3");
		nvram_unset("2:phycal_tempdelta");
		nvram_unset("2:pdoffset20in80m5gcore3_1");
		nvram_unset("2:sromrev");
		nvram_unset("2:sb20in80and160lr5gmpo");
		nvram_unset("2:ulbpdoffs5gb3a0");
		nvram_unset("2:ulbpdoffs5gb3a1");
		nvram_unset("2:ulbpdoffs5gb3a2");
		nvram_unset("2:ulbpdoffs5gb3a3");
		nvram_unset("2:pdoffset40in80m5gb0");
		nvram_unset("2:pdoffset40in80m5gb1");
		nvram_unset("2:pdoffset40in80m5gb2");
		nvram_unset("2:pdoffset40in80m5gb3");
		nvram_unset("2:sb40and80hr5gx1po");
		nvram_unset("2:rxgainerr5ga0");
		nvram_unset("2:rxgainerr5ga1");
		nvram_unset("2:rxgainerr5ga2");
		nvram_unset("2:rxgainerr5ga3");
		nvram_unset("2:mcs9poexp");
		nvram_unset("2:pdoffset40in80m5gb4");
		nvram_unset("2:pdoffset40ma0");
		nvram_unset("2:pdoffset40ma1");
		nvram_unset("2:pdoffset40ma2");
		nvram_unset("2:temps_period");
		nvram_unset("2:swctrlmap4_cfg");
		nvram_unset("2:venid");
		nvram_unset("2:devpath2");
		nvram_unset("mcsbw205ghpo");
		nvram_unset("2:pdgain5g");
		nvram_unset("2:boardflags2");
		nvram_unset("2:boardflags3");
		nvram_unset("2:boardflags4");
		nvram_unset("2:rxgains5ghtrisoa0");
		nvram_unset("2:rxgains5ghtrisoa1");
		nvram_unset("2:rxgains5ghtrisoa2");
		nvram_unset("2:rxgains5ghtrisoa3");
		nvram_unset("2:rxgains5gtrisoa0");
		nvram_unset("2:rxgains5gtrisoa1");
		nvram_unset("2:rxgains5gtrisoa2");
		nvram_unset("2:rxgains5gtrisoa3");
		nvram_unset("2:rxgains5ghtrelnabypa3");
		nvram_unset("2:mcslr5gx1po");
		nvram_unset("2:mcs11poexp");
		nvram_unset("2:dot11agduphrlrpox");
		nvram_unset("2:mcsbw805gmpo");
		nvram_unset("sb20in80and160lr5glpo");
		nvram_unset("2:sb20in80and160hr5gmpo");
		nvram_unset("2:epagain5g");
		nvram_unset("2:tworangetssi5g");
		nvram_unset("2:tempsense_option");
		nvram_unset("2:sb20in80and160hr5gx1po");
		nvram_unset("2:rxgains5gmelnagaina0");
		nvram_unset("2:rxgains5gmelnagaina1");
		nvram_unset("2:rxgains5gmelnagaina2");
		nvram_unset("2:rxgains5gmelnagaina3");
		nvram_unset("2:xtalfreq");
		nvram_unset("2:aa5g");
		nvram_unset("2:txidxcap5g");
		nvram_unset("2:mcslr5gmpo");
		nvram_unset("2:rpcal5gb2core3");
		nvram_unset("2:tssifloor5g");
		nvram_unset("1:rxgainerr2ga1");
		nvram_unset("1:rxgainerr2ga2");
		nvram_unset("1:rxgainerr2ga3");
		nvram_unset("1:pdoffset20in40m2g");
		nvram_unset("1:rxgains2gtrisoa0");
		nvram_unset("1:rxgains2gtrisoa1");
		nvram_unset("1:rxgains2gtrisoa2");
		nvram_unset("1:sar2g");
		nvram_unset("1:rxgains2gtrisoa3");
		nvram_unset("1:dot11agofdmhrbw202gpo");
		nvram_unset("1:papdcap2g");
		nvram_unset("1:pa2ga0");
		nvram_unset("1:pa2ga1");
		nvram_unset("1:pa2ga2");
		nvram_unset("1:pa2ga3");
		nvram_unset("1:mcsbw402gpo");
		nvram_unset("1:ulbpdoffs2ga0");
		nvram_unset("1:ulbpdoffs2ga1");
		nvram_unset("1:ulbpdoffs2ga2");
		nvram_unset("1:ulbpdoffs2ga3");
		nvram_unset("1:swctrlmap4_TX2g_fem7to4");
		nvram_unset("1:mcsbw202gpo");
		nvram_unset("1:ofdmlrbw202gpo");
		nvram_unset("1:pdoffset20in40m2gcore3");
		nvram_unset("1:rxgains2gtrelnabypa0");
		nvram_unset("1:rxgains2gtrelnabypa1");
		nvram_unset("1:rxgains2gtrelnabypa2");
		nvram_unset("1:rxgains2gtrelnabypa3");
		nvram_unset("1:pdoffset2gcck");
		nvram_unset("1:swctrlmap4_RX2g_fem7to4");
		nvram_unset("1:pdgain2g");
		nvram_unset("1:swctrlmap4_RXByp2g_fem7to4");
		nvram_unset("1:swctrlmap4_misc2g_fem7to4");
		nvram_unset("1:cckbw202gpo");
		nvram_unset("1:agbg0");
		nvram_unset("1:agbg1");
		nvram_unset("1:agbg2");
		nvram_unset("1:agbg3");
		nvram_unset("1:epagain2g");
		nvram_unset("1:rxgains2gelnagaina0");
		nvram_unset("1:rxgains2gelnagaina1");
		nvram_unset("1:rxgains2gelnagaina2");
		nvram_unset("1:rxgains2gelnagaina3");
		nvram_unset("1:swctrlmap4_TX2g_fem3to0");
		nvram_unset("1:tworangetssi2g");
		nvram_unset("1:aa2g");
		nvram_unset("1:txidxcap2g");
		nvram_unset("1:tssifloor2g");
		nvram_unset("1:maxp2ga0");
		nvram_unset("1:maxp2ga1");
		nvram_unset("1:maxp2ga2");
		nvram_unset("1:maxp2ga3");
		nvram_unset("1:cckbw20ul2gpo");
		nvram_unset("1:pdoffset2g40ma0");
		nvram_unset("1:pdoffset2g40ma1");
		nvram_unset("1:pdoffset2g40ma2");
		nvram_unset("1:tssiposslope2g");
		nvram_unset("1:pdoffset2g40mvalid");
		nvram_unset("1:mcs1024qam2gpo");
		nvram_unset("1:ulbpproffs2g");
		nvram_unset("1:swctrlmap4_RX2g_fem3to0");
		nvram_unset("1:noiselvl2ga0");
		nvram_unset("1:noiselvl2ga1");
		nvram_unset("1:noiselvl2ga2");
		nvram_unset("1:noiselvl2ga3");
		nvram_unset("1:swctrlmap4_RXByp2g_fem3to0");
		nvram_unset("1:rpcal2g");
		nvram_unset("1:swctrlmap4_misc2g_fem3to0");
		nvram_unset("1:pa2gccka0");
		nvram_unset("1:pa2g40a0");
		nvram_unset("1:pa2g40a1");
		nvram_unset("1:pa2g40a2");
		nvram_unset("1:pa2g40a3");
		nvram_unset("1:eu_edthresh2g");
		nvram_unset("1:rxgainerr2ga0");
		nvram_unset("1:rxgainerr2ga1");
		nvram_unset("1:rxgainerr2ga2");
		nvram_unset("1:rxgainerr2ga3");
		nvram_commit();
	}
	if ( strcmp(nvram_safe_get("0:macaddr"), nvram_get("k3macaddr0")) || strcmp(nvram_safe_get("1:macaddr"), nvram_get("k3macaddr1")) || strcmp(nvram_safe_get("wl0_hwaddr"), nvram_get("k3macaddr0")) || strcmp(nvram_safe_get("wl1_hwaddr"), nvram_get("k3macaddr1"))) {
		nvram_set("0:macaddr", nvram_get("k3macaddr0"));
		nvram_set("1:macaddr", nvram_get("k3macaddr1"));
	//if (strcmp(nvram_safe_get("2:macaddr"), nvram_safe_get("k3macaddr1"))!=0)//3100 use 0 and 1
		//nvram_set("2:macaddr", nvram_safe_get("k3macaddr1"));
		nvram_set("wl0_hwaddr", nvram_get("k3macaddr0"));
		nvram_set("wl1_hwaddr", nvram_get("k3macaddr1"));
		nvram_set("devpath0", "pcie/1/1/");
		nvram_set("devpath1", "pcie/2/1/");
		nvram_set("wl_mumimo", "0");
		nvram_set("0:mcs10poexp", "0");
		nvram_set("0:mcs1024qam2gpo", "0x000");
		nvram_set("0:swctrlmap4_misc2g_fem3to0", "0x2222");
		nvram_set("0:ofdmlrbw202gpo", "0");
		nvram_set("0:rxgains2gtrisoa0", "7");
		nvram_set("0:rxgains2gtrisoa1", "7");
		nvram_set("0:rxgains2gtrisoa2", "7");
		nvram_set("0:pa2ga0", "0x1D05,0xD4C7,0x1E54,0x2407");
		nvram_set("0:pa2ga1", "0x1CE3,0xD4E9,0x1E27,0x2409");
		nvram_set("0:pa2ga2", "0x1C71,0xD5A8,0x1D21,0x23DC");
		nvram_set("0:pa2ga3", "0x1D10,0xD52A,0x1F11,0x2433");
		nvram_set("0:pa2g40a0", "0x1D72,0xDC6E,0x2BD6,0x255B");
		nvram_set("0:pa2g40a1", "0x1D34,0xDDE4,0x2EFF,0x25D6");
		nvram_set("0:pa2g40a2", "0x1D63,0xDBC2,0x2ACE,0x2533");
		nvram_set("0:pa2g40a3", "0x1D6B,0xDE8E,0x2FCB,0x25D7");
		nvram_set("0:pdoffset20in40m2gcore3", "0x001E");
		nvram_set("0:swctrlmap4_RX2g_fem7to4", "0");
		nvram_set("0:venid", "0x14E4");
		nvram_set("0:aa2g", "15");
		nvram_set("0:ledbh9", "0x7");
		nvram_set("0:swctrlmap4_cfg", "0x5");
		nvram_set("0:mcsbw402gpo", "0xCCA86400");
		nvram_set("0:mcsbw202gpo", "0xCCA86400");
		nvram_set("0:swctrlmap4_TX2g_fem3to0", "0xaaaa");
		nvram_set("0:epagain2g", "0");
		nvram_set("0:pdoffset2g40ma0", "0");
		nvram_set("0:pdoffset2g40ma1", "0");
		nvram_set("0:pdoffset2g40ma2", "0");
		nvram_set("0:rpcal2gcore3", "0x00d4");
		nvram_set("0:txidxcap2g", "0");
		nvram_set("0:tempcorrx", "0x3f");
		nvram_set("0:swctrlmap4_RXByp2g_fem7to4", "0");
		nvram_set("0:pdoffset80ma0", "43452");
		nvram_set("0:pdoffset80ma1", "2144");
		nvram_set("0:rawtempsense", "0x1ff");
		nvram_set("0:cckbw20ul2gpo", "0");
		nvram_set("0:pdoffset80ma2", "99");
		nvram_set("0:tempthresh", "120");
		nvram_set("0:pa5g40a0", "0x1D72,0xDC6E,0x2BD6,0x255B,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0");
		nvram_set("0:pa5g40a1", "0x1D34,0xDDE4,0x2EFF,0x25D6,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0");
		nvram_set("0:pa5g40a2", "0x1D63,0xDBC2,0x2ACE,0x2533,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0");
		nvram_set("0:pa5g40a3", "0x1D6B,0xDE8E,0x2FCB,0x25D7,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0");
		nvram_set("0:pa5ga0", "0x1D05,0xD4C7,0x1E54,0x2407,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0");
		nvram_set("0:pa5ga1", "0x1CE3,0xD4E9,0x1E27,0x2409,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0");
		nvram_set("0:pa5ga2", "0x1D10,0xD52A,0x1F11,0x2433,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0");
		nvram_set("0:pa5ga3", "0x1D10,0xD52A,0x1F11,0x2433,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0");
		nvram_set("0:srom13sig", "0x4D55");
		nvram_set("0:pdoffsetcckma0", "15");
		nvram_set("0:pdoffsetcckma1", "15");
		nvram_set("0:pdoffsetcckma2", "15");
		nvram_set("0:sar2g", "18");
		nvram_set("0:sb20in40lrpo", "0");
		nvram_set("0:gainctrlsph", "0");
		nvram_set("0:swctrlmap4_RX2g_fem3to0", "0x4444");
		nvram_set("0:swctrlmap4_RXByp2g_fem3to0", "0x6666");
		nvram_set("0:swctrlmap4_misc2g_fem7to4", "0");
		nvram_set("0:swctrlmap4_TX2g_fem7to4", "0");
		nvram_set("0:mcs9poexp", "0");
		nvram_set("0:regrev", "0");//3100 992
		nvram_set("0:rxgainerr5ga0", "54,63,63,59");//3100 63,63,63,63
		nvram_set("0:rxgainerr5ga1", "2,31,31,0");//3100 31,31,31,31
		nvram_set("0:rxgainerr5ga2", "1,31,31,31");//3100 31,31,31,31
		nvram_set("0:rxgainerr5ga3", "5,31,31,0");//3100 31,31,31,31
		nvram_set("0:measpower", "0x7f");
		nvram_set("0:pdoffset2g40mvalid", "0");
		nvram_set("0:pdoffset40ma0", "43452");
		nvram_set("0:pdoffset40ma1", "43452");
		nvram_set("0:pdoffset40ma2", "43452");
		nvram_set("0:rxgains2gelnagaina0", "3");//3100 4
		nvram_set("0:rxgains2gelnagaina1", "3");//3100 4
		nvram_set("0:rxgains2gelnagaina2", "3");//3100 4
		nvram_set("0:rxgains2gelnagaina3", "3");//3100 4
		nvram_set("0:pdgain2g", "2");
		nvram_set("0:sromrev", "13");
		nvram_set("0:cckbw202gpo", "0");
		nvram_set("0:mcs11poexp", "0x11111111");
		nvram_set("0:pa2gccka0", "0xffff,0xffff,0xffff");
		nvram_set("0:rxgains2gtrelnabypa0", "1");
		nvram_set("0:rxgains2gtrelnabypa1", "1");
		nvram_set("0:rxgains2gtrelnabypa2", "1");
		nvram_set("0:rxgains2gtrelnabypa3", "1");
		nvram_set("0:rxgains2gtrisoa3", "7");
		nvram_set("0:ccode", "ALL");
		nvram_set("0:rpcal2g", "0");//3100 0x2717
		nvram_set("0:dot11agduplrpo", "0");
		nvram_set("0:fdmlrbw202gpo", "0");
		nvram_set("0:tssifloor2g", "0x339");
		nvram_set("0:tempsense_slope", "0x339");
		nvram_set("0:paparambwver", "0");
		nvram_set("0:devid", "0x43c4");
		nvram_set("0:boardrev", "0x1104");
		nvram_set("0:dot11agofdmhrbw202gpo", "0x8420");//3100 0x1000
		nvram_set("0:sb20in40hrlrpox", "0");
		nvram_set("0:eu_edthresh2g", "255");
		nvram_set("0:maxp2ga0", "0x72");
		nvram_set("0:maxp2ga1", "0x72");
		nvram_set("0:maxp2ga2", "0x72");
		nvram_set("0:maxp2ga3", "0x72");
		nvram_set("0:temps_hysteresis", "5");
		nvram_set("0:pdoffset2gcck", "0x0000");
		nvram_set("0:devpath0", "sb/1/");
		nvram_set("0:rxgainerr2ga0", "63");//3100 54
		nvram_set("0:rxgainerr2ga1", "31");//3100 1
		nvram_set("0:rxgainerr2ga2", "31");//3100 5
		nvram_set("0:rxgainerr2ga3", "31");//3100 10
		nvram_set("0:boardflags", "0x10001000");
		nvram_set("0:sb20in40hrpo", "0");//3100 0x6640
		nvram_set("0:tempoffset", "255");
		nvram_set("0:antswitch", "0");
		nvram_set("0:phycal_tempdelta", "40");
		nvram_set("0:boardflags2", "0x4");
		nvram_set("0:boardflags3", "0x0");
		nvram_set("0:boardflags4", "0xe");//3100 0x8e
		nvram_set("0:temps_period", "10");
		nvram_set("0:tssiposslope2g", "1");
		nvram_set("0:agbg0", "133");
		nvram_set("0:agbg1", "133");
		nvram_set("0:agbg2", "133");
		nvram_set("0:agbg3", "133");
		nvram_set("0:papdcap2g", "0");
		nvram_set("0:pdoffset20in40m2g", "0x7BDE");
		nvram_set("0:tworangetssi2g", "0");
		nvram_set("0:tempsense_option", "0x3");
		nvram_set("0:dot11agduphrpo", "0");
		nvram_set("0:femctrl", "2");
		nvram_set("0:ulbpproffs2g", "65535");
		nvram_set("0:xtalfreq", "40000");
		nvram_set("0:mcs8poexp", "0");
		nvram_set("0:noiselvl2ga0", "31");
		nvram_set("0:noiselvl2ga1", "31");
		nvram_set("0:noiselvl2ga2", "31");
		nvram_set("0:noiselvl2ga3", "31");
		nvram_set("0:measpower1", "0x7f");
		nvram_set("0:measpower2", "0x7e");
		nvram_set("0:pcieingress_war", "15");
		nvram_set("0:txchain", "0xf");
		nvram_set("0:ulbpdoffs2ga0", "65535");
		nvram_set("0:ulbpdoffs2ga1", "65535");
		nvram_set("0:ulbpdoffs2ga2", "65535");
		nvram_set("0:ulbpdoffs2ga3", "65535");
		nvram_set("1:pa5g40a0", "0x1e40,0xdd5e,0x46a5,0x2699,0x1e89,0xdca4,0x4b89,0x275b,0x1E2D,0xDD7C,0x48B6,0x2673,0x1E70,0xD82F,0x3C1A,0x2584,0x1e67,0xd73d,0x38d3,0x255a");
		nvram_set("1:pa5g40a1", "0x1e67,0xda86,0x4b71,0x276d,0x1e4b,0xd847,0x3d72,0x2615,0x1DFF,0xDC74,0x43FF,0x25DE,0x1DEB,0xDE7C,0x4797,0x261E,0x1e65,0xd326,0x35b9,0x257b ");
		nvram_set("1:pa5g40a2", "0x1e4b,0xda9b,0x3f76,0x25db,0x1e81,0xd6a5,0x34ef,0x24f9,0x1D78,0xDAE3,0x48F0,0x274A,0x1DBD,0xD4EB,0x4109,0x2708,0x1edc,0xd4f9,0x4027,0x26bd");
		nvram_set("1:pa5g40a3", "0x1ea3,0xd766,0x3a4f,0x25f6,0x1e75,0xdac3,0x3e88,0x2684,0x1E35,0xDE82,0x4888,0x26AD,0x1E10,0xE04E,0x4982,0x269B,0x1e9e,0xda04,0x43be,0x26fb");
		nvram_set("1:pa5g80a3", "0x1ea8,0xea7e,0x5cdc,0x2822,0x1f52,0xdfa1,0x430d,0x2666,0x1F70,0xDB8A,0x3E87,0x2598,0x1F1F,0xE0DF,0x4913,0x2648,0x1f9c,0xd896,0x3d91,0x260e");
		nvram_set("1:pa5ga0", "0x1d13,0xdce8,0x4bf9,0x2791,0x1d32,0xd66c,0x3722,0x259e,0x1DF3,0xCD12,0x29F2,0x250B,0x1DDC,0xD034,0x3117,0x25E9,0x1d64,0xd594,0x3bb8,0x2625");
		nvram_set("1:pa5ga1", "0x1cfb,0xdb5c,0x4a00,0x2766,0x1d0a,0xd371,0x309e,0x24e1,0x1DD0,0xCD36,0x29D0,0x24B6,0x1DD1,0xCD4F,0x2A67,0x2513,0x1d62,0xd3b9,0x3b94,0x2672");
		nvram_set("1:pa5ga2", "0x1d25,0xdd47,0x55d5,0x28d5,0x1d15,0xd804,0x3c8c,0x2625,0x1D29,0xC81B,0x2008,0x239B,0x1D4D,0xCCA5,0x41FC,0x2AAE,0x1e00,0xc759,0x1efa,0x232f");
		nvram_set("1:pa5ga3", "0x1d91,0xd187,0x2e92,0x2546,0x1cbc,0xe328,0x56b7,0x28f2,0x1DF9,0xD0D6,0x310C,0x2617,0x1E02,0xCE15,0x2954,0x2555,0x1dcb,0xcdf4,0x2965,0x24f2");
		nvram_set("1:pa5g80a0", "0x1fef,0xd66f,0x3a19,0x257b,0x2078,0xd598,0x3bc7,0x2598,0x1F6E,0xD912,0x3B2A,0x2563,0x1FA2,0xD71C,0x38D3,0x2524,0x1fd2,0xd7e4,0x42ab,0x2637");
		nvram_set("1:pa5g80a1", "0x1ed5,0xe3ac,0x56d4,0x27c7,0x1e7e,0xeaa7,0x62ff,0x2842,0x1ED4,0xDCF0,0x44D1,0x25F4,0x1ECA,0xDED1,0x4896,0x266E,0x1f1c,0xd90b,0x41f2,0x2620");
		nvram_set("1:pa5g80a2", "0x1ecb,0xe726,0x5734,0x2793,0x1fe3,0xd902,0x3d54,0x25a6,0x1DE2,0xE5E7,0x5F8C,0x28A1,0x1E82,0xDD7E,0x5587,0x286B,0x1f57,0xd90b,0x3f66,0x25f2");
		nvram_set("1:pa5g80a3", "0x1ea8,0xea7e,0x5cdc,0x2822,0x1f52,0xdfa1,0x430d,0x2666,0x1F70,0xDB8A,0x3E87,0x2598,0x1F1F,0xE0DF,0x4913,0x2648,0x1f9c,0xd896,0x3d91,0x260e");
		nvram_set("1:ulbpdoffs5gb2a1", "65535");
		nvram_set("1:ulbpdoffs5gb2a2", "65535");
		nvram_set("1:ulbpdoffs5gb2a3", "65535");
		nvram_set("1:ulbpdoffs5gb2a0", "65535");
		nvram_set("1:pdoffset20in80m5gb0", "0x7BDD");
		nvram_set("1:pdoffset20in80m5gb1", "0x7FFF");
		nvram_set("1:pdoffset20in80m5gb2", "0x7BDE");
		nvram_set("1:pdoffset20in80m5gb3", "0x7BDE");
		nvram_set("1:pdoffset20in80m5gb4", "0x7BDE");
		nvram_set("1:mcsbw205gx1po", "0xCBA87642");
		nvram_set("1:pcieingress_war", "15");
		nvram_set("1:txchain", "0xf");
		nvram_set("1:rxchain", "0xf");
		nvram_set("1:sb20in80and160lr5glpo", "0");
		nvram_set("1:mcsbw805gmpo", "0xCBA87642");
		nvram_set("1:mcsbw205ghpo", "0xCBA87642");
		nvram_set("1:devpath2", "sb/1/");
		nvram_set("1:dot11agduphrlrpox", "0");
		nvram_set("1:rxgains5ghtrelnabypa3", "1");
		nvram_set("1:maxp5gb3a0", "0x72");//3100 102
		nvram_set("1:maxp5gb3a1", "0x72");
		nvram_set("1:maxp5gb3a2", "0x72");
		nvram_set("1:maxp5gb3a3", "0x72");
		nvram_set("1:maxp5gb2a0", "0x72");
		nvram_set("1:maxp5gb2a1", "0x72");
		nvram_set("1:maxp5gb2a2", "0x72");
		nvram_set("1:maxp5gb2a3", "0x72");
		nvram_set("1:maxp5gb1a0", "0x72");
		nvram_set("1:maxp5gb1a1", "0x72");
		nvram_set("1:maxp5gb1a2", "0x72");
		nvram_set("1:maxp5gb1a3", "0x72");
		nvram_set("1:maxp5gb4a0", "0x72");
		nvram_set("1:maxp5gb4a1", "0x72");
		nvram_set("1:maxp5gb4a2", "0x72");
		nvram_set("1:maxp5gb4a3", "0x72");
		nvram_set("1:maxp5gb0a0", "0x72");
		nvram_set("1:maxp5gb0a1", "0x72");
		nvram_set("1:maxp5gb0a2", "0x72");
		nvram_set("1:maxp5gb0a3", "0x72");
		nvram_set("1:pdoffsetcckma0", "15");
		nvram_set("1:pdoffsetcckma1", "15");
		nvram_set("1:pdoffsetcckma2", "15");
		nvram_set("1:rpcal5gb0core3", "0x009a");
		nvram_set("1:sb20in80and160lr5ghpo", "0");
		nvram_set("1:tssiposslope5g", "1");
		nvram_set("1:disband5grp", "0");
		nvram_set("1:antswitch", "0");
		nvram_set("1:boardflags", "0x10001000");
		nvram_set("1:mcsbw805glpo", "0xCBA87642");//3100 0xa9875310
		nvram_set("1:mcsbw805ghpo", "0xCBA87642");//3100 0xa9875310
		nvram_set("1:mcsbw405gx1po", "0xCBA87642");//3100 0xa9875310
		nvram_set("1:mcsbw405glpo", "0xCBA87642");//3100 0xa9875310
		nvram_set("1:mcsbw405ghpo", "0xCBA87642");//3100 0xa9875310
		nvram_set("1:mcsbw205gmpo", "0xCBA87642");//3100 0xa9875310
		nvram_set("1:mcsbw205gx2po", "0xCBA87642");//3100 0xa9875310
		nvram_set("1:mcsbw805gx2po", "0xCBA87642");//3100 0xa9875310
		nvram_set("1:mcsbw205glpo", "0xCBA87642");//3100 0xa9875310
		nvram_set("1:mcsbw805gx1po", "0xCBA87642");//3100 0xa9875310
		nvram_set("1:mcsbw405gx2po", "0xCBA87642");//3100 0xa9875310
		nvram_set("1:mcsbw405gmpo", "0xCBA87642");//3100 0xa9875310
		nvram_set("1:tempsense_slope", "0xff");
		nvram_set("1:rxgains5ghelnagaina0", "3");
		nvram_set("1:rxgains5ghelnagaina1", "3");
		nvram_set("1:rxgains5ghelnagaina2", "3");
		nvram_set("1:rxgains5ghelnagaina3", "3");
		nvram_set("1:tempoffset", "255");
		nvram_set("1:sb40and80lr5gmpo", "0");
		nvram_set("1:sb20in40hrlrpox", "0");
		nvram_set("1:pdoffset40in80m5gcore3", "0x0422");
		nvram_set("1:pdoffset40in80m5gcore3_1", "0x0041");
		nvram_set("1:sb20in80and160hr5glpo", "0");
		nvram_set("1:femctrl", "2");
		nvram_set("1:mcs1024qam5gmpo", "0x00000000");//3100 0xcbcbcbcb
		nvram_set("1:mcs1024qam5gx2po", "0x00000000");//3100 0xcbcbcbcb
		nvram_set("1:mcs1024qam5glpo", "0x00000000");//3100 0xcbcbcbcb
		nvram_set("1:mcs1024qam5ghpo", "0x00000000");//3100 0xcbcbcbcb
		nvram_set("1:mcs1024qam5gx1po", "0x00000000");//3100 0xcbcbcbcb
		nvram_set("1:rawtempsense", "0x1ff");
		nvram_set("1:pdoffset20in40m5gcore3_1", "0x03BD");
		nvram_set("1:pdoffset20in40m5gb0", "0x7BBD");
		nvram_set("1:pdoffset20in40m5gb1", "0x7BBD");
		nvram_set("1:pdoffset20in40m5gb2", "0x77BD");
		nvram_set("1:pdoffset20in40m5gb3", "0x77BD");
		nvram_set("1:pdoffset20in40m5gb4", "0x77BD");
		nvram_set("1:sb40and80lr5gx2po", "0");
		nvram_set("1:sb20in80and160hr5ghpo", "0");
		nvram_set("1:sb20in40lrpo", "0");
		nvram_set("1:sb40and80hr5gmpo", "0");
		nvram_set("1:mcslr5glpo", "0");
		nvram_set("1:mcslr5ghpo", "0");
		nvram_set("1:rxgains5gmtrelnabypa0", "1");
		nvram_set("1:rxgains5gmtrelnabypa1", "1");
		nvram_set("1:rxgains5gmtrelnabypa2", "1");
		nvram_set("1:rxgains5gmtrelnabypa3", "1");
		nvram_set("1:mcsbw1605glpo", "0xFFFFFFFF");//3100 0xa9875310
		nvram_set("1:mcsbw1605ghpo", "0xFFFFFFFF");//3100 0xa9875310
		nvram_set("1:mcsbw1605gx2po", "0xFFFFFFFF ");//3100 0xa9875310
		nvram_set("1:mcsbw1605gx1po", "0xFFFFFFFF ");//3100 0xa9875310
		nvram_set("1:mcsbw1605gmpo", "0xFFFFFFFF ");//3100 0xa9875310
		nvram_set("1:mcsbw1605gmpo", "0xFFFFFFFF ");//3100 0xa9875310
		nvram_set("1:dot11agduplrpo", "0");
		nvram_set("1:ccode", "ALL");
		nvram_set("1:rxgains5ghtrelnabypa0", "1");
		nvram_set("1:rxgains5ghtrelnabypa1", "1");
		nvram_set("1:rxgains5ghtrelnabypa2", "1");
		nvram_set("1:rpcal5gb0", "0");//3100 0x2ac1 
		nvram_set("1:rpcal5gb1", "0");
		nvram_set("1:rpcal5gb2", "0");
		nvram_set("1:rpcal5gb3", "0");//3100 0x50de
		nvram_set("1:rpcal5gb4", "0");
		nvram_set("1:swctrlmap4_TX5g_fem7to4", "0");
		nvram_set("1:swctrlmap4_RX5g_fem7to4", "0");
		nvram_set("1:swctrlmap4_RXByp5g_fem7to4", "0");
		nvram_set("1:swctrlmap4_misc5g_fem7to4", "0");
		nvram_set("1:swctrlmap4_TX5g_fem3to0", "0x6666");//3100 26214
		nvram_set("1:swctrlmap4_RX5g_fem3to0", "0x1111");//3100 4369
		nvram_set("1:swctrlmap4_RXByp5g_fem3to0", "0x3333");//3100 13107
		nvram_set("1:swctrlmap4_misc5g_fem3to0", "0");
		nvram_set("1:ulbpdoffs5gb1a0", "65535");
		nvram_set("1:ulbpdoffs5gb1a1", "65535");
		nvram_set("1:ulbpdoffs5gb1a2", "65535");
		nvram_set("1:ulbpdoffs5gb1a3", "65535");
		nvram_set("1:ledbh9", "0x7");
		nvram_set("1:mcs8poexp", "0x7");
		nvram_set("1:devid", "0x43c5");
		nvram_set("1:eu_edthresh5g", "255");
		nvram_set("1:sb20in80and160lr5gx2po", "0");
		nvram_set("1:sb40and80lr5glpo", "0");
		nvram_set("1:measpower1", "0x7f");
		nvram_set("1:measpower2", "0x7e");
		nvram_set("1:measpower", "0x7f");
		nvram_set("1:sb40and80lr5ghpo", "0");
		nvram_set("1:mcs10poexp", "0x3E3E3E3E");
		nvram_set("1:paparambwver", "0");
		nvram_set("1:sar5g", "15");
		nvram_set("1:gainctrlsph", "0");
		nvram_set("1:rpcal5gb3core3", "0x00d0");
		nvram_set("1:rpcal5gb1core3", "0");
		nvram_set("1:aga0", "71");
		nvram_set("1:aga1", "71");
		nvram_set("1:aga2", "71");
		nvram_set("1:aga3", "71");
		nvram_set("1:subband5gver", "0x5");
		nvram_set("1:ulbpdoffs5gb4a0", "65535");
		nvram_set("1:ulbpdoffs5gb4a1", "65535");
		nvram_set("1:ulbpdoffs5gb4a2", "65535");
		nvram_set("1:ulbpdoffs5gb4a3", "65535");
		nvram_set("1:sb40and80hr5glpo", "0");
		nvram_set("1:sb40and80hr5gx2po", "0");
		nvram_set("1:sb40and80hr5ghpo", "0");
		nvram_set("1:sb20in40hrpo", "0");
		nvram_set("1:noiselvl5ga0", "31,31,31,31");
		nvram_set("1:noiselvl5ga1", "31,31,31,31");
		nvram_set("1:noiselvl5ga2", "31,31,31,31");
		nvram_set("1:noiselvl5ga3", "31,31,31,31");
		nvram_set("1:ulbpdoffs5gb0a0", "65535");
		nvram_set("1:ulbpdoffs5gb0a1", "65535");
		nvram_set("1:ulbpdoffs5gb0a2", "65535");
		nvram_set("1:ulbpdoffs5gb0a3", "65535");
		nvram_set("1:pdoffsetcck", "0");//3100 65535 
		nvram_set("1:pdoffset20in40m5gcore3", "0x77BD");
		nvram_set("1:pdoffset20in80m5gcore3", "0x7BFE");
		nvram_set("1:boardnum", "53259");
		nvram_set("1:dot11agduphrpo", "0");
		nvram_set("1:papdcap5g", "0");
		nvram_set("1:regrev", "0");//3100 992
		nvram_set("1:rxgains5gtrelnabypa0", "1");
		nvram_set("1:rxgains5gtrelnabypa1", "1");
		nvram_set("1:rxgains5gtrelnabypa2", "1");
		nvram_set("1:rxgains5gtrelnabypa3", "1");
		nvram_set("1:tempcorrx", "0x3f");
		nvram_set("1:mcslr5gx2po", "0");
		nvram_set("1:pdoffset80ma0", "43452");
		nvram_set("1:sb20in80and160hr5gx2po", "0");
		nvram_set("1:pdoffset80ma1", "2144");
		nvram_set("1:pdoffset80ma2", "99");
		nvram_set("1:devpath1", "sb/1/");
		nvram_set("1:temps_hysteresis", "5");
		nvram_set("1:srom13sig", "0x4D55");
		nvram_set("1:rxgains5gmtrisoa0", "6");//3100 7
		nvram_set("1:rxgains5gmtrisoa1", "6");//3100 7
		nvram_set("1:rxgains5gmtrisoa2", "6");//3100 7
		nvram_set("1:rxgains5gmtrisoa3", "6");//3100 7
		nvram_set("1:tempthresh", "120");
		nvram_set("1:rxgains5gelnagaina0", "3");
		nvram_set("1:rxgains5gelnagaina1", "3");
		nvram_set("1:rxgains5gelnagaina2", "3");
		nvram_set("1:rxgains5gelnagaina3", "3");
		nvram_set("1:phycal_tempdelta", "40");
		nvram_set("1:pdoffset20in80m5gcore3_1", "0x03DE");
		nvram_set("1:sromrev", "13");
		nvram_set("1:sb20in80and160lr5gmpo", "0");
		nvram_set("1:ulbpdoffs5gb3a0", "65535");
		nvram_set("1:ulbpdoffs5gb3a1", "65535");
		nvram_set("1:ulbpdoffs5gb3a2", "65535");
		nvram_set("1:ulbpdoffs5gb3a3", "65535");
		nvram_set("1:pdoffset40in80m5gb0", "0x0000");
		nvram_set("1:pdoffset40in80m5gb1", "0x0420");
		nvram_set("1:pdoffset40in80m5gb2", "0x0440");
		nvram_set("1:pdoffset40in80m5gb3", "0x0820");
		nvram_set("1:sb40and80hr5gx1po", "0");
		nvram_set("1:rxgainerr5ga0", "63,63,63,63");//3100 54,63,63,59
		nvram_set("1:rxgainerr5ga1", "31,31,31,31");//3100 2,31,31,0
		nvram_set("1:rxgainerr5ga2", "31,31,31,31");//3100 1,31,31,31
		nvram_set("1:rxgainerr5ga3", "31,31,31,31");//3100 5,31,31,0
		nvram_set("1:mcs9poexp", "0");
		nvram_set("1:pdoffset40in80m5gb4", "0x0841");
		nvram_set("1:pdoffset40ma0", "43452");
		nvram_set("1:pdoffset40ma1", "43452");
		nvram_set("1:pdoffset40ma2", "43452");
		nvram_set("1:temps_period", "10");
		nvram_set("1:swctrlmap4_cfg", "1");
		nvram_set("1:venid", "0x14E4");
		nvram_set("1:pdgain5g", "2");
		nvram_set("1:boardflags2", "0x4");
		nvram_set("1:boardflags3", "0x0");
		nvram_set("1:boardflags4", "0xe");//3100 0x8e
		nvram_set("1:rxgains5ghtrisoa0", "6");
		nvram_set("1:rxgains5ghtrisoa1", "6");
		nvram_set("1:rxgains5ghtrisoa2", "6");
		nvram_set("1:rxgains5ghtrisoa3", "6");
		nvram_set("1:rxgains5gtrisoa0", "7");//3100 6
		nvram_set("1:rxgains5gtrisoa1", "7");//3100 6
		nvram_set("1:rxgains5gtrisoa2", "7");//3100 6
		nvram_set("1:rxgains5gtrisoa3", "7");//3100 6
		nvram_set("1:mcslr5gx1po", "0");
		nvram_set("1:mcs11poexp", "0x3E3E3E3E ");//3100 0
		nvram_set("1:sb20in80and160hr5gmpo", "0");
		nvram_set("1:epagain5g", "0");
		nvram_set("1:tworangetssi5g", "0");
		nvram_set("1:tempsense_option", "0x3");
		nvram_set("1:sb20in80and160hr5gx1po", "0");
		nvram_set("1:rxgains5gmelnagaina0", "3");
		nvram_set("1:rxgains5gmelnagaina1", "3");
		nvram_set("1:rxgains5gmelnagaina2", "3");
		nvram_set("1:rxgains5gmelnagaina3", "3");
		nvram_set("1:xtalfreq", "40000");
		nvram_set("1:aa5g", "15");
		nvram_set("1:txidxcap5g", "0");
		nvram_set("1:mcslr5gmpo", "0");
		nvram_set("1:rpcal5gb2core3", "0");
		nvram_set("1:tssifloor5g", "0x0,0x3ff,0x335,0x318");
		nvram_commit();
	}
#if defined(RTCONFIG_SOFTCENTER)
	nvram_set("sc_wan_sig", "0");
	nvram_set("sc_nat_sig", "0");
	nvram_set("sc_mount_sig", "0");
#endif
}

int k3screena(){
	_dprintf("....k3screen start a....\n");
	char fwver[32];
	FILE *fpu;
	if (!nvram_get("hd_version"))
		nvram_set("hd_version", "A1/A2");

	if (!nvram_get("product"))
		nvram_set("product", "K3");
	if(nvram_get_int("sw_mode") == 1){
		sprintf(fwver, "%s_%s", nvram_get("buildno"), nvram_get("extendno"));
		nvram_set("fw_version", fwver);
		nvram_set("sw_version", fwver);
		nvram_set("wan_ifname", "vlan2");
	} else {
		sprintf(fwver, "AP:%s", nvram_safe_get("lan_ipaddr"));
		nvram_set("fw_version", fwver);
		nvram_set("sw_version", fwver);
		nvram_set("wan_ifname", "vlan1");
	}
	if (!nvram_get("wan_pppoe_ifname"))
		nvram_set("wan_pppoe_ifname", "ppp0");
	if (nvram_get_int("bsd_role") != 0)
		nvram_set_int("bsd_role", 0);
	if (!nvram_get("pingcheck"))
		nvram_set("pingcheck", "1");
	if (nvram_get_int("get_wan_port_status") != 1)
		nvram_set_int("get_wan_port_status", 1);
	if (!nvram_get("screen_time"))
		nvram_set("screen_time", "20");
	if (!nvram_get("screen_2G5G_pwd_en"))
		nvram_set("screen_2G5G_pwd_en", "1");
	if (!nvram_get("city_ch"))
		nvram_set("city_ch", "北京");
	if (!nvram_get("county_ch"))
		nvram_set("county_ch", "北京");
	if (!nvram_get("city_id"))
		nvram_set("city_id", "WX4FBXXFKE4F");
	if (!nvram_get("vis_ssid_enable"))
		nvram_set("vis_ssid_enable", "1");
	if (!nvram_get("screen_guest_pwd_en"))
		nvram_set("screen_guest_pwd_en", "1");
	if (!nvram_get("vis_ssid"))
		nvram_set("vis_ssid", "ASUS_GUEST");
	if (!nvram_get("vis_ssid_pwd"))
		nvram_set("vis_ssid_pwd", "1234567890");
	nvram_commit();
	doSystem("killall -q -9 phi_speed wl_cr uhmi k3screenctrl update_weather 2>/dev/null");
	if ((fpu = fopen("/tmp/uhmi.sh", "w"))){
		fprintf(fpu, "#!/bin/sh\n");
		fprintf(fpu, "mkdir -p /jffs/softcenter/lib\n");
		fprintf(fpu, "ln -sf /usr/share/libwlcr.so /jffs/softcenter/lib/libwlcr.so\n");
		fprintf(fpu, "devmem 0x1800c1c1 32 0x00001f0f\n");
		fprintf(fpu, "[ -n \"$(echo $LD_LIBRARY_PATH |grep \"jffs\")\" ] || export LD_LIBRARY_PATH=/jffs/softcenter/lib:/lib:/usr/lib\n");
		fprintf(fpu, "phi_speed &\n");
		fprintf(fpu, "wl_cr &\n");
		fprintf(fpu, "uhmi &\n");
		fclose(fpu);
	}
	doSystem("chmod +x /tmp/uhmi.sh");
	doSystem("/tmp/uhmi.sh &");
	doSystem("echo '#!/bin/sh' > /tmp/update_weather");
	doSystem("echo 'while [ 1 ]' >> /tmp/update_weather");
	doSystem("echo 'do' >> /tmp/update_weather");
	doSystem("echo 'weather update_weather' >> /tmp/update_weather");
	doSystem("echo 'sleep 3600' >> /tmp/update_weather");
	doSystem("echo 'done' >> /tmp/update_weather");
	doSystem("chmod +x /tmp/update_weather");
	doSystem("/tmp/update_weather &");
	_dprintf("....k3screen ok....\n");
	return 0;
}
int k3screenb(){
		_dprintf("....k3screen start b....\n");
	FILE *fpb, *fph, *fpp, *fpw, *fpe, *fpt;
	char *timeout;
	doSystem("mkdir -p /tmp/k3screenctrl");
	if ((fpb = fopen("/tmp/k3screenctrl/basic.sh", "w"))){
		fprintf(fpb, "#!/bin/sh\n");
		fprintf(fpb, "if [ -n `nvram get et2macaddr` ]; then\n");
		fprintf(fpb, "    MAC_ADDR=$(nvram get et2macaddr)\n");
		fprintf(fpb, "else\n");
		fprintf(fpb, "    MAC_ADDR=$(nvram get k3macaddr)\n");
		fprintf(fpb, "fi\n");
		fprintf(fpb, "BUILD_NO=`nvram get buildno`\n");
		fprintf(fpb, "EXTEND_NO=`nvram get extendno`\n");
		fprintf(fpb, "swmode=`nvram get sw_mode`\n");
		fprintf(fpb, "if [ \"$swmode\" == \"1\" ]; then\n");
		fprintf(fpb, "FW_VERSION=\"$BUILD_NO\"_\"$EXTEND_NO\"\n");
		fprintf(fpb, "else\n");
		fprintf(fpb, "FW_VERSION=AP:$(nvram get lan_ipaddr)\n");
		fprintf(fpb, "fi\n");
		fprintf(fpb, "echo K3\n");
		fprintf(fpb, "echo A1/A2\n");
		fprintf(fpb, "echo $FW_VERSION\n");
		fprintf(fpb, "echo $FW_VERSION\n");
		fprintf(fpb, "echo $MAC_ADDR\n");
		fclose(fpb);
	}
	if ((fph = fopen("/tmp/k3screenctrl/host.sh", "w"))){
		fprintf(fph, "#!/bin/sh\n");
		fprintf(fph, "data=`cat /tmp/k3screenctrl/device_online`\n");
		fprintf(fph, "echo \"${data}\"\n");
		fclose(fph);
	}
	if ((fpp = fopen("/tmp/k3screenctrl/port.sh", "w"))){
		fprintf(fpp, "#!/bin/sh\n");
		fprintf(fpp, "eval $(/usr/sbin/robocfg show 2>/dev/null | awk 'NR==2,NR==5{printf $3\" \"}' | awk '{printf(\"LAN2=%%s; LAN1=%%s; LAN3=%%s; WAN1=%%s;\",$1,$2,$3,$4)}')\n");
		fprintf(fpp, "  [ \"$LAN2\" = \"DOWN\" ] && LAN2=\"0\" || LAN2=\"1\"\n");
		fprintf(fpp, "  [ \"$LAN1\" = \"DOWN\" ] && LAN1=\"0\" || LAN1=\"1\"\n");
		fprintf(fpp, "  [ \"$LAN3\" = \"DOWN\" ] && LAN3=\"0\" || LAN3=\"1\"\n");
		fprintf(fpp, "  [ \"$WAN1\" = \"DOWN\" ] && WAN1=\"0\" || WAN1=\"1\"\n");
		fprintf(fpp, "  if [ $(nvram get usb_usb3) -eq 1 ]; then\n");
		fprintf(fpp, "   [ \"$(lsusb | wc -l)\" -gt 3 ] && USB=\"1\" || USB=\"0\"\n");
		fprintf(fpp, "  else\n");
		fprintf(fpp, "   [ \"$(lsusb | wc -l)\" -gt 2 ] && USB=\"1\" || USB=\"0\"\n");
		fprintf(fpp, "  fi\n");
		fprintf(fpp, "echo $LAN1\n");
		fprintf(fpp, "echo $LAN2\n");
		fprintf(fpp, "echo $LAN3\n");
		fprintf(fpp, "echo $WAN1\n");
		fprintf(fpp, "echo $USB\n");
		fclose(fpp);
	}
	if ((fpw = fopen("/tmp/k3screenctrl/wan.sh", "w"))){
		fprintf(fpw, "#!/bin/sh\n");
		fprintf(fpw, "WAN_STAT=`nvram get wan0_ipaddr`\n");
		fprintf(fpw, "WAN6_STAT=`nvram get ipv6_ipaddr`\n");
		fprintf(fpw, "[ $(nvram get sw_mode) -eq 1 ] && mode=0\n");
		fprintf(fpw, "[ $(nvram get sw_mode) -eq 1 ] || mode=1\n");
		fprintf(fpw, "[ \"$WAN_STAT\" != \"0.0.0.0\" ] && IPV4_ADDR=\"$WAN_STAT\"\n");
		fprintf(fpw, "[ \"$WAN6_STAT\" != \"\" ] && IPV6_ADDR=\"$WAN6_STAT\"\n");
		fprintf(fpw, "if [ -n \"$IPV4_ADDR\" -o -n \"$IPV6_ADDR\" ]; then\n");
		fprintf(fpw, "    CONNECTED=1\n");
		fprintf(fpw, "else\n");
		fprintf(fpw, "    CONNECTED=0\n");
		fprintf(fpw, "fi\n");
		fprintf(fpw, "UPLOAD_BPS=`cat /tmp/k3screenctrl/upspeed`\n");
		fprintf(fpw, "DOWNLOAD_BPS=`cat /tmp/k3screenctrl/downspeed`\n");
		fprintf(fpw, "echo $CONNECTED\n");
		fprintf(fpw, "echo $IPV4_ADDR\n");
		fprintf(fpw, "echo $UPLOAD_BPS\n");
		fprintf(fpw, "echo $DOWNLOAD_BPS\n");
		fprintf(fpw, "echo 0\n");
		fprintf(fpw, "echo $mode\n");
		fclose(fpw);
	}
	if ((fpe = fopen("/tmp/k3screenctrl/wifi.sh", "w"))){
		fprintf(fpe, "#!/bin/sh\n");
		fprintf(fpe, "ssid24=`nvram get wl0_ssid`\n");
		fprintf(fpe, "pd24=`nvram get wl0_wpa_psk`\n");
		fprintf(fpe, "en24=`nvram get wl0_bss_enabled`\n");
		fprintf(fpe, "cc24=`wl -i eth1 assoclist| wc -l`\n");
		fprintf(fpe, "ssid5=`nvram get wl1_ssid`\n");
		fprintf(fpe, "pd5=`nvram get wl1_wpa_psk`\n");
		fprintf(fpe, "en5=`nvram get wl1_bss_enabled`\n");
		fprintf(fpe, "cc5=`wl -i eth2 assoclist| wc -l`\n");
		fprintf(fpe, "pdg=\"1234567890\"\n");
		fprintf(fpe, "if [ $(nvram get wl0_auth_mode_x) == \"open\" ]; then\n");
		fprintf(fpe, "pd24=\" \"\n");
		fprintf(fpe, "fi\n");
		fprintf(fpe, "if [ $(nvram get wl1_auth_mode_x) == \"open\" ]; then\n");
		fprintf(fpe, "pd5=\" \"\n");
		fprintf(fpe, "fi\n");
		fprintf(fpe, "if [ \"$(nvram get screen_2G5G_pwd_en)\" != \"1\" ]; then\n");
		fprintf(fpe, "pd24=\"********\"\n");
		fprintf(fpe, "pd5=\"********\"\n");
		fprintf(fpe, "fi\n");
		fprintf(fpe, "if [ \"$(nvram get screen_guest_pwd_en)\" == \"0\" ]; then\n");
		fprintf(fpe, "pdg=\"********\"\n");
		fprintf(fpe, "fi\n");
		fprintf(fpe, "echo 0\n");
		fprintf(fpe, "echo $ssid24\n");
		fprintf(fpe, "echo \"$pd24\"\n");
		fprintf(fpe, "echo $en24\n");
		fprintf(fpe, "echo $cc24\n");
		fprintf(fpe, "echo $ssid5\n");
		fprintf(fpe, "echo \"$pd5\"\n");
		fprintf(fpe, "echo $en5\n");
		fprintf(fpe, "echo $cc5\n");
		fprintf(fpe, "echo ASUS_GUEST\n");
		fprintf(fpe, "echo \"$pdg\"\n");
		fprintf(fpe, "echo 0\n");
		fprintf(fpe, "echo 0\n");
		fclose(fpe);
	}
	if ((fpt = fopen("/tmp/k3screenctrl/weather.sh", "w"))){
		fprintf(fpt, "#!/bin/sh\n");
		fprintf(fpt, "get_json_value()\n");
		fprintf(fpt, "{\n");
		fprintf(fpt, "  local json=$1\n");
		fprintf(fpt, "  local key=$2\n");
		fprintf(fpt, "  if [[ -z \"$3\" ]]; then\n");
		fprintf(fpt, "    local num=1\n");
		fprintf(fpt, "  else\n");
		fprintf(fpt, "    local num=$3\n");
		fprintf(fpt, "  fi\n");
		fprintf(fpt, "  local value=$(echo \"${json}\" | awk -F\"[,:}]\" '{for(i=1;i<=NF;i++){if($i~/'${key}'\042/){print $(i+1)}}}' | tr -d '\"' | sed -n ${num}p)\n");
		fprintf(fpt, "  echo ${value}\n");
		fprintf(fpt, "}\n");
		fprintf(fpt, "week=$(date +%%w)\n");
		fprintf(fpt, "data=`cat /lib/k3screenctrl/date`\n");
		fprintf(fpt, "time=`cat /lib/k3screenctrl/time`\n");
		fprintf(fpt, "[ -f \"/lib/k3screenctrl/starttime\" ] || echo $(($(date +%%s -d $time)+7200)) > /lib/k3screenctrl/starttime\n");
		fprintf(fpt, "starttime=`cat /lib/k3screenctrl/starttime`\n");
		fprintf(fpt, "[ ! -f \"/lib/k3screenctrl/http\" -o $(date +%%s -d $time) -ge $starttime ] && json=`curl -s \"https://api.seniverse.com/v3/weather/now.json?key=5fjwjirm6bzk95rx&location=ip&language=zh-Hans&unit=c\"` && echo $json > /lib/k3screenctrl/http && echo $(($(date +%%s -d $time)+7200)) > /lib/k3screenctrl/starttime\n");
		fprintf(fpt, "http=`cat /lib/k3screenctrl/http`\n");
		fprintf(fpt, "city=`get_json_value \"$http\" name`\n");
		fprintf(fpt, "temp=`get_json_value \"$http\" temperature`\n");
		fprintf(fpt, "code=`get_json_value \"$http\" code`\n");
		fprintf(fpt, "echo $city\n");
		fprintf(fpt, "echo $temp\n");
		fprintf(fpt, "echo $data\n");
		fprintf(fpt, "echo $time\n");
		fprintf(fpt, "echo $code\n");
		fprintf(fpt, "echo $week\n");
		fprintf(fpt, "echo 0\n");
		fclose(fpt);
	}
	doSystem("killall -q -9 phi_speed wl_cr uhmi k3screenctrl update_weather k3screend 2>/dev/null");
	doSystem("chmod +x /tmp/k3screenctrl/*.sh");
	doSystem("/usr/sbin/k3screend &");
	if (nvram_get_int("k3screen_timeout")==1)
		timeout = "-m0";
	else
		timeout = "-m30";
	char *k3screenctrl_argv[] = { "k3screenctrl", timeout,NULL };
	pid_t pid;
	_eval(k3screenctrl_argv, NULL, 0, &pid);
	_dprintf("....k3screen ok....\n");
	return 0;
}
int start_k3screen(void){
	logmessage("K3", "屏幕支援程序开始启动");
	if (!nvram_get("k3screen")){
		nvram_set("k3screen", "b");
		nvram_commit();
	}
	_dprintf("....k3screen start....\n");
	if ((strcmp(nvram_get("k3screen"), "A")==0) || (strcmp(nvram_get("k3screen"), "a")==0))
		return k3screena();
	else if ((strcmp(nvram_get("k3screen"), "B")==0) || (strcmp(nvram_get("k3screen"), "b")==0))
		return k3screenb();
	else {
		nvram_set("k3screen", "b");
		nvram_commit();
		return k3screenb();
		}
	return 0;
}

void k3_insmod(){
	eval("insmod", "ip_set");
	eval("insmod", "ip_set_bitmap_ip");
	eval("insmod", "ip_set_bitmap_ipmac");
	eval("insmod", "ip_set_bitmap_port");
	eval("insmod", "ip_set_hash_ip");
	eval("insmod", "ip_set_hash_ipport");
	eval("insmod", "ip_set_hash_ipportip");
	eval("insmod", "ip_set_hash_ipportnet");
	eval("insmod", "ip_set_hash_ipmac");
	eval("insmod", "ip_set_hash_ipmark");
	eval("insmod", "ip_set_hash_net");
	eval("insmod", "ip_set_hash_netport");
	eval("insmod", "ip_set_hash_netiface");
	eval("insmod", "ip_set_hash_netnet");
	eval("insmod", "ip_set_hash_netportnet");
	eval("insmod", "ip_set_hash_mac");
	eval("insmod", "ip_set_list_set");
	eval("insmod", "nf_tproxy_core");
	eval("insmod", "xt_TPROXY");
	eval("insmod", "xt_set");
}

void k3_init_done(){
	_dprintf("############################ k3 init done #################################\n");
#ifdef RTCONFIG_SOFTCENTER
	if (!f_exists("/jffs/softcenter/scripts/ks_tar_intall.sh") && nvram_match("sc_mount","0")){
		doSystem("/usr/sbin/jffsinit.sh &");
		logmessage("软件中心", "开始安装......");
		logmessage("软件中心", "1分钟后完成安装");
		_dprintf("....softcenter ok....\n");
	} else if (f_exists("/jffs/softcenter/scripts/ks_tar_intall.sh") && nvram_match("sc_mount","0"))
		nvram_set("sc_installed","1");
	if(f_exists("/jffs/.asusrouter")){
		unlink("/jffs/.asusrouter");
		doSystem("sed -i '/softcenter-wan.sh/d' /jffs/scripts/wan-start");
		doSystem("sed -i '/softcenter-net.sh/d' /jffs/scripts/nat-start");
		doSystem("sed -i '/softcenter-mount.sh/d' /jffs/scripts/post-mount");
	}
#endif

	//移除这段代码会造成部分人变真砖，并且共享cfe也会造成变砖
	//patch cfe,don't remove this
	k3_nvram_patch();
	if(!cfe_nvram_get("uuid")){
		doSystem("nvram set uuid=`cat /proc/sys/kernel/random/uuid`");
		k3_nvram_set("uuid",nvram_get("uuid"));
		sleep(2);
	} else
		nvram_set("uuid",cfe_nvram_get("uuid"));

	if(!cfe_nvram_get("territory_code") || !strcmp(cfe_nvram_get("territory_code"), "US/01")){
		k3_nvram_set("territory_code","US/01");
		nvram_set("location_code", "US");
	}
	k3_insmod();
	logmessage("K3", "uuid:%s", nvram_get("uuid"));
	logmessage("K3", "mac:%s", cfe_nvram_get("et0macaddr"));

	start_k3screen();
	//华硕似乎实现了aimesh的webui和aimesh核心剥离，从而实现382和384共用一个webui，384则强制显示aimesh界面，禁掉它，防止误导
	//disable aimesh webui,asus splits aimesh into two parts,aimesh webui and aimesh core
	//aimesh core does not work in this firmware,so disable aimesh webui
#if defined(MERLINR_VER_MAJOR_B)
	del_rc_support("amasRouter");
	del_rc_support("amas");
#endif
#if defined(MERLINR_VER_MAJOR_R) || defined(MERLINR_VER_MAJOR_X)
#if defined(K3) || defined(K3C) || defined(R8000P) || defined(R7900P)
	if (auth_code_check(cfe_nvram_get("et0macaddr"), nvram_get("uuid")) == 1)
#elif defined(SBRAC1900P)
	if (auth_code_check(cfe_nvram_get("et2macaddr"), nvram_get("uuid")) == 1)
#endif
	{
		logmessage("K3", "*** verify done ***\n");
	} else {
		logmessage("K3", "*** verify failed, Reboot after 10 min ***\n");
	}
#endif
}

int GetPhyStatusk3(int verbose)
{
	int ports[4];
	int i, ret, lret=0, mask;
	char out_buf[30];
	ports[0]=3; ports[1]=1; ports[2]=0; ports[3]=2;

	memset(out_buf, 0, 30);
	for (i=0; i<4; i++) {
		mask = 0;
		mask |= 0x0001<<ports[i];
		if (get_phy_status(mask)==0) {/*Disconnect*/
			if (i==0)
				sprintf(out_buf, "W0=X;");
			else {
				sprintf(out_buf, "%sL%d=X;", out_buf, i);
			}
		}
		else { /*Connect, keep check speed*/
			mask = 0;
			mask |= (0x0003<<(ports[i]*2));
			ret=get_phy_speed(mask);
			ret>>=(ports[i]*2);
			if (i==0)
				sprintf(out_buf, "W0=%s;", (ret & 2)? "G":"M");
			else {
				lret = 1;
				sprintf(out_buf, "%sL%d=%s;", out_buf, i, (ret & 2)? "G":"M");
			}
		}
	}

	if (verbose)
		puts(out_buf);

	return lret;
}


#define FWUPDATE_DBG(fmt,args...) \
        if(1) { \
                char info[1024]; \
                snprintf(info, sizeof(info), "echo \"[FWUPDATE][%s:(%d)]"fmt"\" >> /tmp/webs_upgrade.log", __FUNCTION__, __LINE__, ##args); \
                system(info); \
        }

int str_split(char* buf, char** s, int s_size) {
	int curr = 0;
	char* token = strtok(buf, ".");
	while(token && curr < s_size) {
		s[curr++] = token;
		token = strtok(NULL, ".");
	}
	return curr;
}

int versioncmp(char *cur_fwver, char *fwver) {
	char buf1[20] = {0}, buf2[20] = {0};
	char* s1[20] = {0};
	char* s2[20] = {0};
	char* end;
	int i, n1, n2, s1_len, s2_len, s_max, rlt;
	strncpy(buf1, cur_fwver, strlen(cur_fwver));
	strncpy(buf2, fwver, strlen(fwver));
	//fprintf(stderr, "%s\n", buf1);
	//fprintf(stderr, "%s\n", buf2);

	s1_len = str_split(buf1, s1, 10);
	s2_len = str_split(buf2, s2, 10);

	//fprintf(stderr, "s1=%d, s2=%d\n", s1_len, s2_len);

	s_max = (s1_len > s2_len ? s1_len: s2_len);

	rlt = 0;
	for(i = 0; i < s_max; i++) {
		if(!s1[i]) {
			s1[i] = "0";
		}
		if(!s2[i]) {
			s2[i] = "0";
		}

		n1 = strtol(s1[i], &end, 10);
		if(*end) {
			//parse error, but not break hear
			rlt = 1;
		}

		n2 = strtol(s2[i], &end, 10);
		if(*end) {
			if (1 == rlt) {
				//both error
				rlt = 0;
				break;
			}
			rlt = -1;
			break;
		}

		if(1 == rlt) {
			break;
		}

		if (n1 == n2) {
			continue;
		} else if(n1 < n2) {
			rlt = 1;
			break;
		} else {
			rlt = -1;
			break;
		}
	}
	return rlt;
}

size_t getcontentlengthfunc(void *ptr, size_t size, size_t nmemb, void *stream) {
	int r;
	long len = 0;

	/* _snscanf() is Win32 specific */
	// r = _snscanf(ptr, size * nmemb, "Content-Length: %ld\n", &len);
	r = sscanf(ptr, "Content-Length: %ld\n", &len);
	if (r) /* Microsoft: we don't read the specs */
		*((long *) stream) = len;

	return size * nmemb;
}

size_t wirtefunc(void *ptr, size_t size, size_t nmemb, void *stream)
{
	return fwrite(ptr, size, nmemb, stream);
}
#if 0
size_t readfunc(void *ptr, size_t size, size_t nmemb, void *stream)
{
	FILE *f = stream;
	size_t n;

	if (ferror(f))
		return CURL_READFUNC_ABORT;

	n = fread(ptr, size, nmemb, f) * size;

	return n;
}
#endif
int curl_download_file(CURL *curlhandle, const char * remotepath, const char * localpath, long timeout, long tries)
{
	FILE *f;
	curl_off_t local_file_len = -1 ;
	long filesize =0 ;

	CURLcode r = CURLE_GOT_NOTHING;
	//int c;
	struct stat file_info;
	int use_resume = 0;
	//if(access(localpath,F_OK) ==0)

	if(stat(localpath, &file_info) == 0) 
	{
		local_file_len =  file_info.st_size;
		use_resume  = 1;
	}
	f = fopen(localpath, "ab+"); 
	if (f == NULL) {
		perror(NULL);
		return 0;
	}

	//curl_easy_setopt(curlhandle, CURLOPT_UPLOAD, 1L);

	curl_easy_setopt(curlhandle, CURLOPT_URL, remotepath);
	curl_easy_setopt(curlhandle, CURLOPT_CONNECTTIMEOUT, timeout);
	curl_easy_setopt(curlhandle, CURLOPT_HEADERFUNCTION, getcontentlengthfunc);
	curl_easy_setopt(curlhandle, CURLOPT_HEADERDATA, &filesize);
	curl_easy_setopt(curlhandle, CURLOPT_RESUME_FROM_LARGE, use_resume?local_file_len:0);
	curl_easy_setopt(curlhandle, CURLOPT_SSL_VERIFYPEER, 0);
	curl_easy_setopt(curlhandle, CURLOPT_SSL_VERIFYHOST, 0);
	curl_easy_setopt(curlhandle, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1); 
	curl_easy_setopt(curlhandle, CURLOPT_WRITEDATA, f);
	curl_easy_setopt(curlhandle, CURLOPT_WRITEFUNCTION, wirtefunc);

	//curl_easy_setopt(curlhandle, CURLOPT_READFUNCTION, readfunc);
	//curl_easy_setopt(curlhandle, CURLOPT_READDATA, f);
	curl_easy_setopt(curlhandle, CURLOPT_NOPROGRESS, 1);
	curl_easy_setopt(curlhandle, CURLOPT_VERBOSE, 1);

	r = curl_easy_perform(curlhandle);
	fclose(f);

	if (r == CURLE_OK)
		return 1;
	else {
		fprintf(stderr, "%s\n", curl_easy_strerror(r));
		return 0;
	}
}

int merlinr_firmware_check_update_main(int argc, char *argv[])
{
	//char notetxt[]="/tmp/release_note.txt";
	//char downloadphp[]="download.php";
	//char sqdownloadphp[]="SQ_download.php";
	//char wlanutdatetxt[]="/tmp/wlan_utdate.txt";
	//char wlan_update_mrflag1[]="wlan_update_mrflag1.zip";
	FILE *fpupdate;
	int download;
	char url[100];
	char log[200];
	char serverurl[]="https://update.paldier.com";
	char serverupdate[]="wlan_update_v2.zip";
	char localupdate[]="/tmp/wlan_update.txt";
	char releasenote[]="/tmp/release_note0.txt";
	char model[20], modelname[20], fsver[10], fwver[10], tag[10];
	char cur_fwver[10];
	char *tmp_fwver=nvram_get("extendno");
	char info[100];
	nvram_set("webs_state_update", "0");
	nvram_set("webs_state_flag", "0");
	nvram_set("webs_state_error", "0");
	nvram_set("webs_state_odm", "0");
	nvram_set("webs_state_url", "");
	unlink("/tmp/webs_upgrade.log");
	unlink("/tmp/wlan_update.txt");
	unlink("/tmp/release_note0.txt");
	sscanf(tmp_fwver, "%*[A-Z0-9]_%[A-Z0-9.]-%*[a-z0-9]", cur_fwver);
	CURL *curlhandle = NULL;

	curl_global_init(CURL_GLOBAL_ALL);
	curlhandle = curl_easy_init();
	snprintf(url, sizeof(url), "%s/%s", serverurl, serverupdate);
	//snprintf(log, sizeof(log), "echo \"[FWUPDATE]---- update dl_path_info for general %s/%s ----\" >> /tmp/webs_upgrade.log", serverurl, serverupdate);
	download=curl_download_file(curlhandle , url,localupdate,8,3);
	//system(log);
	FWUPDATE_DBG("---- update dl_path_info for general %s/%s ----", serverurl, serverupdate);
	_dprintf("%d\n",download);
	if(download)
	{
		fpupdate = fopen(localupdate, "r");
		if (!fpupdate)
			goto GODONE;
		//BLUECAVE#K3C#3004384#R7.0#g13e704e
		char buffer[1024];
		while(NULL!=fgets(buffer,sizeof(buffer),fpupdate)){
			sscanf(buffer,"%[A-Z0-9-]#%[A-Z0-9]#%[0-9]#%[A-Z0-9.]#%[a-z0-9]",model,modelname,fsver,fwver,tag);
			_dprintf("%s#%s#%s#%s\n",model,modelname,fsver,fwver);
			if(!strcmp(model, nvram_get("productid")) && !strcmp(modelname, nvram_safe_get("modelname"))){
				if((strstr(cur_fwver, "B") && strstr(fwver, "B"))||(strstr(cur_fwver, "R") && strstr(fwver, "R"))||(strstr(cur_fwver, "X") && strstr(fwver, "X"))){
					//_dprintf("%s#%s\n",fwver,cur_fwver);
					if(versioncmp((cur_fwver+1),(fwver+1))==1){
						nvram_set("webs_state_url", "");
#if defined(SBRAC3200P) || defined(RTACRH17) || defined(RTAC3200)
						snprintf(info,sizeof(info),"3004_382_%s_%s-%s",modelname,fwver,tag);
#else
						snprintf(info,sizeof(info),"3004_384_%s_%s-%s",modelname,fwver,tag);
#endif
						FWUPDATE_DBG("---- current version : %s ----", nvram_get("extendno"));
						FWUPDATE_DBG("---- productid : %s_%s-%s ----", modelname, fwver, tag);
						nvram_set("webs_state_info", info);
						nvram_set("webs_state_REQinfo", info);
						nvram_set("webs_state_flag", "1");
						nvram_set("webs_state_update", "1");

						memset(url,'\0',sizeof(url));
						memset(log,'\0',sizeof(log));
						char releasenote_file[100];
						snprintf(releasenote_file, sizeof(releasenote_file), "%s_%s_%s_note.zip", nvram_get("productid"), nvram_get("webs_state_info"),nvram_get("preferred_lang"));
						snprintf(url, sizeof(url), "%s/%s", serverurl, releasenote_file);
						//snprintf(log, sizeof(log), "echo \"[FWUPDATE]---- download real release note %s/%s ----\" >> /tmp/webs_upgrade.log", serverurl, releasenote_file);
						//system(log);
						FWUPDATE_DBG("---- download real release note %s/%s ----", serverurl, releasenote_file);
						download=curl_download_file(curlhandle , url,releasenote,8,3);
						if(download ==0 ){
							memset(url,'\0',sizeof(url));
							snprintf(releasenote_file, sizeof(releasenote_file), "%s_%s_US_note.zip", nvram_get("productid"), nvram_get("webs_state_info"));
							snprintf(url, sizeof(url), "%s/%s", serverurl, releasenote_file);
							//snprintf(log, sizeof(log), "echo \"[FWUPDATE]---- download real release note %s/%s ----\" >> /tmp/webs_upgrade.log", serverurl, releasenote_file);
							//system(log);
							FWUPDATE_DBG("---- download real release note %s/%s ----", serverurl, releasenote_file);
							curl_download_file(curlhandle , url,releasenote,8,3);
						}
						FWUPDATE_DBG("---- firmware check update finish ----");
						return 0;
#if 0
						if(strstr(nt_center,"nt_center")){
							if((!nvram_get("webs_last_info"))||(strcmp(nvram_get("webs_last_info"), nvram_get("webs_state_info")))){
								system("Notify_Event2NC \"$SYS_FW_NWE_VERSION_AVAILABLE_EVENT\" \"{\\\"fw_ver\\\":\\\"$update_webs_state_info\\\"}\"");
								nvram_set("webs_last_info", nvram_get("webs_state_info"));
							}
						}
#endif
					}
				}
			}
		}
	}

	curl_easy_cleanup(curlhandle);
	curl_global_cleanup();

GODONE:
#if defined(SBRAC3200P) || defined(RTACRH17) || defined(RTAC3200)
	snprintf(info,sizeof(info),"3004_382_%s",nvram_get("extendno"));
#else
	snprintf(info,sizeof(info),"3004_384_%s",nvram_get("extendno"));
#endif
	nvram_set("webs_state_url", "");
	nvram_set("webs_state_flag", "0");
	nvram_set("webs_state_error", "1");
	nvram_set("webs_state_odm", "0");
	nvram_set("webs_state_update", "1");
	nvram_set("webs_state_info", info);
	nvram_set("webs_state_REQinfo", info);
	nvram_set("webs_state_upgrade", "");
#ifdef RTCONFIG_AMAS
	nvram_set("cfg_check", "9");
	nvram_set("cfg_upgrade", "0");
#endif
	FWUPDATE_DBG("---- firmware check update finish ----");
	return 0;
}
#if !defined(BLUECAVE)
void exec_uu()
{
	FILE *fpmodel, *fpmac, *fpuu, *fpurl, *fpmd5, *fpcfg;
	char buf[128];
	int download,i;
	char *dup_pattern, *g, *gg;
	char p[10][100];
	if(nvram_get_int("sw_mode") == 1){
		if ((fpmodel = fopen("/var/model", "w"))){
			fprintf(fpmodel, nvram_get("productid"));
			fclose(fpmodel);
		}
		if ((fpmac = fopen("/var/label_macaddr", "w"))){
			char *etmac=nvram_get("et2macaddr");
			toUpperCase(etmac);
			fprintf(fpmac, etmac);
			fclose(fpmac);
		}
		if ((fpuu = fopen("/var/uu_plugin_dir", "w"))){
			fprintf(fpuu, "/jffs");
			fclose(fpuu);
		}
		system("mkdir -p /tmp/uu");
		download = system("wget -t 2 -T 30 --dns-timeout=120 --header=Accept:text/plain -q --no-check-certificate 'https://router.uu.163.com/api/script/monitor?type=asuswrt-merlin' -O /tmp/uu/script_url");
		if (!download){
			_dprintf("download uuplugin script info successfully\n");
			if ((fpurl = fopen("/tmp/uu/script_url", "r"))!=NULL){
				fgets(buf, 128, fpurl);
				fclose(fpurl);
				unlink("/tmp/uu/script_url");
				i=0;
				g = dup_pattern = strdup(buf);
				gg = strtok( g, "," );
				while (gg != NULL)
				//for(g = strsep(&dup_pattern, ","); g != NULL; g = strsep(&dup_pattern, ","))
				{
					if (gg!=NULL){
						strcpy(p[i], gg);
						i++;
						++download;
						//logmessage("K3", "download: %d",download);
						gg = strtok( NULL, "," );
					}
				}
				if ( download > 0 )
				//if ( download == 2 )
				{
					_dprintf("URL: %s\n",p[0]);
					_dprintf("MD5: %s\n",p[1]);
					//logmessage("K3", "URL: %s,MD5: %s",p[0],p[1]);
					if ( !doSystem("wget -t 2 -T 30 --dns-timeout=120 --header=Accept:text/plain -q --no-check-certificate %s -O /tmp/uu/uuplugin_monitor.sh", p[0]))
					{
						_dprintf("download uuplugin script successfully\n");
						if ((fpcfg = fopen("/tmp/uu/uuplugin_monitor.config", "w"))){
							fprintf(fpcfg, "router=asuswrt-merlin\n");
							fprintf(fpcfg, "model=\n");
							fclose(fpcfg);
						}
						if((fpmd5=popen("md5sum /tmp/uu/uuplugin_monitor.sh | sed 's/[ ][ ]*/ /g' | cut -d' ' -f1", "r")))
						{
							memset(buf,'\0',sizeof(buf));
							if((fread(buf, 1, 128, fpmd5)))
							{
								buf[32]='\0';
								buf[33]='\0';
								//logmessage("K3", "MD5: %s,MD5: %s",buf,p[1]);
								if ( !strcasecmp(buf, p[1]))
								{
									pid_t pid;
									char *uu_argv[] = { "/tmp/uu/uuplugin_monitor.sh", NULL };
									_dprintf("prepare to execute uuplugin stript...\n");
									//logmessage("K3", "prepare to execute uuplugin stript...");
									chmod("/tmp/uu/uuplugin_monitor.sh", 0755);
									_eval(uu_argv, NULL, 0, &pid);
									//eval("/tmp/uu/uuplugin_monitor.sh");
								}
							}
							pclose(fpmd5);
						}
					}
				}
			}
			free(dup_pattern);
		}
	}
}
#endif

#if defined(RTCONFIG_SOFTCENTER)
void softcenter_eval(int sig)
{
	//1=wan,2=nat,3=mount
	pid_t pid;
	char path[100], action[10], sc[]="/jffs/softcenter/bin";
	if(SOFTCENTER_WAN == sig){
		snprintf(path, sizeof(path), "%s/softcenter-wan.sh", sc);
		snprintf(action, sizeof(action), "start");
	} else if (SOFTCENTER_NAT == sig){
		snprintf(path, sizeof(path), "%s/softcenter-net.sh", sc);
		snprintf(action, sizeof(action), "start_nat");
	} else if (SOFTCENTER_MOUNT == sig){
		snprintf(path, sizeof(path), "%s/softcenter-mount.sh", sc);
		snprintf(action, sizeof(action), "start");
	} else {
		logmessage("Softcenter", "sig=%s, bug?",sig);
		return;
	}
	char *eval_argv[] = { path, action, NULL };
	_eval(eval_argv, NULL, 0, &pid);
}
#endif
