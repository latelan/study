/*************************************************************************
	> File Name: simulate_ping.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-14 09:36:06
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void send_ip()
{
	printf("send a icmp echo request packet\n");
}

void recv_ip()
{
	while(1);
}

void handler_sigalarm(int signo)
{
	send_ip();
	alarm(2);
}

int main()
{
	/* 安装信号处理程序 */
	signal(SIGALRM,handler_sigalarm);

	/* 触发一个SIGALRM信号给本进程 */
	raise(SIGALRM);
	recv_ip();

	return 0;
}

