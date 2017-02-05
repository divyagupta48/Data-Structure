//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
//PROGRAM-8
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node
{
	int S_Rollno;
	char S_Name[20];
	char S_Grade;
	struct node* next;
}node;
node* enque(node*);
node* deque(node*);
void display(node*);
int main()
{
	node* left=NULL,*right=NULL;
	int ch;
do
{
	printf("******MENU*******\n");
	printf("1.insert into queue\n");
	printf("2.delete from queue\n");
	printf("3.to display\n");
	printf("4.exit\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:right=enque(right);
		       if(left==NULL)
		       left=right;
		       break;
	    case 2:left=deque(left);
	           if(left==NULL)
	           right=NULL;
	           break;
	    case 3:display(left);
	           break;
	    case 4:break;
	    default:printf("wrong choice");
	}
}while(ch!=4);
return 0;
}
 node* enque(node* right)
	 {
	 	node* p,*t;
	 	p=(node*)malloc(sizeof(node));
	 	p->next=NULL;
	 	printf("enter the student roll no.\n");
	 	scanf("%d",&p->S_Rollno);
	 	printf("enter the student name\n");
	 	scanf("%s",p->S_Name);
	 	printf("enter the grade\n");
	 	scanf("%s",&p->S_Grade);
	 	if(p!=NULL)
	 	{
	 	if(right==NULL)
	 	{
	 		right=p;
	 		}
	 		else
	 		{
	 			t=right;
	 			while(t->next!=NULL)
	 			t=t->next;
	 			t->next=p;
	 			}
	 		}
	 		else
	 		printf("not enough memory");
	 			return right;
	 }
void display(node *left)
{
	while(left!=NULL)
	{
		printf("student rollno=%d\n",left->S_Rollno);
		printf("student name=%s\n",left->S_Name);
		printf("student grade=%c\n",left->S_Grade);
		left=left->next;
	}
}
node* deque(node* left)
{
	node* p;
	if(left==NULL)
	printf("no node present");
	else
	{
	p=left;
	left=left->next;
	p->next=NULL;
	free(p);	
	printf("node deleted");
	}
	return left;
}
