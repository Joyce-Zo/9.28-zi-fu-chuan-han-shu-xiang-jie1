#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<assert.h>

				strlen  - �����ַ�������

  1. ��������  2. �ݹ�-���ô�����ʱ����
3. ָ�� - ָ��
int my_strlen1(const char* arr) // 1. ��������
{
	assert(arr);
	int num = 0;
	while (*arr)//while(*arr != '\0'),ǰ��д*arr����*arr����\0Ҳ������ѭ��
	{
		num++;
		arr++;
	}
	return num;
}

int num = 0;
int my_strlen2(char *arr)// 2. �ݹ�
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
		    unsigned int 3 - unsigned int 6 = -3 Ҳ���޷��������������ԭ�������
		 strlen  �ķ���������size-t - ���޷�����
		  ���������Լ�д��my_strlen�ķ���������int����������
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}
				strcpy  - �ַ�������

char* my_strcpy(char* arr1,const char* arr2)
{
	assert(arr1);
	assert(arr2);
	char* ret = arr1;
	  ����arr2ָ����ַ�����arr1ָ��Ŀռ䣬����'\0'
	while (*arr1++ = *arr2++)	//while (*arr2 != '\0')
	{ 							//{
		;						////	tmp = *arr1;		���ߵȼ�
	}							//	*arr1 = *arr2;
									*arr2 = tmp;
									arr1++;
									arr2++;
								}
								*arr1 = *arr2;
	return ret;	// ����Ŀ�Ŀռ����ʼ��ַ
}
int main()
{
	char arr1[] = "abcdefg";
	char arr2[] = "chb";
	char arr3[] = { 'a','b','c' };//  ����ʾ��1 - ��'\0'
	char* arr4 = "abcde";		// ����ʾ��2 - �����ַ����޷�ʹ��
	char arr4[] = "a";			// ����ʾ��3 - Ŀ�ĵؿռ�̫С����Խ�����
	strcpy(arr1, arr2);
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

				strcat  - �ַ���׷��

   ����ʵ��
char* my_strcat(char* arr1, const char* arr2)
{
	assert(arr1);
	assert(arr2);
	char* ret = arr1;
	  1.�Լ�д��
	while (*arr2 != '\0')
	{
		if (*arr1 == '\0')
		{
			*arr1 = *arr2;  //  2. ׷��
			arr2++;
		}
		arr1++;	//  1. �ҵ�Ŀ���ַ����� \0
	}
	 2.�߼���
	while (*arr1 != '\0')
	{
		arr1++;		//  1. �ҵ�Ŀ���ַ����� \0
	}
	while (*arr1++ = *arr2++)  //  2. ׷��
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
