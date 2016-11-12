/*  Nome:       Rodrigo Sousa Alves
    Matricula:  0011264
    Data:       27/10/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct node {
    NohArv item;
    struct node *proxPtr;
};

struct topo {
    stackNode* topPtr;
    int cont;
};

Pilha Pcria(){
    Pilha pilha = (Pilha)malloc(sizeof(Pilha));
    pilha->topPtr  = NULL;
    pilha->cont = 0;
    return pilha;
}

int Pvazia(Pilha pilha) {
    if (pilha->topPtr  == NULL)
        return 1;
    else
        return 0;
}

void Pdestroi(Pilha pilha) {
    
    /* Pilha nao vazia     */
    if(Pvazia(pilha) == 0) {
        stackNode *tempPtr = NULL;
        while(pilha->topPtr  != NULL) {
            tempPtr = pilha->topPtr ;
            pilha->topPtr  = pilha->topPtr->proxPtr;
            free(tempPtr);
        }
    }
}

int Ptamanho(Pilha pilha) {
    return (pilha->cont);
}

NohArv Pexamina(Pilha pilha) {
    if(Pvazia(pilha) == 1)
        return NULL;
    else
        return(pilha->topPtr->item);
}

void Pinsere(Pilha pilha, NohArv valor) {
    stackNode *newNode = (stackNode*)malloc(sizeof(stackNode));
    
    if(newNode == NULL)   /* Caso o SO nao forneca memoria */
        exit(1);
    else {
        newNode->item = valor;
        newNode->proxPtr = pilha->topPtr; /* Aponta para o topo anterior */
        
        pilha->topPtr = newNode;   /* Aponta para o novo topo da pilha */
        pilha->cont++;
    }
}

int Premove(Pilha pilha) {
    
    stackNode *tempPtr;
    if(Pvazia(pilha) == 1)
        return 0;
    else {
        tempPtr = pilha->topPtr ;
        pilha->topPtr  = pilha->topPtr->proxPtr;
        
        /* Medida de seguranca para desligar o node removido da pilha */
        tempPtr->proxPtr = NULL;
        
        free(tempPtr);
        pilha->cont--;
        return 1;
    }
}
