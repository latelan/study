/*************************************************************************
	> File Name: my_create.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-06 10:07:27
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int fd;

//	if ((fd = open("example_62.c",O_CREAT | O_EXCL, S_IRUSR|S_IWUSR)) == -1 ) {
	if((fd = creat("example_62.c", S_IRWXU)) == -1) {
//		perror("open");
		printf("open: %s with errno:%d\n",strerror(errno),errno);
		exit(1);
	} else {
		printf("create file success\n");
	}

	close(fd);
	return 0;
}
