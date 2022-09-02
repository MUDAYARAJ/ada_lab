
#include<stdio.h>
#include<conio.h>
int a[10][10],n,vis[10];
int dfs(int);
int main()
{
 int i,j,src,ans;
 for(j=1;j<=n;j++)
 {
  vis[j]=0;
 }
 printf("\nENTER NO OF NODES: ");
 scanf("%d",&n);
 printf("\nENTER ADJACENCY MATRIX:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 printf("\nENTER SOURCE NODE:");
 scanf("%d",&src);
 ans=dfs(src);
 if(ans==1)
 {
  printf("\nGRAPH IS CONNECTED\n");
 }
 else
 {
  printf("\nGRAPH IS NOT CONNECTED\n");
 }
}

int dfs(int src)
{
 int j;
 vis[src]=1;
 for(j=1;j<=n;j++)
 {
  if(a[src][j]==1&&vis[j]!=1)
  {
   dfs(j);
  }
 }
 for(j=1;j<=n;j++)
 {
  if(vis[j]!=1)
  {
   return 0;
  }
 }
 return 1;
}

