#include<assert.h>
#include<stdlib.h>
//strlen
unsigned int strlen(const char* str)
{
	assert(str);
	char* p = (char*)str;
	while (*str)str++;
	return str - p;
}
//strcpy

char* strcpy(char* destination, const char* source)
{
	assert(destination&& source);
	char* ret = destination;
	while(*destination++ = *source++);
	return ret;
}
//strncpy
char* strncpy(
	char* destination,
	const char* source, 
	int num
	)
	{
		assert(destination && source);
		char* ret = destination;
		while (num--&& (*destination++ = *source++));
		while (num--)*destination = '\0';
		return ret;
	}
//strcat

char* strcat(
	char* destination,
	const char* source
	)
	{
	assert(destination && source);
	char* ret = destination;
	while (*destination)destination++;
	while (*destination++ = *source++);
	return ret;
	}


//strncat
char* strncat(
	char* destination, 
	const char* source, 
	int num
	)
{
	assert(destination && source);
	char* ret = destination;
	while (*destination)destination++;
	while (num--&&(*destination++ = *source++));
	//*destination = '\0';
	return ret;
}
//strcmp
int strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str2 == '\0')return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

//strstr
char* strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	while (true)
	{
		char* pp1 = (char*)p1;
		char* pp2 = (char*)p2;
		while (*pp1++ == *pp2++)if (!*pp2)return (char*)p1;
		if (!*pp1)return NULL;
		p1++;
	}
}

//memcpy
void* memcpy(void* destination,const void* source,unsigned long num)
{
	assert(destination && source);
	char* p1 = (char*)destination;
	char* p2 = (char*)source;
	while (num--)*p1++ = *p2++;
	return destination;
}


void* memmove_spcace(void* destination, void* source, unsigned long num)
{
	assert(destination && source);
	char* p = (char*)malloc(num*sizeof(char));
	assert(p);
	char* rubbish = p;
	char* pp = p;
	char* p1 = (char*)destination;
	char* ret = p1;
	char* p2 = (char*)source;
	int i = 0;
	while (i++ != num)*p++ = *p2++;
	i = 0;
	while (i++ != num)*p1++ = *pp++;
	free(rubbish);
	return ret;
}

//情况一dest<source
//    1 2 3 4 5 6 7 8 9
//   /1 2 3 4 5/
//		 /3 4 5 6 7/
//情况二dest>source
//    1 2 3 4 5 6 7 8 9
//		 /3 4 5 6 7/
//  / 1 2 3 4 5 /
//没问题
void* memmove_move(void* destination, void* source, unsigned long num)
{
	assert(destination && source);
	char* p1 = (char*)destination;
	char* p2 = (char*)source;
	char* ret = p1;
	if (destination > source)
		while (num--)*(p1 + num) = *(p2 + num);
	else
	{
		while (num--)*p1++ = *p2++;
		return ret;
	}
}

int memcpy(void* destination, void* source, unsigned long num)
{
	return 0;
}