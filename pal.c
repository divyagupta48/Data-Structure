//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
//PROGRAM-1
#include<stdio.h>
int palin(int [],int);
int check(int);
int main()
{
	int a[50],i,n,c;
	printf("enter the length of the array");
	scanf("%d",&n);
	printf("enter the array");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	c=palin(a,n);
	printf("\t\t\tCount of palindrome numbers:%d",c);
	return 0;
}
int palin(int a[50],int n)
{
	int i,c=0,f;
	for(i=0;i<n;i++)
    {
    	f=check(a[i]);
    	if(f==1)
    	c++;
	}
	return c;
}
int check(int n)
{
	int rev=0,d;
	d=n;
	while(n>0)
	{
		rev =(rev*10)+(n%10);
		n=n/10;
	}
	if(rev==d)
	return 1;
	else 
	return 0;
}
