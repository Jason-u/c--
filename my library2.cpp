 #include<stdio.h>//ʵ��һ���鱾���࣬���֣����飬���� ,
//ɾ��ʱ��ӡ��ɾ���鼮����Ϣ�����鿴�ķ�ʽ�Ű� 
#include<windows.h>
#include<conio.h>
typedef struct The_users   //�û�������Ϣ 
{
    char id[20]; //�˺� 
    char pwd[20]; //���� 
    struct The_users *next;
}users;
typedef struct Book{
	char bookname[20];
	char writer[20];
	int id;//ͼ���� 
	char press[20];//������ 
	int isjy;
	int  notjy; 
	char publishtime[20];//����ʱ�� 
	int price;//��ļ�Ǯ 
	int num_book;
	struct Book *next;
}book; 
book *head2=(book*)malloc(sizeof(book));
//ɾ��ϵ�к��� 
void del_booknum(book *q);
void del_bookname(book *q);
void del_bookwriter(book *q);
void del_press(book *q);
void del_bookmenu();

//���ĺ���

void lend_book(); 
void lend_name(book *p);
void lend_press(book *p);
void lend_writer(book *p);

//���ܲ˵� 
void function_menu();

//�����鼮������Ŀǰ�鼮���� 
int tongji(struct song *head);

void add_book();

//�޸�ϵ�к��� 
void modify_book();
void name_mod();
void num_mod();
 
 //��д�ļ�

void writefile();
void readfile() ;

//�����ļ� 
void cre_doucument();

void menu(); 
void quit();//�˳� 
void zhuce();//ע���˺� 
void login(); //��¼ 
//������г�ʼ�� 
void initial_book(book *p);  
void insert_book();//���� 
void broswer_book();//��� 
void sort_book();//���� 
void home_book();//��� 
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
	printf("\t\t\t\t\t\t\t\t��������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t��**********************************************************��\n");
	printf("\t\t\t\t\t\t\t\t��***����������������������������������������������������***��\n");
	printf("\t\t\t\t\t\t\t\t��***��************************************************��***��\n");
	printf("\t\t\t\t\t\t\t\t��***��***                                         ****��***��\n");
	printf("\t\t\t\t\t\t\t\t��***��***         ��ӭʹ��ͼ�������Ϣϵͳ        ****��***��\n");
	printf("\t\t\t\t\t\t\t\t��***��***                                         ****��***��\n");
	printf("\t\t\t\t\t\t\t\t��***��***                                         ****��***��\n");
	printf("\t\t\t\t\t\t\t\t��***��***                 jiasen                  ****��***��\n");
	printf("\t\t\t\t\t\t\t\t��***��***                                         ****��***��\n"); 
	printf("\t\t\t\t\t\t\t\t��***��*               2019��11��20��              ****��***��\n");
	printf("\t\t\t\t\t\t\t\t��***��***                                         ****��***��\n");
	printf("\t\t\t\t\t\t\t\t��***��************************************************��***��\n");
	printf("\t\t\t\t\t\t\t\t��***����������������������������������������������������***��\n");
	printf("\t\t\t\t\t\t\t\t��**********************************************************��\n");
	printf("\t\t\t\t\t\t\t\t��������������������������������������������������������������\n");
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
	printf("\t\t\t\t\t\t\t\t\t|                1.ע��                        |\n");
	printf("\t\t\t\t\t\t\t\t\t|                                              |\n");
	printf("\t\t\t\t\t\t\t\t\t|                                              |\n");
	printf("\t\t\t\t\t\t\t\t\t|                                              |\n");
	printf("\t\t\t\t\t\t\t\t\t|                2.��½                        |\n");
	printf("\t\t\t\t\t\t\t\t\t|                                              |\n");
	printf("\t\t\t\t\t\t\t\t\t|                                              |\n");
	printf("\t\t\t\t\t\t\t\t\t|                                              |\n");
	printf("\t\t\t\t\t\t\t\t\t|                3.�˳�                        |\n");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t");
	printf("ѡ��"); 
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
			printf("\t\t\t\t\t\t\t\t\t�����1~3֮��������");
			n=1;
			scanf("%d",&cmd);	
	//getchar();
	}
	}
 }
void cre_doucument()
{
	FILE *fp;
	fp=fopen("userdata.txt","a");//��ü���һ���Ƿ�ɹ��������ļ� 
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
    users user; //������ûɶ�ã��ڸ������������Ƚϵ� 
 	printf("\t\t\t\t\t\t\t\t\t�������˺ţ� ");
	scanf("%s",admin);
	do{ 
	 k=0;
	printf("\t\t\t\t\t\t\t\t\t���������룺 ");
	while((ch=getch())!='\r'||i==0)//�������i==0Ҳ�������˷�����������ģ����������˼·��
	//��һ�������ǳ�����������������һ��������������i==0 
	{
		if(ch=='\r')//�˷�������Ҳ���е����� 
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
	printf("\n\t\t\t\t\t\t\t\t\t��������һ�����룺 ");
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
		printf("\t\t\t\t\t\t\t\t\t�������벻һ�£�����������\n"); 
		k=1;
	 }else if(strcmp(password,password2)==0)
	 {
	 printf("\n\t\t\t\t\t\t\t\t\tע��ɹ�����\n");
	fprintf(fp,"%s %s\n",admin,password);
	 } 
	 }while(k); 
	 printf("\n\t\t\t\t\t\t\t\t\t�����л�ҳ�棬���Ե�");
	 printf("��");
	 Sleep(300);
	 printf("��");
	 Sleep(300);
	 printf("��");
	 Sleep(300);
	  printf("��");
	 Sleep(300);
	  printf("��");
	 Sleep(300);
	  printf("��");
	 Sleep(300);
	 system("cls"); 
	 fclose(fp);//֮ǰ����һֱ��û��д�ر��ļ���������һ������loginһֱ�Ǵ�ģ�������ô���� 
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
		printf("\n\n\t\t\t\t\t\t\t\t\t�ļ�Ϊ�գ�����ȥע��!");
		system("cls");
		printf("\n\n\t\t\t\t\t\t\t\t\t�Ƿ�ѡ��ȥע��(Y/y)");
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
	printf("\t\t\t\t\t\t\t���¼�� "); 
	printf("\n\n\n\n");
 	printf("\t\t\t\t\t\t\t�û�����");
	scanf("%s",id); 
	printf("\t\t\t\t\t\t\t���룺");
		while((ch=getch())!='\r'||i==0)//�������i==0Ҳ�������˷�����������ģ����������˼·��
	//��һ�������ǳ�����������������һ��������������i==0 
	{
		if(ch=='\r')//�˷�������Ҳ���е����� 
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
	 	printf("  \n\n\t\t\t\t\t      ��¼�ɹ���\n");
				 printf("\n\t\t\t\t\t\t\t\t\t�����л�ҳ�棬���Ե�");
				 printf("��");
				 Sleep(100);
				 printf("��");
				 Sleep(100);
				 printf("��");
				 Sleep(100);
				  printf("��");
				 Sleep(100);
				  printf("��");
				 Sleep(100);
				  printf("��");
				 Sleep(100);
				 system("cls"); 
			function_menu();
	  } 
	  else {
			printf("\n\n\t\t\t\t\t\t\t\t\t�����˺Ż����������ȷ������ע�ᣩ\n");
			printf("\t\t\t\t\t\t\t\t\t���Ƿ�Ҫ������¼����y/n��");
			fflush(stdin);
			ch=getchar(); 
			if(ch=='y'||ch=='Y')
			{
				login();
			}
			else
			{
				printf("\t\t\t\t\t\t\t\t\t���ڷ�����ҳ");
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
  	printf("\t\t\t\t\t\t\t\t\t��ȷ��Ҫ�˳�����ô��(Y/N)");
  	while(k)
{
		//ΪʲôҪ�������� ,����������Ļس�����ȥ�� 
	fflush(stdin); 
		k=0;
		scanf("%c",&ch);
		//ch=getchar();
	if(ch=='Y'||ch=='y')
	{
		system("cls");
		//�Ժ��������һ���˳������Ч��
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t���ѳɹ��˳�����ӭ�´�ʹ��");
	
	} else if(ch=='N'||ch=='n')
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t��ӭ����ʹ��");
		Sleep(500);
		menu(); 
	} else
	{
		printf("\t\t\t\t\t\t\t\t\t�����N��Y"); 
		k=1;
	}
	}
  }
  //���ܺ��� 
  void function_menu()
  {
  		int choice;
	printf("\n\n\n\n");
	printf("\t\t\t\t\t���������������һ��");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         1.�鼮��Ϣ¼��            |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         2.�鼮��Ϣ����            |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         3.�鼮��Ϣɾ��            |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         4.�鼮��Ϣ�޸�            |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         5.�鼮��Ϣ��ѯ            |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         6.�鼮��Ϣ����            |"); 
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         7. �����鼮               |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|                                   |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|         8. �˳�����               |");
	printf("\n\t\t\t\t\t\t\t\t\t\t|___________________________________|");
    printf("\n\t\t\t\t\t\t\t\t\t\t������: ");
    fflush(stdin);
	scanf("%d",&choice);       
	switch(choice)
	{
		case 1:
			system("cls");
			add_book();
			printf("\n\n\t\t\t\t\t\t\t\t\t\t����������ع��ܽ���\n");
			getch(); 
			system("cls");
			function_menu();
			break;
		case 2:
			system("cls");
			insert_book();
			printf("\n\n\t\t\t\t\t\t\t\t\t\t����������ع��ܽ���\n");
			getch(); 
			system("cls");
			function_menu();
			break;
		case 3:
			system("cls");
			del_bookmenu();
			printf("\n\n\t\t\t\t\t\t\t\t\t\t����������ع��ܽ���\n");
			getch(); 
			system("cls");
			function_menu();
			break;
		case 4:
			system("cls");
			modify_book();
				printf("\n\n\t\t\t\t\t\t\t\t\t\t����������ع��ܽ���\n");
			getch(); 
			system("cls");
			function_menu();
			break;
		case 5:
			system("cls");
			broswer_book();
				printf("\n\n\t\t\t\t\t\t\t\t\t\t����������ع��ܽ���\n");
			getch(); 
			system("cls");
			function_menu();
			break;
		case 6:
			system("cls");
			sort_book();
			printf("\n\n\t\t\t\t\t\t\t\t\t\t����������ع��ܽ���\n");
			getch(); 
			system("cls");
			function_menu();
			break;
		case 7:
			system("cls");
			lend_book();
			printf("\n\n\t\t\t\t\t\t\t\t\t\t����������ع��ܽ���\n");
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
				printf("\n\n\t\t\t\t\t\t\t\t\t\t����������ع��ܽ���\n");
			getch(); 
			system("cls");
			function_menu();
			break;		
	 } 

}
void add_book()//�������� ,���еĽڵ㶼���������ġ�����head 
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
	printf("\t\t\t\t\t\t\t\t\t\t������������"); 
	scanf("%s",p->bookname);
	//getchar();
	printf("\t\t\t\t\t\t\t\t\t\t�������鱾������"); 
	scanf("%d",&p->num_book);
	getchar();
	printf("\t\t\t\t\t\t\t\t\t\t���������ߣ�"); 
	scanf("%s",p->writer);
	//getchar();
	printf("\t\t\t\t\t\t\t\t\t\t�������ţ�"); 
	scanf("%d",&p->id);
	getchar();
	printf("\t\t\t\t\t\t\t\t\t\t����������磺"); 
	scanf("%s",p->press);
	getchar();
	printf("\t\t\t\t\t\t\t\t\t\t������ɱ���������"); 
	scanf("%d",&p->isjy);
	printf("\t\t\t\t\t\t\t\t\t\t�������ѱ���������"); 
	scanf("%d",&p->notjy);
	printf("\t\t\t\t\t\t\t\t\t\t���������ʱ�䣺"); 
	scanf("%s",p->publishtime);
	//getchar();
	printf("\t\t\t\t\t\t\t\t\t\t�������Ǯ��"); 
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
	printf("\t\t\t\t\t\t\t\t\t\t��������Ҫ�����λ�ã�");
	scanf("%d",&n) ;
	if(n==1)
	{
		initial_book(p); 
		p->next=head2->next;
		head2->next=p;
		printf("\t\t\t\t\t\t\t\t\t\t��ӳɹ���"); 
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
		printf("\t\t\t\t\t\t\t\t\t\t��ӳɹ���"); 
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
	printf("\t\t\t\t���\t\t����\t\t����\t\t����\t\t������\t\t�۸�\t\t����ʱ��\t\t�ɽ�����\t\t�ѽ�����\t\t\n");
	printf("\t\t\t*****************************************************************************************************************************************************************\n");
	while(p)
	{
		printf("\t\t\t|%s\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\t\t%s\t\t%d\t\t%d\t|\n",
		p->bookname,p->writer,p->id,p->press,p->isjy,p->notjy,p->publishtime,p->price,p->num_book);
		p=p->next;
	}
	printf("\t\t\t*****************************************************************************************************************************************************************\n");
	printf("\n\n\n\n\n\t\t\t\t\t�Ѵ�ӡ�������鼮��Ϣ\n");
}
void sort_book()//�ַ���һ���ܵ��͵Ĵ�����ָ��ֻ��ָȥ��
//ȴʲô�����ı� ,����Ӧ�øĵ������� 
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
		printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t����δ����鼮��\n"); 
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
			d=p;//��֤k��Զָ�����һ�������������˵��Ϲ��ָ�룬ֻ�ǻ���ָ�룬�����ݲ������ı䡣 
			p=k;
			k=d;
		}
		k=k->next;
		p=p->next;
		q=q->next;
	}
	 }
	 printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t���������");
	 printf("\n\t\t\t\t\t\t\t\t\t\t�Ƿ�Ҫ�鿴����y/n��");
	 fflush(stdin);
	 ch=getchar();
	 if(ch=='y'||ch=='Y')
	 {
	 	broswer_book();
	  } 
}
void del_bookmenu()
{
	printf("\t\t\t\t\t\t\t\t\t\t��������������һҳ\n");
	int a;
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n\n\n\n");
	printf("\n\n\n\n");
  	printf("\t\t\t\t\t\t\t\t\t\t1.�����ɾ��\n\n\n");
  	printf("\t\t\t\t\t\t\t\t\t\t2.������ɾ��\n\n\n");
  	printf("\t\t\t\t\t\t\t\t\t\t3.������ɾ��\n\n\n");
  	printf("\t\t\t\t\t\t\t\t\t\t4.��������ɾ��\n\n\n"); 
  	printf("\t\t\t\t\t\t\t\t\t\t������ɾ����ʽ��");
	scanf("%d",&a); 
	switch(a)
	{
    		system("cls");
		case 1:
			del_booknum(head2);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t����������ع��ܽ���\n");
			getch(); 
			system("cls");
			del_bookmenu();
			break;
		case 2:
			del_bookname(head2);
			printf("\n\n\t\t\t\t\t\t\t\t\t\t����������ع��ܽ���\n");
			getch(); 
			system("cls");
			del_bookmenu();
			break;
		case 3:
			del_bookwriter(head2);
				printf("\n\n\t\t\t\t\t\t\t\t\t\t����������ع��ܽ���\n");
			getch(); 
			system("cls");
			del_bookmenu();
			break;
		case 4:
			del_press(head2);
				printf("\n\n\t\t\t\t\t����������ع��ܽ���\n");
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
		printf("\t\t\t\t\t\t\t\t\t������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t\t\t�� �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[ ��\n");
		printf("\t\t\t\t\t\t\t\t\t�� �U             �� ӭ �� �� ͼ �� �� Ϣ �� �� ģ ��        �U ��\n");
		printf("\t\t\t\t\t\t\t\t\t�� �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a ��\n");
		printf("\t\t\t\t\t\t\t\t\t�� ***********************************************************  ��\n"); 
		printf("\t\t\t\t\t\t\t\t\t�� *                          *                              *  ��\n"); 
		printf("\t\t\t\t\t\t\t\t\t�� *       1.��ͼ�������޸�   *      2.��ͼ������޸�        *  ��\n"); 
		printf("\t\t\t\t\t\t\t\t\t�� *                          *                              *  ��\n");  
		printf("\t\t\t\t\t\t\t\t\t�� ***********************************************************  ��\n"); 
		printf("\t\t\t\t\t\t\t\t\t�� *                     3.�������˵�����                    *  ��\n");  
		printf("\t\t\t\t\t\t\t\t\t������������������������������������������������������������������\n"); 
		printf("���������ѡ��1-3:  ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				name_mod();
				printf("\t\t\t\t\t\t\t\t\t\t���������������һҳ\n");
				getch();
				system("cls");
				modify_book(); 
				break;
			case 2:
				num_mod();
				printf("\t\t\t\t\t\t\t\t\t\t���������������һҳ\n");
				getch();
				system("cls");
				modify_book(); 
				break;
			default :
				printf("\t\t\t\t\t\t\t\t\t\t���������������һҳ\n");
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
	printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t����������:");
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
			printf("\n\n\n\t\t\t\t\t\t\t\t\t������Ҫ�޸ĵ�ѡ�\n");
			printf("\t\t\t\t\t\t\t\t\t1.�޸�����\n");
			printf("\t\t\t\t\t\t\t\t\t2.�޸����\n");
			printf("\t\t\t\t\t\t\t\t\t3.�޸�����\n");
			printf("\t\t\t\t\t\t\t\t\t4.�޸ĳ�����\n");
			printf("\t\t\t\t\t\t\t\t\t5.�޸ĳ���ʱ��\n");
			printf("\t\t\t\t\t\t\t\t\t6.�޸ļ�Ǯ\n");
			printf("\t\t\t\t\t\t\t\t\t7.�޸��������\n");
			printf("\t\t\t\t\t\t\t\t\t8.�޸���Ŀɽ�����\n");
			printf("\t\t\t\t\t\t\t\t\t9.�޸�����ѽ�����\n");
			printf("ѡ�� "); 
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					printf("\t\t\t\t\t\t\t\t\t\t�������µ�����: ");
					scanf("%s",p->bookname);
					printf("\t\t\t\t\t\t\t\t\t\t�޸�ͼ����Ϣ�ɹ���\n\n");
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
					break;
				case 2:
					printf("\t\t\t\t\t\t\t\t\t\t�������µ����: ");
					scanf("%d",p->id);
					printf("\t\t\t\t\t\t\t\t\t\t�޸�ͼ����Ϣ�ɹ���\n\n");
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 3:
				    printf("\t\t\t\t\t\t\t\t\t\t�������µ�����: ");
				    scanf("%s",p->writer);
				    printf("\t\t\t\t\t\t\t\t\t\t�޸�ͼ����Ϣ�ɹ���\n\n");
				    printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
				    	break;
				case 4 : 
					printf("\t\t\t\t\t\t\t\t\t\t�������µĳ�����: ");
					scanf("%s",p->press);
					printf("\t\t\t\t\t\t\t\t\t\t�޸�ͼ����Ϣ�ɹ���\n\n");
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 5 : 
					printf("\t\t\t\t\t\t\t\t\t\t�������µĳ���ʱ��: ");
					scanf("%s",p->publishtime);
					printf("\t\t\t\t\t\t\t\t\t\t�޸�ͼ����Ϣ�ɹ���\n\n");
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 6 : 
					printf("\t\t\t\t\t\t\t\t\t\t�������µļ�Ǯ: ");
					scanf("%d",p->price);
					printf("\t\t\t\t\t\t\t\t\t\t�޸�ͼ����Ϣ�ɹ���\n\n");
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 7 : 
					printf("\t\t\t\t\t\t\t\t\t\t�������µ�����: ");
					scanf("%d",p->num_book);
					printf("\t\t\t\t\t\t\t\t\t\t�޸�ͼ����Ϣ�ɹ���\n\n");
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
					case 8 : 
						printf("\t\t\t\t\t\t\t\t\t\t�������µĿɽ�����: ");
						scanf("%d",&p->isjy);
						printf("\t\t\t\t\t\t\t\t\t\t�޸�ͼ����Ϣ�ɹ���\n\n");
						printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
						getchar();
						Sleep(300);
						system("cls");
						modify_book();
						break;
					case 9 : 
						printf("\t\t\t\t\t\t\t\t\t\t�������µ��ѽ�����: ");
						scanf("%d",&p->notjy);
						printf("\t\t\t\t\t\t\t\t\t\t�޸�ͼ����Ϣ�ɹ���\n\n");
						printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
						getchar();
						Sleep(300);
						system("cls");
						modify_book();
						break;
				default :
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
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
	printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t������������:");
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
			printf("\n\n\n\t\t\t\t\t\t\t\t\t������Ҫ�޸ĵ�ѡ�\n");
			printf("\t\t\t\t\t\t\t\t\t1.�޸�����\n");
			printf("\t\t\t\t\t\t\t\t\t2.�޸����\n");
			printf("\t\t\t\t\t\t\t\t\t3.�޸�����\n");
			printf("\t\t\t\t\t\t\t\t\t4.�޸ĳ�����\n");
			printf("\t\t\t\t\t\t\t\t\t5.�޸ĳ���ʱ��\n");
			printf("\t\t\t\t\t\t\t\t\t6.�޸ļ�Ǯ\n");
			printf("\t\t\t\t\t\t\t\t\t7.�޸��������\n");
			printf("\t\t\t\t\t\t\t\t\t8.�޸���Ŀɽ�����\n");
			printf("\t\t\t\t\t\t\t\t\t9.�޸�����ѽ�����\n");
			printf("ѡ�� ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					printf("\t\t\t\t\t\t\t\t\t\t�������µ�����: ");
					scanf("%s",p->bookname);
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
					break;
				case 2:
					printf("\t\t\t\t\t\t\t\t\t\t�������µ����: ");
					scanf("%d",p->id);
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 3:
				    printf("\t\t\t\t\t\t\t\t\t\t�������µ�����: ");
				    scanf("%s",p->writer);
				    printf("\t\t\t\t\t\t\t\t\t\t �������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
				    	break;
				case 4 : 
					printf("\t\t\t\t\t\t\t\t\t\t�������µĳ�����: ");
					scanf("%s",p->press);
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 5 : 
					printf("\t\t\t\t\t\t\t\t\t\t�������µĳ���ʱ��: ");
					scanf("%s",p->publishtime);
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 6 : 
					printf("\t\t\t\t\t\t\t\t\t\t�������µļ�Ǯ: ");
					scanf("%d",p->price);
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 7 : 
					printf("\t\t\t\t\t\t\t\t\t\t�������µ�����: ");
					scanf("%d",p->num_book);
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 8 : 
					printf("\t\t\t\t\t\t\t\t\t\t�������µĿɽ�����: ");
					scanf("%d",&p->isjy);
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				case 9 : 
					printf("\t\t\t\t\t\t\t\t\t\t�������µ��ѽ�����: ");
					scanf("%d",&p->notjy);
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
						break;
				default :
					printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
					getchar();
					Sleep(300);
					system("cls");
					modify_book();
			
			}
		 } 
	}
	printf("\t\t\t\t\t\t\t\t\t\t�޸�ͼ����Ϣ�ɹ���"); 
}
void del_press(book *q)
{
	int flag=1;
	char press[20];
	book *p=head2->next;
	printf("\t\t\t\t\t\t\t\t\t\t��������ĳ�����: ");
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
		printf("\t\t\t\t\t\t\t\t\t\tδ�ҵ�Ŀ���鼮\n\n"); 
	}
	else 
	{
		printf("\t\t\t\t\t\t\t\t\t\t�ѳɹ�ɾ�������й��鼮\n\n"); 
	}
}
void del_bookwriter(book *q)
{
	int flag=1;
	char writer[20];
	book *p=head2->next;
	printf("\n\t\t\t\t\t\t\t\t\t\t�������������: ");
	scanf("%s",writer); 
	
	printf("\n\n\n");
	printf("\t\t\t\t����\t\t����\t\t����\t\t������\t\t�۸�\t\t����ʱ��\t\t�ɽ�����\t\t�ѽ�����\t\t\n");
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
		printf("\t\t\t\t\t\t\t\t\t\tδ�ҵ�Ŀ���鼮\n\n"); 
	}
	else 
	{
		printf("\t\t\t\t\t\t\t\t\t\t�ѳɹ�ɾ�������й��鼮\n\n"); 
	}
	fflush(stdin);
}
void del_bookname(book *q)
{
	int flag=1;
	char name[20];
	book *p=head2->next;
	printf("\n\t\t\t\t\t\t\t\t\t\t�������������: ");
	scanf("%s",name); 
	printf("\n\n\n");
	printf("\t\t\t\t����\t\t����\t\t����\t\t������\t\t�۸�\t\t����ʱ��\t\t�ɽ�����\t\t�ѽ�����\t\t\n");
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
		printf("\t\t\t\t\t\t\t\t\t\tδ�ҵ�Ŀ���鼮\n\n"); 
	}
	else 
	{
		printf("\t\t\t\t\t\t\t\t\t\t�ѳɹ�ɾ�������й��鼮\n\n"); 
	}
	fflush(stdin);
}
void del_booknum(book *q)
{
		int flag=1;
	int num;
	book *p=head2->next;
	printf("\n\t\t\t\t\t\t\t\t\t\t������������: ");
	scanf("%d",&num);
	printf("\t\t\t\t����\t\t����\t\t����\t\t������\t\t�۸�\t\t����ʱ��\t\t�ɽ�����\t\t�ѽ�����\t\t\n");
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
		printf("\t\t\t\t\t\t\t\t\t\tδ�ҵ�Ŀ���鼮\n\n"); 
	}
	else 
	{
		printf("\t\t\t\t\t\t\t\t\t\t�ѳɹ�ɾ�������й��鼮\n\n"); 
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
	printf("\t\t\t\t\t\t\t\t\t���ķ�ʽ��\n");
	printf("\t\t\t\t\t\t\t\t\t1.�鼮����\n ");
	printf("\t\t\t\t\t\t\t\t\t2.����������\n ");
	printf("\t\t\t\t\t\t\t\t\t3.��������\n ");
	printf("��ѡ����ķ�ʽ��  ");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			system("cls");
			lend_name(head2);
				printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
				getchar();
				Sleep(300);
				system("cls");
				lend_book();						
				break;
		case 2:
			system("cls");
			lend_press(head2);
			printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
				getchar();
				Sleep(300);
				system("cls");
				lend_book();						
				break;
		case 3:
			system("cls");
			lend_writer(head2);
			printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
				getchar();
				Sleep(300);
				system("cls");
				lend_book();						
				break;
		default:
				printf("\t\t\t\t\t\t\t\t\t\t�������������һҳ\n");
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
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t�������鼮���ƣ� ");
	scanf("%s",bookname); 
	fflush(stdin);
	printf("\n\n\n");
	printf("\t\t\t\t����\t\t����\t\t����\t\t������\t\t�۸�\t\t����ʱ��\t\t�ɽ�����\t\t�ѽ�����\t\t\n");
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
		printf("\n\n\n\t\t\t\t\t�Ƿ�Ҫ�����Ȿ�飿");
	    char n;
	    scanf("%c",&n);
	    fflush(stdin);
	    if(n=='Y'||n=='y')
	{
		printf("\n\n\t\t\t\t���ѳɹ����ģ�");
		p->isjy=p->isjy-1;
		p->notjy=p->notjy+1;
	}
		p=p->next;
	}
}
	printf("\n\n���·������������һҳ");
}
void lend_press(book *p)
{
		char press[20];
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t��������������ƣ� ");
	scanf("%s",press); 
	fflush(stdin);
	printf("\n\n\n");
	printf("\t\t\t\t����\t\t����\t\t����\t\t������\t\t�۸�\t\t����ʱ��\t\t�ɽ�����\t\t�ѽ�����\t\t\n");
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
		printf("\n\n\n\t\t\t\t\t�Ƿ�Ҫ�����Ȿ�飿");
	char n;
	scanf("%c",&n);
	fflush(stdin);
	if(n=='Y'||n=='y')
	{
		printf("\n\n\t\t\t\t���ѳɹ����ģ�\n\n\n");
		p->isjy=p->isjy-1;
		p->notjy=p->notjy+1;
	}
		p=p->next;
		
	}
}
	//printf("\t\t\t*******************************************************************************************************************************************************\n");

	printf("\n\n���·������������һҳ");
}
void lend_writer(book *p)
{
		char writer[20];
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t�������������ƣ� ");
	scanf("%s",writer); 
	fflush(stdin);
	printf("\n\n\n");
	printf("\t\t\t\t����\t\t����\t\t����\t\t������\t\t�۸�\t\t����ʱ��\t\t�ɽ�����\t\t�ѽ�����\t\t\n");
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
		printf("\n\n\n\t\t\t\t\t�Ƿ�Ҫ�����Ȿ�飿");
	char n;
	scanf("%c",&n);
	fflush(stdin);
	if(n=='Y'||n=='y')
	{
		printf("\n\n\t\t\t\t���ѳɹ����ģ�");
		p->isjy=p->isjy-1;
		p->notjy=p->notjy+1;
	}
		p=p->next;
	}
}
	//printf("\t\t\t***************************************************************************************************************************************************************\n");
	printf("\n\n���·������������һҳ");
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
	while(p->next)//����Ϊʲô����p 
	{
	fprintf(fp,"%s %s %d %s %d %d %s %d %d\n",
	p->bookname,p->writer,p->id,p->press,p->isjy,p->notjy,p->publishtime,p->price,p->num_book);
	p=p->next;
	}
	fclose(fp);
}
