/*************************************************************************
	> File Name: diffork.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-07-22 11:59:56
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int globVar = 5;

int main(void)
{
	pid_t pid;
	int var,i;
	var = 1;

	printf("fork is different with vfork \n");

//	pid = fork();
	 pid =vfork();
	switch(pid) {
		case 0:
			i = 3;
			while(i-- > 0)
			{
				printf("Child process is running\n");
				globVar++;
				var++;
				sleep(1);
			}

			printf("Child's globVar = %d, var = %d\n",globVar,var);
			break;
		case -1:
			perror("Process creation failed\n");
			exit(0);
		default:
			i = 5;

			while(i-- > 0)
			{
				printf("Parent process is running\n");
				globVar++;
				var++;
				sleep(1);
			}
			printf("Parent's globVar = %d, var = %d\n", globVar,var);
			exit(0);
	}
}

