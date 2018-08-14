#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define PLAYER_ONE 1
#define PLAYER_TWO 2

void simulateGame(int n);

int getNewValue(int n);

int isSameBeauty(int n1, int n2);

int numberOfOnes(int n);

int switchPlayer(int player);

int main() {
    int n;

    printf("Enter number:\n");
    scanf("%d",&n);

    simulateGame(n);
    return 0;
}
/*
 * enter number:
 * 110
 *
 * player 1:
 * 123
 * player 2:
 * 123
 *
 *
 * player 1 loses;
 * */


void simulateGame(int n) {
    int newValue;
    int currentPlayer = PLAYER_ONE;


    n = getNewValue(n);

    while (n != -1) {
        printf("player %d:\n%d\n", currentPlayer, n);
        currentPlayer = switchPlayer(currentPlayer);
        n = getNewValue(n);
    }

    printf("player %d loses\n", currentPlayer);
}

int switchPlayer(int player) {
    return 3-player;
}

int getNewValue(int n) {
    int powerOfTwo;

    for (powerOfTwo = 1; n-powerOfTwo >= 0; powerOfTwo*=2){
        if (isSameBeauty(n,n-powerOfTwo)){
            return n-powerOfTwo;
        }
    }

    return -1;
}

int isSameBeauty(int n1, int n2) {
    return numberOfOnes(n1) == numberOfOnes(n2);
}

int numberOfOnes(int n) {
    int count = 0;

    for (count=0; n != 0; n>>=1){
        if (n%2){
            count++;
        }
    }

    return count;
}