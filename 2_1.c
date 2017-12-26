#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    	struct timeval start,end;
	double diffrent;
	gettimeofday(&start, NULL);
	sleep(1);
	gettimeofday(&end, NULL);
	diffrent = end.tv_sec *1000000.0 + end.tv_usec- start.tv_sec*1000000.0 - start.tv_usec;
	printf("%f\n",diffrent);
	return 0;
}
