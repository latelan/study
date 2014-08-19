/*************************************************************************
	> File Name: ftok.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-19 21:41:58
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>

int main(void)
{
	int i;
	for(i=1;i<=5;i++) {
		printf("key[%d] = %ul\n",i,ftok(".",i));
	}
}
