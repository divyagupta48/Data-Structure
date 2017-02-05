//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int info,pri;
	struct node *next;
}node;

void insert(node **);
void display(node*);
void serve(node*,node**);
int main()
{
	node *left=NULL,*right=NULL;
	int ch;
	do
	{
		printf("\n*******MENU******");
		printf("\n1.insertion");
		printf("\n2.serve");
		printf("\n3.display");
		printf("\n4.exit");
		printf("\nenter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert(&left);
			        if(right==NULL)
			          right=left;
			        break;
		    case 2:serve(left,&right);
		        break;
			case 3:display(left);
			        break;
			case 4:break;
			default: printf("wrong choice");        
		}
	}while(ch!=4);
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
		printf("enter priority\n");
		scanf("%d",&p->pri);
		t=*lt;
		if(t==NULL||t->pri>=p->pri)
	    {
			*lt=p;
	    	p->next=t;
		}
		else
	    {
		  while(t->next!=NULL&&(t->next)->pri<p->pri)
		      t=t->next;		
		  p->next=t->next;
		  t->next=p;  
	    }
	}
}
void serve(node*lt,node**rt)
{
	if(lt==NULL)
	   printf("list empty\n");
	else
	{   
	  node*p=*rt;
	  while(lt->next!=p)
	    lt=lt->next;
	  *rt=lt;
	  lt->next=NULL;
   	  free(p); 
}}
void display(node *left)
{		while(left!=NULL)
    	{
	    	printf("\nnum=%d\tpriority=%d",left->info,left->pri);
		    left=left->next;
    } 	}

	

