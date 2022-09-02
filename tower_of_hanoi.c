#include<stdio.h>
void tower(int n,char sour,char temp,char dest)
{
    if(n==1)
    {
        printf("Move disc 1 from %c to %c\n",sour,dest);

    }
    else{
        tower(n-1,sour,dest,temp);
        printf("Move %d disc from %c to %c\n",n,sour,dest);
        tower(n-1,temp,sour,dest);
        }
}
int main()
{
    int n;
    printf("enter the number of disc\n");
    scanf("%d",&n);
    tower(n,'S','T','D');
    return 0;
}
