#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
} Node;

typedef struct {
    Node *head;
} List;


void addNode(List *l, int key);
void printList(Node *curNode);
List *createNewList(List *list);

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

    newList = createNewList(list);

    if (newList){
        printList(newList->head);
    }

    return 0;
}

List *createNewList(List *list) {
    List *newList;
    Node *curNode;
    int sum = 0;


    if (!list || !list->head){
        return NULL;
    }

    /*  allocate and initialize new list    */
    newList = (List*) malloc(sizeof(List));
    newList->head = NULL;

    /*  curNode will iterate over the old list  */
    curNode = list->head;

    /*  sum will hold the current number to be added to the new list    */
    sum = list->head->key;

    /*  go through all nodes in list    */
    while(curNode->next){
        /*  if next node isn't bigger than me ==> add to new list   */
        if (curNode->next->key <= curNode->key){
            addNode(newList,sum);
            sum = 0;
        }
        sum += curNode->next->key;
        curNode = curNode->next;
    }
    /*  add the sum of the last series  */
    addNode(newList,sum);

    return newList;
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