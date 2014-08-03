/*************************************************************************
	> File Name: fork3.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-03 15:41:03
 ************************************************************************/

#include <stdio.h>

int main()
{
	int i=0;
	for(i=0;i<2;i++)
	{
		fork();
		printf("A %d",getpid());
	}
}

