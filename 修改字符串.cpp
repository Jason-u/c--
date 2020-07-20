#include<stdio.h>
#include<string.h>

int main(void)
{			   
	char S1[]="abababaab";//因为要修改s1，所以要用字符数组，而非字符串常量
	char last[10]="";//这里用的last，x,我原来写的是指针，后来发现了很恐怖的错误，稍后再说
	char x[]="abababaab";//用x数组来存储最新修改过的s1。
	char S2[]="baa";
	char S3[]="aba";
	char *p=S2;//使用指针来遍历数组
	int cnt = 0;
	char *q=S1;
	int c=1;
	while(c)//在这里终于体会到什么是模块化思想，3个while，3个层面。
	{
		c=0;
		while(*q){//是否将s1中的ba全部替换一遍
              while(cnt<strlen(S2))//这个条件厉害，适用于多中情况的字符串，比下面代码中的条件适用性更强
      {
			if(*p==*q)
				{
					p++;
					q++;
					cnt++;
				}
				else
				{
					if(cnt)//这里的cnt=1用来表示当第一个字母相等，第二个不等的情况，实际上这里的1应该换成更为普遍的形式，不过我这里已经默认了，s2的长度为2
					{ 
						p=S2;//将s2的指针指回初始位置
						q=q-cnt+1; 
						cnt=0;
					}
					else if(cnt==0)
				{
					q++;
				}
				}
				if(*q== NULL)//这个条件是原先没想到的，，没有这个条件，出不去
				{
					break;
				}
      }
			if(*q)//原来也没有控制是否要打印，通过调试发现在s1的末尾是可能出现越界的，而实际上，只有*q有值，我们才进行替换
			{
				for(int i=0;i<strlen(S2);i++)
				{
					*(q+i-strlen(S2))=S3[i];
					c=1;
				}
			}
			p=S2;//	p=p-strlen(S2);原来写的是注释中的条件，只是觉得这种形式看起来牛一点，故意写成这样的，谁知道翻车了，为此浪费了有1个小时，原因是写成这种形式之后，可能p原来并没有指向NULL，所以可能越界
			cnt=0;
		}
		q=S1;
		puts(S1); 
		printf("\n");
	}
	return 0;	
 }
