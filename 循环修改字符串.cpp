#include<stdio.h>
#include<string.h>

int main(void)
{			   
	char S1[10]="abababab";
	char last[10]="";
	char x[10]="abababab";
	char S2[]="ba";
	char S3[]="ab";
	char *p=S2;
	int cnt = 0;
	char *q=S1;
	int c=1;
	while(c)
	{
		c=0;
		while(*q)
		{   
			while(*q)
			{
				if(*p==*q)
				{ 
					p++;
					q++;
				}
				else
				{
					q++;
				}
				if(*p == NULL)
				{
					break;
				}
			}
             
			if(*q)
			{
				for(int i=0;i<strlen(S2);i++)
				{
					*(q+i-strlen(S2))=S3[i];
					c=1;
				}
			}
			p=S2;//	p=p-strlen(S2);
			cnt=0;
		}
		q=S1;
		puts(S1); 
		printf("\n");
//		strcpy(last,x);
//		strcpy(x,S1);
//		if(strcmp(x,last))
//			c=0;
//		else
//			c=1; 
	}
	return 0;	
 } 

	


