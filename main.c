/*	Nome:		Rodrigo Sousa Alves
	Matricula:	0011264
	Data:		27/10/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "entrada.h"

int main(int argc, char const *argv[]) {
	
	Pilha p;
    p = Pcria();

	int op;
	printf("Entrada de dados:\n");
	printf("1. Via Tela.\n");
	printf("2. Via Arquivo.\n");
	scanf("%d", &op);
	EntradaDeDados(p, op);

    Pdestroi(p);
	/*	a = Alibera(a); */

	return 0;
}