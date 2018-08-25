#include <stdio.h>

int getDegIn(int mat[][4], int size, int k);

int getDegOut(int *row, int size, int k);

int isGood(int mat[][4], int size);

int main(){
    int mat[][4] = {
            {0,1,0,0},
            {0,1,0,1},
            {1,1,0,0},
            {0,0,1,0}
    };

    printf("is%s good!", isGood(mat,4) ? "": " not");
    return 0;
}


int isGood(int mat[][4], int size){
    int flag1=0, flag2=0;
    int degIn, degOut;
    int i;

    for (i=0, degIn=0, degOut=0; i<size; i++){
        degIn = getDegIn(mat,size,i);
        degOut= getDegOut(mat[i],size,i);

        if (degIn+1 == degOut){
            flag1++;
        } else if (degOut+1 == degIn){
            flag2++;
        } else if (degOut != degIn){
            return 0;
        }
    }

    printf("%d %d", flag1, flag2);
    return flag1==1 && flag2==1;
}

int getDegOut(int *row, int size, int k) {
    int i;
    int deg=0;

    for (i=0; i<size; i++){
        deg += row[i];
    }

    return deg;
}

int getDegIn(int mat[][4], int size, int k) {
    int deg=0;
    int i;

    for (i=0; i<size; i++){
        deg += mat[i][k];
    }

    return deg;
}



