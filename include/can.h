
#ifndef _CAN_H_
#define	_CAN_H_

/************************************************************************************************/
/* Definitions for configuration register CANCON												*/
/************************************************************************************************/
#define CAN_MODE_BITS		0xE0		   				/* Mode bits in configuration register	*/
#define CAN_MODE_CONFIG		0x80		   				/* Configuration mode					*/
#define CAN_MODE_LISTEN		0x60		   				/* Listen Only mode						*/
#define CAN_MODE_NORMAL		0x00		   				/* Normal mode							*/

/************************************************************************************************/
/* Definitions for interrupt code in CANSTAT register											*/
/************************************************************************************************/
#define INTCODE				0x0E		   				/* Mask for interrupt code bits			*/
#define WAKEINT				0x0E		   				/* Wake up interrupt					*/
#define RXB0INT				0x0C		   				/* RX buffer 0 interrupt				*/
#define RXB1INT				0x0A		   				/* RX buffer 1 interrupt				*/
#define TXB0INT				0x08		   				/* TX buffer 0 interrupt				*/
#define TXB1INT				0x06		   				/* TX buffer 1 interrupt				*/
#define TXB2INT				0x04		   				/* TX buffer 2 interrupt				*/
#define ERRORINT			0x02		   				/* error interrupt						*/
#define NOINT				0x00		   				/* kein interrupt						*/

/************************************************************************************************/
/* Definitions for Win bits in CANCON register													*/
/************************************************************************************************/
#define TXB0REG				0x08		   				/* TX buffer 0 register access			*/
#define TXB1REG				0x06		   				/* TX buffer 1 register access			*/

#define	BPS_125K			0
#define	BPS_50K				1
#define	BPS_25K				2

#define	C_BAUDRATE_LISTEN_10S	780 * 4
#define	C_MINIMAM_TIMES			4

#define RX_SIZE						30
#define TX_SIZE						30

#ifdef _CAN_C_

BYTE volatile rc;			// RX message counter
BYTE volatile tc;			// TX message counter
BYTE volatile ro;			// pointer for FIFO read
BYTE volatile ri;			// pointer for FIFO write
BYTE volatile to;			// pointer for TX FIFO read
BYTE volatile ti;			// pointer for TX FIFO write
BYTE volatile tr;			// Senden fertig

BYTE volatile rx[RX_SIZE][10];	// RX message buffer
BYTE volatile tx[TX_SIZE][10];	// TX message buffer


void init_can (BYTE baudrate);
void can_transmit (void);
void transmit_in (BYTE * input);
void sdo_response (BYTE command, WORD index, BYTE subindex, DWORD value);
void sdo_segment (BYTE command, BYTE size, BYTE * value);
void abort_sdo (DWORD errorcode);
void lss_response (BYTE command, BYTE value);
void transmit_error (void);
void transmit_load (void);
void read_rx (void);

BYTE check_for_call (BYTE value);
void set_output (BYTE *virt);
void set_io_config (void);

#else
extern BYTE volatile rc;
extern BYTE volatile tc;
extern BYTE volatile ro;
extern BYTE volatile ri;
extern BYTE volatile to;
extern BYTE volatile ti;
extern BYTE volatile tr;
extern BYTE volatile rx[RX_SIZE][10];
extern BYTE volatile tx[TX_SIZE][10];


extern	void init_can (BYTE baudrate);
extern	void read_rx (void);
extern	void abort_sdo (DWORD errorcode);
extern	void transmit_error (void);
extern	void transmit_in (BYTE * input);
extern	void transmit_load (void);
extern	void lss_response (BYTE command, BYTE value);
extern	void ListenCAN(BYTE baudrate);
extern	BYTE check_for_call (BYTE value);
extern	void set_io_config (void);
extern	void sent_heartbeat(void);


#endif
#endif

