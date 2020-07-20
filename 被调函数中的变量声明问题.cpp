#include<stdio.h>
//int imin(int,int);
int imin(,)
 {
 	int min;
 	int e1,e2;
 	
	 if(e1>e2)
	 min=e2;
	 else
	 min=e1;	
	 return min;
 }
int main(void)
{
	float e1,e2;
	printf("Please enter.\n");
	while(scanf("%d  %d",&e1,&e2)==2)
	{
		printf("The lesser of %d and %d is %d.\n",e1,e2,imin(e1,e2));
		printf("Please\n");
	}
	printf("bye.");
	return 0;
}
 
 
 
