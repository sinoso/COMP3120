#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(void){
	char buffer[30];
	char input[100];
	int fd[2];
	pipe(fd)==-1; 
	pid_t pid;
	pid_t pid2;
	pid = fork();
	pid2 = fork();
	if(pid==0)
	{
		scanf("%s",input);
		write(fd[1],input,100); 
	}
        else if (pid2==0)
	{ 
		read(fd[0],buffer,100);
		printf("Output of child2 : %s \n\n",buffer);
        }
	else
	{
		wait();
		sleep(1);
	}
	return 0;
}


