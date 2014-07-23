/*************************************************************************
	> File Name: fork_orphan.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-07-22 11:41:16
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	
	pid = fork();
	switch(pid){
		case 0:
			while(1) {
				printf("A backgroud process, PID: %d,ParentID:%d\n",getpid(), getppid());
				sleep(3);
			}
		case -1:
			perror("Process creation failed\n");
			exit(-1);
		default:
			printf("I am parent process. my pid is %d\n",getpid());
			exit(0);
	}

	return 0;
}
