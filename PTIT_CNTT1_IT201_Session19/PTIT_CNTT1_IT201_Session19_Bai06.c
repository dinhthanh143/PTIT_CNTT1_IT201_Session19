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


void BFS(Node *root, int value) {
    if (root == NULL) {
        printf("FALSE\n");
        return;
    }
    Queue *q = createQueue(100);
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node *node = q->arr[q->front++];
        if (node->data == value) {
            printf("TRUE\n");
            return;
        }
        if (node->left)  enqueue(q, node->left);
        if (node->right) enqueue(q, node->right);
    }
    printf("FALSE\n");
    free(q->arr);
    free(q);
}

void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int value;
    printf("Moi nhap gia tri muon tim: ");
    scanf("%d", &value);

    BFS(root, value);
    freeTree(root);
    return 0;
}