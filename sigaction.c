#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

//SIGFPE

struct sigaction act;
struct sigaction act2;

static void hdl1(int sig, siginfo_t *siginfo, void *context){
	printf("Interdit de faire des divisions par 0\n");
	sigaction(SIGFPE,&act2,NULL);
}



static void error_fatal(int sig, siginfo_t *siginfo, void *context){
	printf("Vous n'avez rien compris je me tire \n");
	exit(0);
}

int main(void){
	memset(&act, '\0', sizeof(act));
	memset(&act, '\0', sizeof(act2));
	act2.sa_sigaction = &error_fatal;
	act.sa_sigaction = &hdl1;
	sigaction(SIGFPE,&act,NULL);
	int c = 3/0;
	sleep(5);
	int d = 4/0;
}
