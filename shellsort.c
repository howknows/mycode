#include<stdio.h>

void main()
{
	int array[7]={4,7,5,2,1,3,6};
	int i,j,temp,size;
	int n=7;
	for(size=n/2;size>0;size/=2){
		for(i=size;i<n;i++){	
			for(j=i-size;j>=0&&(array[j]>array[j+size]);j-=size){
				temp=array[j];
				array[j]=array[j+size];
				array[j+size]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\t",array[i]);
	putchar('\n');
}