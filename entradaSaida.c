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
	int op;

	printf("Entrada de dados:\n");
	printf("1. Via Tela.\n");
	printf("2. Via Arquivo.\n");
	scanf("%d", &op);

	if (op == 1)
		ESleituraTela(p);
	else
		ESleituraArquivo(p);
}

void ESleituraTela(Pilha p) {
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

void ESleituraArquivo(Pilha p) {
	
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
		printf("\n\n//---///---//---///---//---///---//---///---//\n");
		for (i = 0; i < strlen(exp); i++) {
			printf("%c", exp[i]);
			IindexaChar(p, exp[i]);
		}
		printf("\n\n");
		/*	Cada linha do arquivo lido	*/
		ESimprimeExpressao(p);
		printf("\nResultado:\t%d\n", IcalculaExpressao(Pexamina(p)));
		Pdestroi(p);
	}
	printf("\n");
	fclose(fileExp);
}

void ESimprimeExpressao(Pilha p) {

	printf("Posfixada: ");
	AimprimePos(Pexamina(p));
	printf("\n");
	printf("Infixa: ");
	AimprimeInf(Pexamina(p));
	printf("\n");
	printf("Prefixada: ");
	AimprimePre(Pexamina(p));
	printf("\n\n");
	ESformataExpressao(Pexamina(p));
	printf("\n");
}

void ESformataExpressao(NohArv arv) {
	if (!Avazia(arv)) {	
		if (IehOperador(AitemArv(arv))) {
			/*	Operador	*/
			printf("(");
			switch (AitemArv(arv)) {
				case '+':
					ESformataExpressao(AnohEsq(arv));
					printf(" + ");
					ESformataExpressao(AnohDir(arv));
					break;
				case '-':
					ESformataExpressao(AnohEsq(arv));
					printf(" - ");
					ESformataExpressao(AnohDir(arv));
					break;
				case '*':
					ESformataExpressao(AnohEsq(arv));
					printf(" * ");
					ESformataExpressao(AnohDir(arv));
					break;
				case '/':
					ESformataExpressao(AnohEsq(arv));
					printf(" / ");
					ESformataExpressao(AnohDir(arv));
					break;
			}
			printf(") ");
		} 
		else
			printf("%c", AitemArv(arv));
	}
}