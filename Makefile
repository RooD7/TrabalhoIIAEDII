#	Nome:		Rodrigo Sousa Alves
#	Matricula:	0011264
#	Data:		27/10/2016

all:
	gcc -Wall -ansi -o arvore.o -c arvore.c
	gcc -Wall -ansi -o pilha.o -c pilha.c
	gcc -Wall -ansi -o entrada.o -c entrada.c
	gcc -Wall -ansi -o indexa.o -c indexa.c
	gcc -Wall -ansi main.c indexa.o entrada.o pilha.o arvore.o -o main
run:
	./main