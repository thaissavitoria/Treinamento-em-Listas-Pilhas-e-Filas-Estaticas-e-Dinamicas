#include "PilhaEstatica.h"

void FPVazia3(Pilha3 *p3) {
    p3->top3 = 0;
    p3->base3 = 0;
}

void PUSH3(Pilha3 *p3, Item3 d3) {
    if (p3->top3 >= MAXTAM) {
        printf("PILHA CHEIA!\n");
    } else {
        p3->vet3[p3->top3] = d3;
        p3->top3++;
    }
}

void PImprime3(Pilha3 *p3) {
    printf("Operandos:\n");
    for (int i = p3->base3; i <= p3->top3-1; i++)
        printf("%d\n", p3->vet3[i].val3);
    printf("\n");
}



void FPVazia4(Pilha4 *p4) {
    p4->top4 = 0;
    p4->base4 = 0;
}

void PUSH2(Pilha4 *p4, Item4 d4) {
    if (p4->top4 >= MAXTAM) {
        printf("PILHA CHEIA!\n");
    } else {
        p4->vet4[p4->top4] = d4;
        p4->top4++;
    }
}

void PImprime4(Pilha4 *p4) {
     printf("Operadores:\n");
    for (int j = p4->base4; j <= p4->top4-1; j++)
        printf("%c\n", p4->vet4[j].val4);
    printf("\n");
}



void Verifica() {

    Pilha3 p3;
    Item3 aux3;

    Pilha4 p4;
    Item4 aux4;
    
    FPVazia3(&p3);
    FPVazia4(&p4);

    char funcao[TAM];

    printf("Informe uma função matemática: ");
    fgets(funcao, TAM-1, stdin);
    strtok(funcao, "\n");

    int tamanho = strlen(funcao);

    for (int i=0; i < tamanho; i++) {
        if (funcao[i] >= '0' && funcao[i] <= '9') {
            int aux2 = funcao[i] - '0';
            aux3.val3 = aux2;
            PUSH3(&p3, aux3);
        }
        else if (funcao[i] == '+' || funcao[i] == '-' || funcao[i] == '*' || funcao[i] == '/') {
            char aux3 = funcao[i];
            aux4.val4 = aux3;
            PUSH2(&p4, aux4);
        }
    }

    PImprime3(&p3);
    PImprime4(&p4);

}
