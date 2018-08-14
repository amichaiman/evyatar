#include <stdio.h>

typedef struct node{
    int key;
    struct node *next;
} Node;


void printList(Node *cur);

Node *listRotate(Node *head, int k);

int main(){
    Node n1;
    Node n2;
    Node n3;
    Node n4;
    Node n5;
    Node n6;

    Node *newList;

    n1.key = 10;
    n2.key = 20;
    n3.key = 30;
    n4.key = 40;
    n5.key = 50;
    n6.key = 60;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = NULL;


    printList(&n1);

    newList = listRotate(&n1,3);

    printList(newList);

    return 0;
}

void printList(Node *cur) {
    if (!cur){
        printf("\n");
        return;
    }

    printf("%d\t",cur->key);
    printList(cur->next);
}



Node *listRotate(Node *head, int k) {
    Node *curNode;
    int listLen;
    int i;

    /*  move curNode to point at last node  */
    for(curNode=head, listLen=1; curNode->next != NULL; curNode = curNode->next, listLen++);

    /*  connect head to tail    */
    curNode->next = head;

    curNode = head;
    /*  curNode points to newList's tail    */
    for(i=0; i<listLen-k-1; i++){
        curNode=curNode->next;
    }

    /*  next node after tail is the new head    */
    head = curNode->next;

    /*  set curNode's next to tail by setting it's next field to NULL   */
    curNode->next = NULL;

    return head;
}


