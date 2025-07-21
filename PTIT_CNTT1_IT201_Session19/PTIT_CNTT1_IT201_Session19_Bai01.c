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

int main(){
   printf("Moi nhap so nguyen lam goc: ");
   int value;
   scanf("%d",&value);
   Node *root = createNode(value);
   free(root);
   return 0;
}
