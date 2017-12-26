#include<stdio.h>

int main(void)
{
	int pid = fork();
	int v_x=100;
	if(pid==0){
		v_x++;
		printf("child process %d\n",v_x);
	}
	else{
		v_x--;
		printf("parent process %d\n",v_x);
	};
	return 0;
}
