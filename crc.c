/******************************************************************************
UNVERIFIED code
Code for CRC on the Sender side.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int dec2bin(int dec)
{
   int rem = 0, bin = 0;
   for(int i=0; dec>0; i++)
   {
   rem = dec%2;
   bin = bin + (rem*(pow(10,i)));
   dec = dec/2;
   }
   return(bin);
}
int bin2dec(int bin)
{
    int rem = 0, dec = 0;
    for(int i=0; bin>0; i++)
    {
        rem = bin%10;
        dec = dec + (rem*pow(2,i));
        bin = bin/10;
    }
    return(dec);
  
}

int main()
{
    char msg[40],gen[10];
    int gen_len, gen_bin, msg_bin, gen_dec, msg_dec, crc, new_msg;
    printf("enter binary generator:");
    scanf("%s",gen);
    printf("enter binary msg:");
    scanf("%s",msg);
    gen_len = strlen(gen);
    gen_bin = atoi(gen);
    msg_bin = atoi(msg);
    
    //converting binary to decimal
    msg_dec = bin2dec(msg_bin);
    gen_dec = bin2dec(gen_bin);
  
    /*Performing CRC: left shifting by (gen_len-1)positions
    Caution: The length of redundancy bits i.e.(gen_len-1) here works for gen_len = 4 and 6 bits i guess.Unverified*/
    msg_dec = msg_dec*pow(2,(gen_len-1));
    printf(" \nThe msg after adding zeros %d", dec2bin(msg_dec));
    printf("\n%d divided by %d = ", msg_dec, gen_dec);
    crc = msg_dec % gen_dec;
    printf("\t haha %d", crc);
    printf(" \nCRC is %d", dec2bin(crc));
    
    new_msg = msg_dec + crc;
    printf(" \nMsg to be transmitted: %d", dec2bin(new_msg));
    
    
}

