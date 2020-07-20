#include<stdio.h>
int main(void)
{
	int n,m;
	int tree;
	int i=0;
	int k=0;
	int j=0;
	int jian;
	int l;
	int jiansum=0;
	int sum=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		jiansum=0;
		scanf("%d",&tree);
		sum+=tree; 
		for(l=0;l<m;l++)
	{
		scanf("%d",&jian);
		jiansum+=jian;
	}
	sum+=jiansum;
	if(k==0)
	{
		k=jiansum;
	}else
	{
		if(jiansum<k)
		{
			k=jiansum;
			j=i;
		}
	}
	}
	printf("%d %d %d",sum,j+1,-k);
	return 0;
}
