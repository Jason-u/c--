#include<stdio.h>

int main(void)
{
	int num,ret;
	ret=1;
	scanf("%d",&num);
	for(int i=2;i<=num;i++)
	{
		int j;
		for(j=2;j<=i,i%j!=0;j++);
		if(j==i)
		{
			printf("%3d",i);
			
		}
	}
	
	 return 0;
}

