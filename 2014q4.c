#include <stdio.h>
#include <stdlib.h>

int permuteNumber(int x, int offsets[]);

int getBit(int c, int i);

int setBit(int c, int i, int val);

int main() {
    int arr[] = {
            0,1,2,3,4,5,6,7,8,9,
            10,11,12,13,14,15,16,17,18,19,
            20,21,22,23,24,25,26,27,28
            ,29,30,31};


    printf("%d\n", permuteNumber(1234,arr));

    return 0;
}

int permuteNumber(int x, int offsets[]) {
    int result = 0;
    int i;
    int currentBit = 0;

    for (i=0; i<8* sizeof(int); i++){
        currentBit = getBit(x, offsets[i]);
        result = setBit(result, i, currentBit);
        printf("%d\t", result);
    }

    return result;
}


int getBit(int c, int i){
    int mask = 1 << i;
    return (c & mask) >> i;
}

int setBit(int c, int i, int val){
    int mask = 1 << i;
    if (val == 1){
        return c | mask;
    } else {
        return c & ~mask;
    }
}