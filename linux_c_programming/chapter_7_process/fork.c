/*************************************************************************
	> File Name: fork.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-07-22 10:10:47
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	printf("Process Creation Study\n");
	pid = fork();
	switch(pid){
		case 0:
			printf("Child process is running, CurPid is %d, ParentPid is %d\n", pid, getppid());
			break;
		case -1:
			printf("Process creation failed\n");
			break;
		default:
			printf("Parent process is running. ChilPid is %d, ParentPid is %d\n",pid,getpid());
			break;
	}

	exit(0);
}
