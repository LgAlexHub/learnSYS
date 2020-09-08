#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//1) Il va falloir quatre processus pour cet exercice
//2) On peut les nommer ainsi car chaque processus à un père différent, et qu'un processus ne peut créer qu'un 0 ou 1 fils
//3) Flemme 
//4) Le but de waitpid est de faire un processus en lui donnant le pid du processus qu'il doit attendre 
int main(void){
	system("clear");
	int a = fork();
	if (a == 0){
		printf("[Fils] : %d mon père c'est : %d, maintenant sieste de 5 sec  \n",getpid(),getppid());
		sleep(5);
		int b = fork();
		if (b == 0){
			printf("[Petit fils] : %d mon père c'est : %d, maintenant sieste de 5 sec \n",getpid(),getppid());
			sleep(5);
			int c = fork();	
			if(c==0){
				printf("[Arrière petit fils] : %d mon père c'est : %d, maintenant sieste de 5 sec \n",getpid(),getppid());			      sleep(5);
			}else{
				printf("[Petit fils] : %d j'attend : %d \n",getpid(),c);
			}
		}else{
			printf("[Fils] : %d j'attend : %d \n",getpid(),b); 
			waitpid(b,NULL,0);
		}
	}else{
		printf("[Père] : %d j'attend : %d \n",getpid(),a);
		waitpid(a,NULL,0);
	}
}
