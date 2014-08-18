#include<stdio.h>
#define OK 1
#define NO 0
int temp;
int test=NO;

void ungetch()
{
	test=OK;
}

char getch()
{
	if(test){
		test=NO;
		return temp;
	}
	else
		return temp=getchar();
}