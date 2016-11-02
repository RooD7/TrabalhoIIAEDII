/*	Nome:		Rodrigo Sousa Alves
	Matricula:	0011264
	Data:		27/10/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "arvore.h"

int main(int argc, char const *argv[]) {
	
	stackNodePtr pilha;
    int aux;

    pilha = Pcria();
    Pinsere(pilha, 6);
    aux = Pexamina(pilha);
    aux = Ptamanho(pilha);
    aux = Premove(pilha);
    Pdestroi(pilha);

    /* sub-árvore 'd' */
	NohArv a1= Acria('d',AcriaVazia(),AcriaVazia());
	/* sub-árvore 'b' */
	NohArv a2= Acria('b',AcriaVazia(),a1);
	/* sub-árvore 'e' */
	NohArv a3= Acria('e',AcriaVazia(),AcriaVazia());
	/* sub-árvore 'f' */
	NohArv a4= Acria('f',AcriaVazia(),AcriaVazia());
	/* sub-árvore 'c' */
	NohArv a5= Acria('c',a3,a4);
	/* árvore 'a' */
	NohArv a = Acria('a',a2,a5 );

	a = Alibera(a);
	
	return 0;
}