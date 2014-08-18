#include<stdio.h>
#define OVER 100
int val=0;
double stack[OVER];

void push(double num)
{
	(val<=100)?stack[val++]=num:printf("Stack full!\n");
}

double pop()
{
	return (val!=0)?stack[--val]:printf("%s\n","Stack is empty!" );;
}

void clearstack()
{
	int i;
	for(i=0;i<OVER;i++)
		stack[i]=0;
}