#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Adjacency list (array of pointers)
    struct Node* adj[100] = {NULL};

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Add v to u
        struct Node* temp = newNode(v);
        temp->next = adj[u];
        adj[u] = temp;

        // For undirected graph (add u to v)
        temp = newNode(u);
        temp->next = adj[v];
        adj[v] = temp;
    }

    // Print adjacency list
    printf("Adjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);

        struct Node* temp = adj[i];
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}