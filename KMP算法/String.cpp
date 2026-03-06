#include"String.h"


int* InitPrecedence()
{
	int* Precedence = (int*)malloc(128 * sizeof(int));
	if (Precedence == NULL)return NULL;
	else
	{
		Precedence['+'] = 1;
		Precedence['-'] = 1;
		Precedence['*'] = 2;
		Precedence['/'] = 2;
		Precedence['('] = 3;
		Precedence[')'] = 0;
	}
	return Precedence;
}

char* ExchangeLDRToLRD(char array[], int sz)
{
	int* Precedence = InitPrecedence();
	char* S = (char*)malloc(sz * sizeof(char));
	int pS = 0;
	char* ret = (char*)malloc(sz * sizeof(char));
	int pret = 0;
	for (int i = 0; i < sz-1; i++)
	{
		if (array[i] >= 'A' && array[i] <= 'Z'
			|| array[i] >= 'a' && array[i] <= 'z'
			|| array[i] >= '0' && array[i] <= '9'
			)//如果是字符或者数字
		{
			ret[pret++] = array[i];
		}
		else//如果是运算符
		{
			if (pS == 0)//如果是空栈
			{
				S[pS++] = array[i];
				cout << array[i] << " 入栈" << endl;
			}
			else//如果不是空栈
			{
				if (S[pS - 1] == '(')//直接入栈即可
				{
					S[pS++] = array[i];
					cout << array[i] << " 入栈" << endl;
				}
				else if(array[i]==')')//出栈,直到栈顶元素为'('
				{
					cout << ") 入栈" << endl;
					cout << ") 出栈" << endl;
					while (S[pS - 1] != '(')
					{
						ret[pret++] = S[--pS];
						cout << S[pS] << " 出栈" << endl;
					}
					pS--;
					cout << S[pS] << " 出栈" << endl;
				}
				else if (Precedence[array[i]]>Precedence[S[pS-1]])
				{
					S[pS++] = array[i];
					cout << array[i] << " 入栈" << endl;
				}
				else if (Precedence[array[i]] <= Precedence[S[pS - 1]])
				{
					while (
						pS!=0//栈不能为空
						&&
						S[pS - 1] != '('//栈顶元素不是'('
						&&
						Precedence[array[i]]<=Precedence[S[pS - 1]]
						//栈顶元素优先级要大>=入栈元素优先级
						)
					{
						ret[pret++] = S[--pS];
						cout << S[pS] << " 出栈" << endl;
					}
					S[pS++] = array[i];
					cout << array[i] << " 入栈" << endl;
				}

			}
			
		}
	}
	while (pS != 0)
	{
		ret[pret++] = S[--pS];
		cout << S[pS] << " 出栈" << endl;
	}
	ret[pret++] = '\0';
	return ret;
}

int BF(char target[], char son[])
{
	int pt = 0;//母串指针
	int ps = 0;//子串指针
	while (target[pt])
	{
		int p = pt;//母串指针的副本,由它来进行移动
		while (target[p] == son[ps]&&son[ps])
		{
			p++;
			ps++;
		}
		if (son[ps] == '\0')return pt+1;//返回母串的起始位置
		pt++;//母串指针自增
		ps = 0;//子串指针归零
	}
	return -1;
}


int KMP(char* son, char* mon)
{

	int i = 0;//母串指针
	int j = 0;//子串指针
	while (son[j])j++;//计算子串长度 
	//-------------------------------------------------------//
	//计算PM数组
	int* PM = (int*)malloc(j * sizeof(int));//申请数组空间 
	PM[0] = 0;//只有一个元素的数组部分匹配值必为0
	int count = 0;//最长公共前后缀长度 
	j = 1;//从子串的第二个字符开始
	while (son[j])
	{
		if (son[j] == son[count])//如果子串指针上的字符==最长公共前后缀的下一个字符
		{
			count++;//最长公共前后缀自增 
			PM[j] = count;//记录部分匹配值数组
			j++;//子串指针自增
		}
		else
		{
			if (count == 0)
			{
				PM[j] = 0;
				j++;
			}
			else
				count = PM[count - 1];//count回溯到上一个最长前后缀 
		}
	}
	//-------------------------------------------------------//
	//由PM数组计算next数组
	int* next = (int*)malloc(j * sizeof(int));//申请next数组内存空间
	next[0] = 0;
	for (int k = 1; k < j; k++)
		next[k] = PM[k - 1];//通过PM数组求next数组
	//-------------------------------------------------------//
	//修正next数组
	for (int k = 1; k < j; k++)
		if (son[k] == son[next[k]])
		{
			while (son[k] == son[next[k]] && next[k] != 0)
			{
				next[k] = next[next[k]];//直接递归到son[k]!=son[next[k]]或者next[k]==0为止
			}
		}
	//
	//查找
	j = 0;//子串指针复位 
	while (mon[i])
	{
		if (son[j] == mon[i])//子串指针内容和母串指针内容相匹配
		{
			i++;//子串指针自增
			j++;//母串指针自增
		}
		else
		{
			if (j == 0)//子串指针已经回溯到0
				i++;//母串指针自增即可
			else
				j = next[j];//子串指针基于next数组来进行回溯

		}

		if (son[j] == '\0')
			return i - j + 1;//匹配成功

	}
	return -1;//匹配失败
}

int maxRepeating(char* sequence, char* word) {
	int i = 0;
	int j = 0;
	int wordlen = 0;
	while (word[wordlen])wordlen++;
	int* PM = (int*)malloc(wordlen * sizeof(int));
	PM[0] = 0;
	j = 1;
	int count = 0;
	while (word[j])
	{
		if (word[j] == word[count])
		{
			count++;
			PM[j] = count;
			j++;
		}
		else if (count > 0)
		{
			count = PM[count - 1];
		}
		else PM[j++] = count;
	}
	j = 0;
	int k = 0;
	int ret = 0;
	while (sequence[i])
	{

		if (sequence[i] == word[j])
		{
			i++;
			j++;
		}
		else
		{
			ret = ret > k ? ret : k;
			k = 0;
			if (j > 0)
			{
				if (PM[j]-1 != 0)
				{
					i -= (PM[j]-1 + j);
					j = 0;
				}
				else
				{
					j = PM[j - 1];
				}
				
			}
			else i++;
		}

		if (word[j] == '\0')
		{
			k++;
			j = 0;
		}
		

	}
	return ret;

}


void Clacnext(char* son)
{
	int j = 0;
	while (son[j])j++;
	int *PM = (int*)malloc(j * sizeof(int));
	int *next= (int*)malloc(j * sizeof(int));
	int* nextval = (int*)malloc(j * sizeof(int));
	PM[0] = 0;
	int count = 0;
	j = 1;
	while (son[j])
	{
		if (son[j] == son[count])
		{
			count++;
			PM[j] = count;
			j++;
		}
		else
		{
			if (count == 0)
			{
				PM[j] = 0;
				j++;
			}
			else
				count = PM[count - 1];
		}
	}
	for (int i = 0; i < j; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < j; i++)
	{
		cout << son[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < j; i++)
	{
		cout << PM[i] << " ";
	}
		
	cout << endl;
	next[0] = 0;
	nextval[0] = 0;
	for (int i = 1; i < j; i++)
	{
		next[i] = PM[i - 1];
		nextval[i] = next[i];
	}
	for (int i = 0; i < j; i++)
		cout << next[i] << " ";
	cout << endl;
	for (int i = 2; i < j; i++)
	{
		if (son[i] == son[nextval[i]])//失配元素值==回溯到的元素的值
		{
			while (nextval[i])
			{
				nextval[i] = nextval[nextval[i]];
				if (son[i] != son[nextval[i]])break;
			}
		}
	}

	for (int i = 0; i < j; i++)
		cout << nextval [i] << " ";
}
