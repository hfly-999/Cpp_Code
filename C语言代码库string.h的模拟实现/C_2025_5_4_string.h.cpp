// C_2025_5_4_string.h.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//'strtok': This function or variable may be unsafe. Consider using strtok_s instead. To disable deprecation, use . See online help for details.
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
int main()
{
	char str[] = "192.168.1.1";
	char str2[] = ".";
	for (char* p = strtok(str, str2); p!=NULL; p = strtok(NULL, str2))
		printf("%s\n", p);
	return 0;
}
