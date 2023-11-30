#include <stdio.h>
#include <stdlib.h>
void stuffered11data(int[],int);
void destuffereddata(int[],int);
int main()
{
  int i,n;
  int a[20];
  
  printf("enter the data size:\t");
  scanf("%d",&n);
  
  printf("enter the data :\t");
  for (i=0;i<n;i++)
  {
  scanf("%d",&a[i]);
  }
  
  stuffered11data(a,n);
  return 0;
}
void stuffered11data(int y[20],int n1)
{
  int b[30];
  int i=0,j=0,h;
  int count=0;
  while(i<n1)
    {
      if(y[i]==1 && count<5)
      {
        b[j]=y[i];
        j++;
		i++;
        count+=1;
      }
      else if(y[i]==1 && count==5)
      {
        b[j]=0;
        j+=1;
        
        b[j]=y[i];
        j++;i++;
        
        count=1;
      }
      else{
        b[j]=y[i];
        j++;
		i++;
        count=0;
      }
    }
  printf("stuffeed data is :\t");
  for(h=0;h<j;h++)
    {
      printf("%d",b[h]);
    }
  destuffereddata(b, j);
}
void destuffereddata(int z[30],int s1)
{
  int count=0;
  int i=0,j=0,h;
  int c[20];
  while(i<s1)
    {
      if (z[i]==1 && count<5)
      {
        c[j]=z[i];
        j++;i++;
        count+=1;
        
      }
      else if (z[i+1]==1 && count==5)
      { 
          i+=1;
          c[j]=z[i];
          j++;i++;
          count=1;
      }
    else{
          c[j]=z[i];
          j++;i++;
          count=0;
        } 
}
    printf("\ndestuffeed data is :\t");
    for(h=0;h<j;h++)
    {
      printf("%d",c[h]);
    }
    printf("\n");
}


// output
// enter the data size:    13
// enter the data :        1
// 1
// 1
// 1
// 1
// 1
// 0
// 1
// 1
// 1
// 1
// 1
// 1
// stuffeed data is :      111110101111101
// destuffeed data is :    1111110111111
