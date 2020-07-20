#include<stdio.h>
int main()
{
	int y;
	int i=1; 
	printf("请输入年份：");
	scanf("%d",&y);//! && ||
//	if(y<0)
//	{
//		break;
//	}
	if(y<0)
	{
		printf("%d年不是闰年\n",y);
		i=0;
	}
	while(i>0)
	{ 
		if(((y%4==0)&&(y%100!=0))||(y%400==0))
		{
			printf("%d年是闰年\n",y); 
		}
		else
		{
			printf("%d年不是闰年\n",y);
		}
		printf("请输入年份："); 
		scanf("%d",&y);
		if(y<0)
			i=0;
	}
	return 0;
}
