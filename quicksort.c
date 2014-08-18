#include<stdio.h>

void show(int *array)
{
	int j=10,i=0;
		while(j--) {
		printf("%d  ",*(array+i));
		i++;
	}
	putchar('\n');
}

void quicksort(int *array,int low,int high)
{
	int a;
	if(low<high){
	a=partition(array,low,high);
	quicksort(array,low,a-1);
	quicksort(array,a+1,high);
	}
}

int partition(int *array,int low,int high)
{
	int temp;
	temp=*(array+low);
	while(low<high){
		while(low<high&&temp<=*(array+high))
			high--;
		if(low<high){
			*(array+low)=*(array+high);
			low++;
				}
		while(low<high&&temp>=*(array+low))
			low++;
		if(low<high){
			*(array+high)=*(array+low);
			high--;
				}
	}
	*(array+low)=temp;
	return low;
}

void main()
{
	int array[10]={7,9,5,0,1,4,2,3,6,8};
	quicksort(array,0,9);
	show(array);
}