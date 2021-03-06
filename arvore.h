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

/* Imprime arvore Posfixada */
void AimprimePos(NohArv arv, FILE* fileOut);

/* Imprime arvore Prefixada */
void AimprimePre(NohArv arv, FILE* fileOut);

/* Imprime arvore Infixa */
void AimprimeInf(NohArv arv, FILE* fileOut);

/*	Retorna elemento arvore	*/
char AitemArv(NohArv arv);

/*	Noh esquerdo	*/
NohArv AnohEsq(NohArv arv);

/*	Noh direito	*/
NohArv AnohDir(NohArv arv);

