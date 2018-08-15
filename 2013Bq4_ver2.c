#include <stdio.h>

#define NUMBER_OF_BITS_IN_BYTES 8

unsigned char reverse(unsigned char c);

unsigned char setBit(unsigned char c, int i, int val);

unsigned char getBit(unsigned char c, int i);

int main(){
    unsigned char c = 0xca;

    printf("%x before reverse, %x after reverse\n", c, reverse(c));

    return 0;
}

/*  flip bit order  */
unsigned char reverse(unsigned char c){
    unsigned char new_c = 0x0;
    int i;

    for (i=0; i<NUMBER_OF_BITS_IN_BYTES* sizeof(c); i++){
        new_c = setBit(new_c, NUMBER_OF_BITS_IN_BYTES - 1 - i, getBit(c, i));
    }

    return new_c;
}


unsigned char getBit(unsigned char c, int i){
    char mask = 1 << i;
    return (c & mask) >> i;
}

unsigned char setBit(unsigned char c, int i, int val){
    unsigned char mask = 1 << i;
    if (val == 1){
        return c | mask;
    } else {
        return c & ~mask;
    }
}