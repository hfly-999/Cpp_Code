#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#include <iostream>
#define CH "~`!@#$%^&*()_+={[}]:;'\"<,>.?/\\|-/*"
#define VOC "abcdefghijklmnopqrstuvwxyz"
#define CAP "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBER "0123456789"
//¶¨Òå×Ö·û
#define CH_SIZE sizeof(CH)
#define	VOC_SIZE sizeof(VOC)
#define	CAP_SIZE sizeof(CAP)
#define NUM_SIZE sizeof(NUMBER)


#define LON 128
#define WAIT 1

using namespace std;
void print_function(char arr[LON], int sz);

