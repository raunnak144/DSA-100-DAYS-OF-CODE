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

// Find index in inorder
int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build Tree
struct Node* build(int inorder[], int postorder[],
                   int inStart, int inEnd,
                   int* postIndex) {

    if (inStart > inEnd)
        return NULL;

    // Root from postorder
    struct Node* root = newNode(postorder[*postIndex]);
    (*postIndex)--;

    int rootIndex = findIndex(inorder, inStart, inEnd, root->data);

    // RIGHT subtree first
    root->right = build(inorder, postorder,
                        rootIndex + 1, inEnd,
                        postIndex);

    root->left = build(inorder, postorder,
                       inStart, rootIndex - 1,
                       postIndex);

    return root;
}

// Print Inorder (to verify)
void printInorder(struct Node* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = build(inorder, postorder, 0, n - 1, &postIndex);

    // Print inorder to verify
    printInorder(root);

    return 0;
}