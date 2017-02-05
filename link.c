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
node* createS(node*,node*,node*);
int main()
{
	node* head=NULL,*head1=NULL,*head2=NULL;
	int ch,n;
     do
     { 
     printf("******MENU*******\n");
     printf("1.to create linked list A\n");
     printf("2.to create linked list B\n");
     printf("3.to create linked list S\n");
     printf("4.to display the contents of A\n");
     printf("5.to display the contents of B\n");
     printf("6.to display the contents of S\n");
     printf("7.to exit\n");
     printf("enter your choice\n");
     scanf("%d",&ch);
     switch(ch)
     {
     	case 1:
     	printf("enter the elemnt to b inserted\n");
     	scanf("%d",&n);
     	head1=create(head1,n);
     	break;
     	case 2:
     	printf("enter the elemnt to b inserted\n");
     	scanf("%d",&n);
     	head2=create(head2,n);
     	break;	
     	case 3:
     	head=createS(head,head1,head2);
     	break;
     	case 4:
     	printf("contents of A:\n");
     	display(head1);
     	break;
     	case 5:
     	printf("contents of B:\n");
     	display(head2);
     	break;
     	case 6:
	    printf("contents of S:\n");
	    display(head);
     	break;
     	case 7:break;
     	default:printf("wrong choice");
	        }
 }while(ch!=7);
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
	node* createS(node* head,node* head1,node* head2)
	{
		while((head1!=NULL)&&(head2!=NULL))
		{
		head=create(head,head1->info);
		head1=head1->next;
		head=create(head,head2->info);
		head2=head2->next;
		}
		while(head1!=NULL)
		{
				head=create(head,head1->info);
		head1=head1->next;
		}
		while(head2!=NULL)
		{
			head=create(head,head2->info);
		head2=head2->next;	
		}
			printf("s created\n");
		return head;
	
	}
void display(node *head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->info);
		head=head->next;
	}
}
