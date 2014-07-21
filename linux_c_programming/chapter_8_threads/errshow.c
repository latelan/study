/*************************************************************************
	> File Name: errshow.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-07-21 08:19:26
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

FILE * open_file(char* filename)
{
	FILE *stream;
	errno = 0;

	stream = fopen(filename,"r");
	if(stream == NULL){
		printf("can not open the file %s, reason: %s\n", filename, strerror(errno));
		exit(-1);
	} else {
		return stream;
	}
}

int main(void)
{
	char *filename = "test";

	open_file(filename);
	return 0;
}
