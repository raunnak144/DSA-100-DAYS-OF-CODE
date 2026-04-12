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

// DFS function
void dfs(int node, struct Node* adj[], int visited[]) {
    visited[node] = 1;
    printf("%d ", node);

    struct Node* temp = adj[node];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(temp->data, adj, visited);
        }
        temp = temp->next;
    }
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

    printf("DFS Traversal:\n");
    dfs(s, adj, visited);

    return 0;
}