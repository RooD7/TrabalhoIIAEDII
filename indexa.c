/*	Nome:		Rodrigo Sousa Alves
	Matricula:	0011264
	Data:		27/10/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include "indexa.h"
#include "arvore.h"

int IehOperador(char c) {
	return ((c == '+') || (c == '-') ||
			 (c == '*') || (c == '/'));
}

int IehOperando(char c) {
	return ((c >= 48) && (c <= 57));
}

void IindexaChar(Pilha p, char c) {

	NohArv arv;
	char aux;

	if (c != '\n') {
		if  (IehOperador(c)) {
			NohArv a1 = Pexamina(p);
			Premove(p);
			NohArv a2 = Pexamina(p);
			Premove(p);
			aux = AitemNoh(a2);
			/* segundo item é operador, fica a esquerda do novo noh*/
			if  (IehOperador(aux))
				arv = Acria(c, a2, a1);
			else
				arv = Acria(c, a1, a2);	
		} 
		else 
			arv = Acria(c, AcriaVazia(), AcriaVazia());

		Pinsere(p, arv);
	}
}

int IcalculaExpressao(NohArv arv) {
	
	if (IehOperador(AitemArv(arv))) {
		/*	Operador	*/
		switch (AitemArv(arv)) {
			case '+':
				return (IcalculaExpressao(AnohEsq(arv)) + IcalculaExpressao(AnohDir(arv)));
				break;
			case '-':
				return (IcalculaExpressao(AnohEsq(arv)) - IcalculaExpressao(AnohDir(arv)));
				break;
			case '*':
				return (IcalculaExpressao(AnohEsq(arv)) * IcalculaExpressao(AnohDir(arv)));
				break;
			case '/':
				return (IcalculaExpressao(AnohEsq(arv)) / IcalculaExpressao(AnohDir(arv)));
				break;
		}
	} 
	else {
		/*	Converte char to int	*/
		char c = AitemArv(arv);
		return ((int)c - 48);
	}
	return 0;
}