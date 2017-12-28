#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
void *t_function1(void *  data)
{
	FILE *  fp = fopen(data, "r");
	char line[1024];
	while(1)
	{
	while (fgets(line, 1024, fp) != NULL)
	{
		if (strstr(line,"VmSize"))
		{       
		printf("%s",line);
		break;
		};
	};
	sleep(1);
	fp = fopen(data, "r");
	};
}

void *t_function2(void *  data)
{
	FILE *  fp = fopen(data, "r");
	char line[1024];
	int i=0,a,b, total,save=0,tmp;
	while(1)
	{
	sleep(1);
		while (i != 15)
		{
			fscanf(fp,"%s",line);
			i++;
			if (i==14)
			a=atoi(line);
		};
	b=atoi(line);
	total= a+b;
	if(save == 0)
	{
		save=total;
		total=0;
	}
	else
	{
		tmp = total;
		total -= save;
		save = tmp;	
	};
	printf("usage = %d milesec\n",total*10);
	i=0;
	fp = fopen(data, "r");
	};
}

int main(int argc, char **argv)
{
	char name[128];
	char name2[128];
	sprintf(name,"/proc/%s/status",argv[1]);
	sprintf(name2,"/proc/%s/stat",argv[1]);
	pthread_t p_thread1,p_thread2;
	pthread_create(&p_thread2, NULL, t_function2, (void *)name2);
	pthread_create(&p_thread1, NULL, t_function1, (void *)name);
	pthread_join(p_thread1,NULL);
	pthread_join(p_thread2,NULL);
	return 0;
}


