#include <stdio.h> 
#include <stdlib.h>
//1.9
void echange_entier(int *entier_1, int *entier_2){
	int tmp = *entier_1;
	*entier_1 = *entier_2;
	*entier_2 = tmp;
}

int main(void){
	//1.1
	int  a[]={1,23,0,78,46,104,54,15,17,2,4};
	//1.2
	printf("---DEBUT BOUCLE TABLEAU---\n");
	for (int i = 0 ; i < sizeof(a)/sizeof(int) ;i++){
		printf("a[%d] = %d   @ = %p  \n",i,a[i],&a[i]);
	}
	printf("---FIN BOUCLE TABLEAU---\n");
	//1.4 
	int  *pa = &a[0];
	printf("*pa = %p \n",*pa);
	//1.5	
	int  *pb = a;
	printf("*pb = %p \n",*pb);
	// &a[0] = &a  car l'adresse du tableau correspond à ça première case, allocation d'un tableau dans la mémoire est représenté 	      
	//la allocation du nombre de case du tableau à la suite 
	//1.6
	printf("---1.6---\n");
	printf("[&a] -> %p \n\n",&a);
	printf("[pa] -> %p \n\n",pa);
	printf("[*pa+2] -> %d \n",*pa+2); //pointe vers le contenu de a[2]
	printf("[*(pa+2)] -> %d \n",*(pa+2));//pointe vers le contenue de l'adresse pa + 2 ;
	printf("[pa+3] -> %p \n",pa+3);//Adresse de la 4eme case du tableau
	printf("[&pa] -> %p \n",&pa);//Adresse de la première case du tableau 
	printf("[&pa+1] -> %p \n",&pa+1);//Adresse du pointeur en mémoire plus une fois la taille d'un pointeur de type char surement égale à l'adresse de pb 
	printf("[&pa[4]-3] -> %p \n",&pa[4]-3);//Addresse de a[1]
	printf("[&a[7]-pa] -> %d \n",&a[7]-pa);//Ceci est la soustraction de deux adresse en hexa 
	printf("[pa+(10-*pa)] -> %p \n",pa+(10-*pa));//adresse du tableau a plus 10-1 car pointe vers la première case du tableau, donc l'addresse de la neuxième case du tableau
	printf("[*(pa+*(pa+8)-a[7])] -> %d \n", *(pa+*(pa+8)-a[7]) );//Pointe vers l'adresse du tableau + la 8ème case du tableau - la 7ème case du tableau
	//1.7 Il n'y a plus qu'une variation de 4  entre chaque adresse à cause de la taille d'un int 
	//1.8
	int input;
	printf("Veuillez saisir un entier \n");
	scanf("%d",&input);
	int  *b ;
	b = malloc(input * sizeof(int));
	//b[] = {1,23,0,78,46,104,54};
	
	//1.9
	int c = 3 ; 
	int d = 5 ; 
	printf(" c = %d , d = %d \n",c,d);
	echange_entier(&c,&d);
	printf(" c= %d, d = %d \n",c,d);
	
}


