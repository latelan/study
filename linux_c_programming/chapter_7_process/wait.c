/*************************************************************************
	> File Name: wait.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-07-26 07:48:05
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	char *msg;
	int k;
	int exit_code;

	printf("Study how to get exit code\n");
	pid = fork();
	switch(pid) {
		case 0:
			msg = "Child process is running.";
			k = 5;
			exit_code = 37;
			break;
		case -1:
			perror("Process creation failed\n");
			exit(1);
		default:
			exit_code = 0;
			sleep(4);
			break;
	}

	if(pid != 0) {
		int stat_val;
		pid_t child_pid;
		
		printf("Parent process starts waitting.\n");
		child_pid = wait(&stat_val);

		printf("Child process has exited, pid = %d\n",child_pid);
		if(WIFEXITED(stat_val))
			printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
		else
			printf("Child exited abnormally\n");
	}
	else {
		printf("Process ID is %d,parent ID is %d\n",getpid(),getppid());
		while(k-- > 0) {
			puts(msg);
			sleep(1);
		}
	}

	exit(exit_code);
}

