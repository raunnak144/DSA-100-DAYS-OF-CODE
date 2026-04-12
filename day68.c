#include <stdio.h>
#include <stdlib.h>

#define MAX 1000   // safer limit

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[MAX] = {NULL};
    int indegree[MAX] = {0};

    int u, v;

    // Input edges (0-based assumed)
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* temp = newNode(v);
        temp->next = adj[u];
        adj[u] = temp;

        indegree[v]++;
    }

    int queue[MAX];
    int front = 0, rear = 0;

    // Push indegree 0 nodes
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int topo[MAX];
    int index = 0;

    // Kahn's Algorithm
    while (front < rear) {
        int node = queue[front++];
        topo[index++] = node;

        struct Node* temp = adj[node];
        while (temp) {
            int neighbor = temp->data;

            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    // Check cycle
    if (index != n) {
        printf("Cycle detected!\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}