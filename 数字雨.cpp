#include<stdio.h>
#include<time.h>
#include<windows.h>
typedef struct
{
	int x,y;
	char ch;
}STU;
STU st[100];
//出现位置   
 
void gotoxy(int x, int y)  
{  
    HANDLE hout;  
    COORD pos;  
    pos.X = x;  
    pos.Y = y;  
	
    hout = GetStdHandle(STD_OUTPUT_HANDLE);  
    SetConsoleCursorPosition(hout, pos);  
}  
 
/*隐藏光标*/  
void show_cursor(int hide)  
{  
    CONSOLE_CURSOR_INFO cciCursor;  
    HANDLE hout;  
	
    hout = GetStdHandle(STD_OUTPUT_HANDLE);  
    if(GetConsoleCursorInfo(hout, &cciCursor))  
    {  
        cciCursor.bVisible = hide;  
        SetConsoleCursorInfo(hout, &cciCursor);  
    }  
}  
 
/*设置颜色*/  
void set_color(int color)  
{  
	
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);  
}  
 
 
main()
{
	int i,j;
	show_cursor(0);
	srand(time(NULL));
	//初始化结构体 
	for (i=0;i<100;i++)
	{
		st[i].x = rand()%80;
		st[i].y = rand()%20;
		st[i].ch = rand()%(49-47)+48;
	}
	while (1)
	{
		for (i=0;i<100;i++)
		{
			gotoxy(st[i].x,st[i].y);
			set_color(0x2);
			putchar(st[i].ch);
			gotoxy(st[i].x,st[i].y-5);
			putchar(' ');
			st[i].y++;
			st[i].ch = rand()%(49-47)+48;
			if (st[i].y-5>=18)
			{
				gotoxy(st[i].x,st[i].y-1);
				putchar(' ');
				gotoxy(st[i].x,st[i].y-2);
				putchar(' ');
				gotoxy(st[i].x,st[i].y-3);
				putchar(' ');
				gotoxy(st[i].x,st[i].y-4);
				putchar(' ');
				gotoxy(st[i].x,st[i].y-4);
				putchar(' ');
			}
			if (st[i].y > 23)
			{
				st[i].x = rand()%80;
				st[i].y = rand()%20;
			}
			gotoxy(st[i].x,st[i].y);
			set_color(0xA);
			putchar(st[i].ch);
		}
		Sleep(120);
	}
}
