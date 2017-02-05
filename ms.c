/*Q16 Write a C program to create a file named as “item.txt”. Store names of ten items such as “keyboard”, “mouse” etc.  Then read those names from the same file and sort them in ascending        order using Merge sort. Finally print them. */
#include<stdio.h>
#include<string.h>
void merge(char arr[][100],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    char L[n1][100],R[n2][100];
    for(i=0;i<n1;i++)
        strcpy(L[i],arr[l+i]);
    for(j=0;j<n2; j++)
        strcpy(R[j],arr[m+1+j]);
        i=0;
        j=0;
        k=l;
    while(i<n1&&j<n2)
    {
        if(strcmp(L[i],R[j])<=0)
        {
            strcpy(arr[k],L[i]);
            i++;
        }
        else
        {
            strcpy(arr[k],R[j]);
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        strcpy(arr[k],L[i]);;
        i++;
        k++;
    }
    while(j<n2)
    {
        strcpy(arr[k],R[j]);
        j++;
        k++;
    }
}
void mergeSort(char arr[][100],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
void printArray(char arr[][100],int n)
{
	int i;
	for(i=0;i<n;i++)
		puts(arr[i]);	
}
int main()
{
	FILE *fp1;
	char oneword[100];
	char c;
	char a[100][100];
	int i=0,n=0;
    fp1= fopen("items.txt","r");
    do
    {       
       c=fscanf(fp1,"%s",oneword);
       strcpy(a[n],oneword); 
	   memset(oneword,0,100);
	   n++;
    }while(c!=EOF);  
    fclose(fp1);
    printf("\nOrignal Contents Of File Are \n\n");
    printArray(a,n);
    mergeSort(a,0,n-1);
    printf("\nFinal Contents Of File Are \n");
    printArray(a,n);
    fp1 = fopen("items.txt","r");
    return 0;
}

