#include<stdio.h>
int main(void)
{
	int b=0;
	int c=0;
	for(b=0;b<50;b++)
{
	
	c=(40-b)/4;
	if(c<=20&&c>=0&&!((40-b)%4))
	{
	printf("%d %d\n",b,c);
	}
}	
	return 0;
}

 
