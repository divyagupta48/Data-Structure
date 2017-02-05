//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
//PROGRAM-2
//MERGE TWO SORTED ARRAY
#include<stdio.h>
void input(int [],int);
void merge(int [],int [],int,int);
int main()
{
	int a[50],b[50],n1,n2;
	printf("enter the length of frst array:");
	scanf("%d",&n1);
	input(a,n1);
	printf("enter the length of second array:");
	scanf("%d",&n2);
	input(b,n2);
	merge(a,b,n1,n2);
	return 0;
}
void input(int a[50],int n)
{
	int i;
	printf("enter the sorted array:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
}
void merge(int a[50],int b[50],int n1,int n2)
{
	int c[50],k=0,i=0,j=0;
	while((i<n1)&&(j<n2))
	{
		if(a[i]<b[j])
        c[k++]=a[i++];
		else
		c[k++]=b[j++];		
	}
	while(i<n1)
	c[k++]=a[i++];
	while(j<n2)
	c[k++]=b[j++];
	printf("\nmerged array\n");
	for(i=0;i<k;i++)
     printf("%d\n",c[i]);
}
