#include <stdlib.h>
#include <stdio.h>
#include "pilhaEncadeada.h"

int main(void){
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
                    scanf(" %s", expressao);

                    if(escolha == 1){
                        res = inserirExpressaoPilha(notPre, expressao);
                    }else if(escolha == 2){
                        res = verificarExpressaoPosfixa(notInf, expressao);
                    }else {
                        printf("Valor Inválido!");
                        break;
                    }

                    imprimirPilha(notPre);


                break;
            
            default:
                break;
        }


    }while(opcao != 1000);

    return 0;
}