#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Min Heap Node
struct HeapNode {
    int node;
    int dist;
};

// Swap
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Min Heapify
void heapify(struct HeapNode heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

// Extract min
struct HeapNode extractMin(struct HeapNode heap[], int* size) {
    struct HeapNode root = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return root;
}

// Insert into heap
void insertHeap(struct HeapNode heap[], int* size, int node, int dist) {
    int i = (*size)++;
    heap[i].node = node;
    heap[i].dist = dist;

    while (i && heap[i].dist < heap[(i-1)/2].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX] = {0};

    int u, v, w;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // remove if directed
    }

    int s;
    scanf("%d", &s);

    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    dist[s] = 0;

    struct HeapNode heap[1000];
    int size = 0;

    insertHeap(heap, &size, s, 0);

    while (size > 0) {
        struct HeapNode curr = extractMin(heap, &size);
        int u = curr.node;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    insertHeap(heap, &size, v, dist[v]);
                }
            }
        }
    }

    // Print result
    printf("Shortest distances:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", i, dist[i]);
    }

    return 0;
}