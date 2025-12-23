#include <stdio.h>

int adj[20][20], visited[20], queue[20];
int n, front = 0, rear = 0;

void bfs(int start)
{
    int i;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
