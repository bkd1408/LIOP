
#include "AllHeader.h"

/************************************************************************************************/
/* read a single byte from EEPROM																*/
/************************************************************************************************/
BYTE read_eeprom (WORD address){
	EEADRH = address >> 8;
	EEADR  = (BYTE)address;						/* write address to EEPROM register		*/
	EECON1bits.EEPGD 	= 0;							/* point to EEPROM						*/
	EECON1bits.CFGS 	= 0;							/* access to EEPROM						*/
	EECON1bits.RD 		= 1;							/* initiates EEPROM read				*/
	return (EEDATA);									/* read EEPROM data						*/
}

/************************************************************************************************/
/* write a single byte to EEPROM																*/
/************************************************************************************************/
BYTE write_eeprom (WORD address, BYTE value){
	EEADRH = address >> 8;
	EEADR 				= (BYTE)address;						/* write address to EEPROM register		*/
	EEDATA				= value;						/* write value to EEPROM register		*/
	EECON1bits.EEPGD 	= 0;							/* point to EEPROM						*/
	EECON1bits.CFGS 	= 0;							/* access to EEPROM						*/
	EECON1bits.WREN		= 1;							/* enables EEPROM write					*/
	INTCONbits.GIEH		= 0;							/* high priority interrupts disable		*/
	INTCONbits.GIEL		= 0;							/* low priority interrupts disable		*/
	EECON2				= 0x55;							/* special write enable sequence		*/
	EECON2				= 0xAA;
	EECON1bits.WR 		= 1;							/* initiates EEPROM write				*/
	INTCONbits.GIEH		= 1;							/* high priority interrupts enable		*/
	INTCONbits.GIEL		= 1;							/* low priority interrupts enable		*/
	ClrWdt();
	while (!PIR4bits.EEIF);								/* wait until write is ready			*/
	PIR4bits.EEIF 		= 0;							/* reset EEPROM write ready bit			*/
	EECON1bits.WREN		= 1;							/* disables EEPROM write				*/
	if (read_eeprom (address) == value)					/* read EEPROM back to verify			*/
		return (0);										/* return ok.							*/
	return (1);											/* return error							*/
}

#ifdef __DEBUG
const unsigned char C_INIT_NODEID = ESE_ID;
#else
const unsigned char C_INIT_NODEID = 0xff;
#endif
