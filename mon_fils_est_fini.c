#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void mon_fils_est_fini(int sig){
	printf("[%d] = > %d signal \n",getpid(),sig);
	printf("mon fils est terminé ...\n");
}


int main(){
	pid_t pid;
	system("clear");
	if((pid = fork()) == 0){
		printf("Je me met en pause, mon PID est : %d \n",getpid());
		for(;;);
	}
	printf("père, mon PID : %d\n",getpid());
	system("ps -lH");
	(void) signal(SIGCHLD, mon_fils_est_fini);
	printf("Appuyez sur une touche pour stopper le fils \n");
	getchar();
	kill(pid, SIGINT);
	system("ps -lH");
	waitpid(pid,NULL,0);
	system("ps -lH");
	return EXIT_SUCCESS;
}
