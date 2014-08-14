/*************************************************************************
	> File Name: right_return.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-13 17:08:04
 ************************************************************************/

#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>

#define ENV_UNSAVE 0
#define ENV_SAVED  1

int flag_saveenv = ENV_UNSAVE;
jmp_buf env;	// 保存待跳转位置的栈信息

/* 信号SIGRTMIN+15的处理函数 */
void handler_sigrtmin15(int signo)
{
	if(flag_saveenv == ENV_UNSAVE) {
		return;
	}

	printf("recv SIGRTMIN+15\n");
	sleep(10);
	printf("in handler_sigrtmin15, after sleep\n");
	siglongjmp(env,1);	// 返回到env值，注意第二个参数的值
}

int main()
{
	/* 设置返回点 */
	switch(sigsetjmp(env,1)) {
		case 0:
			printf("return 0\n");	// sigsetjmp的第二个参数只要非0即可
			flag_saveenv = ENV_SAVED;
			break;
		case 1:
			printf("return form SIGRTMIN+15\n");
			break;
		default:
			printf("return else\n");
			break;
	}

	/* 捕捉信号，安装信号处理函数 */
	signal(SIGRTMIN+15,handler_sigrtmin15);

	while(1);

	return 0;
}
