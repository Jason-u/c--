#include<stdio.h>
int main(void)
{
	int n,m;
	int k;
	scanf("%d %d",&n,&m);
	int sum=0;
	int maxjian[n]={0};
	int shu[n];
	int a[n][m];
	int i; 
	int j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&shu[i]);
		sum+=shu[i];
		for( j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			maxjian[i]+=a[i][j];
		}
		sum+=maxjian[i];
	}
	printf("%d",sum);
	k=0;
	for(i=0;i<n;i++)
	{
		if(maxjian[k]>maxjian[i+1])
		{
			k=i+1;
		}
	}
	printf(" %d %d",k+1,-maxjian[k]);
	return 0;
}
