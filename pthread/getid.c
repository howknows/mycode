#include<stdio.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
	printf("father:%d  child:%d\n",getppid(),getpid() );
	return 0;
}