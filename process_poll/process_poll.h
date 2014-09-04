/*************************************************************************
  > File Name: process_pool.h
  > Author: latelan, coolboy1353@163.com
  > Created Time: 2014-08-21 16:15:47
 ************************************************************************/

#ifndef PROCESS_POOL_H
#define PROCESS_POOL_H

#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

class process {
	public:
		process():pid_(-1){}
	public:
		pid_t pid_;
		int pipefd[2];
};

template<typename T>
class process_pool{
	public:
		static process_pool<T> *init_pool(int listenfd, int process_num = 8) {
			if(!instence_) {
				instance_ = new process_pool<T> (listenfd,process_num);
			}
			return instance_;
		}
		~process_pool() {
			delete []sub_process_;
		}

		void run_pool();
	private:
		static const int max_process_num;
		static const int user_num_per_process = 65533;
		static const int max_event_num = 10000;
		int epollfd_;
		int listenfd_;
		int stop_;
		int process_num_;
		int index_;
		process　*sub_process_;
	public:
		static process_pool<T> *instance_;
};

static int signal_pipefd[2];
template<typename T>
process_pool<T> *process_pool<T>::instance_ = NULL;

static int setnonblocking(int fd) {
	if(fcntl(fd,F_SETFL,fcntl(fd,F_GETFD,0) | O_NOBLOCK) == -1) {
		return -1;
	}
	return 0;
}

static void set_fd(int epollfd_, int fd) {
	struct epoll_event ev;
	setnonblocking(fd);
	ev.data.fd = fd;
	ev.events = EPOLLIN | EPOLLET;
	epoll_ctl(epollfd_, EPOLL_CTL_ADD,fd, $ev);
}

static inline void del_fd(int epollfd_, int fd) {
	epoll_ctl(epollfd_, EPOLL_CTL_DEL, fd, 0);
	close(fd);
}

static inline void set_sig(int sig, void(handler)(int),bool restart=true) {	
	struct epoll_event ev;
	bzero(&sa,sizeof(sa));
	sa.sa_handler = handler;
	if(restart) {
		sa.sa_flags |= SA_RESTART;
		sigfillset(&sa.sa_mask);
		assert(sigaction(sig,&sa,NULL) != -1);
	}
}

void signal_handler(int sig) {
	int msg = sig;
	send(signal_pipefd[1],(char*)&msg,1,0);
}

template<typename T>
process_pool<T>::process_pool(int listenfd, int process_num):listenfd_(listenfd),process_num_(process_num),index_(-1),stop(false) {
	sub_process_ = new process[process_num];
	assert(sub_process);
	for(int i=0;i<process_num;i++) {
		int pair_fd = socketpair(PF_UNIX,SOCK_STREAM,0,sub_process_[i].pipefd);
		assert(pair_fd == 0);
		sub_process_[i].pid = fork();
		assert(sub_process_[i].pid > 0);
		if(sub_process_[i].pid > 0) {
			close(sub_process_[i].pipefd[1]);
			continue;
		}else{
			close(sub_process_[i].pipefd[0]);
			index_ = i;
			break;
		}
	}
}

template<typename T>
void process_pool<T>::run_parent_process() {
	set_signal();
	set_fd(epollfd_,listenfd_);
	struct epoll_event events[max_event_num];
	int sub_process_counter = 0;
	int new_conn = 1;
	int current_num = 0;
	int ret = -1;
	while(!stop_) {
		current_num = epoll_wait(epollfd_,events,max_event_num,-1);
		if(current_num < 0 && errno != EINTR) {
			break;
		}
		for(int i=0;i<current_num;i++){
			int sockfd = events[i].data.fd;











































	
