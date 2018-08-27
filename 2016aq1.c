#include <stdio.h>
#include <stdbool.h>


typedef struct node{
    int key;
    struct node *left, *right;
} Node;


bool isNonDuplicateBST(Node *cur);

int main(){
    Node n1 = {10, NULL,NULL};
    Node n2 = {70, NULL,NULL};
    Node n3 = {75, NULL,NULL};
    Node n4 = {80, NULL,NULL};
    Node n5 = {100, NULL,NULL};
    Node n6 = {196, NULL,NULL};
    Node n7 = {202, NULL,NULL};

    n1.left = &n2;
    n1.right = &n5;

    n2.left = &n3;
    n2.right = &n4;

    n5.left = &n6;
    n5.right = &n7;


    printf("is%s non dup!\n", isNonDuplicateBST(&n1) ? "" : " not");
    return 0;
}

bool isNonDuplicateBST(Node *cur) {
    if (!cur || (!cur->left && !cur->right)){
        return true;
    }
    /*  check that closest from above is legal*/
    if (cur->right){
        Node *closestFromAbove;
        for(closestFromAbove=cur->right; closestFromAbove->left; closestFromAbove = closestFromAbove->left);

        if (closestFromAbove->key <= cur->key){
            return false;
        }
    }


    /*  check that closest from below is legal*/
    if (cur->left){
        Node *closestFromBelow;
        for(closestFromBelow=cur->left; closestFromBelow->right; closestFromBelow= closestFromBelow->right);

        if (closestFromBelow->key >= cur->key){
            return false;
        }
    }

    return isNonDuplicateBST(cur->left) && isNonDuplicateBST(cur->right);
}

