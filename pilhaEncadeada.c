#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilhaEncadeada.h"

typedef struct elemento
{
    int topo;
    unsigned capacidade;
    int *vetor;
} Elemento;

Pilha *criarPilha(unsigned capacidade)
{
    Pilha *pi = (Pilha *)malloc(sizeof(Pilha));

    if (!pi)
        return 0;

    pi->topo = -1;
    pi->capacidade = capacidade;
    pi->vetor = (int *)malloc(pi->capacidade * sizeof(int));

    return pi;
}

int verificaVazio(Pilha *pi)
{
    return pi->topo == -1;
}

char consultarTopo(Pilha *pi)
{
    return pi->vetor[pi->topo];
}

char removerElemento(Pilha *pi)
{
    if (!verificaVazio(pi))
        return pi->vetor[pi->topo--];
    return '$';
}

void inserirElemento(Pilha *pi, char op)
{
    pi->vetor[++pi->topo] = op;
}

int verificaOperando(char valor)
{
    return (valor >= '0' && valor <= '9');
}

int verificaPrecedencia(char valor)
{
    switch (valor)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

// funcao converter expressao em formato
// infixo para o formato posfixo
int converteInfixo(char *exp)
{
    int i, k;

    Pilha *pilha = criarPilha(strlen(exp));
    if (!pilha)
        return 0;

    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (verificaOperando(exp[i]) || exp[i] == ' ')
            exp[++k] = exp[i];

        else if (exp[i] == '(')
            inserirElemento(pilha, exp[i]);

        else if (exp[i] == ')')
        {
            while (!verificaVazio(pilha) && consultarTopo(pilha) != '(')
                exp[++k] = removerElemento(pilha);

            if (!verificaVazio(pilha) && consultarTopo(pilha) != '(')
                return -1;

            else
                removerElemento(pilha);
        }
        else
        {
            while (!verificaVazio(pilha) && verificaPrecedencia(exp[i]) <= verificaPrecedencia(consultarTopo(pilha)))
                exp[++k] = removerElemento(pilha);

            inserirElemento(pilha, exp[i]);
        }
    }

    while (!verificaVazio(pilha))
        exp[++k] = removerElemento(pilha);

    exp[++k] = '\0';
}

int resolvePosfixo(char *exp)
{
    Pilha *pilha = criarPilha(strlen(exp));
    int i;

    if (!pilha)
        return -1;

    for (i = 0; exp[i]; ++i)
    {
        if (exp[i] == ' ')
            continue;

        else if (verificaOperando(exp[i]))
        {
            int num = 0;

            while (verificaOperando(exp[i]))
            {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;

            inserirElemento(pilha, num);
        }

        else
        {
            int val1 = removerElemento(pilha);
            int val2 = removerElemento(pilha);

            switch (exp[i])
            {
            case '+':
                inserirElemento(pilha, val2 + val1);
                break;
            case '-':
                inserirElemento(pilha, val2 - val1);
                break;
            case '*':
                inserirElemento(pilha, val2 * val1);
                break;
            case '/':
                inserirElemento(pilha, val2 / val1);
                break;
            }
        }
    }
    return removerElemento(pilha);
}
