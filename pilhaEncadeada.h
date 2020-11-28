#ifndef _PILHA
#define _PILHA

typedef struct elemento * Pilha;

Pilha criarPilha();
int liberarPilha(Pilha *pi);
int inserirElemento(Pilha *pi, char dado);

#endif