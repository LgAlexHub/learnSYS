#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void){
	int p = fork();
	if (p == 0 ) {
		// on est dans fils 
		sleep(10);
		printf("J'ai fini de travailler je pointe : %d \n",getpid());
		system("ps -af | grep synchro &");
		exit(0);
	}else{
		printf("Je suis le père %d j'attend que %d pointe \n",getpid(),p);
		system("ps -af | grep synchro &");
		return(0);
	}
}
