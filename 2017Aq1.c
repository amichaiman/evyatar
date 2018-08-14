#include <stdio.h>

typedef struct node{
    int key;
    struct node *left, *right;
} Node;


int isPositiveTree(Node *cur, int *sum);

int main(){
    Node root;
    Node n1;
    Node n2;
    Node n3;
    Node n4;

    root.key = 100;
    n1.key = 90;
    n2.key = 110;
    n3.key = 105;
    n4.key = 120;

    root.left = &n1;
    root.right = &n2;

    n1.left = n1.right = NULL;

    n2.left = &n3;
    n2.right = &n4;

    n3.left = n3.right = NULL;
    n4.left = n4.right = NULL;

    printf("it is%s a positive tree\n", isPositiveTree(&root,NULL) ? "" : " not");

    return 0;
}




int isPositiveTree(Node *cur, int *sum){
    if (!cur){
        return 0;
    }

    if (sum){       //are we not the root
        *sum = *sum + cur->key;
    }

    if (!cur->left && !cur->right){
        return 1;
    }

    int sumLeft=0, sumRight=0;

    return isPositiveTree(cur->right, &sumRight) && isPositiveTree(cur->left, &sumLeft) && (sumLeft < sumRight);

}