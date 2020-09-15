#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void){
    int pip[2];
    pid_t pid;
    char chaine[]="Avant...";
    int taille;
    pipe(pip);

    if((pid=fork())==0){
        sleep(2);
        char chaine_fils[]="Pour toi papa :)";
        close(pip[0]);
        write(pip[1],&chaine_fils,strlen(chaine_fils));
        close(pip[1]);
        exit(0);
    }else{
        char chaine_papa[]="Je vais etre effacee";
        int taille_chaine = strlen(chaine_papa);
        printf("taille %d \n",taille_chaine);
        memset(chaine_papa,'\0',taille_chaine);
        printf("Chaine avant %s \n",chaine_papa);
        close(pip[1]);
        read(pip[0],chaine_papa,taille_chaine);
        close(pip[0]);
        printf("Chaine après %s \n",chaine_papa);
    }
}