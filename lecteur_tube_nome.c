#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
	int tube;
	char chaine [30];
	tube = open("fichier_du_tube",O_RDONLY);
	read(tube,chaine,26);
	chaine[29]=0;
	printf("Processus lecteur de tube");
	printf("fichier_du_tube : %s \n",chaine);
	close(tube);
}
