#include <stdio.h>
int main(void)
{
	int a[5]={3432,54,7654,634,3234};
	int i;
	int j;
	int tem;
	int n;
	for(j=0;j<4;j++)
	{
		for(n=0;n<4-j;n++ )
		{
			if(a[n]>a[n+1])
			{
			  tem=a[n];
			  a[n]=a[n+1];
			  a[n+1]=tem;
		}
	}
}
for(int b=0;b<=4;b++)
{
	printf("%d\n",a[b]);
}
return 0;
}
