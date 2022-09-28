#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<assert.h>

				strlen  - 计算字符串长度

  1. 计数器法  2. 递归-不用创建临时变量
3. 指针 - 指针
int my_strlen1(const char* arr) // 1. 计数器法
{
	assert(arr);
	int num = 0;
	while (*arr)//while(*arr != '\0'),前面写*arr，当*arr等于\0也不进入循环
	{
		num++;
		arr++;
	}
	return num;
}

int num = 0;
int my_strlen2(char *arr)// 2. 递归
{
	if (*arr != '\0')
	{
		num++;
		my_strlen2(++arr);
	}
	else
		return num;
}
int main()
{
	int len = strlen("abcdef");
	char arr1[] = { 'a','b','c','d','e','f' };
	char arr2[] = { "abcdef"};
	/*int len = strlen(arr);*/
	int len = my_strlen2(arr1);
	printf("%d ", len);
	if (strlen("abc") - strlen("abcdef") > 0)
	{	//      3     -           6     =    -3
		    unsigned int 3 - unsigned int 6 = -3 也是无符号数，所以输出原码的正数
		 strlen  的返回类型是size-t - 是无符号数
		  不过我们自己写的my_strlen的返回类型是int，是正常的
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}
				strcpy  - 字符串拷贝

char* my_strcpy(char* arr1,const char* arr2)
{
	assert(arr1);
	assert(arr2);
	char* ret = arr1;
	  拷贝arr2指向的字符串到arr1指向的空间，包含'\0'
	while (*arr1++ = *arr2++)	//while (*arr2 != '\0')
	{ 							//{
		;						////	tmp = *arr1;		两者等价
	}							//	*arr1 = *arr2;
									*arr2 = tmp;
									arr1++;
									arr2++;
								}
								*arr1 = *arr2;
	return ret;	// 返回目的空间的起始地址
}
int main()
{
	char arr1[] = "abcdefg";
	char arr2[] = "chb";
	char arr3[] = { 'a','b','c' };//  错误示范1 - 无'\0'
	char* arr4 = "abcde";		// 错误示范2 - 常量字符串无法使用
	char arr4[] = "a";			// 错误示范3 - 目的地空间太小，会越界访问
	strcpy(arr1, arr2);
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

				strcat  - 字符串追加

   自我实现
char* my_strcat(char* arr1, const char* arr2)
{
	assert(arr1);
	assert(arr2);
	char* ret = arr1;
	  1.自己写的
	while (*arr2 != '\0')
	{
		if (*arr1 == '\0')
		{
			*arr1 = *arr2;  //  2. 追加
			arr2++;
		}
		arr1++;	//  1. 找到目的字符串的 \0
	}
	 2.高级的
	while (*arr1 != '\0')
	{
		arr1++;		//  1. 找到目的字符串的 \0
	}
	while (*arr1++ = *arr2++)  //  2. 追加
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[30] = "hello ";
	char arr2[] = "world";
	my_strcat(arr1, arr2);
	printf("%s ", arr1);
	printf("%s ", strcat(arr1, arr2));
	return 0;
}
