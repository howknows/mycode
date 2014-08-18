#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct TREENOTE
{
	int data;
	struct TREENOTE *lefttree;
	struct TREENOTE *righttree;

}TREE;
TREE *trnote;


int main(int argc, char const *argv[])
{

	trnote=(TREE *)malloc(sizeof(TREE));
	trnote->data=12;
	trnote->lefttree=(TREE *)malloc(sizeof(TREE));
	trnote->righttree=(TREE *)malloc(sizeof(TREE));
	trnote->lefttree->data=13;
	printf("%d %d \n",trnote->data,trnote->righttree->data );
	return 0;
}