#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n, m;

void dfs(int node)
{
    visited[node] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (adj[node][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}