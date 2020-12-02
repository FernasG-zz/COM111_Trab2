#ifndef _PILHA
#define _PILHA

typedef struct elemento Pilha;

// Funcoes básicas da pilha
Pilha *criarPilha(unsigned capacidade);
int verificaVazio(Pilha *pi);
char consultarTopo(Pilha *pi);
char removerElemento(Pilha *pi);
void inserirElemento(Pilha *pi, char op);

// Funcoes para avaliacao
int verificaOperando(char valor);
int verificaPrecedencia(char valor);

int converteInfixo(char *exp);
int resolvePosfixo(char *exp);

#endif