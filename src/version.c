
#include "typedef.h"
#include "bootloader.h"

//#define	__DEBUG

DWORD const identyty[ID_NUMS] =
{
	0x000000B5,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 注意:软件版本的格式为 "vX.XX",在测试仪及硬件测试中使用,不可随意更改
BYTE const version_uea_G741[SW_SIZE] = "V1.5A";
BYTE const version_uea_G742[SW_SIZE] = "V1.4A";

BYTE const hardware_uea_G741[HW_SIZE] = "V1.3";	
BYTE const device_name_G741[DV_SIZE] = {
	'G', '-', '7', '4', '1',
};

BYTE const hardware_uea_G742[HW_SIZE] = "V1.1";	
BYTE const device_name_G742[DV_SIZE] = {
	'G', '-', '7', '4', '2',
};

WORD const version_fver = FVER_G_741;

#ifdef __DEBUG
DWORD const version_chksum = DEBUG_CHKSUM;
#else
DWORD const version_chksum = 0xffffffff;
#endif

