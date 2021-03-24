// grade score.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

char if_handle(int grade) {
	if (grade >= 90)
		return 'A';
	if (grade >= 80)
		return 'B';
	if (grade >= 70)
		return 'C';
	if (grade >= 60)
		return 'D';
	return 'E';
}

char switch_handle(int grade) {
	grade /= 10;
	switch (grade)
	{
	case 10:
	case 9:
		return 'A';
	case 8:
		return 'B';
	case 7:
		return 'C';
	case 6:
		return 'D';

	default:
		return 'E';
	}
}

void exception() {
	printf_s("Invalid input!");
	exit(-1);
}

int main(int argc, char* argv[])
{
	try
	{
		int grade;
		printf_s("Please input grade: ");
		scanf_s("%d", &grade);
		if (grade > 100 or grade < 0)
			exception();
		printf_s("Your grade (if): %c\n", if_handle(grade));
		printf_s("Your grade (switch): %c\n", switch_handle(grade));
	}
	catch (const char* msg)
	{
		exception();
	}
	return 0;
}