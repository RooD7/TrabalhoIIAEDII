/*	Nome:		Rodrigo Sousa Alves
	Matricula:	0011264
	Data:		27/10/2016
*/

/* Cabeçalhos das funções implementadas no módulo arvore.c */

typedef struct reg* NohArv;

/* Cria um noh vazia */
NohArv AcriaVazia(void);

/* Cria um noh */
NohArv Acria(char c, NohArv esq, NohArv dir);

/* Destroi arvore */
NohArv Alibera(NohArv arv);

/* Arvore vazia */
int Avazia(NohArv arv);

/* Pertence a arvore */
int Apertence(NohArv arv, char c);

/* Imprime arvore */
void Aimprime(NohArv arv);