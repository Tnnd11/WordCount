// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int CharCount(FILE* fp)
{
	int num = 0;
	while (fgetc(fp) != EOF)
	{
		num++;
	}
	return num;
}

int WordCount(FILE* fp)
{
	int num = 0;
	int flag = 0;
	char ch;

	do
	{
		ch = fgetc(fp);
	} while (ch != EOF && (ch == ' ' || ch == ','));

	if (ch != EOF)
		flag = 0;
	else
		return 0;

	while (ch != EOF)
	{
		ch = fgetc(fp);
		if (flag == 0 && (ch == ' ' || ch == ','))
		{
			num++;
			flag = 1;
		}
		else if (ch != ' ' && ch != ',')
		{
			flag = 0;
		}
	}

	if (flag == 0)
	{
		num++;
	}

	return num;
}


int main(int argc, char* argv[])
{
	FILE* fp;
	char command[3];
	char filename[15];

	scanf("%s", command);
	scanf("%s", filename);

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("无法打开该文件\n");
		exit(0);
	}
	if (strcmp(command, "-c") == 0)
	{
		printf("字符数：%d\n", CharCount(fp));
	}
	else if (strcmp(command, "-w") == 0)
	{
		printf("单词数：%d\n", WordCount(fp));
	}
	else
	{
		printf("指令错误!\n");
	}

	fclose(fp);

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
