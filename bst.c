//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
//binary search tree
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct tree
{
	char info[20];
	struct tree *left,*right;
}tree_type;
void create(tree_type**,char[20]);
void del(tree_type**,char[20]);
void search(tree_type*,char[20]);
void count(tree_type*,int*);
int main()
{
	tree_type* root=NULL;
	char str[20],cha;
	FILE *fp;
	int ch,c;
     do
     { 
     printf("******MENU*******\n");
     printf("1.to create binary search tree\n");
     printf("2.to delete a node from BST\n");
     printf("3.to count the number of leaf nodes\n");
     printf("4.to search a particular node in BST\n");
     printf("5.to exit\n");
     printf("enter your choice\n");
     scanf("%d",&ch);
     switch(ch)
     {
     	case 1:
     		fp=fopen("Tree.txt","w+");
	while((cha=getchar())!=EOF)
fputc(cha,fp);
rewind(fp);
printf("file tree.txt created!\n");
     		while(fscanf(fp,"%s",str)!=EOF)
        create(&root,str);
        fclose(fp);
        printf("tree created");
     	break;
     	case 2:
     	printf("enter the elemnt to b deleted\n");
     	scanf("%s",str);
        del(&root,str);
     	break;	
     	case 3:
     		c=0;
     	count(root,&c);
     	printf("the total no. of leaf nodes:%d\n",c);
     	break;
     	case 4:
     	printf("enter the element to b searched\n");
     	scanf("%s",str);
     	search(root,str);
     	break;
     	case 5:break;
     	default:printf("wrong choice");
	        }
 }while(ch!=5);
 return 0;
	 }
	 void create(tree_type** rt,char n[20])
	 {
	 	tree_type* p;
	 	if(*rt==NULL)
	 	{
	 	p=(tree_type*)malloc(sizeof(tree_type));
	 	if(p!=NULL)
	 	{
	 	p->left=NULL;
	 	p->right=NULL;
	 	strcpy(p->info,n);
	 	*rt=p;
		 	 }
	 else
	 printf("not enough memory");
}
else
{
	if(strcmp(n,(*rt)->info)==-1)
	create(&((*rt)->left),n);
	else
	create(&((*rt)->right),n);
}
}
void count(tree_type* rt,int *c)
{
	if(rt!=NULL)
	{
		if(rt->left==NULL&&rt->right==NULL)
		(*c)++;
		count(rt->left,c);
		count(rt->right,c);
	}
}
void search(tree_type* rt,char n[20])
{
	if(rt==NULL)
    printf("NOT FOUND");
	else
	{
		if(strcmp(n,rt->info)==0)
		printf("NODE FOUND!");
		else if(strcmp(n,rt->info)==-1)
		search(rt->left,n);
		else
		search(rt->right,n);
		}	
}
void del(tree_type **rt,char n[20])
{
	tree_type *t,*pr;
	if(*rt==NULL)
	printf("no tree");
	else
	{
		t=*rt;
		pr=NULL;
		while(t!=NULL)
		{
			if(strcmp(t->info,n)==0)
			break;
			else if(strcmp(n,t->info)==-1)
			{
				pr=t;
				t=t->left;
			}
			else
			{
				pr=t;
				t=t->right;
			}
		}
		if(t==NULL)
		printf("node not found!");
		else if(t->left==NULL&&t->right==NULL)
		{
			if(pr==NULL)
			{
				*rt=NULL;
				free(t);
			}
			else if(pr->left==t)
			{
			pr->left=NULL;
			free(t);
			}
			else
			{
				pr->right=NULL;
				free(t);
			}
		}
		else if(t->left!=NULL&&t->right==NULL)
		{
			if(pr==NULL)
			{
				*rt=(*rt)->left;
				t->left=NULL;
				free(t);
			}
			else if(pr->left==t)
			{
				pr->left=t->left;
				t->left=NULL;
				free(t);
			}
			else
			{
				pr->right=t->left;
				t->left=NULL;
				free(t);
			}
		}
		else if(t->left==NULL&&t->right!=NULL)
		{
			if(pr==NULL)
			{
				*rt=(*rt)->right;
				t->right=NULL;
				free(t);
			}
			else if(pr->left==t)
			{
				pr->left=t->right;
				t->right=NULL;
				free(t);
			}
			else
			{
				pr->right=t->right;
				t->right=NULL;
				free(t);
			}
		}
		else
		{
			tree_type *ispr,*isuc;
			ispr=t;
			isuc=t->right;
			while(isuc->left!=NULL)
			{
				ispr=isuc;
				isuc=isuc->left;
			}
			if(ispr==t)
			{
				strcpy(t->info,isuc->info);
				t->right=isuc->right;
				isuc->right=NULL;
				free(isuc);
			}
			else
			{
				strcpy(t->info,isuc->info);
				ispr->left=isuc->right;
				isuc->right=NULL;
				free(isuc);
			}
		}
	}
}
