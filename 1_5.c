#include<stdio.h>

int main(void)
{
	int pid = fork();

	if(pid==0){
		printf("wait = %d\n",wait());
		printf("child process \n");
	}
	else{	
		printf("parent process \n");
	};
	return 0;
}
