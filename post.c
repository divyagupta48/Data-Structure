//NAME-DIVYA GUPTA
//BTECH CS,3RD SEM
//GRAPHIC ERA HILL UNIVERSITY
//PROGRAm to evaluate postfix
#include<stdio.h>
#include<stdlib.h>
void push(int[],int*,int);
int isoperand(int n);
char pop(int[],int*);
int evaluate(char[]);
int main()
{
	char a[20];
	int res;
	gets(a);
	res=evaluate(a);
	printf("result=%d\n",res);
	return 0;
}
int evaluate(char a[])
{
	int d,i,res,top=-1;
	int op2,op1;
	int st[20];
	for(i=0;a[i]!='\0';i++)
	{
		if(isoperand(a[i])==1)
		{
		push(st,&top,a[i]-48);
	}
		else
		{
			op2=pop(st,&top);
			printf("op2=%d\n",op2);
			op1=pop(st,&top);
			printf("op1=%d\n",op1);
			switch(a[i])
			{
				case '+':res=op1+op2;break;
				case '-':res=op1-op2;break;
				case '/':res=op1/op2;break;
				case '%':res=op1%op2;break;
				case '*':res=op1*op2;break;
			}
			push(st,&top,res);
		}
	}
	return res;
}
int isoperand(int n)
{
	if(n>=48&&n<=57)
	return 1;
	else
	return 0;
}
void push(int st[20],int *top,int value)
{
	(*top)++;
	st[*top]=value;
}
char pop(int st[20],int *top)
{
int e;
e=st[*top];
(*top)--;
return e;	
}
