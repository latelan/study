/*************************************************************************
	> File Name: my_signal.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-13 09:11:31
 ************************************************************************/

#include <stdio.h>
#include <signal.h>

void handler_sigint(int signo)
{
	printf("recv SIGINT\n");
}

int main()
{
	/* 安装信号处理函数 */
	signal(SIGINT, handler_sigint);

	while(1);

	return 0;
}
