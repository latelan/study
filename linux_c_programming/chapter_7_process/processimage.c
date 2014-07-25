/*************************************************************************
	> File Name: processimage.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-07-25 20:29:24
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[], char * environ)
{
	int i;

	printf("I am a process image!\n");
	printf("My pid = %d, parentpisd = %d\n",getpid(),getppid());
	printf("uid = %d,gid = %d\n",getuid(),getgid());

	for(i=0;i< argc;i++){
		printf("argv[%d]: %s\n",i,argv[i]);
	}
}
