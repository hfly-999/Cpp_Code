#include"function.h"


void menu()
{
	Sleep(WAIT);//停一会
	printf("print successful!\n");
	Sleep(WAIT);//停一会
	printf("***************************\n");
	Sleep(WAIT);//停一会
	printf("<<    0.stop  1.again    >>\n");
	Sleep(WAIT);//停一会
	printf("***************************\n");
	Sleep(WAIT);//停一会
}
void print()//花式打印函数
{
	int input = 0;
	do {
		printf("please input->\n");//引导用户输入
		char arr[LON] = " ";
		cin.getline(arr, LON);//把用户存的数据存到内存里面
		Sleep(WAIT);//停一会
		int sz = strlen(arr);//计算大小
		printf("your input is ->%s\n", arr);//打印一下看看
		print_function(arr, sz);//导入函数
		menu();
		scanf_s("%d", &input);
		char VOID_LINE = getchar();
		
	} while (input);
}

int main()
{
	//建立数组，用于存储用户输入的字符串
	
	print();
	return 0;
}
