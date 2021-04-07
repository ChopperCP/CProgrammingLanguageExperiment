// Statistics.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX 500

int comp(const void* lhs, const void* rhs) {
	// 比较函数，首先要把 void* 转化成 int* 才可以使用 < 运算符
	return *(int*)lhs - *(int*)rhs;
}

struct age_item
{
	int age;
	int cnt;
};

int main(int argc, char* argv[])
{
	int ages[MAX];
	srand(time(0));	// 以时间作为随机数种子
	for (int i = 0; i < MAX; ++i)
		ages[i] = rand() % 100;

	qsort(ages, MAX, sizeof(int), comp);	// 排序

	// 统计每个年龄的出现次数
	int prev_age = ages[0];
	int cnt = 1;
	for (int i = 1; i < MAX; ++i) {
		if (ages[i] != prev_age) {
			printf("Age %d, appearance: %d\n", prev_age, cnt);
			prev_age = ages[i];
			cnt = 0;
		}
		++cnt;
	}

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件