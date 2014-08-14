/*************************************************************************
	> File Name: my_kill.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-14 09:12:28
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	int i,j;
	int signum = SIGTERM;
	pid_t pid;

	if(argc !=2 && argc != 4) {
		printf("Usage: ./my_kill <-s signum> [PID]\n");
		exit(0);
	}

	for(i=1; i<argc; i++) {
		if(!strcmp(argv[i],"-s")) {
			signum = atoi(argv[i+1]);
			break;
		}
	}

	if(argc == 2) {
		pid = atoi(argv[1]);
	} else {
		for(j=1; j<argc; j++) {
			if(j!=i && j!= i+1) {
				pid = atoi(argv[j]);
				break;
			}
		}
	}

	if(kill(pid,signum) < 0 ) {
		perror("kill");
		exit(1);
	}

	return 0;
} 
