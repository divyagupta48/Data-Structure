//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
//PROGRAM-4
#include<stdio.h>
#include<string.h>
void input(char [][20],int);
void sort(char [][20],int);
int main()
{
	char a[5][20],i,n;
	printf("enter the length of array:");
	scanf("%d",&n);
	input(a,n);
	sort(a,n);
	printf("sorted array:\n");
	for(i=0;i<n;i++)
	printf("%s\n",a[i]);
	return 0;
}
void input(char a[5][20],int n)
{
	int i;
	printf("enter the array:");
	for(i=0;i<n;i++)
	scanf("%s",a[i]);
}
void sort(char a[5][20],int n)
{
	char temp[20];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{ 
			if(strcmp(a[i],a[j])==1)
			{
			strcpy(temp,a[j]);
			strcpy(a[j],a[i]);
			strcpy(a[i],temp);
		}
	}
	}
}
