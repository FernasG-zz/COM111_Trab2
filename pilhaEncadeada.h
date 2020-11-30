#ifndef _PILHA
#define _PILHA

typedef struct elemento * Pilha;

// Funcoes basicas de TAD pilha Encadeada
Pilha *criarPilha();
int liberarPilha(Pilha *pi);
int removerElemento(Pilha *pi);
int inserirElemento(Pilha *pi, char dado);
int consultarTopoPilha(Pilha *pi, char *dado);
void imprimirPilha(Pilha *pi);

// Função de Verificacao
int verificarExpressaoPosfixa(Pilha *pi, char *string);

#endif