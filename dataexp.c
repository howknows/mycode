#include<stdio.h>

int main(int argc, char const *argv[])
{
	int w,c,y;
	int m,d,n;
	scanf("%d %d %d",&n,&m,&d);
	if(m==1||m==2){
		n-=1;
		m+=12;
	}
	c=n/100;
	y=n - c*100;
	w=(c/4) -2*c +y +(y/4) + (26 * (m+1)/10 ) + d -1;
	while( (w-=7) > 7 )
		if(w<=0)
			w+=7;
	if(w<=0)
		w+=7;
	if(w==7)
		printf("%d\n",0 );
	else
		printf("%d\n",w );
	return 0;
}