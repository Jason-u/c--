#include<stdio.h>
int main()
{
	int y;
	int i=1; 
	printf("��������ݣ�");
	scanf("%d",&y);//! && ||
//	if(y<0)
//	{
//		break;
//	}
	if(y<0)
	{
		printf("%d�겻������\n",y);
		i=0;
	}
	while(i>0)
	{ 
		if(((y%4==0)&&(y%100!=0))||(y%400==0))
		{
			printf("%d��������\n",y); 
		}
		else
		{
			printf("%d�겻������\n",y);
		}
		printf("��������ݣ�"); 
		scanf("%d",&y);
		if(y<0)
			i=0;
	}
	return 0;
}
