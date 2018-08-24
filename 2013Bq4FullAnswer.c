#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_BITS_IN_BYTES 8

typedef struct {
    int idNo;
    int char_num;
    unsigned char age;
    char *name;
} Client;

void** encodeArray(void** array, int size, void*(*encodeSingleObject)(void*));

unsigned char reverse(char c);

void* encodeClient(void* k);

int main(){
    Client *clients[1];
    Client **encodedClients;
    Client c = {12,12,0xca, "hello"};
    clients[0] = &c;

    encodedClients = encodeArray(clients, 1, encodeClient);

    printf("%x\n", clients[0]->age);
    printf("%x\n", encodedClients[0]->age);
    return 0;
}


void* encodeClient(void* k){
    Client *client = (Client*)k;
    Client *newClient = (Client*) malloc (sizeof(Client));

    newClient->idNo = client->idNo;
    newClient->age = reverse(client->age);
    newClient->name = client->name;
    newClient->char_num = client->char_num;

    return newClient;
}

void** encodeArray(void** array, int size, void*(*encodeSingleObject)(void*)){
    int i;
    void** newArray;

    newArray = (void**) malloc (sizeof(void*));

    for (i=0; i<size; i++){
        newArray[i] = encodeSingleObject(array[i]);
    }

    return newArray;
}

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