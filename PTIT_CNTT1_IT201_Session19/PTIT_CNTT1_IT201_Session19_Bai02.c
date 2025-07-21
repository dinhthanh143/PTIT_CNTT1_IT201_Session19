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
void preOrder(Node *root) {
   if (root == NULL) {
      return;
   }
   printf("%d\n", root->data);
   preOrder(root->left);
   preOrder(root->right);
}
void freeTree(Node *root) {
   if (root == NULL) {
      return;
   }
   freeTree(root->left);
   freeTree(root->right);
   free(root);
}
int main(){
   Node *root = createNode(2);
   root->left = createNode(3);
   root->right = createNode(4);
   root->left->left = createNode(5);
   preOrder(root);
   freeTree(root);
   return 0;
}
