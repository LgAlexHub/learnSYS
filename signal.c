#include <stdio.h>
#include <signal.h>
#include <sys/wait.h> 
#include <sys/types.h>
#include <unistd.h>
void handler(int sig){
		printf("BONJOUR \n");
		signal(sig,SIG_IGN);
}

void handler_1(int sig){
	printf("BONSOIR \n");
	signal(sig,SIG_DFL);
}

int main(void){
	printf("BONJOUR JE SUIS %d \n",getpid());
	signal(SIGUSR1,handler);
	signal(SIGUSR2,handler_1);
	while(1){}
}
