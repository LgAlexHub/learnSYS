#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void){
	int pid,r;
	if ((pid = fork()) == 0 ){
		sleep(1);
		printf("\tfils %d  de %d \n",getpid(),getppid());
		sleep(30);
		printf("\tmort fils %d de %d \n",getpid(),getppid());
		exit(0);
	}
	printf("\t père %d de %d \n",getpid(),pid);
	sleep(100);
	wait(&r);
	printf("\t mort père %d de %d mort(%d) \n",getpid(),pid,r);
	sleep(100);
	return 0;
}
