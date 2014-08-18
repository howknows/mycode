#include <stdio.h>

long Fib(int n)
{
	if(n<=1)
		return 1;
	else
		return Fib(n-1) + Fib(n-2);
}

int main(int argc, char const *argv[])
{
	int n=50;
	printf("%ld\n",Fib(n));
	return 0;
}