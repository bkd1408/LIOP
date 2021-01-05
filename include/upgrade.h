
#ifndef _UPGRADE_H_
#define _UPGRADE_H_



#define BYTE_ADDR_SRCADDR	0x00				//Դ��ַ
#define BYTE_ADDR_TYPE		0x01				//��Ϣ����
	#define TYPE_UPGRADE		0x10				//������Ϣ����
#define BYTE_ADDR_COMMAND	0x02				//������
	#define CMD_UPGRADE_NODE	0x10				//��ʼ��������
	#define CMD_DATA_TRANSMIT	0x11				//������������
	#define CMD_UPGRADE_END		0x12				//������������
	#define CMD_UPGRADE_ACK		0x13				//����Ӧ��

#define BYTE_ADDR_MODE		0x03				//��ʼ���������е��ֽڶ���
#define BYTE_ADDR_FVER1		0x04
#define BYTE_ADDR_FVER2		0x05
#define BYTE_ADDR_SVER1		0x06
#define BYTE_ADDR_SVER2		0x07

#define BYTE_ADDR_INDEX		0x03				//��ʼ���������е��ֽڶ���
#define BYTE_ADDR_DATA1		0x04
#define BYTE_ADDR_DATA2		0x05
#define BYTE_ADDR_DATA3		0x06
#define BYTE_ADDR_DATA4		0x07

#define BYTE_ADDR_ACK		0x03				//��ʼ���������е��ֽڶ���
	#define ACK_OK				0x00
	#define ACK_RETRY			0x01
	#define ACK_FAIL			0x02
	#define ACK_OVER			0x03



#define ADDR_CAN_BROADCAST		0x00			//���չ㲥��ַ0x00��������




// Definitions for configuration register CANCON
#define CAN_MODE_BITS		0xE0
#define CAN_MODE_CONFIG		0x80
#define CAN_MODE_NORMAL		0x00





BYTE flashread(WORD addr);
void Upgrade(void);

#endif


