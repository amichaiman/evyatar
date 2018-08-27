#include <stdio.h>

void printChar(unsigned char *glif);

int main(){
    unsigned char glif[] = {0x00, 0x00, 0x2e, 0x30, 0x30, 0x30, 0x2e, 0x00};


    printChar(glif);
}
unsigned char getBit(unsigned char c, int i){
    char mask = 1 << i;
    return (c & mask) >> i;
}

void printChar(unsigned char *glif) {
    int i,j;

    for (i=0; i<9; i++){
        for (j= sizeof(char)*8-1; j>=0; j--){
            printf("%c", getBit(glif[i],j) ? 'x' : ' ');
        }
        putchar('\n');
    }
}

void printFont(char *font, int numberOgGlifs){
    int i;

    for (i=0; i<numberOgGlifs; i++){
        printChar(font+9*i);
    }
}