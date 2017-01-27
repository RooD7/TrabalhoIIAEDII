/*	Nome:		Rodrigo Sousa Alves
	Matricula:	0011264
	Data:		27/10/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entradaSaida.h"
#include "indexa.h"


/*	Tipo de Entrada de Dados	*/
void ESentradaDeDados(Pilha p) {
	int opIn, opOut;
	FILE* fileIn;
	FILE* fileOut;

	/*	Entrada de Dados	*/
	printf("Entrada de dados:\n");
	printf("1. Via Tela.\n");
	printf("2. Via Arquivo.\n");
	scanf("%d", &opIn);

	if(opIn == 2) {
		char nameFileIn[50];
		printf("Nome do Arquivo Entrada: ");
		scanf("%s", nameFileIn);
		fileIn = fopen(nameFileIn, "r");
		if(fileIn == NULL)
			exit(1);
	}
	else
		fileIn = stdout;

	/*	Saida de Dados	*/
	printf("\nSaida de dados:\n");
	printf("1. Via Tela.\n");
	printf("2. Via Arquivo.\n");
	scanf("%d", &opOut);

	if(opOut == 2) {
		char nameFileOut[50];
		printf("Nome do Arquivo Saida: ");
		scanf("%s", nameFileOut);
		fileOut = fopen(nameFileOut, "w");
		if(fileOut == NULL)
			exit(1);
	}
	else
		fileOut = stdout;

	/*	Funções de leitura de dados	*/
	if (opIn == 1)
		ESleituraTela(p, fileOut);
	else
		ESleituraArquivo(p, fileIn, fileOut);

	fclose(fileIn);
	fclose(fileOut);
}

void ESleituraTela(Pilha p, FILE* fileOut) {
	char exp[50];
	int i;

	printf("\n\nExpressão: ");
	scanf("%s", exp);

	for (i = 0; i < strlen(exp); i++)
		IindexaChar(p, exp[i]);

	/*	Saida de dados	*/	
	ESimprimeExpressao(p, fileOut);

	Pdestroi(p);
}

void ESleituraArquivo(Pilha p, FILE* fileIn, FILE* fileOut) {
	char exp[50];
	int i;

	/*	Cada linha do arquivo lido	*/
	while(fscanf(fileIn, "%s", exp) != EOF) {
		/*	Indexa char na pilha de arvores		*/
		for (i = 0; i < strlen(exp); i++)
			IindexaChar(p, exp[i]);

		/*	Saida de dados	*/	
		ESimprimeExpressao(p, fileOut);
	
		Pdestroi(p);
	}
}

void ESimprimeExpressao(Pilha p, FILE* fileOut) {

	fprintf(fileOut,"\n\n//---///---//---///---//---///---//---///---//\n");
	fprintf(fileOut,"Infixa: ");
	AimprimeInf(Pexamina(p), fileOut);
	fprintf(fileOut,"\n");
	fprintf(fileOut,"Prefixada: ");
	AimprimePre(Pexamina(p), fileOut);
	fprintf(fileOut,"\n");
	fprintf(fileOut,"Posfixada: ");
	AimprimePos(Pexamina(p), fileOut);
	fprintf(fileOut,"\n\n");
	ESformataExpressao(Pexamina(p), fileOut);
	fprintf(fileOut,"\n");
	fprintf(fileOut,"\nResultado:\t%.2f\n", IcalculaExpressao(Pexamina(p)));
}

void ESformataExpressao(NohArv arv, FILE* fileOut) {
	if (!Avazia(arv)) {	
		if (IehOperador(AitemArv(arv))) {
			/*	Operador	*/
			fprintf(fileOut,"(");
			switch (AitemArv(arv)) {
				case '+':
					ESformataExpressao(AnohEsq(arv), fileOut);
					fprintf(fileOut," + ");
					ESformataExpressao(AnohDir(arv), fileOut);
					break;
				case '-':
					ESformataExpressao(AnohEsq(arv), fileOut);
					fprintf(fileOut," - ");
					ESformataExpressao(AnohDir(arv), fileOut);
					break;
				case '*':
					ESformataExpressao(AnohEsq(arv), fileOut);
					fprintf(fileOut," * ");
					ESformataExpressao(AnohDir(arv), fileOut);
					break;
				case '/':
					ESformataExpressao(AnohEsq(arv), fileOut);
					fprintf(fileOut," / ");
					ESformataExpressao(AnohDir(arv), fileOut);
					break;
			}
			fprintf(fileOut,") ");
		} 
		else
			fprintf(fileOut,"%c", AitemArv(arv));
	}
}