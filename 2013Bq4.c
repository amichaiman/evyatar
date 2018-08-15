#include <stdio.h>

#define NUMBER_OF_BITS_IN_BYTES 8

unsigned char reverse(char c);

int main(){
    unsigned char c = 0xca;

    printf("%x before reverse, %x after reverse\n", c, reverse(c));

    return 0;
}

/*  flip bit order  */
unsigned char reverse(char c){
    unsigned char new_c = 0x0;
    int i;
    char rightmostBit;

    for (i=0; i<NUMBER_OF_BITS_IN_BYTES* sizeof(c); i++, c >>= 1){
        /*  isolate rightmost bit  */
        rightmostBit = c&0x1;
        /*  make room for new bit   */
        new_c <<= 1;
        /*  add new bit */
        new_c |= rightmostBit;
    }

    return new_c;
}