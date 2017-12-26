#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main(void)
{
	char *avrg[3] = {"Command-line",".",NULL};
	int pid=fork();

	if (pid==0) {
		printf("CHILD\n");
		execl("/bin/ls","ls","-l",(char*) 0);
		printf("CHILD-1\n");

	}
	else{
		wait();
		printf("PARENT\n");

	}

	return 0;
}
