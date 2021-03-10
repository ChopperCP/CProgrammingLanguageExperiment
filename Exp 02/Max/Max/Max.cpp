// Max.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

int comp(const void* lhs, const void* rhs) {
	// 比较函数，首先要把 void* 转化成 int* 才可以使用 < 运算符
	return *(int*)lhs < *(int*)rhs;
}

int main(int argc, char* argv[])
{
	int arr[3];
	for (int i = 0; i < 3; ++i) {
		scanf_s("%d", &arr[i]);	// 这里要加取地址符&
	}

	qsort(arr, 3, sizeof(int), comp);

	printf_s("[*]The biggese number is: %d", arr[0]);
	return 0;
}