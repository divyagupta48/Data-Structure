//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
//PROGRAM-6
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node
{
	int info;
	struct node* next;
}node;
node* create(node*,int);
void display(node*);
void del(int,node*);
int main()
{
	node* head=NULL;
	int ch,n,ptr;
     do
     { 
     printf("******MENU*******\n");
     printf("1.to create linked list \n");
     printf("2.to delete the specified node");
     printf("3.to display the contents of \n");
     printf("4.to exit\n");
     printf("enter your choice\n");
     scanf("%d",&ch);
     switch(ch)
     {
     	case 1:
     	printf("enter the elemnt to b inserted\n");
     	scanf("%d",&n);
     	head=create(head,n);
     	break;
     	case 2:
     	printf("enter the pointer");
     	scanf("%d",ptr);
     	del(ptr,head);
     	break;
     	case 3:
		 display(head);
		 break;
		 case 4:break;
     	default:printf("wrong choice");
	        }
 }while(ch!=4);
 return 0;
	 }
	 node* create(node* head,int n)
	 {
	 	node* p,*t;
	 	p=(node*)malloc(sizeof(node));
	 	p->next=NULL;
	 	p->info=n;
	 	if(p!=NULL)
	 	{
	 	if(head==NULL)
	 	{
	 		head=p;
	 		}
	 		else
	 		{
	 			t=head;
	 			while(t->next!=NULL)
	 			t=t->next;
	 			t->next=p;
	 			}
	 		}
	 		else
	 		printf("not enough memory");
	 			return head;
	 }
void del(int ptr,node *head)
{
	node* temp,*p;
	while(head!=NULL)
	{
		if(head==(node*)ptr)
		{
			temp=head->next;
			head->info=temp->info;
			head->next=temp->next;
			temp->next=NULL;
			free(temp);
}head=head->next;
}
}
void display(node *head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->info);
		printf("%d\n",head);
		head=head->next;
	}
}
