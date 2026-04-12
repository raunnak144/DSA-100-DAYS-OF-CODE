#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Queue node for BFS
struct QNode {
    struct TreeNode* node;
    int hd; // horizontal distance
};

// Simple queue implementation
struct Q {
    struct QNode* arr;
    int front, rear, size;
};

struct Q* createQueue(int size) {
    struct Q* q = (struct Q*)malloc(sizeof(struct Q));
    q->arr = (struct QNode*)malloc(size * sizeof(struct QNode));
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

void enqueue(struct Q* q, struct TreeNode* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

struct QNode dequeue(struct Q* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Q* q) {
    return q->front == q->rear;
}

// Vertical Order Traversal
void verticalOrder(struct TreeNode* root) {
    if (root == NULL) return;

    // Map HD → list of nodes (using array for simplicity)
    int offset = 1000; // shift to handle negative HD
    int maxSize = 2000;
    int* map[maxSize];
    int count[maxSize];
    for (int i = 0; i < maxSize; i++) {
        map[i] = (int*)malloc(100 * sizeof(int));
        count[i] = 0;
    }

    struct Q* q = createQueue(1000);
    enqueue(q, root, 0);

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);
        struct TreeNode* node = temp.node;
        int hd = temp.hd;

        map[hd + offset][count[hd + offset]++] = node->val;

        if (node->left) enqueue(q, node->left, hd - 1);
        if (node->right) enqueue(q, node->right, hd + 1);
    }

    // Print vertical order
    for (int i = 0; i < maxSize; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

// Example usage
int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}
