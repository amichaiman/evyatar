#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
} Node;

typedef struct {
    Node *head;
} List;

/********************************************/
typedef struct nodeGeneric{
    void* key;
    struct nodeGeneric *next;
} NodeGeneric;


typedef struct {
    NodeGeneric *head;
} ListGeneric;
/********************************************/

void addNode(List *l, int key);
void printList(Node *curNode);
List splitList(List *list);
int getListLen(Node *curNode);
void duplicateRemove(List *list);

int main() {
    List *list = (List*) malloc(sizeof(List));
    List newList;

    list->head = NULL;

    addNode(list,1);
    addNode(list,15);
    addNode(list,6);
    addNode(list,6);
    addNode(list,3);
    addNode(list,4);

    /*newList = splitList(list);

    printList(list->head);

    printList(newList.head);
    */
    printList(list->head);
    duplicateRemove(list);
    printList(list->head);

    return 0;
}


void duplicateRemoveGeneric(ListGeneric *list, int(*areEqual)(void*, void*), void(*freeKey)(void*)){
    if (!list || !list->head){
        return;
    }

    NodeGeneric *cur;
    NodeGeneric *toDelete;

    for (cur=list->head; cur->next != NULL; cur=cur->next){
        /*  if duplicate    */
        if (areEqual(cur->key, cur->next->key)){
            /*  remove duplicate    */
            toDelete = cur->next;
            cur->next = toDelete->next;
            freeKey(toDelete->key);
            free(toDelete);
        }
    }
}

void duplicateRemove(List *list) {
    if (!list || !list->head){
        return;
    }

    Node *cur;
    Node *toDelete;

    for (cur=list->head; cur->next != NULL; cur=cur->next){
        /*  if duplicate    */
        if (cur->key == cur->next->key){
            /*  remove duplicate    */
            toDelete = cur->next;
            cur->next = toDelete->next;
            free(toDelete);
        }
    }
}


List splitList(List *list) {
    List newList;
    int i;
    Node *cur;

    newList.head = NULL;

    if (!list || !list->head){
        return newList;
    }

    int listLen = getListLen(list->head);

    /*  go to last node of first list   */
    for (i=0, cur=list->head; i < listLen/2 + listLen%2 - 1; i++, cur = cur->next);

    /*  split   */
    newList.head = cur->next;
    cur->next = NULL;

    return newList;
}










int getListLen(Node *curNode) {
    if (!curNode){
        return 0;
    }
    return 1+getListLen(curNode->next);
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