#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 100
#define CLEANSTATE 1

double pop();
void push(double num);
char getop(char *str);

int main()
{
	int cls;
	char  state=0;
	char  str[MAXLINE];
	double temp,result;
	printf("#########Calc########\n");
	printf("%s\n","Input:" );
	while( (state=getop(str))!=EOF ){
	switch(state){
		case '0':
			push(atof(str));
			break;
		case '1':
			temp=atof(str) * -1;
			push(temp);
			break;
		case '+':
			push(pop()+pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			temp=pop();
			push(pop()-temp);
			break;
		case '/':
			temp=pop();
			push(pop()/temp);
			break;
		case  '%':
			temp=pop();
			push( (int)pop() % (int)temp);
			break;
		case  'c':
			printf("%s\n","The stack is clean." );
			cls=CLEANSTATE;
			break; 
		case '\n':
		if(cls!=CLEANSTATE)
			result=pop();
		else cls=0;
			break;
		default :
		printf("Have a error!\n");
			exit(0);}
		}

	printf("The result is %.2f.\n",result );

}