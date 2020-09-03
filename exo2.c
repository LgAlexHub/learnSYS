#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>


void toLowerCase (char *tab, int size) {
	for (int i = 0 ; i < size ; i++ ) {
		putchar(tolower(*(tab+i)));
	}
}

int howManyE(char *tab, int size){
	toLowerCase(tab,size);
	int res = 0 ; 
	for (int i = 0 ; i < size ; i++){
		if (*(tab+i) == 'e' ){
			res++;
		}
	}
	return res;
}

int isLipogramme (char tab[], int size){
	for (int i = 0 ; i < size ; i++){
		if (tab[i] == 'e') {
			return 0;
		}
	}
	return 1;
}

void wordReverser (char *tab, int size){
	char *tmp = malloc(size*sizeof(char));
	for (int i = 0 ; i < size ;i++){
		*(tmp+size-i-1) = *(tab+i);
	}
	for (int i = 0  ; i < size ; i++){
		if (*(tmp+i) == '\0'){
		continue;
		}
		*(tab+i) = *(tmp+i);
	}

}

int isPalindrome (char *tab, int size){
	if (*(tab+size-1) == '\0')
		size = size -1 ;
	if (size%2 ==  1){
		printf("DEBUG-> Taille du char impair \n");
		int loop = size/2;
		printf("DEBUG -> loop : %d \n",loop);
		char firstPart[loop];
		char lastPart[loop];
		for (int i=0 ; i<loop;i++){
			firstPart[i] = *(tab+i);
			lastPart[i] = *(tab+size-i-1);
			printf("FirstPart[%d] = > %c | LastPart[%d] => %c \n",i,*(tab+i),i, *(tab+size-i-1));
		}
		printf("Debug -> lastPart = %c%c \n",*lastPart,*(lastPart+1));
		for (int i = 0 ; i<loop;i++){
			if (firstPart[i] != lastPart[i]){
				return 0;
			}
		}
		return 1;
	}else{
		return 0;
	}
}

int main(void){	
/*	char phras[] = "Je suis content de faire du c ";	
	printf("| Nombre de e : %d \n",howManyE(phras,sizeof(phras)));
	printf("%s| ",phras);
	if (isLipogramme(phras, sizeof(phras)) == 1){
		printf("est un lipogramme \n");
	}else{
		printf("n'est pas un lipogramme \n");
	}

	printf("Avant le reverse : %s \n",phras); 
	wordReverser(phras, sizeof(phras));
	printf("Après le reverse : %s \n",phras);
*/
	char kayak[]="kayak";
	printf("%s is palindromme ? : %d \n",kayak,isPalindrome(kayak,sizeof(kayak)));
}
