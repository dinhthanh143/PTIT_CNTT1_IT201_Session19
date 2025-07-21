#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Queue {
    Node **arr;
    int front;
    int rear;
    int cap;
} Queue;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Queue *createQueue(int cap) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->arr = (Node**)malloc(sizeof(Node*) * cap);
    q->front = 0;
    q->rear = -1;
    q->cap = cap;
    return q;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}
int isFull(Queue *q) {
    return q->rear == q->cap - 1;
}

void enqueue(Queue *q, Node *node) {
    if (isFull(q)) return;
    q->arr[++q->rear] = node;
}


void addToTree(Node *root, int value) {
    if (root == NULL) {
        root = createNode(value);
        return;
    }
    Queue *q = createQueue(100);
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node *node = q->arr[q->front++];
        if (node->left == NULL) {
            node->left = createNode(value);
            return;
        }else {
            enqueue(q, node->left);
        }
        if (node->right == NULL) {
            node->right = createNode(value);
            return;
        }else {
            enqueue(q, node->right);
        }
    }
}
void printTree(Node *root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%d \t", root->data);
    printTree(root->right);
}
int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    printTree(root);
    int value;
    printf("\nMoi nhap gia tri muon them: ");
    scanf("%d", &value);
    addToTree(root, value);
    printf("\n");
    printTree(root);

    return 0;
}