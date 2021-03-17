// Encode Char.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 1024

int main(int argv, char* argc[]) {
	char str[MAX_STR_LEN];
	char result[MAX_STR_LEN];

	while (1) {
		// 清理内存
		memset(str, 0, MAX_STR_LEN);
		memset(result, 0, MAX_STR_LEN);

		scanf_s("%s", str, MAX_STR_LEN);

		char* pCurr = str;
		char* pResult = result;
		while (*pCurr != '\0') {
			int code = (int)*pCurr;	// 字符的ASCII代码
			int mod;

			if (code > 64 && code < 91) {
				// 大写字母
				mod = 64;
			}
			else if (code > 96 && code < 123) {
				// 小写字母
				mod = 96;
			}
			else {
				printf_s("%s", "Illegal input.\n");
				return -1;
			}

			int diff = code % mod;					// 字符到字母表开始的偏移
			int newcode = (diff * 2 % 25) + mod;	// 偏移*2，取模以限制其范围
			*pResult = (char)newcode;				// 结果存入result[]

			++pCurr;
			++pResult;
		}

		*pResult = '\0';			// 结束result字符串
		printf_s("%s\n", result);	// 输出结果
	}

	return 0;
}