
#ifndef _LIOP_H_
#define _LIOP_H_

#define	true 1
#define	false 0

#define	BIT_0		0X01
#define	BIT_1		0X02
#define	BIT_2		0X04
#define	BIT_3		0X08
#define	BIT_4		0X10
#define	BIT_5		0X20
#define	BIT_6		0X40
#define	BIT_7		0X80


#define	T0START_1TO32		0x84						// Start Timer 0, prescaler 1 : 32/
#define	T0H_500ms			0x0C						// Timer 0 preset value 500 ms/
#define	T0L_500ms			0x00
#define	T1START_1TO1	0x03//	0x81						// Start Timer 1, no prescaler
#define	T1H_10ms				0x63						// Timer 1 preset value 2 ms
#define	T1L_10ms				0xC0
#define	T1H_2ms				0xE0//0xF0						// Timer 1 preset value 2 ms
#define	T1L_2ms				0xC0//0x60
#define	T2START_1TO48		0x16//0x0E//0x16						// Start Timer 2, prescaler 1 : 16, postscale 1 : 3
#define	T2_3ms				0xFF

#define	MAX_ESE				110

#define	SETID_NULL			0x00
#define	SETID_BY_KEY		0x01
#define	SETID_BY_CAN		0x02

/************************************************************************************************/
/* Definitions for input and output variables													*/
/************************************************************************************************/
#define	IO_BASIC_FUNC		0							/* basic function of input / output		*/
#define	IO_SUB_FUNC			1							/* sub function of input / output		*/
#define	IO_LIFT				2							/* lift number of input / output		*/
#define	IO_FLOOR			3							/* floor number of input / output		*/
#define	IO_DOOR				4							/* door number of input / output		*/
#define	IO_STATE			5							/* state of input / output				*/
#define	IO_ENABLE		6
#define	IO_ACK				7							/* acknowledgement marker for calls		*/
#define	ENABLE				1
#define	DISABLE			0

#define	WD_MERKER			0xAA						// restart by watchdog timer
#define	BS_MERKER			0x55						// restart by CAN bus off
#define	RC_MERKER			0x5A						// restart by error in rc pointer
#define	ID_MERKER			0xA5

#define SDO_TIMER			0x0A
#define	MAX_IO				8
#define	MAX_IO_TYPE	7

#define HSETIME						50//10
#define HEARTBEATTIME			4
#define	ID_SET_TIME					50
#define	MAX_LIFT						8
#define	INPUT_DETECT_INTERVAL		7
#define ERROR_TIME			20
#define FLASH_TIME			6

//背光灯时间常量
#define	NO_SIGNAL_TIMEOUT		120
#define	DARK_COUNT		8//5
#define	CTE_FLAG_MODE	0x55

#define	BACKLIGHT_NORMAL		0
#define	BACKLIGHT_DARK		1
#define	BACKLIGHT_OFF		2

#define	KEYCODE_UP		BIT_0
#define	KEYCODE_DOWN		BIT_1
#define	KEYCODE_SYSSET	BIT_2
#define	NO_KEY				0xAA

enum {NotUsed, KEYVALUE_UP, KEYVALUE_DOWN, KEYVALUE_SYSSET};

//按住键后可开始重复定时(以100MS为单位)
#define ENABLEREPINTERVAL 	5
//重复键的时间间隔(以100MS为单位)
#define REPEATINTERVAL 		2
#define LONGKEYTIME_SET		30

//定义宏
#define	OPEN_BL()	LATAbits.LATA3 = 1
#define	CLOSE_BL()	LATAbits.LATA3 = 0
#define	OPEN_FULL()	LATEbits.LATE0 = 1
#define	CLOSE_FULL()	LATEbits.LATE0 = 0
#define	OPEN_FIRE()	LATEbits.LATE1 = 1
#define	CLOSE_FIRE()	LATEbits.LATE1 = 0
#define	OPEN_OUT_OF_ORDER()	LATEbits.LATE1 = 1
#define	CLOSE_OUT_OF_ORDER()	LATEbits.LATE1 = 0
#define	OPEN_INUSE()	LATEbits.LATE2 = 1
#define	CLOSE_INUSE()	LATEbits.LATE2 = 0

#ifdef _MAIN_C_

BYTE merker;					// variable for restart

BYTE node_id = 0;					// node id of CAN
BYTE disp_id = 0;
BYTE disp_lift = 0;				// ift number assigned to display
BYTE nmtstate;					// network management state
BYTE setid_mode;				// set liop can ID mode
BYTE setid_mode_old;				// set liop can ID mode
BYTE preset_node_id = 0;

BYTE id_buff[4];
WORD volatile nmtwait;			// waiting time for 1. heartbeat

WORD volatile sdo_index = 0;
BYTE volatile sdo_subindex = 0;
BYTE sdo_timer = 0;				// timer for SDO segment transfer
BYTE errorregister = 0;			// error register
WORD errorcode = 0;				// error code
DWORD device_type;				// Device type and profile number
WORD virtual_device[3];			// Virtual device types + profile number

BYTE volatile input[3];			// input variables for debouncing
BYTE volatile in;				// variable for input after debouncing
BYTE inold;						// variable to save old input state
BYTE volatile out;				// output state
BYTE volatile inpush;			// push button inputs
BYTE volatile outpush;			// push button indication
BYTE in_polarity;				// input is inverted / not inverted
BYTE out_polarity;				// output is inverted / not inverted

BYTE		row 			= 0;				// row to switch on 				
BYTE		scroll		= 0;				// 1 : UP 	2: DN 	other: NO_Arrow 
SBYTE 	scrollpos 	= 0;			// 1 more value to transmit 	
BYTE		scrolltimer = 0;			// timer for scrolling arrows 	

BYTE heartbeat;					// timer for transmitting heartbeat
BYTE input_detect = 0;

BYTE landingcalltimer = 0;		// timer for landing call misuse
BYTE landingcallfloor = 0;		// flor marker for landing call misuse
BYTE direction_ind_mode = 0;

BYTE virt_in[MAX_IO_TYPE];				// virtual input (last changed)
BYTE virt_out[MAX_IO_TYPE];				// virtual output (last changed)
BYTE inpar[MAX_IO][MAX_IO_TYPE];			// input parameter
BYTE outpar[MAX_IO][MAX_IO_TYPE + 1];			// output parameter

BYTE arrowtype = 0;				// arrow type
BYTE arrowflash = 0;
BYTE arrowflash_old = 0;
BYTE flashcontent = 0;
BYTE mSwitch_code = 0;
BYTE	baudrate = 0;

BYTE volatile hsetime;
BYTE volatile hsecheck = 0;
BYTE volatile hse_heartbeat = 0;
BYTE volatile can_inittime = 0;
BYTE can_passive_time = 0;
BYTE display_scantimer = 0;
BYTE hardware_version = 0;
BYTE timer1_countH = 0;
BYTE timer1_countL = 0;
BYTE com_can_work = 0;
BYTE keytimer = 0;
BYTE flashtimer = 0;

BYTE mKeyValue = 0;
BYTE mKeyValue_Back = 0;
BYTE mLongKeyTime = 0;
BYTE timer_1S5 = 0;
BYTE display_timer = 0;
BYTE testno = 0;

BYTE u8Start_Dark = 0;
BYTE u8PWM_Count = 0;
BYTE backlight_mode = 0;
BYTE backlight_func = 0;			
WORD backlight_off_time = 0;
WORD backlight_time_count = 0;
BYTE light_para_ok = 0;
BYTE display_STN_mode = 0;
	// 0-->按照最新的楼层布局图显示,   数字"1"在右边
	// 1 -->改进"17"的显示楼层，数字"1"在左边，"17"的1在右边
	// 2，3-->保留备用

BYTE recei_monitor[8];

BYTE const tKeyCode[] = {
	KEYCODE_UP	, KEYCODE_DOWN, KEYCODE_SYSSET, NO_KEY,
};

struct{
	BYTE KeyScanEn 	:1; 	//按键扫描允许标志
	BYTE KeyTrue 		:1; 	//按键有效标志
	BYTE LKeyScanEnd :1; 	//长按键扫描结束标志
	BYTE LongKeyEn 	:1; 	//长按键有效标志
	BYTE KeyAnswer 	:1; 	//按键响应标志
	BYTE KeyRepeat 	:1; 	//重复键定时
	BYTE KeyRepeatEn :1; 	//按住键1秒后允许重复
}bKey_Fg;

struct {
	BYTE Time_10ms: 1;		//10ms 标志
	BYTE Time_100ms: 1;		//100ms 标志
	BYTE Time_500ms: 1;		//500ms 标志
	BYTE Time_2s: 1;
	BYTE Time_5s: 1;
	BYTE Time_alarm_fg: 1;		//司机蜂鸣器工作标志
}bTime;

#else

extern	BYTE input_detect;

extern BYTE merker;
extern BYTE scroll;

extern BYTE node_id;
extern BYTE disp_id;
extern BYTE disp_lift;
extern BYTE nmtstate;
extern BYTE setid_mode;
extern BYTE setid_mode_old;				// set liop can ID mode
extern BYTE preset_node_id;

extern BYTE id_buff[];
extern WORD volatile nmtwait;

extern WORD volatile sdo_index;
extern BYTE volatile sdo_subindex;
extern BYTE sdo_timer;
extern BYTE errorregister;
extern WORD errorcode;
extern DWORD device_type;
extern WORD virtual_device[];

extern BYTE volatile input[];
extern BYTE volatile in;
extern BYTE inold;
extern BYTE volatile input[];
extern BYTE volatile in;
extern BYTE inold;
extern BYTE virt_in[];
extern BYTE virt_out[];
extern BYTE volatile out;
extern BYTE volatile inpush;
extern BYTE volatile outpush;
extern BYTE in_polarity;
extern BYTE out_polarity;
extern BYTE landingcalltimer;
extern BYTE landingcallfloor;
extern BYTE direction_ind_mode;

extern BYTE inpar[MAX_IO][MAX_IO_TYPE];
extern BYTE outpar[MAX_IO][MAX_IO_TYPE + 1];

extern BYTE volatile display[];
extern BYTE arrowtype;
extern BYTE arrowflash;
extern BYTE arrowflash_old;
extern BYTE flashcontent;
extern BYTE mSwitch_code;

extern BYTE		row;				// row to switch on 				
extern BYTE		scroll;				// 1 : UP 	2: DN 	other: NO_Arrow 
extern SBYTE 	scrollpos;			// 1 more value to transmit 	
extern BYTE		scrolltimer;			// timer for scrolling arrows 	

extern BYTE heartbeat;

extern BYTE volatile hsetime;
extern BYTE volatile hsecheck;
extern	BYTE volatile hse_heartbeat;
extern	BYTE volatile can_inittime;
extern	BYTE can_passive_time;
extern	BYTE display_scantimer;

extern	BYTE mKeyValue;
extern	BYTE mKeyValue_Back;
extern	BYTE mLongKeyTime;

extern	BYTE hardware_version;
extern	BYTE timer1_countH;
extern	BYTE timer1_countL;
extern	BYTE com_can_work;
extern	BYTE keytimer;
extern	BYTE flashtimer;
extern	BYTE timer_1S5;
extern	BYTE display_timer;
extern	BYTE testno;
extern	BYTE u8Start_Dark;
extern	BYTE u8PWM_Count;
extern	BYTE backlight_mode;
extern	BYTE backlight_func;			
extern	WORD backlight_time_count;
extern	WORD backlight_off_time;
extern	BYTE light_para_ok;

extern	BYTE recei_monitor[8];
extern	BYTE display_STN_mode;

extern	BYTE const tKeyCode[];
extern	struct{
	BYTE KeyScanEn 	:1; 	//按键扫描允许标志
	BYTE KeyTrue 		:1; 	//按键有效标志
	BYTE LKeyScanEnd :1; 	//长按键扫描结束标志
	BYTE LongKeyEn 	:1; 	//长按键有效标志
	BYTE KeyAnswer 	:1; 	//按键响应标志
	BYTE KeyRepeat 	:1; 	//重复键定时
	BYTE KeyRepeatEn :1; 	//按住键1秒后允许重复
}bKey_Fg;

extern	struct {
	BYTE Time_10ms: 1;		//10ms 标志
	BYTE Time_100ms: 1;		//100ms 标志
	BYTE Time_500ms: 1;		//500ms 标志
	BYTE Time_2s: 1;
	BYTE Time_5s: 1;
	BYTE Time_alarm_fg: 1;		//司机蜂鸣器工作标志
}bTime;


#endif
#endif

