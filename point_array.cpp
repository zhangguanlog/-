#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

// 数组指针作为函数参数
int print_shuzuzhizhen_test(char (*arr)[10], int row, int col)
{
	int i;
	int j;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%2d ", (*arr)[j]);
		}
		printf("\n");
		arr++;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	char *num[10]; // 指针数组
	char (*ptr)[10]; // 数组指针
	// 二维数组
	char arr[5][10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
					   10, 11, 12, 13, 14, 15, 16, 17, 18 ,19,
					   20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
					   30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
					   40, 41, 42, 43, 44, 45, 46, 47, 48, 49
					  };
	int i = 0;
	int j = 0;

	// 指针
	char *ptr_one;

	// 二位数组的头地址赋值给普通指针
	ptr_one = &arr[0][0];

	// 数组指针指向二维数组
	ptr = arr;

	// 指针数组中的前3个指针分配空间
	for (i = 0; i < 3; i++)
	{
		num[i] = (char *)malloc(10 * sizeof(char));
	}

	// 赋值
	memcpy(num[0], "zhangg", 6);
	memcpy(num[1], "lisi", 4);
	memcpy(num[2], "longwu", 6);

	// 打印核对赋值是否正确
	for (i = 0; i < 3; i++)
	{
		printf("*num[%d]:%s \n", i, num[i]);
	}

	// 打印二维数组
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%2d ", arr[i][j]);	
		}
		printf("\n");
	}

	printf("\n");

	// 用数组指针的方式打印二维数据
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%2d ", (*ptr)[j]);
		}
		ptr++;
		printf("\n");	
	}

	printf("\n");

	// 用普通指针的方式打印二维数组
	for (i = 0; i < 50; i++)
	{
		printf("%2d ", *ptr_one);
		ptr_one++;
		if ((i + 1) % 10 == 0 && i != 0)
		{
			printf("\n");
		}
	}

	printf("\n");

	// 数组指针作为函数参数
	print_shuzuzhizhen_test(arr, 5, 10);

	return 0;
}




