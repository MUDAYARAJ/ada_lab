#include <stdio.h>
#include <stdlib.h>
void knapsack();
int max(int a, int b);
int n, m, p[10], w[10], v[10][10];
void main()
{
    printf("enter number of objects\n");
    scanf("%d", &n);
    printf("enter weight of each item\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("enter the profit\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    printf("enter the knapsack capacity\n");
    scanf("%d", &m);
    knapsack();
}
void knapsack()
{
    int x[10];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (j - w[i] < 0)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], p[i] + v[i - 1][j - w[i]]);
        }
    }
    printf("the output is\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
    printf("the optimal solution is %d \n", v[n][m]);
    printf("the solution vector is\n");
    for (int i = n; i >= 1; i--)
    {
        if (v[i][m] != v[i - 1][m])
        {
            x[i] = 1;
            m = m - w[i];
        }
        else
            x[i] = 0;
    }
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1)
        {
            c++;
            printf("%d\t", w[i]);
        }
    }
    printf("count of items selected =%d", c);
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
