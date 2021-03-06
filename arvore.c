/*  Nome:       Rodrigo Sousa Alves
    Matricula:  0011264
    Data:       27/10/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct reg {
	char info;
	NohArv esq;
	NohArv dir;
};

/* Cria um noh vazia */
NohArv AcriaVazia(void) {
	return NULL;
}

/* Cria um noh */
NohArv Acria(char c, NohArv esq, NohArv dir) {
	NohArv arv = (NohArv)malloc(sizeof(NohArv*));
	arv->info = c;
	arv->esq = esq;
	arv->dir = dir;
	return arv;
}

/* Destroi arvore */
NohArv Alibera(NohArv arv) {
	if (!Avazia(arv)) {
		Alibera(arv->esq);
		Alibera(arv->dir);
		free(arv);
	}
	return NULL;
}

/* Arvore vazia */
int Avazia(NohArv arv) {
	return(arv == NULL);
}

/* Pertence a arvore */
int Apertence(NohArv arv, char c) {
	if(Avazia(arv))
		return 0;
	else
		return arv->info == c ||
			Apertence(arv->esq, c) ||
			Apertence(arv->dir, c);
}

/* Imprime arvore Posfixada */
void AimprimePos(NohArv arv, FILE* fileOut) {
	if (!Avazia(arv)) {
		AimprimePos(arv->esq, fileOut);
		AimprimePos(arv->dir, fileOut);
		fprintf(fileOut,"%c ", arv->info);
	}
}

/* Imprime arvore Prefixada */
void AimprimePre(NohArv arv, FILE* fileOut) {
	if (!Avazia(arv)) {
		fprintf(fileOut,"%c ", arv->info);
		AimprimePre(arv->esq, fileOut);
		AimprimePre(arv->dir, fileOut);
	}
}

/* Imprime arvore Infixa */
void AimprimeInf(NohArv arv, FILE* fileOut) {
	if (!Avazia(arv)) {
		AimprimeInf(arv->esq, fileOut);
		fprintf(fileOut,"%c ", arv->info);
		AimprimeInf(arv->dir, fileOut);
	}
}

char AitemArv(NohArv arv) {
	return(arv->info);
}

NohArv AnohEsq(NohArv arv) {
	return(arv->esq);
}

NohArv AnohDir(NohArv arv) {
	return(arv->dir);
}