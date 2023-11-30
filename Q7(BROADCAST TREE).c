#include<stdio.h>
int p,q,u,v,n,i,j;
int min=99,mincost=0;
int t[50][2],parent[50],edge[50][50];
void Sunion(int l,int m)
{
parent[l]=m;
}
int find(int k)
{
if(parent[k]>0)
k=parent[k];
return k;
}
int main()
{
   printf("\n Enter the number of nodes: ");
   scanf("\t%d",&n);
   printf("Enter Matrix:\n");
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
       scanf("%d",&edge[i][j]);
   }
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
         if(edge[i][j]!=0)
            if(min>edge[i][j])
             {
               min=edge[i][j];
               u=i;
               v=j;
            }
	p=find(u);
  q=find(v);
    if(p!=q)
      {
           t[i][0]=u;
           t[i][1]=v;
           mincost+=edge[u][v];
           Sunion(p,q);
      }
    else
    {
t[i][0]=-1;
t[i][1]=-1;
}
min=99;
}
printf("Minimum cost is %d\nMinimum spanning tree is\n" ,mincost);
for(i=0;i<n;i++)
if(t[i][0]!=-1 && t[i][1]!=-1)
{
printf("%c %c %d", 65+t[i][0],65+t[i][1],edge[t[i][0]][t[i][1]]);
printf("\n");
}
}

// output

//  Enter the number of nodes: 4
// Enter Matrix:
// 0 8 0 5
// 8 0 2 0
// 0 2 0 3
// 5 0 3 0
// Minimum cost is 10
// Minimum spanning tree is
// A D 5
// B C 2
// D C 3
