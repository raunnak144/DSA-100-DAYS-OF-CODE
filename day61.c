#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[100][100] = {0};

    int u, v;

    // Choose type (1 = undirected, 2 = directed)
    int type;
    scanf("%d", &type);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if (type == 1) { // undirected
            adj[v][u] = 1;
        }
    }

    // Print adjacency matrix
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}