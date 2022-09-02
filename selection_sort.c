#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<math.h>
void selsort(int n, int a[]);
int main()
{
    int a[15000], n, i, j, ch, temp;
    clock_t start, end;
    while (1)
    {
        printf("\n1:FOR MANUAL ENTRY");
        printf("\n2:DISPLAY TIME TAKEN TO SORT ELEMENTS FROM RANGE 500 TO 15000");
        printf("\n3:EXIT");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nENTER NUMBER OF ELEMENTS: ");
            scanf("%d", &n);
            printf("\nENTER ARRAY ELEMENTS: ");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &a[i]);
            }
            start = clock();
            selsort(n, a);
            end = clock();
            printf("\nSORTED ELEMENTS IS: ");
            for (i = 0; i < n; i++)
                printf("%d\t", a[i]);
            printf("\n TIME TAKEN TO SORT %d NUMBERS IS %f SECS", n, (((double)(end - start)) / CLOCKS_PER_SEC));
            break;
        case 2:
            n = 500;
            while (n <= 15000)
            {
                for (i = 0; i < n; i++)
                {
                    a[i]=rand()%n;
                    //a[i] = n - i;
                }
                start = clock();
                selsort(n, a);
                for (j = 0; j < 500000; j++)
                {
                    temp = 38 / 600;
                }
                end = clock();
                printf("\n TIME TAKEN TO SORT %d NUMBERS IS %f SECS", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                n = n + 1000;
            }
            break;
        case 3:
            exit(0);
        }
        getchar();
    }
}

void selsort(int n, int a[])
{
    int i, j, t, small, pos;
    for (i = 0; i < n - 1; i++)
    {
        pos = i;
        small = a[i];
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < small)
            {
                small = a[j];
                pos = j;
            }
        }
        t = a[i];
        a[i] = a[pos];
        a[pos] = t;
    }
}

