#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>


// 引用 Windows Multimedia API
#pragma comment(lib,"Winmm.lib")


#define High 579 ?// 游戏画面尺寸
#define Width 1024


IMAGE img_bk; // 背景图片
float position_x,position_y; // 飞机位置
float bullet_x,bullet_y; // 子弹位置
float enemy_x,enemy_y; // 敌机位置
float enemy2_x,enemy2_y;// 敌机位置
float enemy3_x,enemy3_y;// 敌机位置
IMAGE img_planeNormal1,img_planeNormal2; // 正常飞机图片
IMAGE img_planeExplode1,img_planeExplode2; // 爆炸飞机图片
IMAGE img_bullet1,img_bullet2; // 子弹图片
IMAGE img_enemyPlane1,img_enemyPlane2,img_enemyPlane3,img_enemyPlane4; // 敌机图片
int isExpolde = 0; // 飞机是否爆炸
int shengming = 3;//生命
int score = 0; // 得分
int guanka=1;//关卡
int temp=2;
int gameStatus = 0; // 游戏状态，0为初始菜单界面，1为正常游戏，2为结束游戏状态，3为游戏暂停
void startMenu(); // 初始菜单界面
void pauseMenu(); // 游戏暂停后菜单界面，一般按ESC键后启动该界面
void startup(); ?// 数据初始化	
void show(); ?// 显示画面
void updateWithoutInput(); ?// 与用户输入无关的更新
void updateWithInput(); ? ? // 与用户输入有关的更新
void gameover(); ? ? // 游戏结束、后续处理
void readRecordFile(); ?//读取游戏数据文件存档
void writeRecordFile(); ?//存储游戏数据文件存档


void startMenu() // 初始菜单界面
{
putimage(0, 0, &img_bk);	// 显示背景
setbkmode(TRANSPARENT);
settextcolor(BLACK);
settextstyle(50,0, _T("黑体"));
outtextxy(Width*0.3, High*0.2, "1 新游戏");
outtextxy(Width*0.3, High*0.3, "2 读取游戏存档");
outtextxy(Width*0.3, High*0.4, "3 退出");


settextcolor(BLUE);
settextstyle(30,0, _T("黑体"));
outtextxy(Width*0.25, High*0.6, "鼠标移动控制飞机移动");
outtextxy(Width*0.25, High*0.65, "鼠标左键发射子弹");
outtextxy(Width*0.25, High*0.7, "ESC键暂停游戏");
outtextxy(Width*0.25, High*0.75, "撞击后按任意键重新开始");
FlushBatchDraw();
Sleep(2);


char input;
if(kbhit()) ?// 判断是否有输入
{
input = getch(); ?// 根据用户的不同输入来移动，不必输入回车
if (input == '1')?
gameStatus = 1;
else if (input == '2')
{
readRecordFile();
gameStatus = 1;
}
else if (input == '3')
{
gameStatus = 2;
exit(0);
}
}
}


void pauseMenu() // 游戏暂停后菜单界面，一般按ESC键后启动该界面
{
putimage(0, 0, &img_bk);	// 显示背景
setbkmode(TRANSPARENT);
settextcolor(BLACK);
settextstyle(50,0, _T("黑体"));
outtextxy(Width*0.3, High*0.2, "1 继续游戏");
outtextxy(Width*0.3, High*0.3, "2 保存档案");
outtextxy(Width*0.3, High*0.4, "3 退出");


settextcolor(BLUE);
settextstyle(30,0, _T("黑体"));
outtextxy(Width*0.25, High*0.6, "鼠标移动控制飞机移动");
outtextxy(Width*0.25, High*0.65, "鼠标左键发射子弹");
outtextxy(Width*0.25, High*0.7, "ESC键暂停游戏");
outtextxy(Width*0.25, High*0.75, "撞击后按任意键重新开始");
FlushBatchDraw();
Sleep(2);

char input;
if(kbhit()) ?// 判断是否有输入
{
input = getch(); ?// 根据用户的不同输入来移动，不必输入回车
if (input == '1')?
gameStatus = 1;
else if (input == '2')
{
writeRecordFile();
gameStatus = 1;
}
else if (input == '3')
{
gameStatus = 2;
exit(0);
}
}
}


void readRecordFile() ?//读取游戏数据文件存档
{
FILE *fp;
fp = fopen(".\\gameRecord.dat","r");
fscanf(fp,"%f %f %f %f %f %f %d %d",&position_x,&position_y,&bullet_x,&bullet_y,&enemy_x,&enemy_y,&isExpolde,&score);
fclose(fp);
}


void writeRecordFile() ?//存储游戏数据文件存档
{
FILE *fp;
fp = fopen(".\\gameRecord.dat","w");
fprintf(fp,"%f %f %f %f %f %f %d %d",position_x,position_y,bullet_x,bullet_y,enemy_x,enemy_y,isExpolde,score);
fclose(fp);
}


void startup()
{
mciSendString("open .\\game_music.mp3 alias bkmusic", NULL, 0, NULL);//打开背景音乐
mciSendString("play bkmusic repeat", NULL, 0, NULL); ?// 循环播放


initgraph(Width,High);
// 获取窗口句柄
HWND hwnd = GetHWnd();
// 设置窗口标题文字
SetWindowText(hwnd, "数据结构小游戏开发-飞机大战");


loadimage(&img_bk, ".\\background.jpg");
loadimage(&img_planeNormal1, ".\\planeNormal_1.jpg");
loadimage(&img_planeNormal2, ".\\planeNormal_2.jpg");
loadimage(&img_bullet1, ".\\bullet1.jpg");
loadimage(&img_bullet2, ".\\bullet2.jpg");
loadimage(&img_enemyPlane1, ".\\enemyPlane1.jpg");
loadimage(&img_enemyPlane2, ".\\enemyPlane2.jpg");
loadimage(&img_enemyPlane3, ".\\enemyPlane3.jpg");
loadimage(&img_enemyPlane4, ".\\enemyPlane4.jpg");
loadimage(&img_planeExplode1, ".\\planeExplode_1.jpg");
loadimage(&img_planeExplode2, ".\\planeExplode_2.jpg");


position_x = Width*0.5;
position_y = High*0.8;


bullet_x = position_x;
bullet_y = -25;


enemy_x = Width*0.5;
enemy_y = 10;


BeginBatchDraw();	

while (gameStatus==0)
startMenu(); // 初始菜单界面
}


void startup2()
{
loadimage(&img_bk, ".\\background.jpg");
loadimage(&img_planeNormal1, ".\\planeNormal_1.jpg");
loadimage(&img_planeNormal2, ".\\planeNormal_2.jpg");
loadimage(&img_bullet1, ".\\bullet1.jpg");
loadimage(&img_bullet2, ".\\bullet2.jpg");
loadimage(&img_enemyPlane1, ".\\enemyPlane1.jpg");
loadimage(&img_enemyPlane2, ".\\enemyPlane2.jpg");
loadimage(&img_enemyPlane3, ".\\enemyPlane3.jpg");
loadimage(&img_enemyPlane4, ".\\enemyPlane4.jpg");
loadimage(&img_planeExplode1, ".\\planeExplode_1.jpg");
loadimage(&img_planeExplode2, ".\\planeExplode_2.jpg");


position_x = Width*0.5;
position_y = High*0.9;
bullet_x = position_x;
bullet_y = -25;
enemy_x = Width*0.5;
enemy_y = 10;


BeginBatchDraw();
}


void show()
{
while (gameStatus==3)
pauseMenu(); // 游戏暂停后菜单界面，一般按ESC键后启动该界面


putimage(0, 0, &img_bk);	// 显示背景	
if (isExpolde<=4)
{
putimage(position_x-50, position_y-60, &img_planeNormal1,NOTSRCERASE); // 显示正常飞机	
putimage(position_x-50, position_y-60, &img_planeNormal2,SRCINVERT);


putimage(bullet_x-7, bullet_y, &img_bullet1,NOTSRCERASE); // 显示子弹	
putimage(bullet_x-7, bullet_y, &img_bullet2,SRCINVERT);


putimage(enemy_x, enemy_y, &img_enemyPlane1,NOTSRCERASE); // 显示敌机	
putimage(enemy_x, enemy_y, &img_enemyPlane2,SRCINVERT);

if(guanka>=2)
{
if(score==10)
temp=1;
if(temp==1)
{
putimage(enemy2_x, enemy2_y, &img_enemyPlane3,NOTSRCERASE); // 显示敌机	boos
putimage(enemy2_x, enemy2_y, &img_enemyPlane4,SRCINVERT);
}


putimage(enemy3_x, enemy3_y, &img_enemyPlane1,NOTSRCERASE); // 显示敌机	
putimage(enemy3_x, enemy3_y, &img_enemyPlane2,SRCINVERT);
}
}
else
{
putimage(position_x-50, position_y-60, &img_planeExplode1,NOTSRCERASE); // 显示爆炸飞机	
putimage(position_x-50, position_y-60, &img_planeExplode2,SRCINVERT);
}


settextcolor(RED);
settextstyle(20,0, _T("黑体"));
outtextxy(Width*0.68, High*0.95, "得分：");
char s[5];
sprintf(s, "%d", score);
outtextxy(Width*0.74, High*0.95, s);


settextcolor(RED);
settextstyle(20,0, _T("黑体"));
outtextxy(Width*0.2, High*0.95, "生命：");
char s2[5];
sprintf(s2, "%d", shengming);
outtextxy(Width*0.26, High*0.95, s2);


settextcolor(BLACK);
settextstyle(25,0, _T("黑体"));
outtextxy(Width*0.45, High*0.95, "关卡:");
char s3[5];
sprintf(s3, "%d", guanka);
outtextxy(Width*0.52, High*0.95, s3);


FlushBatchDraw();
Sleep(2);
}


void updateWithoutInput()
{
if (isExpolde<=4)
{	
if (bullet_y>-25)
bullet_y = bullet_y-2;

if (enemy_y<High-25)
{
enemy_y = enemy_y+0.5;
}
else
enemy_y = 5;


if(temp==1)
if (enemy2_y<High-25)
{
enemy2_y = enemy2_y+0.75;
}
else
{
enemy2_y = 5;
enemy2_x = rand()%Width;
}
if(guanka>=2)
if (enemy3_y<High-25)
{
enemy3_y = enemy2_y+0.45;
}
else
{
enemy3_y = 5;
enemy3_x = rand()%Width+70;
}


if (abs(bullet_x-enemy_x)+abs(bullet_y-enemy_y) < 80) ?// 子弹击中敌机
{
enemy_x = rand()%Width;
enemy_y = -40;
bullet_y = -85;	
mciSendString("stop gemusic", NULL, 0, NULL); ? // 先把前面一次的音乐停止
mciSendString("close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
mciSendString("open .\\gotEnemy.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
mciSendString("play gemusic", NULL, 0, NULL); // 仅播放一次
score++;
}


if(abs(bullet_x-enemy2_x)+abs(bullet_y-enemy2_y) < 80) ?// 子弹击中敌机
{
enemy2_x = rand()%Width;
enemy2_y = -40;
bullet_y = -85;
mciSendString("stop gemusic", NULL, 0, NULL); ? // 先把前面一次的音乐停止
mciSendString("close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
mciSendString("open .\\gotEnemy.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
mciSendString("play gemusic", NULL, 0, NULL); // 仅播放一次
temp++;
score++;
}


if(abs(bullet_x-enemy3_x)+abs(bullet_y-enemy3_y) < 80) ?// 子弹击中敌机
{
enemy3_x = rand()%Width;
enemy3_y = -40;
bullet_y = -85;
mciSendString("stop gemusic", NULL, 0, NULL); ? // 先把前面一次的音乐停止
mciSendString("close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
mciSendString("open .\\gotEnemy.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
mciSendString("play gemusic", NULL, 0, NULL); // 仅播放一次
score++;
}


if(score>=10)
{
guanka=2;
}
if(score>=25)
{
guanka=3;
}
if (abs(position_x-enemy_x)+abs(position_y-enemy_y) < 150||
abs(position_x-enemy2_x)+abs(position_y-enemy2_y) < 150||
abs(position_x-enemy3_x)+abs(position_y-enemy3_y) < 150) ?// 敌机击中我们
{
isExpolde ++ ;
if(isExpolde==1)
{
startup2();
shengming=2;
}
if(isExpolde==3)
{
startup2();
? ?shengming=1;
}
}
}
}


void updateWithInput()
{
if (isExpolde<=4)
{
MOUSEMSG m;	// 定义鼠标消息
while (MouseHit()) ?//这个函数用于检测当前是否有鼠标消息
{
m = GetMouseMsg();
if(m.uMsg == WM_MOUSEMOVE)
{
// 飞机的位置等于鼠标所在的位置
position_x = m.x;
position_y = m.y;	
}
else if (m.uMsg == WM_LBUTTONDOWN)
{
// 按下鼠标左键，发射子弹
bullet_x = position_x;
bullet_y = position_y-85;
mciSendString("stop fgmusic", NULL, 0, NULL); ? // 先把前面一次的音乐停止
mciSendString("close fgmusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
mciSendString("open .\\f_gun.mp3 alias fgmusic", NULL, 0, NULL); // 打开跳动音乐
mciSendString("play fgmusic", NULL, 0, NULL); // 仅播放一次
}
}	
}

char input;
if(kbhit()) ?// 判断是否有输入
{
input = getch(); ?// 根据用户的不同输入来移动，不必输入回车
if (input == 27) // ESC键的ACSII码为27
{
gameStatus = 3;
}
}
}


void gameover()
{
EndBatchDraw();
getch();
closegraph();
}


int main()
{
startup(); ?// 数据初始化	
while (1) ?// ?游戏循环执行
{
show(); ?// 显示画面
updateWithoutInput(); ?// 与用户输入无关的更新
updateWithInput(); ? ? // 与用户输入有关的更新
}
gameover(); ? ? // 游戏结束、后续处理
return 0;
}
————————————————
版权声明：本文为CSDN博主「这个程序员不太冷」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/h471507602/article/details/80945700
