#include <stdio.h>

unsigned int updateBits(unsigned int n, unsigned int m, unsigned int i, unsigned int i1);

unsigned int setBit(unsigned int c, unsigned int i, unsigned int val);

unsigned int getBit(unsigned int c, unsigned int i);

unsigned int main(){
    unsigned int n = 0x8000000e;
    unsigned int m = 0x00000015;

    printf("%x\n", updateBits(n, m, 2, 6));


}

unsigned int updateBits(unsigned int n, unsigned int m, unsigned int i, unsigned int j) {
    unsigned int res = n;
    unsigned int k;

    for (k=0; k< j-i+1; k++){
        res = setBit(res ,i+k, getBit(m,k));
    }

    return res;
}




unsigned int getBit(unsigned int c,unsigned int i){
    unsigned int mask = 1 << i;
    return (c & mask) >> i;
}

unsigned int setBit(unsigned int c, unsigned int i, unsigned int val){
    unsigned int mask = 1 << i;
    if (val == 1){
        return c | mask;
    } else {
        return c & ~mask;
    }
}