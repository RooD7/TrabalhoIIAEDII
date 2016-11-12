/*	Nome:		Rodrigo Sousa Alves
	Matricula:	0011264
	Data:		27/10/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "entradaSaida.h"

int main(int argc, char const *argv[]) {
	
	Pilha p;
    p = Pcria();

	ESentradaDeDados(p);

    Pdestroi(p);

	return 0;
}