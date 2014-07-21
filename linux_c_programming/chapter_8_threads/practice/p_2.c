/*************************************************************************
  > File Name: p_2.c
  > Author: latelan, coolboy1353@163.com
  > Created Time: 2014-07-21 17:22:55
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int share;

void *thread1(void *arg)
{
	pthread_t thid;
	int i;

	thid = pthread_self();
	for(i=0;i<10;i++0){
		share ++;
		printf("this is  thread1, thread ID = %u, share = %d\n", thid,share);
		sleep(2);
	}
	return NULL;
}

void *thread2(void *arg)
{
	pthread_t thid;

	thid = pthread_self();
	share --;
	printf("this is thread2, thread ID = %u, share = %d\n", thid,share);
	return NULL;
}

void *thread3(void *arg)
{
	pthread_t thid;

	thid = pthread_self();
	share --;
	printf("this is thread3, thread ID = %u, share = %d\n", thid,share);
	return NULL;
}

int main(void)
{
	pthread_t thid, thid1, thid2, thid3;

	share = 5;
	printf("main thread, ID is %u, share = %d\n", pthread_self(),share);
	pthread_create(&thid1,NULL,thread1,NULL);
	pthread_create(&thid2,NULL,thread2,NULL);
	pthread_create(&thid3,NULL,thread3,NULL);

	sleep(3);
	printf("main thread exit.\n");
	exit(0);
}
