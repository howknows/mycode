#include<stdio.h>
#include<ctype.h>
#define ZHENG 0
#define FU 1

char getch();
void ungetch();
void clearstack();

char getop(char  *str)
{
	char c,t;
	int flag=ZHENG,i=1;
	while( ( str[0]=c=getch() )==' '||c=='\t' )
		;
	if(c=='c'){
		clearstack();
		return 'c';
	}
	str[1]='\0';
	if( !isdigit(c) && c!='.' ){
		if ( !isdigit(t=getch()) ){
		ungetch();
		return c;}
		else{
			str[0]=t;
			flag=FU;
		}
	}
	
	while( isdigit(c=getch()) )
		str[i++]=c;
	if(c=='.'){
		str[i++]='.';
		while( isdigit(c=getch()) )
		str[i++]=c;}
	str[i]='\0';
	if(c!=EOF)
		ungetch();
	if(flag==ZHENG)
		return '0';
	else 
		return '1';
}