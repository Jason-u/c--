#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int main(void)
{
	int x1,y1,Y1,X1,X2,Y2,X3,Y3,X4,Y4,p,q,i;
	char ch;
	x1=4,Y1=2;
	X2=5,Y2=2;
	X3=4,Y3=4;
	X4=5,Y4=4;
	
	int sum=0;
	p=3;q=2;
	char a[12] [12]={"##########",
					"##     ###",
                    "##o      #",
                    "# s o  o #",
                    "# * * o ##",
                    "##* *   ##",
                    "##########",
    };

	for(i=0;i<=6;i++)
	puts(a[i]);
	ch=getch();
	while(a[4][2]!='@'||a[4][4]!='@'||a[5][2]!='@'||a[5][4]!='@')
	{
		if(ch=='s')
{
	if(a[p+1][q]!='#')
	{
		if(a[p+1][q]==' ')
		{
			a[p][q]=' ';
			p++;
			a[p][q]='s';
		}else if(a[p+1][q]=='o'&&a[p+2][q]!='#')
		{ 
		if(a[p+2][q]==' ')
		{
				a[p][q]=' ';
				p++;
				a[p][q]='s';
				a[p+1][q]='o';
		}else if(a[p+2][q]=='*')
		{
			a[p][q]=' ';
			p++;
			a[p][q]='s';
			a[p+1][q]='@';
		}
		}else if(a[p+1][q]=='@'&&a[p+2][q]!='#')
		{
		
		if(a[p+2][q]==' ')
		{
			a[p][q]=' ';
			p++;
			a[p][q]='s';
			a[p+1][q]='o';
		}else if(a[p+2][q]=='*')
		{
			a[p][q]=' ';
			p++;
			a[p][q]=' ';
			a[p+1][q]='@';}
		}else if(a[p+1][q]='*')
		{
			a[p][q]=' ';
			p++;
			a[p][q]='s';
		}
	}
}
if(ch=='w')
{
	if(a[p-1][q]!='#')
	{
		if(a[p-1][q]==' ')
		{
			a[p][q]=' ';
			p--;
			a[p][q]='s';
		}else 
		if(a[p-1][q]=='o'&&a[p-2][q]!='#'){
		
		if(a[p-1][q]=='o'&&a[p-2][q]==' ')
		{
				a[p][q]=' ';
				p--;
				a[p][q]='s';
				a[p-1][q]='o';
		}else if(a[p-1][q]=='o'&&a[p-2][q]=='*')
		{
			a[p][q]=' ';
			p--;
			a[p][q]='s';
			a[p-1][q]='@';}
		}else if(a[p-1][q]=='@'&&a[p-2][q]!='#'){
		
		
		if(a[p-2][q]==' ')
		{
			a[p][q]=' ';
			p--;
			a[p][q]='s';
			a[p-1][q]='o';
		}else if(a[p-2][q]=='*')
		{
			a[p][q]=' ';
			p--;
			a[p][q]=' ';
			a[p-1][q]='@';
		}}else if(a[p-1][q]='*')
		{
			a[p][q]=' ';
			p--;
			a[p][q]='s';
		}
	}
}
if(ch=='a')
{
	if(a[p][q-1]!='#')
	{
		if(a[p][q-1]==' ')
		{
			a[p][q]=' ';
			q--;
			a[p][q]='s';
		}else if(a[p][q-1]=='o'&&a[p][q-2]!='#'){
		
		if(a[p][q-2]==' ')
		{
				a[p][q]=' ';
				q--;
				a[p][q]='s';
				a[p][q-1]='o';
		}else if(a[p][q-2]=='*')
		{
			a[p][q]=' ';
			q--;
			a[p][q]='s';
			a[p][q-1]='@';}
		}else if(a[p][q-1]=='@'&&a[p][q-2]!='#')
		{
		
		 if(a[p][q-2]==' ')
		{
			a[p][q]=' ';
			q--;
			a[p][q]='s';
			a[p][q-1]='o';
		}else if(a[p][q-2]=='*')
		{
			a[p][q]=' ';
			q--;
			a[p][q]=' ';
			a[p][q-1]='@';
		}}else if(a[p][q-1]='*')
		{
			a[p][q]=' ';
			q--;
			a[p][q]='s';
		}
	}
}
if(ch=='d')
{
	if(a[p][q+1]!='#')
	{
		if(a[p][q+1]==' ')
		{
			a[p][q]=' ';
				q++;
			a[p][q]='s';
		}else if(a[p][q+1]=='o'&&a[p][q+2]!='#'){
		 if(a[p][q+2]==' ')
		{
				a[p][q]=' ';
				q++;
				a[p][q]='s';
				a[p][q+1]='o';
		}else if(a[p][q+2]=='*')
		{
			a[p][q]=' ';
			q++;
			a[p][q]='s';
			a[p][q+1]='@';
		}}else if(a[p][q+1]=='@'&&a[p][q+2]!='#'){
		if(a[p][q+2]==' ')
		{
			a[p][q]=' ';
			q++;
			a[p][q]='s';
			a[p][q+1]='o';
		}else if(a[p][q+2]=='*')
		{
			a[p][q]=' ';
			q++;
			a[p][q]=' ';
			a[p][q+1]='@';
		}}else if(a[p][q+1]='*')
		{
			a[p][q]=' ';
			q++;
			a[p][q]='s';
		}
	}
}
if(a[4][2]!='@'&&a[4][2]!='s')
		a[4][2]='*';
		if(a[5][2]!='@'&&a[5][2]!='s')
		a[5][2]='*';
		if(a[4][4]!='@'&&a[4][4]!='s')
		a[4][4]='*';
		if(a[5][4]!='@'&&a[5][4]!='s')
		a[5][4]='*';
		system("cls");
		for(i=0;i<=6;i++)
		puts(a[i]);
		ch=getch();
		}
		system("cls");
		printf("you win!");
	return 0;
}

