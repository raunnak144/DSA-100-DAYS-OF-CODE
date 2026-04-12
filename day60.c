#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create Node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build Tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[1000];

    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n) {
            curr->left = newNode(arr[i++]);
            queue[rear++] = curr->left;
        }

        if (i < n) {
            curr->right = newNode(arr[i++]);
            queue[rear++] = curr->right;
        }
    }

    return root;
}

// Count nodes
int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check CBT
int isCBT(struct Node* root, int index, int total) {
    if (!root) return 1;

    if (index >= total) return 0;

    return isCBT(root->left, 2 * index + 1, total) &&
           isCBT(root->right, 2 * index + 2, total);
}

// Check Min-Heap property
int isHeap(struct Node* root) {
    if (!root->left && !root->right)
        return 1;

    if (!root->right) {
        return (root->data <= root->left->data) &&
               isHeap(root->left);
    }

    return (root->data <= root->left->data &&
            root->data <= root->right->data &&
            isHeap(root->left) &&
            isHeap(root->right));
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    int total = countNodes(root);

    if (isCBT(root, 0, total) && isHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}