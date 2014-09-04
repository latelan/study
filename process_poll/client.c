/*************************************************************************
	> File Name: client.c
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-08-21 15:40:31
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 5577

int main(int argc, char *argv[]) 
{
	int sockfd;
	char send_buf[2048] = "FIRST";
	char recv_buf[2048];
	struct sockaddr_in server;
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htonl(PORT);
	bzero(&server.sin_zero,8);
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	
	if(connect(sockfd,(struct sockaddr*)&server,sizeof(server)) == -1){
		perror("connect error");
		exit(1);
	}
	while(send(sockfd,send_buf,strlen(send_buf),0) != 0) {
		int ret = recv(sockfd,recv_buf,2048,0);
		if(ret < 0) {
			break;
		}
		printf("client recv from server: %s\n",recv_buf);
		memset(send_buf,'\0',2048);
		printf("input sql_query command >>");
		fgets(send_buf,2048,stdin);
		if(strncasecmp(send_buf,"quit",4) == 0){
			printf("thanks for use !\n");
			break;
		}
		close(sockfd);
		return 0;
	}
}
