#include "Fila.h"

int main()
{
    srand(time(NULL));

    int tam;

    printf("Digite o tamanho da fila: ");
    scanf("%d", &tam);

    Fila f1;
    Fila f2;

    PreencherFila(&f1, tam);
    PreencherFila(&f2, tam);

    FImprime(&f1);
    FImprime(&f2);

    SwapFilas(&f1, &f2, tam);

    FImprime(&f1);
    FImprime(&f2);

    return 0;
}