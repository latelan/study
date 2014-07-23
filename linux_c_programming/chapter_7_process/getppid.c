/*************************************************************************
	> File Name: getppid.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-07-22 10:43:24
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	printf("CurPid is %d, Parent ID is %d\n",getpid(),getppid());

	exit(0);
}
