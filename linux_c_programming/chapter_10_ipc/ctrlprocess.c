/*************************************************************************
	> File Name: ctrlprocess.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-16 10:21:04
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int arg, char *argv[])
{
	int n;
	char buf[1024];
	int cmpc = 0;

	while(1)
	{
		if((n = read(0,buf,1024)) > 0) {
			buf[n] = '\0';
			printf("ctrlprocess receive: %s\n",buf);

			if(!strcmp(buf,"exit")) {
				exit(0);
			}
			if(!strcmp(buf,"getpid")){
				printf("My pid: %d\n",getpid());
				sleep(3);
				exit(0);
			}
		}
	}
}
