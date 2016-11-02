/*	Nome:		Rodrigo Sousa Alves
	Matricula:	0011264
	Data:		27/10/2016
*/
#include "arvore.h"
/* Cabeçalhos das funções implementadas no módulo pilha.c */

typedef struct node stackNode;

typedef struct topo* Pilha;

/* Cria uma pilha vazia */
Pilha Pcria();

/* examina se a pilha esta vazia */
int Pvazia(Pilha pilha);

/* destroi a pilha */
void Pdestroi(Pilha pilha);

/* retorna a quantidade de elementos na pilha */
int Ptamanho(Pilha pilha);

/* retorna o elemento no topo da pilha */
NohArv Pexamina(Pilha pilha);

/* insere o elemento no topo da pilha */
void Pinsere(Pilha pilha, NohArv valor);

/* remove e retorna o elemento no topo da pilha */
int Premove(Pilha pilha);