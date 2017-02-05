//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
//PROGRAM-8
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
typedef struct node
{
	int S_Rollno;
	char S_Name[20];
	struct node* next;
}node;
node* insert(node*);
void remdup(node*);
void display(node*);
int main()
{
	node* head=NULL;
	int ch;
do
{
	printf("******MENU*******\n");
	printf("1.insert into linked list\n");
	printf("2.remove duplicacy from list\n");
	printf("3.to display\n");
	printf("4.exit\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:head=insert(head);
		       break;
	    case 2:remdup(head);
	           break;
	    case 3:display(head);
	           break;
	    case 4:break;
	    default:printf("wrong choice");
	}
}while(ch!=4);
return 0;
}
node* insert(node* head)
	 {
	 	node* p,*t;
	 	p=(node*)malloc(sizeof(node));
	 	p->next=NULL;
	 	if(p!=NULL)
	 	{
	 		printf("enter roll no.:");
	 		scanf("%d",&p->S_Rollno);
	 		printf("enter name of student:");
	 		scanf("%s",p->S_Name);
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
void display(node *head)
{
	while(head!=NULL)
	{
		printf("student rollno=%d\n",head->S_Rollno);
		printf("student name=%s\n",head->S_Name);
		head=head->next;
	}
}
void remdup(node* head)
{
	node* p,*t,*tmp;
	if(head==NULL)
	printf("no node present");
	else
	{
     p=head;
     while(p!=NULL)
     {
     	t=p;
     	while(t!=NULL)
    {     tmp=t->next;
     		if((strcmp(p->S_Name,tmp->S_Name))==0)
     		{
     			t->next=tmp->next;
     			tmp->next=NULL;
     			free(tmp);
     			printf("node deleted");
			 }
			 t=t->next;
		 }
		 p=p->next;
	 }
 }
}

