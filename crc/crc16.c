#include <crc16.h>

static unsigned int crctable[256];

void MakeCRC16Table(void)
{
 unsigned int r=0;
 unsigned int i,j;
  for(i=0; i<256; i++)
   {
    r = ((unsigned int)i)<<8;
     for(j=0; j<8; j++)
       {
        if(r&(1<<15)) r=(r<<1)^0x8005;
        else r=r<<1;
       }
     crctable[i]=r;
   }
}

unsigned int crc16(unsigned char * crcptr, unsigned int crc_len)
{
unsigned int crc_temp=NULL;
 /* Sanity check: */
    if(crcptr == NULL)
        return 0;


 crc_temp=0xFFFF;
 while(crc_len--)
  {
crc_temp=crctable[((crc_temp>>8)^*crcptr++)&0xFF] ^ (crc_temp<<8);
  }
  crc_temp ^= 0xFFFF;
return crc_temp;
}


unsigned int sum16(unsigned char * crcptr, unsigned int crc_len)
{
unsigned int sum_temp=0;
unsigned int i;
 /* Sanity check: */
    if(crcptr == NULL)
        return 0;
for(i=0;i<crc_len;i++)
{
sum_temp=+ *(crcptr+i);
}
return sum_temp;
}
