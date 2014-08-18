#include<stdio.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
	char *str[]={"ls","-al",NULL};//NULL is important!If NULL is forget the program run error! 
	//NULL like a end of the char array for execve().
	printf("pid: %d\n",getpid() );
	if(execve("/bin/ls",str,str+1) < 0)
		printf("%s\n","Error!" );
	return 0;
}