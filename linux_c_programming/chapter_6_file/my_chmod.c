/*************************************************************************
	> File Name: my_chmod.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-06 08:31:22
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char ** argv)
{
	int mode;
	int mode_u;
	int mode_g;
	int mode_o;
	char *path;

	if(argc < 3){
		printf("%s < mode num> <target file>\n",argv[0]);
		exit(0);
	}

	mode = atoi(argv[1]);
	if(mode > 777 || mode < 0) {
		printf("mode num error!\n");
		exit(0);
	}

	mode_u = mode / 100;
	mode_g = mode / 10 % 10;
	mode_o = mode % 10;
	mode = (mode_u * 8 * 8) + (mode_g * 8) + mode_o;
	path = argv[2];

	if(chmod(path,mode) == -1) {
		perror("chmod error");
		exit(1);
	}

	return 0;
}
