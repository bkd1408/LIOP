
#ifndef _CANOPEN_H_
#define _CANOPEN_H_

//*******************************************************************************
// Function code in CAN identifier
//*******************************************************************************
#define	FCT_CODE_MASK			0xF0		/* Mask for function code in identifier				*/
#define	NMT						0x00		// NMT message
#define	EMERGENCY				0x10		// Emergency message
#define	TIME					0x20		// Time stamp message
#define	FC_3					0x30		// Function code for load message, drive messages..
#define	DOORS					0x40		// Door message
#define	FC_5					0x50		// Function code for FU (Lust bus)
#define	FC_6					0x60		// Function code for FU (Lust bus)
#define	FC_7					0x70		// Function code 7 (not in use)
#define	PDO_OUT					0x80		// PDO virtual output
#define	PDO_IN					0x90		// PDO virtual input
#define	MPDO					0xA0		// Multiplexed PDO
#define	TSDO					0xB0		// transmit SDO message
#define	RSDO					0xC0		// receive SDO message
#define	FC_D					0xD0		// Function code 0x0D (not in use) Time
#define	HEARTBEAT				0xE0		// Heartbeat message
#define	LSS						0xF0		// Layer setting services

//*******************************************************************************
// Definitions for standard node id
//*******************************************************************************
#define	HSE_ID					0x01		// node id HSE
#define	DCU_ID					0x02		// node id DCU
#define	SAF_ID					0x03		/* node id Safety circuit (SGM)						*/
#define	PSE_ID					0x04		// node id PSE
#define	EXE_ID					0x05		// node id of 1. EXT board, total 4 pcs 0x05~0x08
#define	DOOR3_ID				0x06		/* node id door 3 (not CANopen conform)				*/
#define	DOOR1_ID				0x07		/* node id door 1									*/
#define	DOOR2_ID				0x08		/* node id door 2									*/

#define	DSE_ID					0x09		// node id DSE
#define	MON_ID				0x0A		// node id monitoring system
#define	EMS_ID					0x0B		// node id monitoring system2
#define	SHM_ID					0x0B		/* node id Safety module SHM						*/
#define	FVE_ID					0x0C		// node id FVE
#define	CBC_ID					0x0D		/* node id of 1. CBC								*/
#define	WEIGHT_ID				0x0D		/* node id of load measuring device					*/
#define	DRV_ID					0x0E		// node id drive
#define	MUL_FUNC			0x0F		// node id of 辅助功能ID
#define	TSE_ID					0x10		// node id of 1. TSE
#define	READ_CARD_ID		0x20		// node id of 1. TSE
#define	ESE_ID					0x10		// node id of 1. ESE
#define	INI_ID					0x7D		// node id of init

//Virtual termial ID
#define	DOOR_CONTROLLER_ID	0x30		// node id of SPEECH
#define	POSITION_SYSTEM_ID		0x31		// node id of SPEECH
#define	LOADWEIGH_ID				0x32		// node id of SPEECH
#define	RFID_COP_ID					0x33		// node id of SPEECH
#define	SPEECH_ID						0x34		// node id of SPEECH
#define	COP_DISPLAY_ID			0x35		// node id of SPEECH
#define	RFID_LIOP_ID				0x60		// node id of SPEECH
#define	LIOP_DISPLAY_ID			0x60		// node id of SPEECH

//*******************************************************************************
// Part 2 of identifier if function code is EMERGENCY
//*******************************************************************************
#define	SYS_FU_ID				0x5D		// ID part 2 system start FU (Lust bus)

/************************************************************************************************/
/* Part 2 of identifier if function code is TIME												*/
/************************************************************************************************/
#define	TIME_ID					0x00		/* ID part 2 time of day							*/

/************************************************************************************************/
/* Definition for MPDO																			*/
/************************************************************************************************/
#define	MPDO_DESTINATION		0x80		/* MPDO destination address mode					*/

//*******************************************************************************
// Part 2 of identifier if function code is FC_3
//*******************************************************************************
#define	DRV_TARGET				0x00		/* ID part 2 Target position for position mode		*/
#define	CONTR_DRV_P				0x00		// ID part 2 Control word Drive position mode
#define	CONTR_EFFORT			0x01		/* ID part 2 Control effort for position mode		*/
#define	STAT_DRV_P				0x01		// ID part 2 Status word Drive position mode
#define	CONTR_DRV_V				0x04		// ID part 2 Control word Drive velocity mode
#define	STAT_DRV_V				0x05		// ID part 2 Status word Drive velocity mode
#define	LOAD_ID					0x08		// ID part 2 Load
#define	LOAD_STATE			0x09
#define	CONTR_POS				0x0A		/* ID part 2 Position supervisor unit control		*/
#define	STAT_POS				0x0B		/* ID part 2 Position supervisor unit status		*/
#define	POS_ID					0x0C		// ID part 2 Position
#define	POS1_ID					0x0D		/* ID part 2 Position from unit 2					*/
#define	RELAY_HSE				0x25		/* ID part 2 Relay test (Response to LIMAX)			*/
#define	RELAY_LIMAX				0x2C		/* ID part 2 Relay test	(Request from LIMAX)		*/
#define	ERR_FU_ID				0x3A		// ID part 2 Error FU (Lust bus)
//*******************************************************************************
// Part 2 of identifier if function code is DOORS
//*******************************************************************************
#define	DOOR_ID					0x00		// ID part 2 car door + door number
#define	LS_ID					0x04		// ID part 2 Light screen + door number
#define	DOOR_FVE				0x08		/* ID part 2 FVE as car door controller				*/

//*******************************************************************************
// Part 2 of identifier if function code is FC_5
//*******************************************************************************
#define	CONTR_FU_ID				0x16		// ID part 2 Control word FU (Lust bus)
#define	ERROR_POS				0x00		/* ID part 2 Error register pos. supervisor unit	*/

//*******************************************************************************
// Part 2 of identifier if function code is FC_6
//*******************************************************************************
#define	STAT_FU_ID				0x72		// ID part 2 Status word FU (Lust bus)

//*******************************************************************************
// Part 2 of identifier if function code is PDO_OUT
//*******************************************************************************
#define	KOMM_FU_ID				0x4E		// ID part 2 communication with FU (Lust bus)

//*******************************************************************************
// Part 2 of identifier if function code is RSDO
//*******************************************************************************
#define	START_FU_ID				0x08		// ID part 2 Start FU (Lust bus)

//*******************************************************************************
// Part 2 of identifier if function code is MPDO
//*******************************************************************************
#define	QUIT_FU_ID				0x2A		// ID part 2 communication with FU (Lust bus)

//*******************************************************************************
// Part 2 of identifier if function code is LSS
//*******************************************************************************
#define	LSS_REQ_ID				0x65		// ID part 2 LSS request
#define	LSS_RES_ID				0x64		// ID part 2 LSS response


//*******************************************************************************
// modrol SDO and paratype definition
//*******************************************************************************
#define	MODROL_SDO_READ			0x40
#define	MODROL_SDO_WRITE		0x22
#define	MODROL_ACK_READ			0x42
#define	MODROL_ACK_WRITE		0x60
#define	MODROL_ACK_ERROR		0x80
#define	MAX_SDO_RETRY			5

#define	MODROL_SDO_INVALID_ADDR	0x00		// 非法地址
#define	MODROL_SDO_ERROR_LENGTH	0x10		// 数据长度错误
#define	MODROL_SDO_INVALID_OP	0x11		// 非法操作(特征字错误)
#define	MODROL_SDO_OUT_OF_RANGE	0x30		// 写入参数超范围
#define	MODROL_SDO_REFUSE_ACCESS	0x22		// 驱动器运行中，不能

#define	MODROL_CMD_ADDR			0xC0		// 命令地址

#define	MODROL_CMD_TEACHIN		0x0300		// 自学习
#define	MODROL_CMD_RESET_PARA	0x0400		// 复位参数
#define	MODROL_CMD_CLEAR_ERR	0x0500		// 清除故障
#define	MODROL_CMD_REWRITE_EE	0x0700		// 重写 EEPROM
#define	MODROL_CMD_RESET		0x0001		// 复位
#define	MODROL_CMD_SET_ENCODER	0x1000		// 设置编码器计数

#define	MODROL_CMD_ACK_OK		0x01
#define	MODROL_CMD_ACK_FAIL		0x02


#define	IV_TEACH_MODE_0			0x01
#define	IV_TEACH_MODE_1			0x02
#define	IV_TEACH_MODE_2			0x04
#define	IV_TEACH_MODE_3			0x08
#define	IV_TEACH_MODE_4			0x10

#define	MODROL_TEACH_IN_ACK_START	0x01
#define	MODROL_TEACH_IN_ACK_NOINIT	0x02
#define	MODROL_TEACH_IN_ACK_INVALID	0x03
#define	MODROL_TEACH_IN_ACK_SUCCESS	0x04


#define	MODROL_1BYTE			0x00
#define	MODROL_2BYTE			0x01
#define	MODROL_4BYTE			0x02
#define	MODROL_BITS				0x03

#define	ADDR_LOW_VOLTAGE_EN		0x442B
#define	LOW_VOLTAGE_EN_YES		(0x01 << 4)
#define	LOW_VOLTAGE_EN_NO		(0x00 << 4)

#define	ADDR_CTRL_MODE			0x4E2
#define	VECT_I					2
#define	VECT_M					3
#define	PM_VECT_I				4
#define	PM_VECT_M				5

#define	ADDR_ENC_ANGLE			0x486

#define	ADDR_LOAD_MEM			0x28
#define	SIZE_LOAD_MEM			MODROL_BITS
#define	BIT_LOAD_MEM			2

//*******************************************************************************
// SDO type (Byte 0 in SDO)
//*******************************************************************************
#define	COMMAND_SPECIFIER		0xE0		// command specifier of SDO, Bit 7 (MSB) to Bit 5
#define	INIT_WRITE_REQ			0x20		// Initialize write or expedited write request
#define	INIT_WRITE_RESP			0x60		// Initialize write or expedited write response
#define	WRITE_SEGM_REQ			0x00		// Write segment request
#define	WRITE_SEGM_RESP			0x20		// Write segment response
#define	INIT_READ_REQ			0x40		// Initialize read or expedited read request
#define	INIT_READ_RESP			0x40		// Initialize read or expedited read response
#define	READ_SEGM_REQ			0x60		// Read segment request
#define	READ_SEGM_RESP			0x00		// Read segment response
#define	ABORT_REQ				0x80		// Abort SDO transfer request
#define	EXPEDITED_BIT			0x02		// Bit 1=0: Normal transfer; =1: Expedited transfer
#define	TOGGLE_BIT				0x10		// Bit 4 is toggle bit; must be 0 for 1. segment
#define	SET_TOGGLE_BIT			0x10		// Set Bit 4 (toggle bit)
#define	LAST_SEGM_BIT			0x01		// more segments (=0) or no more segments (=1)
#define	WSIZE_1_DB				0x0C		// 1 data bytes in SDO (expedited mode) for write
#define	WSIZE_2_DB				0x08		// 2 data bytes in SDO (expedited mode) for write
#define	WSIZE_3_DB				0x04		// 3 data bytes in SDO (expedited mode) for write
#define	WSIZE_4_DB				0x00		// 4 data bytes in SDO (expedited mode) for write
#define	RSIZE_1_DB				0x0C		// 1 data bytes in SDO (expedited mode) for read
#define	RSIZE_2_DB				0x0A		// 2 data bytes in SDO (expedited mode) for read
#define	RSIZE_3_DB				0x08		// 3 data bytes in SDO (expedited mode) for read
#define	RSIZE_4_DB				0x06		// 4 data bytes in SDO (expedited mode) for read
#define	RSIZE_5_DB				0x04		// 5 data bytes in SDO (expedited mode) for read
#define	RSIZE_6_DB				0x02		// 6 data bytes in SDO (expedited mode) for read
#define	RSIZE_7_DB				0x00		// 7 data bytes in SDO (expedited mode) for read
#define	SIZE_IND				0x01		// size indicated in segmented read
#define SIZE_FIELD				0x0C		/* bits to indicate size for expedited transfer		*/
#define BRANCH_FIELD_INIT		0x1C		/* ESE branch bits (not CANopen conform)			*/
#define BRANCH_FIELD_SEGM		0x0E		/* ESE branch bits (not CANopen conform)			*/

//*******************************************************************************
// Error code for SDO abort request
//*******************************************************************************
#define	SDO_TOGGLEBIT			0x05030000	// Toggle bit not alternated
#define	SDO_TIMEOUT				0x05040000	// SDO protocol timed out
#define	SDO_NOT_VALID			0x05040001	// Client/server command specifier not valid/unknown
#define	SDO_BLOCKSIZE			0x05040002	// Invalid block size (block mode only)
#define	SDO_SEQU_NUMBER			0x05040003	// Invalid sequence number (block mode only)
#define	SDO_CRC					0x05040004	// CRC error (block mode only)
#define	SDO_OUT_OF_MEM			0x05040005	// Out of memory
#define	SDO_UNSUPPORTED			0x06010000	// Unsupported access to an object
#define	SDO_READ_OF_WO			0x06010001	// Attempt to read a write only object
#define	SDO_WRITE_OF_RO			0x06010002	// Attempt to write a read only object
#define	SDO_NOT_EXIST			0x06020000	// Object does not exist in the object dictionary
#define	SDO_CANT_MAPPED			0x06040041	// Object cannot be mapped to the PDO
#define	SDO_OBJECTSIZE			0x06040042	// Number+length of objects to be mapped exceed PDO
#define	SDO_PARA_INCOMP			0x06040043	// General parameter incompatibility reason
#define	SDO_DEV_INCOMP			0x06040047	// General internal incompatibility in the device
#define	SDO_HW_ERROR			0x06060000	// Access failed due to an hardware error
#define	SDO_LENGTH				0x06070010	// Length of service parameter does not match
#define	SDO_L_TO_HIGH			0x06070012	// Length of service parameter too high
#define	SDO_L_TO_LOW			0x06070013	// Length of service parameter too low
#define	SDO_SUB_WRONG			0x06090011	// Sub-index does not exist
#define	SDO_VALUE_WRONG			0x06090030	// Value range of parameter exceeded (write access)
#define	SDO_VALUE_HIGH			0x06090031	// Value of parameter written too high
#define	SDO_VALUE_LOW			0x06090032	// Value of parameter written too low
#define	SDO_MAX_MIN				0x06090036	// Maximum value is less than minimum value
#define	SDO_GENERAL				0x08000000	// general error
#define	SDO_CANT_STORE			0x08000020	// Data cannot be transferred/stored to application
#define	SDO_LOCAL_CONTROL		0x08000021	// Cannot be transf./stored because of local control
#define	SDO_DEVICESTATE			0x08000022	// Cannot be tr./st. because of present device state
#define	SDO_NO_DICT				0x08000023	// No object dictionary is present

//*******************************************************************************
// Object name
//*******************************************************************************
#define	D_DOMAIN				2			// Large variable amount of data e.g. program code
#define	D_DEFTYPE				5			// type definition
#define	D_DEFSTRUCT				6			// Defines a new record type
#define	D_VAR					7			// single value such as an UNSIGNED8, Boolean, float
#define	D_ARRAY					8			// Array of simple variables of the same type
#define	D_RECORD				9			// any combination of simple variables

//*******************************************************************************
// Data types
//*******************************************************************************
#define	D_BOOLEAN				0x01
#define	D_INTEGER8				0x02
#define	D_INTEGER16				0x03
#define	D_INTEGER32				0x04
#define	D_UNSIGNED8				0x05
#define	D_UNSIGNED16			0x06
#define	D_UNSIGNED32			0x07
#define	D_REAL32				0x08
#define	D_VIS_STRING			0x09
#define	D_OCTET_STRING			0x0A
#define	D_UNICODE_STRING		0x0B
#define	D_TIME_OF_DAY			0x0C
#define	D_TIME_DIFFERENCE		0x0D
#define	D__DOMAIN				0x0F
#define	D_INTEGER24				0x10
#define	D_REAL64				0x11
#define	D_INTEGER40				0x12
#define	D_INTEGER48				0x13
#define	D_INTEGER56				0x14
#define	D_INTEGER64				0x15
#define	D_UNSIGNED24			0x16
#define	D_UNSIGNED40			0x18
#define	D_UNSIGNED48			0x19
#define	D_UNSIGNED56			0x1A
#define	D_UNSIGNED64			0x1B
#define	D_PDO_COMM_PARA			0x20
#define	D_PDO_MAPPING			0x21
#define	D_SDO_PARA				0x22
#define	D_IDENTITY				0x23
#define	D_DATE					0x81

//*******************************************************************************
// access type
//*******************************************************************************
#define	D_READ					0x01		// read access
#define	D_WRITE					0x02		// write access
#define	D_RW					0x03		// read and write access

//*******************************************************************************
// NMT state
//*******************************************************************************
#define	BOOT_UP					0x00		// Boot up state
#define	STOPPED					0x04		// Stopped state
#define	OPERATIONAL				0x05		// Operational state
#define	PRE_OP					0x7F		// Pre-operational state

//*******************************************************************************
// NMT commands
//*******************************************************************************
#define	START_NODE				0x01		// Start node (enter operational state)
#define	STOP_NODE				0x02		// Stop node (enter stopped state)
#define	ENTER_PREOP				0x80		// Enter preoperational state
#define	RESET_NODE				0x81		// Reset node
#define	RESET_COMM				0x82		// Reset communication
#define	TEST_MODE				0xF0		// Test mode (not CANopen conform)
#define	SET_HWCODE				0xF1		// Set hardware code (not CANopen conform)
#define VERSION_NODE			0xF2		// Display node version

//*******************************************************************************
// LSS command specifier
//*******************************************************************************
#define	LSS_SWITCH_GLOBAL		0x04		/* global switch command							*/			
#define	SET_NODE_ID				0x11		// set node id
#define	DISP_NODE_ID			0x12		// display node id
#define	ABORT_NODE_ID			0x13		// abort id set
#define	SET_NODE_ID2				0x14		// set node id
#define	SET_BAUD				0x16		/* set baud rate									*/
#define LSS_STORE_CONFIG		0x17		/* store new configuration in nonvolatile memory	*/

/************************************************************************************************/
/* LSS mode																						*/
/************************************************************************************************/
#define	LSS_WAIT				0x00		/* LSS waiting state								*/
#define	LSS_CONFIG				0x01		/* LSS configuration state							*/

/************************************************************************************************/
/* Bit rate (set by LSS)																		*/
/************************************************************************************************/
#define	BAUDRATE_1000k			0x00		/* Baud rate 125 kBaud								*/
#define	BAUDRATE_800k			0x01		/* Baud rate 125 kBaud								*/
#define	BAUDRATE_500k			0x02		/* Baud rate 125 kBaud								*/
#define	BAUDRATE_250k			0x03		/* Baud rate 125 kBaud								*/
#define	BAUDRATE_125k			0x04		/* Baud rate 125 kBaud								*/
#define	BAUDRATE_50k			0x06		/* Baud rate 125 kBaud								*/
#define	BAUDRATE_20k			0x07		/* Baud rate 125 kBaud								*/
#define	BAUDRATE_10k			0x08		/* Baud rate 125 kBaud								*/
#define	BAUDRATE_AUTO			0x09		/* Baud rate 125 kBaud								*/

//*******************************************************************************
// LSS error code
//*******************************************************************************
#define	OUT_OF_RANGE			0x01		// value out of range

//*******************************************************************************
// Object dictionary
//*******************************************************************************
#define	DEVICE_TYPE				0x1000		// Device type and profile number
#define	ERROR_REGISTER			0x1001		// Error register
#define	ERROR_FIELD				0x1003		// Pre-defined error field (history)
#define	DEVICE_NAME				0x1008		// Device name
#define	HW_VERSION				0x1009		// Hardware version
#define	SW_VERSION				0x100A		// Software version
#define	STORE_PARAMETER			0x1010		/* Store parameter in non-volatile memory			*/
#define	CONS_HB_TIME			0x1016		// Consumer heartbeat time
#define	PROD_HB_TIME			0x1017		// Producer heartbeat time
#define	IDENTITY				0x1018		// Identity object
#define	OS_PROMPT				0x1026		// OS prompt object (LCD display)
#define	IC_CARD_PROMPT			0x1030		// OS prompt object (LCD display)
#define	VIRTUAL_DEVICE			0x6000		// Supported virtual device type
#define	LIFT_NUMBER				0x6001		// Lift number of the device
#define	VIRTUAL_TERMINAL		0x600A		/* Virtual terminal object							*/
#define	VIRTUAL_INPUT			0x6010		// Virtual input mapping object
#define	VIRTUAL_OUTPUT			0x6011		// Virtual output mapping object
#define	SET_POWER_SAVING		0x6031		/* Set power saving mode							*/
#define	POWER_SAVING_MODE		0x6032		/* Actual power saving mode							*/
#define	INPUT_GROUP				0x6100		// Input group 1 (0x6100) to group 32 (0x611F)
#define	INPUT_PARA1				0x6120		// Input parameter 1 for group 1(0x6120)-32(0x613F)
#define	INPUT_PARA2				0x6140		// Input parameter 2 for group 1(0x6140)-32(0x615F)
#define	INPUT_PARA3				0x6160		// Input parameter 3 for group 1(0x6160)-32(0x617F)
#define	INPUT_PARA4				0x6180		// Input parameter 4 for group 1(0x6180)-32(0x619F)
#define	RFID_NUMBER				0x61B4		/* RFID number										*/
#define	OUTPUT_GROUP			0x6200		// Output group 1 (0x6200) to group 32 (0x621F)
#define	OUTPUT_PARA1			0x6220		// Output parameter 1 for group 1(0x6220)-32(0x623F)
#define	OUTPUT_PARA2			0x6240		// Output parameter 2 for group 1(0x6240)-32(0x625F)
#define	OUTPUT_PARA3			0x6260		// Output parameter 3 for group 1(0x6260)-32(0x627F)
#define	OUTPUT_PARA4			0x6280		// Output parameter 4 for group 1(0x6280)-32(0x629F)
#define	DOOR_CONTROL			0x6300		// Door control word
#define	DOOR_STATUS				0x6301		// Door status word
#define	DOOR_POSITION			0x6302		/* Door position in mm (door closed = 0)			*/
#define	DOOR1_PARA				0x6304		// Door 1 configuration parameter
#define	DOOR2_PARA				0x6305		// Door 2 configuration parameter
#define	DOOR3_PARA				0x6306		// Door 3 configuration parameter
#define	LS_STATUS				0x6310		// Light screen status
#define	SETTING_POS				0x6380		/* Operation parameter positioning unit				*/
#define	PRESET_POS				0x6382		// Preset position (position of reset switch)
#define	POSITION				0x6383		// Lift position
#define	SPEED					0x6390		// Lift speed
#define	POS_LOW_LIMIT			0x63B4		/* Position unit high limit							*/
#define	POS_HIGH_LIMIT			0x63B8		/* Position unit high limit							*/
#define	DRV_CONTROL				0x6400		// Drive control word
#define	DRV_STATUS				0x6401		// Drive status word
#define	DRV_MODE				0x6403		/* Mode of operation (0x01-position, 0x02-velocity)	*/
#define	DRV_MODE_DISPLAY		0x6404		/* Mode of operation display						*/
#define	DRV_CONTROL_EFFORT		0x6406		// Control effort drive
#define	DRV_MOTOR_DIR			0x641E		/* Motor direction									*/
#define	POS_CONVERSATION		0x641F		/* Position conversation							*/
#define	TARGET_POS				0x6420		// Target position of drive
#define	POS_RANGE_LIMIT			0x6421		/* Position range limit								*/
#define	SW_POS_LIMIT			0x6422		/* Software position limit							*/
#define	PROFILE_VELOCITY		0x6423		/* Profile velocity									*/
#define	TARGET_VELOCITY			0x6430		// Target velocity of drive
#define	DRV_VELOCITY			0x6433		// Actual velocity value
#define	LOAD_VALUE				0x6480		// absolute load value
#define	LOAD_SIGNALLING			0x6482		// Load signalling
#define	LOAD_SIG_LIMIT			0x6483		// Load signalling limits (zero/half/full/overload)

#define	CAR_REFERENCE_WEIGHT	0x6486		/* Car reference weight (for zero calibration)		*/

#define	DRV_ACC_DEC				0x640B		/* Drive acceleration / deceleration				*/
#define	DRV_GEAR				0x6416		/* Drive gear										*/
#define	DRV_MOTOR_TYPE			0x6440		/* Drive Motor type (asynchron / synchron)			*/
#define	DRV_RATED_SPEED			0x6441		/* Drive Motor rated speed [rpm]					*/
#define	DRV_RATED_FREQ			0x6442		/* Drive Motor rated frequency [0,1Hz]				*/
#define	DRV_POLE_PAIRS			0x6443		/* Drive Motor pole pairs							*/
#define	DRV_RATED_CURRENT		0x6444		/* Drive Motor rated current [mA]					*/
#define	DRV_RATED_VOLTAGE		0x6445		/* Drive Motor rated voltage [V]					*/
#define	DRV_RATED_POWER			0x6446		/* Motor rated power [W]							*/
#define	DRV_CONN_MODE			0x6447		/* Drive Motor connection mode (Star / Delta)		*/
#define	DRV_COS_PHI				0x6448		/* Drive Motor cos phi [0,001]						*/
#define	DRV_MOMENT				0x6449		/* Drive Motor cos phi [0,001]						*/
#define	DRV_ENC_TYPE			0x6450		/* Drive Encoder type								*/
#define	DRV_ENC_RES				0x6451		/* Drive Encoder resolution [0,1]					*/
#define	DRV_ENC_ANGLE			0x6452		/* Encoder alignment angle							*/
#define	DRV_LIFT_SPEED			0x6460		/* Lift installation speed (nominal speed)			*/
#define	DRV_RPM_BY_SPEED		0x6461		/* Rated speed (rpm) by nominal speed				*/
#define	DRV_SHEAVE_DIA			0x6462		/* Sheave diameter [mm]								*/
#define	DRV_SUSPENSION			0x6463		/* Suspension										*/
#define	DRV_LIFT_LOAD			0x6465		/* Nominal lift load [kg]							*/
#define	DRV_BRAKETIMING			0x6466		/* CANopen drive brake timing parameter				*/

#define	DRV_BC_TYPE				0x306C		/* BR / BC type										*/
#define	DRV_AUTO_SPEED			0x308F		/* automatic speed preset							*/
#define	DRV_CO_CHECK			0x30A3		/* Contactor check									*/
#define	DRV_BR_CHECK			0x30A2		/* Brake check										*/
#define	DRV_TEMP_CHECK			0x309F		/* Motor temperature check							*/
#define	DRV_SB_MODE				0x30C1		/* SPD mode											*/
#define	DRV_SPD_KP				0x312C		/* base gain factor									*/
#define	DRV_SPD_TI				0x3130		/* base gain factor									*/
#define	DRV_K_START				0x3151		/* start gain										*/

//*******************************************************************************
// Object dictionary (manufacturer specific part)
//*******************************************************************************
#define	DOORNUMBER				0x2000		// number of car doors
#define	REVDOOR					0x2001		// door has revolving door; 1 entry per door
#define	DOOROPENTIME			0x2002		// door open time; 1 entry per door
#define	DOORCLOSETIME			0x2003		// door close time; 1 entry per door
#define	DOORERRORTIME			0x2004		// door error time; 1 entry per door
#define	DOORSWITCHTIME			0x2005		// switch time (open to close); 1 entry per door
#define	DOORDELAYTIME			0x2006		// door closing delay time; 1 entry per door
#define	DOORRELAYMODE			0x2007		// door relay mode (on or off); 1 entry per door
#define	DOORTIMER				0x2008		// count state of door timer;1 entry per door
#define	DOORRELAYTIME_CL		0x2009		// max. door close relay time; 1 entry per door
#define	MAX_LS_ON_TIME			0x200A		// max. time light screen interrupted to error
#define	DOORRELAYTIME_OP		0x200B		// max. door open relay time; 1 entry per door
#define	RAMPMODE				0x200C		// retiring ramp off mode; 1 entry per door
#define	RAMPTIMING				0x200D		// timing for retiring ramp; 1 entry per door
#define	RAMPDELAY				0x200E		// ramp on delay time; 1 entry per door
#define	DOOROPENDELAY			0x200F		// door delay after ramp off; 1 entry per door
#define	DOOROUTPUTSTATE			0x2010		// state of door outputs
#define	POS_INDICATION			0x2011		/* actual position in [m] for indication			*/
#define	EEML_OPERATIONSTATE		0x2081		/* for EEML: operation state						*/
#define	EEML_HARD_FAULT			0x2082		/* for EEML: Hard faults							*/
#define	EEML_SOFT_FAULT			0x2083		/* for EEML: Soft faults	 						*/
#define	EEML_WARNING			0x2084		/* for EEML: Warnings								*/
#define	EEML_EVACUATION			0x2085		/* for EEML: Evacuation								*/
#define	EEML_STATISTICS			0x2086		/* for EEML: Statistics								*/
#define	EEML_CABINET			0x2087		/* for EEML: Door state controller cabinet			*/
#define	EEML_LIFTNAME			0x2091		/* for EEML: Lift name for identification			*/
#define	EEML_MANUFACTURER		0x2092		/* for EEML: Lift manufacturer						*/
#define	EEML_PRODUCTION_YEAR	0x2093		/* for EEML: Production year						*/
#define	EEML_SETUP_DATE			0x2094		/* for EEML: Setup date								*/
#define	EEML_TRACTION_TYPE		0x2095		/* for EEML: Traction type							*/
#define	EEML_HEIGHT				0x2096		/* for EEML: Lift height							*/
#define	EEML_FLOORNUMBER		0x2097		/* for EEML: Floor number							*/
#define	EEML_PAYLOAD			0x2098		/* for EEML: Payload								*/
#define	EEML_REMOTE_CMD			0x20A0		/* for EEML: Remote command							*/
#define	EEML_REMOTE_STATE		0x20A1		/* for EEML: Remote state (ackknowledge to command)	*/
#define	EEML_REMOTE_FEEDBACK	0x20A2		/* for EEML: Remote feedback						*/
#define	STATE_SPECIAL_MODE		0x20B0		/* special mode										*/
#define	STATE_SPECIAL_KEY		0x20B1		/* state of special key								*/
#define	STATE_ADV_KEY			0x20B2		/* state of advanced key							*/
#define	STATE_EMERG_KEY			0x20B3		/* state of emergency key							*/
#define	STATE_TIMER1_TRIP		0x20B4		/* state of timer trip 1							*/
#define	STATE_TIMER2_TRIP		0x20B5		/* state of timer trip 2							*/
#define	STATE_FIRE_MODE			0x20B6		/* fire mode										*/

#define	HSE_STATE				0x2100		// HSE state
#define	FLOOR					0x2101		// actual floor number
#define	SC_STATE				0x2102		/* actual state of safety circuit					*/
#define	CC_TABLE				0x2103		/* Car call table									*/
#define	LCU_TABLE				0x2104		/* Landing call up table							*/
#define	LCD_TABLE				0x2105		/* Landing call down table							*/
#define	CALL_STATE				0x2106		/* Call state										*/
#define	DOORSTOP_STATE			0x2107		/* Door stop state									*/
#define	SPECIAL_KEY_STATE		0x2108		/* Special key state								*/
#define	ADV_KEY_STATE			0x2109		/* Advanced key state								*/
#define	EMERG_KEY_STATE			0x210A		/* Emergency key state								*/
#define	REMOTE_KEY_STATE		0x210B		/* Remote off key state								*/
#define	TIMER1_TRIP_STATE		0x210C		/* Timer 1 input state state						*/
#define	TIMER2_TRIP_STATE		0x210D		/* Timer 2 input state state						*/
#define	LAND_OFF_KEY_STATE		0x210E		/* Landing call off switch state					*/
#define	ACT_DOORTAB				0x210F		/* actual door table (door function)				*/
#define	SOL_DOORZONE			0x63E8		/* Door zone size Position supervision unit			*/
#define	SOL_FINAL_LIMIT			0x63E9		/* Final limit switch Position supervision unit		*/
#define	SOL_REF_LIMIT			0x63EA		/* Reference position SOLIMAX						*/
#define	SOL_FLOOR_NUMBER		0x63EC		/* Floor tab for SOLIMAX							*/
#define	SOL_FLOOR_TAB			0x63ED		/* Floor tab for SOLIMAX							*/
#define	SOL_FLOOR_TAB_CONTR		0x2148		/* Controller floor tab for SOLIMAX					*/
#define	SOL_DEFECT_CHB			0x2158		/* Defect log channel B								*/
#define	SOL_DEFECT_CHA			0x2159		/* Defect log channel A								*/
#define	GROUPMASTER				0x215A		/* this HSE is group master yes / no				*/
#define	TIMER3_TRIP_STATE		0x215B		/* Timer 3 input state state						*/
#define	TIMER4_TRIP_STATE		0x215C		/* Timer 4 input state state						*/
#define	TIMER5_TRIP_STATE		0x215D		/* Timer 5 input state state						*/
#define	SERIAL_NUMBER			0x215E		/* Serial number									*/
#define	BATTERY_VALUE			0x215F		/* last Battery value								*/

#define	MAXSLICK				0x2160		/* maximum slick									*/
#define	BRAKE_SPEED				0x2161		/* speed limit for UPS brake opening				*/
#define	EVAC_CLOSE_DOOR			0x2162		/* close door in evacuation floor					*/
#define	TIMER1_PARKINGTIME		0x2163		/* parking time for timer 1 trip; 0=no parking trip	*/
#define	TIMER2_PARKINGTIME		0x2164		/* parking time for timer 2 trip; 0=no parking trip	*/

#define	ENABLE_CC_STATE			0x2180		/* Table of car call enable inputs					*/
#define	DISABLE_CC_STATE		0x2181		/* Table of car call disable inputs					*/
#define	ENABLE_LC_STATE			0x2182		/* Table of hall call enable inputs					*/
#define	DISABLE_LC_STATE		0x2183		/* Table of hall call disable inputs				*/

#define	MUSIC_SEETING				0x2300		// Position difference when SGM is switching on
#define	DISPLAYVALUE			0x2320		// ASCII signs for display value
#define	ESE_LIFTNO_BRANCH1		0x2330		// lift number for display on ESE board	1 -	64
#define	ESE_LIFTNO_BRANCH2		0x2331		// lift number for display on ESE board	65 - 128
#define	ESE_LIFTNO_BRANCH3		0x2332		// lift number for display on ESE board 129 - 192
#define	ESE_LIFTNO_BRANCH4		0x2333		// lift number for display on ESE board 193 - 256
#define	ESE_LIFTNO_BRANCH5		0x2334		// lift number for display on ESE board 257 - 320
#define	ESE_LIFTNO_BRANCH6		0x2335		// lift number for display on ESE board 321 - 384
#define	ESE_LIFTNO_BRANCH7		0x2336		// lift number for display on ESE board 385 - 448
#define	ESE_LIFTNO_BRANCH8		0x2337		// lift number for display on ESE board 449 - 512
#define	DOORTABLE_NORMAL		0x2340		// enabled door in normal mode
#define	DOORTABLE_TIMER_1		0x2341		// enabled door in timer 1 mode
#define	DOORTABLE_TIMER_2		0x2342		// enabled door in timer 2 mode
#define	DOORTABLE_SPECIAL		0x2343		// enabled door in special mode
#define	DOORTABLE_ADV			0x2344		// enabled door in advanced mode
#define	DOORTABLE_EMERG			0x2345		// enabled door in emergency mode
#define	DOORTABLE_FIREMAN		0x2346		// enabled door in fireman mode
#define	DOORTABLE_ALARM			0x2347		// enabled door in fire alarm mode
#define	DOORTABLE_N_HALL		0x2348		// enabled door for hall calls in normal mode
#define	DOORTABLE_T1_HALL		0x2349		// enabled door for hall calls in timer 1 mode
#define	DOORTABLE_T2_HALL		0x234A		// enabled door for hall calls in timer 2 mode
#define	DOORTABLE_AUTOCALL		0x234B		// enabled door in autocall mode
#define	ERRORHIST				0x2360		// error history input 0
#define	ERRORHIST_50			0x2391		// error history input 49
#define	ERRORHIST_100			0x23C3		/* last index for error history						*/
#define	BOT_FLOOR				0x2400		// bottom floor
#define	TOP_FLOOR				0x2401		// top floor
#define	LIFTNAME				0x2402		// only for information
#define	GROUPSIZE				0x2403		// number of lifts in group (1 - 8)
#define	GROUPNUMBER				0x2404		// number of lift in group (0 - 7)
#define	LIFTTYPE				0x2405		// 0=rope, 1=hydraulic
#define	DOORPOS					0x2406		// position of shaft doors
#define	FLOORSIGN				0x2407		// sign for car position display
#define	PARKDOOR				0x2408		// shaft doors for parking with open doors
#define	SPEEDTABLE				0x2409		// relation between speed and control outputs
#define	SETUP_READY				0x240A		// setup (teach in) done: yes=1, no=0
#define	STARDELTATIME			0x240B		// star/delta switching time in ms
#define	WAIT_FOR_CONTACTOR		0x240C		// contactor input delay time in ms (open/close)
#define	WAIT_FOR_BRAKE			0x240D		// brake input delay time in ms (open/close)
#define	STOPPING_DELAY			0x240E		// delay time to release direction
#define	STOP_DELAY				0x240F		// delay time to release mains contactor
#define	TRIPTIME				0x2410		// trip time according to EN-81 in s
#define	PARKINGTIME				0x2411		// parking trip time in s; 0=no parking trip
#define	PARKFLOOR				0x2412		// floor for parking trip (0 - top floor)
#define	PARKDOORMODE			0x2413		// parking with open (=0) or closed doors (=1)
#define	LSTIME					0x2414		// light screen reclose time in s
#define	REVTIME					0x2415		// reopen by reverse contact reclose time in s
#define	NUDGINGTIME				0x2416		// closing time if ligth screen is on in 2s
#define	DOORSTAYTIME_CC			0x2417		// door open stay time if only car call
#define	DOORSTAYTIME_LC			0x2418		// door open stay time if also hall call
#define	DOORSTAYTIME_NC			0x2419		// door open stay time if no new call
#define	FVE_INPAR				0x241A		// free programmable inputs of FVE
#define	FVE_OUTPAR				0x241B		// free programmable outputs of FVE
#define	ASE_INPAR				0x241C		// free programmable inputs of ASE
#define	ASE_OUTPAR				0x241D		// free programmable outputs of ASE
#define	HSE_INPAR				0x241E		// free programmable inputs of HSE
#define	HSE_OUTPAR				0x241F		// free programmable outputs of HSE
#define	RESCUETIME				0x2420		// 
#define	LOAD_TYPE				0x2420		/* type of load measurement							*/
#define	ROLLTEXT				0x2421		/* roll text for display							*/
#define	SPEECHDELAY				0x2422		/* delay time for speech signal after floor signal	*/
#define	SPEECH_TARGETDIST		0x2423		/* target distance for speech signal				*/
#define	PARKZONE				0x2424		/* park zones										*/
#define	DOORZONEOFFSET			0x2425		// distance from switch SGM to doorzone (SW)
#define	LEVELZONE				0x2426		// size of level zone (above 0)
#define	DIFF_ONOFF				0x2427		// distance on/off state magnetic switch
#define	LEVELSWITCH				0x2428		// positions of level zone SGO+SGU on (absolute)
#define	LEVEL					0x2429		// floor positions (absolute)
#define	ZONESWITCH				0x242A		// positions of door zone magnets SGM (absolute)
#define	SLOW_DOWN_DIST			0x242B		// slow down distance speed V1-V3 up and down
#define	STOP_DIST				0x242C		// stop distance from V0 to 0 up and down
#define	RESET_SPEED				0x242D		// speed for reset trip
#define	ARRIVAL_SPEED			0x242E		// speed limit for advanced door opening
#define	ADV_DOOR_OP				0x242F		// advanced door opening: yes=1, no=0
#define	RELEVEL					0x2430		// re-levelling enabled: yes=1, no=0
#define	RELEVEL_TRIP			0x2431		// re-levelling if new call : yes=1, no=0
#define	INSP_STOP_DIST			0x2432		// stop distance from Inspection to 0 up/down
#define	INSP_SLOW_DIST			0x2433		// slow down distance for inspection up/down
#define	REL_STOP_DIST			0x2434		// stop distance from re-levelling to 0 up/down
#define	POSTYPE					0x2435		// Type of Positioning system
#define	TARGETLIMIT				0x2436		// min. distance to start with v1/v2/v3
#define	LCMODE_ACTFLOOR			0x2437		// mode if landing call pressed 韓 actual floor
#define	CARLIGHTTIMER			0x2438		// automatic switch off car light (0=disabled)
#define	POSDIR					0x2439		// count direction encoder connected to HSE
#define	DOORZONESWITCHSIZE		0x243A		// distance SGM on
#define	CORRPOS_TOP				0x243B		// last floor before slow down limit switch
#define	COORPOS_BOTTOM			0x243C		// last floor before slow down limit switch
#define	POS_CAL					0x243D		// number of encoder increments per mm
#define	ERRORTIME				0x243E		// error delay (clear calls...)
#define	DRIVETYPE				0x243F		// 0=no CAN, 1=CAN lust, 2=ASE, 3=CANopen drive
#define	FORCED_STOP				0x2440		// forced stop: yes / no
#define	FORCED_STOP_FLOOR		0x2441		// floor for forced stop
#define	FORCED_STOP_DIR			0x2442		// direction for forced stop
#define	FORCED_STOP_DOOR		0x2443		// door for foced stop
#define	CONTROLTYPE				0x2444		// call collecting / single call lift
#define	REMOTE_OFF_FLOOR		0x2445		// floor for remote switch off
#define	REMOTE_OFF_DOOR			0x2446		// doors for remote switch off
#define	REMOTE_OFF_LIGHT		0x2447		// car light state when remote switch off
#define	FAN_MODE				0x2448		// cabin fan mode: 0=push, 1=automatic
#define	FAN_TIME				0x2449		// cabin fan: time delay
#define	DOUBLE_CANCEL			0x244A		// cancel call by double pressing
#define	DIR_PENDING				0x244B		// cancel hall calls direction pending
#define	REMOTE_CLEAR_CALLS		0x244C		// clear calls when remote switch off
#define	CC_NO_LS				0x244D		// max.number of car calls without light screen
#define	CLEAR_OTHER_LC_IF_CC	0x244E		// clear landing call in other dir. if car call
#define	MOTOR_RUN_ON			0x244F		// delay time between valve and motor off
#define	MAIN_FLOOR				0x2450		// main floor
#define	SIMULATION				0x2451		// simulation mode on / off
#define	START_DELAY				0x2452		// delay time for speed and direction
#define	BRAKE_ON_DELAY			0x2453		// delay time to open the brake
#define	BRAKE_OFF_DELAY			0x2454		// delay time to release the brake
#define	DRIVE_ERROR_DELAY		0x2455		// delay time to drive error
#define	MAX_START				0x2456		// max. waiting time to drive speed > 0
#define	MAX_READY_ON			0x2457		// max. waiting time for ready signal
#define	MAX_BRAKE_ON			0x2458		// max. waiting time for brake signal
#define	MAX_STOP				0x2459		// max. waiting time to drive speed = 0
#define	MAX_BRAKE_OFF			0x245A		// max. waiting time for brake signal off
#define	MAX_READY_OFF			0x245B		// max. waiting time for ready signal off
#define	STARTTIME				0x245C		// start delay (debouncing safety circuit door)
#define	IV_READY				0x245D		// inverter setup-ready
#define	SLICK_CAL				0x245D		/* number of pulses per mm for slick sensor			*/
#define	LAST_TRIP_SPECIAL		0x245E		// finish last trip when special call
#define	LAST_TRIP_ADVANCED		0x245F		// finish last trip when advanced call
#define	LAST_TRIP_EMERGENCY		0x2460		// finish last trip when emergency call
#define	TIME_SPECIAL			0x2461		// time lift stays in special mode
#define	TIME_ADVANCED			0x2462		// time lift stays in advanced mode
#define	TIME_EMERGENCY			0x2463		// time lift stays in emergency mode
#define	HALLCALL_SPECIAL		0x2464		// disable hall calls in special mode
#define	HALLCALL_ADVANCED		0x2465		// disable hall calls in advanced mode
#define	HALLCALL_EMERGENCY		0x2466		// disable hall calls in emergency mode
#define	CARCALL_SPECIAL			0x2467		// clear car calls in special mode
#define	CARCALL_ADVANCED		0x2468		// clear car calls in advanced mode
#define	CARCALL_EMERGENCY		0x2469		// clear car calls in emergency mode
#define	NUMBER_CARCALL_SPECIAL	0x246A		// max. number of car calls in special mode
#define	NUMBER_CARCALL_ADV		0x246B		// max. number of car calls in advanced mode
#define	NUMBER_CARCALL_EMERG	0x246C		// max. number of car calls in emergency mode
#define	MAX_CC					0x246D		// max.number of car calls at the same time
#define	FORCED_CLOSE_EMERG		0x246E		// forced door closing in emergency mode
#define	FIRE_DOORCLOSEMODE		0x246F		// door closing mode in fireman mode
#define	FIRE_DOOROPENMODE		0x2470		// door open mode in fireman mode
#define	REPEAT_FIRECALL			0x2471		// repeat fire call if fire key is off
#define	DOOR_FIREFLOOR			0x2472		// door mode in fireman floor
#define	TIMER_CLEARCALL			0x2473		// clear calls if timer trip
#define	TIMERTRIP_START			0x2474		// time to start timer trip
#define	TIMERTRIP_STOP			0x2475		// time to stop timer trip
#define	TIMER1_PARKFLOOR		0x2476		// parking floor for timer 1 trip
#define	TIMER2_PARKFLOOR		0x2477		// parking floor for timer 2 trip
#define	AUTOCALL_CC				0x2478		// auto call when enabling car calls
#define	DISABLE_SPECIAL			0x2479		// disabling also for special calls
#define	ENABLE_SPECIAL			0x247A		// enabling also for special calls
#define	AUTOCALL_LC				0x247B		// auto call when enabling landing calls
#define	CALLTIME_SPECIAL		0x247C		// time calls enabled in special mode
#define	CALLTIME_ADVANCED		0x247D		// time calls enabled in advanced mode
#define	CALLTIME_EMERGENCY		0x247E		// time calls enabled in emergency mode
#define	TIME_BACK_SPECIAL		0x247F		// delay time back to normal from special mode
#define	TIME_BACK_ADVANCED		0x2480		// delay time back to normal from advanced mode
#define	TIME_BACK_EMERGENCY		0x2481		// delay time back to normal from emergency mode
#define	CALL_ACTIVE_SPECIAL		0x2482		// calls enabled only if special key is on
#define	CALL_ACTIVE_ADVANCED	0x2483		// calls enabled only if advanced key is on
#define	CALL_ACTIVE_EMERGENCY	0x2484		// calls enabled only if emergency key is on
#define	AUTO_FIREMODE			0x2485		// automatic fireman mode if fire call is ready
#define	NORMAL_CC_SPECIAL		0x2486		// normal car calls enabled in special mode
#define	NORMAL_CC_ADVANCED		0x2487		// normal car calls enabled in advanced mode
#define	NORMAL_CC_EMERGENCY		0x2488		// normal car calls enabled in emergency mode
#define	FIRE_LS_ACTIVE			0x2489		// light screen active in case of fire
#define	FIRE_DOORPARKMODE		0x248A		// door park mode in case of fire
#define	FIRE_CARLIGHT_OFF		0x248B		// carlight off in case of fire
#define	FIREFLOOR_DYNAMIC		0x248C		// dynamic fire floor
#define	FIREINPUT_ACTIVE		0x248D		// fire input must be active for fire mode
#define	FIRE_BACK_TO_NORMAL		0x248E		// automatic back to normal mode
#define	CROSS_FIREFLOOR			0x248F		// cross already burning floor
#define	FIRE_FLOOR				0x2490		// order for floors in case of fire
#define	MAX_DOOR_CLOSE_GROUP	0x2491		// max. waiting time for door in group
#define	SAFETY_BEAM_CONNECTED	0x2492		// lift has safety beam
#define	NOMINAL_SPEED			0x2493		// nominal speed
#define	RELEVEL_SPEED			0x2494		// relevel speed
#define	DOORSTAYTIME_CC_MAIN	0x2495		// door open stay time if only car call, main floor
#define	DOORSTAYTIME_LC_MAIN	0x2496		// door open stay time if also hall call, main floor
#define	DOORSTAYTIME_NC_MAIN	0x2497		// door open stay time if no new call, main floor
#define	DOORSTOPTIME			0x2498		// door open stay time if no new call, main floor
#define	SPEEDTIMING				0x2499		// time to set speed signals
#define	DOOROPENLIMIT			0x249A		// door open limit in case of door open error
#define	DOORCLOSELIMIT			0x249B		// door close limit in case of door close error
#define	MAX_LS_ON				0x249C		// max. time light screen interrupted to error
#define	CARCALL_SPECIAL_LC		0x249D		// clear car calls by special landing call
#define	CARCALL_ADVANCED_LC		0x249E		// clear car calls by advanced landing call
#define	CARCALL_EMERGENCY_LC	0x249F		// clear car calls by emergency landing call
#define	EVACUATIONDELAY			0x24A0		// min. waiting time in evacuation mode
#define	EVACUATIONTIME			0x24A1		// max. waiting time for evacuation enable
#define	EVAC_AUTORETURN			0x24A2		// automatic return from evacuation
#define	FORCED_CLOSE_FIRE		0x24A3		// light screen active in case of fire
#define	FIREDETECT_ACTIVE		0x24A4
#define	ENABLE_PRIORITY			0x24A5
#define	ATTEND_CARCALL			0x24A6
#define	AUTOCALL_DIR			0x24A7
#define	CC_CANCEL				0x24A8
#define	MAX_CC_EMPTY			0x24A9
#define	CLEAR_CC_LAST_FLOOR		0x24AA
#define	CLEAR_CC_OPP_DIR		0x24AB
#define	UP_PEAK_START			0x24AC
#define	UP_PEAK_STOP			0x24AD
#define	DN_PEAK_START			0x24AE
#define	DN_PEAK_STOP			0x24AF
#define	UP_PEAK_PARKFLOOR		0x24B0
#define	DN_PEAK_PARKFLOOR		0x24B1
#define	SPEED_TABLE				0x24B2
#define	PARASET					0x24B3
#define	TESTTRIP				0x24B4
#define	LANDINGS_OFF			0x24B5
#define	DOOROFF					0x24B6
#define	CORRPOS					0x24B7		// last floor before reset switch
#define	POS_DOOROPEN			0x24B8		// position for advanced door opening
#define	ZEROLOADVALUE			0x24B9		/* analog value for zero load for calibration		*/
#define	FULLLOADVALUE			0x24BA		/* analog value for full load for calibration		*/
#define	TEST_STARTTIME			0x24BB
#define	TEST_ENDTIME			0x24BC
#define	TEST_WEEKDAY			0x24BD
#define	TEST_TIMES				0x24BE
#define	TEST_INTERVAL			0x24BF

#define	FLOORCOUNT				0x24C0		// floor count (number of trips)
#define	PCUNUMBERS				0x24C4
#define	LCUNUMBERS				0x24C5
#define	TEST_CYCLE_MODE			0x24C6
#define	EXENUMBERS				0x24C7
#define	DRIVE_MODE				0x24C8
#define	LOADTYPE				0x24C9
#define	ARROW_MODE				0x24CA
#define	IOU_EXT_NUMS			0x24CB

#define	FORCE_SWITCH_SPD1		0x24CC
#define	FORCE_SWITCH_SPD2		0x24CD
#define	FORCE_SWITCH_SPD3		0x24CE
#define	FORCE_SWITCH_SDU1		0x24CF
#define	FORCE_SWITCH_SDU2		0x24D0
#define	FORCE_SWITCH_SDU3		0x24D1
#define	FORCE_SWITCH_SDD1		0x24D2
#define	FORCE_SWITCH_SDD2		0x24D3
#define	FORCE_SWITCH_SDD3		0x24D4
#define	EVAC_DIR_CORRECT		0x24D5
#define	CHK_DOORLOCK_SHORT		0x24D6
#define	AD_EMPTY_LOAD			0x24D7
#define	AD_HALF_LOAD			0x24D8
#define	AD_FULL_LOAD			0x24D9
#define	AD_OVER_LOAD			0x24DA
#define	LIGHT_BTN_WHILE_PUSH	0x24DB
#define	LOAD_AD_VALUE			0x24DC
#define	SETDATE_DAY				0x24DD
#define	SETDATE_MONTH			0x24DE
#define	SETDATE_YEAR			0x24DF
#define	SETDATE_WEEK			0x24E0
#define	SETTIME_SECOND			0x24E1
#define	SETTIME_MINUTE			0x24E2
#define	SETTIME_HOUR			0x24E3
#define	START_TIME				0x24E4
#define	DOORZONEIN				0x24E5
#define	ENCODER_POS			0x24E6
#define	TEST_SRU				0x24E7
#define	OLD_CDU_VERSION			0x24EB
#define	ANTI_FAINT			0x24EC
#define	HALL_LATERN_MODE		0x24ED
#define	DIRECTION_IND_MODE	0x24EE			
#define	LANGUAGE				0x24EF
#define	SAVE_MCU_PARA			0x24F0
#define	SAVE_IV_PARA			0x24F1
#define	LOAD_MCU_PARA			0x24F2
#define	LOAD_IV_PARA			0x24F3
#define	READY_OFF_DELAY		0x24F4
#define	READY_ON_DELAY		0x24F5
#define	TORQUE_ENABLE		0x24F6
#define	TORQUE_OFFSET		0x24F7
#define	GAIN_DRIVE				0x24F8
#define	GAIN_BRAKE				0x24F9
#define	FX_ACTIVE				0x24FA
#define	FX_ONTIME			0x24FB
#define	FX_OFFTIME			0x24FC
#define	RUN_OFF_DELAY		0x24FD
#define	BRAKE_FEEDBACK_DLY	0x24FE
#define	BRAKE_RELEASE_DLY	0x24FF
#define	POWER_ON_RESET_TRIP	0x2500
#define	DETECT_FLOOR_ERROR	0x2501
#define	FLOOR_ERROR_DEC_LEN	0x2502
#define	RSTTRIP_STOP_DLY	0x2503
#define	BYPASS_LC_IN_DZ		0x2504
#define	DIS_CLOSE_WHILE_OPEN		0x2505
#define	CMD_RESET_MCU		0x2506
#define	EVAC_DOOR				0x2505
#define	EVAC_CARLIGHT_MODE		0x2506
#define	LANDING_PUSH_MODE		0x2507
#define	UPS_DIRECTION_MODE		0x2508
#define	CANBUS_CHECK_MODE		0x2509
#define	TORQUE_DIR						0x250A
#define	SAFETY_BEAM_MODE			0x250B
#define	ENABLE_P6PARA				0x250C
#define	BACKLIGHT_MODE				0x250D
#define	UCMP_CHECK_MODE			0x250E
#define	INSPECTION_LOCK			0x250F
#define	EMPPOWER_DOOR			0x2510
#define	CTE_MODE					0x2511
#define	CHECK_MR_TEMP			0x2512
#define	ATT_HALL_ALARM			0x2513
#define	EVAC_CARLIGHT_TIME	0x2514
#define	SHE_MODE					0x2515
#define	CHECK_BUTTOM			0x2516
#define	FORCE_STARTHOUR		0x2517
#define	FORCE_STOPHOUR			0x2518
#define	KEY_BUTTOM_TIME		0x2519
#define	DOOR_CONNECT_MODE		0x251A
#define	FIRE_FAN_MODE		0x251B
#define	ACCESS_DIST_UP		0x251C
#define	ACCESS_DIST_DOWN		0x251D

#define	PASSWORD_ADMIN		0x2520
#define	PASSWORD_HELP		0x2521
#define	PASSWORD_INSTALL		0x2522
#define	PASSWORD_MAINTAIN		0x2523
#define	COOPERATE_FUNC1	0x2524
#define	FIRE_DOOR_REV		0x2525
#define	LIFT_FUNCTION_SEL1	0x2526
#define	MAX_SPEED	0x2527

#define	BATTERYCHECK			0x25C1		/* time between 2 battery checks					*/
#define	BATTERYLEVEL			0x25C2		/* battery level									*/
#define	TOP_LIMIT				0x25C3		/* position of top limit switch above top level		*/
#define	BOT_LIMIT				0x25C4		/* position of bottom limit switch below top level	*/
#define	DOORCLOSETYPE			0x25C5		/* function of door close switch					*/
#define	DOOROPENTYPE			0x25C6		/* function of door open switch						*/
#define	STOP_TIME				0x25C7		/* waiting time after drive is stopped				*/
#define	DEADMAN_CTRL			0x25C8		/* Deadman control type								*/
#define	CARLIFT					0x25C9		/* Car lift											*/
#define	LC_NO_DOOR				0x25CA		/* Accept landing calls without doors				*/
#define	LEVELZONE_DN   			0x25CB		/* size of level zone below level					*/
#define	DISP_OVERLOAD  			0x25CC		/* display overload on level display				*/
#define	DISP_NONSMOKE_CB		0x25CD		/* display non smoke on car display					*/
#define	DISP_NONSMOKE_SB		0x25CE		/* display non smoke on shaft display				*/
#define	RELEV_DELAY				0x25CF		/* re-levelling delay								*/
#define	ATTEND_REOPEN			0x25D0		/* reopen door in car attendance mode				*/
#define	ATTEND_LS				0x25D1		/* ignore light screen in car attendance mode		*/
#define	ATTENDANCE_TIME			0x25D2		/* automatic switch off car attendance mode			*/
#define	AUTO_FIREBACK			0x25D3		/* automatic back from fireman mode					*/
#define	BEARER_MODE_TOP			0x25D4		/* mode for safety bearer in top of shaft			*/
#define	BEARER_MODE_BOT			0x25D5		/* mode for safety bearer in bottom of shaft		*/
#define	BEARER_TIME_TOP			0x25D6		/* waiting time for safety bearer in top of shaft	*/
#define	BEARER_TIME_BOT			0x25D7		/* waiting time for safety bearer in bottom of shaft*/
#define	BEARER_INSP_TOP			0x25D8		/* stop position inspection in bearer mode in top	*/
#define	BEARER_INSP_BOT			0x25D9		/* stop position inspection in bearer mode in bottom*/
#define	DISP_INSPECTION			0x25DA		/* display inspection on level display				*/
#define	DISP_OUT_OF_ORDER		0x25DB		/* display out of order on level display			*/
#define	DISP_FAULT				0x25DC		/* display fault on level display					*/
#define	APRON_TYPE				0x25DD		/* type of car apron								*/
#define	SC4_DOOROPEN			0x25DE		/* open door if SC4 off (for autom. shaft doors)	*/
#define	CCTIME_VISITORCALL		0x25DF		/* time call is enabled for target call control		*/
#define	LCTIME_VISITORCALL		0x25E0		/* time call is enabled for target call control		*/
#define	MOTORFANTIME			0x25E1		/* motor fan delay time								*/
#define	APRON_CHECK_UP			0x25E2		/* check position if mechanical apron off			*/
#define	APRON_CHECK_DN			0x25E3		/* check position if mechanical apron on			*/
#define	APRON_SLOW_UP			0x25E4		/* slowdown position if mechanical car apron		*/
#define	APRON_SLOW_DN			0x25E5		/* slowdown position if mechanical car apron		*/
#define	DISPLAY_TARGETDIST		0x25E6		/* position where to change display					*/
#define	GONG_TARGETDIST			0x25E7		/* position where to switch gong					*/
#define	GONGTYPE				0x25E8		/* type of gong										*/
#define	GONGTIME				0x25E9		/* switch on time of gong							*/
#define	FORCED_CLOSING			0x25EA		/* forced closing enabled							*/
#define	GONG_NODOOR				0x25EB		/* Gong if landing call without door				*/
#define	POSUNIT_DIST			0x25EC		/* distance between AWG1 and AWG2					*/
#define	CALLCONFIGMODE			0x25ED		/* mode with 5 different call configurations		*/
#define	CFG_1_LC				0x25EE		/* landing call configuration 1				 		*/
#define	CFG_2_LC				0x25EF		/* landing call configuration 2				 		*/
#define	CFG_3_LC				0x25F0		/* landing call configuration 3				 		*/
#define	CFG_4_LC				0x25F1		/* landing call configuration 4				 		*/
#define	CFG_5_LC				0x25F2		/* landing call configuration 5				 		*/
#define	INC_ACCU				0x25F3		/* encoder buffered by battery			 			*/
#define	CALLCLEARPOS			0x25F4		/* position where the calls are cleared				*/
#define	SPEECHTIME				0x25F5		/* pulse wide of speech signal						*/
#define	MIN_DOORZONE			0x25F6		/* min. floor distance for separate door zones		*/
#define	VVVF_OFFTIMER			0x25F7		/* time delay to switch off VVVF					*/
#define	VVVF_ONDELAY			0x25F8		/* time delay after VVVF is switched on				*/
#define	HAZARD_CARCALL			0x25F9		/* hazardous transport with car calls				*/
#define	HAZARD_FAN				0x25FA		/* hazardous transport with car fan on				*/
#define	HAZARD_FIREMODE			0x25FB		/* hazardous transport priority higher than firemode*/
#define	HAZARD_KEYTYPE			0x25FC		/* hazard.transport type of car input (push/switch)	*/
#define	HAZARD_CALLDOOR			0x25FD		/* automatic door opening by hazardous call			*/
#define	HAZARD_TIME_BACK		0x25FE		/* delay time to go back to normal mode				*/
#define	LANDINGCALLTIME			0x25FF		/* delay time between 2 landing calls (misuse)		*/
#define	MAINT_INTERVAL			0x2600		/* Maintenance interval (number of trips)			*/
#define	MAINT_TYPE				0x2601		/* Action if maintenance interval is over			*/
#define	DOORTABLE_HAZARD		0x2602		/* enabled door in hazard mode						*/
#define	SAFETY_BEAM_RESET_LC	0x2603		/* safety beam reset also by landing call			*/
#define	MAX_POS_DIFF			0x2604		/* max. difference when SGM switches on / off		*/
#define	MAX_DOOR_REV_GROUP		0x2605		/* max. door reopen until lift goes out of group	*/	
#define	MAX_DOOR_BLOCK_GROUP	0x2606		/* max. door blocking until lift goes out of group	*/	
#define	HOLDING_BOLTS			0x2607		/* lift with holding bolts							*/
#define	HOLDING_FLOOR			0x2608		/* floors with holding bolts						*/
#define	HOLDING_STOP			0x2609		/* stop position to set/reset holding bolts			*/
#define	HOLDING_MIN				0x260A		/* min. stop position to set/reset holding bolts	*/
#define	HOLDING_MAX				0x260B		/* min. stop position to set/reset holding bolts	*/
#define	HOLD_PUMP_DELAY			0x260C		/* delay time to start pressure pump				*/
#define	HOLDINGRELAYMODE		0x260D		/* state of holding bolts relay outputs				*/
#define	HOLDING_MAX_TIME		0x260E		/* max. wait time for holding bolts					*/
#define	HOLD_PUMP_OFF			0x260F		/* max. re-pump position							*/
#define	HOLD_STOP_DIST			0x2610		/* stop distance in holding mode (vH)				*/
#define	HOLDING_IN_ERROR		0x2611		/* bolts in error count								*/
#define	HOLDING_OUT_ERROR		0x2612		/* bolts out error count							*/
#define	HOLDING_FIRE			0x2613		/* bolt mode in case of fire						*/
#define	HOLDING_SWITCHTIME		0x2614		/* time delay to change between in and out			*/
#define	HOLDING_ZONE			0x2615		/* size of holding zone								*/
#define	HOLDING_AGAIN			0x2616		/* repeated holding down trip						*/
#define	SMS_1_ACTIVE			0x2617		/* SMS 1 transfer active							*/
#define	SMS_1_PROVIDER			0x2618		/* SMS 1 provider number							*/
#define	SMS_1_NUMBER			0x2619		/* SMS 1 number										*/
#define	SMS_1_TEXT				0x261A		/* SMS 1 additional text							*/
#define	SMS_2_ACTIVE			0x261B		/* SMS 2 transfer active							*/
#define	SMS_2_PROVIDER			0x261C		/* SMS 2 provider number							*/
#define	SMS_2_NUMBER			0x261D		/* SMS 2 number										*/
#define	SMS_2_TEXT				0x261E		/* SMS 2 additional text							*/
#define	SMS_3_ACTIVE			0x261F		/* SMS 3 transfer active							*/
#define	SMS_3_PROVIDER			0x2620		/* SMS 3 provider number							*/
#define	SMS_3_NUMBER			0x2621		/* SMS 3 number										*/
#define	SMS_3_TEXT				0x2622		/* SMS 3 additional text							*/
#define	FAX_1_ACTIVE			0x2623		/* FAX 1 transfer active							*/
#define	FAX_1_NUMBER			0x2624		/* FAX 1 number										*/
#define	FAX_1_TEXT				0x2625		/* FAX 1 additional text							*/
#define	FAX_2_ACTIVE			0x2626		/* FAX 2 transfer active							*/
#define	FAX_2_NUMBER			0x2627		/* FAX 2 number										*/
#define	FAX_2_TEXT				0x2628		/* FAX 2 additional text							*/
#define	PC_1_ACTIVE				0x2629		/* PC 1 transfer active								*/
#define	PC_1_NUMBER				0x262A		/* PC 1 number										*/
#define	PC_1_TEXT				0x262B		/* PC 1 additional text								*/
#define	PC_2_ACTIVE				0x262C		/* PC 2 transfer active								*/
#define	PC_2_NUMBER				0x262D		/* PC 2 number										*/
#define	PC_2_TEXT				0x262E		/* PC 2 additional text								*/
#define	MODEM_DIALTIME			0x262F		/* Waiting time between 2 dial attemps				*/
#define	MAINT_WARNING			0x2630		/* Warning by number of trip before maint.action	*/
#define	EVAC_SLOWDOWN			0x2631		/* Slowdown pos. for UPS evacuation					*/
#define	HAZARD_DOORINPUT		0x2632		/* Separate door open/close input for hazard mode	*/
#define	TRAFFIC_LIGHT_DOOR		0x2633		/* Color of traffic light if door is closed			*/
#define	TRAFFIC_LIGHT_OFF		0x2634		/* time delay to switch off all traffic lights		*/
#define	MODEM_DIALNUMBER		0x2635		/* Number of dial attemps							*/
#define	MODEM_INIT				0x2636		/* Additional modem init string						*/
#define	GOVERNOR_MODE			0x2637		/* mode for governor output							*/
#define	GOVERNOR_TIME			0x2638		/* supervision time for governor input				*/
#define	SPECIAL_CALL_NO_DOOR	0x2639		/* special calls without doors enabled				*/
#define	ADVANCED_CALL_NO_DOOR	0x263A		/* advanced calls without doors enabled				*/
#define	EMERGENCY_CALL_NO_DOOR	0x263B		/* emergency calls without doors enabled			*/
#define	EVAC_SPEED				0x263C		/* max. evacuation speed							*/
#define	SAFETY_BEAM_SC			0x263D		/* safety beam error if safety circuit is off		*/
#define	MODEM_TYPE				0x263E		/* type of i-modul									*/
#define	SAFETY_BEAM_CLEAR_CC	0x263F		/* clear car calls if safety beam error				*/
#define	BEARER_DEBOUNCE_TIME	0x2640		/* debounce time for bearer input					*/
#define	HOLDING_DEBOUNCE_TIME	0x2641		/* debounce time for holding input					*/
#define	HOLDING_STARTDELAY		0x2642		/* start delay time after holding in / out			*/
#define	START_WT_DOOR			0x2643		/* waittime for door if starting a trip				*/
#define	OP_LIFT					0x2644		/* OP lift											*/
#define	GONG_LC_DIR				0x2645		/* Gong if LC direction changed						*/
#define	DOOR_SWITCH				0x2646		/* Existing door switches							*/
#define	MAX_RAMP				0x2647		/* Max. ramp on time								*/
#define	EMERG_TRIP_BY_FIRE		0x2648		/* Emergency trip in case of fire					*/
#define	EMERG_RUN_TO_FIRE		0x2649		/* Emergency trip to fire floors					*/
#define	MODEM_ANSWER			0x264A		/* number of rings until taking call				*/
#define	SEGMENTSIZE				0x264B		/* max. length of TCP/IP telegram					*/
#define	CFG_1_CC				0x264C		/* car call configuration 1					 		*/
#define	CFG_2_CC				0x264D		/* car call configuration 2					 		*/
#define	CFG_3_CC				0x264E		/* car call configuration 3					 		*/
#define	CFG_4_CC				0x264F		/* car call configuration 4					 		*/
#define	CFG_5_CC				0x2650		/* car call configuration 5				 			*/
#define	SPEED_VALUE				0x2651		/* speed values (CAN open drive)					*/
#define	RAMP_SIZE				0x2652		/* ramp size										*/
#define	PARKDOOR_SPECIAL		0x2653		/* park doors in special run state					*/
#define	PARKDOOR_ADVANCED		0x2654		/* park doors in advanced run state					*/
#define	PARKDOOR_EMERGENCY		0x2655		/* park doors in emergency run state				*/
#define	DOORS_LOCKED_SPECIAL	0x2656		/* doors locked  in special run state				*/
#define	DOORS_LOCKED_ADVANCED	0x2657		/* doors locked in advanced run state				*/
#define	DOORS_LOCKED_EMERGENCY	0x2658		/* doors locked in emergency run state				*/
#define	DOORS_LOCKED			0x2659		/* doors locked in normal run state					*/
#define	AUTO_SUMMERTIME			0x265A		/* automatic summer time							*/
#define	DIVING_TYPE				0x265B		/* type of diving (next floor/end floor)			*/
#define	BUZZERTYPE				0x265C		/* type of buzzer (overload, door, call)			*/
#define	ADD_RAMPONDELAY			0x265D		/* on delay of additional ramp						*/
#define	ADD_RAMPOFFDELAY		0x265E		/* off delay of additional ramp						*/
#define	DOOR_RELAY				0x265F		/* Existing door relays								*/
#define	CARLIFT_AUTOCALL		0x2660		/* Automatic call for Car lift with 2 floors		*/
#define	SLOWSTARTDELAY			0x2661		/* start delay for slow start contactor				*/
#define	SC_RELEV				0x2662		/* waiting time for SC4 while re-levelling			*/
#define	CC_NO_DOOR				0x2663		/* Accept car calls without doors					*/
#define	DOORTYPE				0x2664		/* Door type (CAN-Open / Standard)					*/
#define	V_LIMIT					0x2665		/* speed limit for output							*/
#define DECEL_POS				0x2666		/* position before final floor to slow down			*/
#define SLOW_SPEED				0x2667		/* slow down to this speed on final floor			*/
#define	MODEM_TIMEOUT			0x2668		/* Modem timeout if no data received				*/
#define	OIL_TIME				0x2669		/* Oil warming trip timer							*/
#define	OIL_STARTMONTH			0x266A		/* Oil warming trip start month						*/
#define	OIL_STARTDAY			0x266B		/* Oil warming trip start day						*/
#define	OIL_STOPPMONTH			0x266C		/* Oil warming trip stop month						*/
#define	OIL_STOPPDAY			0x266D		/* Oil warming trip stop day						*/
#define	OIL_SLOWPOS				0x266E		/* Extended slow down way if oil is cold			*/
#define	OIL_FLOOR				0x266F		/* Floor for oil warming trip						*/
#define	ESE_MANDAT_BRANCH1		0x2670		/* mandatory ESE board   1 -  64					*/
#define	ESE_MANDAT_BRANCH2		0x2671		/* mandatory ESE board  65 - 128					*/
#define	ESE_MANDAT_BRANCH3		0x2672		/* mandatory ESE board 129 - 192					*/
#define	ESE_MANDAT_BRANCH4		0x2673		/* mandatory ESE board 193 - 256					*/
#define	ESE_MANDAT_BRANCH5		0x2674		/* mandatory ESE board 257 - 320					*/
#define	ESE_MANDAT_BRANCH6		0x2675		/* mandatory ESE board 321 - 384					*/
#define	ESE_MANDAT_BRANCH7		0x2676		/* mandatory ESE board 385 - 448					*/
#define	ESE_MANDAT_BRANCH8		0x2677		/* mandatory ESE board 449 - 512					*/
#define	TSE_MANDATORY			0x2678		/* mandatory TSE 									*/
#define	SLOW_DOWN_VZ			0x2679		/* slow down distance add. speeds VZ1+VZ2			*/
#define	TARGETLIM_VZ			0x267A		/* min. distance to start with vZ1/vZ2				*/
#define	EVAC_TRIPTIME			0x267B		/* trip time acc. to EN-81 in s while evacuation	*/
#define	PARKMODE				0x267C		/* park mode										*/
#define	VISITORDOOR				0x267D		/* visitor controlled doors							*/
#define	VISITOR_REQUESTTIME		0x267E		/* time for visitor request output					*/
#define	DISABLE_CLEAR			0x267F		/* clear existing call if call disable input		*/
#define	LOCK_TEST_POS			0x2680		/* position for door lock test						*/
#define	BRAKETESTDELAY			0x2681		/* delay time to stop drive for brake test			*/
#define	FVE_VERSION				0x2682		/* FVE version										*/
#define	PSE_VERSION				0x2683		/* PSE version										*/
#define	ASE_VERSION				0x2684		/* ASE version										*/
#define	PARKZONE_MAND			0x2685		/* park zone 1 mandatory							*/
#define	POSITIONMODE			0x2686		/* CANopen drive position mode active				*/
#define	POS_MODE_RES			0x2687		/* pos. reserve to shift target in position mode	*/
#define	IP_ADDRESS				0x2688		/* IP address Ethernet module						*/
#define	DNS_SERVER				0x2689		/* DNS server address Ethernet						*/
#define	GATEWAY					0x268A		/* Gateway address Ethernet							*/
#define	SUBNET_MASK				0x268B		/* Subnet mask Ethernet								*/
#define	ETHERNET_INIT			0x268C		/* Additional init string Ethernet module			*/
#define	ETHERNET_PORT			0x268D		/* Port Ethernet module								*/
#define	DIALTONE_DETECT			0x268E		/* Dialtone detection activ							*/
#define	BUSY_DETECT				0x268F		/* Busy detection activ								*/
#define	LINE_DIALING			0x2690		/* Line dialing string (e.g. 0)						*/
#define	BLOCK_TIME				0x2691		/* Ethernet block time								*/
#define	BLOCK_SIZE				0x2692		/* Max. Ethernet block size							*/
#define	IGNORE_VVVF_PARA		0x2693		/* Ignore VVVF parameter (CANopen)					*/
#define	HANDICAPT_CALLTYPE		0x2694		/* Call type for handicapt calls					*/
#define	HANDICAPT_DOORTIME		0x2695		/* Door open time for handicapt calls				*/
#define	EVAC_DOORCLOSEMODE		0x2696	 	/* door closing mode in evacuation mode				*/
#define	EVAC_DOOROPENMODE		0x2697	 	/* door open mode in evacuation mode				*/
#define	EVAC_FIRE_ACTIVE		0x2698	 	/* fire signals active on evacuation control		*/
#define	EVAC_CROSS_FIRE			0x2699	 	/* cross fire floors on evacuation control			*/
#define	DOORCLOSEMODE			0x269A		/* automatic door close or only by door close push	*/
#define	LAST_FIRETRIP			0x269B		/* Trip if fire alarm in every floor				*/
#define	LAST_FIREFLOOR			0x269C		/* Floor for last trip								*/
#define	GROUP_OFF_KEYTYPE		0x269D		/* Group off input type (push/switch)				*/
#define	SAVE_ESE_ERROR			0x269E		/* Save all ESE errors in error stack				*/
#define	QUICKSTART				0x269F		/* drive quick start function active				*/
#define	QUICKSTARTDELAY			0x26A0		/* drive quick start delay							*/
#define	CAR_DISPLAY_OFF			0x26A1		/* timer to switch off car display (energy saving)	*/
#define	LAND_DISPLAY_OFF		0x26A2		/* timer to switch off land.display (energy saving)	*/
#define	INIT_LOAD_DEVICE		0x26A3		/* Init load device (CANopen)						*/
#define	FORCED_STOP_LOCK_DIR	0x26A4		/* forced stop is locked in this direction			*/
#define	FORCED_ENABLE_TIME		0x26A5		/* time enable input for forced stop is active		*/
#define	FORCED_WAIT_TIME		0x26A6		/* waiting time if forced stop active				*/
#define	FORCED_TIMERTRIP		0x26A7		/* forced stop enabled while timer trip				*/
#define	FORCED_SPECIALTRIP		0x26A8		/* forced stop enabled while special trip			*/
#define	HAZARD_CLEAR_CALLS		0x26A9		/* clear calls by hazard trip						*/
#define	INTERMEDIATE_RUN		0x26AA		/* intermediate_run									*/
#define	CANCEL_CC_IF_MAX		0x26AB		/* cancel old car call if max. car call = 1			*/
#define	LOCK_DEADMAN			0x26AC		/* lock deadman state while moving					*/
#define	LIFT_OFF_DOOR			0x26AD		/* door table for lift switched off					*/
#define	DOOR_OFFTIMER			0x26AE		/* time delay to switch off door					*/
#define	DOOR_ONDELAY			0x26AF		/* time delay after door is switched on				*/
#define	QUICKSTARTDOORPOS		0x26B0		/* door position for drive quick start function		*/
#define	ANALOG_VALUE			0x26B1		/* analogue input value FVE							*/
#define	GROUP_ALLOC				0x26B2		/* group allocation for CBC							*/
#define	GROUP_LIFTS				0x26B3		/* group configuration for HSE						*/
#define	DOORTABLE_TIMER_3		0x26B4		/* enabled door in timer 3 mode						*/
#define	DOORTABLE_TIMER_4		0x26B5		/* enabled door in timer 4 mode						*/
#define	DOORTABLE_TIMER_5		0x26B6		/* enabled door in timer 5 mode						*/
#define	DOORTABLE_T3_HALL		0x26B7		/* enabled door for hall calls in timer 3 mode		*/
#define	DOORTABLE_T4_HALL		0x26B8		/* enabled door for hall calls in timer 4 mode		*/
#define	DOORTABLE_T5_HALL		0x26B9		/* enabled door for hall calls in timer 5 mode		*/
#define	TEMP_SENSOR_CHECK		0x26BA		/* temperature check by temperature sensor			*/
#define	TEMP_LIMIT				0x26BB		/* temperature limit by temperature sensor			*/
#define	AUTO_APRON_DN			0x26BC		/* position below lowest floor to get apron			*/
#define	VISITOR_EMPTY			0x26BD		/* car must be empty to start visitir calls			*/
#define	AUTOCALL_CC_ENABLE		0x26BE		/* car calls enabled if auto call function			*/
#define	AUTOCALL_LC_ENABLE		0x26BF		/* landing calls enabled if auto call function		*/
#define	PALLET_LIFT				0x26C0		/* Car pallet lift									*/
#define	HOOK_TIME				0x26C1		/* Timer for pallet hook							*/
#define	FIRE_DOOROPENPUSH		0x26C2		/* door open push in case of fire active			*/
#define	DOOR_LOCK				0x26C3		/* Doors locked (5*)								*/
#define	DISABLE_LC				0x26C4		/* disable landing calls (6*)						*/
#define SM_NUMBER				0x26C5		/* SIM number GPRS/UMTS								*/
#define SM_NUMBER_PUK			0x26C6		/* PUK number GPRS/UMTS								*/
#define	COOLING_TEMP			0x26C7		/* cooling temperature limit by temperature sensor	*/
#define	RECALL_STOP				0x26C8		/* stop on VO/VU for recall operation/inspection	*/
#define	DEADMAN_CLEAR			0x26C9		/* clear all calls if deadman enable is off			*/
#define	SC_DOOR_TEST			0x26CA		/* test of SL door necessary						*/
#define	VI_LIMIT				0x26CB		/* Inspection speed limit before final floor		*/
#define	VI_LIMIT_DIST			0x26CC		/* Position before final floor for insp.speed limit	*/
#define	ACC_FUNCTION			0x26CD		/* Functions for access control						*/
#define	CODE_FUNCTION			0x26CE		/* Functions for access control						*/
#define	LOAD_MEASURING			0x26CF		/* load measurement always or only if doors open	*/
#define	PARK_DEADMAN			0x26D0		/* parking trip enabled in deadman mode				*/
#define	GOODS_INPUT				0x26D1		/* input to start good transportation mode			*/
#define	GOODS_ACTIVATION		0x26D2		/* button press time to start good transp.mode		*/
#define	GOODS_DEACTIVATION		0x26D3		/* time to finish good transportation mode			*/
#define	BRAKETEST_START			0x26D4		/* time interval to start brake open test			*/
#define	BRAKETEST_ONTIME		0x26D5		/* time brake on while brake open test				*/
#define	BRAKETEST_OFFTIME		0x26D6		/* time brake off while brake open test				*/
#define	BRAKETEST_NO_CC			0x26D7		/* time without car call to start brake test		*/
#define	BRAKETEST_DIFF			0x26D8		/* time without car call to start brake test		*/
#define	SHELTER_SC4				0x26D9		/* shelter off if SC4 off while lift outside level	*/
#define	SAFETY_UNIT				0x26DA		/* safety unit SHM exists							*/
#define	EARTHQUAKE_TIME_BACK	0x26DB		/* delay time to go back to normal mode				*/
#define	EVAC_DIRECTION			0x26DC		/* direction for UPS evacuation						*/
#define	EVAC_TYPE				0x26DD		/* UPS evacuation by drive or by brake opening		*/
#define	SC3_SC4_TEST			0x26DE		/* test door contacts by SC3/SC4 (special wiring)	*/
#define	EARTHQUAKE_SPEED		0x26DF		/* maximum speed if earthquake						*/

#define	SAFETY_CHECK			0x2F00		/* Safety check object								*/
#define	CLEAR_GROUP				0x2FFB		/* Clear group call									*/
#define	REALTIMER				0x2FFC		/* Internal timer (100ms)							*/
#define	PORT_IN					0x2FFD		// port input state
#define	PORT_OUT				0x2FFE		// port output state
#define	SAVEPARA				0x2FFF		// 1=save all lift parameter
#define	TSE_INPAR				0x3000		// free programmable inputs of TSE
#define	TSE_OUTPAR				0x3100		// free programmable outputs of TSE
#define	CLEAR_TSE				0x33FE		/* clear all TSE parameter (for DFUE)				*/
#define	CLEAR_ESE				0x33FF		// clear all ESE parameter (for HSE synchronisation)
#define	ESE_INPAR				0x3400		// free programmable inputs of ESE
#define	ESE_OUTPAR				0x3800		// free programmable outputs of ESE
#define	HW_CODE					0x3C00		// internal hardware code
#define	CHECKSUM				0x3C01		/* Parameter checksum								*/
#define	PCB_TEST				0x3C10		/* PCB test mode									*/


#define	LIMIT_YEARS				0x4000
#define	LIMIT_MONTHS			0x4001
#define	LIMIT_DAYS				0x4002
#define	LIMIT_HOURS				0x4003
#define	LIMIT_COUNT				0x4004
#define	LIMIT_ENABLE			0x4005

#define	HHT_LIMIT_YEARS				0x4006
#define	HHT_LIMIT_MONTHS			0x4007
#define	HHT_LIMIT_DAYS				0x4008
#define	HHT_LIMIT_ENABLE			0x4009
#define	HHT_LIMIT_SAVEPARA		0x400A


#define IV_CAPACITY									0x4101
#define IV_SERIERS									0x4102
#define IV_VOLTAGECLASS								0x4103
#define IV_ENCODERTYPE								0x4104
#define IV_MOTOR_CONTROL_TYPE						0x4105
#define IV_CARRIERFREQUENCY							0x4106
#define	IV_RUN_INSTRUCTION_SEL						0x4107
#define	IV_RUN_MODE_SEL								0x4108
#define	IV_STOP_MODE_SEL							0x4109
#define	IV_FREQ_INSTRUCTION_SEL						0x410A

#define IV_PULSES									0x4201
#define IV_FILTERTIMING								0x4202
#define IV_ENCODERPHASE								0x4203
#define IV_ENCODERANGLE								0x4204
#define IV_CANENABLE								0x4205
#define IV_CANBAUDRATE								0x4206
#define IV_NODEID									0x4207
#define IV_AUTOSENDID								0x4208

#define IV_ACCELERATETIME1							0x4301
#define IV_DECELERATETIME1							0x4302
#define IV_ACCELERATETIME2							0x4303
#define IV_DECELERATETIME2							0x4304
#define IV_ACCE_SHIFTFREQ							0x4305
#define IV_DECE_SHIFTFREQ							0x4306
#define IV_ACCE_START_CORNERTIME					0x4307
#define IV_ACCE_END_CORNERTIME						0x4308
#define IV_DECE_START_CORNERTIME					0x4309
#define IV_DECE_END_CORNERTIME						0x430a

#define IV_CONTACTDELAY								0x4401
#define IV_STARTLOCKTIME							0x4402
#define IV_OPENBRAKEDELAY							0x4403
#define IV_CLOSEBRAKEDELAY							0x4404
#define IV_POWEROFF_TRANSTIME						0x4405
#define IV_EMERGENCYSTOP_TIME						0x4406

#define IV_FREQ_INSTRUCTION1						0x4501
#define IV_FREQ_INSTRUCTION2						0x4502
#define IV_FREQ_INSTRUCTION3						0x4503
#define IV_FREQ_INSTRUCTION4						0x4504
#define IV_FREQ_INSTRUCTION5						0x4505
#define IV_FREQ_INSTRUCTION6						0x4506
#define IV_FREQ_INSTRUCTION7						0x4507
#define IV_FREQ_INSTRUCTION8						0x4508
#define IV_INCHING_FREQ								0x4509
#define IV_MAX_OUT_FREQ								0x450a
#define IV_ZEROSPEED_VALVE_FREQ						0x450b
#define IV_FREQ_CHECK_AMPLITUDE						0x450c


#define IV_MOTOR_RATED_POWER						0x4601
#define IV_MOTOR_POLES								0x4602
#define IV_MOTOR_RATED_CURRENT						0x4603
#define IV_MOTOR_RATED_VOLTAGE						0x4604
#define IV_MOTOR_RATED_FREQ							0x4605
#define IV_MOTOR_RATED_RSPEED						0x4606
#define IV_MOTOR_NOLOAD_CURRENT						0x4607
#define IV_MOTOR_RATED_RDIFF						0x4608
#define IV_MOTOR_L_RESISTANCE						0x4609
#define IV_MOTOR_LEAKAGE_RESIS						0x460a
#define IV_SATURATED_COEFFICIENT1					0x460b
#define IV_SATURATED_COEFFICIENT2					0x460c
#define IV_ROTATE_DIRECTION							0x460d

#define IV_HS_PROPORTION_GAIN						0x4701
#define IV_LS_PROPORTION_GAIN						0x4702
#define IV_START_PROPORTION_GAIN					0x4703
#define IV_HS_INTEGRAL_TIME							0x4704
#define IV_LS_INTEGRAL_TIME							0x4705
#define IV_START_INTEGRAL_TIME						0x4706
#define IV_ASR_SHIFT_FREQ							0x4707
#define IV_MOMENT_FILTER_TIME						0x4708
#define IV_DRAG_MOMENT_LIMIT						0x4709
#define IV_BRAKE_MOMENT_LIMIT						0x470a
#define IV_CURRENT_COMP_EN							0x470b
#define IV_CURRENT_GAIN								0x470c

#define IV_START_POS_LOCK_SEL						0x4801
#define IV_ZERO_POS_LOCK_GAIN						0x4802
#define IV_DWELL_START_FREQ							0x4803
#define IV_DWELL_START_TIME							0x4804
#define IV_MOMENT_BIAS_COMP_MODE					0x4805
#define IV_ZEORLOAD_UP_BRAKE_CM						0x4806
#define IV_ZEORLOAD_DOWN_DRAG_CM					0x4807
#define IV_FULLLOAD_UP_DRAG_CM						0x4808
#define IV_FULLLOAD_DOWN_BRAKE_CM					0x4809
#define IV_START_CM_DIRECTION						0x480a

#define IV_MOTOR_OVERLOAD_PROT_ENABLE				0x4901
#define IV_MOTOR_OVERLOAD_PROT_TIME					0x4902
#define IV_OVERTEMP_PROT_ENABLE						0x4903
#define IV_OVERTEMP_PROT_LIMIT						0x4904
#define IV_OVERTEMP_PROT_TIME						0x4905
#define IV_START_FAN_TEMP							0x4906
#define IV_OTHER_OVERTEMP_PROT_ENABLE				0x4907
#define IV_OVERMOMENT_PROT_ENABLE					0x4908
#define IV_OVERMOMENT_PROT_LIMIT					0x4909
#define IV_OVERMOMENT_DECT_TIME						0x490a
#define IV_STALLING_PROT_ENABLE						0x490b
#define IV_STALLING_LIMIT_FREQ_RATE					0x490c
#define IV_STALLING_PROT_TIME						0x490d
#define IV_OVERSPEED_PROT_ENABLE					0x490e
#define IV_OVERSPEED_LIMIT_FREQ_RATE				0x490f
#define IV_OVERSPEED_PROT_TIME						0x4910
#define IV_DISCONNECT_ENCODER_PROT_ENABLE			0x4911
#define IV_INPUT_LOSEPHASE_PROT_ENABLE				0x4912
#define IV_INPUT_LOSEPHASE_PROT_LIMIT				0x4913
#define IV_OUTPUT_LOSEPHASE_PROT_ENABLE				0x4914
#define IV_MOTOR_CREEPAGE_PROT_ENABLE				0x4915
#define IV_DISCONNECT_PROT_ENABLE					0x4916
#define IV_DISCONNECT_DECT_TIME						0x4917
#define IV_LOW_VOLTAGE_ENABLE						0x4918

//*******************************************************************************
// Object dictionary sub index for Door configuration parameter (6304h - 6306h)
//*******************************************************************************
#define	VELOCITY_PROFILE		0x01		// Door velocity profile
#define	OPEN_WIDE_PROFILE		0x02		// Door velocity profile
#define	DOOR_TYPE				0x03		// Door velocity profile
#define	LS_EVENT_MODE			0x04		// Light screen event mode
#define	REV_MODE				0x05		// Force limit reached mode
#define	FINGER_PROT_MODE		0x06		// Finger prtector mode
#define	MOTION_DETECT_MODE		0x07		// Motion detection mode
#define	LS_RECLOSE_TIME			0x08		// Light screen reclose time in sec
#define	REV_RECLOSE_TIME		0x09		// Closing force limit reached reclose time in sec
#define	LS_BROKEN_TIME			0x0A		// Light screen broken close time in 2 sec (nudging)
#define	HB_LOST_MODE			0x0B		// Heartbeat lost mode

/************************************************************************************************/
/* Vendor ID (Object 0x1018)																	*/
/************************************************************************************************/
#define	INTEC_VENDOR_ID			0x000002F0	/* INTEC vendor ID (CiA)							*/

//*******************************************************************************
// Device type (Object 0x1000 and 0x6000 (if 1 physical device includes more virtual devices))
// The lower 2 Bytes show the profile nuimber (417 for lift application profile)
//*******************************************************************************
#define	MULTIPLE_DEVICES		0x000001A1	// Phyical device supports more than 1 virtual dev.
#define	CALL_CONTROLLER			0x010001A1	// Call controller
#define	INPUT_PANEL_UNIT		0x020001A1	// Input panel unit
#define	OUTPUT_PANEL_UNIT		0x030001A1	// Output panel unit
#define	CAR_DOOR_CONTROLLER		0x040001A1	// Car door controller
#define	CAR_DOOR_UNIT			0x050001A1	// Car door unit
#define	CAR_POSITION_UNIT		0x060001A1	// Car position unit
#define	LIGHT_BARRIER_UNIT		0x070001A1	// Light barrier unit
#define	CAR_DRIVE_CONTROLLER	0x080001A1	// Car drive controller
#define	CAR_DRIVE_UNIT			0x090001A1	// Car drive unit
#define	LOAD_MEASURING_UNIT		0x0A0001A1	// Load measuring unit
#define	SENSOR_UNIT				0x0B0001A1	// Sensor unit
#define	SPEECH_UNIT				0x0C0001A1	// Sensor unit
#define	RFID_COP_UNIT				0x0D0001A1	// Sensor unit
#define	RFID_LIOP_UNIT				0x0E0001A1	// Sensor unit
#define	LIOP_DISPLAY_UNIT				0x0F0001A1	// Sensor unit
#define	POWER_MEASURE_UNIT		0x100001A1	/* Power measurement unit							*/
#define	HANDHELD_UNIT			0x800001A1	// handheld terminal unit

/************************************************************************************************/
/* Output definitions																			*/
/************************************************************************************************/
#define	PROPERTY_BITS			0x0E		/* property bits in output function data			*/
#define	PULSE					0x04		/* pulse outputs									*/

/************************************************************************************************/
/* Definition for all doors and all floors														*/
/************************************************************************************************/
#define	CAR_PANEL				0x00		/* for CANopen for general output functions			*/
#define	ALL_FLOORS				0xFF		/* for CANopen for general output functions			*/
#define ALL_DOORBITS			0xFF		/* for CANopen for general output functions			*/

//*******************************************************************************
// Basic function (Input panel unit, object 0x6100 to 0x611F, Byte 0)
// Basic function (Output panel unit, object 0x6200 to 0x621F, Byte 0)
//*******************************************************************************
#define	GEN_IO					0x01		// generic input / output
#define	HALL_CALL				0x02		// standard hall call / acknowledgement
#define	HALL_CALL_LOW			0x03		// low priority hall call / acknowledgement
#define	HALL_CALL_HIGH			0x04		// high priority hall call / acknowledgement
#define	CAR_CALL				0x05		// standard car call / acknowledgement
#define	CAR_CALL_LOW			0x06		// low priority car call / acknowledgement
#define	CAR_CALL_HIGH			0x07		// high priority car call / acknowledgement
#define	DEST_CALL				0x08		// standard destination call / acknowledgement
#define	DEST_CALL_LOW			0x09		// low priority destination call / acknowledgement
#define	DEST_CALL_HIGH			0x0A		// high priority destination call / acknowledgement
#define	CALL_TO_DEST			0x0B		// standard call to destination floor / acknowl.
#define	CALL_TO_DEST_LOW		0x0C		// low priority call to destination floor / ackn.
#define	CALL_TO_DEST_HIGH		0x0D		// high priority call to destination floor / ackn.
#define	SPECIAL_FUNC			0x0E		// special function / acknowledgement
#define	ACC_CODE_UPLOAD			0x0F		// access code upload request / acknowledgement
#define	SPEECH_CONNECT			0x10		// speech connection request / acknowledgement
#define	AREA_MONITORING			0x11		// area monitoring connection request / acknowl.
#define	FUNC_CTE_MODE					0x12
#define	ACCESS_OP_IN			0x13
#define	FIRE_FUNCTION		0x14		//考虑旧产品的兼容性，使用与 SPECIAL_FUNC 同样的功能码
#define	CALL_TYPE			0x15

// only for outputs
#define	POSITION_INDICATOR		0x40		// Position indicator
#define	HALL_LANTERN					0x41		// Hall lantern
#define	DIRECTION_IND					0x42		// Direction indication
#define	SPECIAL_INDICATION			0x43		// Special indication
#define	ARRIVAL_INDICATION		0x44		// Arrival indication (Gong)
#define	OPERATION_DATA				0x45		// Operation data
#define	PUBLICATION_INDICATION	0x46		// Publicity indication
#define	MUSIC_ARRIVAL			0x47		// Operation data
#define	DISP_FLASH					0x48		// Operation data
#define	LIGHT_FUNC					0x49		// car light input or output
#define	SPEECH_OUT					0x4A		/* Outputs Vocal floors announcement				*/
#define	SPEECH_MESSAGE			0x4B		/* Outputs for Vocal messages						*/
#define	SPEAKER_BUZ				0x4C		// ARRIVAL_INDICATION Arrival indication (Gong)

// manufacturer specific code area
#define	INSPECT_IN				0x80		// inspection inputs
#define	DOORTEST				0x81		// door test
#define	POS_IN					0x82		// position switches
#define	CARLIGHT				0x83		// car light input or output
#define	LOAD_IN					0x84		// load measurement input
#define	DOOR_IO					0x85		// door input or door output relay
#define	DOOR_LS					0x86		// light screen
#define	SAFETY_CIRCUIT			0x87		// safety circuit
#define	EMERGENCY_LIGHT			0x88		// emergency light output
#define	EM_OP_IN				0x89		// emergency recall operation inputs
#define	DRIVE_OUT				0x8A		// drive I/O (mains contactors)
#define	BRAKE_CHECK				0x8B		// brake check inputs
#define	TEMPERATURE				0x8C		// temperature inputs
#define	PRESSURE				0x8D		// pressure inputs (hydraulic lifts)
#define	CONNECTED_IO			0x8E		// Connection between input and output
#define	HALL_CALL_SPECIAL		0x8F		// special hall call (higher priority)
#define	HALL_CALL_ADVANCED		0x90		// advanced hall call (higher priority)
#define	HALL_CALL_EMERGENCY		0x91		// emergency hall call (higher priority)
#define	ENABLE_CARCALL			0x92		// enable car call or doors (I)
#define	DISABLE_CARCALL			0x93		// disable car call or doors (I)
#define	ENABLE_HALLCALL			0x94		// enable hall call or doors (I)
#define	DISABLE_HALLCALL		0x95		// disable hall call or doors (I)
#define	ALARM_CALL				0x96		// alarm call input or alarm call output relay
#define	FORCE_SWITCH				0x97		// force dec switch
#define	CONT_CHECK				0x98
#define	DOOR_FUNCTION		0x99

#define	SLICKTEST				0xA0		/* slick test input									*/
#define	SETUP_TRIP_IN			0xA1		/* setup trip inputs								*/
#define	INSPECT_PIT				0xA2		/* inspection from shaft pit inputs					*/
#define	DEADMAN_IN				0xA3		/* Deadman control inputs							*/
#define	CAR_SENSOR				0xA4		/* Car sensor										*/
#define	LIFT_TRAFFIC_LIGHT		0xA5		/* Car control traffic light for lift				*/
#define	PRE_TRAFFIC_LIGHT		0xA6		/* Car control traffic light before lift			*/
#define	ATTEND_FUNC				0xA7		/* Inputs and outputs for attendance mode			*/
#define	FIRE_FUNC				0xA8		/* Inputs and outputs for fire control				*/
#define	UPS_FUNC				0xA9		/* Inputs and outputs for UPS evacuation			*/
#define	SHELTER_SPACE			0xAA		/* Inputs and outputs for Safety shelter			*/
#define	VISITOR_CALL_1			0xAB		/* visitor call type 1 (I)							*/
#define	VISITOR_CALL_2_UP		0xAC		/* visitor call type 2 with down landing call (I)	*/
#define	VISITOR_CALL_3			0xAD		/* visitor call type 3 (I)							*/
#define	TARGET_CALL_UP			0xAE		/* target call with up landing call (I)				*/
#define	HAZARD_CALL				0xAF		/* hazardous transportation call (I/O)				*/
#define	FAULT_OUT				0xB0		/* Fault outputs (O)								*/
#define	HOLDING_BOLT			0xB1		/* Inputs and outputs for Holding bolts				*/
#define	HAZARD_DOOR				0xB2		/* hazardous transportation door command (I)		*/
#define	TARGET_CALL_DN			0xB3		/* target call with down landing call (I)			*/
#define	VISITOR_CALL_2_DN		0xB4		/* visitor call type 2 with down landing call (I)	*/
#define	VISITOR_CC_ENABLE		0xB5		/* visitor car call enabled (O)						*/
#define	VISITOR_LC_ENABLE		0xB6		/* visitor landing call enabled (O)					*/
#define	OP_DEVICE				0xB7		/* OP device (I/O)									*/
#define	RAMP_IN					0xB8		/* ramp drive (I)									*/
#define	TRAVEL_IND				0xB9		/* Travel direction indication						*/
#define	SPEECH_FLOOR			0xBA		/* Floor outputs for speech indication				*/
#define	VISITOR_REQUEST			0xBB		/* Visitor car call request							*/
#define	EVAC_CONTROL			0xBC		/* Evacuation control (IO)							*/
#define	PALLET_CALL				0xBD		/* Pallet call										*/
#define	PALLET_STATE			0xBE		/* Pallet exist										*/
#define	PALLET_HOOK				0xBF		/* Pallet hook position								*/
#define	PALLET_TEST				0xC0		/* Pallet test input								*/
#define	PENTHOUSE_CALL			0xC1		/* Penthouse call									*/

// only for test, not CANopen conform
#define	TEST_IO					0xF0		// outputs and inputs for test

/* not CANopen conform, to transmit door state of CANopen door from HSE to FVE (from  SDO)		*/
#define	DR_STATE				0xF1		/* outputs and inputs for test						*/

/************************************************************************************************/
/* Sub function if basic function is PALLET_STATE output (0xB6)									*/
/************************************************************************************************/
#define PALLET_IN				0x01		/* relay to bring pallet in							*/
#define PALLET_OUT				0x02		/* relay to put pallet out							*/
#define PALLET_FAST				0x04		/* relay to move pallet fast						*/

/************************************************************************************************/
/* Sub function if basic function is PALLET_HOOK input (0xB7)									*/
/************************************************************************************************/
#define PALLET_HOOK_MIDDLE		0x01		/* pallet hook is in middle position				*/
#define PALLET_HOOK_END			0x02		/* pallet hook is in end position 					*/
#define PALLET_HOOK_MI_LE		0x03		/* pallet hook is in middle position on left switch	*/
#define PALLET_HOOK_MI_RI		0x04		/* pallet hook is in middle position on right switch*/
#define PALLET_HOOK_END_LE		0x05		/* pallet hook is in end position on left switch	*/
#define PALLET_HOOK_END_RI		0x06		/* pallet hook is in end position on right switch	*/
#define PALLET_HOOK_LIMIT		0x07		/* pallet is in final limit position				*/

/************************************************************************************************/
/* Sub function if basic function is pallet test input (0xB8)									*/
/************************************************************************************************/
#define	PALLET_TEST_ON			0x01		/* pallet test active								*/
#define	PALLET_TEST_IN			0x02		/* pallet in for test								*/
#define	PALLET_TEST_OUT			0x04		/* pallet out for test								*/

//*******************************************************************************
// Sub function (Input panel unit, object 0x6100 to 0x611F, Byte 1) if basic function is 2 - 4
//*******************************************************************************
#define	HALL_CALL_UP			0x01		// hall call up direction
#define	HALL_CALL_DOWN			0x02		// hall call down direction
#define	HALL_CALL_NO_DIR		0x03		// hall call both directions

//*******************************************************************************
// Sub function (Input panel unit, object 0x6100 to 0x611F, Byte 1) if basic function is 0x0E
// Sub function (Output panel unit, object 0x6200 to 0x621F, Byte 1) if basic function is 0x0E
//*******************************************************************************
#define	FAN_1					0x01		// Request fan 1 / acknowledgement (IO)
#define	FAN_2				0x02		/* Request fan 2 / acknowledgement (IO)				*/
//#define	CARLIGHT					0x03		// car light input or output
#define	KEY_SPECIAL				0x05		// Key lock 1 / acknowledgement (IO)
#define	KEY_ADVANCED			0x06		// Key lock 2 / acknowledgement	(IO)
#define	KEY_EMERGENCY			0x07		// Key lock 3 / acknowledgement	(IO)
#define	KEY_OFF					0x08		// Key lock 4 / acknowledgement	(I)
#define	DOOR_OPEN				0x09		// Request door open / acknowledgement (IO)
#define	DOOR_CLOSE				0x0A		// Request door close / acknowledgement	(IO)
#define	FIRE_SERVICE_ENABLE		0x0B		// Fire service enable / acknowledgement (car) (IO)
#define	FIRE_SERVICE			0x0C		// Fire service / acknowledgement (hall) (IO)
#define	HALL_CALL_DISABLE		0x0D		// disable hall calls / acknowledgement (I)
#define	ATTENDANT_SERVICE	0x0E		/* attendant service / acknowledgement				*/
#define	VIP_SERVICE			0x0F		/* VIP service / acknowledgement					*/
#define	OUT_OF_ORDER			0x10		// out of order / acknowledgement (IO)
#define	FORCED_STOP_IN	0x11
#define	FIRE_CALL1			0x12		// Fire service / acknowledgement (hall) (IO)
#define	FIRE_CALL2			0x13		// Fire service / acknowledgement (hall) (IO)

#define	LOAD_TIME_1			0x23		/* Request load time 1 / acknowledgement (IO)		*/
#define	LOAD_TIME_2			0x24		/* Request load time 2 / acknowledgement (IO) 		*/
#define	BED_SERVICE			0x25		/* bed passenger service / acknowledgement			*/
#define	SPECIAL_SERVICE		0x26		/* special service / acknowledgement				*/
#define	SERVICE_RUN			0x27		/* service run / acknowledgement					*/
#define	DOGGING_ENABLE		0x28		/* dogging service enable / acknowledgement			*/
#define	DOGGING_UP			0x29		/* dogging service up / acknowledgement				*/
#define	DOGGING_DOWN		0x2A		/* dogging service down / acknowledgement			*/
#define	EARTHQUAKE_DETECTOR		0x2B		/* Earthquake detector (seismic detection system)	*/

#define	CAR_EMPTY				0x30		/* car sensor (I)									*/
#define	INSPECTION_OUT			0x31		/* Inspection output (O)							*/
#define	SC_OUT					0x32		/* Sacfety circuit indication output (O)			*/
#define	DOOROPEN_IND			0x33		/* Door is opened indication output (O)				*/
#define	PARKING_TRIP			0x34		/* Indication for parking trip						*/
#define	CARLIGHT_IND			0x35		/* Indication that carlight is off					*/
#define	CC_BUZZER				0x36		/* car call buzzer (O)								*/
#define	LC_BUZZER				0x37		/* hall call buzzer (O)								*/
#define	DOOR_IS_OPENING			0x38		/* Door is opening (O)								*/
#define	CONFIGMODE				0x39		/* Actual call configuration mode					*/
#define	LEVEL_ZONE				0x3A		/* Lift inside level zone (indication)				*/
#define	FINAL_LIMIT				0x3B		/* Final limit switch								*/
#define	EM_STOP					0x3C		/* Emergency stop (I/O)								*/
#define	INSP_LIMIT				0x3D		/* Inspection limit switch (top floor)				*/
#define	SERVICE_MODE			0x3E		/* Service mode										*/
#define	IN_LEVEL				0x3F		/* Lift inside level (indication)					*/
#define	SAFETY_ERROR			0x40		/* Signal from safety unit							*/
#define	CAN_SAF					0x41		/* Output to connect control bus and CAN safety unit*/
#define	HALLCALL_OFF			0x42		/* Hall calls switched off							*/
#define	PHASE_ERROR				0x43		/* Phase error										*/
#define	VVVF_OFF				0x44		/* switch off VVVF									*/
#define	KEY_HAZARD				0x45		/* Key for hazardous transport (I/O)	 			*/
#define	CALL_HAZARD				0x46		/* Call for hazardous transport	(O)		 			*/
#define	PARKING					0x47		/* Lift is parking (O)								*/
#define	CALLCONFIG_MODE			0x48		/* start call configuration mode (I)				*/
#define	ALARM_ENABLED			0x49		/* Alarm is enabled									*/
#define	LC_REQUEST				0x4A		/* Landing call pressed while not enabled			*/
#define	USE_CARD				0x4B		/* Use card to enable car calls						*/
#define	INSP_CAR_OUT			0x4C		/* Inspection (car top) output (O)					*/
#define	INSP_PIT_OUT			0x4D		/* Inspection (pit) output (O)						*/
#define	PRESENCE_SENSOR			0x4E		/* Presence sensor input (I)						*/
#define	STANDSTILL_LEVEL		0x4F		/* Presence sensor output (O)						*/
#define	RAMP_OUT				0x50		/* Ramp mode output (O)								*/
#define	SAF_GEAR_TEST			0x51		/* Test output for Safety gear test					*/
#define	V_LIMIT_OUT				0xB2		/* Output for speed limit							*/
#define	DOORPUSHBUZZER			0x53		/* buzzer for door open/close push (O)				*/
#define	DOOR_LOCK_TEST			0x54		/* Input to move up for checking door lock (O)		*/
#define	TEACH_IN_SIGNAL			0x55		/* Teach-in active (O)								*/
#define	ZONE_RESET				0x56		/* Switch off SGM (KH7 input) after reset			*/
#define	HANDICAP_LC				0x57		/* Handicapt landing call active					*/
#define	HANDICAP_CC				0x58		/* Handicapt car calls active						*/
#define	TEST_TRIP				0x59		/* Test trips										*/
#define	GROUP_OFF				0x5A		/* group control off								*/
#define	STANDBY					0x5B		/* standby (energy saving)							*/
#define	FORCED_STOP_OFF			0x5C		/* unlock forced stop								*/
#define	ROLL_TEXT				0x5D		/* set roll text (only for PMA) or free sign (LCD)	*/
#define	DOOR_STANDBY			0x5E		/* switch door off (standby)						*/
#define	TIMER3_TRIP				0x5F		/* Timer 3 trip	(I/O)								*/
#define	TIMER4_TRIP				0x60		/* Timer 4 trip	(I/O)								*/
#define	TIMER5_TRIP				0x61		/* Timer 5 trip	(I/O)								*/
#define	TELECOM_OFF				0x62		/* Data remote control (telecom) inactive			*/
#define	TIMER_TRIP				0x63		/* Timer trip general (O)							*/
#define	VISITOR_CALL			0x64		/* visitor call general (O)							*/
#define	COOLING					0x65		/* Controller cabinet cooling (O)					*/
#define	SC_BYPASS				0x66		/* Safety circuit bypass switch (EN81-20)			*/
#define	INSP_RESET				0x67		/* Reset inspection pit								*/
#define	CLEAR_CARCALLS			0x68		/* Clear all car calls (I)							*/
#define	GOODS_TRANSPORT			0x69		/* goods transportation mode (O)					*/
#define	SAFETY_FUNC				0x6A		/* General safety function (I/O)					*/
#define	SAFETY_FUNC_RESET		0x6B		/* Reset input for general safety function			*/
#define	SPEED_MAX				0x6C		/* Input to limit the maximum speed					*/

#define	BUZZER					0x80		// buzzer for general use (O)
#define	REMOTE_OFF				0x81		// Remote switch off (IO)
#define	INTERMEDIATE_DOOR		0x82		// Intermediate door in car (I)
#define	TIMER1_TRIP				0x83		// Timer 1 trip	(I)
#define	TIMER2_TRIP				0x84		// Timer 2 trip	(I)
#define	NO_LOAD_STATE			0x85		// no load output (car empty) (O)
#define	FULL_LOAD_STATE			0x86		// full load output (car full) (O)
#define	OVER_LOAD_STATE			0x87		// over load output (car overloaded) (O)
#define	FIRE_STATE				0x88		// Fire mode output	(O)
#define	OCCUPIED				0x89		// Lift is occupied	(O)
#define	FAULT_SIGNAL			0x8A		// Fault signal	(O)
#define	REMOTE_OFF_STATE		0x8B		// Lift is remote switched off (O)
#define	DOOR_IS_CLOSING			0x8C		// Door is closing (O)
#define	SPECIAL_MODE			0x8D		// Lift is in special mode (not normal mode) (O)
#define	CLEAR_CALLS				0x8E		// Clear all calls (I)
#define	FIRE_EVACUATION			0x8F		// Fire evacuation (I)
#define	FIRE_ALARM				0x90		// Fire alarm (IO)
#define	FIRE_ALARM_RETURN		0x91		// Return from fire alarm (I)
#define	FIRE_ALARM_FLOOR		0x92		// Return from fire alarm (O)
#define	UPS_EVACUATION			0x93		// UPS evacuation (IO)
#define	SAFETY_BEAM				0x94		// Safety beam (I) or safety beam reset
#define	EARTHQUAKE				0x95		// earthquake (I)
#define	CAR_ATTENDANCE			0x96		// car attendance (I)
#define	CALLDIR_UP				0x97		// set call direction to up (I)
#define	CALLDIR_DN				0x98		// set call direction to down (I)
#define	CALL_BYPASS				0x99		// bypass a call (I)
#define	HALLCALL_BYPASS			0x9A		// bypass a hall call (IO)
#define	AUTO_CALL				0x9B		// auto-call function ("Sabbat-control")
#define	UP_PEAK_TRAFFIC			0x9C		// up peak traffic
#define	DN_PEAK_TRAFFIC			0x9D		// down peak traffic
#define	EVACUATION_ACTIVE				0x9E		// evacuation enable (I)
#define	EVACUATION_READY		0x9F		// evacuation ready (IO)
#define	EVACUATION_NORMAL		0xA0		// evacuation normal (I)
#define	DOOR_STOP				0xA1		// door stop push (I)
#define	UPS_BRAKE				0xA2		// UPS evacuation by just brake opening
#define	LIGHT_SWITCH			0xA3
#define	FAN_SWITCH				0xA4
#define	ANTI_FAINT_OUTPUT		0xA5
#define	FIREFLOOR_IND			0xA6
#define	UPS_EVAC_READY			0xA7
#define	UPS_EVAC_READY_SPEAKER	0xA8
#define	SAFETY_BEAM_SWITCH				0xA9		// Safety beam 到位信号
#define	UCMP_LOCK			0xAA		
#define	EMP_POWER			0xAB		
#define	FIRE_BYPASS			0xAC
#define	ATT_BUZ_ALARM	0xAD
#define	DOOR_CONN_ALARM		0xAE
#define	GROUP_FLOOR_LOCK		0xAF
//#define	DOOR_LS					0xB0		// light screen
#define	VIP_CARCALL			0xB1
#define	SAFETY_RAMP			0xB2
#define	FIRE_HOLD				0xB3
#define	FIRE_PHASE2				0xB4
#define	EVACUATION_KEY		0xB5

/************************************************************************************************/
/* Dewfinitions for buzzer type																	*/
/************************************************************************************************/
#define	OVERLOAD_BUZZER			0x01		/* overload buzzer									*/
#define	DOOR_BUZZER				0x02		/* door nudging buzzer								*/
#define	CALL_BUZZER				0x04		/* call buzzer										*/
#define	FVE_DOOR_BUZZER			0x08		/* door nudging buzzer controlled by FVE			*/

/************************************************************************************************/
/* Sub function if basic function is 0x43 (Special indication)									*/
/************************************************************************************************/
#define	SP_OUT_NOLOAD			0x01		/* No load indication								*/
#define	SP_OUT_FULLLOAD			0x02		/* Full load indication								*/
#define	SP_OUT_OVERLOAD			0x03		/* Overload indication								*/
#define	SP_OUT_FIRE				0x04		/* Fire indication									*/
#define	SP_OUT_FIREMODE			0x05		/* Fire state indication							*/
#define	SP_OUT_HELP_COMING		0x06		/* Help is coming indication						*/
#define	SP_OUT_SPECIAL			0x07		/* Special service indication						*/
#define	SP_OUT_LOAD_TIME		0x08		/* Load time indication								*/
#define	SP_OUT_OCCUPIED			0x09		/* Occupied indication								*/
#define	SP_OUT_OUT_OF_ORDER		0x0A		/* Out of order indication							*/
#define	SP_OUT_CLOSE_DOOR		0x0B		/* Close door indication							*/
#define	SP_OUT_CASE_OF_FIRE		0x0C		/* Case of fire indication							*/
#define	SP_OUT_HALLCALL_OFF		0x0D		/* Hall calls disabled indication					*/
#define	SP_OUT_EVACUATION		0x0E		/* Evacuation travel indication						*/
#define	SP_OUT_FIRE_TRIP		0x0F		/* Travel to fire floor indication					*/

/************************************************************************************************/
/* Sub function if basic function is 0x4A (Speech output)										*/
/************************************************************************************************/
#define	SP_DIR_UP				0x01		/* Direction up										*/
#define	SP_DIR_DN				0x02		/* Direction down									*/
#define	SP_DR_CLOSING			0x03		/* Door is closing									*/
#define	SP_DR_OPENING			0x04		/* Door is opening									*/
#define	SP_ENABLE				0x05		/* Enable signal for speech							*/
#define	SP_TIMER1_TRIP			0x06		/* Clock run 1										*/
#define	SP_TIMER2_TRIP			0x07		/* Clock run 2										*/
#define	SP_FIRE_STATE			0x08		/* Fire state										*/
#define	SP_FIRE_SERVICE_ENABLE	0x09		/* Fire service										*/
#define	SP_FIRE_SERVICE			0x0A		/* Fire call										*/
#define	SP_FIRE_ALARM			0x0B		/* Fire alarm										*/
#define	SP_EVACUATION			0x0C		/* Evacuation active								*/
#define	SP_SPECIAL_MODE			0x0D		/* Special mode										*/
#define	SP_KEY_SPECIAL			0x0E		/* Special run										*/
#define	SP_KEY_ADVANCED			0x0F		/* VIP run											*/
#define	SP_KEY_EMERGENCY		0x10		/* Emergency run									*/
#define	SP_FAULT_SIGNAL			0x11		/* Fault signal										*/
#define	SP_OUT_OF_ORDER			0x12		/* Out of work										*/
#define	SP_USE_CARD				0x13		/* Use card to enable car calls						*/
#define	SP_CAR_CALL				0x14		/* Car call pressed									*/
#define	SP_TIMER3_TRIP			0x15		/* Clock run 3										*/
#define	SP_TIMER4_TRIP			0x16		/* Clock run 4										*/
#define	SP_TIMER5_TRIP			0x17		/* Clock run 5										*/

/************************************************************************************************/
/* Sub function if basic function is 0xA7 (attendance mode)										*/
/************************************************************************************************/
#define	CAR_ATTENDANCE_IN			0x01		/* car attendance (I)								*/
#define	CAR_ATTENDANCE_PUSH		0x02		/* Car attendance push input						*/
#define	CAR_ATTENDANCE_OFF		0x03		/* Car attendance off push input					*/
#define	CALLDIR_UP_IN				0x04		/* set call direction to up (I)						*/
#define	CALLDIR_DN_IN				0x05		/* set call direction to down (I)					*/
#define	CALL_BYPASS_IN				0x06		/* bypass a call (I)								*/
#define	HALLCALL_BYPASS_IN			0x07		/* bypass a hall call (IO)							*/
#define	HALLCALL_PUSH			0x08		/* Hall calls switched off							*/
#define	HALLCALL_IGNORE			0x09		/* ignore hall calls (I)							*/

/************************************************************************************************/
/* Sub function if basic function is 0xA8 (fire control)										*/
/************************************************************************************************/
#define	FIRE_SERVICE_ENABLE_IN		0x01		/* Fire service enable / acknowledgement (car) (IO)	*/
#define	FIRE_SERVICE_IN			0x02		/* Fire service / acknowledgement (hall) (IO)		*/
#define	FIRE_EVACUATION_IN			0x03		/* Fire evacuation (I)								*/
#define	FIRE_ALARM_IN				0x04		/* Fire alarm (IO)									*/
#define	FIRE_ALARM_RETURN_IN		0x05		/* Return from fire alarm (I)						*/
#define	FIRE_ALARM_FLOOR_IN		0x06		/* Return from fire alarm (O)						*/
#define	FIRE_STATE_IN				0x07		/* Fire mode output	(O)								*/
#define	FIRE_SERVICE_RETURN_IN		0x08		/* Return from fire service mode					*/
#define	FIRE_WARNING_IN			0x09		/* Fire warning output (e.g. if inspection is on)	*/

/************************************************************************************************/
/* Sub function if basic function is 0xA9 (UPS evacuation)										*/
/************************************************************************************************/
#define	UPS_EVACUATION_IN			0x01		/* UPS evacuation (I)								*/
#define	UPS_BRAKE_IN				0x02		/* UPS evacuation by just brake opening				*/
#define	EVACUATION_IN			0x03		/* evacuation enable (I)							*/
#define	EVACUATION_READY_IN		0x04		/* evacuation ready (IO)							*/
#define	EVACUATION_NORMAL_IN		0x05		/* evacuation normal (I)							*/
#define	V_LIMIT_UPS_IN				0x06		/* open brake if UPS power and speed > 0,3 m/s		*/
#define	MOVING_UP_IN				0x07		/* lift is moving upwards (O)						*/
#define	MOVING_DN_IN				0x08		/* lift is moving downwards (O)						*/
#define	UPS_EVACUATION_READY_IN	0x09		/* evacuation ready (IO)							*/
#define	EVACUATION_ACTIVE_IN		0x0A		/* evacuation active (O)							*/

/************************************************************************************************/
/* Sub function if basic function is 0xAA (Inputs and outputs for Safety shelter)				*/
/************************************************************************************************/
#define	BEARER_TOP				0x01		/* Bearer in top of shaft (IO)						*/
#define	BEARER_BOT				0x02		/* Bearer in bottom of shaft (IO)					*/
#define	SHELTER_TOP				0x03		/* Selter in top of shaft (I)						*/
#define	SHELTER_BOT				0x04		/* Shelter in bottom of shaft (I)					*/
#define	SHELTER					0x05		/* Shelter in bottom and/or top of shaft (I)		*/
#define	CAR_APRON				0x06		/* Car apron (IO)									*/
#define	BEARER_WARN_TOP			0x07		/* Warning that bearer is not used (manual) (O)		*/
#define	BEARER_WARN_BOT			0x08		/* Warning that bearer is not used (manual) (O)		*/
#define	RAILING					0x09		/* Railing on top of car (I)						*/
#define	GOVERNOR				0x0A		/* Overspeed governor as parking brake (I/O)		*/
#define	UNCONTR_MOVE			0x0B		/* Uncontrolled Movement (I/O)						*/
#define	DECEL_CHECK				0x0C		/* Deceleration check control input					*/
#define	UNCONTR_MOVE_RESET		0x0D		/* Input to reset uncontrolled Move error (I)		*/
#define	GOVERNOR_CHECK_OFF		0x0E		/* Ignore governor input for emergency rescue		*/
#define	SHELTER_RESET			0x0F		/* Input to reset shelter space						*/
#define	UCM_BYPASS				0x10		/* Output to bypass UCM actor						*/

/************************************************************************************************/
/* Sub function if basic function is 0xB1 (Inputs and outputs for Holding bolts)				*/
/************************************************************************************************/
#define	HOLDING_ACTIVE			0x01		/* Activate holding bolt mode (I)					*/
#define	HOLDING_TEST_ON			0x02		/* Start holding bolt test mode (I)					*/
#define	HOLDING_PRESSURE		0x03		/* Hydr. pressure too low while holding bolt (IO)	*/
#define	HOLDING_BOLT_OUT		0x04		/* holding bolt out (IO) (command or state)			*/
#define	HOLDING_BOLT_IN			0x05		/* holding bolt in (IO) (command or state)			*/
#define	HOLDING_REACHED			0x06		/* holding position reached (I)						*/
#define	HOLDING_BOLT_IS_OUT		0x07		/* holding bolt in (IO) (command or state)			*/
#define	HOLDING_BOLT_IS_IN		0x08		/* holding bolt in (IO) (command or state)			*/
#define	HOLDING_TEST_IN			0x09		/* Holding bolt in in test mode (I)					*/
#define	HOLDING_TEST_OUT		0x0A		/* Holding bolt out in test mode (I)				*/
#define	HOLDING_TEST_UP			0x0B		/* Move up from holding position in test mode		*/
#define	HOLDING_TEST_DN			0x0C		/* Move down to holding position in test mode		*/
#define	HOLDING_TEST_STOP		0x0D		/* Holding bolt stop in test mode (I)				*/

/************************************************************************************************/
/* Sub function if basic function is 0xBC (Evacuation control)									*/
/************************************************************************************************/
#define	EVAC_CONTROL_ON			0x01		/* Evacuation control mode (I)						*/
#define	EVAC_CARCALL			0x02		/* Evacuation car call enable (I)					*/
#define	EVAC_STOPP				0x03		/* evacuation enable (I)							*/

/************************************************************************************************/
/* Inputs for holding bolt test																	*/
/************************************************************************************************/
#define	HOLD_TEST_ON			0x01		/* Holding test is on								*/
#define	HOLD_TEST_IN			0x02		/* Holding bolt in in test mode						*/
#define	HOLD_TEST_OUT			0x04		/* Holding bolt out in test mode					*/
#define	HOLD_TEST_UP			0x08		/* Move up from holding position in test mode		*/
#define	HOLD_TEST_DN			0x10		/* Move down to holding position in test mode		*/
#define	HOLD_TEST_STOP			0x20		/* Stop in holding test mode						*/


//*******************************************************************************
// Sub function (Input panel unit, object 0x6100 to 0x611F, Byte 1) if basic function is 0x80
// (Inspection inputs)
//*******************************************************************************
#define	INSP_ON					0x01		// inspection on
#define	INSP_UP					0x02		// inspection up
#define	INSP_DOWN				0x04		// inspection down
#define	INSP_FAST				0x08		// inspection fast

#define	INSP_TOPCAR_ACTIVE			0x01		// inspection on
#define	INSP_INCAR_ACTIVE				0x02		// inspection on
//#define	INSP_ACCESS_ACTIVE				0x04		// inspection on
#define	INSP_CONTROLLER_ACTIVE	0x04		// inspection on
#define	INSP_PITBOX_ACTIVE				0x08		// inspection on
#define	INSP_PLATFORM_ACTIVE		0x10		// inspection on

#define	INSP_TOPCAR_ON				0x01		// inspection on
#define	INSP_TOPCAR_UP				0x02		// inspection up
#define	INSP_TOPCAR_DOWN			0x04		// inspection down
#define	INSP_INCAR_ON					0x11		// inspection on
#define	INSP_INCAR_UP					0x12		// inspection up
#define	INSP_INCAR_DOWN			0x14		// inspection down
#define	INSP_CONTROLLER_ON		0x21		// inspection on
#define	INSP_CONTROLLER_UP		0x22		// inspection up
#define	INSP_CONTROLLER_DOWN	0x24		// inspection down
#define	INSP_PITBOX_ON				0x31		// inspection on
#define	INSP_PITBOX_UP					0x32		// inspection up
#define	INSP_PITBOX_DOWN			0x34		// inspection down
#define	INSP_PLATFORM_ON			0x41		// inspection on
#define	INSP_PLATFORM_UP			0x42		// inspection up
#define	INSP_PLATFORM_DOWN		0x44		// inspection down

#define	INSP_ACCESS_ON				0x01		// inspection on
//#define	INSP_ACCESS_ACTIVE			0x02		// inspection on
#define	INSP_ACCESS_UP				0x02		// inspection up
#define	INSP_ACCESS_DOWN			0x04		// inspection down

/************************************************************************************************/
/* Sub function (Input panel unit, object 0x6100 to 0x611F, Byte 1) if basic function is 0x80	*/
/* (Deadman control inputs)																		*/
/************************************************************************************************/
#define	DEADMAN_ON					0x01		/* Deadman control on							*/
#define	DEADMAN_UP					0x02		/* Deadman control up							*/
#define	DEADMAN_DN					0x04		/* Deadman control down							*/
#define	DEADMAN_MOVE				0x08		/* Deadman control fast							*/
#define	DEADMAN_ENABLE				0x10		/* activate deadman control by input			*/
#define	DEADMAN_LOCKED				0x80		/* marker to lock deadman enable input			*/
#define	DEADMAN_ENABLED				0x90		/* test if deadman control is enabled			*/

/************************************************************************************************/
/* Sub function (Input panel unit, object 0x6100 to 0x611F, Byte 1) if basic function is 0x9B	*/
/* (Car position sensor)																		*/
/************************************************************************************************/
#define	SENSOR_DOOR1				0x01		/* Car is on door 1								*/
#define	SENSOR_DOOR2				0x02		/* Car is on door 2								*/
#define	SENSOR_DOOR3				0x04		/* Car is on door 3								*/
#define	SENSOR_MIDDLE				0x80		/* Car is in middle								*/

/************************************************************************************************/
/* Sub function (Input panel unit, object 0x6100 to 0x611F, Byte 1) if basic function is 0x9C	*/
/* (Car traffic light)																			*/
/************************************************************************************************/
#define	RED_LIGHT					0x01		/* Red traffic light							*/
#define	GREEN_LIGHT					0x02		/* Green traffic light							*/

//*******************************************************************************
// Sub function (Input panel unit, object 0x6100 to 0x611F, Byte 1) if basic function is 0x82
// (Position inputs)
//*******************************************************************************
#define	POS_SGM					0x0001		// position switch middle
#define	POS_SGU					0x0002		// position switch above
#define	POS_SGD					0x0004		// position switch below
#define	POS_LPLS					0x0008
#define	POS_ILU					0x0020		// inspection limit switch above
#define	POS_ILD						0x0040		// inspection limit switch below
#define	POS_UPLS					0x0080

#define	FORCE_SDU1				0x01
#define	FORCE_SDU2				0x02
#define	FORCE_SDU3				0x04
#define	FORCE_SDD1				0x10
#define	FORCE_SDD2				0x20
#define	FORCE_SDD3				0x40

#define	POS_SDU1					(FORCE_SDU1 << 8)
#define	POS_SDU2					(FORCE_SDU2 << 8)
#define	POS_SDU3					(FORCE_SDU3 << 8)
#define	POS_SDD1					(FORCE_SDD1 << 8)
#define	POS_SDD2					(FORCE_SDD2 << 8)
#define	POS_SDD3					(FORCE_SDD3 << 8)

//*******************************************************************************
// Sub function (Input panel unit, object 0x6100 to 0x611F, Byte 1) if basic function is 0x84
// (Load measurement inputs)
//*******************************************************************************
#define	ZERO_LOAD				0x01		// zero load limit reached
#define	HALF_LOAD				0x02		// half load limit reached
#define	FULL_LOAD				0x04		// full load limit reached
#define	OVERLOAD				0x08		// overload limit reached

//*******************************************************************************
// Sub function (Input panel unit,object 0x6100-0x611F, Byte 1) if basic function is door input
// Sub function (Output panel unit,object 0x6200-0x621F,Byte 1) if basic function is door output
//*******************************************************************************
#define	DOOR_OP					0x01		// door open switch or door open relay
#define	DOOR_CL					0x02		// door close switch or door close relay
#define	DOOR_REV				0x04		// door nudging switch or door nudging relay
#define	DOOR_RAMP				0x08		// retiring ramp for revolving door
#define	DOOR_CL_SLOW			0x10		// door close switch or door close relay slow
#define	DOOR_REVOLV			0x20		/* contact on revolving door						*/
#define	DOOR_ADD_RAMP		0x40		/* add. ramp on car door (while opening/closing)	*/
#define	DOOR_ERR				0x80		/* contact on revolving door						*/

/************************************************************************************************/
/* Sub function (Input panel unit,object 0x6100-0x611F, Byte 1) if basic function is ls input	*/
/************************************************************************************************/
#define	LS_SIGNAL				0x00		/* light screen input								*/
#define	LS_ERR					0x01		/* light screen error								*/

//*******************************************************************************
// Sub function (object 0x6100-0x611F, Byte 1) if basic function is safety circuit (0x87)
//*******************************************************************************
#define	SC1						0x01		// safety circuit start
#define	SC2						0x02		// safety circuit car door
#define	SC3						0x04		// safety circuit shaft door / end
#define	SC4						0x08		// safety circuit safety beam
#define	SC_GEAR					0x10		/* safety circuit before gear						*/
#define	SC_GEAR_RESET			0x20		/* Reset input for safety gear						*/

//*******************************************************************************
// Sub function (Output panel unit,object 0x6200-0x621F,Byte 1) if basic function is position
// indicator (0x40)
//*******************************************************************************
#define	ONE_OF_N				0x01		// 1 of n controlled display
#define	BINARY					0x02		// binary controlled display
#define	GRAY					0x03		// gray code controlled display
#define	SEGM_7					0x04		/* 7 segment controlled display						*/
#define	SEGM_9_K				0x05		/* 9 segment controlled display (K style)			*/

/************************************************************************************************/
/* Sub function if basic function is fault output (0xB0)										*/
/************************************************************************************************/
#define	F_SAFETY				0x01		/* Fault in safety unit								*/
#define	F_DOOR					0x02		/* Door fault										*/
#define	F_TEMP_1				0x03		/* Overtemperature 1								*/
#define	F_TEMP_2				0x04		/* Overtemperature 2								*/
#define	F_TEMP_MAX				0x05		/* Machine room temperature too high				*/
#define	F_TEMP_MIN				0x06		/* Machine room temperature too low					*/
#define	F_DRIVE					0x07		/* Drive error										*/
#define	F_PRESS_MIN				0x08		/* Hydraulic pressure too low						*/
#define	F_PRESS_MAX				0x09		/* Hydraulic pressure too high						*/
#define	F_TRIPTIME				0x0A		/* Triptime exceeded								*/
#define	F_LIGHTSCREEN			0x0B		/* Lightscreen error								*/
#define	F_NUDGING				0x0C		/* Lightscreen error								*/
#define	F_BRAKE					0x0D		/* Brake error										*/
#define	F_MAINTENANCE			0x0E		/* Maintenance; lift not moving anymore				*/
#define	F_FAULT_SIGNAL			0x0F		/* Fault signal	(O)									*/
#define	F_SAFETY_BEAM_ERR		0x10		/* Output safety beam error							*/
#define	F_SC					0x11		/* Fault in safety circuit							*/
#define	F_OVERSPEED				0x12		/* overspeed fault 									*/
#define	F_CARLIGHT				0x13		/* carlight off 									*/
#define	F_MAINT_WARNING			0x14		/* Maintenance necessary							*/
#define	F_TEMP_SENSOR_MAX		0x15		/* HSE temperature sensor max. limit				*/
#define	F_TEMP_SENSOR_MIN		0x16		/* HSE temperature sensor min. limit				*/

//*******************************************************************************
// Lift number
//*******************************************************************************
#define	LIFT1					0x01		// bit for lift number 1
#define	LIFT2					0x02		// bit for lift number 2
#define	LIFT3					0x04		// bit for lift number 3
#define	LIFT4					0x08		// bit for lift number 4
#define	LIFT5					0x10		// bit for lift number 5
#define	LIFT6					0x20		// bit for lift number 6
#define	LIFT7					0x40		// bit for lift number 7
#define	LIFT8					0x80		// bit for lift number 8

//*******************************************************************************
// Door number
//*******************************************************************************
#define	DOOR1					0x01		// bit for door number 1
#define	DOOR2					0x02		// bit for door number 2
#define	DOOR3					0x04		// bit for door number 3

//*******************************************************************************
// Function data (Input panel unit, object 0x6100 to 0x611F, Byte 5)
//*******************************************************************************
#define	NO_CALL_REQUEST			0x00		// no call or other input request
#define	CALL_REQUEST			0x01		// call or other input request
#define	FUNC_DEFECT				0x02		// function is defect
#define	FUNC_NOT_INSTALLED		0x03		// function is not installed

//*******************************************************************************
// Edge / polarity (Input parameter 3, object 0x6160 to 0x617F, Byte 1)
// Polarity (Output parameter 3, object 0x6260 to 0x627F, Byte 1)
//*******************************************************************************
#define	POLARITY_BIT			0x80		// Bit 7 (MSB) is polarity bit
#define	HL_EDGE_BIT				0x02		// Bit 1 is high-low edge bit
#define	LH_EDGE_BIT				0x01		// Bit 0 (LSB) is low-high edge bit
#define	INVERTED				1			// Input is inverted
#define	NON_INVERTED			0			// Input is not inverted
#define	EDGE_TRANSMISSION		1			// Input shall be transmitted on this edge
#define	NO_EDGE_TRANSMISSION	0			// Input shall be transmitted on this edge
#define	ENABLE					1
#define	DISABLE					0

//*******************************************************************************
// Sub function (Output panel unit, object 0x6200-0x621F, Byte 1) if basic funct.is 0x41 or 0x42
//*******************************************************************************
#define	DIRECTION_BITS			0x03		// Bits 1 and 0 (LSB) direction arrow bits
#define	LIFT_BITS				0x0C		// Bits 3 and 2 left and right arrow bits
#define	MOVING_BIT				0x10		// Bit 4 moving bit
#define	ARROW_UP				0x01		// Direction arrow up
#define	ARROW_DOWN				0x02		// Direction arrow down
#define	ARROW_RIGHT				0x04		// Direction arrow right
#define	ARROW_LEFT				0x08		// Direction arrow left
#define	MOVING_ARROW_UP			0x10		/* Moving arrow up									*/
#define	MOVING_ARROW_DOWN		0x20		/* Moving arrow down								*/
#define	ALL_ARROWS				0x33		/* Bit mask for all arrows							*/

//*******************************************************************************
// Sub function (Output panel unit, object 0x6200-0x621F, Byte 1) if basic function is 0x43
//*******************************************************************************
#define	ALL_OUTPUTS_OFF		0x00		/* command to switch all special outputs off		*/
#define	NO_LOAD_IND			0x01		/* no load indication (car empty)					*/
#define	FULL_LOAD_IND			0x02		// full load indication (car full)
#define	OVER_LOAD_IND			0x03		// over load indication (car overloaded)
#define	FIRE_IND				0x04		// Fire	indication
#define	FIRE_SERVICE_IND	0x05		/* Fire brigade service	indication					*/
#define	HELP_COMING_IND		0x06		/* Help is coming indication						*/
#define	SPECIAL_SERVICE_IND	0x07		/* Special service indication						*/
#define	LOAD_TIME_IND		0x08		/* Load time indication								*/
#define	OCCUPIED_IND		0x09		/* Lift is occupied indication						*/
#define	OUT_OF_ORDER_IND		0x0A		// Out of order indication
#define	FAULT_SIGNAL_IND	0x80		/* Fault signal										*/

//*******************************************************************************
// Sub function (Output panel unit, object 0x6200-0x621F, Byte 1) if basic function is DRIVE_IO
//*******************************************************************************
#define	D_MAIN					0x01		// main contactor
#define	D_BRAKE					0x02		// brake contactor
//#define	D_FAST					0x02		/* fast contactor  									*/
//#define	D_UP					0x03		/* upward contactor									*/
//#define	D_DOWN					0x04		/* downward contactor								*/
#define	D_FENGXING				0x04		// fx contactor
#define	D_STAR					0x06		/* star contactor									*/
#define	D_DELTA					0x07		/* delta contactor									*/
#define	D_CTRL_UP				0x08		/* control signal up								*/
#define	D_CTRL_DOWN				0x09		/* control signal down								*/
#define	D_CTRL_1				0x0A		/* control signal 1									*/
#define	D_CTRL_2				0x0B		/* control signal 2									*/
#define	D_CTRL_3				0x0C		/* control signal 3									*/
#define	D_CTRL_4				0x0D		/* control signal 4									*/
#define	D_CTRL_5				0x0E		/* control signal 5									*/
#define	D_CTRL_6				0x0F		/* control signal 6									*/
#define	D_CTRL_7				0x10		/* control signal 7									*/
#define	D_CTRL_8				0x11		/* control signal 8									*/
#define	D_ENABLE				0x12		/* enable drive (RF)								*/
#define	D_TRIP					0x14		/* trip (for example for safety gear releasing		*/
#define	D_SLOW					0x15		/* slow contactor  									*/
#define	D_MOTORFAN				0x16		/* motor fan	  									*/
#define	D_VALVE1				0x17		/* Valve output (if valve delayed off)				*/
#define	D_VALVE2				0x18		/* Pump contactor (if valve delayed off)			*/
#define	D_ERROR_RESET			0x19		/* Drive error reset output				 			*/
#define	D_RELEV					0x1A		/* Re-levelling output				 				*/
#define	D_DZ_BYPASS				0x1B		/* Doorzone bypass output			 				*/
#define	D_SLOWSTART				0x1C		/* slow start delay contactor  						*/
#define	D_START					0x1D		/* delayed start signal (fixed 500 ms)				*/
#define	D_HOLDING				0x1E		/* output for holding up or down					*/
#define	D_OPEN_VALVE			0x1F		/* output to open motor valve						*/
#define	D_CLOSE_VALVE			0x20		/* output to close motor valve						*/

//*******************************************************************************
// Sub function (Input panel unit, object 0x6100-0x611F, Byte 1) if basic function is DRIVE_IO
//*******************************************************************************
#define	D_RUNCONT_SUP			0x01		// running contactors supervising input
#define	D_FXCONT_SUP				0x02		// fx contactor supervising input
#define	D_BRKCONT_SUP			0x04		// brake contactor supervising input
//#define	D_CONTACTOR				0x01		/* main contactors supervising input				*/
//#define	D_FAULT_SIGNAL			0x02		/* drive fault										*/
//#define	D_READY_SIGNAL			0x03		/* drive contactor on signal						*/
//#define	D_BRAKE_SIGNAL			0x04		/* drive open brake signal							*/
//#define	D_MOVE_SIGNAL			0x05		/* drive moving signal (speed > 0)					*/
//#define	D_SOFTSTART_RDY			0x06		/* softstarter ready								*/
//#define	D_RDY_SIGNAL			0x07		/* drive ready to move signal						*/
//#define	D_SLOW_VALVE			0x08		/* motor valve slow position						*/

//*******************************************************************************
// Sub function (Input panel unit,object 0x6100-0x611F,Byte 1) if basic function is BRAKE_CHECK
//*******************************************************************************
#define	BRAKE1					0x01		// brake check input 1
#define	BRAKE2					0x02		// brake check input 2
#define	BRAKE3					0x04		// brake check input 3
#define	BRAKEWARNING			0x08		/* brake state warning								*/
#define	UP_VALVE				0x10		/* up valve supervising input						*/
#define	DOWN_VALVE1				0x20		/* down valve 1 supervising input					*/
#define	DOWN_VALVE2				0x40		/* down valve 2 supervising input					*/
#define	EMERG_IVALVE			0x80		/* emergency iValve supervising input				*/

//*******************************************************************************
// Sub function (Input panel unit,object 0x6100-0x611F,Byte 1) if basic function is TEMPERATURE
//*******************************************************************************
#define	OVERTEMP1				0x01		// motor overtemperature 1
#define	OVERTEMP2				0x02		// motor overtemperature 2
#define	ROOMTEMP_MIN			0x04		// machine room overtemperature minimum
#define	ROOMTEMP_MAX			0x08		// machine room overtemperature maximum
#define	WARNINGTEMP				0x10		// motor temperature warning level
#define	OILTEMP					0x20		/* oil temperature warning level					*/
#define	TEMP_ERROR				0xCF		/* temperature error bits							*/
#define	MOTORTEMP_ERROR			0x03		/* motor temperature error bits						*/
#define TEMP_SENSOR_MIN			0x40		/* temperature sensor min. limit					*/
#define TEMP_SENSOR_MAX			0x80		/* temperature sensor max. limit					*/

//*******************************************************************************
// Sub function (Input panel unit,object 0x6100-0x611F,Byte 1) if basic function is PRESSURE
//*******************************************************************************
#define	MINPRESS				0x01		// < minimal hydraulic pressure
#define	MAXPRESS				0x02		// > maximal hydraulic pressure

//*******************************************************************************
// Function data (Output panel unit, object 0x6200 to 0x621F, Byte 5)
//*******************************************************************************
#define	INDICATION_OFF			0x00		// indication is switched off
#define	INDICATION_ON			0x01		// indication is switched on

/************************************************************************************************/
/* Sub function if basic function is connected IO												*/
/************************************************************************************************/
#define	NORMAL_OUT				0x00		/* normal connected output							*/
#define	ON_DELAY_OUT			0x01		/* output with on delay								*/
#define	OFF_DELAY_OUT			0x02		/* output with off delay							*/
#define ON_OFF_DELAY_OUT		0x03		/* output with on and off delay						*/
#define	PULSE_OUT				0x04		/* pulse output										*/			
#define	BISTABLE				0x05		/* bistable output									*/			

//*******************************************************************************
// Sub function (Input panel unit, object 0x6100 to 0x611F, Byte 1) if basic function is 0x82
// (Door function inputs)
//*******************************************************************************
#define	CARDOOR_CONNECT				0x01
#define	SHAFTDOOR_CONNECT			0x02
#define	PHOTO_SENSOR						0x03
#define	DOOR_POSIOTION_MONITOR	0x04


//*******************************************************************************
// Bits in error register
//*******************************************************************************
#define	ER_GENERIC				0x01		// generic error
#define	ER_CURRENT				0x02		// current error
#define	ER_VOLTAGE				0x04		// voltage error
#define	ER_TEMPERATURE			0x08		// temperature error
#define	ER_COMMUNICATION		0x10		// communication error
#define	ER_DEVICE_PROFILE		0x20		// device profile specific error
#define	ER_MANUFACTURER			0x80		// manufacturer specific error

//*******************************************************************************
// Error code
//*******************************************************************************
#define	E_NO					0x0000 	/* Error Reset or No Error							*/
#define	E_GENERIC				0x1000 	/* Generic Error									*/
#define	E_POS_BAND					0x1001	/* positioning system error (ELGO system internal)	*/
#define	E_CURRENT				0x2000 	/* Current											*/
#define	E_POS_DEFECTIVE				0x2070	/* positioning system error (ELGO system internal)	*/
#define	E_INPUT_CURRENT			0x2100 	/* Current, device input side						*/
#define	E_CURRENT_INSIDE		0x2200 	/* Current inside the device						*/
#define	E_OUTPUT_CURRENT			0x2300 	/* Current, device output side						*/
#define	E_VOLTAGE				0x3000 	/* Voltage											*/

#define	E_LIGHT_VOLTAGE			0x3101		// Light Voltage
#define	E_INSIDE_VOLTAGE		0x3200		// Voltage inside the device
#define	E_OUTPUT_VOLTAGE		0x3300 	/* Output Voltage									*/
#define	E_SC_VOLTAGE			0x3400		// Safety Circuit Voltage
#define	E_SC_VOLTAGE_MOVE		0x3401		// Safety Circuit Voltage while moving
#define	E_SC_VOLTAGE_DOOR		0x3402		// Safety Circuit Voltage door
#define	E_SC_VOLTAGE_LIMIT		0x3403		// Safety Circuit Final limit switch
#define	E_SC_VOLTAGE_DRIVE		0x3404		// Drive error after safety circuit was off	on trip
#define	E_SC_VOLTAGE_BEAM		0x3405		// Safety circuit light beam while moving
#define	E_SC_BYPASS					0x3410  /* Error in safety bypass feedback (EN81-20)		*/
#define	E_SC_GEAR					0x3411  /* Safety circuit gear off							*/
#define	E_SC_SHAFTDOOR				0x3412	/* safety Circuit shaft door bypassed				*/
#define	E_SC_DOORTEST				0x3413	/* safety circuit door test not working				*/
#define	E_SC_REV_DOOR				0x3414	/* safety Circuit revolving door bypassed			*/
#define	E_RAMP_CONTACT				0x3415	/* ramp contact not closed							*/
#define	E_BATTERY_VOLTAGE		0x3500		// Battery not okay
#define	E_TEMPERATURE			0x4000 	/* Temperature										*/
#define	E_AMBIENT_TEMP			0x4100 	/* Ambient temperature								*/
#define	E_DEVICE_TEMP				0x4200 	/* Device temperature								*/
#define	E_MOTOR_TEMP1			0x4300		// Motor temperature 1
#define	E_MOTOR_TEMP2			0x4301		// Motor temperature 2
#define	E_ROOM_TEMP_MIN			0x4302		// Machine room temperature minimum
#define	E_ROOM_TEMP_MAX			0x4303		// Machine room temperature maximum
#define	E_PCB_TEMP_MIN				0x4304  /* PCB temperature sensor minimum limit				*/
#define	E_PCB_TEMP_MAX				0x4305  /* PCB temperature sensor maximum limit				*/
#define	E_DEVICE_HW					0x5000 	/* Device Hardware									*/
#define	E_HW_CODE				0x5001		// Wrong hardware code
#define	E_DEVICE_SW					0x6000 	/* Device Software									*/
#define	E_INTERNAL_SW			0x6100		// Internal Software
#define	E_SW_START				0x6101		// Normal software start
#define	E_BG_START				0x6102		// Restart PCB
#define	E_ASE_SW					0x6103	/* ASE software too old								*/
#define	E_FVE_SW					0x6104	/* FVE software too old								*/
#define	E_SW_RESET					0x6105  /* Software start by software reset					*/
#define	E_HW_RESET					0x6106  /* Software start by hardware reset					*/
#define	E_CALIBRATION				0x6200 	/* Load sensor not calibrate						*/
#define	E_ESE_PARA				0x6201		// ESE parameter are not the same inside a group
#define	E_DRIVE_PARA				0x6202 	/* Drive parameter are not the same like in EEPROM	*/
#define	E_DATE_SET				0x6300 	/* Data Set											*/
#define	E_ADD_MODULES			0x7000 	/* Additional Modules								*/
#define	E_MONITORING			0x8000 	/* Monitoring										*/
#define	E_SMS_ERROR					0x8000	/* General error while sending SMS or fax			*/
#define	E_SMS_NO_CARRIER			0x8003	/* No carrier while sending SMS or fax				*/
#define	E_SMS_NO_DIALTONE			0x8006	/* No dialtone while sending SMS or fax				*/
#define	E_SMS_BUSY					0x8007	/* Busy while sending SMS or fax					*/
#define	E_SMS_1_ERROR				0x8010	/* General error while sending SMS 1				*/
#define	E_SMS_1_NO_CARRIER			0x8013	/* No carrier while sending SMS 1					*/
#define	E_SMS_1_NO_DIALTONE			0x8016	/* No dialtone while sending SMS 1					*/
#define	E_SMS_1_BUSY				0x8017	/* Busy while sending SMS 1							*/
#define	E_SMS_2_ERROR				0x8020	/* General error while sending SMS 2				*/
#define	E_SMS_2_NO_CARRIER			0x8023	/* No carrier while sending SMS 2					*/
#define	E_SMS_2_NO_DIALTONE			0x8026	/* No dialtone while sending SMS 2					*/
#define	E_SMS_2_BUSY				0x8027	/* Busy while sending SMS 2							*/
#define	E_SMS_3_ERROR				0x8030	/* General error while sending SMS 3				*/
#define	E_SMS_3_NO_CARRIER			0x8033	/* No carrier while sending SMS 3					*/
#define	E_SMS_3_NO_DIALTONE			0x8036	/* No dialtone while sending SMS 3					*/
#define	E_SMS_3_BUSY				0x8037	/* Busy while sending SMS 3							*/
#define	E_FAX_1_ERROR				0x8040	/* General error while sending Fax 1				*/
#define	E_FAX_1_NO_CARRIER			0x8043	/* No carrier while sending Fax 1					*/
#define	E_FAX_1_NO_DIALTONE			0x8046	/* No dialtone while sending Fax 1					*/
#define	E_FAX_1_BUSY				0x8047	/* Busy while sending Fax 1							*/
#define	E_FAX_2_ERROR				0x8050	/* General error while sending Fax 2				*/
#define	E_FAX_2_NO_CARRIER			0x8053	/* No carrier while sending Fax 2					*/
#define	E_FAX_2_NO_DIALTONE			0x8056	/* No dialtone while sending Fax 2					*/
#define	E_FAX_2_BUSY				0x8057	/* Busy while sending Fax 2							*/
#define	E_PC_1_ERROR				0x8060	/* General error while sending message to PC1		*/
#define	E_PC_1_NO_CARRIER			0x8063	/* No carrier while sending message to PC1			*/
#define	E_PC_1_NO_DIALTONE			0x8066	/* No dialtone while sending message to PC1			*/
#define	E_PC_1_BUSY					0x8067	/* Busy while sending message to PC1				*/
#define	E_PC_2_ERROR				0x8060	/* General error while sending message to PC2		*/
#define	E_PC_2_NO_CARRIER			0x8063	/* No carrier while sending message to PC2			*/
#define	E_PC_2_NO_DIALTONE			0x8066	/* No dialtone while sending message to PC2			*/
#define	E_PC_2_BUSY					0x8067	/* Busy while sending message to PC2				*/
#define	E_COMMUNICATION			0x8100 	/* Communication									*/
#define	E_CAN_OVERRUN_A			0x8110		// CAN Overrun (Objects lost) (HSE CAN A)
#define	E_CAN_OV_SW_A			0x8111		// CAN Overrun (Objects lost) Software buffer CAN A
#define	E_CAN_OVERRUN_B			0x8112		// CAN Overrun (Objects lost) CAN B
#define	E_CAN_OV_SW_B			0x8113		// CAN Overrun (Objects lost) Software buffer CAN B
#define	E_CAN_RXCOUNT			0x8114		// CAN Rx counter error
#define	E_CAN_OVERRUN1				0x8115  /* CAN Overrun (Heartbeat lost) (HSE CAN A)			*/
#define	E_CAN_OVERRUN2				0x8116  /* CAN Overrun (SDO lost) (HSE CAN A)				*/
#define	E_CAN_OVERRUN3				0x8117  /* CAN Overrun (Position mesasage lost) (HSE CAN A)	*/
#define	E_CAN_OVERRUN_C			0x8118		// CAN Overrun(Objects lost) CAN C
#define	E_CAN_OV_SW_C			0x8119		// CAN Overrun(Objects lost) Software buffer CAN C
#define	E_CAN_PASSIVE_A			0x8120		// CAN in Error Passive Mode (HSE CAN A)
#define	E_CAN_PASSIVE_B			0x8121 	/* CAN in Error Passive Mode CAN B					*/
#define	E_CAN_PASSIVE_C			0x8122 	/* CAN in Error Passive Mode CAN B					*/
#define	E_HEARTBEAT				0x8130		// Life Guard Error or Heartbeat Error
#define	E_HEARTBEAT_CDU			0x8131		// Life Guard Error or Heartbeat Error HSE
#define	E_HEARTBEAT_DRV			0x8132		// CAN Tx software buffer overrun CAN C
#define	E_MANDATORY_ESE				0x8133  /* Heartbeat error of mandatory ESE					*/
#define	E_MANDATORY_TSE				0x8134  /* Heartbeat error of mandatory TSE					*/
#define	E_BUS_OFF_A				0x8140		// recovered from bus off (HSE CAN A)
#define	E_BUS_OFF_B				0x8141		// recovered from bus off CAN B
#define	E_BUS_OFF_C				0x8142		// recovered from bus off CAN C
#define	E_TCOB_ID				0x8150 	/* Transmit COB-ID									*/
#define	E_ERROR_BRANCH				0x8151	/* ESE error on branch 								*/
#define	E_BRANCH_OFF				0x8152	/* complete brunch off								*/
#define	E_LOCAL_ESE					0x8153	/* local HSE off									*/
#define	E_CAN_TX_A				0x8160		// CAN Tx error CAN A
#define	E_CAN_TX_SW_A			0x8161		// CAN Tx software buffer overrun CAN A
#define	E_CAN_TX_B				0x8162		// CAN Tx error CAN B
#define	E_CAN_TX_SW_B			0x8163		// CAN Tx software buffer overrun CAN B
#define	E_CAN_TSE				0x8164		// No CAN connection to TSE (car panel)
#define	E_CAN_SX_SW_A			0x8165		// CAN Sx software buffer overrun CAN A
#define	E_CAN_SX_SW_B			0x8166		// CAN Sx software buffer overrun CAN B
#define	E_CAN_SX_SW_C			0x8167		// CAN Sx software buffer overrun CAN C
#define	E_CAN_TX_C				0x8168		// CAN Tx error CAN C
#define	E_CAN_TX_SW_C		0x8169		// CAN Tx software buffer overrun CAN C
#define	E_CAN_EXE				0x8170		// No CAN connection to TSE (car panel)
#define	E_HEARTBEAT_EXE	0x8171		// Life Guard Error or Heartbeat Error EXE
#define	E_BRAKE_CHECK		0x8172		// 
#define	E_ASC0_OVERRUN				0x8180	/* ASC0 overrun										*/
#define	E_ASC0_BUFFER_OFFLINE		0x8181	/* ASC0 buffer error (offline state)				*/
#define	E_ASC0_BUFFER_ONLINE		0x8182	/* ASC0 buffer error (online state)					*/
#define	E_ASC0_RX_CRC_ERROR			0x8183	/* ASC0 receive CRC error							*/
#define	E_ASC1_OVERRUN				0x8190	/* ASC1 overrun										*/
#define	E_ASC1_BUFFER_OFFLINE		0x8191	/* ASC1 buffer error (offline state)				*/
#define	E_ASC1_BUFFER_ONLINE		0x8192	/* ASC1 buffer error (online state)					*/
#define	E_ASC1_RX_CRC_ERROR			0x8193	/* ASC1 receive CRC error							*/

#define	E_PROTOCOL				0x8200 	/* Protocol Error									*/
#define	E_PDO_LENGHT			0x8210 	/* PDO not processed due to length error			*/
#define	E_PDO_LENGHT_EX			0x8220 	/* PDO length exceeded								*/
#define	E_GROUPNUMBER			0x8230		// same group number HSE
#define	E_EXTERNAL				0x9000 	/* External Error									*/
#define	E_MIN_PRESSURE			0x9001		// Hydraulik min. pressure
#define	E_MAX_PRESSURE			0x9002		// Hydraulik max. pressure
#define	E_OVERLOADED				0x9010	/* Overload error									*/

#define	E_DRIVE					0xA000		// Drive Error
#define	E_DRIVE_MOVE			0xA100		// Drive Error: No movement while signals on
#define	E_DRIVE_NO_READY_SIG	0xA101		// Drive Error: No ready signal in specified time
#define	E_DRIVE_NO_BRAKE_SIG	0xA102		// Drive Error: No brake signal in specified time
#define	E_DRIVE_READY_SIG		0xA103		// Drive Error: Ready signal not off in time
#define	E_DRIVE_BRAKE_SIG		0xA104		// Drive Error: Brake signal not off in time
#define	E_DRIVE_MOVE_SIG		0xA105		// Drive Error: Move signal not off in time
#define	E_DRIVE_NO_READY_TRIP	0xA106		// Drive Error: No ready signal while moving
#define	E_DRIVE_NO_BRAKE_TRIP	0xA107		// Drive Error: No brake signal while moving
#define	E_DRIVE_NO_MOVE_TRIP	0xA108		// Drive Error: No move signal while moving
#define	E_RUNCONTACT_NOTON	0xA200		// Drive Error: Contactor not on
#define	E_RUNCONTACT_NOTOFF	0xA201		// Drive Error: Contactor not off
#define	E_BRAKE_NOTON		0xA300		// Drive Error: Brake not opened
#define	E_BRAKE_NOTOFF		0xA301		// Drive Error: Brake not closed
#define	E_DRIVE_BRAKE_WARNING	0xA302		// Drive Error: Brake warning state

#define	E_DRIVE_NO_SOFT_TRIP		0xA308  /* Drive Error: No softstart signal while moving	*/
#define	E_DRIVE_NO_SOFT_SIG			0xA309  /* Drive Error: No softstart signal in spec. time	*/
#define	E_DRIVE_READY_STILL			0xA30A  /* Drive Error: ready signal on in standstill		*/
#define	E_DRIVE_BRAKE_STILL			0xA30B  /* Drive Error: brake signal on in standstill		*/
#define	E_DRIVE_SOFTSTART_STILL		0xA30C  /* Drive Error: softstarter signal on in standstill	*/
#define	E_DRIVE_NO_SWITCHED_ON		0xA30D  /* Drive Error: No switched on message in time		*/
#define	E_DRIVE_NO_VOLT_ENABLED		0xA30E  /* Drive Error: No voltage enabled message in time	*/
#define	E_DRIVE_NO_RDY_TO_SW_ON		0xA30F  /* Drive Error: No Rdy. to switch on message in time*/
#define	E_DRIVE_NO_SPEED_ZERO		0xA310  /* Drive Error: No speed zero message in time		*/
#define	E_DRIVE_NO_OP_DISABLED		0xA311  /* Drive Error: No operat. disabled message in time	*/
#define	E_DRIVE_NO_RDY_TRIP			0xA312  /* Drive Error: No RDY signal while moving			*/
#define	E_DRIVE_RDY_STILL			0xA313  /* Drive Error: RDY signal on in standstill			*/
#define	E_DRIVE_RDY_SIG				0xA314  /* Drive Error: RDY signal not off					*/
#define	E_DRIVE_OP_DISABLED			0xA315  /* Drive Error: Operation disabled message timeout	*/
#define	E_DRIVE_OP_ENABLED			0xA316  /* Drive Error: Operation enabled message timeout	*/
#define	E_DRIVE_SPEED_ZERO			0xA317  /* Drive Error: Speed zero while moving				*/
#define	E_DRIVE_NO_TARGET_ACK		0xA318  /* Drive Error: No target ack. (position mode)		*/
#define	E_DRIVE_NO_CONTACTOR		0xA319  /* Drive Error: Contactor not on					*/
#define	E_DRIVE_CONTACTOR_ON		0xA31A  /* Drive Error: Contactor not off					*/
#define	E_DRIVE_NO_BRAKE			0xA31B  /* Drive Error: Brake not opened					*/
#define	E_DRIVE_NO_BRAKE_OFF		0xA31C  /* Drive Error: Brake not closed					*/
#define	E_DRIVE_NO_GOVERNOR			0xA31E  /* Drive Error: Governor not on						*/
#define	E_DRIVE_GOVERNOR			0xA31F  /* Drive Error: Governor not off					*/
#define	E_DRIVE_NO_VALVE			0xA320  /* Drive Error: Valve not opened					*/
#define	E_DRIVE_NO_VALVE_OFF		0xA321  /* Drive Error: Valve not closed					*/
#define	E_DRIVE_NO_VALVE1			0xA322  /* Drive Error: Valve not opened					*/
#define	E_DRIVE_NO_VALVE1_OFF		0xA323  /* Drive Error: Valve not closed					*/
#define	E_DRIVE_NO_VALVE2			0xA324  /* Drive Error: Valve not opened					*/
#define	E_DRIVE_NO_VALVE2_OFF		0xA325  /* Drive Error: Valve not closed					*/
#define	E_DRIVE_BRAKE_ON			0xA326  /* Drive Error: Brake opened while standstill		*/
#define	E_DRIVE_VALVE_ON			0xA327  /* Drive Error: Valve opened while standstill		*/
#define	E_DRIVE_VALVE1_ON			0xA328  /* Drive Error: Valve opened while standstill		*/
#define	E_DRIVE_VALVE2_ON			0xA329  /* Drive Error: Valve opened while standstill		*/
#define	E_DRIVE_NO_IVALVE			0xA32A  /* Drive Error: iValve not opened					*/
#define	E_DRIVE_NO_IVALVE_OFF		0xA32B  /* Drive Error: iValve not closed					*/
#define	E_BRAKE_ERROR1				0xA32C  /* Drive Error: Brake 1 cant hold the lift			*/
#define	E_BRAKE_ERROR2				0xA32D  /* Drive Error: Brake 2 cant hold the lift			*/
#define	E_BRAKE_ERROR3				0xA32E  /* Drive Error: Brake 3 cant hold the lift			*/

#define	E_LUST_CPU				0xA401		// Lust Drive Error: Hardware or software error
#define	E_LUST_OFF				0xA402		// Lust Drive Error: Power failure
#define	E_LUST_OC				0xA403		// Lust Drive Error: Over current
#define	E_LUST_OV				0xA404		// Lust Drive Error: Over voltage
#define	E_LUST_OLI				0xA405		// Lust Drive Error: I2t error
#define	E_LUST_OLM				0xA406		// Lust Drive Error: It	error
#define	E_LUST_OTM				0xA407		// Lust Drive Error: Overtemperature motor
#define	E_LUST_OTI				0xA408		// Lust Drive Error: Overtemperature VVVF
#define	E_LUST_PLS				0xA409		// Lust Drive Error: parameter plausibility
#define	E_LUST_PAR				0xA40A		// Lust Drive Error: parameter error
#define	E_LUST_FLT				0xA40B		// Lust Drive Error: floating point error
#define	E_LUST_PWR				0xA40C		// Lust Drive Error: unknown power unit
#define	E_LUST_EXT				0xA40D		// Lust Drive Error: external error
#define	E_LUST_USR				0xA40E		// Lust Drive Error: user software error
#define	E_LUST_OP1				0xA40F		// Lust Drive Error: error option module 1
#define	E_LUST_OP2				0xA410		// Lust Drive Error: error option module 2
#define	E_LUST_SIO				0xA412		// Lust Drive Error: error serial connection
#define	E_LUST_EEP				0xA413		// Lust Drive Error: EEPROM error
#define	E_LUST_WBK				0xA414		// Lust Drive Error: broken wire
#define	E_LUST_SC				0xA415		// Lust Drive Error: self init
#define	E_LUST_PF				0xA416		// Lust Drive Error: Power fail
#define	E_LUST_RM				0xA417		// Lust Drive Error: Init run mode
#define	E_LUST_ENC				0xA41E		// Lust Drive Error: Encoder error
#define	E_LUST_SLD				0xA429		// Lust Drive Error: Schleppfehler

#define	E_EM_AOC				0xA441		// EV3100E Error : E001 Acc overcurrent
#define	E_EM_DOC				0xA442		// EV3100E Error : E002 Dec overcurrent
#define	E_EM_RUNOC				0xA443		// EV3100E Error : E003 Constant speed running overcurrent
#define	E_EM_AOV				0xA444		// EV3100E Error : E004 Acc overvoltage
#define	E_EM_DOV				0xA445		// EV3100E Error : E005 Dec overvoltage
#define	E_EM_RUNOV				0xA446		// EV3100E Error : E006 Constant speed running overvoltage
#define	E_EM_POWOV				0xA447		// EV3100E Error : E007 Overvoltage of power supply
#define	E_EM_PHFIN				0xA448		// EV3100E Error : E008 Phase failure at input side
#define	E_EM_PHFOUT				0xA449		// EV3100E Error : E009 Phase failure at output side
#define	E_EM_POWF				0xA44A		// EV3100E Error : E010 Power module faulty
#define	E_EM_POWOH				0xA44B		// EV3100E Error : E011 Power module heatsink voerheated
#define	E_EM_RES1				0xA44C		// EV3100E Error : E012 Reserved
#define	E_EM_DRIOL				0xA44D		// EV3100E Error : E013 Drive overloaded
#define	E_EM_MOTOL				0xA44E		// EV3100E Error : E014 Moter overloaded
#define	E_EM_EXTFAU				0xA44F		// EV3100E Error : E015 External equipment fault
#define	E_EM_EEPR				0xA450		// EV3100E Error : E016	EEPROM read/write faulty
#define	E_EM_RS485ERR			0xA451		// EV3100E Error : E017	RS485 communication error
#define	E_EM_CONNCLO			0xA452		// EV3100E Error : E018	Contactor not closed
#define	E_EM_CFAU				0xA453		// EV3100E Error : E019	Current detecting circuit faulty
#define	E_EM_CPUFAU				0xA454		// EV3100E Error : E020 CPU faulty
#define	E_EM_RES2				0xA455		// EV3100E Error : E021 Reserved
#define	E_EM_RES3				0xA456		// EV3100E Error : E022 Reserved
#define	E_EM_KBEEPR				0xA457		// EV3100E Error : E023 Keyboard EEPROM R/W Error
#define	E_EM_TUNERR				0xA458		// EV3100E Error : E024 Tuning Error
#define	E_EM_PGFAU				0xA459		// EV3100E Error : E025 PG faulty
#define	E_EM_RES4				0xA45A		// EV3100E Error : E026 Reserved
#define	E_EM_BRAFAU				0xA45B		// EV3100E Error : E027 Brake unit faulty
#define	E_EM_PARSET				0xA45C		// EV3100E Error : E028	Parameter setting error
#define	E_EM_RES5				0xA45D		// EV3100E Error : E029 reserved
#define	E_EM_OVSPEED			0xA45E		// EV3100E Error : E030	overspeed
#define	E_EM_RES6				0xA45F		// EV3100E Error : E031 reserved
#define	E_EM_OVDISTANCE			0xA460		// EV3100E Error : E032 over distance of shaft
#define	E_EM_LEARNERR			0xA461		// EV3100E Error : E033 Error in learn the motor
#define	E_EM_RES7				0xA462		// EV3100E Error : E034 reserved
#define	E_EM_CBE				0xA463		// EV3100E Error ; E035	contactant KR2

#define	E_BASIC_SETTING			0xA500		// basic setting
#define	E_RESCUE					0xA501		// rescue
#define	E_EMOP_BTN_STICK			0xA502		// emergency recall up or down button stick
#define E_DL_SHORTED_CAR			0xA503
#define E_DL_SHORTED_HALL		0xA504

#define	E_NICE_RUN_NOTON			0xA601
#define	E_NICE_RUN_NOTOFF			0xA602
#define	E_NICE_BRAKE_NOTON		0xA603
#define	E_NICE_BRAKE_NOTOFF		0xA604
#define	E_NICE_MOVE_NOTON		0xA605
#define	E_NICE_MOVE_NOTOFF		0xA606
#define	E_FXCONTACT_NOTON		0xA607
#define	E_FXCONTACT_NOTOFF		0xA608
#define	E_BRKCONTACT_NOTON		0xA609
#define	E_BRKCONTACT_NOTOFF	0xA60A
#define	E_NICE_DIR_NOTON			0xA60B
#define	E_NICE_OVER_SPEED			0xA60C

#define	E_IV_ERROR				0xA700

#define	E_VO_DOORZONE			0xB001		// VO changed inside door zone
#define	E_VU_DOORZONE			0xB002		// VU changed inside door zone
#define	E_VO_VU_ERROR			0xB003		// state of VO and / or VU wrong
#define	E_SGM_OFF				0xB004		// SGM off, but positioning in level
#define	E_SGM_ON				0xB005		// SGM on, but positioning outside doorzone
#define	E_KH5_ON				0xB006		// KH5 not released
#define	E_KH5_OFF				0xB007		// KH5 not on
#define	E_STOP_TO_EARLY			0xB008		// Lift did stop too early (level zone not reached)
#define	E_STOP_TO_LATE			0xB009		// Lift did stop too late (level zone leaved)
#define	E_RELEV_SHORT			0xB00A		// Re-levelling too short
#define	E_RELEV_LONG			0xB00B		// Re-levelling too long
#define	E_RELEV_OVERSPEED		0xB00C		// overspeed while re-levelling
#define	E_OVERSPEED				0xB00D		// overspeed
#define	E_WRONG_DIR				0xB00E		// wrong travel direction
#define	E_FAST_VO				0xB00F		// lift is still fast on VO
#define	E_FAST_VU				0xB010		// lift is still fast on VU
#define	E_MAGNETCOUNT			0xB011		// Count error (positioning with magnet)
#define	E_SGV_IN_DZ				0xB012		// SGV in door zone (positioning with magnet)
#define	E_SGE_DOORZONE			0xB013		// SGE changed inside door zone
#define	E_SGE_ERROR				0xB014		// SGE on / off on wrong position
#define	E_SGM_ERROR				0xB015		// SGM interrupt error
#define	E_ILS_ERROR				0xB016		// inspection limit switch
#define	E_FAST_SDU1				0xB017
#define	E_FAST_SDU2				0xB018
#define	E_FAST_SDU3				0xB019
#define	E_FAST_SDD1				0xB01A
#define	E_FAST_SDD2				0xB01B
#define	E_FAST_SDD3				0xB01C
#define	E_DIVING_ERR			0xB01D
#define	E_RESET_TRIP			0xB01E

#define	E_SLICK_ERROR				0xB020  /* Slick between motor and car too big				*/
#define	E_HB_SAFETY					0xB021  /* No heartbeat from safety unit (AWG2)				*/
#define	E_SIGNAL_SAFETY				0xB022  /* Error output from safety unit (AWG2)				*/
#define	E_SHELTER_TOP				0xB023  /* Shelter in top of shaft open						*/
#define	E_SHELTER_BOT				0xB024  /* Shelter in bottom of shaft open					*/
#define	E_BEARER_TOP_OFF			0xB025  /* Bearer in top of shaft open is off				*/
#define	E_BEARER_TOP_ON				0xB026  /* Bearer in top of shaft open is on				*/
#define	E_BEARER_BOT_OFF			0xB027  /* Bearer in bottom of shaft open is off			*/
#define	E_BEARER_BOT_ON				0xB028  /* Bearer in bottom of shaft open is on				*/
#define	E_SHELTER					0xB029  /* Shelter in bottom and top of shaft open			*/
#define	E_APRON_OFF					0xB02A  /* Car apron is off									*/
#define	E_APRON_ON					0xB02B  /* Car apron is not off								*/
#define	E_INTERM_DOOR				0xB030  /* Intermediate door open while moving				*/
#define	E_POS_DIFF					0xB040  /* Difference too big while SGM is switching on/off	*/
#define	E_HOLD_OUT					0xB050	/* error while holding bolts out					*/
#define	E_HOLD_IN					0xB051	/* error while holding bolts in						*/
#define	E_HOLD_TRIP					0xB052	/* holding bolts out while moving					*/
#define	E_HOLD_ERROR				0xB053	/* holding bolts error								*/
#define	E_HOLD_REPUMP				0xB054	/* error while re-pumping							*/
#define	E_HOLD_REACHED				0xB055	/* holding position reached signal not off			*/
#define	E_HOLD_NO_REACHED			0xB056	/* holding reached signal not switched on			*/
#define	E_HOLD_TRIP_ERROR			0xB057	/* holding trip not possible						*/
#define	E_DIVING_ERROR				0xB058	/* diving not possible								*/
#define	E_OP_DEVICE_STATE			0xB070	/* state error of OP device (in and out signals)	*/
#define	E_OP_DEVICE_LOCK			0xB071	/* OP device ramp not on while starting				*/
#define	E_OP_DEVICE_OUT				0xB072	/* OP device not out in time						*/
#define	E_OP_DEVICE_IN				0xB073	/* OP device not in in time							*/
#define	E_OP_DEVICE_RAMP			0xB074	/* OP device ramp not out in time					*/
#define	E_OP_DEVICE_LOCKED			0xB075	/* OP device ramp not on in time					*/
#define	E_PALLET_HOOK				0xB078	/* Pallet hook timeout error						*/
#define	E_PALLET_LIMIT				0xB079	/* pallet is in final limit position				*/
#define	E_UNCONTR_MOVE				0xB080	/* Uncontrolled movement							*/
#define	E_UNCONTR_MOVE_IN			0xB081	/* Uncontrolled movement input not on				*/
#define	E_NO_DECELERATION			0xB083	/* No deceleration in final floors					*/
#define	E_DECELERATION_CIRCUIT		0xB084	/* Deceleration circuit not working					*/
#define	E_SOLIMAX_FLOORTAB			0xB090	/* SOLIMAX floortab not compared inside 5 min		*/
#define	E_SOLIMAX_INSPECTION		0xB091	/* SOLIMAX inspection signals wrong					*/
#define	E_SOLIMAX_RELAYTIME			0xB092	/* SOLIMAX relay test not finished					*/

#define	E_SAFETY_CHECK_TIME			0xB810	/* SHM Safety check time out						*/
#define	E_SAFETY_CHECK				0xB811	/* SHM Safety check error							*/

#define	E_GENERAL				0xC000  /* General errors									*/
#define	E_TRIP_TIME				0xC001		// Error trip time
#define	E_LIGHT_SCREEN			0xC002		// Light screen defect or car call misuse
#define	E_ALARM_CALL			0xC003		// Alarm call pressed
#define	E_PULL_PULLEY			0xC004		// pull pulley while no power
#define	E_RTCLOWPOWER			0xC005		// RTC battery low power
#define	E_LEAD_BAD				0xC006
#define	E_LEAD_LACK				0xC007
#define	E_LEAD_SPACE			0xC008
#define	E_ITI_TSE_NONEHEAD		0xC009
#define	E_ITI_TSE_MULTHEAD		0xC00A
#define	E_ITI_TSE_NONERESP		0xC00B
#define	E_ITI_ESE_NONEHEAD		0xC00C
#define	E_ITI_ESE_MULTHEAD		0xC00D
#define	E_ITI_ESE_NONERESP		0xC00E
#define	E_INSP_STICK			0xC00F
#define	E_MSI_NOTOFF			0xC010
#define	E_MSI_LEVING			0xC011
#define	E_UCMP_LOCK			0xC012

//#define	E_ADD_FUNCTIONS			0xF000 	/* Additional Functions								*/
#define	E_DEVICE_SPEC				0xFF00 	/* Device specific									*/

/************************************************************************************************/
/* Error code area device specific: Zetadyn VVVF												*/
/************************************************************************************************/
#define	E_DEVICE_ERROR				0xF000 	/* Device error filter mask							*/
#define	E_ZETADYN_ERROR				0xE000 	/* Ziehl-Abegg 3BF Error: Starting with 0xExxx		*/

#define	E_3BF_SERIAL_NO				0xE064 	/* Ziehl-Abegg 3BF Error 100: 						*/
#define	E_3BF_SYSTEM_ERROR			0xE065 	/* Ziehl-Abegg 3BF Error 101: 						*/
#define	E_3BF_CU_NO_ID				0xE06E	/* Ziehl-Abegg 3BF Error 110: 						*/
#define	E_3BF_CU_NO_ID1				0xE078 	/* Ziehl-Abegg 3BF Error 120: 						*/
#define	E_3BF_CUSH_NO_ID			0xE06F 	/* Ziehl-Abegg 3BF Error 111: 						*/
#define	E_3BF_CUEE_NO_ID			0xE071 	/* Ziehl-Abegg 3BF Error 113: 						*/
#define	E_3BF_CUEE_NO_ID1			0xE07B 	/* Ziehl-Abegg 3BF Error 123: 						*/
#define	E_3BF_SP_NO_ID				0xE073 	/* Ziehl-Abegg 3BF Error 115: 						*/
#define	E_3BF_SP_NO_ID1				0xE07D 	/* Ziehl-Abegg 3BF Error 125: 						*/
#define	E_3BF_PP_NO_ID				0xE074 	/* Ziehl-Abegg 3BF Error 116: 						*/
#define	E_3BF_PP_NO_ID1				0xE07E 	/* Ziehl-Abegg 3BF Error 126: 						*/
#define	E_3BF_MP_NO_ID				0xE075 	/* Ziehl-Abegg 3BF Error 117: 						*/
#define	E_3BF_MP_NO_ID1				0xE07F 	/* Ziehl-Abegg 3BF Error 127: 						*/
#define	E_3BF_CUSH_ID				0xE079 	/* Ziehl-Abegg 3BF Error 121: 						*/
#define	E_3BF_MP_IGBT				0xE08C 	/* Ziehl-Abegg 3BF Error 140: 						*/
#define	E_3BF_MP_TEMP_SENS			0xE08D 	/* Ziehl-Abegg 3BF Error 141: 						*/
#define	E_3BF_HW_CONFLICT			0xE096 	/* Ziehl-Abegg 3BF Error 150: 						*/
#define	E_3BF_NO_ANALOG_IN			0xE09B 	/* Ziehl-Abegg 3BF Error 155: 						*/
#define	E_3BF_CUMT					0xE0AE 	/* Ziehl-Abegg 3BF Error 174: 						*/
#define	E_3BF_UF_CTRL				0xE0B4 	/* Ziehl-Abegg 3BF Error 180: 						*/

#define	E_3BF_FINISH_INPUT			0xE0C8 	/* Ziehl-Abegg 3BF Error 200: 						*/
#define	E_3BF_MOT_TYPEPLATE			0xE0C9 	/* Ziehl-Abegg 3BF Error 201: 						*/
#define	E_3BF_MOT_TYPE				0xE0CA 	/* Ziehl-Abegg 3BF Error 202: 						*/
#define	E_3BF_N0					0xE0CB 	/* Ziehl-Abegg 3BF Error 203: 						*/
#define	E_3BF_N_3N					0xE0CC 	/* Ziehl-Abegg 3BF Error 204: 						*/
#define	E_3BF_DOUBLE_INPUT			0xE0CD 	/* Ziehl-Abegg 3BF Error 205: 						*/
#define	E_3BF_INPUT_BFR_BR			0xE0CF 	/* Ziehl-Abegg 3BF Error 207: 						*/
#define	E_3BF_DELAY_ACTIVE			0xE0D0 	/* Ziehl-Abegg 3BF Error 208: 						*/
#define	E_3BF_WRONG_ENC_TYPE		0xE0D2 	/* Ziehl-Abegg 3BF Error 210: 						*/
#define	E_3BF_NO_BIN_ENC			0xE0D3 	/* Ziehl-Abegg 3BF Error 211: 						*/
#define	E_3BF_WRONG_SM_DATA			0xE0DC 	/* Ziehl-Abegg 3BF Error 220: 						*/
#define	E_3BF_WRONG_ASM_DATA		0xE0DD 	/* Ziehl-Abegg 3BF Error 221: 						*/
#define	E_3BF_V_G1					0xE0E7 	/* Ziehl-Abegg 3BF Error 231: 						*/
#define	E_3BF_V_G2					0xE0E8 	/* Ziehl-Abegg 3BF Error 232: 						*/
#define	E_3BF_V_G3					0xE0E9 	/* Ziehl-Abegg 3BF Error 233: 						*/
#define	E_3BF_SLOW_DIST				0xE118 	/* Ziehl-Abegg 3BF Error 280: 						*/
#define	E_3BF_V_0					0xE11D 	/* Ziehl-Abegg 3BF Error 285: 						*/
#define	E_3BF_VX_V					0xE11F 	/* Ziehl-Abegg 3BF Error 287: 						*/
#define	E_3BF_V3_V					0xE120 	/* Ziehl-Abegg 3BF Error 288: 						*/
#define	E_3BF_V1_V2_V3				0xE121 	/* Ziehl-Abegg 3BF Error 289: 						*/
#define	E_3BF_PARA2					0xE122 	/* Ziehl-Abegg 3BF Error 290: 						*/

#define	E_3BF_MOP_TIMEOUT			0xE12D 	/* Ziehl-Abegg 3BF Error 301: 						*/
#define	E_3BF_MOP_SW_ERROR			0xE12F 	/* Ziehl-Abegg 3BF Error 303: 						*/
#define	E_3BF_MOP_HW_ERROR			0xE130 	/* Ziehl-Abegg 3BF Error 304: 						*/
#define	E_3BF_ADC_ERROR1			0xE131 	/* Ziehl-Abegg 3BF Error 305: 						*/
#define	E_3BF_ADC_ERROR2			0xE132 	/* Ziehl-Abegg 3BF Error 306: 						*/
#define	E_3BF_CURR_SENSOR			0xE133 	/* Ziehl-Abegg 3BF Error 307: 						*/
#define	E_3BF_IU_IV					0xE134 	/* Ziehl-Abegg 3BF Error 308: 						*/
#define	E_3BF_NO_AWG				0xE136 	/* Ziehl-Abegg 3BF Error 310: 						*/
#define	E_3BF_ENDAT_ERROR			0xE13B	/* Ziehl-Abegg 3BF Error 315: 						*/
#define	E_3BF_ENDAT_RES				0xE13C 	/* Ziehl-Abegg 3BF Error 316: 						*/
#define	E_3BF_ENC_START				0xE140 	/* Ziehl-Abegg 3BF Error 320: 						*/
#define	E_3BF_ENDAT_ULP				0xE141 	/* Ziehl-Abegg 3BF Error 321: 						*/
#define	E_3BF_ENDAT_COM				0xE142 	/* Ziehl-Abegg 3BF Error 322: 						*/
#define	E_3BF_SSI_ACK				0xE144 	/* Ziehl-Abegg 3BF Error 324: 						*/
#define	E_3BF_SSI_TIMEOUT			0xE145 	/* Ziehl-Abegg 3BF Error 325: 						*/
#define	E_3BF_ENC_READ				0xE147 	/* Ziehl-Abegg 3BF Error 327: 						*/
#define	E_3BF_ENC_COUNT				0xE148 	/* Ziehl-Abegg 3BF Error 328: 						*/
#define	E_3BF_ENC_SINUS_S			0xE149 	/* Ziehl-Abegg 3BF Error 329: 						*/
#define	E_3BF_ENC_SINUS_F			0xE14A 	/* Ziehl-Abegg 3BF Error 330: 						*/
#define	E_3BF_ENC_NDEF				0xE14B 	/* Ziehl-Abegg 3BF Error 331: 						*/
#define	E_3BF_ENC_CD0				0xE14C 	/* Ziehl-Abegg 3BF Error 332: 						*/
#define	E_3BF_ENC_ABS_VALUE			0xE174 	/* Ziehl-Abegg 3BF Error 372: 						*/
#define	E_3BF_ENC_ABS_ENDE			0xE175 	/* Ziehl-Abegg 3BF Error 373: 						*/
#define	E_3BF_P1P2					0xE176 	/* Ziehl-Abegg 3BF Error 374: 						*/
#define	E_3BF_MOT_TEMP				0xE177 	/* Ziehl-Abegg 3BF Error 375: 						*/
#define	E_3BF_BR_TEMP				0xE179 	/* Ziehl-Abegg 3BF Error 377: 						*/
#define	E_3BF_NO_MP					0xE17A 	/* Ziehl-Abegg 3BF Error 378: 						*/
#define	E_3BF_MP_TEMP				0xE17B 	/* Ziehl-Abegg 3BF Error 379: 						*/
#define	E_3BF_BR_START				0xE17C 	/* Ziehl-Abegg 3BF Error 380: 						*/
#define	E_3BF_MP_ERROR				0xE18B 	/* Ziehl-Abegg 3BF Error 395: 						*/
#define	E_3BF_ADC_CURRENT			0xE19A 	/* Ziehl-Abegg 3BF Error 410: 						*/
#define	E_3BF_MOT_UVW_OFF			0xE19C 	/* Ziehl-Abegg 3BF Error 412: 						*/
#define	E_3BF_MOT_UVW_CURR			0xE19F 	/* Ziehl-Abegg 3BF Error 415: 						*/
#define	E_3BF_MOT_TEMP_ALARM		0xE1A4 	/* Ziehl-Abegg 3BF Error 420: 						*/
#define	E_3BF_MP_PWM				0xE1AF 	/* Ziehl-Abegg 3BF Error 431: 						*/
#define	E_3BF_MP_OVERLOAD			0xE1C2 	/* Ziehl-Abegg 3BF Error 450: 						*/
#define	E_3BF_HY_OVERLOAD			0xE1CC 	/* Ziehl-Abegg 3BF Error 460: 						*/
#define	E_3BF_UDC_MIN				0xE1D6 	/* Ziehl-Abegg 3BF Error 470: 						*/
#define	E_3BF_UDC_MAX				0xE1D7 	/* Ziehl-Abegg 3BF Error 471: 						*/
#define	E_3BF_U_850					0xE1DB 	/* Ziehl-Abegg 3BF Error 475: 						*/
#define	E_3BF_MP_CURRENT			0xE1E0 	/* Ziehl-Abegg 3BF Error 480: 						*/
#define	E_3BF_MP_CURRENT_CO			0xE1E1 	/* Ziehl-Abegg 3BF Error 481: 						*/
#define	E_3BF_MP_CURRENT_BC			0xE1E4 	/* Ziehl-Abegg 3BF Error 484: 						*/
#define	E_3BF_MP_CURRENT_ZK			0xE1E5 	/* Ziehl-Abegg 3BF Error 485: 						*/
#define	E_3BF_MP_CURRENT_ZK_CO		0xE1E6 	/* Ziehl-Abegg 3BF Error 486: 						*/
#define	E_3BF_STO_MOP				0xE1E7 	/* Ziehl-Abegg 3BF Error 487: 						*/
#define	E_3BF_UCE_ALARM				0xE1EA 	/* Ziehl-Abegg 3BF Error 490: 						*/
#define	E_3BF_UCE_ALARM_CO			0xE1EB 	/* Ziehl-Abegg 3BF Error 491: 						*/
#define	E_3BF_MOVE_MB_OFF			0xE1F5 	/* Ziehl-Abegg 3BF Error 501: 						*/
#define	E_3BF_ENC_SIN_OFF			0xE1F6 	/* Ziehl-Abegg 3BF Error 502: 						*/
#define	E_3BF_NO_ENC				0xE1F7 	/* Ziehl-Abegg 3BF Error 503: 						*/
#define E_3BF_ENC_INTERRUPTED		0xE1F8	/* Ziehl-Abegg 3BF Error 504: 						*/
#define	E_3BF_MB_ENC				0xE1F9 	/* Ziehl-Abegg 3BF Error 505: 						*/
#define	E_3BF_V110					0xE203 	/* Ziehl-Abegg 3BF Error 515: 						*/
#define	E_3BF_V150					0xE204 	/* Ziehl-Abegg 3BF Error 516: 						*/
#define	E_3BF_N15					0xE206 	/* Ziehl-Abegg 3BF Error 518: 						*/
#define	E_3BF_N15_1					0xE207 	/* Ziehl-Abegg 3BF Error 519: 						*/
#define	E_3BF_WRONG_DIR				0xE208 	/* Ziehl-Abegg 3BF Error 520: 						*/
#define	E_3BF_ENC_POS_DIFF			0xE20A 	/* Ziehl-Abegg 3BF Error 522: 						*/
#define	E_3BF_ENC_NEG_DIFF			0xE20B 	/* Ziehl-Abegg 3BF Error 523: 						*/
#define	E_3BF_ADC_LIMIT				0xE20D 	/* Ziehl-Abegg 3BF Error 525: 						*/
#define	E_3BF_QUICKSTART			0xE211 	/* Ziehl-Abegg 3BF Error 529: 						*/
#define	E_3BF_STO_ENABLE			0xE212 	/* Ziehl-Abegg 3BF Error 530: 						*/
#define	E_3BF_STO_BREAK				0xE213 	/* Ziehl-Abegg 3BF Error 531: 						*/
#define	E_3BF_STO_OFF				0xE214 	/* Ziehl-Abegg 3BF Error 532: 						*/
#define	E_3BF_STO_FAULT				0xE215 	/* Ziehl-Abegg 3BF Error 533: 						*/
#define	E_3BF_STO_NO_SIG			0xE216 	/* Ziehl-Abegg 3BF Error 534: 						*/

#define	E_3BF_NO_CO					0xE21C 	/* Ziehl-Abegg 3BF Error 540: 						*/
#define	E_3BF_CO_V_ACTIVE			0xE220 	/* Ziehl-Abegg 3BF Error 544: 						*/
#define	E_3BF_CO_OFF				0xE221 	/* Ziehl-Abegg 3BF Error 545: 						*/
#define	E_3BF_CO_OFF_M				0xE222 	/* Ziehl-Abegg 3BF Error 546: 						*/
#define	E_3BF_CO1_ON				0xE224 	/* Ziehl-Abegg 3BF Error 548: 						*/
#define	E_3BF_CO12_ON				0xE225 	/* Ziehl-Abegg 3BF Error 549: 						*/
#define	E_3BF_OVERLOAD				0xE226 	/* Ziehl-Abegg 3BF Error 550: 						*/
#define	E_3BF_MOTOR_TEMP			0xE23F 	/* Ziehl-Abegg 3BF Error 575: 						*/
#define	E_3BF_BR_T2					0xE246 	/* Ziehl-Abegg 3BF Error 582: 						*/
#define	E_3BF_BR_MOVE				0xE247 	/* Ziehl-Abegg 3BF Error 583: 						*/
#define	E_3BF_BR_MOVE1				0xE248 	/* Ziehl-Abegg 3BF Error 584: 						*/
#define	E_3BF_BR_T5					0xE249 	/* Ziehl-Abegg 3BF Error 585: 						*/
#define	E_3BF_BR_STOP				0xE24A 	/* Ziehl-Abegg 3BF Error 586: 						*/
#define	E_3BF_RV1_RV2				0xE24E 	/* Ziehl-Abegg 3BF Error 590: 						*/
#define	E_3BF_TIME_QUICKSTART		0xE30C 	/* Ziehl-Abegg 3BF Error 780: Quickstart Timeout	*/
#define	E_3BF_QUICK_TRIP			0xE30D 	/* Ziehl-Abegg 3BF Error 781: Quickstart Trip		*/
#define	E_3BF_RF_OFF				0xE31F 	/* Ziehl-Abegg 3BF Error 799: 						*/

#define	E_3BF_TIMEOUT_HB			0xE320 	/* Ziehl-Abegg 3BF Error 800: No heartbeat from HSE	*/
#define	E_3BF_QUICK_STOP			0xE32A 	/* Ziehl-Abegg 3BF Error 810: Quick stop detected	*/
#define	E_3BF_ILLEGAL_STAT			0xE334 	/* Ziehl-Abegg 3BF Error 820: CAN: Illegal Status	*/
#define	E_3BF_TIMEOUT_EN_OP			0xE33E 	/* Ziehl-Abegg 3BF Error 830: Timeout Enable Op.	*/
#define	E_3BF_TIMEOUT_DIS_OP		0xE33F 	/* Ziehl-Abegg 3BF Error 831: Timeout Disable Op.	*/
#define	E_3BF_TIMEOUT_SHUTDOWN		0xE340 	/* Ziehl-Abegg 3BF Error 832: Timeout Shutdown		*/
#define	E_3BF_TIMEOUT_DIS_VOLT		0xE341 	/* Ziehl-Abegg 3BF Error 833: Timeout Dis. Voltage	*/
#define	E_3BF_NO_ENC_INFO			0xE348 	/* Ziehl-Abegg 3BF Error 840: No encoder info		*/

#define	E_3BF_HW_SW					0xE389  /* Ziehl-Abegg 3BF Error 905: 						*/
#define	E_3BF_PFU_BR				0xE38B  /* Ziehl-Abegg 3BF Error 907: 						*/
#define	E_3BF_PFU_FAULT				0xE38C  /* Ziehl-Abegg 3BF Error 908: 						*/
#define	E_3BF_PFU_ALARM				0xE38D  /* Ziehl-Abegg 3BF Error 909: 						*/
#define	E_3BF_BC_FAULT				0xE38E  /* Ziehl-Abegg 3BF Error 910: 						*/
#define	E_3BF_BR_OVERLOAD			0xE38F  /* Ziehl-Abegg 3BF Error 911: 						*/
#define	E_3BF_BC_ALARM				0xE390  /* Ziehl-Abegg 3BF Error 912: 						*/
#define	E_3BF_U_DC_U_BC				0xE391  /* Ziehl-Abegg 3BF Error 913: 						*/
#define	E_3BF_NO_X_ENC15			0xE392  /* Ziehl-Abegg 3BF Error 914: 						*/
#define	E_3BF_X_ENC15				0xE394  /* Ziehl-Abegg 3BF Error 916: 						*/
#define	E_3BF_BR_ACTIVE				0xE395  /* Ziehl-Abegg 3BF Error 917: 						*/
#define	E_3BF_MP_TEMP_FAIL			0xE396  /* Ziehl-Abegg 3BF Error 918: 						*/
#define	E_3BF_MOP_ACTIVE			0xE398  /* Ziehl-Abegg 3BF Error 920: 						*/
#define	E_3BF_UCE					0xE3A2  /* Ziehl-Abegg 3BF Error 930: 						*/
#define	E_3BF_MP_ERR_EXT			0xE3A3  /* Ziehl-Abegg 3BF Error 931: 						*/
#define	E_3BF_STO_DIAG				0xE3C0  /* Ziehl-Abegg 3BF Error 960: 						*/
#define	E_3BF_STO_HARDWARE			0xE3C1  /* Ziehl-Abegg 3BF Error 961: 						*/
#define	E_3BF_MOP_TIMEOUT2			0xE3E2  /* Ziehl-Abegg 3BF Error 994: 						*/
#define	E_3BF_ENC_LIMIT				0xE3E3  /* Ziehl-Abegg 3BF Error 995: 						*/

//*******************************************************************************
// Error code area device specific: Lust VVVF
//*******************************************************************************
#define	E_LUST					0xA400		// Lust VVVF uses error code area 0xA400-0xA4FF

//*******************************************************************************
// Error code device specific: Doors
// The door number is mapped into bit 8 - 11
//*******************************************************************************
#define	E_DOOR_CLOSING			0xF001		// Door time out while closing
#define	E_DOOR_OPENING			0xF002		// Door time out while opening
#define	E_DOOR_REV				0xF003		// Door time out while reopening
#define	E_DOOR_OP_SW			0xF004		// Door open switch off while door is opened
#define	E_DOOR_CL_SW			0xF005		// Door close switch off while door is closed
#define	E_DOOR_SC				0xF006		// safety circuit closed while door is open
#define	E_DOOR_NUDGING			0xF007		// nudging while light screen is interrupted
#define	E_DOOR_LS				0xF008		// light screen always interrupted
#define	E_DOOR_REV_IN			0xF009  	/* reversing input always interrupted				*/
#define	E_DOOR_OP_FLOOR			0xF00A  	/* door open switch in wrong floor (floor selected)	*/
#define	E_DOOR_LS_ERROR			0xF00B  	/* light screen error signal						*/

//*******************************************************************************
// Error code device specific: Doors
// With door number mapped into bit 8 - 11
//*******************************************************************************
#define	E_DOOR_CLOSING_1		0xF101		// Door time out while closing
#define	E_DOOR_OPENING_1		0xF102		// Door time out while opening
#define	E_DOOR_REV_1			0xF103		// Door time out while reopening
#define	E_DOOR_OP_SW_1			0xF104		// Door open switch off while door is opened
#define	E_DOOR_CL_SW_1			0xF105		// Door close switch off while door is closed
#define	E_DOOR_SC_1				0xF106		// safety circuit closed while door is open
#define	E_DOOR_NUDGING_1		0xF107		// nudging while light screen is interrupted
#define	E_DOOR_LS_1				0xF108		// light screen always interrupted
#define	E_DOOR_REV_IN_1			0xF109  	/* reversing input always interrupted				*/
#define	E_DOOR_OP_FLOOR_1		0xF10A  	/* door open switch in wrong floor (floor selected)	*/
#define	E_DOOR_LS_ERROR_1		0xF10B  	/* light screen error signal						*/
#define	E_DOOR_CLOSING_2		0xF201		// Door time out while closing
#define	E_DOOR_OPENING_2		0xF202		// Door time out while opening
#define	E_DOOR_REV_2			0xF203		// Door time out while reopening
#define	E_DOOR_OP_SW_2			0xF204		// Door open switch off while door is opened
#define	E_DOOR_CL_SW_2			0xF205		// Door close switch off while door is closed
#define	E_DOOR_SC_2				0xF206		// safety circuit closed while door is open
#define	E_DOOR_NUDGING_2		0xF207		// nudging while light screen is interrupted
#define	E_DOOR_LS_2				0xF208		// light screen always interrupted
#define	E_DOOR_REV_IN_2			0xF209  	/* reversing input always interrupted				*/
#define	E_DOOR_OP_FLOOR_2		0xF20A  	/* door open switch in wrong floor (floor selected)	*/
#define	E_DOOR_LS_ERROR_2		0xF20B  	/* light screen error signal						*/
#define	E_DOOR_CLOSING_3		0xF301		// Door time out while closing
#define	E_DOOR_OPENING_3		0xF302		// Door time out while opening
#define	E_DOOR_REV_3			0xF303		// Door time out while reopening
#define	E_DOOR_OP_SW_3			0xF304		// Door open switch off while door is opened
#define	E_DOOR_CL_SW_3			0xF305		// Door close switch off while door is closed
#define	E_DOOR_SC_3				0xF306		// safety circuit closed while door is open
#define	E_DOOR_NUDGING_3		0xF307		// nudging while light screen is interrupted
#define	E_DOOR_LS_3				0xF308		// light screen always interrupted
#define	E_DOOR_REV_IN_3			0xF309  	/* reversing input always interrupted				*/
#define	E_DOOR_OP_FLOOR_3		0xF30A  	/* door open switch in wrong floor (floor selected)	*/
#define	E_DOOR_LS_ERROR_3		0xF30B  	/* light screen error signal						*/

//*******************************************************************************
// Door command
//*******************************************************************************
#define	CLOSE_DOOR				0x00		// Close door without limit force
#define	CLOSE_DOOR_L			0x10		// Close door with limit force
#define	CLOSE_DOOR_LS		0x20		// Close door with limit force and slow speed
#define	OPEN_DOOR				0x30		// Open door without limit force
#define	OPEN_DOOR_L				0x40		// Open door with limit force
#define	CLOSE_DOOR_NUDGING		0x50		/* Close door with nudging (reduced speed)			*/
#define	STOP_DOOR				0x70		// Stop door without limit force
#define	STOP_DOOR_L				0x80		// Stop door with limit force
#define	REV_DOOR				0x90		// reopen door
#define	RESET_DOOR				0xE0		// Reset door
#define	TEACH_DOOR				0xD0		/* Teach-in											*/
#define	DOOR_OFF				0xF0		// Do not care / take no action

//*******************************************************************************
// Door state
//*******************************************************************************
#define	DOOR_CLOSED				0x0000		// Door is closed
#define	DOOR_CLOSED_NO_TORQUE	0x1000		/* Door is closed without torque					*/
#define DOOR_CLOSING			0x2000		/* Door is closing									*/
#define DOOR_CLOSE_DELAY		0x2100		/* Door is delayed closing (not CANopen conform)	*/
#define DOOR_NUDGING			0x2200		/* Door is nudging (not CANopen conform)			*/
#define	DOOR_OPENED				0x3000		// Door is opened
#define	DOOR_OPENED_NO_TORQUE	0x4000		/* Door is opened									*/
#define	DOOR_OPENING			0x5000		// Door is opening
#define DOOR_OPEN_DELAY			0x5100		/* Door is delayed opening (not CANopen conform)	*/
#define	DOOR_CLOSING			0x2000		// Door is closing
#define	DOOR_REVERSE			0x6000		// Door is reversing
#define DOOR_RE_OPENED			0x6100		/* Door is re-opened (not CANopen conform)			*/
#define	DOOR_STOPPED			0x7000		// Door is stopped
#define DOOR_STOPPED_NO_TORQUE	0x8000		/* Door is stopped without torque					*/
#define DOOR_TEACH_IN			0xD000		/* Door is in teach in state						*/
#define	DOOR_ERROR				0xE000		// Door is in error state

/************************************************************************************************/
/* Light screen state																			*/
/************************************************************************************************/
#define	LS_NOT_INSTALLED		0x80		/* light screen not available / not installed		*/
#define	LS_INTERRUPTED			0x40		/* light screen interrupted							*/

/************************************************************************************************/
/* Drive control type 																			*/
/************************************************************************************************/
#define	POSITION_MODE				1		/* Drive position mode								*/
#define	VELOCITY_MODE				3		/* Drive velocity mode								*/


//*******************************************************************************
// Drive command (state machine according to DSP402)
//*******************************************************************************
#define	DRV_SHUTDOWN			0x0006		// shutdown drive (mains contactors switched on)
#define	DRV_SWITCH_ON			0x0007		// switch on drive (brake released)
#define	DRV_ENABLE_OPERATION	0x000F		// enable operation	(start moving)
#define	DRV_DISABLE_OPERATION	0x0007		// disable operation (brake switched off)
#define	DRV_DISABLE_VOLTAGE		0x0000		// disable voltage (mains contactors switched off)

#define	DB_SWITCH_ON			0x0001		/* bit 0: switch on									*/
#define	DRV_QUICK_STOP			0x0002		// quick stop
#define	DRV_FAULT_RESET			0x0080		// fault reset
#define	DB_ENABLE_VOLTAGE		0x0002		// bit: enable voltage
#define	DB_NO_QUICK_STOP		0x0004		/* bit 2: quick stop								*/
#define	DB_ENABLE_OPERATION		0x0008		/* bit 3: enable operation							*/
#define	DB_NEW_SET_POINT		0x0010		/* bit 4: new set point (only position mode)		*/
#define	DB_CHANGE_SET_POINT		0x0020		/* bit 5: change set immediately (only pos. mode)	*/
#define	DB_RELATIVE				0x0040		/* bit 6: target position relative instead of abs.	*/
#define	DB_FAULT_RESET			0x0080		/* bit 7: fault reset								*/
																		/* bit 8...10 defined by CANopen drive				*/
																		/* bit 11...13 manufacture specific					*/
#define	DB_MAIN_CONT			0x0800		/* bit 11: main contactor							*/
#define	DB_STAR_DELTA			0x1000		/* bit 12: Delta contactor							*/
#define	DB_EM_OP_SPEED			0x4000		/* bit 14: Emergency recall operation				*/
#define	DB_INSP_SPEED			0x8000		/* bit 15: Inspection								*/

//*******************************************************************************
// Drive status (state machine according to DSP402)
//*******************************************************************************
#define	DRV_NOT_READY_TO_ON		0x0000		// not ready to switch on
#define	DRV_SWITCH_ON_DISABLED	0x0040		// switch on disabled (stopped state)
#define	DRV_READY_TO_SWITCH_ON	0x0021		// ready to switch on
#define	DRV_SWITCHED_ON			0x0023		// switched on (ready to open brake)			
#define	DRV_OPERATION_ENABLED	0x0027		// operation enabled, (moving state)
#define	DRV_QUICK_STOP_ACTIVE	0x0007		// quick stop active
#define	DRV_FAULT_REACTION		0x000F		// fault reaction
#define	DRV_FAULT				0x0008		// fault state

#define	DB_READY_TO_SWITCH_ON	0x0001		// bit: ready to switch on
#define	DB_SWITCHED_ON			0x0002		// bit: switched on
#define	DB_OPERATION_ENABLED	0x0004		// bit: operation enabled
#define	DB_FAULT				0x0008		// bit: fault
#define	DB_VOLTAGE_ENABLED		0x0010		/* bit  4: voltage enabled							*/
#define	DB_QUICK_STOP			0x0020		/* bit  5: quick stop								*/
#define	DB_SWITCH_ON_DISABLED	0x0040		/* bit  6: switch on disabled						*/
#define	DB_WARNING				0x0080		/* bit  7: warning									*/
#define	DB_RDY					0x0100		/* bit  8: RDY										*/
#define	DB_REMOTE				0x0200		/* bit  9: remote									*/
#define	DB_SPEED_ZERO			0x1000		// bit: speed = 0
#define	DB_TARGET_REACHED		0x0400		// bit: target speed / position reached
#define	DB_INTERNAL_LIMIT		0x0800		/* bit 11: internal limit active					*/
#define	DB_SPEED_ZERO			0x1000		/* bit 12: speed = 0 (velocity mode)				*/
#define	DB_TARGET_ACK			0x1000		/* bit 12: setpoint acknowledge (position mode)		*/
#define	DB_OP_MODE_SPECIFIC		0x2000		/* bit 13: operation mode specific					*/
#define	DB_MANUFACTURER			0xC100		/* bit 8, 14, 15: manufacturer specific				*/

//*******************************************************************************
// Loadtype type
//*******************************************************************************
#define NONE_LOAD					0xFF
#define ANALOG_ON_CDU			0
#define DIGIT_LOAD_CDU			1
#define ANALOG_ON_MCU			2
#define DIGIT_LOAD_MCU			3
#define NORMAL_LOAD_OTHER	4

//*******************************************************************************
// arrow mode
//*******************************************************************************
#define ARROW_SCROLL		0
#define ARROW_FLASH			1
#define ARROW_STATIC		2

/************************************************************************************************/
/* Definition for MPDO																			*/
/************************************************************************************************/
//Virtual terminal
#define	CTRL_A				0x0001
#define	CTRL_D				0x0004
#define	MPDO_DESTINATION		0x80		/* MPDO destination address mode					*/

//define Light function code
#define	HALL_LANTERN_UP 	0x01
#define	HALL_LANTERN_DN 	0x02
#define	DIRECTION_IND_UP 	0x04
#define	DIRECTION_IND_DN 	0x08
//#define	EMERGENCY_LIGHT	0x10		// emergency light output
#define	FIRE_LIGHT			 	0x20	
#define	ACCESS_LIGHT			0x30
#define	CDOOR_LIGHT 			0x40
#define	HDOOR_LIGHT 			0x50

//define gong function code
#define	BUZZER_UP					0x01
#define	BUZZER_DN 				0x02
#define	BUZZER_FIRE				0x04
#define	BUZZER_LEVELING		0x08
#define	BUZZER_NORMAL			0x10

//鸣叫的类型
#define	SPEEKER_CONTINUE	0
#define	SPEEKER_PAUSE			1
#endif

