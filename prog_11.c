//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int info;
	struct node *next;
	struct node *prev;
}node;
void insert(node **);
void display(node*);
int main()
{
	node *left=NULL,*right=NULL;
	int ch;
	do
	{
		printf("\n******MENU*******");
		printf("\n1.insertion");
		printf("\n2.display");
		printf("\n3.exit");
		printf("\n enter your choice:");
		scanf("%d",&ch);		
		switch(ch)
		{
			case 1:insert(&left);
			        if(right==NULL)
			          right=left;
			        break;
		    case 2:display(left);
			        break;
			case 3:break;
			default: printf("wrong choice");        
		}
	}while(ch!=3);
	return 0;
}
void insert(node **lt)
{
	node *p,*t;
	p=(node*)malloc(sizeof(node));
	if(p!=NULL)
	{
		printf("enter a number\n");
		scanf("%d",&p->info);
		t=*lt;
		if(t==NULL||t->info>=p->info)
	    {
		
	    	*lt=p;
	    	p->prev=NULL;
	    	p->next=t;
		}
		else
	    {
		  while(t->next!=NULL&&(t->next)->info<p->info)
		      t=t->next;		
		  p->next=t->next;
		  t->next=p;
		  p->prev=t;
		  (p->next)->prev=p;   
	    }
	}
}
void display(node *left)
{
	while(left!=NULL)
    	{
	    	printf("\n%d",left->info);
		    left=left->next;
    } 	
}
	

