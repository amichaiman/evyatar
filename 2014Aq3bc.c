#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    void* key;
    struct node *next;
} Node;

typedef struct {
    Node *head;
} List;


void addNode(List *l, int key);
void printList(Node *curNode);
List *createNewList(List *list, int(*ArithmaticOperation)(void*,void*));

int isEven(int index);

int main() {
    List *list = (List*) malloc(sizeof(List));
    List *newList = NULL;
    list->head = NULL;

    addNode(list,7);
    addNode(list,2);
    addNode(list,4);
    addNode(list,8);
    addNode(list,20);
    addNode(list,18);
    addNode(list,19);
    addNode(list,20);
    addNode(list,20);
    addNode(list,5);
    addNode(list,-3);
    addNode(list,0);
    addNode(list,9);
//    addNode(list,1);

//    newList = createNewList(list);

    if (newList){
        printList(newList->head);
    }

    return 0;
}

List *createNewList(List *list, int(*arithmaticOperation)(void*,void*)) {
    List *newList;
    Node *curNode;

    if (!list || !list->head){
        return NULL;
    }

    newList = (List*) malloc(sizeof(List));
    curNode = list->head;

    while (curNode){
        if (curNode->next){
            addNode(newList,arithmaticOperation(curNode->key,curNode->next->key));
            curNode = curNode->next->next;
        } else {
            addNode(newList,arithmaticOperation(curNode->key,NULL));    //assuming arithmatic
            curNode = NULL;
        }
    }
}


int isEven(int index) {
    return index%2 == 0;
}

/*  appends node to end of list
 * */
void addNode(List *l, int key){
    Node *curNode;
    Node *toAdd;

    /*  make sure list exists   */
    if (!l){
        return;
    }

    curNode = l->head;

    /*  create new node;
     *      set it's key to given key
     *      set next to null    */
    toAdd = (Node*) malloc(sizeof(Node));
    toAdd->key = key;
    toAdd->next = NULL;

    /*  only if the list is empty   */
    if (!l->head){
        l->head = toAdd;
        return;
    }


    /*  move the curNode pointer to the last node in list   */
    while(curNode->next){
        curNode = curNode->next;
    }
    /*  now that the curNode pointer is pointing to last node, add the new node.    */
    curNode->next = toAdd;
}


void printList(Node *curNode){
    if (!curNode){
        printf("\n");
        return;
    }

    printf("%d\t",curNode->key);
    printList(curNode->next);
}