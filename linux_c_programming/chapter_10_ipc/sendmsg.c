/*************************************************************************
	> File Name: sendmsg.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-19 22:06:08
 ************************************************************************/

#include <stdlib.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUF_SIZE	256
#define PROJ_IO		32
#define PATH_NAME	"."

int main(void)
{
	/* 用户自定义消息缓冲 */
	struct mymsgbuf {
		long msgtype;
		char ctrlstring[BUF_SIZE];
	}msgbuffer;
	int qid;
	int msglen;
	key_t msgkey;

	/* 获取数据 */
	if((msgkey = ftok(PATH_NAME, PROJ_ID)) == -1)
	{
		perror("ftok error!\n");
		exit(1);
	}

	/* 创建消息队列 */
	if((qid = msgget(msgkey, IPC_CREATE | 0666)) == -1) {
		perror("msgget error!\n");
		exit(1);
	}

	/* 填充消息结构，发送到消息队列 */
	msgbuffer.msgtype = 3;
	strcpy(msgbuffer.ctrlstring, "Hello,message queue");
	msglen = sizeof(struct mymsgbuff) - 4;
	if(msgsnd(qid,&msgbuffer,msglen,0) == -1) {
		perror("msgget error!\n");
		exit(1);
	}

	exit(0);
}
