#ifndef _DISPLAY_H_
#define	_DISPLAY_H_

//?¡§??????
#define	A_BETR		37
#define CHAR_N	23
#define CHAR_C		12
#define NO_FLOOR				85
#define NO_ARROW			NO_FLOOR
#define	DIRECTION_UP		86
#define	DIRECTION_DN		87
#define NUM_TEST_DATA	90

#define	THREE_FLOOR_NUM	47
#define	STANDER_FLOOR_NUM	38

#define SEG__	 	0x00	//??????
#define SEG_G2		0x80	//A??????
#define SEG_B		0x40	//B??????
#define SEG_J3		0x20	//C??????
#define SEG_A2		0x10	//D??????
#define SEG_J2		0x08	//E??????
#define SEG_A1		0x04	//F??????
#define SEG_J1		0x02	//G??????
#define SEG_F		0x01	//H??????

#define SEG_G1		0x8000	//J??????
#define SEG_E		0x4000	//K??????
#define SEG_K1		0x2000	//L??????
#define SEG_D1		0x1000	//M??????
#define SEG_K2		0x800	//N??????
#define SEG_D2		0x400	//R??????
#define SEG_K3		0x200	//P??????
#define SEG_C		0x100	//Q??????

#define	SEG_T1		0x80	//S10??????
#define	SEG_T2		0x40	//S10??????
#define	SEG_T3		0x20	//S10??????
#define	SEG_T4		0x10	//S10??????
#define	SEG_T5		0x08	//S10??????

#define	MAX_FLOOR	40

//????¡Á???????????????
//0--9 ??????¡Á???   	A     		A2		B		C		D2		D1			E		F		G1		G2		J1		J2		J3  	K1      K2      K3
#define Char0		(SEG_A1 + SEG_A2 + SEG_B + SEG_C + SEG_D2 + SEG_D1 + SEG_E + SEG_F + SEG__ +  SEG__ +  SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define	Char1_LEFT	(SEG__  + SEG__  + SEG__ + SEG__ + SEG__  + SEG__ + SEG_E + SEG_F + SEG__ +  SEG__ +  SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define	Char1_RIGHT (SEG__  + SEG__ + SEG_B + SEG_C + SEG__  + SEG__ + SEG__ + SEG__ + SEG__ +  SEG__ +  SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define Char2		(SEG_A1 + SEG_A2 + SEG_B + SEG__ + SEG_D2 + SEG_D1 + SEG_E + SEG__ + SEG_G1 + SEG_G2 + SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define Char3		(SEG_A1 + SEG_A2 + SEG_B + SEG_C + SEG_D2 + SEG_D1 + SEG__ + SEG__ + SEG_G1 + SEG_G2 + SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define Char4		(SEG__ +  SEG__  + SEG_B + SEG_C + SEG__  + SEG__  + SEG__ + SEG_F + SEG_G1 + SEG_G2 + SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define Char5		(SEG_A1 + SEG_A2 + SEG__ + SEG_C + SEG_D2 + SEG_D1 + SEG__ + SEG_F + SEG_G1 + SEG_G2 + SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define Char6		(SEG_A1 + SEG_A2 + SEG__ + SEG_C + SEG_D2 + SEG_D1 + SEG_E + SEG_F + SEG_G1 + SEG_G2 + SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define Char7		(SEG_A1 + SEG_A2 + SEG_B + SEG_C + SEG__  + SEG__  + SEG__ + SEG__ + SEG__  +  SEG__ +  SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define Char8		(SEG_A1 + SEG_A2 + SEG_B + SEG_C + SEG_D2 + SEG_D1 + SEG_E + SEG_F + SEG_G1 + SEG_G2 + SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define Char9		(SEG_A1 + SEG_A2 + SEG_B + SEG_C + SEG_D2 + SEG_D1 + SEG__ + SEG_F + SEG_G1 + SEG_G2 + SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
//??????¡Á???
#define Char10	(SEG__  + SEG_A2 + SEG_B + SEG_C + SEG_D2 + SEG__  + SEG_E + SEG_F + SEG__  +  SEG__ + SEG__ + SEG_J2 + SEG__ + SEG__ + SEG_K2 + SEG__)
#define Char11	(SEG__  + SEG__  + SEG_B + SEG_C + SEG__  + SEG__  + SEG_E + SEG_F + SEG__  +  SEG__ +  SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define	Char12	(SEG__  + SEG_A2 + SEG_B + SEG__ + SEG_D2  + SEG__  + SEG_E + SEG_F + SEG__  + SEG_G2 + SEG__ + SEG__ + SEG__ + SEG__ + SEG_K2 + SEG__)
#define Char13	(SEG__ +  SEG_A2 + SEG_B + SEG_C + SEG_D2 + SEG__  + SEG_E + SEG_F  + SEG__ +  SEG_G2 + SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define Char14	(SEG__ +  SEG__  + SEG_B + SEG_C + SEG__  +  SEG__  + SEG_E + SEG_F  + SEG__ +  SEG_G2 + SEG__ + SEG_J2 + SEG__ + SEG__ + SEG__ + SEG__)
#define Char15	(SEG__ +  SEG_A2 + SEG__ + SEG_C + SEG_D2  + SEG__  + SEG_E + SEG_F  + SEG__ +  SEG_G2 + SEG__ + SEG_J2 + SEG__ + SEG__ + SEG__ + SEG__)
#define Char16	(SEG__ +  SEG_A2 + SEG__ + SEG_C + SEG_D2  + SEG__  + SEG_E + SEG_F  + SEG__ +  SEG_G2 + SEG__ + SEG_J2 + SEG__ + SEG__ + SEG_K2 + SEG__)
#define Char17	(SEG__ +  SEG_A2 + SEG_B + SEG_C + SEG__   + SEG__  + SEG_E + SEG_F  + SEG__ +  SEG__  + SEG__ + SEG__  + SEG__ + SEG__ + SEG__ + SEG__)
#define Char18	(SEG__ +  SEG_A2 + SEG_B + SEG_C + SEG_D2  + SEG__  + SEG_E + SEG_F  + SEG__ +  SEG_G2 + SEG__ + SEG_J2 + SEG__ + SEG__ + SEG_K2 + SEG__)
#define Char19	(SEG__ +  SEG_A2 + SEG_B + SEG_C + SEG_D2  + SEG__  + SEG_E + SEG_F  + SEG__ +  SEG_G2 + SEG__ + SEG_J2 + SEG__ + SEG__ + SEG__ + SEG__)
#define Char21	(SEG_A1  + SEG__  + SEG_B + SEG_C + SEG__  + SEG_D1  + SEG_E + SEG__ + SEG_G1 + SEG__ +  SEG__ + SEG_J2 + SEG__ + SEG__ + SEG__ + SEG__)
#define Char31	(SEG_A1  + SEG__  + SEG_B + SEG_C + SEG__  + SEG_D1  + SEG__ + SEG__ + SEG_G1 + SEG__ +  SEG__ + SEG_J2 + SEG__ + SEG__ + SEG_K2 + SEG__)
#define Char41	(SEG__   + SEG__  + SEG_B + SEG_C + SEG__  + SEG__   + SEG__ + SEG_F + SEG_G1 + SEG__ +  SEG__ + SEG_J2 + SEG__ + SEG__ + SEG_K2 + SEG__)
#define Char51	(SEG_A1  + SEG__  + SEG_B + SEG_C + SEG__  + SEG_D1  + SEG__ + SEG_F + SEG_G1 + SEG__ +  SEG__ + SEG__ + SEG__ + SEG__ + SEG_K2 + SEG__)
#define Char61	(SEG_A1  + SEG__  + SEG_B + SEG_C + SEG__  + SEG_D1  + SEG_E + SEG_F + SEG_G1 + SEG__ +  SEG__ + SEG__ + SEG__ + SEG__ + SEG_K2 + SEG__)
#define Char71	(SEG_A1  + SEG__  + SEG_B + SEG_C + SEG__  + SEG__  + SEG__ +  SEG__ + SEG__  +  SEG__ +  SEG__ + SEG_J2 + SEG__ + SEG__ + SEG__ + SEG__)
#define Char81	(SEG_A1  + SEG__  + SEG_B + SEG_C + SEG__  + SEG_D1  + SEG_E + SEG_F + SEG_G1 + SEG__ +  SEG__ + SEG_J2 + SEG__ + SEG__ + SEG_K2 + SEG__)
#define Char91	(SEG_A1  + SEG__  + SEG_B + SEG_C + SEG__  + SEG_D1  + SEG__ + SEG_F + SEG_G1 + SEG__ +  SEG__ + SEG_J2 + SEG__ + SEG__ + SEG_K2 + SEG__)

//¡Á?????????
#define CharA	(SEG_A1 + SEG_A2 + SEG_B  + SEG_C + SEG__ +  SEG__  +  SEG_E + SEG_F + SEG_G1 + SEG_G2 + SEG__ + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define	CharB	(SEG_A1 + SEG_A2 + SEG_B  + SEG_C + SEG_D2 + SEG_D1 +  SEG__ + SEG__ + SEG__  + SEG_G2 + SEG__ + SEG_J2 + SEG__ + SEG__ + SEG_K2 + SEG__)
#define CharC	(SEG_A1 + SEG_A2 + SEG__  + SEG__ + SEG_D2 + SEG_D1 +  SEG_E + SEG_F + SEG__  + SEG__  + SEG__  + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define	CharD	(SEG_A1 + SEG_A2 + SEG_B  + SEG_C + SEG_D2 + SEG_D1 +  SEG__ + SEG__ + SEG__  + SEG__  + SEG__  + SEG_J2 + SEG__ + SEG__ + SEG_K2 + SEG__)
#define CharE		(SEG_A1 + SEG_A2 + SEG__  + SEG__ + SEG_D2 + SEG_D1 +  SEG_E + SEG_F + SEG_G1 + SEG_G2 + SEG__  + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define CharF		(SEG_A1 + SEG_A2 + SEG__  + SEG__ + SEG__  + SEG__  +  SEG_E + SEG_F + SEG_G1 + SEG_G2 + SEG__  + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define CharG	(SEG_A1 + SEG_A2 + SEG__  + SEG_C + SEG_D2 + SEG_D1 + SEG_E + SEG_F  + SEG__  + SEG_G2 + SEG__  + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define CharH	(SEG__  + SEG__  + SEG_B  + SEG_C + SEG__  + SEG__  + SEG_E + SEG_F  + SEG_G1 + SEG_G2 + SEG__  + SEG__ + SEG__ + SEG__ + SEG__ + SEG__)
#define	CharI		(SEG_A1 + SEG_A2 + SEG__  + SEG__ + SEG_D2 + SEG_D1 + SEG__ + SEG__  + SEG__  + SEG__  + SEG__  + SEG_J2 + SEG__ + SEG__ + SEG__ + SEG_K2)
#define	CharJ		(SEG_A1 + SEG_A2 + SEG__  + SEG__ + SEG__  + SEG_D1 + SEG__ + SEG__  + SEG__  + SEG__  + SEG__  + SEG_J2 + SEG__ + SEG__ + SEG__ + SEG_K2)
#define	CharK	(SEG__  + SEG__  + SEG__  + SEG__ + SEG__  + SEG__  + SEG__  + SEG__ + SEG__  + SEG__  + SEG__  + SEG_J2 + SEG_J3 + SEG__ + SEG_K3 + SEG_K2)
#define CharL		(SEG__  + SEG__  + SEG__  + SEG__ + SEG_D2 + SEG_D1 + SEG_E  + SEG_F + SEG__  + SEG__ + SEG__   + SEG__  + SEG__ + SEG__ + SEG__ + SEG__)
#define CharM	(SEG__  + SEG__  + SEG_B  + SEG_C + SEG__  + SEG__  + SEG_E + SEG_F + SEG__  +  SEG__ + SEG_J1  + SEG__  + SEG_J3 + SEG__ + SEG__ + SEG__)
#define CharN	(SEG__  + SEG__  + SEG_B  + SEG_C + SEG__  + SEG__  + SEG_E + SEG_F + SEG__  +  SEG__ + SEG_J1  + SEG__  + SEG__ + SEG__ + SEG_K3 + SEG__)
#define CharO	(SEG_A1 + SEG_A2 + SEG_B  + SEG_C + SEG_D2 + SEG_D1 + SEG_E + SEG_F + SEG__  +  SEG__ + SEG__  + SEG__  + SEG__ + SEG__ + SEG__ + SEG__)
#define CharP		(SEG_A1 + SEG_A2 + SEG_B  + SEG__ + SEG__  + SEG__  + SEG_E  + SEG_F + SEG_G1 + SEG_G2 + SEG__ + SEG__  + SEG__ + SEG__ + SEG__ + SEG__)
#define CharQ	(SEG_A1 + SEG_A2 + SEG_B  + SEG_C + SEG__  + SEG__  + SEG__  + SEG_F + SEG_G1 + SEG_G2 + SEG__ + SEG__  + SEG__ + SEG__ + SEG__ + SEG__)
#define CharR	(SEG_A1 + SEG_A2 + SEG__  + SEG__ + SEG__  + SEG__  + SEG_E  + SEG_F + SEG_G1 +  SEG__ + SEG__ + SEG__  + SEG_J3 + SEG__ + SEG_K3 + SEG__)
#define	CharS		(SEG_A1 + SEG_A2 + SEG__  + SEG__ + SEG_D2 + SEG_D1 + SEG__  + SEG__ + SEG__  +  SEG__ + SEG_J1 + SEG__  + SEG__ + SEG__ + SEG_K3 + SEG__)
#define CharT		(SEG_A1 + SEG_A2 + SEG__  + SEG__  + SEG__  + SEG__  + SEG__ + SEG__ + SEG__  +  SEG__ + SEG__  + SEG_J2 + SEG__ + SEG__ + SEG__  + SEG_K2)
#define CharU 	(SEG__  + SEG__  + SEG_B  + SEG_C + SEG_D2 + SEG_D1 + SEG_E + SEG_F + SEG__  +  SEG__ + SEG__  + SEG__  + SEG__ + SEG__ + SEG__  + SEG__)
#define CharV 	(SEG__  + SEG__  + SEG_B  + SEG_C + SEG_D2 + SEG_D1 + SEG_E + SEG_F + SEG__  +  SEG__ + SEG__  + SEG__  + SEG__ + SEG__ + SEG__  + SEG__)
#define CharW	(SEG__  + SEG__  + SEG_B  + SEG_C + SEG_D2 + SEG_D1 + SEG_E + SEG_F + SEG__  +  SEG__ + SEG__  + SEG_J2  + SEG__ + SEG__ + SEG__  + SEG_K2)
#define CharX 	(SEG__  + SEG__  + SEG__  + SEG__ + SEG__   +  SEG__ + SEG__ + SEG__ + SEG__  +  SEG__ + SEG_J1 + SEG__  + SEG_J3 + SEG_K1 + SEG_K3 + SEG__)
#define CharY 	(SEG__  + SEG__  + SEG__  + SEG__ + SEG__   + SEG__  + SEG__ + SEG__ + SEG__  +  SEG__ + SEG_J1 + SEG__  + SEG_J3 + SEG__  + SEG__  + SEG_K2)
#define CharZ 	(SEG_A1 + SEG_A2 + SEG__  + SEG__ + SEG_D2  + SEG_D1 + SEG__ + SEG__ + SEG__  +  SEG__ + SEG__ + SEG__  + SEG_J3 + SEG_K1 + SEG__  + SEG__)
#define	Char_Add (SEG__ + SEG__  + SEG__  + SEG__ + SEG__   + SEG__  + SEG__ + SEG__ + SEG_G1 +  SEG_G2 + SEG__ + SEG_J2 + SEG__ + SEG__  + SEG__  + SEG_K2)
#define	Char_Sub (SEG__ + SEG__  + SEG__  + SEG__ + SEG__   + SEG__  + SEG__ + SEG__ + SEG_G1 +  SEG_G2 + SEG__ + SEG__  + SEG__ + SEG__  + SEG__  + SEG__)

#define	Char_PARK			SEG_T5
#define	Char_FULL			SEG_T4
#define	Char_ArrowUp		(SEG_T3 + SEG_T2)
#define	Char_ArrowDown	(SEG_T2 + SEG_T1)
#define	Char_ArrowAll 	(SEG_T3 + SEG_T2 + SEG_T1)


#define	PARK	0x01
#define	FULL			0x02

#define	BUF_ARROW		0
#define	BUF_TEN		    1
#define	BUF_UNIT		2
#define	BUF_MESSAGE		3


#ifdef _DISPLAY_C_
//?¡§????????¡À???


BYTE	volatile		display [4];
	//[0]: Arrow
	//[1]: ten
	//[2]: unit
	//[3]: message

BYTE const tDisp_FloorAscii[] = {//?¨´????????ASCII??
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z', '+', '-',
//??????3???????¨²??
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
	'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
	'u', 'v', 'w', 'x', 'y', 'z', '!', '#', '$', '%',
	'&', '(', ')', '*', 0x27,',', ':', ';', '<', '>',
	'=', '@', '[', ']', '{', '}', '|', 0x00,
//	! #  $	%  &	(  )	*  '	,  :	;  <	>  =	@  [	]  {	}  |
};

WORD const	tFloor_Tab[] = {//??¡À¨ª???? LED ??¡Á???¡À¨ª????
//	Char0,		Char1_LEFT , Char2,	Char3,		Char4,		Char5,		Char6,			Char7,		Char8,		Char9,		//0-9
	Char0,		Char1_RIGHT,Char2, Char3,	Char4,		Char5,		Char6,			Char7,		Char8,		Char9,		//0-9
	CharA,		CharB,		CharC,		CharD,		CharE,		CharF,		CharG,			CharH,		CharI,		CharJ,		//10-19
	CharK, 	CharL,		CharM,		CharN,		CharO,		CharP,		CharQ,			CharR,		CharS,		CharT,		//20-29
	CharU,		CharV, 	CharW,		CharX,		CharY,		CharZ,		Char_Add, 	Char_Sub,									//30-37
///3??????
	Char10,		Char11,		Char12,		Char13,		Char14,		Char15,		Char16,			Char17,		Char18,		Char19,		//38-47
	SEG__, 	Char21, 	SEG__, 	SEG__, 	SEG__, 	SEG__, 	SEG__, 		SEG__, 	SEG__, 	SEG__, 	//48-57
	SEG__,	Char31, 	SEG__,	SEG__,	SEG__,	SEG__,	SEG__,		SEG__,	SEG__,	SEG__, 	//58-67
	SEG__,	Char41, 	SEG__,	SEG__,	SEG__,	SEG__,	SEG__,		SEG__,	SEG__,	SEG__, 	//68-77
	SEG__,	Char51, 	SEG__,	SEG__,	SEG__,	SEG__,	SEG__,		SEG__,									//78-85
//???¨°????
	Char_ArrowUp,	Char_ArrowDown,																													//86-87
//¡Á???????
	Char_FULL, Char_PARK, 																															//88-89
//??????????
	SEG_A1,		SEG_A2,		SEG_B,	SEG_C,		SEG_D2,	SEG_D1,	SEG_E,	SEG_F,	SEG_G1,	SEG_G2,	SEG_J1,	//90??????????????
	SEG_J2,		SEG_J3,		SEG_K3,	SEG_K2,		SEG_K1,
	SEG_A1,		SEG_A2,		SEG_B,	SEG_C,		SEG_D2,	SEG_D1,	SEG_E,	SEG_F,	SEG_G1,	SEG_G2,	SEG_J1,
	SEG_J2,		SEG_J3,		SEG_K3,	SEG_K2,		SEG_K1,
	Char_ArrowUp,	Char_ArrowDown,	Char_FULL,	Char_PARK,	Char_ArrowAll,0xFFFF,
};

BYTE const sign[][7] = {
	0b11101110, 	// 0
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,
	0b11101110,

	0b11101000, 	// 1
	0b11101100,
	0b11101010,
	0b11101000,
	0b11101000,
	0b11101000,
	0b11101000,

	0b11101110, 	// 2
	0b11110001,
	0b11110000,
	0b11101000,
	0b11100100,
	0b11100010,
	0b11111111,

	0b11101110, 	// 3
	0b11110001,
	0b11110000,
	0b11101100,
	0b11110000,
	0b11110001,
	0b11101110,

	0b11101000, 	// 4
	0b11100100,
	0b11101010,
	0b11101001,
	0b11111111,
	0b11101000,
	0b11101000,

	0b11111111, 	// 5
	0b11100001,
	0b11101111,
	0b11110000,
	0b11110000,
	0b11110001,
	0b11101110,

	0b11101110, 	// 6
	0b11110001,
	0b11100001,
	0b11101111,
	0b11110001,
	0b11110001,
	0b11101110,

	0b11111111, 	// 7
	0b11110000,
	0b11101000,
	0b11100100,
	0b11100010,
	0b11100010,
	0b11100010,

	0b11101110, 	// 8
	0b11110001,
	0b11110001,
	0b11101110,
	0b11110001,
	0b11110001,
	0b11101110,

	0b11101110, 	// 9
	0b11110001,
	0b11110001,
	0b11111110,
	0b11110000,
	0b11110001,
	0b11101110,

	0b11101110, 	// A--10
	0b11110001,
	0b11110001,
	0b11111111,
	0b11110001,
	0b11110001,
	0b11110001,

	0b11101111, 	// B--11
	0b11110001,
	0b11110001,
	0b11101111,
	0b11110001,
	0b11110001,
	0b11101111,

	0b11101110, 	// C--12
	0b11110001,
	0b11100001,
	0b11100001,
	0b11100001,
	0b11110001,
	0b11101110,

	0b11101111, 	// D--13
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,
	0b11101111,

	0b11111111, 	// E--14
	0b11100001,
	0b11100001,
	0b11101111,
	0b11100001,
	0b11100001,
	0b11111111,

	0b11111111, 	// F--15
	0b11100001,
	0b11100001,
	0b11101111,
	0b11100001,
	0b11100001,
	0b11100001,

	0b11101110, 	// G--16
	0b11110001,
	0b11100001,
	0b11111101,
	0b11110001,
	0b11110001,
	0b11101110,

	0b11110001, 	// H--17
	0b11110001,
	0b11110001,
	0b11111111,
	0b11110001,
	0b11110001,
	0b11110001,

	0b11100100, 	// I--18
	0b11100100,
	0b11100100,
	0b11100100,
	0b11100100,
	0b11100100,
	0b11100100,

	0b11111111, 	// J--19
	0b11101000,
	0b11101000,
	0b11101000,
	0b11101000,
	0b11101001,
	0b11100110,

	0b11110001, 	// K--20
	0b11101001,
	0b11100101,
	0b11100011,
	0b11100101,
	0b11101001,
	0b11110001,

	0b11100001, 	// L--21
	0b11100001,
	0b11100001,
	0b11100001,
	0b11100001,
	0b11100001,
	0b11111111,

	0b11110001, 	// M--22
	0b11111011,
	0b11110101,
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,

	0b11110001, 	// N--23
	0b11110001,
	0b11110011,
	0b11110101,
	0b11111001,
	0b11110001,
	0b11110001,

	0b11101110, 	// O--24
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,
	0b11101110,

	0b11101111, 	// P--25
	0b11110001,
	0b11110001,
	0b11101111,
	0b11100001,
	0b11100001,
	0b11100001,

	0b11101110, 	// Q--26
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110101,
	0b11111001,
	0b11101110,

	0b11101111, 	// R--27
	0b11110001,
	0b11110001,
	0b11101111,
	0b11100101,
	0b11101001,
	0b11110001,

	0b11101110, 	// S--28
	0b11110001,
	0b11100001,
	0b11101110,
	0b11110000,
	0b11110001,
	0b11101110,

	0b11111111, 	// T--29
	0b11100100,
	0b11100100,
	0b11100100,
	0b11100100,
	0b11100100,
	0b11100100,

	0b11110001, 	// U--30
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,
	0b11101110,

	0b11110001, 	// V--31
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,
	0b11101010,
	0b11100100,

	0b11110001, 	// W--32
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110101,
	0b11101010,

	0b11110001, 	// X--33
	0b11110001,
	0b11101010,
	0b11100100,
	0b11101010,
	0b11110001,
	0b11110001,

	0b11110001, 	// Y--34
	0b11110001,
	0b11101010,
	0b11100100,
	0b11100100,
	0b11100100,
	0b11100100,

	0b11111111, 	// Z--35
	0b11110000,
	0b11101000,
	0b11100100,
	0b11100010,
	0b11100001,
	0b11111111,

	0b11100000, 	// +--36
	0b11100100,
	0b11100100,
	0b11111111,
	0b11100100,
	0b11100100,
	0b11100000,

	0b11100000, 	// -	--37
	0b11100000,
	0b11100000,
	0b11111111,
	0b11100000,
	0b11100000,
	0b11100000,

//??????3??????
	0b11111101, 	// 10	--38
	0b11110101,
	0b11110101,
	0b11110101,
	0b11110101,
	0b11110101,
	0b11111101,

	0b11110010, 	// 11	--39
	0b11110010,
	0b11110010,
	0b11110010,
	0b11110010,
	0b11110010,
	0b11110010,

	0b11111101, 	// 12	--40
	0b11110001,
	0b11110001,
	0b11111101,
	0b11100101,
	0b11100101,
	0b11111101,

	0b11111101, 	// 13	--41
	0b11110001,
	0b11110001,
	0b11111101,
	0b11110001,
	0b11110001,
	0b11111101,

	0b11110101, 	// 14	--42
	0b11110101,
	0b11110101,
	0b11111101,
	0b11110001,
	0b11110001,
	0b11110001,

	0b11111101, 	// 15	--43
	0b11100101,
	0b11100101,
	0b11111101,
	0b11110001,
	0b11110001,
	0b11111101,

	0b11111101, 	// 16	--44
	0b11100101,
	0b11100101,
	0b11111101,
	0b11110101,
	0b11110101,
	0b11111101,

	0b11111101, 	// 17	--45
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,
	0b11110001,

	0b11111101, 	// 18	--46
	0b11110101,
	0b11110101,
	0b11111101,
	0b11110101,
	0b11110101,
	0b11111101,

	0b11111101, 	// 19	--47
	0b11110101,
	0b11110101,
	0b11111101,
	0b11110001,
	0b11110001,
	0b11111101,

	0b11100000, 	// 20	--48(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11110111, 	// 21	--49
	0b11110100,
	0b11110100,
	0b11110111,
	0b11110001,
	0b11110001,
	0b11110111,

	0b11100000, 	// 22	--50(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 23	--51(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 24	--52(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 25	--53(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 26	--54(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 27	--55(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 28	--56(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 29	--57(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 30	--58(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11110111, 	// 31	--59
	0b11110100,
	0b11110100,
	0b11110111,
	0b11110100,
	0b11110100,
	0b11110111,

	0b11100000, 	// 32	--60(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 33	--61(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 34	--62(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 35 --	63(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 36	--64(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 37	--65(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 38	--66(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 39	--67(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 40	--68(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11110101, 	// 41	--69
	0b11110101,
	0b11110101,
	0b11110111,
	0b11110100,
	0b11110100,
	0b11110100,

	0b11100000, 	// 42	--70(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 43	--71(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 44	--72(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 45	--73(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 46	--74(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 47	--75(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 48	--76(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 49	--77(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 50	--78(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11110111, 	// 51	--79
	0b11110001,
	0b11110001,
	0b11110111,
	0b11110100,
	0b11110100,
	0b11110111,

	0b11100000, 	// 52	--80(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 53	--81(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 54	--82(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 55	--83(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// 56	--84(????????)
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// Spa	--85
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100100, 	// arr up	--86
	0b11101110,
	0b11110101,
	0b11100100,
	0b11100100,
	0b11100100,
	0b11100100,

	0b11100100, 	// arr dn	--87
	0b11100100,
	0b11100100,
	0b11100100,
	0b11110101,
	0b11101110,
	0b11100100,

	0b11100000, 	// no	--88
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000, 	// no --89
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

//??????????????
	0b11111111,		// 90
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000,		// 91
	0b11111111,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000,		// 92
	0b11100000,
	0b11111111,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000,		// 93
	0b11100000,
	0b11100000,
	0b11111111,
	0b11100000,
	0b11100000,
	0b11100000,

	0b11100000,		// 94
	0b11100000,
	0b11100000,
	0b11100000,
	0b11111111,
	0b11100000,
	0b11100000,

	0b11100000,		// 95
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11111111,
	0b11100000,

	0b11100000,		// 96
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11100000,
	0b11111111,

	0b11110000,		// 97
	0b11110000,
	0b11110000,
	0b11110000,
	0b11110000,
	0b11110000,
	0b11110000,

	0b11101000,		// 98
	0b11101000,
	0b11101000,
	0b11101000,
	0b11101000,
	0b11101000,
	0b11101000,

	0b11100100,		// 99
	0b11100100,
	0b11100100,
	0b11100100,
	0b11100100,
	0b11100100,
	0b11100100,

	0b11100010,		// 100
	0b11100010,
	0b11100010,
	0b11100010,
	0b11100010,
	0b11100010,
	0b11100010,

	0b11100001,		// 101
	0b11100001,
	0b11100001,
	0b11100001,
	0b11100001,
	0b11100001,
	0b11100001,

	0b11111111,		// 102
	0b11111111,
	0b11111111,
	0b11111111,
	0b11111111,
	0b11111111,
	0b11111111,
};


/************************************************************************************************/
/* display for test mode																		*/
/************************************************************************************************/
BYTE const testdisplay[][3] = {
	90, 90, 90,
	91, 91, 91,
	92, 92, 92,
	93, 93, 93,
	94, 94, 94,
	95, 95, 95,
	96, 96, 96,
	97, 97, 97,
	98, 98, 98,
	99, 99, 99,
	100, 100, 100,
	101, 101, 101,
	102, 102, 102,
	103, 103, 103,
	69, 66, 73,
	66, 60, 69,
	60, 60, 66,
	60, 60, 60,
	60, 60, 60,
	85, 49, 63,
	85, 49, 63,
	85, 49, 63,
	85, 49, 63,
	69, 71, 63,
	69, 71, 63,
	70, 49, 63,
	70, 49, 63,
	70, 50, 63,
	70, 50, 63,
	70, 51, 63,
	70, 51, 63,
	70, 52, 63,
	70, 52, 63,
	70, 53, 63,
	70, 53, 63,
	70, 54, 63,
	70, 54, 63,
	70, 54, 62,
	70, 54, 62,
	70, 54, 62,
	70, 54, 62,
	70, 54, 64,
	70, 54, 64,
	70, 54, 64,
	70, 54, 64,
	70, 53, 64,
	70, 53, 64,
	70, 52, 64,
	70, 52, 64,
	70, 51, 64,
	70, 51, 64,
	70, 50, 64,
	70, 50, 64,
	70, 49, 64,
	70, 49, 64,
	69, 71, 64,
	69, 71, 64,
	85, 49, 64,
	85, 49, 64,
	61, 61, 62,
	61, 61, 62,
	60, 60, 70,
	60, 70, 69,
	70, 69, 85,
	69, 85, 69,
	85, 69, 82,
	69, 82, 87,
	82, 87, 69,
	87, 69, 72,
	69, 72, 82,
	72, 82, 70,
	82, 70, 65,
	70, 65, 72,
	65, 72, 82,
	72, 82, 84,
	82, 84, 60,
	84, 60, 60,
	60, 60, 60,
	60, 60, 60,
	60, 60, 60
};

void init_SPI(void);
BYTE SPI_SendOneByte(BYTE dat);
void Display_test(void);
void TestMode(void);
void read_switch(void);


#else
extern	BYTE	volatile		display [];
extern	BYTE const tDisp_FloorAscii[];
extern	WORD const	tFloor_Tab[];
extern	BYTE const sign[][7];

extern	void init_SPI(void);
extern	BYTE SPI_SendOneByte(BYTE dat);
extern	void Display_test(void);
extern	void TestMode(void);
extern	void SetNodeId(void);
extern	void KeyScan(void);
extern	void KeyProg(const BYTE value);
extern	void check_key_buttom(void);
extern	void key_buttom_output(void);
extern	void peak_led_out(void);

#endif
#endif

