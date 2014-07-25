/*************************************************************************
	> File Name: envp.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-07-24 15:03:10
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>
/* argc-参数个数，argv-参数列表，envp-环境变量*/
int main(int argc, char *argv[], char **envp)
{
	int i;
	char **p;
	printf("Argument:\n");
	for(i=0;i<argc;i++) {
		printf("argv[%d] is %s\n",i,argv[i]);
	}

	printf("Environment:\n");
	
	for(p=envp; *p != NULL; p++){
		printf("%s\n",*p);
	}


	return 0;
}
