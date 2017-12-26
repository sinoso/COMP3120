
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main(void)
{
	int file = open("test.txt", O_WRONLY);
	int pid=fork();
	if (pid==0) {
		printf("this is child_p for write CHILD\n");
		write(file,"CHILD\n",sizeof("CHILD"));
	}
	else{
		printf("this is parent_p for write PARENT\n");
		write(file,"PARENT\n",sizeof("PARENT"));
	}
	close(file);

	return 0;
}
