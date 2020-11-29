#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaEncadeada.h"

typedef struct elemento{
    char dado;
    struct elemento *prox;
}Elemento;

Pilha *criarPilha(){
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

int removerElemento(Pilha *pi){
    if(pi == NULL){
        return 0;
    }

    if((*pi) == NULL){
        return 0;
    }

    Elemento *aux;
    aux = *pi;
    *pi = aux->prox;

    free(aux);

    return 1;
}

int verificarExpressaoPosfixa(Pilha *pi, char *string){
    int i, res, tam = strlen(string);
    int pos = 0;

    // Pilha auxiliar que vai armazenar os operandos
    char op[100];

    for(i = 0; i < tam; i++){
        // Variavel auxiliar para receber char atul
        char aux = string[i]; 

        if((aux >= 'a' && aux <= 'z') || (aux >= '0' && aux <= '9')){
            op[pos] = aux;
            pos++;
        }else {
            if(aux = '('){
                res = inserirElemento(pi, aux);
            }
        }
    }

    return 1;
}

void imprimirPilha(Pilha *pi){
    Elemento * aux = *pi;
    while(aux != NULL){
        printf(" %c", aux->dado);
        aux = aux->prox;
    }
}

