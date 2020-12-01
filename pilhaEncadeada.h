#ifndef _PILHA
#define _PILHA

typedef struct elemento Pilha;  

// Funcoes básicas da pilha
Pilha * criarPilha(unsigned capacidade);
int estaVazio(Pilha *pi);
char consultarTopo(Pilha *pi);
char removerElemento(Pilha *pi);
void inserirElemento(Pilha *pi, char op);

// Funcoes para avaliacao
char *tradutorExpressao(char *exp);
int eOperando(char valor);
int verificaPrecedencia(char valor);
int converteInfixoParaPosfixo(char *exp);

#endif