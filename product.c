//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
//PROGRAM-3
#include<stdio.h>
#include<string.h>
void sort(char [][10],int);
int main()
{
	char a[15][10]={' '},t[15][10],ch,s[20];
	FILE* fp;
	int n=10,i=0,j;
	fp=fopen("product.txt","w+");
	while((ch=getchar())!=EOF)
fputc(ch,fp);
rewind(fp);
while(fscanf(fp,"%s",a[i])!=EOF)
{
i++;
}
	fclose(fp);
	printf("array before sorting\n");
	for(j=0;j<i;j++)
	printf("%s\n",a[j]);
	sort(a,i);
	//after sorting
	printf("after sorting\n");
	for(j=0;j<i;j++)
	printf("%s\n",a[j]);
return 0;
}
void sort(char a[][10],int n)
{
	char temp[20];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{ 
			if(strcmp(a[j],a[j+1])==1)
			{
			strcpy(temp,a[j]);
			strcpy(a[j],a[j+1]);
			strcpy(a[j+1],temp);
		}
	}
	}
}
