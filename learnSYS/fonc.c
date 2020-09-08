#include <stdio.h>

int isAPlusGrandQueB (int a, int b){
	return a>b;
}

int (*pf)(int,int) = &isAPlusGrandQueB;

int main(void){
	int a=5,b=3;
	printf("Is A plus grand que b ? = %d \n",(*pf)(a,b));
	return 0;

}
