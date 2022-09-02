#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
int bin_srch(int [],int,int,int);
int lin_srch(int [],int,int,int);
int n,a[10000];
int main()
{
 int ch,key,search_status,temp;
 clock_t end,start;
 long int i, j;
 
 while(1)
 {
  printf("\n1: BINARY SEARCH\t 2: LINEAR SEARCH\t 3: EXIT\n");
  printf("\nENTER YOUR CHOICE:\t");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
      n=1000;
	  while(n<=5000)
	  {
	   for(i=0;i<n;i++)
	   {
	   
	   a[i]=i;
	   }
	   key=a[n-1]; 
	   start=clock();
         
	   search_status=bin_srch(a,0,n-1,key);
	   if(search_status==-1)
              printf("\nKey Not Found");
           else
              printf("\n Key found at position %d",search_status);
          
	   for(j=0;j<500000;j++){ temp=38/600;}
	   end=clock();
	   printf("\nTIME FOR n=%d IS %f SECS",n,(((double)(end-start))/CLOCKS_PER_SEC));
	   n=n+1000;
	  }
	  break;
   case	2:
          n=1000;
	  while(n<=5000)
	  {
           for(i=0;i<n;i++)
	   {
	
	    a[i]=i;
	   }
	   key=a[n-1];
	   start=clock();
	   search_status=lin_srch(a,0,n-1,key);
	   if(search_status==-1)
              printf("\nKey Not Found");
           else
              printf("\n Key found at position %d",search_status);
       
	 for(j=0;j<500000;j++){ temp=38/600;}
	   end=clock();
	   printf("\nTIME FOR n=%d IS %f SECS",n,(((double)(end-start))/CLOCKS_PER_SEC));
	   n=n+1000;
	  }
	  break;
   default:
          exit(0);
  }
  getchar();
 }
}

int bin_srch(int a[],int low,int high,int key)
{
 int mid;
 if(low>high)
 {
  return -1;
 }
 mid=(low+high)/2;
 if(key==a[mid])
 {
  return mid;
 }
 if(key<a[mid])
 {
  return bin_srch(a,low,mid-1,key);
 }
 else
 {
  return bin_srch(a,mid+1,high,key);
 }
}

int lin_srch(int a[],int i,int high,int key)
{
 if(i>high)
 {
  return -1;
 }
 if(key==a[i])
 {
  return i;
 }
 else
 {
  return lin_srch(a,i+1,high,key);
 }
}

