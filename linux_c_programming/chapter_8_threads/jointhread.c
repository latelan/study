#include <stdio.h>
#include <pthread.h>

void assistthread(void* arg)
{

	printf("I am helping to do some jobs\n");
	sleep(3);
	pthread_exit(0);
}

int main(void)
{
	pthread_t assistthid;
	int status;

	pthread_create(&assistthid, NULL, (void *)assistthread, NULL);
	pthread_join(assistthid, (void *)&status);
	printf("assistthread's exit is caused %d\n", status);

	return 0;
}
