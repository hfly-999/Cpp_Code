#include"function.h"
char voc[VOC_SIZE] = VOC;
char cap[CAP_SIZE] = CAP;
char ch[CH_SIZE] = CH;
char NUM[NUM_SIZE] = NUMBER;
void print_voc(char arr[LON], int i, int num, int sz)
{
	num = rand() % (VOC_SIZE - 1);
	do
	{
		if (arr[i] == voc[num])//如果找到了
		{

			for (int k = 0; k < i; k++)//打印之前的数字已经找到的数字
			{
				printf("%c", arr[k]);
			}
			for (int k = 0; k < (sz - i); k++)//打印之后的随机数
			{

				printf("%c", voc[num]);
				num = (rand() + rand()) % (VOC_SIZE - 1);
			}
			Sleep(WAIT);//停一会
			printf("\n");//打印完之后换行就行

		}
		else//如果没有找到就打印已经找到的东西，然后
		{
			for (int k = 0; k < i; k++)//打印之前的数字已经找到的数字
			{
				printf("%c", arr[k]);
			}
			for (int k = 0; k < (sz - i); k++)//打印之后的随机数
			{

				printf("%c", voc[num]);
				num = rand() % (VOC_SIZE - 1);
			}
			Sleep(WAIT);
			printf("\n");
		}
		num = rand() % (VOC_SIZE - 1);
	} while (arr[i] != voc[num]);
	
}
void print_cap(char arr[LON], int i, int num, int sz)
{
	num = rand() % (CAP_SIZE - 1);
	do
	{

		num = rand() % (CAP_SIZE - 1);
		if (arr[i] == cap[num])//如果找到了
		{

			for (int k = 0; k < i; k++)//打印之前的数字已经找到的数字
			{
				printf("%c", arr[k]);
			}
			for (int k = 0; k < (sz - i); k++)//打印之后的随机数
			{

				printf("%c", cap[num]);
				num = (rand() + rand()) % (CAP_SIZE - 1);
			}
			Sleep(WAIT);//停一会
			printf("\n");//打印完之后换行就行

		}
		else//如果没有找到就打印已经找到的东西，然后
		{
			for (int k = 0; k < i; k++)//打印之前的数字已经找到的数字
			{
				printf("%c", arr[k]);
			}
			for (int k = 0; k < (sz - i); k++)//打印之后的随机数
			{

				printf("%c", cap[num]);
				num = rand() % (CAP_SIZE - 1);
			}
			Sleep(WAIT);
			printf("\n");

		}

	} while (arr[i] != cap[num]);
}
void print_char(char arr[LON], int i, int num, int sz)
{
	num = rand() % (CH_SIZE - 1);
	do
	{
		if (arr[i] == ch[num])//如果找到了
		{

			for (int k = 0; k < i; k++)//打印之前的数字已经找到的数字
			{
				printf("%c", arr[k]);
			}
			for (int k = 0; k < (sz - i); k++)//打印之后的随机数
			{

				printf("%c", ch[num]);
				num = (rand() + rand()) % (CH_SIZE - 1);
			}
			Sleep(WAIT);//停一会
			printf("\n");//打印完之后换行就行

		}
		else//如果没有找到就打印已经找到的东西，然后
		{
			for (int k = 0; k < i; k++)//打印之前的数字已经找到的数字
			{
				printf("%c", arr[k]);
			}
			for (int k = 0; k < (sz - i); k++)//打印之后的随机数
			{

				printf("%c", ch[num]);
				num = rand() % (CH_SIZE - 1);
			}
			Sleep(WAIT);
			printf("\n");
		}
		num = rand() % (CH_SIZE - 1);
	} while (arr[i] != ch[num]);
}
void print_NUM(char arr[LON], int i, int num, int sz)
{
	num = rand() % (NUM_SIZE - 1);
	do
	{
		if (arr[i] == ch[num])//如果找到了
		{

			for (int k = 0; k < i; k++)//打印之前的数字已经找到的数字
			{
				printf("%c", arr[k]);
			}
			for (int k = 0; k < (sz - i); k++)//打印之后的随机数
			{

				printf("%c", NUM[num]);
				num = (rand() + rand()) % (NUM_SIZE - 1);
			}
			Sleep(WAIT);//停一会
			printf("\n");//打印完之后换行就行

		}
		else//如果没有找到就打印已经找到的东西，然后
		{
			for (int k = 0; k < i; k++)//打印之前的数字已经找到的数字
			{
				printf("%c", arr[k]);
			}
			for (int k = 0; k < (sz - i); k++)//打印之后的随机数
			{

				printf("%c", NUM[num]);
				num = rand() % (NUM_SIZE - 1);
			}
			Sleep(WAIT);
			printf("\n");
		}
		num = rand() % (NUM_SIZE - 1);
	} while (arr[i] != NUM[num]);
}
void print_void_line(char arr[LON], int i, int num, int sz)
{
	for (int k = 0; k < i + 1; k++)//打印之前的数字已经找到的数字，并且打印空格
	{
		printf("%c", arr[k]);
	}
	Sleep(WAIT);//停一会
	for (int k = 0; k < (sz - i - 1); k++)//打印之后的随机数
	{
		num = rand() % (VOC_SIZE - 1);
		printf("%c", voc[num]);

	}
	Sleep(WAIT);//停一会
	printf("\n");
}
void print_last(char arr[LON], int i, int num, int sz)
{
	if (i == sz)
	{
		for (int k = 0; k < i; k++)//打印之前的已经找到
		{
			printf("%c", arr[k]);
		}
		printf("\n");
	}
}
void print_function(char arr[LON], int sz)
{
	int i = 0;
	srand((unsigned)time(NULL));//给随机数种子
	int num = 0 ;
	do //正在打印第几个数
	{

	if (arr[i] <= 'z' && 'a' <= arr[i])//对于小写字母
	{
		print_voc(arr, i, num, sz);
	}
	else if(arr[i] <= 'Z' && 'A' <= arr[i])//对于大写字母
	{
		print_cap(arr, i, num, sz);
	}
	else if (arr[i] == ' ')//如果是空格
	{
		print_void_line(arr, i, num, sz);
	}
	else if (arr[i] <= '9' && '0' <= arr[i])
	{
		print_NUM(arr, i, num, sz);
	}
	else 
	{
		print_char(arr, i, num, sz);
	}
	i++;
	print_last(arr, i, num, sz);
	} while (arr[i] != '\0' && i <sz);
	
}



