#include "PilhaEstatica.h"

void FPEVazia(PilhaEst *pNum) {
    pNum->top = 0;
    pNum->base = 0;
}

void PUSHE(PilhaEst *pNum, ItemEst dNum) {
    if (pNum->top >= MAXTAM) {
        printf("PILHA CHEIA!\n");
    } else {
        pNum->vet[pNum->top] = dNum;
        pNum->top++;
    }
}

void PImprimeI(PilhaEst *pNum) {
    printf("Operandos:\n");
    for (int i = pNum->base; i <= pNum->top-1; i++)
        printf("%d\n", pNum->vet[i].val);
    printf("\n");
}

void PImprimeO(PilhaEst *pOpe) {
     printf("Operadores:\n");
    for (int j = pOpe->base; j <= pOpe->top-1; j++)
        printf("%c\n", pOpe->vet[j].val);
    printf("\n");
}

void Verifica() {

    PilhaEst pNum;
    ItemEst auxNum;

    PilhaEst pOpe;
    ItemEst auxOpe;
    
    FPEVazia(&pNum);
    FPEVazia(&pOpe);

    char funcao[TAM];

    printf("Informe uma função matemática: ");
    fgets(funcao, TAM-1, stdin);
    strtok(funcao, "\n");

    int tamanho = strlen(funcao);

    for (int i=0; i < tamanho; i++) {
        if (funcao[i] >= '0' && funcao[i] <= '9') {
            int aux2 = funcao[i] - '0';
            auxNum.val = aux2;
            PUSHE(&pNum, auxNum);
        }
        else if (funcao[i] == '+' || funcao[i] == '-' || funcao[i] == '*' || funcao[i] == '/') {
            char auxNum = funcao[i];
            auxOpe.val = auxNum;
            PUSHE(&pOpe, auxOpe);
        }
    }

    PImprimeI(&pNum);
    PImprimeO(&pOpe);

}
