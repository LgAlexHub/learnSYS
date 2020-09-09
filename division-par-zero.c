#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h> //pour memset

struct sigaction action;
sigset_t ens;

void rienCompris() { // 
  printf("Je viens de vous dire que le dénominateur ne doit pas être nul !!! \n");
  action.sa_handler=SIG_DFL; // la prochaine fois on jette !
  sigaction(SIGFPE, &action, NULL);
}

void handFPE() { // Le handler ou fonction lancée !
  printf("Vous avez fait une division par 0 !!!\n");
  action.sa_handler=rienCompris; // en permanence
  sigaction(SIGFPE, &action, NULL);
}

int main() {
  int a =12;
  int b = 0;
  int c;

  action.sa_handler = handFPE;
  action.sa_flags=0; 
  //vide l'ensemble de signaux fourni
  sigemptyset(&action.sa_mask); 
  sigaction(SIGFPE, &action, NULL);
  sigaddset(&action.sa_mask,SIGFPE);
  
  c = a/b; // la divison par 0 ...
  printf("encore une fois \n");
  c = a/b;
  printf("encore une fois et c'est la dernière ! \n");
  c = a/b;
  printf("Je ne serais jamais affiché sniff !!!\n");
  return 0;
}
