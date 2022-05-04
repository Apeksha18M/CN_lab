/******************************************************************************
CRC
*******************************************************************************/

#include <stdio.h>
#include <string.h>

char crc[30];

void XOR(char a[30],char generator[30])
{
    char crc[30];
    for(int i=0; i<strlen(generator);i++)
        crc[i] = a[i]^generator[i];
}

int main()
{
    char msg[20], gen[10], crc[20];
    int gen_len, msg_len,i,j;
    printf("Enter msg: ");
    scanf("%s", msg);
    printf("\nEnter generator: ");
    scanf("%s", gen);
    gen_len=strlen(gen);
    msg_len = strlen(msg);

    for(i=msg_len; i<(msg_len + gen_len -1); i++)
    {

        msg[i] = '0';
    }
    msg[i+1] = '\0';
    printf("meow");
    printf("\nAfter appending zeros: %s",msg);
    
    //Performing modulo-2 division
    for(i=0;i<gen_len-1; i++)
    {
        crc[i] = msg[i]; //copying the msg to crc
    }
    do{
        if(crc[0]=='1')
            XOR(crc,gen);
        for(j=0;j<gen_len-1;j++)
            crc[j] = crc[j+1];
        crc[j] = msg[j+1];
    }while(i<=(msg_len+gen_len-1));
    
    printf("\nchecksum is %s",crc);
    
    for(i = 0; i<(gen_len-1); i++)
    {
        msg[msg_len-gen_len+1+i] = crc[i];
    }
    printf("\nFinal codeword: %s", msg);
    
}

