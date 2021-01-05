
#ifndef _EEPROM_H_
#define _EEPROM_H_


#define EE_NODEID_ADDR		0x00						// node id in EEPROM
#define EE_CTE_ADDR			0x02						// CTE flag in EEPROM


BYTE read_eeprom (WORD address);
BYTE write_eeprom (WORD address, BYTE value);

#endif

