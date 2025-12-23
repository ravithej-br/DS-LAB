#include <stdio.h>

int adj[20][20], visited[20], n;

void dfs(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

int main()
{
    int i, j;
    int connected = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal starting from vertex 0: ");
    dfs(0);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("Graph is connected\n");
    else
        printf("Graph is not connected\n");

    return 0;
}
