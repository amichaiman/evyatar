#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);

int main(){
    int(*operation[3])(int,int);
    int input;
    int a, b;


    operation[0] = add;
    operation[1] = sub;
    operation[2] = mul;

    printf("1)add\n2)sub\n3)mul\n");
    scanf("%d",&input);

    printf("enter numbers:\n");

    scanf("%d%d",&a,&b);

    printf("answer: %d\n", operation[input-1](a,b));
    return 0;
}


int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int mul(int a, int b){
    return a*b;
}