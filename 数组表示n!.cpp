#include<stdio.h>
#define MAX 3000 
int main(void)
{
	int jinwei,weishu=1;
	int n,temp,tem,k,d,j,i;
	int sum[MAX]={1}; 
	int a[MAX];
	a[0]=1;
	scanf("%d",&n);
	for(i=2;i<=n;i++)//��ÿ��С��n��������һ�� 
	{
		for(j=0,jinwei=0;j<weishu;j++)//��ÿһλ�ϵ��������ʱ������һ�� 
		{
			temp=a[j]*i+jinwei;
			a[j]=temp%10;
			jinwei=temp/10;
		}
		while(jinwei)
		{
			weishu++;
			a[weishu-1]=jinwei%10;
			jinwei=jinwei/10;
		 } 
		 for(k=0;k<weishu;k++)
		 {
		 	d=k;
		 	tem=sum[d]+a[d];
		 	sum[d]=tem%10;
		 	tem=tem/10;
		 	while(tem)
		 	{
		 		d++;
		 		sum[d]=(sum[d]+tem)%10;
		 		tem=(sum[d]+tem)/10;
			 }
		 }
	}
	printf("n!��=");
	for(i=weishu-1;i>=0;i--)
	{
		printf("%d",sum[i]);
	}
}
