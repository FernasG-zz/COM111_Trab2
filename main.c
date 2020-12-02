#include <stdlib.h>
#include <stdio.h>
#include "pilhaEncadeada.h"
//#include "pilhaEncadeada.c"

int main()
{
    // char exp[] = "33 + 3 - 1";
    char exp[100];
    scanf("%[^\n]s", &exp);
    converteInfixo(exp);
    printf("%s\n", exp);
    printf("%d\n", resolvePosfixo(exp));

    return 0;
}