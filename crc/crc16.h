
#ifndef __CRC16_H
#define __CRC16_H

#ifndef CRC16
#define CRC16 0x8005
#endif

#ifndef NULL
#define NULL 0x00
#endif

void MakeCRC16Table(void);
unsigned int crc16(unsigned char * crcptr, unsigned int crc_len);
unsigned int sum16(unsigned char * crcptr, unsigned int crc_len);

#endif

