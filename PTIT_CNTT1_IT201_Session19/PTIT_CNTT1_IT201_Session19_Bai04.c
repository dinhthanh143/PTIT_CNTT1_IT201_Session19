#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void InOrder(Node *root) {
    if (root == NULL) return;
    InOrder(root->left);
    printf("%d \n",root->data);
    InOrder(root->right);
}
int main(){
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    InOrder(root);
    return 0;
}
