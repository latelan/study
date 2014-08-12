/*************************************************************************
	> File Name: my_mv.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-12 08:06:26
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int  argc, char **argv)
{
	/* 检查参数个数 */
	if(argc < 3){
		printf("my_mv <old file> <new file>\n");
		exit(0);
	}

	if(rename(argv[1],argv[2]) < 0) {
		perror("rename");
		exit(1);
	}

	return 0;
}
