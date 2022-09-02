#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
void quicksort(int[], int, int);
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
            quicksort(a, 0, n - 1);
            end = clock();
            printf("\nSORTED ARRAY IS: ");
            for (i = 0; i < n; i++)
                printf("%d\t", a[i]);
            printf("\n TIME TAKEN TO SORT %d NUMBERS IS %f SECS", n, (((double)(end - start)) / CLOCKS_PER_SEC));
            break;
        case 2:
            n = 500;
            while (n <= 10500)
            {
                for (i = 0; i < n; i++)
                {
                     a[i]=rand()%n;
                    //a[i] = n - i;
                }
                start = clock();
                quicksort(a, 0, n - 1);
                
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

void quicksort(int number[5000],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         for(int x=0;x<100000;x++);
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}

