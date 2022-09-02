#include<stdio.h>
#include<conio.h>
int gcd(int m,int n)
{
    if(n==0)
    {
        return m;
    }
    else if(m<n)
    {
        return(n,m);
    }
    else
    {
        return gcd(n,m%n);
    }
}
void main()
{
    int m,n,ans;
    printf("Enter the two numbers \n");
    scanf("%d %d",&m,&n);
    ans=gcd(m,n);
    printf("GCD=%d",ans);
}
