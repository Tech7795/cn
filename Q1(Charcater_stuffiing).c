#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[40],b[40]="",c[40]="",start,end,s[3],e[3],t[3],x[3],y[3];
	int i;
	
	printf("enter the string :");
	fgets(a,sizeof(a),stdin);
	size_t l=strlen(a);
	a[l-1]='\0';
	
printf("\nEnter starting delimiter : ");
scanf(" %c", &start);

printf("\nEnter ending delimiter : ");
scanf(" %c", &end);
	
	x[0]=s[0]=s[1]=start;
	x[1]=s[2]='\0';
	
    y[0]=e[0]=e[1]=end;
	y[1]=e[2]='\0';
	
	strcat(b,x);
	for(i=0;i<strlen(a);i++)
	{
		t[0]=a[i];
		t[1]='\0';
		if(t[0]==start)
		{
			strcat(b,s);
		}
		else if(t[0]==end)
		{
			strcat(b,e);
		}
		else
		{
			strcat(b,t);
		}
	}
	strcat(b,y);
	printf("\n after stuffing the data is : %s",b);
	printf("\nDestuffed data: ");
	
	for(i=1;i<strlen(b)-1;i++)
	{
		t[0]=b[i];
		t[1]='\0';
		
		if((b[i]==start&&b[i+1]==start)||(b[i]==end&&b[i+1]==end))
		{
			strcat(c,t);
			i++;
		}
		else{
			strcat(c,t);
		}
	}
	printf("%s",c);
	return 0;
}

// output
// enter the string :sai krishna

// Enter starting delimiter : a

// Enter ending delimiter : n

// after stuffing the data is : asaai krishnnaan
// Destuffed data: sai krishna
