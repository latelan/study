/*************************************************************************
	> File Name: test_umask.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-08 17:12:55
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	umask(0);
	if (creat("example_681.test",S_IRWXU | S_IRWXG |S_IRWXO) < 0) {
		perror("create");
		exit(1);
	}

	umask(S_IRWXO);
	if(creat("example_682.text",S_IRWXU | S_IRWXG | S_IRWXO) < 0) {
		perror("create");
		exit(1);
	}

	return 0;
}
