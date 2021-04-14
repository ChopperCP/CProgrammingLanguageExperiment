// Function Graph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 62*236

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define X_ABS_RANGE 15	// X的绝对值范围
#define Y_ABS_RANGE 15	// Y的绝对值范围
#define ORIGIN_X X_ABS_RANGE	// 画布中原点的X坐标
#define ORIGIN_Y Y_ABS_RANGE	// 画布中原点的Y坐标
#define SCREEN_ROW_CNT 45
#define SCREEN_COL_CNT 145

int get_y(int a, int b, int x) {
	return a * x + b / x;
}

int main(int argc, char* argv[])
{
	char str[20];
	scanf_s("%s", str, 20);

	char a_str[20], b_str[20];
	int a = 0, b = 0;

	// 提取a，b
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == 'x' and a == 0) {
			int c = 0;
			for (; c < i; ++c)
				a_str[c] = str[c];
			a_str[c] == '\0';	// 添加字符串结尾
			a = atoi(a_str);
		}
		if (str[i] == '+') {
			int c = i + 1;
			for (; str[c] != '/'; ++c)
				b_str[c - i - 1] = str[c];
			b_str[c] == '\0';	// 添加字符串结尾
			b = atoi(b_str);
			break;
		}
	}

	char canvas[X_ABS_RANGE * 2 + 5][Y_ABS_RANGE * 2 + 5];
	memset(canvas, ' ', (X_ABS_RANGE * 2 + 5)*(Y_ABS_RANGE * 2 + 5));	// 清空画布

	//描点
	for (int x = -X_ABS_RANGE; x <= X_ABS_RANGE; ++x) {
		if (x == 0) {
			// 画出x趋近无穷
			int last_y_abs = abs(get_y(a, b, -1));
			for (int y = -Y_ABS_RANGE; y <= Y_ABS_RANGE; ++y) {
				if (abs(y) > last_y_abs) {
					canvas[ORIGIN_X + x][ORIGIN_Y + y] = '*';
				}
			}
			continue;
		}

		int y = get_y(a, b, x);
		canvas[ORIGIN_X + x][ORIGIN_Y + y] = '*';
	}

	// 输出画面
	for (int y = SCREEN_ROW_CNT / 2; y >= -SCREEN_ROW_CNT / 2; --y) {
		for (int x = -SCREEN_COL_CNT / 2; x <= SCREEN_COL_CNT / 2; ++x) {
			if (y <= Y_ABS_RANGE && y >= -Y_ABS_RANGE && x >= -X_ABS_RANGE && x <= X_ABS_RANGE) {
				// 在画布内才画
				printf_s("%c", canvas[x + ORIGIN_X][y + ORIGIN_Y]);
			}
			else {
				// 不在就填充空格即可
				printf_s("%c", ' ');
			}
		}
		printf_s("%s", "\n");
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