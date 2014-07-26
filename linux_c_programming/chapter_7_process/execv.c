/*************************************************************************
	> File Name: execv.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-07-24 16:18:35
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>


int main(void)
{
	char *argv[] = {"touch","a.txt",NULL};
	char *path = "/bin/touch";

	execv(path,argv);

	return 0;
}
