#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 

int isAPlusPetitQueB(int a, int b ){
	return a>b;
}	


void tri_bulle(int *tab, int size,int (*func_tri)(int,int)){
	int echange_effectue;
	do{
		echange_effectue = 0;
		for (int j = 0  ; j < size ; j++){
			if (func_tri(*(tab+j), *(tab+j+1))) {
				int tmp=*(tab+j); 
				*(tab+j) = *(tab+j+1);
				*(tab+j+1) = tmp;
				echange_effectue = 1;
			}
		}
		size = size -1 ; 
	}while(echange_effectue == 1);

}
	
int main(void){
	srand(time(NULL));
	int tab[(rand()%(100-1+1))+1];
	for (int i = 0  ; i < sizeof(tab)/sizeof(int) ; i++){
		tab[i] = (rand()%(100-1+1))+1;
		printf("tab [%d] => %d \n",i,tab[i]);	
	}	
	tri_bulle(tab,sizeof(tab)/sizeof(int),isAPlusPetitQueB);
	printf("---Tableau rang---\n");
	for (int i = 0 ; i < sizeof(tab)/sizeof(int) ; i++){
		printf("tab [%d] => %d \n ",i , tab[i]);
	}

	
}
