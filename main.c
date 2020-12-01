#include <stdlib.h>
#include <stdio.h>
#include "pilhaEncadeada.h"

int main(){
    char exp[] = "(32+49)*2";
    converteInfixoParaPosfixo(exp);

    return 0;
}