#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void init_array(int array[10][10]);

void main()
{
	int i,j;
	int array[10][10]={};
	init_array(array);
	for(i=0;i<10;i++)
		for(j=0;j<10;j++){
			system("clear");
			//usleep(500000);
			printf("%u ",array[i][j] );
		}

	putchar('a');
}

void init_array(int array[10][10])
{
	int i,j;
	char num=0;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			array[i][j]=num++;

}