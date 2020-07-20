#include<stdio.h>
#include<windows.h>
#define FOOD -4     //食物
#define WALL -9   //墙
#define COL 35
#define ROW 20
#define VK_UP 72   //方向键上下左右的第二个值,方向键有两个值,第一个是224,分别是72,...
#define VK_DOWN 80
#define VK_LEFT 75
#define VK_RIGHT 77
#define int short  //把所有的int类型数据换成short类型节约空间 
/*心得，常量大写，变量有多个单词加下划线，函数多个单词首字母小写，其余首字母大写*/
//用word打特殊符号，再复制
void fangXiangChoice(int arr[][COL]);  //输入的方向的
void start(int p[][COL]);           //开始之前的初始化操作
void print(int* a);                 //输出函数，输出到屏幕
void produceFood(int a[][COL]);        //产生食物
void moveSnake(int (*arr)[COL],int * fx);          //蛇的移动
int head_v = 4,head_h = 5;
    //蛇头的纵向坐标和横向坐标,用大于0的数做蛇，从蛇尾到蛇头的数依次增大，
int arr[ROW][COL];
int speed_snake = 5;  //蛇移动的速度，几次循环执行一次来控制
int fang_xiang = VK_RIGHT;//蛇移动的方向，默认向右
int exitgame = 0;

HANDLE hOutput,hOutBuf;  //控制台屏幕缓冲区句柄
HANDLE *houtpoint;
COORD coord = {1,0};
DWORD bytes = 0;
char data[ROW][COL];
int zhixiang_hOutput = 0;  //通过指针轮流指向两个缓冲区，实现双缓冲 
int main(void)
{
    int k;
    start(arr);
    produceFood(arr);
    puts("嗨～欢迎你来到贪吃蛇的世界！请君坐好了，要开车了～");
    Sleep(2000);  //休眠2秒
    system("cls");
    hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,  //定义进程可以往缓冲区写数据
        FILE_SHARE_WRITE, //定义缓冲区可共享写权限
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,  //定义进程可以往缓冲区写数据
        FILE_SHARE_WRITE, //定义缓冲区可共享写权限
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    SetConsoleTitle(TEXT("贪吃蛇"));
	SMALL_RECT rc =  {0,0,COL+10,ROW+4};  //设置窗口大小，宽度和高度
	SetConsoleWindowInfo(hOutput,1,&rc);
	SetConsoleWindowInfo(hOutBuf,1,&rc);
    //隐藏两个缓冲区的光标
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize =1;
    SetConsoleCursorInfo(hOutput, &cci);
    SetConsoleCursorInfo(hOutBuf, &cci);
    while(1)
    {
        if(kbhit())
        {
            fangXiangChoice(arr);
            moveSnake(arr,&fang_xiang);
            print(arr[0]);
         }
       if(k++ % speed_snake == 0)
        {
             moveSnake(arr,&fang_xiang);
             print(arr[0]);
        }Sleep(40);
    }
    return 0;
}
void fangXiangChoice(int arr[][COL])
{
  	int key1,key2;
	key1 = getch();
	if(key1 == 27)//ESC建退出
 		exitgame = 1;
 	if(key1 == 224)
  	{
            key2 = getch();
		switch(key2)
  		{
            case VK_UP: if(fang_xiang != VK_DOWN) fang_xiang = VK_UP;  //如果在向下移动，那蛇就不能向上移动，下面的相同
                break;
            case VK_DOWN: if(fang_xiang != VK_UP) fang_xiang = VK_DOWN;
                break;
            case VK_LEFT: if(fang_xiang != VK_RIGHT) fang_xiang = VK_LEFT;
                break;
            case VK_RIGHT: if(fang_xiang != VK_LEFT) fang_xiang = VK_RIGHT;
    	}
	}
}
void start(int p[][COL])
{
    int i,j;
    p[head_v][head_h] = 2; //初始化蛇头，蛇身
    p[head_v][head_h-1] = 1;
    for(i = 0; i < ROW; i++)
    {
       for(j = 0; j < COL; j++)
       {
           if(i == 0 || i == ROW-1 || j == 0 || j == COL-1)
                p[i][j] = WALL;     //初始化墙
       }
    }
}
void produceFood(int a[][COL])
{
    int food_v,food_h;
    srand(time(NULL));
    food_v = rand() % ROW;
    food_h = rand() % COL;
    while(a[food_v][food_h] != 0)
    {
        food_v = rand() % ROW;
        food_h = rand() % COL;
    }
    a[food_v][food_h] = FOOD;
}
/**
//蛇头的纵向坐标和横向坐标,用大于0的数做蛇，从蛇尾到蛇头的数依次增大，
//碰到食物就把食物那个点的值变成蛇头值+1，食物的点变成蛇头，退出
//没有碰到食物，下一个点为空，就把下一个点的值变成蛇头值+1，
//在将整个数组大于0的值都减一，蛇尾为一的自然变为0，就消失了，其它情况直接退出
*/
void moveSnake(int (*arr)[COL],int * fx)  //根据传入的方向移动蛇
{
     int i,j,eat_food = 0; //为0表示没有吃到食物
     int temp = arr[head_v][head_h]; //记录现在蛇头的值
     if(*fx == VK_UP)
     {
         if(arr[head_v - 1][head_h] ==  0)    head_v--;
         else if(arr[head_v - 1][head_h] ==  FOOD)
              head_v--,eat_food = 1; //吃到食物了，蛇身不用减一
         else exitgame = 1;        //其它情况只有撞墙和吃蛇身
     }if(*fx  == VK_DOWN)
     {
         if(arr[head_v + 1][head_h] ==  0)    head_v++;
         else if(arr[head_v + 1][head_h] ==  FOOD)
              head_v++,eat_food =1;
        else exitgame = 1;
     }if(*fx  == VK_LEFT)
     {
         if(arr[head_v][head_h -1] ==  0)     head_h--;
         else if(arr[head_v][head_h -1] ==  FOOD)
              head_h--,eat_food = 1;
         else exitgame = 1;
     }if(*fx  == VK_RIGHT)
     {
         if(arr[head_v][head_h + 1] ==  0)    head_h++;
         else if(arr[head_v][head_h + 1] ==  FOOD)
              head_h++,eat_food = 1;
         else exitgame = 1;
     }
     /**没有吃的食物大于零的数都要减一*/
     arr[head_v][head_h] = temp+1;
     if(!eat_food)
     {
        for(i = 0; i < ROW; i++)
        {
            for(j = 0; j < COL; j++)
            {
                if(arr[i][j] > 0) arr[i][j] = arr[i][j] - 1;
            }
        }
     }
    else
        produceFood(arr); //吃到食物了，产生一个食物
}
void print(int* p)
{
    int i,j;
    char shuo_ming1[] = "请按方向键 ↑ ↓ ← → 的控制上下左右";
    char shuo_ming2[] = "连续按方向键会加速，退出按ESC键";
    for(i = 0; i < ROW; i++)
    {	
	   for(j = 0; j < COL; j++,p++)
       {
           if(*p == WALL)
                data[i][j] = '*'; 	//printf("■");    //墙墙
           if(*p == 0)
                data[i][j] = ' ';	 //printf("　");
           if(*p > 0)       //蛇
           {
               if(i == head_v && j == head_h) data[i][j] = '0';//printf("⊙");
               else data[i][j] = '@';	//printf("●");
           }
           if(*p == FOOD)
               data[i][j] = '@'; 	//printf("●");
       }//printf("\n");
    }
    //以下是缓冲代码
   zhixiang_hOutput = !zhixiang_hOutput ;
    if(!zhixiang_hOutput)
    {
        houtpoint = &hOutput;
    }
    else
    {
        houtpoint = &hOutBuf;
    }
    coord.Y = 1;
    WriteConsoleOutputCharacterA(*houtpoint,shuo_ming1,strlen(shuo_ming1), coord,&bytes);
    coord.Y++; WriteConsoleOutputCharacterA(*houtpoint,shuo_ming2,strlen(shuo_ming2), coord,&bytes);
    for(i = 0; i < ROW; i++)
    {
        coord.Y++ ;
        WriteConsoleOutputCharacterA(*houtpoint,(char *)data[i],COL, coord,&bytes);
    }
    if(exitgame)
    {
    	char score[20];//得分为蛇吃的食物乘以3
		sprintf(score,"你的得分为:%d",(arr[head_v][head_h]-2)*3);
		coord.Y++;
		WriteConsoleOutputCharacterA(*houtpoint,score,strlen(score), coord,&bytes);
		SetConsoleActiveScreenBuffer(*houtpoint);
		getch();exit(0);
    }
    SetConsoleActiveScreenBuffer(*houtpoint);} 

//————————————————
//版权声明：本文为CSDN博主「zh阿飞」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/z1832729975/article/details/88382018
