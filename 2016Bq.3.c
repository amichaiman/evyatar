#include <stdio.h>

#define POSITIVE 0xb
#define NEGATIVE 0xc

int encodeBCD(int number, unsigned char *buf);

int main(){
    int x = -1245;
    unsigned char buf[100];
    int i;
    int bufLen;

    printf("%d\n",x);

    bufLen = encodeBCD(x, buf);

    for (i=0; i<bufLen+1; i++){
        printf("0x%x\t",buf[i]);
    }

    return 0;
}

int encodeBCD(int number, unsigned char *buf) {
    unsigned char sign = number > 0 ? POSITIVE : NEGATIVE;
    unsigned char c = 0;
    int i;

    if (sign == NEGATIVE){
        number = -number;
    }

    for (i=0; number > 0; i++, c=0){
        c |= number%10;
        number /= 10;

        c <<= 4;

        c |= number%10;
        number /= 10;
        buf[i] = c;
    }

    if ((buf[i-1]&0xf) == 0){
        buf[i-1] |= sign;
        return i-1;
    } else {
        buf[i] = sign;
        buf[i] <<= 4;
        return i;
    }

}


int decodeBCD(int *number, char *buf){


}


