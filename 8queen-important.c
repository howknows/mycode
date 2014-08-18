#include <stdio.h>//NB!
int wancheng=1;
int Ans=0;
int queen(long heng,long left,long right)
{
	long pos,p;
	pos=wancheng&(~(heng|left|right));
	if(heng!=wancheng)
		while(pos){
			p=pos&-pos;
			pos-=p;
			queen((heng+p),(left+p)<<1,(right+p)>>1);
		}

	else 
		Ans++;
}

int main(int argc, char const *argv[])
{
	int deepth;
	scanf("%d",&deepth);
	wancheng=(wancheng<<deepth)-1;
	queen(0,0,0);
	printf("Result:%d\n",Ans );
	return 0;
}