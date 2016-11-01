/*	Nome:		Rodrigo Sousa Alves
	Matricula:	0011264
	Data:		27/10/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char const *argv[]) {
	
	stackNodePtr pilha;
    int aux;

    pilha = Pcria();
    Pinsere(pilha, 6);
    aux = Pexamina(pilha);
    aux = Ptamanho(pilha);
    aux = Premove(pilha);
    Pdestroi(pilha);
	return 0;
}