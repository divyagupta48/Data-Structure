#include<stdio.h>
#include<conio.h>
#include<time.h>
void ins(int a[50],int n)
{
     int i,j,temp,c=0;
     clock_t t1,t2;
     t1=clock();
     for(j=1;j<n;j++,c++)
     {i=j-1;
     temp=a[j];
       while(a[i-1]>temp && i>=1)
	   {
	   	a[i]=a[i-1];
	   	i--;
			   }
			   a[i]=temp;        }
        t2=clock();
        printf("time=%d\n",t2-t1);
        printf("the no. of steps=%d\n",c);
        }
void display(int arr[50],int n)
{ int i;
     for(i=0;i<n;i++)
     printf("%d\t",arr[i]);
     }
int main()
{
    int arr[50];
    int i,n;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
    arr[i]=rand()%100;
}
    printf("array after sorting:\n");
    ins(arr,n);
   display(arr,n);
    getch();
    return 0;}

