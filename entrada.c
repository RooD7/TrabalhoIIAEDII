/*	Nome:		Rodrigo Sousa Alves
	Matricula:	0011264
	Data:		27/10/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada.h"
#include "arvore.h"
#include "indexa.h"


/*	Tipo de Entrada de Dados	*/
void EntradaDeDados(Pilha p, int opcao) {
	if (opcao == 1)
		LeituraTela(p);
	else
		LeituraArquivo(p);
}

void LeituraTela(Pilha p) {
	char exp[50];
	int i;

	printf("Expressão: ");
	scanf("%s", exp);

	for (i = 0; i < strlen(exp); i++) {
		printf("%c", exp[i]);
		IindexaChar(p, exp[i]);
	}
	printf("\n");
}

void LeituraArquivo(Pilha p) {
	
	FILE* fileExp;
	/*
		char nameFile[50];
	*/
	char exp[50];
	int i;

	printf("Nome do Arquivo: ");
	/*
	scanf("%s", nameFile);

	fileExp = fopen(nameFile, "r");
	*/
	fileExp = fopen("test.txt", "r");

	if (fileExp == NULL)
		exit(1);

	while(fscanf(fileExp, "%s", exp) != EOF) {
		for (i = 0; i < strlen(exp); i++) {
			printf("%c", exp[i]);
			IindexaChar(p, exp[i]);
		}
		printf("\n");
		ImprimeExpressao(p);
		printf("\n//------------------------------//\n");
		printf("Resultado:\t%d\n", IcalculaExpressao(Pexamina(p)));
	}
	printf("\n");
	fclose(fileExp);
}

void ImprimeExpressao(Pilha p) {

	printf("Posfixada: ");
	AimprimePos(Pexamina(p));
	printf("\n");
	printf("Infixa: ");
	AimprimeInf(Pexamina(p));
	printf("\n");
	printf("Prefixada: ");
	AimprimePre(Pexamina(p));
	printf("\n");

}