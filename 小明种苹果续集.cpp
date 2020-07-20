#include<stdio.h>
int main(void)
{
	int n;
	long jian;
	int shumu=0;
	int cnt=0;
	int c=0;
	int m;
	int flag=0;
	long sum=0,ssum=0;
	scanf("%d",&n);
	int diao[n]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&jian);
			if(j==0)
		{
			ssum+=jian; 
		}
			if(j!=0&&jian>0)
		{
			if(ssum!=jian)
			{
				ssum=jian;
				flag++;
				diao[i]++;
			}
			if(diao[i]>1)
			{
				diao[i]=1;
				flag--;
			}
		}
		if(jian<=0)
		{
			ssum+=jian;
		}
		}
	sum+=ssum;
	ssum=0;
	}
	if(flag==3)
	{
		shumu=1;
	}else if(flag>3)
	{
		for(int k=0;k<n;k++)
		{
			int d=k;
			while(cnt<3&&c<3)
			{
				if(diao[d]==1)
				{
					cnt++;
					d++;
					if(d==n)
					{
						d=0;
						
					}
				}else
				{
					cnt=0;
				}
				c++;
			}
			if(cnt==3)
			{
				shumu++;
			}
			cnt=0;
			c=0; 
		}
	}
	printf("%d %d %d",sum,flag,shumu);
	return 0;
 } 
