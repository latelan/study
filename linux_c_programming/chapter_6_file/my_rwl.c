/*************************************************************************
	> File Name: my_rwl.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-06 10:53:53
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void my_err(const char *err_string, int line)
{
	fprintf(stderr,"line:%d ",line);
	perror(err_string);
	exit(1);
}

int my_read(int fd)
{
	int len;
	int ret;
	int i;
	char read_buf[64];

	if(lseek(fd,0,SEEK_END) == -1) {
		my_err("lseek",__LINE__);
	}
	if((len = lseek(fd,0,SEEK_CUR)) == -1) {
		my_err("lseek",__LINE__);
	}
	if((lseek(fd,0,SEEK_SET)) == -1) {
		my_err("lseek",__LINE__);
	}

	printf("len:%d\n",len);
	/* 读数据 */
	if((ret = read(fd,read_buf,len)) < 0) {
		my_err("lseek",__LINE__);
	}

	/* 打印数据 */
	for(i=0; i<len; i++) {
		printf("%c",read_buf[i]);
	}
	printf("\n");

	return ret;

		
}
int main()
{
	int fd;
	char write_buf[32] = "Hello world!";

	/* 在当前目录下创建文件example.c */
	// if (( fd = creat("example.c", S_IRWXU) == -1) {
	if ((fd = open("example.c", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU)) == -1 ) {
		my_err("open",__LINE__);
	} else {
		printf("create file success\n");
	}

	/* 写数据 */
	if (write(fd,write_buf, strlen(write_buf)) != strlen(write_buf)) {
			my_err("write",__LINE__);
	}
	my_read(fd);

	/* 演示文件的间隔 */
	printf("/*---------------------*/\n");
	if(lseek(fd, 10, SEEK_END) == -1) {
		my_err("lseek",__LINE__);
	}
	if(write(fd,write_buf,strlen(write_buf)) != strlen(write_buf)) {
		my_err("write",__LINE__);
	}
	my_read(fd);

	close(fd);
	return 0;
}
