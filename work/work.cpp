/*
 *  @author:  duidui
 *  @name:    Test of Intersection & Union
 *  @time:    2020 - 03 - 07
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#define MAX_NUM 12  // 集中元素的最多数量
#define True 1
#define False 0
// #define None 99999  // 不存在的空间

struct new_set
{
	int u;  // 储存数字
	int v;  // 储存当前数字的数量
};

struct Koop
{
	int rum;  // 储存数字
};

struct set
{
	int num;  // 集中元素数量
	int list[MAX_NUM] = { 0,0,0,0,0,0,0,0,0,0,0,0 };  // 集中元素
	struct set* next;
};
/*
struct dictory
{
	int nm[53] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
				   26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52 };
	char c[53] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
				  'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
}dic;
*/
FILE* fp;

void HideCursor(int i);  // 隐藏与恢复光标

void Color(const unsigned short color);  // 颜色控制

struct set* set_init(struct set* column);  // 初始化集

void interface_init();  // 初始化界面

void menu();  // 菜单界面

void introduce();  // 介绍界面

void test_interface_init();  // 测试界面初始化

void test_environment();  // 测试

void create_set();  // 生成测试集

struct set* set_make();  // 创建或添加集

void insert_set();  // 添加测试集

void view_set();  // 查看测试集

void clean_set();  // 清空测试集

void Intersection();  // 交集测试

void Union();  // 并集测试

/************************************ 大致主体区块 ************************************/

int main(void)
{
	fp = fopen("Set_List.txt", "a");
	fclose(fp);
	menu();
}

void HideCursor(int i)  //隐藏与恢复光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, i };  //i 为 0 的时候隐藏光标，i 为 1 的时候恢复
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void Color(const unsigned short color)  //颜色控制
{   /*仅限改变0-15的颜色;如果在0-15那么实现他的颜色   因为如果超过15后面的改变的是文本背景色。*/
	if (color >= 0 && color <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
/*  颜色对应值：
　　0=黑色                8=灰色　　
	1=蓝色                9=淡蓝色                　　
　　2=绿色                10=淡绿色     　　
　　3=湖蓝色              11=淡浅绿色
　　4=红色                12=淡红色 　
　　5=紫色                13=淡紫色    　　
　　6=黄色                14=淡黄色
　　7=白色                15=亮白色
*/

struct set* set_init(struct set* column)  // 初始化集
{
	printf("\n\t\t\t\t\t   请输入你期望的集的大小：");
	scanf_s("%d", &column->num);  // 为 n 赋值
	printf("\n\n");
	printf("\t\t\t\t\t   请依次输入集中的元素组成：\n");
	printf("\t\t\t\t\t   ");
	for (int i = 0; i < column->num; i++)  // 为 r 集的每个元素赋值
		scanf_s("%d", &column->list[i]);
	printf("\n");
	return column;
}

void interface_init()  // 初始化界面
{
	HideCursor(0);
	system("cls");  // 清屏
	Color(1);
	printf("\n\n\n\n\t\t\t\tWelcome to duidui's Test --- Intersection & Union !\n\n");
	Color(7);
}

void menu()  // 菜单界面
{
	interface_init();
	printf("\n\t\t\t\t\t\t1. 创建一次测试\n\n");
	printf("\n\t\t\t\t\t\t2. 查看概览说明\n\n");
	printf("\n\t\t\t\t\t\t3. 关注我的博客\n\n");

	char hand_in = _getch();  // 用户做出选择

	if (hand_in == '1')
		test_environment();
	else if (hand_in == '2')
		introduce();
	else if (hand_in == '3')
	{
		Color(4);
		printf("\n\t\t\t\t\t\t     Welcome!\n\n");
		Color(7);
		system("start http://duitutu.cn/");
		Sleep(700);
		menu();
	}
	else
	{
		Color(4);
		printf("\n\t\t\t\t\t      输入错误！请重新输入\n\n");
		Color(7);
		Sleep(700);
		menu();
	}
	menu();
}

/************************************ 大致主体区块 ************************************/

/************************************ 信息介绍区块 ************************************/

void introduce()  // 介绍
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t  程序名称：交集与并集测试");
	printf("\n\n\t\t\t\t  开发人员：陈树雄（堆堆）");
	printf("\n\n\t\t\t\t  开发日期：2020年3月6日");
	printf("\n\n\t\t\t\t         程序用途");
	printf("\n\n\t\t\t\t  进行简单的交集与并集测试");
	printf("\n\n\t\t\t\t  并为以后的测试代码提供源码框架"); 
	Color(4);
	printf("\n\n\t\t\t\t  Copyright 2020 duidui All Rights Reserved");
	printf("\n\n\t\t\t\t  ");
	Color(2);
	system("pause");
	Color(7);
	menu();
}

/************************************ 信息介绍区块 ************************************/

/************************************ 测试代码区块 ************************************/

void test_environment()  // 测试
{
start:
	test_interface_init();
	printf("\n\t\t\t\t\t\t 1. 生成测试集\n\n");
	printf("\n\t\t\t\t\t\t 2. 查看测试集\n\n");
	printf("\n\t\t\t\t\t\t 3. 清空测试集\n\n");
	printf("\n\t\t\t\t\t\t 4. 进行交集测试\n\n");
	printf("\n\t\t\t\t\t\t 5. 进行并集测试\n\n");
	printf("\n\t\t\t\t\t\t 6. 退出本次测试\n\n");

	char hand_in = _getch();
	switch (hand_in)
	{
	case '1':
		create_set();
		break;
	case '2':
		view_set();
		break;
	case '3':
		clean_set();
		break;
	case '4':
		Intersection();
		break;
	case '5':
		Union();
		break;
	case '6':
		return;
	default:
		Color(4);
		printf("\n\t\t\t\t\t\t 输入太过奇怪！！！\n");
		Sleep(700);
		Color(7);
	}
	HideCursor(0);
	goto start;
}

void test_interface_init()  // 测试界面初始化
{
	HideCursor(0);
	system("cls");  // 清屏
	Color(10);
	printf("\n\n\n\n\t\t\t\t\t\t    The  Test\n\n");
	Color(7);
}

void create_set()  // 生成测试集（1. 的入口）
{
	test_interface_init();
	insert_set();  // 添加测试集
}

struct set* set_make()  // 获取测试集
{
	struct set* head = (struct set*)malloc(sizeof(struct set));
	struct set* p, * q;
	head->next = NULL;
	q = head;
	if ((fp = fopen("Set_List.txt", "r")) == NULL)
	{
		Color(4);
		printf("\n\t\t\t\t\t\t 打开文件失败！\n");
		Color(7);
		Sleep(700);
		exit(1);
	}
	while (!feof(fp))
	{
		p = (struct set*)malloc(sizeof(struct set));
		fscanf_s(fp, "num:%d => ", &p->num);
		for (int i = 0; i < p->num; i++)
			fscanf_s(fp, "%d ", &p->list[i]);
		fscanf_s(fp, "\n");
		p->next = NULL;
		q->next = p;
		q = p;
	}
	fclose(fp);
	return head;
}

void insert_set()  // 添加测试集
{
	HideCursor(1);
	int num;  // 集的数量
	printf("\n\t\t\t\t\t   请输入你期望创建的集的数量：");
	scanf_s("%d", &num);  // 赋值呗
	if (num == 0)
	{
		Color(4);
		printf("\n\t\t\t\t\t     你特么不创建集来这里干嘛！\n");
		Color(7);
		Sleep(700);
		return;
	}
	else if (num < 0)
	{
		Color(4);
		printf("\n\t\t\t\t\t     你想干嘛？？？？？？？？？\n");
		Color(7);
		Sleep(700);
		return;
	}
	struct set* head = set_make();  // 获取测试集头部
	struct set* p, * q;
	head->next = NULL;
	q = head;
	while (q->next != NULL)
		q = q->next;
	for (int i = 0; i < num; i++)
	{
		p = (struct set*)malloc(sizeof(struct set));
		p = set_init(p);
		p->next = NULL;
		q->next = p;
		q = p;
	}
	if ((fp = fopen("Set_List.txt", "a")) == NULL)
	{
		Color(4);
		printf("\n\t\t\t\t\t\t 打开文件失败！\n");
		Color(7);
		Sleep(700);
		exit(1);
	}
	struct set* visit = head->next;
	while (visit != NULL)
	{
		fprintf(fp, "num:%d => ", visit->num);
		for (int i = 0; i < visit->num; i++)
			fprintf(fp, "%d ", visit->list[i]);
		fprintf(fp, "\n");
		visit = visit->next;
	}
	fclose(fp);
	return;
}

void view_set()  // 查看测试集
{
	test_interface_init();
	struct set* q = (struct set*)malloc(sizeof(struct set));
	struct set* p;
	q->next = NULL;
	int rt = 0;
	if ((fp = fopen("Set_List.txt", "r")) == NULL)
	{
		Color(4);
		printf("\n\t\t\t\t\t\t 打开文件失败！\n");
		Color(7);
		Sleep(700);
		exit(1);
	}
	if(feof(fp))
	{
		Color(4);
		printf("\n\t\t\t\t\t\t 还没有数据储存哟\n");
		Color(7);
		Sleep(700);
		return;
	}
	while (!feof(fp))
	{
		p = (struct set*)malloc(sizeof(struct set));
		fscanf_s(fp, "num:%d => ", &p->num);
		for (int i = 0; i < p->num; i++)
			fscanf_s(fp, "%d ", &p->list[i]);
		fscanf_s(fp, "\n");
		printf("\n\t\t\t测试集 %d\n", ++rt);
		printf("\n\t\t\t容量：%d  =>  ", p->num);
		for (int i = 0; i < p->num; i++)
			printf("%d ", p->list[i]);
		printf("\n");
		p->next = NULL;
		q->next = p;
		q = p;
	}

	printf("\n\n\t\t\t");
	Color(4);
	system("pause");
	Color(7);
	return;
}

void clean_set()  // 清空测试集
{
	test_interface_init();
	if ((fp = fopen("Set_List.txt", "w")) == NULL)
	{
		Color(4);
		printf("\n\t\t\t\t\t\t 打开文件失败！\n");
		Color(7);
		Sleep(700);
		exit(1);
	}
	Color(3);
	printf("\n\t\t\t\t\t\t    成功清空！\n");
	Sleep(700);
	Color(7);
	return;
}

void Intersection()  // 交集测试
{
	test_interface_init();
	HideCursor(1);
	struct set* head = (struct set*)malloc(sizeof(struct set));
	struct set* p, * q;
	head->next = NULL;
	q = head;
	int rt = 0;
	if ((fp = fopen("Set_List.txt", "r")) == NULL)
	{
		Color(4);
		printf("\n\t\t\t\t\t\t 打开文件失败！\n");
		Color(7);
		Sleep(700);
		exit(1);
	}
	while (!feof(fp))
	{
		p = (struct set*)malloc(sizeof(struct set));
		fscanf_s(fp, "num:%d => ", &p->num);
		for (int i = 0; i < p->num; i++)
			fscanf_s(fp, "%d ", &p->list[i]);
		fscanf_s(fp, "\n");
		p->next = NULL;
		q->next = p;
		q = p;
	}
	fclose(fp);
	int ber;
	int x[20];
	int r;
	printf("\n\t\t\t\t\t   请输入你期望测试的集的数（两个及以上）：");
	scanf_s("%d", &ber);
	printf("\n\t\t\t\t\t   请输入你期望测试的 %d 个集：", ber);
	if (ber < 2 && ber > 0)
	{
		Color(4);
		printf("\n\t\t\t\t\t   连两个都不输入，你在想墨子？");
		Sleep(700);
		Color(7);
		return;
	}
	if (ber <= 0)
	{
		Color(4);
		printf("\n\t\t\t\t\t   你想干嘛？？？？？？？？？");
		Sleep(700);
		Color(7);
		return;
	}
	for(r = 0; r < ber; r++)
		scanf_s("%d", &x[r]);
	for (r = 0; r < ber; r++)
		if (x[r] <= 0)
		{
			Color(4);
			printf("\n\t\t\t\t\t     你想干嘛？？？？？？？？？\n");
			Color(7);
			Sleep(700);
			return;
		}
	struct new_set k[500];
	int t = 0;  // 记录数总量
	for (r = 0; r < ber; r++)
	{
		struct set* visit = head->next;
		for (int i = 1; i < x[r]; i++)
		{
			if (visit->next == NULL)
			{
				Color(4);
				printf("\n\t\t\t\t\t     大哥你是不是整错了？？？？\n");
				Color(7);
				Sleep(700);
				return;
			}
			visit = visit->next;
		}
		for (int i = 0; i < visit->num; i++)
		{
			if (t == 0)
			{
				k[0].u = visit->list[i];
				k[0].v = True;
				t++;
			}
			else
			{
				for (int j = 0; j < t; j++)  // 遍历已有数
					if (k[j].u == visit->list[i])
						break;
					else if (j == t - 1)
					{
						k[t].u = visit->list[i];
						k[t].v = True;
						t++;
						break;
					}
			}
		}
	}
	if ((fp = fopen("Intersection.txt", "a")) == NULL)
	{
		Color(4);
		printf("\n\t\t\t\t\t\t 打开文件失败！\n");
		Color(7);
		Sleep(700);
		exit(1);
	}
	printf("\n\t\t\t\t\t   参与测试的集共有 %d 个，详情如下\n\n", ber);
	for (int i = 0; i < ber; i++)
	{
		struct set* visit = head->next;
		for (int j = 1; j < x[i]; j++)
			visit = visit->next;
		printf("\t\t\t测试集： %d\n", x[i]);
		printf("\t\t\t容量：%d  =>  ", visit->num);
		for (int j = 0; j < visit->num; j++)
			printf("%d ", visit->list[j]);
		printf("\n\n");
		fprintf(fp, "join_num:%d => ", visit->num);
		for (int i = 0; i < visit->num; i++)
			fprintf(fp, "%d ", visit->list[i]);
		fprintf(fp, "\n");
	}
	printf("\n\t\t\t\t\t   测试集群并集测试生成的集如下\n\n");
	struct set* new_set = (struct set*)malloc(sizeof(struct set));
	new_set->num = t;
	printf("\t\t\t生成集容量：%d  =>  ", new_set->num);
	for (int i = 0; i < t; i++)
	{
		new_set->list[i] = k[i].u;
		printf("%d ", new_set->list[i]);
	}
	fprintf(fp, "generate_num:%d => ", new_set->num);
	for (int i = 0; i < new_set->num; i++)
		fprintf(fp, "%d ", new_set->list[i]);
	fprintf(fp, "\n\n");
	printf("\n\n\t\t\t");
	Color(3);
	printf("测试结果已保存到 Intersection.txt ！");
	Color(2);
	printf("同时，");
	Color(4);
	system("pause");
	Color(7);
	fclose(fp);
	return;
}

void Union()  // 并集测试
{
	test_interface_init();
	HideCursor(1);
	struct set* head = (struct set*)malloc(sizeof(struct set));
	struct set* p, * q;
	head->next = NULL;
	q = head;
	int rt = 0;
	if ((fp = fopen("Set_List.txt", "r")) == NULL)
	{
		Color(4);
		printf("\n\t\t\t\t\t\t 打开文件失败！\n");
		Color(7);
		Sleep(700);
		exit(1);
	}
	while (!feof(fp))
	{
		p = (struct set*)malloc(sizeof(struct set));
		fscanf_s(fp, "num:%d => ", &p->num);
		for (int i = 0; i < p->num; i++)
			fscanf_s(fp, "%d ", &p->list[i]);
		fscanf_s(fp, "\n");
		p->next = NULL;
		q->next = p;
		q = p;
	}
	fclose(fp);
	int ber;
	int x[20];
	int r;
	printf("\n\t\t\t\t\t   请输入你期望测试的集的数（两个及以上）：");
	scanf_s("%d", &ber);
	printf("\n\t\t\t\t\t   请输入你期望测试的 %d 个集：", ber);
	if (ber < 2 && ber > 0)
	{
		Color(4);
		printf("\n\t\t\t\t\t   连两个都不输入，你在想墨子？");
		Sleep(700);
		Color(7);
		return;
	}
	if (ber <= 0)
	{
		Color(4);
		printf("\n\t\t\t\t\t   你想干嘛？？？？？？？？？");
		Sleep(700);
		Color(7);
		return;
	}
	for (r = 0; r < ber; r++)
		scanf_s("%d", &x[r]);
	for (r = 0; r < ber; r++)
		if (x[r] <= 0)
		{
			Color(4);
			printf("\n\t\t\t\t\t     你想干嘛？？？？？？？？？\n");
			Color(7);
			Sleep(700);
			return;
		}
	struct new_set k[500];
	struct Koop pk[500];
	int t = 0;  // 记录数总量
	int h = 0;  // 记录真总数
	for (r = 0; r < ber; r++)
	{
		struct set* visit = head->next;
		for (int i = 1; i < x[r]; i++)
		{
			if (visit->next == NULL)
			{
				Color(4);
				printf("\n\t\t\t\t\t     大哥你是不是整错了？？？？\n");
				Color(7);
				Sleep(700);
				return;
			}
			visit = visit->next;
		}
		for (int i = 0; i < visit->num; i++)
		{
			if (t == 0)
			{
				k[0].u = visit->list[i];
				k[0].v = 1;
				t++;
			}
			else
			{
				for (int j = 0; j < t; j++)  // 遍历已有数
					if (k[j].u == visit->list[i])
					{
						if (k[j].v < ber)
						{
							k[j].v++;
							if (k[j].v == ber)
							{
								pk[h].rum = visit->list[i];
								h++;
							}
						}
						break;
					}
					else if (j == t - 1)
					{
						k[t].u = visit->list[i];
						k[t].v = 1;
						t++;
						break;
					}
			}
		}
	}
	if ((fp = fopen("Union.txt", "a")) == NULL)
	{
		Color(4);
		printf("\n\t\t\t\t\t\t 打开文件失败！\n");
		Color(7);
		Sleep(700);
		exit(1);
	}
	printf("\n\t\t\t\t\t   参与测试的集共有 %d 个，详情如下\n\n", ber);
	for (int i = 0; i < ber; i++)
	{
		struct set* visit = head->next;
		for (int j = 1; j < x[i]; j++)
			visit = visit->next;
		printf("\t\t\t测试集： %d\n", x[i]);
		printf("\t\t\t容量：%d  =>  ", visit->num);
		for (int j = 0; j < visit->num; j++)
			printf("%d ", visit->list[j]);
		printf("\n\n");
		fprintf(fp, "join_num:%d => ", visit->num);
		for (int i = 0; i < visit->num; i++)
			fprintf(fp, "%d ", visit->list[i]);
		fprintf(fp, "\n");
	}
	printf("\n\t\t\t\t\t   测试集群并集测试生成的集如下\n\n");
	struct set* new_set = (struct set*)malloc(sizeof(struct set));
	new_set->num = h;
	printf("\t\t\t生成集容量：%d  =>  ", new_set->num);
	for (int i = 0; i < h; i++)
	{
		new_set->list[i] = pk[i].rum;
		printf("%d ", new_set->list[i]);
	}
	fprintf(fp, "generate_num:%d => ", new_set->num);
	for (int i = 0; i < new_set->num; i++)
		fprintf(fp, "%d ", new_set->list[i]);
	fprintf(fp, "\n\n");
	printf("\n\n\t\t\t");
	Color(3);
	printf("测试结果已保存到 Union.txt ！");
	Color(2);
	printf("同时，");
	Color(4);
	system("pause");
	Color(7);
	fclose(fp);
	return;
}

/************************************ 测试代码区块 ************************************/