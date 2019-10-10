#if defined(RTCONFIG_QCA)
#include <net/ethernet.h>
#endif
//amas_bhctrl connection status
#define ETH 		0x01  	//ethernet
#define WL_2G 		0x02  	//2G
#define WL_5G 		0x04	//5G
#define WL_5G_1 	0x08	//5G-1

/*
Ethernet selection rule:
ETHERNET_PLUGIN: ethernet connected to P-AP and CAP.
ETHERNET_HOP : ethernet connected to P-AP and CAP, ethernet hop count smaller than wireless.
We add nvram [amas_ethernet] for config ethernet selection rule.
*/
enum {
		NONE=0,
		ETHERNET_NONE,
		ETHERNET_PLUGIN,
		ETHERNET_HOP,
};



#define OB_OFF			1
#define OB_AVALIABLE	2
#define OB_REQ			3
#define OB_LOCKED		4
#define OB_SUCCESS		5

#define SS_OFF              0
#define SS_KEY				1
#define SS_KEYACK			2
#define SS_SECURITY			3
#define SS_SUCCESS			4
#define SS_FAIL         	5
#define SS_KEYFAIL			6
#define SS_SECURITYFAIL		7
#define SS_TIMEOUT          8
#define SS_KEY_FIN			9
#define	SS_KEYACK_FIN		10
#define SS_SECURITY_FIN		11
#define SS_SUCCESS_FIN		12
#define SS_OBD_FIN          13


#define HASH_LEN			32
#define GEN_KEY_LEN			32


/*Only for ETH1, ETH2, 2G, 5G1, 5G2,  if add ethernet/wireless interface, must modify  bitmask defined.
                                                      Wireless                                          Ethernet
                                                Value 使用與否                 優先權                   使用與否                         優先權                       Backward compatible for amas_ethernet
Bitmask                                                  15     14   13   12     11      10    9    8       7        6       5      4       3        2      1     0
                                                      Reserved  5G2  5G1 2.4G Reserved  5G2   5G1  2.4G Reserved Reserved  ETH2   ETH1  Reserved Reserved  ETH2  ETH1
ETH1_ONLY                                    0x001100         0    0    0    0        0     0    0     0        0        0      0      1        0        0     0     1     0     0     0     0     0     0     0     0
ETH2_ONLY                                    0x002200         0    0    0    0        0     0    0     0        0        0      1      0        0        0     1     0     0     0     0     0     0     0     0     0
ETH1_ETH2_ONLY_ETH1FIRST                     0x003100         0    0    0    0        0     0    0     0        0        0      1      1        0        0     0     1     0     0     0     0     0     0     0     0
ETH1_ETH2_ONLY_ETH2FIRST                     0x003200         0    0    0    0        0     0    0     0        0        0      1      1        0        0     1     0     0     0     0     0     0     0     0     0
WL2G_ONLY                                    0x110000         0    0    0    1        0     0    0     1        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0
WL5G1_ONLY                                   0x220000         0    0    1    0        0     0    1     0        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0
WL5G2_ONLY                                   0x440000         0    1    0    0        0     1    0     0        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0
WL2G_5G1_ONLY_2GFIRST                        0x310000         0    0    1    1        0     0    0     1        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0
WL2G_5G1_ONLY_5G1FIRST                       0x320000         0    0    1    1        0     0    1     0        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0
ETH1_ETH2_2G_5G1_BYCOST_ETH1FIRST            0x303100         0    0    1    1        0     0    0     0        0        0      1      1        0        0     0     1     0     0     0     0     0     0     0     0
ETH1_ETH2_2G_5G1_BYCOST_ETH2FIRST            0x303200         0    0    1    1        0     0    0     0        0        0      1      1        0        0     1     0     0     0     0     0     0     0     0     0
ETH1_ETH2_2G_5G1_BYCOST_2GFIRST              0x313000         0    0    1    1        0     0    0     1        0        0      1      1        0        0     0     0     0     0     0     0     0     0     0     0
ETH1_ETH2_2G_5G1_BYCOST_5G1FIRST             0x323000         0    0    1    1        0     0    1     0        0        0      1      1        0        0     0     0     0     0     0     0     0     0     0     0
WL2G_5G2_ONLY_2GFIRST                        0x510000         0    1    0    1        0     0    0     1        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0
WL2G_5G1_5G2_ONLY_5G1FIRST                   0x720000         0    1    1    1        0     0    1     0        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0
WL2G_5G2_ONLY_5G2FIRST                       0x540000         0    1    0    1        0     1    0     0        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0
ETH1_ETH2_2G_5G2_BYCOST_ETH1FIRST            0x503100         0    1    0    1        0     0    0     0        0        0      1      1        0        0     0     1     0     0     0     0     0     0     0     0
ETH1_ETH2_2G_5G2_BYCOST_ETH2FIRST            0x503200         0    1    0    1        0     0    0     0        0        0      1      1        0        0     1     0     0     0     0     0     0     0     0     0
ETH1_ETH2_2G_5G2_BYCOST_2GFIRST              0x513000         0    1    0    1        0     0    0     1        0        0      1      1        0        0     0     0     0     0     0     0     0     0     0     0
ETH1_ETH2_2G_5G1_5G2_BYCOST_5G1FIRST         0x723000         0    1    1    1        0     0    1     0        0        0      1      1        0        0     0     0     0     0     0     0     0     0     0     0
ETH1_ETH2_2G_5G2_BYCOST_5G2FIRST             0x543000         0    1    0    1        0     1    0     0        0        0      1      1        0        0     0     0     0     0     0     0     0     0     0     0
amas_ethernet=2 (Ethernet1_First)            0x000002         0    0    0    0        0     0    0     0        0        0      0      0        0        0     0     0     0     0     0     0     0     0     1     0
amas_ethernet=3 (Auto_by_cost)               0x000003         0    0    0    0        0     0    0     0        0        0      0      0        0        0     0     0     0     0     0     0     0     0     1     1
*/

#define ETH1_ONLY								0x001100
#define ETH2_ONLY								0x002200
#define ETH1_ETH2_ONLY_ETH1FIRST				0x003100
#define ETH1_ETH2_ONLY_ETH2FIRST				0x003200

#define WL2G_ONLY								0x110000
#define WL5G1_ONLY								0x220000
#define WL5G2_ONLY								0x440000

#define WL2G_5G1_ONLY_2GFIRST					0x310000
#define WL2G_5G1_ONLY_5G1FIRST					0x320000
#define ETH1_ETH2_2G_5G1_BYCOST_ETH1FIRST 		0x303100
#define ETH1_ETH2_2G_5G1_BYCOST_ETH2FIRST 		0x303200
#define ETH1_ETH2_2G_5G1_BYCOST_2GFIRST   		0x313000
#define ETH1_ETH2_2G_5G1_BYCOST_5G1FIRST		0x323000

#define WL2G_5G2_ONLY_2GFIRST					0x510000
#define WL2G_5G1_5G2_ONLY_5G1FIRST				0x720000
#define WL2G_5G2_ONLY_5G2FIRST					0x540000
#define ETH1_ETH2_2G_5G2_BYCOST_ETH1FIRST		0x503100
#define ETH1_ETH2_2G_5G2_BYCOST_ETH2FIRST		0x503200
#define ETH1_ETH2_2G_5G2_BYCOST_2GFIRST			0x513000
#define ETH1_ETH2_2G_5G1_5G2_BYCOST_5G1FIRST	0x723000
#define ETH1_ETH2_2G_5G2_BYCOST_5G2FIRST		0x543000

#define OLD_ETH1_FIRST							0x000002
#define OLD_AUTO_BY_COST						0x000003

#define BAND_2G_5G1_AUTO_MASK					0x303000
#define BAND_2G_5G1_5G2_AUTO_MASK				0x703000
#define BAND_2G_5G2_AUTO_MASK					0x503000

#define B2G_5G1_5G2_MASK						0x700000
#define B2G_5G2_WL_MASK							0x500000
#define B2G_5G1_WL_MASK							0x300000

#define ALL_ETH_MASK							0x003000


/*Indicate first priority.
                               Wireless                                          Ethernet                                                      Reserved                                         Value
                               使用與否                 優先權                   使用與否                         優先權
Bitmask                           15     14   13   12     11      10    9    8       7        6       5      4       3        2      1     0
                               Reserved  5G2  5G1 2.4G Reserved  5G2   5G1  2.4G Reserved Reserved  ETH2   ETH1  Reserved Reserved  ETH2  ETH1
ETH1                                   0    0    0    0        0     0    0     0        0        0      0      0        0        0     0     1     0     0     0     0     0     0     0     0   0x000100
ETH2                                   0    0    0    0        0     0    0     0        0        0      0      0        0        0     1     0     0     0     0     0     0     0     0     0   0x000200
2G                                     0    0    0    0        0     0    0     1        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0   0x010000
5G1                                    0    0    0    0        0     0    1     0        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0   0x020000
5G2                                    0    0    0    0        0     1    0     0        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0   0x040000
*/

#define MAX_ETH						4
#define MAX_WIFI					4
#define ETH1_P					0x000100
#define ETH2_P					0x000200
#define ETH3_P					0x000300
#define ETH4_P					0x000400
#define WL2G_P					0x010000
#define WL5G1_P					0x020000
#define WL5G2_P					0x040000

/*Indicate use interface.
                               Wireless                                          Ethernet                                                      Reserved                                         Value
                               使用與否                 優先權                   使用與否                         優先權
Bitmask                        15       14   13   12   11       10    9    8     7        6        5      4      3        2        1     0
                               Reserved 5G2  5G1  2.4G Reserved 5G2   5G1  2.4G  Reserved Reserved ETH2   ETH1   Reserved Reserved ETH2  ETH1
ETH1                                   0    0    0    0        0     0    0     0        0        0      0      1        0        0     0     0     0     0     0     0     0     0     0     0   0x001000
ETH2                                   0    0    0    0        0     0    0     0        0        0      1      0        0        0     0     0     0     0     0     0     0     0     0     0   0x002000
2G                                     0    0    0    1        0     0    0     0        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0   0x010000
5G1                                    0    0    1    0        0     0    0     0        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0   0x200000
5G2                                    0    1    0    0        0     0    0     0        0        0      0      0        0        0     0     0     0     0     0     0     0     0     0     0   0x400000

*/
#define ETH_MAX_BASE			0x008000
#define WL_MAX_BASE				0x800000
#define ETH1_U					0x001000
#define ETH2_U					0x002000
#define ETH3_U					0x004000
#define ETH4_U					0x008000
#define WL2G_U					0x100000
#define WL5G1_U					0x200000
#define WL5G2_U					0x400000

/*COST Verify
DONT_COST (don't check cost)		0	0	1	0x01
ETH_COST  (cost for eth only)		0	1	0	0x02
WIFI_COST (cost for wifi only)		0	1	1	0x03
ALL_COST  (cost for wifi & eth)		1	0	0	0x04
AUTO_COST							1	0	1	0x05

AUTO_COST:
	If a part of the interface gets the cost, choose the interface that has the cost.
	If it fail to get the cost for all interface, we will not check the cost for any path.
	If it can get the cost for all interfaces, we will check the cost for all path.
*/
#define DONT_COST				0x01
#define ETH_COST				0x02
#define WIFI_COST				0x03
#define ALL_COST				0x04
#define AUTO_COST				0x05


/*RSSI SCORE Verify
DONT_RSSISCORE (don't check rssi_score)		1	0	0	0x01
AUTO_RSSISCORE								0	1	0	0x02

AUTO_RSSISCORE:
	If a part of the interface gets the cost, we will not check the cost for any path.
	If it fail to get the cost for all interface, we will not check the cost for any path.
	If it can get the cost for all interfaces, we will check the cost for all path.

	Wi-Fi backhaul's choice based on priority.
	Wi-Fi backhaul and Ethernet backhaul selection based on RSSIscore or cost.
*/

#define DONT_RSSISCORE			0x01
#define ETH_RSSISCORE			0x02
#define WIFI_RSSISCORE			0x03
#define ALL_RSSISCORE			0x04
#define AUTO_RSSISCORE			0x05

/*amas_bhctrl sent command for and amas_wlcconnect by IPC*/
#define ACTION_START					"START_CONNECTING"
#define ACTION_RESTART					"RESTART_CONNECTING"
#define ACTION_STOP						"MAINTAIN_STATUS_QUO"
#define ACTION_START_OPTIMIZATION		"START_SELF_OPTIMIZATION"
#define ACTION_STOP_OPTIMIZATION		"STOP_SELF_OPTIMIZATION"
#define ACTION_DISCONNECT				"DISCONNECT_BAND"
#define ACTION_START_BY_DRIVER			"START_CONNECTING_BY_DRIVER"


#define START_CONNECTING				0x01
#define RESTART_CONNECTING				0x02
#define MAINTAIN_STATUS_QUO				0x03
#define START_SELF_OPTIMIZATION			0x04
#define STOP_SELF_OPTIMIZATION			0x05
#define DISCONNECT_BAND 				0x06
#define START_CONNECTING_BY_DRIVER		0x07

/*amas_wlc_action_state for amas_wlcconnect*/
#define IDLE						0x00
#define BUSY						0x01
#define FIN							0x02

/*Who triggered the behavior of self-optimize*/
#define OPTMZ_FROM_RE				0x01   	// trigger by amas_bhctrl
#define OPTMZ_FROM_CAP				0x02	// trigger by cfg_mnt


#define SEND_ACTION_RESET			0x00
#define SEND_ACTION_SUCCESS			0x01
#define SEND_ACTION_FAIL			0x02




