#include <stdio.h>
#include <stdlib.h>
#include "pilhaEncadeada.h"

typedef struct elemento{
    char dado;
    struct elemento *prox;
}Elemento;

Pilha criarPilha(){
    Pilha *pi = (Pilha *)malloc(sizeof(Pilha));

    if(pi != NULL){
        *pi = NULL;
    }

    return pi;
}

int liberarPilha(Pilha *pi){
    if(pi == NULL){
        return 0;
    }

    Elemento *aux;
    while(*pi != NULL){
        aux = *pi;
        *pi = (*pi)->prox;
        free(aux);
    }

    free(pi);

    return 1;
}

Elemento *criarElemento(){
    Elemento *aux = (Elemento *) malloc(sizeof(Elemento));

    return aux;
}

int inserirElemento(Pilha *pi, char dado){
    if(pi == NULL){
        return 0;
    }

    Elemento *aux = criarElemento();

    aux->dado = dado;
    aux->prox = (*pi);

    *pi = aux;

    return 1;
}

