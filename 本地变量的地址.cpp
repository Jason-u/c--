#include<stdio.h>
int k;
int main(void)
{
	char b=1;
	char a=2;
const	char *p="dasfas";
	printf("%p\n",&a);
	printf("%p\n",&b);
	printf("%p\n",p);
	printf("%p\n",k);
	return 0;
}
