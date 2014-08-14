/*************************************************************************
	> File Name: wrong_return.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-13 10:28:06
 ************************************************************************/

#include <stdio.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf env;

void handler_sigrtmin15(int signo)
{
	printf("recv SIGRTMIN+15\n");
	longjmp(env,1);
}

void handler_sigrtmax14(int signo)
{
	printf("recv SIGRTMAX-14\n");
	longjmp(env,2);
}

int main()
{
	/* 设置返回点 */
	switch(setjmp(env)) {
		case 0:
			break;
		case 1:
			printf("return from SIGRTMIN+15\n");
			break;
		case 2:
			printf("return from SIGRTMAX-15\n");
			break;
		default:
			break;
	}
	
	/* 捕捉信号，安装信号处理函数 */
	signal(SIGRTMIN+15,handler_sigrtmin15);
	signal(SIGRTMAX-14,handler_sigrtmax14);

	while(1);

	return 0;
}
