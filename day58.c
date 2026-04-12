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
struct Node* build(int preorder[], int inorder[],
                   int preStart, int preEnd,
                   int inStart, int inEnd) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    struct Node* root = newNode(preorder[preStart]);

    int rootIndex = findIndex(inorder, inStart, inEnd, root->data);
    int leftSize = rootIndex - inStart;

    // Left subtree
    root->left = build(preorder, inorder,
                       preStart + 1,
                       preStart + leftSize,
                       inStart,
                       rootIndex - 1);

    // Right subtree
    root->right = build(preorder, inorder,
                        preStart + leftSize + 1,
                        preEnd,
                        rootIndex + 1,
                        inEnd);

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

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = build(preorder, inorder, 0, n - 1, 0, n - 1);

    // Print inorder to verify
    printInorder(root);

    return 0;
}