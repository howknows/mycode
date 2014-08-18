#include<stdio.h> 
#define LEAP(y) (y%(y%100?4:400)==0)  
int days(int year,int month,int day) 
{ int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
 int c=day,m,y=year-1; 
 days[2]=28+LEAP(year); 
 for(m=1;m<month;m++) c+=days[m]; 
 return c+y/4-y/100+y/400+y*365; //计算方法是先计算假如全部年份都是平年的天数即y*365L，然后加c，c是year那一年的天数，再加上闰年出现的次数。
} 
void main() 
{ int y,m,d; int t1,t2;  
 scanf("%d%*c%d%*c%d",&y,&m,&d); 
 t1=days(y,m,d); 
 scanf("%d%*c%d%*c%d",&y,&m,&d); 
 t2=days(y,m,d); 
 printf("%d days\n",t2-t1); 
}