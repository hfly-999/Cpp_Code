#include <iostream>
#include<stdlib.h>
using namespace std;
int KMP(char* son,char* mainstring)
{
	int i=0,j=0;
	
	while(son[j])j++;//计算子串长度 
	int *PM=(int*)malloc(j*sizeof(int));//申请数组空间 
	PM[0]=0;
	int count=0;//最长前后缀 
	j=1;
	while(son[j])
	{
		if(son[j]==PM[count])
		{
			count++;//最长前后缀自增 
			PM[j]=count;
			j++;
		}
		else
		{
			if(count==0)
			
				j++;
			else 
				count=PM[count-1];//count回溯到上一个最长前后缀 
		}
	}
	j=0;
	while(mainstring[i])
	{
		if(mainstring[i]==son[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j==0)
				i++;
			else 
				j=PM[j-1];
		}
		if(son[j]=='\0')return i-j+1;//在母串当中找到了子串 
	}
	return -1;//没有找到子串 
}

int BF(char* mon,char* son)
{
	int i=0,j=0;
	while(mon[i])
	{
		if(mon[i]==son[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
		if(son[j]=='\0')return i-j+1;
	}
	return -1;
}


int main() {
	char son[]="ABAe";
	char mainstring[]="BBCABA";
	cout<<KMP(son,mainstring)<<endl;
	cout<<BF(mainstring,son);
}
