#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	int a = fork();
	for (int i = 0 ; i < 2 ; i++){
		if (a == 0 ){
			a = fork();
			system("ps -jf &");
		}else{
			sleep(10);
		}
	}
}
