#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* adj[100] = {NULL};

    int m;
    scanf("%d", &m);

    int u, v;

    // Input edges (undirected)
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* temp = newNode(v);
        temp->next = adj[u];
        adj[u] = temp;

        temp = newNode(u);
        temp->next = adj[v];
        adj[v] = temp;
    }

    int s;
    scanf("%d", &s);

    int visited[100] = {0};
    int queue[100];
    int front = 0, rear = 0;

    // Start BFS
    queue[rear++] = s;
    visited[s] = 1;

    printf("BFS Traversal:\n");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        struct Node* temp = adj[node];
        while (temp) {
            if (!visited[temp->data]) {
                queue[rear++] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }

    return 0;
}