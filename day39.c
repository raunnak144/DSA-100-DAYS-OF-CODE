#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int *a;        // heap array
    int size;      // number of elements in heap
    int capacity;  // allocated capacity
} MinHeap;

void ensure_capacity(MinHeap *h) {
    if (h->size < h->capacity) return;
    int newCap = (h->capacity == 0 ? 4 : h->capacity * 2);
    int *na = (int*)realloc(h->a, newCap * sizeof(int));
    if (!na) {
        // If realloc fails, exit gracefully
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    h->a = na;
    h->capacity = newCap;
}

void swap(int *x, int *y) {
    int t = *x; *x = *y; *y = t;
}

// Move element at index i up to restore heap property
void siftUp(MinHeap *h, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->a[p] <= h->a[i]) break;
        swap(&h->a[p], &h->a[i]);
        i = p;
    }
}

// Move element at index i down to restore heap property
void siftDown(MinHeap *h, int i) {
    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < h->size && h->a[l] < h->a[smallest]) smallest = l;
        if (r < h->size && h->a[r] < h->a[smallest]) smallest = r;

        if (smallest == i) break;
        swap(&h->a[i], &h->a[smallest]);
        i = smallest;
    }
}

void insertKey(MinHeap *h, int x) {
    ensure_capacity(h);
    h->a[h->size] = x;
    h->size++;
    siftUp(h, h->size - 1);
}

int peekMin(MinHeap *h, int *ok) {
    if (h->size == 0) { *ok = 0; return -1; }
    *ok = 1;
    return h->a[0];
}

int extractMin(MinHeap *h, int *ok) {
    if (h->size == 0) { *ok = 0; return -1; }
    *ok = 1;
    int root = h->a[0];
    h->a[0] = h->a[h->size - 1];
    h->size--;
    if (h->size > 0) siftDown(h, 0);
    return root;
}

int main(void) {
    MinHeap h = {NULL, 0, 0};

    int N;
    if (scanf("%d", &N) != 1) return 0;
    // consume the newline after N
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    char line[128];
    for (int i = 0; i < N; i++) {
        if (!fgets(line, sizeof(line), stdin)) break;

        // Trim trailing newline
        size_t len = strlen(line);
        if (len && line[len - 1] == '\n') line[len - 1] = '\0';

        if (strncmp(line, "insert", 6) == 0) {
            // Parse: insert x
            int x;
            if (sscanf(line + 6, "%d", &x) == 1) {
                insertKey(&h, x);
            } else {
                // malformed insert — ignore silently or handle as needed
            }
        } else if (strcmp(line, "peek") == 0) {
            int ok;
            int v = peekMin(&h, &ok);
            if (!ok) printf("-1\n");
            else printf("%d\n", v);
        } else if (strcmp(line, "extractMin") == 0) {
            int ok;
            int v = extractMin(&h, &ok);
            if (!ok) printf("-1\n");
            else printf("%d\n", v);
        } else {
            // Unknown command — ignore
        }
    }

    free(h.a);
    return 0;
}