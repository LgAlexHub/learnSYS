#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void){
	mode_t mode;
	int tube;
	char chaine[]="Bonjour passe dans le tube";
	mode = S_IRUSR | S_IWUSR;
	mkfifo("fichier_du_tube",mode);
	tube = open("fichier_du_tube",O_WRONLY);
	write(tube, chaine, strlen(chaine));
	close(tube);
}
