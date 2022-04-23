#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
struct Audience//定义一个观众结构体
{
	int code;
	char name[50];
	int num;
};
void menu();
void choice();
//输入：录入观众信息
void input(Audience s[], int n);
//新建文件：创建存储数据的文件
void createFile(FILE *fp);
//存储：将录入的观众信息存入文件中
void output(Audience s[], int n);
void save(Audience s[], int n, FILE *fp);
//读取文件数据：读取文件中的数据在显示台输出
const int N = 9;
int main()
{
	menu();
	choice();
	return 0;
}
void menu() {
	printf("*******************  幸运观众抽取系统  *****************\n\n\n");
	printf("***********1.输入观众信息         2.显示观众信息********\n");
	printf("***********3.随机抽取lucky boy    4.退出系统************\n\n");
	printf("***********         5.清空屏幕            ************\n");
	printf("*******************************************************\n\n");
}
void choice() {
	Audience str[N];
	int t=0;
	A:printf("请输入选项：");
	scanf("%d", &t);
	switch (t)
	{
	case 1:{
		FILE *fp = fopen("file05.txt", "w");
		printf("观众信息录入：编号 姓名  手机号\n");
		input(str, N);
		if (!fp)
		{
			printf("file open faile!");
			exit(0);
		}
		fprintf(fp, "%s      %s      %s\n", "编号", "姓名", "手机号");
		for (int i = 0;i <= N;i++)
		{
			fprintf(fp, "%d         %s         %d\n", str[i].code, str[i].name, str[i].num);
		}
		fclose(fp);
		Sleep(2000);
		system("cls");
		menu();
		}break;
	case 2: {
		FILE *file = fopen("file05.txt", "rt");
		if (!file)
			printf("无客户信息");
		else {
			int p = 0;
			char line[50] = { 0 };
			while (1) {
				if (NULL != (fgets(line, sizeof(line), file))) {
					printf("%s\n", line);
					p++;
					if (p == 10)
						break;
				}
			}
			fclose(file);
			goto A;
		}
	}break;
	case 3: {
		srand((unsigned)time(NULL));
		int i, j, k;
		do
		{
			i = rand() % 9;
			j = rand() % 9;
			k = rand() % 9;
		} while (i == j || i == k || j == k);
		printf("Lucky boy:\n");
		printf("%d %s %d\n", str[i].code, str[i].name, str[i].num);
		printf("%d %s %d\n", str[j].code, str[j].name, str[j].num);
		printf("%d %s %d\n", str[k].code, str[k].name, str[k].num);
	    }break;
	case 4:goto B;
	case 5: {system("cls");menu();}break;
	default:
		break;
	}
	goto A;
    B:return;
}

void input(Audience s[], int n)
{
	for (int i = 0;i <= n;i++)
	{
		printf("请输入第%d个观众的信息\n", i + 1);
		scanf("%d %s %d", &s[i].code,&s[i].name, &s[i].num);
	}
}

void createFile(FILE *fp)
{
	
}
void save(Audience s[], int n, FILE *fp)
{
	fp = fopen("file05.txt", "a");
	if (!fp)
	{
		printf("file open faile!");
		exit(0);
	}
	
	fclose(fp);
}
