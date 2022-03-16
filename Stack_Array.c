Implementation of Stack Operations by Structure and Array
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct stk{
	int info[SIZE];	
	int top;
}stack;

void push(stack *, int);
int pop(stack *);
int stack_empty(stack *);
int stack_full(stack *);
int stack_print(stack *);

int main()
{
	int item,ch;
	stack s,*ps;

	ps=&s;

	ps->top=-1;

	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Print\n0.Exit\nEnter your choice:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the information: ");
				scanf("%d",&item);
				push(ps, item);
				break;
			case 2:
				item = pop(ps);
				if(item!=-99999)
					printf("\nElement poped: %d\n", item);
				break;
			case 3:
				item = stack_print(ps);
				if(item!=-99999)
					printf("\nTop Element: %d\n", item);
				break;
			case 0:
				exit(0);
			dafault:
				printf("\nInvalid input!!!Try again....");
		}
	}

	return(0);
}

int stack_empty(stack *ps)
{
	if(ps->top==-1)
		return(1);
return(0);
}

int stack_full(stack *ps)
{
	if(ps->top==SIZE-1)
		return(1);
	return(0);
}

void push(stack *ps, int item)
{
	if(stack_full(ps))
	{
		printf("Overflow!!");
		return;
	}
ps->top=ps->top+1;
	ps->info[ps->top]=item;
	return;
	
}

int pop(stack *ps)
{
	int item;
	if(stack_empty(ps))
	{
		printf("\nUnderflow!!");
		return(-99999);
	}
	item=ps->info[ps->top];
	ps->top=ps->top-1;
	return(item);
	
}
int stack_print(stack *ps)
{
	int i;
	if(stack_empty(ps))
	{
		printf("\nNo stack create.");
		return(-99999);
	}
	return(ps->info[ps->top]);
}
