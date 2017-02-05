//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
//PROGRAM-10
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct node
{
	int s_roll_no;
	char s_name[10];
	struct node *next;
}node;

node *insert(node*);
void duplicate(node*);
void display(node*);

int main()
{
	node *right=NULL,*left=NULL;
	int ch;
	do
	{
		printf("\n******MENU*****");
		printf("\n1.insertion");
	    printf("\n2.to remove duplicate name");
		printf("\n3.to display");
		printf("\n4.exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				right=insert(right);
				if(left==NULL)
				left=right;
				break;
			case 2:
				duplicate(left);
				printf("\nAfter removing Duplicate name, linklist:\n");
				display(left);
				break;
			case 3:
				display(left);
				break;
			case 4:
				break;
			default:
				printf("Wrong choice");
		}
	} while(ch!=4);
return 0;
}

node *insert(node *rt)
{
	node *p;
	int rollno;
	char name[20];
	printf("\nEnter Roll no:");
	scanf("%d",&rollno);
	printf("Enter Student Name:");
	scanf("%s",name);
	p=(node*)malloc(sizeof(node));
	if(p!=NULL)
	{
		p->s_roll_no=rollno;
		strcpy(p->s_name,name);
		p->next=NULL;
		if(rt!=NULL)
		rt->next=p;
		rt=p;
	}
	else
	printf("\nNot enough memory");
	return(rt);
}

void duplicate(node *lt)
{
	node *p,*q,*r;
	if(lt!=NULL)
	{
		while(lt->next!=NULL)
		{
			p=lt;
			q=p->next;
			while(q!=NULL)
			{
				if(strcmp(lt->s_name,q->s_name)==0)
				{
					r=q;
					q=q->next;
					free(r);
					p->next=q;
				}
				else
				{
					p=q;
					q=q->next;
				}
			}
			lt=lt->next;
		}

	}
	else
	printf("\nQueue is empty");
}

void display(node *lt)
{
	while(lt!=NULL)
		{
			printf("\n%d",lt->s_roll_no);
			printf("\n%s",lt->s_name);
			lt=lt->next;
		}
	}


