#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
//SIGFPE

void error_fatal(int sig);
void error_1(int sig){
	printf("Pas de division par 0 derniere avertissement \n");
	signal(sig,error_fatal);
}

void error_fatal(int sig){
	printf("Vous n'avez rien compris je me tire \n");
	exit(0);
}

int main(void){
	signal(SIGFPE,error_1);
	int c = 3/0;
	sleep(5);
	int d = 4/0;
}
