/*************************************************************************
	> File Name: get_cur_dir.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-12 08:47:17
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main()
{
	char *dir_name = NULL;
	dir_name = getcwd(NULL,0);
	
	if(dir_name != NULL)
	{
		printf("%s\n",dir_name);
	}
}
