/*************************************************************************
	> File Name: studyuid.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-07-26 08:23:26
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

extern int errno;

int main()
{
	int fd;

	printf("uid study:\n");
	printf("Process's uid = %d,euid = %d\n",getuid(),geteuid());

	// strerror 函数获取指定错误码的提示信息
	if( fd = open("test.c",O_RDWR) == -1) {
		printf("Open failure,errno is %d: %s\n",errno,strerror(errno));
		exit(1);
	}
	else {
		printf("Open successfully!\n");
	}

	close(fd);
	exit(0);
}
