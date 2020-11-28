#include <stdlib.h>
#include <stdio.h>
#include "pilhaEncadeada.h"

int main(void){
    int opcao, escolha;
    char * expressao;
    Pilha *notPre = criarPilha(); //variavel pilha notacao prefixa
    Pilha *notInf = criarPilha(); //variavel pilha notacao infixa (normal)
    Pilha *notPos = criarPilha(); //variavel pilha notacao posfixa

    do {
        printf("\n\nMenu de opções");
        printf("\n1 - Calcular Expressão");
        printf("\n2 - Sair");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                    printf("\nEscolha qual notacão deseja utilizar:\n1 - Notação Préfixa\n2 - Notação Infixa\n3 - Notação Pósfixa\n");
                    printf("\nOpção: ");
                    scanf("%d", &escolha);

                break;
            
            default:
                break;
        }


    }while(opcao != 1000);

    return 0;
}