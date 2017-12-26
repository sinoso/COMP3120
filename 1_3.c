#include<stdio.h>

int main(void)
{
	int pid = fork();
	if(pid==0){
		printf("hello\n");//child
	}
	else{
		sleep(1);
		printf("goodbye\n");
	};
	return 0;
}
