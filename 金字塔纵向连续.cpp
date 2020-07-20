#include<stdio.h>

int main(void)
{
	char ch='A';
	for(int i=0;i<=5;i++)
	{
		int j;
		for(j=0;j<=i;j++)
		{
			printf("%c",ch+i+j);
		}
		printf("\n");
	}
	 return 0;
}
 A
 BC
 CDE
 DEFG
 EFGHI 
 FGHIJK
