#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(void){
	char buffer[30];
	int fd[2];
	pipe(fd)==-1; 
	pid_t pid;
	pid_t pid2;
	pid = fork();
	pid2 = fork();
	if(pid==0)
	{ 
		write(fd[1],"from child1 to child2",30); 
	}
        else if (pid2==0)
	{ 
		read(fd[0],buffer,30);
		printf("Output of child2 : %s \n\n",buffer);
        }
	else
	{
		wait();
		printf("parent\n");
	}
	return 0;
}

