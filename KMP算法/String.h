#pragma once
#include"Define.h"


int* InitPrecedence();

//把中缀表达式转换为后缀表达式,需要使用到
//int* InitPrecedence();
char* ExchangeLDRToLRD(char [],int sz);

//在目标串当中找子串
int BF(char target[], char son[]);

//KMP算法
int KMP(char *son,char* mon);

//KMP算法变种
int maxRepeating(char* sequence, char* word);
//计算next数组并且打印
void Clacnext(char* son);

