
#define	_MAIN_C_

#include "AllHeader.h"

//#define	___DEBUG

#pragma config FOSC = HS2			// Main oscillator high speed resonator
#pragma config XINST = OFF
#pragma config MCLRE = ON

#ifdef ___DEBUG
#pragma config WDTEN = OFF		// Watchdog timer off
#pragma config CP0 = OFF
#pragma config CP1 = OFF
#pragma config CP2 = OFF
#pragma config CP3 = OFF
#pragma config CPB = OFF
#else
#pragma config PWRTEN = ON
#pragma config WDTEN = ON			// Watchdog timer off
#pragma config CP0 = ON
#pragma config CP1 = ON
#pragma config CP2 = ON
#pragma config CP3 = ON
#pragma config CPB = ON
#endif
#pragma config BOREN = ON		// Brown out reset enabled
#pragma config BORV = 1			// Brown out voltage 2.7V
#pragma config WDTPS = 1024//1024//256		// watchdog postscaler 1 : 256
#pragma config CANMX = PORTB
#pragma config SOSCSEL = DIG


//Tosc=16MHz,无中断情况下,延迟tick个毫秒
void DelayMs(unsigned int tick){
	volatile unsigned long i;

	while(tick--)
	{
		for (i = 0; i < 165; i++);
		ClrWdt();
	}
}

//一共6个输入，4个输出，预留2个备用输入
void InitPorts(void){

	TRISA = 0xF7;				
		// RA0: G-755 check in
		// RA1: G-755 check in
		// RA2: Not used in
		// RA3: backlight output
		// RA4: Not used in
		// RA5: Not used in
		// RA6-RA7: OSC
	OPEN_BL();
	
	PORTB = 0xFF; 		// switch off (important for CAN!)
	TRISB = 0xC8;				
		// RB0: Down Led output
		// RB1: Up Led output
		// RB2-RB3: CAN
		// RB4; Gong Down output
		// RB5; Gong Up output
		// RB6-RB7: PGC-PGD;

	TRISC = 0x1F;				
		//RC0: Up key in
		//RC1: Down key in
		//RC2: Fire in
		//RC3: Lift off in
		//RC4: ID Set in
		//RC5: RCLK output
		//RC6: LCD 同步串口 CK out
		//RC7; LCD 同步串口 DT out
	if(hardware_version == G_741_LCD)
		{
			TRISD = 0x7F; 		
				//RD0: Not used in
				//RD1: Not used in
				//RD2: Not used in
				//RD3: Not used in
				//RD4: Not used in
				//RD5: Not used in
				//RD6: Not used in
				//RD7; Lcd COM output
		}
	else
		TRISD = 0x80; 		
		
	TRISE = 0x00; 
		// RE0: LG1 out
		// RE1: LG2 out
		// RE2: LG3 out

	LATB = 0;
	LATC = 0;
	LATD = 0;
	LATE = 0;

}

/************************************************************************************************/
/* initialize timer 0																			*/
/************************************************************************************************/
void init_timer0 (void){
	INTCONbits.TMR0IE = 1;
	INTCONbits.TMR0IF = 0;
	INTCON2bits.TMR0IP = 0;
	TMR0H = T0H_500ms;
	TMR0L = T0L_500ms;
	T0CON = T0START_1TO32;
}

/************************************************************************************************/
/* initialize timer 1																			*/
/************************************************************************************************/
void init_timer1 (void){
	PIR1bits.TMR1IF = 0;
	IPR1bits.TMR1IP = 0;
	PIE1bits.TMR1IE = 1;
	if(hardware_version == G_741_LCD)
		{
			timer1_countH = T1H_2ms;
			timer1_countL = T1L_2ms;
		}
	else if(hardware_version == G_742_LED)
		{
			timer1_countH = T1H_2ms;
			timer1_countL = T1L_2ms;
		}
	TMR1H = timer1_countH;
	TMR1L = timer1_countL;
	T1CON = T1START_1TO1;
}

/************************************************************************************************/
/* initialize timer 2																			*/
/************************************************************************************************/
void init_timer2 (void){
	PIR1bits.TMR2IF = 0;
	IPR1bits.TMR2IP = 0;
	PIE1bits.TMR2IE = 1;
	PR2 = T2_3ms;
	TMR2 = 0;
	T2CON = T2START_1TO48;
}

/************************************************************************************************/
/* check if a HSE heartbeat time out occured													*/
/* If so, set or reset outputs and displays for this Lift										*/
/************************************************************************************************/
void check_hse (BYTE mode){
	BYTE help;
	BYTE i;
	help = 0;
	
	if (!hsetime)								/* 5s no heartbeat from HSE				*/
		{
			help = 1;							/* set marker							*/
			hsetime = HSETIME;						/* restart HSE heartbeat timer			*/
			if ((!setid_mode) && (!mSwitch_code))					/* display is for this lift				*/
				{
					PIE1bits.TMR1IE	= 0;					/* disable Timer 2 interrupt			*/
					display[BUF_ARROW] = NO_ARROW;					/* display no arrow						*/
					display[BUF_TEN] = CHAR_N;					/* display sign for out of work			*/
					display[BUF_UNIT] = CHAR_C;
					PIE1bits.TMR1IE	= 1;					/* enable Timer 2 interrupt				*/

					if(hardware_version == G_741_LCD)
						arrowflash = 0x01;
					else		
						arrowflash = 0x00;
					flashcontent = display[BUF_ARROW];
				}
			hse_heartbeat = 0;
		}
	if (help && mode)											/* one or more HSE not available		*/
		{
			for (i = 0; i < MAX_IO; i++)					/* check all call indications			*/
				{
					if (check_for_call (outpar[i][IO_BASIC_FUNC]))
						{											/* output is call acknowledgement		*/
			  			outpar[i][IO_ACK] &= ~help;
							if (!outpar[i][IO_ACK])					/* all acknowledgements cancelled		*/
								{
									bit_reset (out, i);					/* clear output							*/
									outpar[i][IO_STATE] = 0;
								}
						}
					else										/* all other output functions			*/
						{
							if (outpar[i][IO_LIFT] & help)			/* output for this lift					*/
								{
									if ((outpar[i][IO_BASIC_FUNC] == SPECIAL_FUNC) &&
									    (outpar[i][IO_SUB_FUNC] == OUT_OF_ORDER))
										{
											bit_set (out, i);				/* set physical output					*/
					 						outpar[i][IO_STATE] = 1;
										}
									else
										{
											bit_reset (out, i);				/* reset physical output				*/
											outpar[i][IO_STATE] = 0;
										}
								}
						}
				}
		}
}

BYTE check_version(BYTE *buf0, BYTE *buf1){
	BYTE i = 0;
	BYTE m = 0, k = 0;
	BYTE version = 0;
	
	for(i = 0; i < 10; i++)
		{
			if(buf0[i])
				m++;
			if(buf1[i])
				k++;
		}
	if(m > 7)
		version |= BIT_0;
	if(k > 7)
		version |= BIT_1;
	return version;
}

void init_userpara(void){
	BYTE i;
	
	display[BUF_ARROW] = NO_ARROW;
	display[BUF_TEN] = A_BETR;
	display[BUF_UNIT] = A_BETR;
	display[BUF_MESSAGE] = 0;

	heartbeat = HEARTBEATTIME;
	display_timer = 0;
	keytimer = 0;
	hsetime = HSETIME;								/* start timer with different times 	*/
	nmtwait = 0;
	hsecheck = 0; 											/* no HSE check now 					*/
	setid_mode = 0;
	setid_mode_old = 0;				// set liop can ID mode	
	
	arrowtype = 0;	
	if(hardware_version == G_741_LCD)
		arrowflash = 0x01;
	else		
		arrowflash = 0x00;
	flashcontent = NO_ARROW;
	
	disp_lift = 1;
	device_type = MULTIPLE_DEVICES;
	virtual_device[0] = INPUT_PANEL_UNIT >> 16;
	virtual_device[1] = OUTPUT_PANEL_UNIT >> 16;
	
	inpush = 0;
	outpush = 0;
	backlight_mode = 0;
	
	for (i = 0; i < MAX_IO; i++)
		{
			inpar[i][IO_STATE] = 0;
			outpar[i][IO_STATE] = 0;
			inpar[i][IO_BASIC_FUNC] = 0;
			outpar[i][IO_BASIC_FUNC] = 0;
			outpar[i][IO_ACK] = 0;
		}
	for (i = 0; i < MAX_IO_TYPE; i++)
		{
			virt_in[i] = 0;
			virt_out[i] = 0;
		}
	in_polarity = 0;
	out_polarity = 0;
	
	out = 0;
	in = PORTC & 0x0F;
	input[0] = in;
	input[1] = in;
	input[2] = in;
	inold = 0;
}


void main(void){
	BYTE i, j;
	BYTE instate;
	BYTE help;

	if (merker == RC_MERKER)
		{
			errorregister |= ER_COMMUNICATION;
		}
	if (merker == BS_MERKER)
		{
			errorregister |= ER_COMMUNICATION;
		}
	else if (RCONbits.POR)
		{
			if (!RCONbits.TO)
				{
					errorregister |= ER_GENERIC;
					errorcode = E_INTERNAL_SW;
				}
		}
	RCONbits.POR = 1;
	RCONbits.BOR = 1;
	merker = WD_MERKER;
	ClrWdt();

//禁止所有的AD功能	
	ADCON0 = 0x00;
	ADCON1 = 0x00;			// port A and E pins as digital I/O
	ODCON = 0x00;
	CTMUCONH = 0x00;
	CTMUCONL = 0x00;
	PADCFG1 = 0x80;
	ANCON0 = 0x00;
	ANCON1 = 0x00;

//上电首先判断板号
	TRISA = 0xFF; 
	for(i = 0; i < 10; i++)
		{
			rx[0][i] = PORTA & BIT_0;
			rx[1][i] = PORTA & BIT_1;
			DelayMs(10);
		}
	i = check_version((BYTE*)(&rx[0][0]), (BYTE*)(&rx[1][0])) & 0x03;
	if(!(i & BIT_0))
		hardware_version = G_741_LCD;
	else if(!(i & BIT_1))
		hardware_version = G_742_LED;
	else		
		hardware_version = G_741_LCD;	

	InitPorts();

	node_id = read_eeprom(EE_NODEID_ADDR);
	disp_lift = LIFT1;
	if ((node_id > MAX_ESE) || (!node_id))
		node_id = ESE_ID;
	
	ClrWdt();
	nmtstate = BOOT_UP;
	nmtwait = node_id;
	preset_node_id = node_id;			//存储之前的ID
	nmtwait = (nmtwait * 20 + 1000) / 3 + 600;
	if (node_id == ESE_ID)
		nmtwait = 1000 / 3 + 600;
	
	init_userpara();

	INTCON = 0;
	RCONbits.IPEN = 1;
	init_timer2();
	init_timer1();
	ClrWdt();	

	init_timer0();
	INTCONbits.GIEH = 1;
	INTCONbits.GIEL = 1;	
	
	while (nmtwait)
		ClrWdt();	
	
	baudrate = BPS_50K;
	init_can (baudrate);								// initialize Onchip CAN	
	DelayMs(100);

	heartbeat = HEARTBEATTIME;
	sent_heartbeat();
	nmtstate = PRE_OP;	
	i = 0;
	j = 0;
	
	hsetime = HSETIME;								/* start timer with different times		*/
	hsecheck = 0;												/* no HSE check now						*/
	ClrWdt();													/* reset watchdog timer					*/
	inold = 0;
	set_io_config();
	
	while (1)									/* wait for start (operational) 		*/
		{			
			ClrWdt ();					/* reset watchdog timer					*/			
			if (rc)													/* Message in receive buffer			*/
				read_rx ();											/* read and handle message				*/
			
			if(display_scantimer)
				{
					KeyScan();
					KeyProg(mKeyValue);
					if (setid_mode)
						SetNodeId();
					else if((nmtstate == TEST_MODE) || ((mSwitch_code == 1) && (com_can_work > 10)))						/* enter test mode						*/
						TestMode ();
					display_scantimer = 0;
				}
			if (sdo_index && !sdo_timer)							/* SDO segment transfer time out		*/
				{
					sdo_index = 0;
					abort_sdo (SDO_TIMEOUT);							/* send SDO abort request				*/
				}
			if ((!heartbeat) && (hse_heartbeat) && (!can_inittime) && (!setid_mode))						/* time to send heartbeat message		*/
				{
					heartbeat = HEARTBEATTIME;				/* restart heartbeat timer				*/
					sent_heartbeat();
				}
			if (errorcode)											/* error occured						*/
				{
					transmit_error ();									/* send emergency message				*/
					errorregister = 0;									/* reset error							*/
					errorcode = 0;
				}		
			if (hsecheck)											/* HSE heartbeat check necessary		*/
				{
					hsecheck = 0;
					check_hse (1);										/* check if a HSE is not available		*/
				}
			if(((merker == BS_MERKER) && (!can_inittime)) || (com_can_work > 40))
				{
					merker = 0;
					com_can_work = 0;
					init_can(BPS_50K);
					errorregister |= ER_COMMUNICATION;
					errorcode = E_BUS_OFF_B;
				}			
			if(nmtstate == PRE_OP)
				{
					instate = in ^ in_polarity;								/* read input state; invert if desired	*/
					for (i = 0; i < MAX_IO; i++)							/* check all inputs						*/
						inpar[i][IO_STATE] = bit_select(instate,i);			/* set input state						*/
				}
			else if(nmtstate == OPERATIONAL)
				{
					instate = in ^ in_polarity; 							/* read input state; invert if desired	*/
					if (instate != inold) 								/* input state changed					*/
						{
							for (i = 0; i < MAX_IO; i++)						/* check all inputs 					*/
								{
									help = bit_select (instate, i);
									if (help != bit_select (inold, i))				/* input has changed					*/
										{
											inpar[i][IO_STATE] = help;					/* set input state						*/
											if (inpar[i][IO_BASIC_FUNC])				/* input has a function 				*/
												{
													for (j = 0; j < MAX_IO_TYPE; j++) 				/* write input to virtual input object	*/
														virt_in[j] = inpar[i][j];
		
													switch (inpar[i][IO_BASIC_FUNC])
														{
															case (CAR_CALL):					/* standard car call					*/
																if (help)
																	transmit_in (virt_in);
																break;
															case (HALL_CALL): 				/* standard hall call 				*/
																if(!setid_mode)
																	{ 							/* landing call misuse					*/
																		if ((!landingcalltimer) || (inpar[i][IO_FLOOR] != landingcallfloor))
																			transmit_in (virt_in);
																		landingcalltimer = 2;
																		landingcallfloor = inpar[i][IO_FLOOR];
																	}
																break;
		
															default:
																transmit_in (virt_in);
																break;
														}
												}
										}
								}
							inold = instate;
						}
				}
		}
}

