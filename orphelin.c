#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
//1) Le fils n'a pas pu prévenir son père de sa mort donc il devient zombie 
//5) Le père quitte avant que le fils fasse son travail donc il devient orphelin
//
int main (int argc,char **argv){
	if (fork() == (pid_t) 0 ) {
		printf("fin du fils pid => %d \n",getpid());
		sleep(30);
		exit(0);
	}
	//sleep(30);
	printf("le père se réveille et stop : %d \n",getpid());
	return 0;
}
