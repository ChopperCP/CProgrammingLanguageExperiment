// Personal information.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
	char name[1024], gender;
	unsigned int age;
	double height, weight, BMI;

	printf_s("%s", "INPUT:\n");
	printf_s("%s", "----------------------------------\n");
	printf_s("%s", "姓名: ");
	scanf_s("%s", name, 1024);
	printf_s("%s", "性别: ");
	scanf_s(" %c", &gender, 1);
	printf_s("%s", "年龄: ");
	scanf_s("%u", &age);
	printf_s("%s", "身高: ");
	scanf_s("%lf", &height);
	printf_s("%s", "体重: ");
	scanf_s("%lf", &weight);

	BMI = weight / (height*height);

	printf_s("%s", "\n\nOUTPUT:\n");
	printf_s("%s", "----------------------------------\n");
	printf_s("姓名: %s\n", name);
	printf_s("性别: %d\n", gender);
	printf_s("年龄: %6d\n", age);
	printf_s("身高: %17.1lf\n", height);
	printf_s("体重: %-.2g\n", weight);
	printf_s("BMI: %f\n", BMI);

	return 0;
}