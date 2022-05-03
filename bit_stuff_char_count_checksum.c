/******************************************************************************

Code for Bit Stuffing on the Sender side.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

void character_count()
{
    char char_count[15];
    printf("Enter the string: ");
    scanf("%s",char_count);
    printf("\n After character-count: %lu%s",(strlen(char_count))+1,char_count);
}

void bitstuffing()
{
    char bitstuff[30];
    int count = 0, inp_len;
    printf(" Enter string for bitstuffing: ");
    scanf("%s",bitstuff);
    for(int i=0; i<strlen(bitstuff);i++)
    {
        inp_len = strlen(bitstuff);
        if(bitstuff[i]=='1')
        {
            count = count + 1;
        }
        else
            count = 0;
        if(count==5)
        {
            /* Termination condition for the below 'for' loop: last_element_pos>current_val_of_i
            i.e. length_of_string-1 > i*/
           for(int j=0; j<inp_len-i; j++)
           {
               bitstuff[inp_len-j+1] = bitstuff[inp_len-j];
           }
           bitstuff[i+1]='0';
               
           }
    }
    printf(" \n After bitstuffing: %s",bitstuff);
}

void checksum_func()
    {
    int msg[30],size, checksum, sum = 0;
    printf(" Enter the array size: ");
    scanf("%d",&size);
    printf("Enter array: ");
    for(int i=0; i<size ;i++)
    {
        scanf("%d",&msg[i]);
    }
    for(int i=0; i<size ;i++)
    {
        sum= sum + msg[i];
    }
    checksum = ~sum;
    printf(" Sum is %d\n Checksum is %d",sum, checksum);
    
}

void main()
{
}

