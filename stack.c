//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
//PROGRAM-7
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node
{
	int Emp_Id;
	char Emp_Name[20];
	float Emp_sal;
	struct node* next;
}node;
node* push(node*);
node* pop(node*);
void display(node*);
int main()
{
	node* top=NULL;
	int ch;
do
{
	printf("******MENU*******\n");
	printf("1.push onto stack\n");
	printf("2.pop from the stack\n");
	printf("3.to display\n");
	printf("4.exit\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:top=push(top);
		       break;
	    case 2:top=pop(top);
	           break;
	    case 3:display(top);
	           break;
	    case 4:break;
	    default:printf("wrong choice");
	}
}while(ch!=4);
return 0;
}
node* push(node* top)
{
	node* p;
	p=(node*)malloc(sizeof(node));
	printf("enter the employee id\n");
	scanf("%d",&p->Emp_Id);
	printf("enter the employee name\n");
	scanf("%s",p->Emp_Name);
	printf("enter the emploee salary\n");
	scanf("%f",&p->Emp_sal);
	p->next=top;
	top=p;
	return top;
	}
	void display(node* top)
	{
		while(top!=NULL)
		{
			printf("emploee id=%d\n",top->Emp_Id);
			printf("emploee name=%s\n",top->Emp_Name);
			printf("employee salary=%g\n",top->Emp_sal);
			top=top->next;
		}
	}
	node* pop(node* top)
	{
	node* p;
	p=top;
	top=top->next;	
	p->next=NULL;
	free(p);
	return top;
	}
