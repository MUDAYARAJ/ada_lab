#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
void split(int[],int,int);
void combine(int[],int,int,int);
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
            printf("\nENTER NUMBER OF ARRAY ELEMENTS: ");
            scanf("%d", &n);
            printf("\nENTER ARRAY ELEMENTS: ");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &a[i]);
            }
            start = clock();
            split(a, 0, n - 1);
            end = clock();
            printf("\nSORTED ARRAY IS: ");
            for (i = 0; i < n; i++)
                printf("%d\t", a[i]);
            printf("\n TIME TAKEN TO SORT %d NUMBERS IS %f SECS", n, (((double)(end - start)) / CLOCKS_PER_SEC));
            break;
        case 2:
            n = 500;
            while (n <= 14500)
            {
                for (i = 0; i < n; i++)
                {
                     a[i]=rand()%n;
                    //a[i] = n - i;
                }
                start = clock();
                split(a, 0, n - 1);
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

void split(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        split(a, low, mid);
        split(a, mid + 1, high);
        combine(a, low, mid, high);
    }
}

void combine(int a[], int low, int mid, int high)
{
    int c[15000], i, j, k;
    i = k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            ++k;
            ++i;
        }
        else
        {
            c[k] = a[j];
            ++k;
            ++j;
        }
    }
    if (i > mid)
    {
        while (j <= high)
        {
            c[k] = a[j];
            ++k;
            ++j;
        }
    }
    if (j > high)
    {
        while (i <= mid)
        {
            c[k] = a[i];
            ++k;
            ++i;
        }
    }
    for (i = low; i <= high; i++)
    {
        a[i] = c[i];
    }
}

