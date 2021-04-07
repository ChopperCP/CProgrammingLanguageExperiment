// Euler Function.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

unsigned int phi(unsigned int n)
{
	unsigned int ans = n;
	for (unsigned int i = 2; i*i <= n; i++)
		if (n%i == 0)//第一次找到的必为素因子
		{
			ans = ans - ans / i;
			while (n%i == 0) {
				n = n / i;//把该素因子全部约掉
			}
		}
	if (n > 1)
		ans = ans - ans / n;
	return ans;
}

int main(int agrc, char* argv[])
{
	unsigned int n;
	scanf_s("%u", &n);
	printf_s("%u\n", phi(n));

	return 0;
}