#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int info;
	struct node *prev;
	struct node *next;
}node;

void insert(node**,node**);
void display(node*);	
int main()
{
	node *right=NULL,*left=NULL;
	int ch;
	do
	{
		printf("\n******MENU*****");
		printf("\n1.insertion");
		printf("\n2.to display");
		printf("\n3.exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert(&left,&right);
				if(left==NULL)
				left=right;
				break;
			case 2:
				display(left);
				break;
			case 3:
				break;
			default:
				printf("Wrong choice");
		}
	} while(ch!=3);
return 0;
}
void insert(node **lt,node **rt)
{
	node *p,*r,*q;
	int num;
	printf("\nEnter element:");
	scanf("%d",&num);
	p=(node*)malloc(sizeof(node));
		if(p!=NULL)
	{
		p->info=num;
	if(*rt==NULL)
	{
		p->prev=NULL;
		p->next=NULL;
		*rt=p;
		*lt=*rt;
	}
	q=*lt;
	       while(q!=NULL)
			{
				if(p->info<q->info)
				{
					r=q->prev;
					p->next=q;
					q->prev=p;
					p->prev=r;
					if(r!=NULL)
					r->next=p;
					else
				    *lt=p;
				    break;
				}
				else
				q=q->next;
			}
		if(q==NULL)
		{
			p->next=NULL;
			p->prev=*rt;
			(*rt)->next=p;
			*rt=p;
		}
	}else
	printf("\nNot enough memory");
}

void display(node *lt)
{
		printf("\nQueue:\n");
		while(lt!=NULL)
		{
			printf("%d\t",lt->info);
			lt=lt->next;
		}
	}


