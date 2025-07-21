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
int search(Node *root, int value) {
   if (root == NULL) {
      return 0;
   }
   if (root->data == value) {
      return 1;
   }
   return search(root->left, value) || search(root->right, value);
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
   printf("Moi nhap gia tri muon tim: ");
   int value;
   int flag = 0;
   scanf("%d", &value);
   if (search(root, value)) {
      printf("\nTrue");
   }else {
      printf("\nFalse");
   }
   freeTree(root);

   return 0;
}
