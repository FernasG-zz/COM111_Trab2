#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilhaEncadeada.h"

int inserirExpressaoPilha(Pilha *pi, char *string){
    int tam, res;
    tam = strlen(string);

    for(int i = 0; i < tam; i++){
        res = inserirElemento(pi, string[i]);

        if(res == 0){
            return 0;
        }
    }

    return 1;
}

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
                    printf("\nEscolha qual notacão deseja utilizar:\n1 - Notação Préfixa\n2 - Notação Infixa\n3 - Notação Pósfixa\n");
                    printf("Opção: ");
                    scanf("%d", &escolha);

                    printf("\nInsira a expressão: ");
                    scanf(" %s", expressao);

                    if(escolha == 1){
                        res = inserirExpressaoPilha(notPre, expressao);
                    }else if(escolha == 2){
                        res = inserirExpressaoPilha(notInf, expressao);
                    }else if(escolha == 3){
                        res = inserirExpressaoPilha(notPos, expressao);
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