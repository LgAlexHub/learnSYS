#include <stdio.h> 

int main(void){
	//1.1
	char a[]={1,23,0,78,46,104,54,15,17,2,4};
	//1.2
	for (int i = 0 ; i < sizeof(a)/sizeof(char) ;i++){
		printf("a[%d] = %c \n",i,a[i]);
	}
	//1.4 
	char *pa = &a[0];
	printf("*pa = %p \n",*pa);
	//1.5	
	char *pb = a;
	printf("*pb = %p \n",*pb);
	}
	// &a[0] = &a  car l'adresse du tableau correspond à ça première case, allocation d'un tableau dans la mémoire est représenté 	      // la allocation du nombre de case du tableau à la suite 
	//1.6
	
