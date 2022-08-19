#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
void warshall(int p[10][10], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                p[i][j] = max(p[i][j], p[i][k] && p[k][j]);
            }
        }
    }
}
int main()
{
    int p[10][10], n;
    printf("enter the number of edges\n");
    scanf("%d", &n);
    printf("enter the matrix form of the graph\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &p[i][j]);
    }
    warshall(p, n);
    printf("transitive matrix is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }
}