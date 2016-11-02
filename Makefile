#	Nome:		Rodrigo Sousa Alves
#	Matricula:	0011264
#	Data:		27/10/2016

all:
	gcc -o pilha.o -c pilha.c
	gcc -o arvore.o -c arvore.c
	gcc main.c pilha.o arvore.o -o main
run:
	./main