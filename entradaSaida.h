/*	Nome:		Rodrigo Sousa Alves
	Matricula:	0011264
	Data:		27/10/2016
*/
#include "arvore.h"
#include "pilha.h"

/*	Define onde a entrada e saida de dados vai ocorrer	*/
void ESentradaDeDados(Pilha p);

/*	Realiza a leitura de dados via arquivo	*/
void ESleituraArquivo(Pilha p, FILE* fileIn, FILE* fileOut);

/*	Realiza a leitura de dados via tela	*/
void ESleituraTela(Pilha p, FILE* fileOut);

/*	Imprime a expressao de diversas formas e o resultado	*/
void ESimprimeExpressao(Pilha p, FILE* fileOut);

/*	Aplica parenteses e define a precedencia da expressao	*/
void ESformataExpressao(NohArv arv, FILE* fileOut);