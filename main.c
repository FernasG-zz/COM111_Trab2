#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilhaEncadeada.h"

int main(int argc, char *argv[]){
    int opcao, escolha, res;
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
                    printf("\nEscolha qual notacão deseja verificar:\n1 - Notação Préfixa\n2 - Notação Pósfixa\n");
                    printf("Opção: ");
                    scanf("%d", &escolha);

                    printf("\nInsira a expressão: ");
                    //fgets(expressao, sizeof(expressao), stdin);
                    scanf("%s", expressao);

                    res = verificarExpressaoPosfixa(notPos, expressao);

                break;
            
            default:
                break;
        }


    }while(opcao != 1000);

    return 0;
}