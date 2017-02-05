//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int info;
	struct node *next;
}node;
void split(node*,node**,node**,node**,node**);
void insert(node **);
void display(node*);
int main()
{
	node *left=NULL,*right=NULL,*elt=NULL,*ert=NULL,*olt=NULL,*ort=NULL;
	int ch;
	do
	{
		printf("\n*******MENU******");
		printf("\n1.insertion");
		printf("\n2.split");
		printf("\n3.display");
		printf("\n4.exit");
		printf("\nenter choice");
		scanf("%d",&ch);		
		switch(ch)
		{
			case 1:insert(&right);
			        if(left==NULL)
			          left=right;
			        break;
		    case 2:split(left,&elt,&ert,&olt,&ort);
		           printf("\nelements at even");
		           display(elt);
		           printf("\nelements at odd");
		           display(olt);
				   break;   
			case 3:display(left);
			case 4:break;
			default: printf("invalid choice");        
		}
	}while(ch!=4);
	return 0;
}
void insert(node **lt)
{
	node *p;
	p=(node*)malloc(sizeof(node));
	if(p!=NULL)
	{
		printf("enter a no\n");
		scanf("%d",&p->info);
		p->next=NULL;
		if(*lt==NULL)
		    *lt=p;
		else
		{
			(*lt)->next=p;
			*lt=p;		     
		}   		
	}
}
void split(node*lt,node**evnlt,node**evnrt,node**odlt,node**odrt)
{
	int pos=1;
	while(lt!=NULL)
	{
	     if(pos%2==0)
	     {
	     	if(*evnlt==NULL)
	     	{
	     		*evnlt=lt;
	     		*evnrt=lt;
			 }
			 else
			 {
			 	(*evnrt)->next=lt;
				 (*evnrt)=lt;
			 }
		 }
		 else
		 {
	     	if(*odlt==NULL)
	     	{
	     		*odlt=lt;
	     		*odrt=lt;
			 }
			 else
			 {
			 	(*odrt)->next=lt;
			 	(*odrt)=lt;
			 }		 
		 }
		 pos++;
		 lt=lt->next;		   	
	}   
	
}
void display(node *left)
{
		while(left!=NULL)
    	{
	    	printf("\n%d",left->info);
		    left=left->next;
    } 	}

