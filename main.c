#include <stdlib.h>
#include <stdio.h>
#include "pilhaEncadeada.h"
#include "pilhaEncadeada.c"

int main()
{
    char exp[] = "33 + 3 - 1";
    converteInfixoParaPosfixo(exp);
    printf("%s\n", exp);
    printf("%d\n", resolverPosfixo(exp));

    return 0;
}