#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
void insertionSort(int[], int);
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
            insertionSort(a, n);
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
                insertionSort(a, n);
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

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

