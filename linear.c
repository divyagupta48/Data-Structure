//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
#include<stdio.h>
#include<string.h>
void input(char [][10],int);
void search(char [][10],int,char[]);
int main()
{
	int n;
	char a[10][10],wrd[10];
	printf("enter the length of ARRAY:");
	scanf("%d",&n);
	input(a,n);
	printf("enter the word to b searched:\n");
	scanf("%s",wrd);
	search(a,n,wrd);
	return 0;
}
void input(char a[10][10],int n)
{
	int i;
	printf("enter the ARRAY:");
	for(i=0;i<n;i++)
	scanf("%s",a[i]);
}
void search(char a[10][10],int n,char wrd[])
{
	int i,flag=0,pos;
	for(i=0;i<n;i++)
	{
			if(strcmp(a[i],wrd)==0)
			{
			flag=1;
			pos=i+1;
		}
	}
	if(flag==1)
	{
		printf("word searched at position:%d",pos);
	}
	}

