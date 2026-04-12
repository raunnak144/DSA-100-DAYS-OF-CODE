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

// DFS for cycle detection
int dfs(int node, int parent, struct Node* adj[], int visited[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return 1;
        }
        else if (neighbor != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[100] = {NULL};

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

    int visited[100] = {0};
    int hasCycle = 0;

    // Handle disconnected graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}