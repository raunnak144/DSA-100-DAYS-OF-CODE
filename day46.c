#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create Node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue Node
struct Queue {
    struct Node* data;
    struct Queue* next;
};

struct Queue* front = NULL;
struct Queue* rear = NULL;

// Enqueue
void enqueue(struct Node* node) {
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->data = node;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

// Dequeue
struct Node* dequeue() {
    if (front == NULL)
        return NULL;

    struct Queue* temp = front;
    struct Node* node = temp->data;

    front = front->next;
    if (front == NULL)
        rear = NULL;

    free(temp);
    return node;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    enqueue(root);

    while (front != NULL) {
        struct Node* current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(current->left);

        if (current->right != NULL)
            enqueue(current->right);
    }
}

// Main Function
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}