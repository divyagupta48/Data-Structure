//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
//PROGRAM-9
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node
{
	int info;
	struct node* next;
}node;
void insert(node**,node**);
void del(node**,node**);
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
		case 1:insert(&right,&left);
		       break;
	    case 2:del(&right,&left);
	           break;
	    case 3:display(left);
	           break;
	    case 4:break;
	    default:printf("wrong choice");
	}
}while(ch!=4);
return 0;
}
void display(node* lt)
{
	node* p;
	p=lt;
	do
	{
		printf("%d\n",p->info);
		p=p->next;
	}while(p!=lt);
}
void insert(node **rt,node **lt)
{
	node *p;
	p=(node*)malloc(sizeof(node));
	if(p!=NULL)
	{
	printf("enter the element");
	scanf("%d",&p->info);
	if(*rt==NULL)
	{
	*rt=p;
	*lt=p;
	(*rt)->next=*lt;
}
    else
    {
	(*rt)->next=p;
     *rt=p;
    (*rt)->next=*lt;     
}
}
    else
    printf("not enough memory!!!");
}
void del(node **rt,node **lt)
{
	node *p,*t;
	int n;
	p=*lt;
	if(*lt==NULL)
	printf("no node present");
		else
	{
		printf("enter the node to b deleted");
		scanf("%d",&n);
		if((*lt)->info==n)
		{
			p=*lt;
		*lt=(*lt)->next;
		(*rt)->next=*lt;
		p->next=NULL;
		free(p);	
		}
	/*else if((*rt)->info==n)
		{
			p=*rt;
			*rt=(*rt)->next;
			p->next=NULL;
			free(p);
		}*/
	    else
		{
			do
			{
				if(p->next->info==(*rt)->info)
				{
					t=p;
					p=*rt;
				 t->next=p->next;
				 *rt=t;
		   p->next=NULL;
		   free(p);break;
				}
				else if(p->next->info==n)
				{
					t=p;
					p=p->next;
					t->next=p->next;
		   p->next=NULL;
		   free(p);
					break;
			}
			p=p->next;
		   }while(p!=*lt);
		   printf("node deleted");	} 			
}
}
