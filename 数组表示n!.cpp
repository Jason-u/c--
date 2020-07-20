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
	for(i=2;i<=n;i++)//把每个小于n的数都乘一遍 
	{
		for(j=0,jinwei=0;j<weishu;j++)//把每一位上的数都与此时的数乘一遍 
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
	printf("n!和=");
	for(i=weishu-1;i>=0;i--)
	{
		printf("%d",sum[i]);
	}
}
