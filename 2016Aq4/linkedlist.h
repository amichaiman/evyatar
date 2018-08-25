#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    void *data;
    struct node *next;
} Node;

typedef struct _linkedList {
    Node *head;
    Node *tail;
} LinkedList;

/* Creates an empty linked list*/
LinkedList* linkedListCreate();
// Adds a data to the list
int linkedListAdd(LinkedList* l, void* data);
// Remove a data from the list
int linkedListRemove(LinkedList* l, void* data);
// Returns 1 if the parameter exists in list and 0 otherwise
int linkedListContains (LinkedList* l, void* data);
// Prints all elements to the standard output
void linkedListPrintAll (LinkedList* l );
// Frees the linked list
void linkedListFree (LinkedList* l);

#endif // LINKEDLIST_