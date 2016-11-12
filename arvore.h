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

/*	Item do Noh	*/
char AitemNoh(NohArv arv);

/* Imprime arvore Posfixada */
void AimprimePos(NohArv arv);

/* Imprime arvore Prefixada */
void AimprimePre(NohArv arv);

/* Imprime arvore Infixa */
void AimprimeInf(NohArv arv);

/*	Retorna elemento arvore	*/
char AitemArv(NohArv arv);

/*	Noh esquerdo	*/
NohArv AnohEsq(NohArv arv);

/*	Noh direito	*/
NohArv AnohDir(NohArv arv);

/* Imprime arvore */
void Aimprime(NohArv arv);

