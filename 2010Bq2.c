#include <stdio.h>
#include <stdlib.h>

void printPointer(unsigned int pointer);

unsigned int readPointer(FILE *fp, unsigned int pointer);

int main(int argc, char **argv){
    FILE* fp;

    /*  if no file input    */
    if (argc < 2){
        exit(1);
    }
    /*  if unable to open file  */
    if (!(fp = fopen(argv[1], "r"))){
        exit(2);
    }
    unsigned int pointer = 0x00;
    printPointer(pointer);

    printPointer(readPointer(fp, pointer));
}

unsigned int readPointer(FILE *fp, unsigned int pointer) {
    unsigned int res = 0;

    fseek(fp, pointer>>3, SEEK_SET);
    printf("%c", fgetc(fp));

    /*  need to read 4 bytes from file to res
     * 
     * fread(res, 4, 1, fp);*/


    return res >> 7-(pointer&0x7);
}

void printPointer(unsigned int pointer) {
    printf("bit: %u\n", pointer&0x7);
    printf("byte: %u\n", pointer>>3);
}