#include <stdio.h>
#include "expressao.h"

int main() {
    char expr[MAX];
    printf("Digite a expressão em notação pós-fixa: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = 0; // remove \n

    float resultado = getValorPosFixa(expr);
    printf("Resultado: %.2f\n", resultado);

    return 0;
}