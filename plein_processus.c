#include <unistd.h>
//1) plein_processus lance 64 processus
//2) ps -jf && pstree -p
//3) si on lance ce programme avec 10 fork on obtient 2^10 processus
//4) 65 
//5) il faudrait avoir une condition qui reconnait si on est dans le processus père ou fils autrement dit la double donné par un fork
//6) 
int main(void){
	fork();fork();fork();fork();fork();fork();
	sleep(300);
}
