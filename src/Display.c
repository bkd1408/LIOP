
#define	_DISPLAY_C_
#include	"AllHeader.h"

void init_SPI(void){
	SSPCON1 = 0x32;		//master mode , clock=Fosc/64 = 250k
	SSPSTAT = 0x00;
}

BYTE SPI_SendOneByte(BYTE dat){
	BYTE i;
	for(i=0; i<8; i++)
		{
			LATCbits.LATC7 = bit_select(dat, 7);
			dat <<= 1;
		
			LATCbits.LATC6 = 1;
			Nop();Nop();Nop();Nop();Nop();Nop();
			Nop();Nop();Nop();Nop();Nop();
			LATCbits.LATC6 = 0;
		}
	return dat;
}

/************************************************************************************************/
/* 	Set node ID												                        			*/
/************************************************************************************************/
void SetNodeId(void){
	static BYTE buffer[3] = {0,0,0};

	if ((disp_id != node_id) || (setid_mode_old != setid_mode))
		{
			if ((setid_mode == 1) || (setid_mode == 4))
				{//手工设置
					display[BUF_ARROW] = NO_ARROW;
					display[BUF_MESSAGE] = 0;
					if (node_id >= ESE_ID && node_id < ESE_ID + MAX_ESE)
						{
							display[BUF_TEN] = (((node_id - ESE_ID + 1) / 10) % 10);
							display[BUF_UNIT] = ((node_id - ESE_ID + 1) % 10);
							if ((node_id - ESE_ID + 1) >= 100)
								{
									if(hardware_version == G_741_LCD)
										display[BUF_ARROW] = DIRECTION_UP;
									else
										display[BUF_ARROW] = '1' - '0';
								}
						}
					else
						{
							display[BUF_TEN] = A_BETR;
							display[BUF_UNIT] = A_BETR;
						}
				}
			else
				{
					display[BUF_ARROW] = id_buff[BUF_ARROW];
					display[BUF_TEN] = id_buff[BUF_TEN] - '0';
					display[BUF_UNIT] = id_buff[BUF_UNIT] - '0';					
					display[BUF_MESSAGE] = 0;
				}
			disp_id = node_id;
			setid_mode_old = setid_mode;
			buffer[BUF_ARROW] = display[BUF_ARROW];
			buffer[BUF_TEN] = display[BUF_TEN];
			buffer[BUF_UNIT] = display[BUF_UNIT];
		}

	if (!flashtimer)
		{			
			INTCONbits.TMR0IE = 0;
			flashtimer = 3;
			if ((display[BUF_ARROW] != NO_ARROW) || (display[BUF_TEN] != NO_ARROW) || (display[BUF_UNIT] != NO_ARROW))
				{
					display[BUF_ARROW] = NO_ARROW;
					display[BUF_TEN] = NO_ARROW;
					display[BUF_UNIT] = NO_ARROW;
					display[BUF_MESSAGE] = 0;
				}
			else
				{
					display[BUF_ARROW] = buffer[BUF_ARROW];
					display[BUF_TEN] = buffer[BUF_TEN];
					display[BUF_UNIT] = buffer[BUF_UNIT];
					display[BUF_MESSAGE] = 0;
				}			
			INTCONbits.TMR0IE = 1;
		}			
}

/************************************************************************************************/
/* 	PCB test mode											                        			*/
/************************************************************************************************/
void TestMode(void){
	BYTE i;
	static BYTE oldin = 0;

	if(timer_1S5)
		{
			if (PORTCbits.RC4)
				{//测试版本号
					if(hardware_version == G_741_LCD)
						{
							display[BUF_TEN] = version_uea_G741[1] - '0';
							display[BUF_UNIT] = version_uea_G741[3] - '0';
						}
					else
						{
							display[BUF_TEN] = version_uea_G742[1] - '0';
							display[BUF_UNIT] = version_uea_G742[3] - '0';
						}						
					display[BUF_ARROW] = NO_ARROW;
					scroll = 0;
					display_timer = 10;
				}
			if (!display_timer)
				Display_test();
			if (in != oldin)
				{
					if ((in & 0x0f) != 0x0f)
						{
							for (i=0; i<4; ++i)
								{
									if (in & (1 << i))
										{
											PIE1bits.TMR1IE	= 0;
											scroll = 0;
											display_timer = 10;
											out = 1 << i;
											switch(i)
												{
													case 0:
														display[BUF_ARROW] = DIRECTION_UP;
														display[BUF_TEN] = 'U' - '7';
														display[BUF_UNIT] = 'P' - '7';
														break;
														
													case 1:
														display[BUF_ARROW] = DIRECTION_DN;
														display[BUF_TEN] = 'D' - '7';
														display[BUF_UNIT] = 'N' - '7';
														break;
														
													case 2:
														display[BUF_ARROW] = NO_ARROW;
														display[BUF_TEN] = 'F' - '7';
														display[BUF_UNIT] = 'F' - '7';
														out = 8;
														break;
														
													case 3:
														display[BUF_ARROW] = NO_ARROW;
														display[BUF_TEN] = 'L' - '7';
														display[BUF_UNIT] = 'L' - '7';
														out = 4;
														break;
												}
											PIE1bits.TMR1IE	= 1;
										}
									else
										{
											if(i < 2)
												bit_reset(out, i);
											else if(i == 2)
												bit_reset(out, 3);
											else
												bit_reset(out, 2);
										}
								}
						}
					oldin = in;
				}
			timer_1S5 = 0;
		}
}

void Display_test(void){
	BYTE number = 0;
	BYTE buf[4];

	if(hardware_version == G_741_LCD)
		number = 37;
	else
		number = 13;
	
	PIE1bits.TMR1IE = 0;
	if(testno < number)
		{
			if(hardware_version == G_741_LCD)
				{
					buf[BUF_ARROW] = NO_ARROW;
					buf[BUF_TEN] = NO_FLOOR;
					buf[BUF_UNIT] = NO_FLOOR;
					buf[BUF_MESSAGE] = 0;
					
					if(testno < 32)
						buf[(testno / 16) + 1] = NUM_TEST_DATA + testno;
					else if(testno < 34)
						buf[BUF_ARROW] = NUM_TEST_DATA + testno - 32;
					else if(testno < 36)
						buf[BUF_MESSAGE] = tFloor_Tab[88 + testno - 34];
					if (testno == number - 1)
						{//最后一个，显示全部
							buf[BUF_ARROW] = NUM_TEST_DATA + testno;
							buf[BUF_TEN] = NUM_TEST_DATA + testno + 1;
							buf[BUF_UNIT] = NUM_TEST_DATA + testno + 1;
							buf[BUF_MESSAGE] = Char_FULL + Char_PARK;
						}
					display[BUF_TEN] = buf[BUF_TEN];
					display[BUF_UNIT] = buf[BUF_UNIT];
					display[BUF_ARROW] = buf[BUF_ARROW];
					display[BUF_MESSAGE] = buf[BUF_MESSAGE];
				}
			else
				{
					display[BUF_ARROW] = testdisplay[testno][2];
					display[BUF_TEN] = testdisplay[testno][0];
					display[BUF_UNIT] = testdisplay[testno][1];
				}
			if (testno == number - 1)
				display_timer = 10;
		}
	else if(testno < number + 64)
		{
			if(testno % 3)
				{
					display[BUF_ARROW] = DIRECTION_UP;
					scroll = 1;
				}
			else
				{
					display[BUF_ARROW] = NO_ARROW;
					scroll = 0;
				}
	
			display[BUF_TEN] = ((testno - number) / 10);
			display[BUF_UNIT] = ((testno - number) % 10);
			if(display[BUF_TEN] == 0)
				display[BUF_TEN] = NO_FLOOR;
		}
	else if(testno < number + 64 + 64)
		{
			if(testno % 3)
				{
					display[BUF_ARROW] = DIRECTION_DN;
					scroll = 2;
				}
			else
				{
					display[BUF_ARROW] = NO_ARROW;
					scroll = 0;
				}
	
			display[BUF_TEN] = ((64 - (testno - number - 64)) / 10);
			display[BUF_UNIT] = ((64 - (testno - number - 64)) % 10);
			if(display[BUF_TEN] == 0)
				display[BUF_TEN] = NO_FLOOR;
		}
	else
		testno = number - 1;
	testno++;
	flashcontent = display[BUF_ARROW];
	PIE1bits.TMR1IE = 1;
}

void KeyScan(void){
	BYTE i, j = 0x00;
	BYTE key_code, value = 0;

	i = PORTC & 0x13;
	key_code = (i >> 2) | (i & 0x03);
	if(!key_code)
		{//无键按下
			mKeyValue_Back = NO_KEY;		
			bKey_Fg.KeyRepeat = bKey_Fg.KeyRepeatEn = bKey_Fg.LongKeyEn = bKey_Fg.KeyAnswer = 0;
			mLongKeyTime = 0x00;
		}
	else
		{//判断具体的按键
			value = key_code;
			for(i=0; i<3; i++)
				{
					if(value & BIT_0)
						++j;
					value >>= 1;
				}
			if(j > 3) 	
				{///3重键无效
					bKey_Fg.KeyTrue = false;
					return;
				}
			for( i=0; i<6; i++ )
				{
					if( key_code == NO_KEY )
						return; 
					if( key_code == tKeyCode[i] )
						break; 		
				}
			//去抖动
			if( mKeyValue != i+1) 
				{
					mKeyValue = i + 1;
					return;
				}
			
			if( mKeyValue != mKeyValue_Back )
				{
					mKeyValue_Back = mKeyValue;
					if(mKeyValue_Back == KEYVALUE_SYSSET)
						mLongKeyTime = LONGKEYTIME_SET;
					else
						mLongKeyTime = LONGKEYTIME_SET;
						
					bKey_Fg.KeyTrue = 1;
					bKey_Fg.KeyRepeat = bKey_Fg.KeyRepeatEn = 0;
				}
			if(mKeyValue == KEYVALUE_SYSSET)
				{
					if( bKey_Fg.LongKeyEn )
						{
							bKey_Fg.LKeyScanEnd = false;
							bKey_Fg.KeyTrue = true;
						}
				}
		}
}

void KeyProg(const BYTE value){

	if(!bKey_Fg.KeyTrue)return;
	switch(value)
		{
			case KEYVALUE_SYSSET:
				if(bKey_Fg.LongKeyEn)
					{
						bKey_Fg.LongKeyEn = 0;
						if(!setid_mode)
							{
								if(!mSwitch_code)
									{//ID setting mode		
										mSwitch_code = 0;
										setid_mode = 1;
										setid_mode_old = 0;
										scroll = 0;
										arrowflash = 0;										
									}
							}
						else if(!mSwitch_code)
							{//Test mode	
								mSwitch_code = 0;
								setid_mode = 0;
								setid_mode_old = 0; 									
								arrowflash = arrowflash_old;										
							}
					}
				break;

			case KEYVALUE_UP:
				if(setid_mode)
					{
						flashtimer = 3;
						if((setid_mode == 1) || (setid_mode == 4))
							{
								keytimer = ID_SET_TIME;
								if (node_id >= ESE_ID && node_id < ESE_ID + MAX_ESE)
									{
										++ node_id;
										if (node_id >= ESE_ID + MAX_ESE)
											node_id = ESE_ID;
									}
								else
									node_id = ESE_ID;
								preset_node_id = node_id;
								write_eeprom (EE_NODEID_ADDR, node_id);
							}
						else if(setid_mode == 2)
							{
								keytimer = 0;
								preset_node_id = node_id;
								write_eeprom (EE_NODEID_ADDR, node_id);
								lss_response (SET_NODE_ID, node_id);
							}
					}
				break;

			case KEYVALUE_DOWN:
				if(setid_mode)
					{
						flashtimer = 3;
						if((setid_mode == 1) || (setid_mode == 4))
							{
								keytimer = ID_SET_TIME;
								if (node_id >= ESE_ID && node_id < ESE_ID+MAX_ESE)
									{
										if (node_id == ESE_ID)
											node_id = ESE_ID + MAX_ESE - 1;
										else
											--node_id;
									}
								else
									node_id = ESE_ID;
								preset_node_id = node_id;
								write_eeprom (EE_NODEID_ADDR, node_id);
							}
						else if(setid_mode == 2)
							{
								keytimer = 0;
								preset_node_id = node_id;
								write_eeprom (EE_NODEID_ADDR, node_id);
								lss_response (SET_NODE_ID, node_id);
							}
					}
				break;
		}
	bKey_Fg.KeyTrue = 0;
}

