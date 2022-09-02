#include <stdio.h>
#include <conio.h>
int a[10][10], n;
void bfs(int);
int main()
{
    int i, j, src;
    printf("\nENTER NUMBER OF NODES:\t");
    scanf("%d", &n);
    printf("\nENTER ADJACENCY MATRIX:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nENTER SOURCE NODE:\t");
    scanf("%d", &src);
    bfs(src);
}

void bfs(int src)
{
    int q[10], f = 0, r = -1, vis[10], i, j;
    for (j = 1; j <= n; j++)
    {
        vis[j] = 0;
    }
    vis[src] = 1;
    r = r + 1;
    q[r] = src;
    while (f <= r)
    {
        i = q[f];
        f = f + 1;
        for (j = 1; j <= n; j++)
        {
            if (a[i][j] == 1 && vis[j] != 1)
            {
                vis[j] = 1;
                r = r + 1;
                q[r] = j;
            }
        }
    }
    for (j = 1; j <= n; j++)
    {
        if (vis[j] != 1)
        {
            printf("\nNODE %d IS NOT REACHABLE\n", j);
        }
        else
        {
            printf("\nNODE %d IS REACHABLE\n", j);
        }
    }
}

