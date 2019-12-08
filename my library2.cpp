 #include<stdio.h>//实现一个书本分类，评分，借书，还书 ,
//删除时打印被删除书籍的信息，给查看的方式排版 
#include<windows.h>
#include<conio.h>
typedef struct The_users   //用户个人信息 
{
    char id[20]; //账号 
    char pwd[20]; //密码 
    struct The_users *next;
}users;
typedef struct Book{
	char bookname[20];
	char writer[20];
	int id;//图书编号 
	char press[20];//出版社 
	int isjy;
	int  notjy; 
	char publishtime[20];//出版时间 
	int price;//书的价钱 
	int num_book;
	struct Book *next;
}book; 
book *head2=(book*)malloc(sizeof(book));
//删除系列函数 
void del_booknum(book *q);
void del_bookname(book *q);
void del_bookwriter(book *q);
void del_press(book *q);
void del_bookmenu();

//借阅函数

void lend_book(); 
void lend_name(book *p);
void lend_press(book *p);
void lend_writer(book *p);

//功能菜单 
void function_menu();

//插入书籍数计算目前书籍总数 
int tongji(struct song *head);

void add_book();

//修改系列函数 
void modify_book();
void name_mod();
void num_mod();
 
 //读写文件

void writefile();
void readfile() ;

//创建文件 
void cre_doucument();

void menu(); 
void quit();//退出 
void zhuce();//注册账号 
void login(); //登录 
//对书进行初始化 
void initial_book(book *p);  
void insert_book();//插入 
void broswer_book();//浏览 
void sort_book();//排序 
void home_book();//书库 
int main(void)
{
	head2->next=NULL;
	system("COLOR 30");
//    cre_doucument();
			printf("\n");
 			printf("\n");
 			printf("\n");
 			printf("\n");
 			printf("\n");
 			printf("\n\n\n\n\n\n");
 			printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t\t\t\t\t\t┃**********************************************************┃\n");
	printf("\t\t\t\t\t\t\t\t┃***┏━━━━━━━━━━━━━━━━━━━━━━━━┓***┃\n");
	printf("\t\t\t\t\t\t\t\t┃***┃************************************************┃***┃\n");
	printf("\t\t\t\t\t\t\t\t┃***┃***                                         ****┃***┃\n");
	printf("\t\t\t\t\t\t\t\t┃***┃***         欢迎使用图书管理信息系统        ****┃***┃\n");
	printf("\t\t\t\t\t\t\t\t┃***┃***                                         ****┃***┃\n");
	printf("\t\t\t\t\t\t\t\t┃***┃***                                         ****┃***┃\n");
	printf("\t\t\t\t\t\t\t\t┃***┃***                 jiasen                  ****┃***┃\n");
	printf("\t\t\t\t\t\t\t\t┃***┃***                                         ****┃***┃\n"); 
	printf("\t\t\t\t\t\t\t\t┃***┃*               2019年11月20日              ****┃***┃\n");
	printf("\t\t\t\t\t\t\t\t┃***┃***                                         ****┃***┃\n");
	printf("\t\t\t\t\t\t\t\t┃***┃************************************************┃***┃\n");
	printf("\t\t\t\t\t\t\t\t┃***┗━━━━━━━━━━━━━━━━━━━━━━━━┛***┃\n");
	printf("\t\t\t\t\t\t\t\t┃**********************************************************┃\n");
	printf("\t\t\t\t\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	system("pause");
	readfile();
	menu();
	writefile();
	return 0;
 } 
 void menu()
 {
 	int cmd;
 	int n=1;
 		system("cls");
 			printf("\n");
 			printf("\n");
 			printf("\n");
 			printf("\n");
 			printf("\n");
 			printf("\n");
 			printf("\n");
 			printf("\n");
	printf("\t\t\t\t\t\t\t\t\t|                1.注册                        |\n");
	printf("\t\t\t\t\t\t\t\t\t|                                              |\n");
	printf("\t\t\t\t\t\t\t\t\t|                                              |\n");
	printf("\t\t\t\t\t\t\t\t\t|                                              |\n");
	printf("\t\t\t\t\t\t\t\t\t|                2.登陆                        |\n");
	printf("\t\t\t\t\t\t\t\t\t|                                              |\n");
	printf("\t\t\t\t\t\t\t\t\t|                                              |\n");
	printf("\t\t\t\t\t\t\t\t\t|                                              |\n");
	printf("\t\t\t\t\t\t\t\t\t|                3.退出                        |\n");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t");
	printf("选择："); 
	scanf("%d",&cmd);
	while(n)
	{
		fflush(stdin);
		n=0;
		switch(cmd){
		case 1:
			zhuce();
			login();
			break;
		case 2:
			login();
			break;
		case 3:
			quit();
			break;
		default:
			printf("\t\t\t\t\t\t\t\t\t请输出1~3之间的命令！！");
			n=1;
			scanf("%d",&cmd);	
	//getchar();
	}
	}
 }
void cre_doucument()
{
	FILE *fp;
	fp=fopen("userdata.txt","a");//最好检验一下是否成功创建了文件 
	fclose(fp);
} 
void zhuce()
 {
 	char ch=0;
 	FILE *fp;
 	fp=fopen("userdata.txt","a+");
 	int k=0;
 	int i=0;
 	char admin[20];
 	char password[20];
    char password2[20];
    users user; //在这里没啥用，在歌曲中是用来比较的 
 	printf("\t\t\t\t\t\t\t\t\t请输入账号： ");
	scanf("%s",admin);
	do{ 
	 k=0;
	printf("\t\t\t\t\t\t\t\t\t请输入密码： ");
	while((ch=getch())!='\r'||i==0)//这里面的i==0也是用来克服空密码问题的，并且这里的思路是
	//第一个条件是出口条件，所以再找一个出口条件，即i==0 
	{
		if(ch=='\r')//克服空密码也能行的问题 
		continue;
			 if(ch=='\b')
			{
				if(i!=0)
				{
					printf("\b \b");
					i--;
				}}
			else 
			{
				password[i]=ch;
				printf("*");
				i++;
			}
	}
	password[i]='\0';
	printf("\n\t\t\t\t\t\t\t\t\t请再输入一遍密码： ");
	i=0;
	while((ch=getch())!='\r'||i==0)
	{
		if(ch=='\r')
		{
			continue;
		}
		 if(ch=='\b')
			{
				if(i!=0)
				{
					printf("\b \b");
					i--;
				}}
				else 
			{
				password2[i]=ch;
				printf("*");
				i++;
			}
	}
	password2[i]='\0';
	if(strcmp(password,password2))
	{
		printf("\t\t\t\t\t\t\t\t\t两次密码不一致，请重新输入\n"); 
		k=1;
	 }else if(strcmp(password,password2)==0)
	 {
	 printf("\n\t\t\t\t\t\t\t\t\t注册成功！！\n");
	fprintf(fp,"%s %s\n",admin,password);
	 } 
	 }while(k); 
	 printf("\n\t\t\t\t\t\t\t\t\t正在切换页面，请稍等");
	 printf("。");
	 Sleep(300);
	 printf("。");
	 Sleep(300);
	 printf("。");
	 Sleep(300);
	  printf("。");
	 Sleep(300);
	  printf("。");
	 Sleep(300);
	  printf("。");
	 Sleep(300);
	 system("cls"); 
	 fclose(fp);//之前这里一直都没有写关闭文件，导致下一个函数login一直是错的，这是怎么回事 
 }
void login()
 {

  	int i=0;
   char ch; 
 	int flag=0;
 	FILE *fp;
 	users user;
 	fp=fopen("userdata.txt","r");
 	char id[20];
 	char pwd[20];
 	while(fp== NULL)
	{
		printf("\n\n\n\n");
		printf("\n\n\t\t\t\t\t\t\t\t\t文件为空，请先去注册!");
		system("cls");
		printf("\n\n\t\t\t\t\t\t\t\t\t是否选择去注册(Y/y)");
		getchar();
		if(getchar() =='Y' || getchar()=='y')
			{
			zhuce();
			break;}
			else
			break;
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t\t\t请登录： "); 
	printf("\n\n\n\n");
 	printf("\t\t\t\t\t\t\t用户名：");
	scanf("%s",id); 
	printf("\t\t\t\t\t\t\t密码：");
		while((ch=getch())!='\r'||i==0)//这里面的i==0也是用来克服空密码问题的，并且这里的思路是
	//第一个条件是出口条件，所以再找一个出口条件，即i==0 
	{
		if(ch=='\r')//克服空密码也能行的问题 
		continue;
			 if(ch=='\b')
			{
				if(i!=0)
				{
					printf("\b \b");
					i--;
				}}
			else 
			{
				pwd[i]=ch;
				printf("*");
				i++;
			}
	}
	pwd[i]='\0';
	 	while(!feof(fp))
		{
			fscanf(fp,"%s%s\n",user.id,user.pwd);  
			if(strcmp(id,user.id)==0 && strcmp(pwd,user.pwd)==0)
			{
				flag=1;
				break;
			} 
		}
		fclose(fp);
	 if(flag)
	 {
	 	printf("  \n\n\t\t\t\t\t      登录成功！\n");
				 printf("\n\t\t\t\t\t\t\t\t\t正在切换页面，请稍等");
				 printf("。");
				 Sleep(100);
				 printf("。");
				 Sleep(100);
				 printf("。");
				 Sleep(100);
				  printf("。");
				 Sleep(100);
				  printf("。");
				 Sleep(100);
				  printf("。");
				 Sleep(100);
				 system("cls"); 
			function_menu();
	  } 
	  else {
			printf("\n\n\t\t\t\t\t\t\t\t\t您的账号或密码错误（请确定您已注册）\n");
			printf("\t\t\t\t\t\t\t\t\t您是否要继续登录？（y/n）");
			fflush(stdin);
			ch=getchar(); 
			if(ch=='y'||ch=='Y')
			{
				login();
			}
			else
			{
				printf("\t\t\t\t\t\t\t\t\t正在返回主页");
				Sleep(300); 
				system("cls");
				menu();
			}
		}
	}

void quit()
  {
  	int k=1;
  	char ch;
  	printf("\t\t\t\t\t\t\t\t\t您确定要退出程序么？(Y/N)");
  	while(k)
{
		//为什么要放在这里 ,两个函数间的回车键哪去了 
	fflush(stdin); 
		k=0;
		scanf("%c",&ch);
		//ch=getchar();
	if(ch=='Y'||ch=='y')
	{
		system("cls");
		//以后在这里加一个退出软件的效果
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t您已成功退出，欢迎下次使用");
	
	} else if(ch=='N'||ch=='n')
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t欢迎继续使用");
		Sleep(500);
		menu(); 
	} else
	{
		printf("\t\t\t\t\t\t\t\t\t请输出N或Y"); 
		k=1;
	}
	}
  }
  //功能函数 
  void function_menu()
  {
  		int choice;
	printf("\n\n\n\n");
	printf("\t\t\t\t\t按非命令键返回上一层");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         1.书籍信息录入            |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         2.书籍信息插入            |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         3.书籍信息删除            |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         4.书籍信息修改            |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         5.书籍信息查询            |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         6.书籍信息排序            |"); 
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         7. 借阅书籍               |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         8. 退出程序               |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|___________________________________|");
    printf("\n\t\t\t\t\t\t\t\t\t\t请输入: ");
    fflush(stdin);
	scanf("%d",&choice);       
	switch(choice)
	{
		case 1:
			system("cls");
			add_book();
			printf("\n\n\t\t\t\t\t\t\t\t\t\t按任意键返回功能界面\n");
			getch(); 
			system("cls");
			function_menu();
			break;
		case 2:
			system("cls");
			insert_book();
			printf("\n\n\t\t\t\t\t\t\t\t\t\t按任意键返回功能界面\n");
			getch(); 
			system("cls");
			function_menu();
			break;
		case 3:
			system("cls");
			del_bookmenu();
			printf("\n\n\t\t\t\t\t\t\t\t\t\t按任意键返回功能界面\n");
			getch(); 
			system("cls");
			function_menu();
			break;
		case 4:
			system("cls");
			modify_book();
				printf("\n\n\t\t\t\t\t\t\t\t\t\t按任意键返回功能界面\n");
			getch(); 
			system("cls");
			function_menu();
			break;
		case 5:
			system("cls");
			broswer_book();
				printf("\n\n\t\t\t\t\t\t\t\t\t\t按任意键返回功能界面\n");
			getch(); 
			system("cls");
			function_menu();
			break;
		case 6:
			system("cls");
			sort_book();
			printf("\n\n\t\t\t\t\t\t\t\t\t\t按任意键返回功能界面\n");
			getch(); 
			system("cls");
			function_menu();
			break;
		case 7:
			system("cls");
			lend_book();
			printf("\n\n\t\t\t\t\t\t\t\t\t\t按任意键返回功能界面\n");
			getch(); 
			system("cls");
			function_menu();
			break;
		case 8:
			system("cls");
			menu();
			break; 
		default:
			fflush(stdin);
			system("cls");
			login();
				printf("\n\n\t\t\t\t\t\t\t\t\t\t按任意键返回功能界面\n");
			getch(); 
			system("cls");
			function_menu();
			break;		
	 } 

}
void add_book()//创建链表 ,所有的节点都是它创建的。除了head 
{
	book *p;
	p=(book*)malloc(sizeof(book));
	initial_book(p);
	p->next=head2->next;
	head2->next=p;
}
void initial_book(book*p) 
{
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t请输入书名："); 
	scanf("%s",p->bookname);
	//getchar();
	printf("\t\t\t\t\t\t\t\t\t\t请输入书本数量："); 
	scanf("%d",&p->num_book);
	getchar();
	printf("\t\t\t\t\t\t\t\t\t\t请输入作者："); 
	scanf("%s",p->writer);
	//getchar();
	printf("\t\t\t\t\t\t\t\t\t\t请输入编号："); 
	scanf("%d",&p->id);
	getchar();
	printf("\t\t\t\t\t\t\t\t\t\t请输入出版社："); 
	scanf("%s",p->press);
	getchar();
	printf("\t\t\t\t\t\t\t\t\t\t请输入可被借阅数："); 
	scanf("%d",&p->isjy);
	printf("\t\t\t\t\t\t\t\t\t\t请输入已被借阅数："); 
	scanf("%d",&p->notjy);
	printf("\t\t\t\t\t\t\t\t\t\t请输入出版时间："); 
	scanf("%s",p->publishtime);
	//getchar();
	printf("\t\t\t\t\t\t\t\t\t\t请输入价钱："); 
	scanf("%d",&p->price);
}
int tongji(book *head)
{
	
	book*p = head->next;
	int count=0;    
	while(p)
	{
		count++;
		p=p->next;
	}
	return count;
 } 
void insert_book()
{
	int n;
	int j=0;
	int cnt=tongji(head2);
	book *p=(book*)malloc(sizeof(book));
	book *q=head2;
	printf("\n\n\n\n");
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t请输入需要插入的位置：");
	scanf("%d",&n) ;
	if(n==1)
	{
		initial_book(p); 
		p->next=head2->next;
		head2->next=p;
		printf("\t\t\t\t\t\t\t\t\t\t添加成功！"); 
	}
	else if(n>cnt)
	{
		while(q->next)
		{
			q=q->next;
		}
		initial_book(p); 
		q->next=p;
		p->next=NULL;
		printf("\t\t\t\t\t\t\t\t\t\t添加成功！"); 
	}else 
	{
		while(q->next)
		{
			j++;
			if(j+1==cnt)
			{
				initial_book(p); 
				p->next=q->next;
				q->next=p; 
			}
			else 
			{
				q=q->next; 
			}
		}
	 } 	 
}
void broswer_book()
{
	book *p=head2->next;
	getchar();
	printf("\n\n\n");
	printf("\t\t\t\t序号\t\t名字\t\t作者\t\t数量\t\t出版社\t\t价格\t\t出版时间\t\t可借阅数\t\t已借阅数\t\t\n");
	printf("\t\t\t*****************************************************************************************************************************************************************\n");
	while(p)
	{
		printf("\t\t\t|%s\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\t\t%s\t\t%d\t\t%d\t|\n",
		p->bookname,p->writer,p->id,p->press,p->isjy,p->notjy,p->publishtime,p->price,p->num_book);
		p=p->next;
	}
	printf("\t\t\t*****************************************************************************************************************************************************************\n");
	printf("\n\n\n\n\n\t\t\t\t\t已打印出所有书籍信息\n");
}
void sort_book()//又犯了一个很典型的错误，拿指针只来指去，
//却什么都不改变 ,链表应该改的是连接 
{
	char ch; 
	int i=0;
	int cnt=tongji(head2);
	book *p;
   	p=head2->next;
	book *q=head2;
	book *d;
	book *k;
	int j;
	if(p==NULL)
	{
		printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t您尚未添加书籍。\n"); 
		return ;
	 } 
	 if(p)
	 {
	 	book *k=p->next;
	 }
	 for(i=0;i<cnt-1;i++)
	 {
	 	book *p=head2->next;
	 	book *q=head2;
	 	book *k=p->next;
	 	for(j=0;j<cnt-1-i;j++){
		if(k->id<p->id)
		{
			q->next=k;
			p->next=k->next;
			k->next=p;
			d=p;//保证k永远指向最后一个，这就是我所说的瞎用指针，只是换了指针，对内容不做出改变。 
			p=k;
			k=d;
		}
		k=k->next;
		p=p->next;
		q=q->next;
	}
	 }
	 printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t已排序完成");
	 printf("\n\t\t\t\t\t\t\t\t\t\t是否要查看？（y/n）");
	 fflush(stdin);
	 ch=getchar();
	 if(ch=='y'||ch=='Y')
	 {
	 	broswer_book();
	  } 
}
void del_bookmenu()
{
	printf("\t\t\t\t\t\t\t\t\t\t按其他键返回上一页\n");
	int a;
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n\n\n\n");
	printf("\n\n\n\n");
  	printf("\t\t\t\t\t\t\t\t\t\t1.按序号删除\n\n\n");
  	printf("\t\t\t\t\t\t\t\t\t\t2.按书名删除\n\n\n");
  	printf("\t\t\t\t\t\t\t\t\t\t3.按作者删除\n\n\n");
  	printf("\t\t\t\t\t\t\t\t\t\t4.按出版社删除\n\n\n"); 
  	printf("\t\t\t\t\t\t\t\t\t\t请输入删除方式：");
	scanf("%d",&a); 
	switch(a)
	{
    		system("cls");
		case 1:
			del_booknum(head2);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t按任意键返回功能界面\n");
			getch(); 
			system("cls");
			del_bookmenu();
			break;
		case 2:
			del_bookname(head2);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t按任意键返回功能界面\n");
			getch(); 
			system("cls");
			del_bookmenu();
			break;
		case 3:
			del_bookwriter(head2);
				printf("\n\n\t\t\t\t\t\t\t\t\t\t按任意键返回功能界面\n");
			getch(); 
			system("cls");
			del_bookmenu();
			break;
		case 4:
			del_press(head2);
				printf("\n\n\t\t\t\t\t按任意键返回功能界面\n");
			getch(); 
			system("cls");
			del_bookmenu();
			break;
		default:
			system("cls");
			function_menu();	
				
	}
}
void modify_book()
{
	int choice;
	printf("\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t\t\t\t\t\t\t\t┃ ╔════════════════════════════╗ ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃ ║             欢 迎 进 入 图 书 信 息 修 改 模 块        ║ ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃ ╚════════════════════════════╝ ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃ ***********************************************************  ┃\n"); 
		printf("\t\t\t\t\t\t\t\t\t┃ *                          *                              *  ┃\n"); 
		printf("\t\t\t\t\t\t\t\t\t┃ *       1.按图书名称修改   *      2.按图书序号修改        *  ┃\n"); 
		printf("\t\t\t\t\t\t\t\t\t┃ *                          *                              *  ┃\n");  
		printf("\t\t\t\t\t\t\t\t\t┃ ***********************************************************  ┃\n"); 
		printf("\t\t\t\t\t\t\t\t\t┃ *                     3.返回主菜单界面                    *  ┃\n");  
		printf("\t\t\t\t\t\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"); 
		printf("请输入你的选择1-3:  ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				name_mod();
				printf("\t\t\t\t\t\t\t\t\t\t按下任意键返回上一页\n");
				getch();
				system("cls");
				modify_book(); 
				break;
			case 2:
				num_mod();
				printf("\t\t\t\t\t\t\t\t\t\t按下任意键返回上一页\n");
				getch();
				system("cls");
				modify_book(); 
				break;
			default :
				printf("\t\t\t\t\t\t\t\t\t\t按下任意键返回上一页\n");
				getch();
				system("cls");
				function_menu();
				break;
		}
}
void name_mod()
{
	int choice;
	char name[20];
	printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t请输入书名:");
	scanf("%s",name);
	getchar();
	book *p=head2->next;
	while(p)
	{
		if(strcmp(p->bookname,name))
		{
			p=p->next;
		}
		else if(strcmp(p->bookname,name)==0)
		{
			printf("\n\n\n\t\t\t\t\t\t\t\t\t请输入要修改的选项：\n");
			printf("\t\t\t\t\t\t\t\t\t1.修改书名\n");
			printf("\t\t\t\t\t\t\t\t\t2.修改序号\n");
			printf("\t\t\t\t\t\t\t\t\t3.修改作者\n");
			printf("\t\t\t\t\t\t\t\t\t4.修改出版社\n");
			printf("\t\t\t\t\t\t\t\t\t5.修改出版时间\n");
			printf("\t\t\t\t\t\t\t\t\t6.修改价钱\n");
			printf("\t\t\t\t\t\t\t\t\t7.修改书的数量\n");
			printf("\t\t\t\t\t\t\t\t\t8.修改书的可借阅数\n");
			printf("\t\t\t\t\t\t\t\t\t9.修改书的已借阅数\n");
			printf("选择： "); 
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的书名: ");
					scanf("%s",p->bookname);
					printf("\t\t\t\t\t\t\t\t\t\t修改图书信息成功！\n\n");
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
					break;
				case 2:
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的序号: ");
					scanf("%d",p->id);
					printf("\t\t\t\t\t\t\t\t\t\t修改图书信息成功！\n\n");
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 3:
				    printf("\t\t\t\t\t\t\t\t\t\t请输入新的作者: ");
				    scanf("%s",p->writer);
				    printf("\t\t\t\t\t\t\t\t\t\t修改图书信息成功！\n\n");
				    printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
				    	break;
				case 4 : 
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的出版社: ");
					scanf("%s",p->press);
					printf("\t\t\t\t\t\t\t\t\t\t修改图书信息成功！\n\n");
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 5 : 
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的出版时间: ");
					scanf("%s",p->publishtime);
					printf("\t\t\t\t\t\t\t\t\t\t修改图书信息成功！\n\n");
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 6 : 
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的价钱: ");
					scanf("%d",p->price);
					printf("\t\t\t\t\t\t\t\t\t\t修改图书信息成功！\n\n");
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 7 : 
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的数量: ");
					scanf("%d",p->num_book);
					printf("\t\t\t\t\t\t\t\t\t\t修改图书信息成功！\n\n");
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
					case 8 : 
						printf("\t\t\t\t\t\t\t\t\t\t请输入新的可借阅数: ");
						scanf("%d",&p->isjy);
						printf("\t\t\t\t\t\t\t\t\t\t修改图书信息成功！\n\n");
						printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
						getchar();
						Sleep(300);
						system("cls");
						modify_book();
						break;
					case 9 : 
						printf("\t\t\t\t\t\t\t\t\t\t请输入新的已借阅数: ");
						scanf("%d",&p->notjy);
						printf("\t\t\t\t\t\t\t\t\t\t修改图书信息成功！\n\n");
						printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
						getchar();
						Sleep(300);
						system("cls");
						modify_book();
						break;
				default :
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
			
			}
		 } 
	} 
}
void num_mod()
{
	int choice;
	int num;
	printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t请输入书的序号:");
	scanf("%d",&num);
	book *p=head2->next;
	while(p)
	{
		if(p->id!=num)
		{
			p=p->next;
		}
		else if(p->id==num)
		{
			printf("\n\n\n\t\t\t\t\t\t\t\t\t请输入要修改的选项：\n");
			printf("\t\t\t\t\t\t\t\t\t1.修改书名\n");
			printf("\t\t\t\t\t\t\t\t\t2.修改序号\n");
			printf("\t\t\t\t\t\t\t\t\t3.修改作者\n");
			printf("\t\t\t\t\t\t\t\t\t4.修改出版社\n");
			printf("\t\t\t\t\t\t\t\t\t5.修改出版时间\n");
			printf("\t\t\t\t\t\t\t\t\t6.修改价钱\n");
			printf("\t\t\t\t\t\t\t\t\t7.修改书的数量\n");
			printf("\t\t\t\t\t\t\t\t\t8.修改书的可借阅数\n");
			printf("\t\t\t\t\t\t\t\t\t9.修改书的已借阅数\n");
			printf("选择： ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的书名: ");
					scanf("%s",p->bookname);
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
					break;
				case 2:
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的序号: ");
					scanf("%d",p->id);
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 3:
				    printf("\t\t\t\t\t\t\t\t\t\t请输入新的作者: ");
				    scanf("%s",p->writer);
				    printf("\t\t\t\t\t\t\t\t\t\t 按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
				    	break;
				case 4 : 
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的出版社: ");
					scanf("%s",p->press);
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 5 : 
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的出版时间: ");
					scanf("%s",p->publishtime);
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 6 : 
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的价钱: ");
					scanf("%d",p->price);
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 7 : 
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的数量: ");
					scanf("%d",p->num_book);
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 8 : 
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的可借阅数: ");
					scanf("%d",&p->isjy);
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 9 : 
					printf("\t\t\t\t\t\t\t\t\t\t请输入新的已借阅数: ");
					scanf("%d",&p->notjy);
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				default :
					printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
			
			}
		 } 
	}
	printf("\t\t\t\t\t\t\t\t\t\t修改图书信息成功！"); 
}
void del_press(book *q)
{
	int flag=1;
	char press[20];
	book *p=head2->next;
	printf("\t\t\t\t\t\t\t\t\t\t请输入书的出版社: ");
	scanf("%s",press); 
	printf("\n\n\n");
	while(p)
	{
		
		if(!strcmp(p->press,press))
		{
			
		printf("\t\t\t|\t%s  \t\t%s  \t\t%d  \t\t%s\t\t%d  \t\t%s  \t\t%d  \t\t%d\t\t|",
		p->bookname,p->writer,p->num_book,p->press,p->price,p->publishtime,p->isjy,p->notjy);
				q->next=p->next;
				p=p->next;
				flag=0;
		}
		else {
		q=p;
		p=p->next;
	}
		}
//	printf("********************************************************************************************************************\n");
printf("\t\t\t*****************************************************************************************************************************************************************\n");
	if(flag)
	{
		printf("\t\t\t\t\t\t\t\t\t\t未找到目标书籍\n\n"); 
	}
	else 
	{
		printf("\t\t\t\t\t\t\t\t\t\t已成功删除所有有关书籍\n\n"); 
	}
}
void del_bookwriter(book *q)
{
	int flag=1;
	char writer[20];
	book *p=head2->next;
	printf("\n\t\t\t\t\t\t\t\t\t\t请输入书的作者: ");
	scanf("%s",writer); 
	
	printf("\n\n\n");
	printf("\t\t\t\t名字\t\t作者\t\t数量\t\t出版社\t\t价格\t\t出版时间\t\t可借阅数\t\t已借阅数\t\t\n");
printf("\n\n\t\t**************************************************************************************************************************************************************************\n");
//printf("\t\t\t****************************************************************************************************************************\n");
	while(p)
	{
		
		if(!strcmp(p->writer,writer))
		{
				q->next=p->next;
				p=p->next;
				flag=0;
		}
		else {
		printf("\t\t\t|\t%s  \t\t%s  \t\t%d  \t\t%s\t\t%d  \t\t%s  \t\t%d  \t\t%d\t\t|",
		p->bookname,p->writer,p->num_book,p->press,p->price,p->publishtime,p->isjy,p->notjy);
			q=p;
			p=p->next;
		}
	}
printf("\n\t\t****************************************************************************************************************************************************************************\n");
//printf("\t\t\t*************************************************************************************************************************\n");
	if(flag)
	{
		printf("\t\t\t\t\t\t\t\t\t\t未找到目标书籍\n\n"); 
	}
	else 
	{
		printf("\t\t\t\t\t\t\t\t\t\t已成功删除所有有关书籍\n\n"); 
	}
	fflush(stdin);
}
void del_bookname(book *q)
{
	int flag=1;
	char name[20];
	book *p=head2->next;
	printf("\n\t\t\t\t\t\t\t\t\t\t请输入书的名称: ");
	scanf("%s",name); 
	printf("\n\n\n");
	printf("\t\t\t\t名字\t\t作者\t\t数量\t\t出版社\t\t价格\t\t出版时间\t\t可借阅数\t\t已借阅数\t\t\n");
	printf("\t\t\t*****************************************************************************************************************************************************************\n");
	//printf("\t\t\t*******************************************************************************************************************************\n");
	while(p)
	{
		
		if(!strcmp(p->bookname,name))
		{
				printf("\t\t\t|\t%s  \t\t%s  \t\t%d  \t\t%s\t\t%d  \t\t%s  \t\t%d  \t\t%d\t\t|",
		p->bookname,p->writer,p->num_book,p->press,p->price,p->publishtime,p->isjy,p->notjy);
				q->next=p->next;
				p=p->next;
				flag=0;
		}
		else {
			q=p;
			p=p->next;
		}
	}
	//printf("\t\t\t******************************************************************************************************\n");
	printf("\t\t\t*****************************************************************************************************************************************************************\n");
	if(flag)
	{
		printf("\t\t\t\t\t\t\t\t\t\t未找到目标书籍\n\n"); 
	}
	else 
	{
		printf("\t\t\t\t\t\t\t\t\t\t已成功删除所有有关书籍\n\n"); 
	}
	fflush(stdin);
}
void del_booknum(book *q)
{
		int flag=1;
	int num;
	book *p=head2->next;
	printf("\n\t\t\t\t\t\t\t\t\t\t请输入书的序号: ");
	scanf("%d",&num);
	printf("\t\t\t\t名字\t\t作者\t\t数量\t\t出版社\t\t价格\t\t出版时间\t\t可借阅数\t\t已借阅数\t\t\n");
	printf("\t\t\t*****************************************************************************************************************************************************************\n");
	while(p)
	{
		
		if(num==p->id)
		{
			
			printf("\t\t\t|\t%s  \t\t%s  \t\t%d  \t\t%s\t\t%d  \t\t%s  \t\t%d  \t\t%d\t\t|",
		p->bookname,p->writer,p->num_book,p->press,p->price,p->publishtime,p->isjy,p->notjy);
				q->next=p->next;
				p=p->next;
				flag=0;
		}
		else {
			q=p;
			p=p->next;
		}
	}
		printf("\n\t\t\t*****************************************************************************************************************************************************************\n");	
		if(flag)
	{
		printf("\t\t\t\t\t\t\t\t\t\t未找到目标书籍\n\n"); 
	}
	else 
	{
		printf("\t\t\t\t\t\t\t\t\t\t已成功删除所有有关书籍\n\n"); 
	}
	fflush(stdin);
}
void lend_book()
{
	fflush(stdin); 
	int a;
	char bookname[20];
	char writer[20];
	char press[20];
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t借阅方式：\n");
	printf("\t\t\t\t\t\t\t\t\t1.书籍名称\n ");
	printf("\t\t\t\t\t\t\t\t\t2.出版社名称\n ");
	printf("\t\t\t\t\t\t\t\t\t3.作者名称\n ");
	printf("请选择借阅方式：  ");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			system("cls");
			lend_name(head2);
				printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
				getchar();
				Sleep(300);
				system("cls");
				lend_book();						
				break;
		case 2:
			system("cls");
			lend_press(head2);
			printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
				getchar();
				Sleep(300);
				system("cls");
				lend_book();						
				break;
		case 3:
			system("cls");
			lend_writer(head2);
			printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
				getchar();
				Sleep(300);
				system("cls");
				lend_book();						
				break;
		default:
				printf("\t\t\t\t\t\t\t\t\t\t按任意键返回上一页\n");
				getchar();
				Sleep(300);
				system("cls");
				function_menu();						
				break;	 
	} 
}
void lend_name(book *p)
{
	
	char bookname[20];
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t请输入书籍名称： ");
	scanf("%s",bookname); 
	fflush(stdin);
	printf("\n\n\n");
	printf("\t\t\t\t名字\t\t作者\t\t数量\t\t出版社\t\t价格\t\t出版时间\t\t可借阅数\t\t已借阅数\t\t\n");
	//printf("\t\t\t*****************************************************************************************************************************************************************\n");
	while(p)
	{
			if(strcmp(p->bookname,bookname))
	  {
		p=p->next;
	  }
	  else 
	  {
		printf("\n");
		printf("\t\t\t*****************************************************************************************************************************************************************\n");
		printf("\t\t\t|\t%s  \t\t%s  \t\t%d  \t\t%s\t\t%d  \t\t%s  \t\t\t%d  \t\t\t%d\t\t|",
		p->bookname,p->writer,p->num_book,p->press,p->price,p->publishtime,p->isjy,p->notjy);
		printf("\n");
		printf("\t\t\t*****************************************************************************************************************************************************************\n");
		printf("\n\n\n\t\t\t\t\t是否要借阅这本书？");
	    char n;
	    scanf("%c",&n);
	    fflush(stdin);
	    if(n=='Y'||n=='y')
	{
		printf("\n\n\t\t\t\t您已成功借阅！");
		p->isjy=p->isjy-1;
		p->notjy=p->notjy+1;
	}
		p=p->next;
	}
}
	printf("\n\n按下非命令键返回上一页");
}
void lend_press(book *p)
{
		char press[20];
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t请输入出版社名称： ");
	scanf("%s",press); 
	fflush(stdin);
	printf("\n\n\n");
	printf("\t\t\t\t名字\t\t作者\t\t数量\t\t出版社\t\t价格\t\t出版时间\t\t可借阅数\t\t已借阅数\t\t\n");
	while(p)
	{
			if(strcmp(p->press,press))
	  {
		p=p->next;
	  }
	  else 
	  {
	  	printf("\t\t\t******************************************************************************************************************************************************************\n");
		printf("\n");
		printf("\t\t\t|\t%s  \t\t%s  \t\t%d  \t\t%s\t\t%d  \t\t%s  \t\t\t%d  \t\t\t%d\t\t|",
		p->bookname,p->writer,p->num_book,p->press,p->price,p->publishtime,p->isjy,p->notjy);
		printf("\t\t\t\t\t\t**************************************************************************************************************************************************************\n");
		printf("\n");
		printf("\n\n\n\t\t\t\t\t是否要借阅这本书？");
	char n;
	scanf("%c",&n);
	fflush(stdin);
	if(n=='Y'||n=='y')
	{
		printf("\n\n\t\t\t\t您已成功借阅！\n\n\n");
		p->isjy=p->isjy-1;
		p->notjy=p->notjy+1;
	}
		p=p->next;
		
	}
}
	//printf("\t\t\t*******************************************************************************************************************************************************\n");

	printf("\n\n按下非命令键返回上一页");
}
void lend_writer(book *p)
{
		char writer[20];
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t请输入作者名称： ");
	scanf("%s",writer); 
	fflush(stdin);
	printf("\n\n\n");
	printf("\t\t\t\t名字\t\t作者\t\t数量\t\t出版社\t\t价格\t\t出版时间\t\t可借阅数\t\t已借阅数\t\t\n");
	//*****************************************************************************************************************************************************\n");
	while(p)
	{
			if(strcmp(p->writer,writer))
	  {
		p=p->next;
	  }
	  else 
	  {
		printf("\n");
		printf("\t\t\t*********************************************************************************************************************************************\n");
		printf("\t\t\t|\t%s  \t\t%s  \t\t%d  \t\t%s\t\t%d  \t\t%s  \t\t\t%d  \t\t\t%d\t\t|",
		p->bookname,p->writer,p->num_book,p->press,p->price,p->publishtime,p->isjy,p->notjy);
		printf("\n");
		printf("\t\t\t*********************************************************************************************************************************************\n");
		printf("\n\n\n\t\t\t\t\t是否要借阅这本书？");
	char n;
	scanf("%c",&n);
	fflush(stdin);
	if(n=='Y'||n=='y')
	{
		printf("\n\n\t\t\t\t您已成功借阅！");
		p->isjy=p->isjy-1;
		p->notjy=p->notjy+1;
	}
		p=p->next;
	}
}
	//printf("\t\t\t***************************************************************************************************************************************************************\n");
	printf("\n\n按下非命令键返回上一页");
}
//void readfile()
//{
//	FILE *fp;
//	book *q=head2;
//	book *p=(book*)malloc(sizeof(book));
//	fp=fopen("bookdata.txt","r");
//	if(fp!=NULL) 
//	{	
//	if(fgetc(fp)!=-1)
//		{ 
//			rewind(fp);
//			while(!feof(fp))
//			{ 
//			fscanf(fp,"%s %s %d %s %d %d %s %d %d\n",
//			p->bookname,p->writer,&p->id,p->press,&p->isjy,&p->notjy,p->publishtime,&p->price,&p->num_book);
//			q->next=p;
//			q=p;
//			p=(book*)malloc(sizeof(book));	
//			}
//		}
//		}	
//	fclose(fp);
//}
void readfile()
{
	FILE *fp;
	book *q=head2;
	book *p=(book*)malloc(sizeof(book));
	fp=fopen("bookdata.txt","a+");
	if(fp!=NULL) 
	{	
	       fgetc(fp);
			while(!feof(fp))
			{ 
			rewind(fp);
			fscanf(fp,"%s %s %d %s %d %d %s %d %d\n",
			p->bookname,p->writer,&p->id,p->press,&p->isjy,&p->notjy,p->publishtime,&p->price,&p->num_book);
			q->next=p;
			q=p;
			p=(book*)malloc(sizeof(book));	
			}
		
		}	
	fclose(fp);
}
void writefile()
{
	book *p=head2->next;
	FILE *fp;
	fp=fopen("bookdata.txt","w");
	while(p->next)//不懂为什么不是p 
	{
	fprintf(fp,"%s %s %d %s %d %d %s %d %d\n",
	p->bookname,p->writer,p->id,p->press,p->isjy,p->notjy,p->publishtime,p->price,p->num_book);
	p=p->next;
	}
	fclose(fp);
}
