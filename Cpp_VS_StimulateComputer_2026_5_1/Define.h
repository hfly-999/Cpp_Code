#pragma once
//定义了系统的位数
//定义了系统的字节大小
//定义了系统的字节
//一切以字节为单位
#include<stdio.h>
#include<stdlib.h>
#define Systembits	16//定义系统位数
#define ByteSize	8//定义字节大小为8bit


namespace DEFINE
{
	class Byte//字节类
	{
	public:
		Byte()
		{
			*((char*)this) = 0x0;
		}
		Byte(unsigned char ch) 
		{
			*((char*)this) = ch;
		}
		char ToChar()
		{
			char ret = *((char*)(this));
			return ret;
		}
		void ConferValue(unsigned char ch)
		{
			*((char*)this) = ch;
		}
		unsigned char bit0 : 1;
		unsigned char bit1 : 1;
		unsigned char bit2 : 1;
		unsigned char bit3 : 1;
		unsigned char bit4 : 1;
		unsigned char bit5 : 1;
		unsigned char bit6 : 1;
		unsigned char bit7 : 1;
	};
	class int16
	{
	public:
		int16(short int val) {
			char* p = (char*) & val;
			for (unsigned char i = 0; i < Systembits / ByteSize; i++)
				Data[i].ConferValue(p[i]);
		}
		Byte Data[2];


	};

	
	class Register//寄存器类
	{
	public:
	};
	
};
