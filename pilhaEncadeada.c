#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilhaEncadeada.h"

// Declaracao de um elemento da pilha
struct elemento
{
    int topo;
    unsigned capacidade;
    int *vetor;
};

// Funcao que cria a pilha
Pilha *criarPilha(unsigned capacidade)
{
    // Aloca a memoria da pilha
    Pilha *pi = (Pilha *)malloc(sizeof(Pilha));

    // verifica se a pilha foi criada corretamente
    if (!pi)
        return 0;

    // Preenche o primeiro elemento da pilha
    pi->topo = -1;
    // Tamanho da expressao
    pi->capacidade = capacidade;
    //
    pi->vetor = (int *)malloc(pi->capacidade * sizeof(int));

    if (!pi->vetor)
        return NULL;

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

// Funcao para retornar o valor de acordo
// com a precedencia de cada operacao
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

    // Cria a pilha
    Pilha *pilha = criarPilha(strlen(exp));

    // Verifica se a pilha foi criada corretamente
    if (!pilha)
        return 0;

    for (i = 0, k = -1; exp[i]; ++i)
    {
        // Se o caractere lido for um operando
        // ou vazio, adiciona ao output
        if (verificaOperando(exp[i]) || exp[i] == ' ')
            exp[++k] = exp[i];

        // Se o caractere lido for um '(', insere na pilha
        else if (exp[i] == '(')
            inserirElemento(pilha, exp[i]);

        // Se o caractere lido for um ')', remove da pilha
        // colocando no output até que se encontre '('
        else if (exp[i] == ')')
        {
            while (!verificaVazio(pilha) && consultarTopo(pilha) != '(')
                exp[++k] = removerElemento(pilha);

            // Verifica expressao invalida
            if (!verificaVazio(pilha) && consultarTopo(pilha) != '(')
                return -1;

            else
                removerElemento(pilha);
        }
        else // Caractere lido e um operador
        {    // Equanto a pilha estiver cheia & A ordem de precedencia for mantida
            while (!verificaVazio(pilha) && verificaPrecedencia(exp[i]) <= verificaPrecedencia(consultarTopo(pilha)))
                exp[++k] = removerElemento(pilha);

            inserirElemento(pilha, exp[i]);
        }
    }

    // Remove todos os elementos da pilha para o output
    while (!verificaVazio(pilha))
        exp[++k] = removerElemento(pilha);

    // Marca o final da string
    exp[++k] = '\0';
}

// Resolve expressoes com notacao prefixa
int resolvePrefixo(char *exp)
{
    // Cria a pilha
    Pilha *pilha = criarPilha(strlen(exp));

    // Verifica se a pilha foi criada corretamente
    if (!pilha)
        return 0;

    char res;

    // Percorre a entrada da direita para a esqueda
    for (int i = strlen(exp) - 1; i >= 0; i--)
    {
        // Continua o loop caso encontre um espaço vazio
        if (exp[i] == ' ')
            continue;

        // Se caractere lido for operando
        else if (verificaOperando(exp[i]))
        {
            // O mesmo e inserido na pilha
            // Tambem converte o char para digito
            inserirElemento(pilha, exp[i] - '0');
        }
        else
        {
            // pega os valores do topo da pilha
            int op1 = removerElemento(pilha);
            int op2 = removerElemento(pilha);

            // operacoes
            switch (exp[i])
            {
            case '+':
                inserirElemento(pilha, op1 + op2);
                break;
            case '-':
                inserirElemento(pilha, op1 - op2);
                break;
            case '*':
                inserirElemento(pilha, op1 * op2);
                break;
            case '/':
                inserirElemento(pilha, op1 / op2);
                break;
            }
        }
    }

    // resultado da expressao = topo da pilha
    return consultarTopo(pilha);
}

int resolvePosfixo(char *exp)
{
    // Cria a pilha
    Pilha *pilha = criarPilha(strlen(exp));

    // Verifica se a pilha foi criada corretamente
    if (!pilha)
        return 0;

    // Percorre a entrada da esquerda para a direita
    for (int i = 0; exp[i]; ++i)
    {
        // Continua o loop caso encontre um espaço vazio
        if (exp[i] == ' ')
            continue;

        // Se operando
        else if (verificaOperando(exp[i]))
        {
            int num = 0;

            // Converte char para digito
            // Loop necessario para numeros com
            // 2 ou mais digitos
            while (verificaOperando(exp[i]))
            {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;

            inserirElemento(pilha, num);
        }

        else // Se operador
        {
            // pega os valores do topo da pilha
            int val1 = removerElemento(pilha);
            int val2 = removerElemento(pilha);

            // operacoes
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
