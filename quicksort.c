//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
//PROGRAM-5
#include<stdio.h>
#include<string.h>
void input(char [][20],int);
void qsort(char [][20],int,int);
int qpart(char [][20],int,int);
int main()
{
	char a[5][20],i,n;
	printf("enter the length of array:");
	scanf("%d",&n);
	input(a,n);
	qsort(a,0,n-1);
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
void qsort(char a[5][20],int l,int r)
{
	int j=0;
	if(l<r)
	{
		j=qpart(a,l,r);
		qsort(a,l,j-1);
		qsort(a,j+1,r);
	}
}
int qpart(char a[5][20],int l,int r)
{
	int i=l,j=r;
	char p[20],temp[20];
	strcpy(p,a[r]);
	while(i<j)
	{
		while(strcmp(a[i],p)==-1)
		i++;
		while((strcmp(a[j],p)==0)||(strcmp(a[j],p)==1)&&i<j)
		j--;
		if(i<j)
		{
			strcpy(temp,a[i]);
			strcpy(a[i],a[j]);
			strcpy(a[j],temp);
		}
	}
	strcpy(temp,a[i]);
	strcpy(a[i],a[r]);
	strcpy(a[r],temp);
	return i;
}

