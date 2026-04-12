#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10000

// Adjacency list node
struct Node {
    int v, w;
    struct Node* next;
};

struct Node* newNode(int v, int w) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->v = v; t->w = w; t->next = NULL;
    return t;
}

// Min-heap node
struct HNode { int v, d; };

// Swap
void swap(struct HNode* a, struct HNode* b) {
    struct HNode t = *a; *a = *b; *b = t;
}

// Heapify
void heapify(struct HNode h[], int n, int i) {
    int s = i, l = 2*i+1, r = 2*i+2;
    if (l < n && h[l].d < h[s].d) s = l;
    if (r < n && h[r].d < h[s].d) s = r;
    if (s != i) { swap(&h[i], &h[s]); heapify(h, n, s); }
}

// Push
void push(struct HNode h[], int* n, int v, int d) {
    int i = (*n)++;
    h[i].v = v; h[i].d = d;
    while (i && h[i].d < h[(i-1)/2].d) {
        swap(&h[i], &h[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Pop (extract min)
struct HNode pop(struct HNode h[], int* n) {
    struct HNode r = h[0];
    h[0] = h[--(*n)];
    heapify(h, *n, 0);
    return r;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[MAX] = {NULL};

    int u, v, w;

    // Input edges (0-based; remove second add if directed)
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        struct Node* t = newNode(v, w);
        t->next = adj[u];
        adj[u] = t;

        // undirected:
        t = newNode(u, w);
        t->next = adj[v];
        adj[v] = t;
    }

    int s; // source
    scanf("%d", &s);

    int dist[MAX];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[s] = 0;

    struct HNode heap[MAX];
    int size = 0;

    push(heap, &size, s, 0);

    while (size > 0) {
        struct HNode cur = pop(heap, &size);
        int node = cur.v;

        // 🔥 Skip outdated entries
        if (cur.d > dist[node]) continue;

        struct Node* t = adj[node];
        while (t) {
            int nb = t->v, wt = t->w;

            if (dist[node] != INT_MAX && dist[node] + wt < dist[nb]) {
                dist[nb] = dist[node] + wt;
                push(heap, &size, nb, dist[nb]);
            }
            t = t->next;
        }
    }

    printf("Shortest distances:\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("%d -> INF\n", i);
        else printf("%d -> %d\n", i, dist[i]);
    }

    return 0;
}