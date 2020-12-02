#include <stdlib.h>
#include <stdio.h>
#include "pilhaEncadeada.h"
#include "pilhaEncadeada.c"

int main()
{
    int opcao;
    char exp[100];

    do
    {
        printf("\n\nMenu de Opções: ");
        printf("\n1 - Calcular Expressão Préfixa");
        printf("\n2 - Calcular Expressão Infixa");
        printf("\n3 - Calcular Expressão Pósfixa");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nExpressão: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", exp);

            break;

        case 2:
            printf("\nExpressão: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", exp);
            converteInfixo(exp);
            printf("%d\n", resolvePosfixo(exp));

            break;

        case 3:
            printf("\nExpressão: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", exp);
            printf("%d\n", resolvePosfixo(exp));

            break;

        default:
            break;
        }

    } while (opcao != 4);

    return 0;
}