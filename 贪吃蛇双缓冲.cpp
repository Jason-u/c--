#include<stdio.h>
#include<windows.h>
#define FOOD -4     //ʳ��
#define WALL -9   //ǽ
#define COL 35
#define ROW 20
#define VK_UP 72   //������������ҵĵڶ���ֵ,�����������ֵ,��һ����224,�ֱ���72,...
#define VK_DOWN 80
#define VK_LEFT 75
#define VK_RIGHT 77
#define int short  //�����е�int�������ݻ���short���ͽ�Լ�ռ� 
/*�ĵã�������д�������ж�����ʼ��»��ߣ����������������ĸСд����������ĸ��д*/
//��word��������ţ��ٸ���
void fangXiangChoice(int arr[][COL]);  //����ķ����
void start(int p[][COL]);           //��ʼ֮ǰ�ĳ�ʼ������
void print(int* a);                 //����������������Ļ
void produceFood(int a[][COL]);        //����ʳ��
void moveSnake(int (*arr)[COL],int * fx);          //�ߵ��ƶ�
int head_v = 4,head_h = 5;
    //��ͷ����������ͺ�������,�ô���0�������ߣ�����β����ͷ������������
int arr[ROW][COL];
int speed_snake = 5;  //���ƶ����ٶȣ�����ѭ��ִ��һ��������
int fang_xiang = VK_RIGHT;//���ƶ��ķ���Ĭ������
int exitgame = 0;

HANDLE hOutput,hOutBuf;  //����̨��Ļ���������
HANDLE *houtpoint;
COORD coord = {1,0};
DWORD bytes = 0;
char data[ROW][COL];
int zhixiang_hOutput = 0;  //ͨ��ָ������ָ��������������ʵ��˫���� 
int main(void)
{
    int k;
    start(arr);
    produceFood(arr);
    puts("�ˡ���ӭ������̰���ߵ����磡��������ˣ�Ҫ�����ˡ�");
    Sleep(2000);  //����2��
    system("cls");
    hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,  //������̿�����������д����
        FILE_SHARE_WRITE, //���建�����ɹ���дȨ��
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,  //������̿�����������д����
        FILE_SHARE_WRITE, //���建�����ɹ���дȨ��
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    SetConsoleTitle(TEXT("̰����"));
	SMALL_RECT rc =  {0,0,COL+10,ROW+4};  //���ô��ڴ�С����Ⱥ͸߶�
	SetConsoleWindowInfo(hOutput,1,&rc);
	SetConsoleWindowInfo(hOutBuf,1,&rc);
    //���������������Ĺ��
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
	if(key1 == 27)//ESC���˳�
 		exitgame = 1;
 	if(key1 == 224)
  	{
            key2 = getch();
		switch(key2)
  		{
            case VK_UP: if(fang_xiang != VK_DOWN) fang_xiang = VK_UP;  //����������ƶ������߾Ͳ��������ƶ����������ͬ
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
    p[head_v][head_h] = 2; //��ʼ����ͷ������
    p[head_v][head_h-1] = 1;
    for(i = 0; i < ROW; i++)
    {
       for(j = 0; j < COL; j++)
       {
           if(i == 0 || i == ROW-1 || j == 0 || j == COL-1)
                p[i][j] = WALL;     //��ʼ��ǽ
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
//��ͷ����������ͺ�������,�ô���0�������ߣ�����β����ͷ������������
//����ʳ��Ͱ�ʳ���Ǹ����ֵ�����ͷֵ+1��ʳ��ĵ�����ͷ���˳�
//û������ʳ���һ����Ϊ�գ��Ͱ���һ�����ֵ�����ͷֵ+1��
//�ڽ������������0��ֵ����һ����βΪһ����Ȼ��Ϊ0������ʧ�ˣ��������ֱ���˳�
*/
void moveSnake(int (*arr)[COL],int * fx)  //���ݴ���ķ����ƶ���
{
     int i,j,eat_food = 0; //Ϊ0��ʾû�гԵ�ʳ��
     int temp = arr[head_v][head_h]; //��¼������ͷ��ֵ
     if(*fx == VK_UP)
     {
         if(arr[head_v - 1][head_h] ==  0)    head_v--;
         else if(arr[head_v - 1][head_h] ==  FOOD)
              head_v--,eat_food = 1; //�Ե�ʳ���ˣ������ü�һ
         else exitgame = 1;        //�������ֻ��ײǽ�ͳ�����
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
     /**û�гԵ�ʳ������������Ҫ��һ*/
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
        produceFood(arr); //�Ե�ʳ���ˣ�����һ��ʳ��
}
void print(int* p)
{
    int i,j;
    char shuo_ming1[] = "�밴����� �� �� �� �� �Ŀ�����������";
    char shuo_ming2[] = "���������������٣��˳���ESC��";
    for(i = 0; i < ROW; i++)
    {	
	   for(j = 0; j < COL; j++,p++)
       {
           if(*p == WALL)
                data[i][j] = '*'; 	//printf("��");    //ǽǽ
           if(*p == 0)
                data[i][j] = ' ';	 //printf("��");
           if(*p > 0)       //��
           {
               if(i == head_v && j == head_h) data[i][j] = '0';//printf("��");
               else data[i][j] = '@';	//printf("��");
           }
           if(*p == FOOD)
               data[i][j] = '@'; 	//printf("��");
       }//printf("\n");
    }
    //�����ǻ������
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
    	char score[20];//�÷�Ϊ�߳Ե�ʳ�����3
		sprintf(score,"��ĵ÷�Ϊ:%d",(arr[head_v][head_h]-2)*3);
		coord.Y++;
		WriteConsoleOutputCharacterA(*houtpoint,score,strlen(score), coord,&bytes);
		SetConsoleActiveScreenBuffer(*houtpoint);
		getch();exit(0);
    }
    SetConsoleActiveScreenBuffer(*houtpoint);} 

//��������������������������������
//��Ȩ����������ΪCSDN������zh���ɡ���ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https://blog.csdn.net/z1832729975/article/details/88382018
