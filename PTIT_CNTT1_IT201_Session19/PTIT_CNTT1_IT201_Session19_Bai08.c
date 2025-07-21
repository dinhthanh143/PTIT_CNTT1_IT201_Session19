#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node {
   int data;
   struct Node *left;
   struct Node *right;
} Node;

Node *createNode(int data) {
   Node *node = (Node *)malloc(sizeof(Node));
   node->data = data;
   node->left = NULL;
   node->right = NULL;
   return node;
}
void printTree(Node *root) {
   if (root == NULL) {
      return;
   }
   printTree(root->left);
   printf("%d \t", root->data);
   printTree(root->right);
}
int getHeight(Node *root) {
   if (root == NULL) {
      return -1;
   }
   int left = getHeight(root->left);
   int right = getHeight(root->right);
   if (left > right) {
      return left +1;
   }else {
      return right +1;
   }
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
   // root->left->left->left = createNode(6);
   printTree(root);
   printf("\n%d", getHeight(root));
   freeTree(root);
   return 0;
}
