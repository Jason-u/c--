#include<stdio.h>
int  main(void)
{
	int num,i,c;
	c=1;
	printf("Please enter a number.\n");
	scanf("%d",&num);
	for(i=2;i<num;i++)
	{
		if(num%i==0)
		{
			c=0;
		}
	
	}
	if(num=1)
	{printf("1 not shushu");
	 } else{
	 
	if(c==0)
	{
		printf("不是素数。"); 
	}else{
		printf("是素数");
	}
}	return 0;
	}

