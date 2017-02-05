//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void merge(char[][20],char[][20],int,int,int);
void m_sort(char[][20],char[][20],int,int);
void m_merge(char[][20],char[][20],int);
int main()
{
	char a[20][20],t[20][20]={' '},ch,s[20];
	FILE* fp;
	int i=0,j;
	fp=fopen("item.txt","w+");
	while((ch=getchar())!=EOF)
fputc(ch,fp);
rewind(fp);
while(fscanf(fp,"%s",a[i])!=EOF)
{
	i++;
}
	fclose(fp);
	printf("array before sorting:\n");
	for(j=0;j<i;j++)
	printf("%s\n",a[j]);
	m_merge(a,t,i);
	//after sorting
	printf("array after sorting:\n");
	for(j=0;j<i;j++)
	printf("%s\n",a[j]);
return 0;
}
void m_merge(char a[][20],char t[][20],int size)
{
	m_sort(a,t,0,size-1);
}
void m_sort(char a[][20],char t[][20],int lb,int ub)
{   
	int mid=0;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		m_sort(a,t,lb,mid);
		m_sort(a,t,mid+1,ub);
		merge(a,t,lb,mid,ub);
	}
}
void merge(char a[][20],char t[][20],int lb,int mid,int ub)
{
	int i,end=mid+1,k=0;
	while(lb<=mid&&end<=ub)
	{
		if(strcmp(a[lb],a[end])==-1)
		{
			strcpy(t[k],a[lb]);
			k++;
			lb++;
		}
		else if(strcmp(a[lb],a[end])==1)
		{
			strcpy(t[k],a[end]);
			end++;
			k++;
		}
		}
		while(lb<=mid)
		strcpy(t[k++],a[lb++]);
		while(end<=ub)
		{
		strcpy(t[k],a[end]);
		end++;
		k++;
	}
		for(i=0;i<=ub;i++)
		strcpy(a[i],t[i]);
	}

	
