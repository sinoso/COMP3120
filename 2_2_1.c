#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
int count = 0;
void *t_function()
{
	while(count<1000000)
	count++;
}

int main()
{
	int i;
	pthread_t p_thread;
	int thr_id;
    	struct timeval start,end;
	double diffrent;
	int thread_multi;

	printf("without lock\n");
	for(thread_multi=1;thread_multi<=128;)
	{
		gettimeofday(&start, NULL);//start
		for(i=0;i<thread_multi;i++)
		{
			thr_id = pthread_create(&p_thread, NULL, t_function, NULL);
			if (thr_id < 0)
			{
				perror("thread create error : ");
				exit(0);
			}
		}
		for(i=0;i<thread_multi;i++)
		{
			pthread_join(p_thread,NULL);
		}
		gettimeofday(&end, NULL);
		diffrent = end.tv_sec *1000000.0 + end.tv_usec- start.tv_sec*1000000.0 - start.tv_usec;
		printf("count=%d time = %f threads = %d\n",count,diffrent, thread_multi);//end
		thread_multi = thread_multi+thread_multi;
	};
	return 0;
}
