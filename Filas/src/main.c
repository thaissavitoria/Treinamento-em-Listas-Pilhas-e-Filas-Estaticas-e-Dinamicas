#include "Fila.h"

int main()
{
    srand(time(NULL));

    Fila f, f1, f2;

    int tam, choice;

    printf("Digite o tamanho da fila: ");
    scanf("%d", &tam);

    while (choice != 3)
    {
        printf("Escolha uma opção: \n");
        printf("1-Inveter metade das listas\n2-Ordenar filas após um cálculo\n3-Sair do programa\nEscolha: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            PreencherFila(&f1, tam, choice);
            PreencherFila(&f2, tam, choice);

            FImprime(&f1, choice);
            FImprime(&f2, choice);

            SwapFilas(&f1, &f2, tam, choice);

            FImprime(&f1, choice);
            FImprime(&f2, choice);

            break;

        case 2:

            PreencherFila(&f, tam, choice);

            FImprime(&f, choice);

            MetodoBolhaInterativo(&f);
            printf("\n");

            FImprime(&f, choice);

            break;

        case 3:

            printf("Saindo do programa.\n");
            break;

        default:
            printf("Digite um valor válido.\n");
        }
    }

    return 0;
}