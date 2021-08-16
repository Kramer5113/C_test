#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
// 利用malloc来开辟动态内存空间
int main()
{
	// 输入数值给num 以此来决定开辟大小
	int num = 0;
	scanf("%d", &num);
	int *p = (int*)malloc(num*sizeof(int));
	if (p == NULL)
	{
		// 当p为空值时 我们利用strerror的错误指令 来指出我们的错误
		printf("%s\n", strerror(errno));
	}
	else
	{
		// 赋值开辟的空间并打印
		int i = 0;
		for (i = 0; i < num; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < num; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	// 内存此时不再使用 归还OS
	free(p);
	// 同时切断p与地址关系
	p=NULL;
	return 0;
}
