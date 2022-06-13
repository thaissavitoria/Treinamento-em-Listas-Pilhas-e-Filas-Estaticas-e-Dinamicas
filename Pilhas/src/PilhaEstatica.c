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

void PUSH4(Pilha4 *p4, Item4 d4) {
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
            PUSH4(&p4, aux4);
        }
    }

    PImprime3(&p3);
    PImprime4(&p4);

}

void iniciaPilha(PILHA *pilha) {

    pilha->top = 0;
}

void iniciaPilha2(PILHA2 *pilha) {

    pilha->top2 = 0;
}

void PUSH(PILHA *pilha, char valor) {
    if (!(pilhaCheia(pilha))) {
        (pilha->top)++;
        pilha->dados[pilha->top] = valor;
    }
}

char POP(PILHA *pilha) {

    char c;

    if (!(pilhaVazia(pilha))) {
        c = pilha->dados[pilha->top];
        (pilha->top)--;
        return c;
    }

    else
        return '\0';
}

void PUSH2(PILHA2 *pilha, char valor) {

    if (!(pilhaCheia2(pilha))) {
        (pilha->top2)++;

        pilha->dados2[pilha->top2] = valor;
    }
}

char POP2(PILHA2 *pilha) {

    char c;

    if (!(pilhaVazia2(pilha))) {

        c = pilha->dados2[pilha->top2];
        (pilha->top2)--;

        return c;
    }

    else
        return '\0';
}

void Infixo(char infixo[]) {

    int i;

    printf("Informe a função infixa: ");

    fflush(stdin);

    for (i = 0; i < 18;) {

        if ((infixo[i] = getchar()) == '\n') {
            i++;
            break;
        }

        else if (!(isspace(infixo[i])))
            i++;
    }

    infixo[i] = '\0';
}

void Posfixo(char infixo[], char posfixo[]) {

    int i, tamanho;
    int j = 0;
    char top_ch;

    PILHA pilha;

    iniciaPilha(&pilha);

    Infixo(infixo);

    tamanho = strlen(infixo);

    if (tamanho) {

        PUSH(&pilha, '(');
        strcat(infixo, ")");

        tamanho++;

        for (i = 0; i < tamanho; i++) {

            if (isdigit(infixo[i])) {
                posfixo[j++] = infixo[i];
            }

            else if (infixo[i] == '(') {
                PUSH(&pilha, '(');
            }

            else if (operadores(infixo[i])) {

                while (VERDADEIRO) {

                    top_ch = topoDaPilha(&pilha);

                    if (top_ch == '\0') {

                        printf("\nFunção inválida\n");

                        exit(1);
                    }

                    else {

                        if (operadores(top_ch)) {

                            if (prioridadeNivel(top_ch) >= prioridadeNivel(infixo[i]))
                                posfixo[j++] = POP(&pilha);

                            else
                                break;
                        }

                        else
                            break;
                    }
                }

                PUSH(&pilha, infixo[i]);
            }

            else if (infixo[i] == ')') {

                while (VERDADEIRO) {

                    top_ch = topoDaPilha(&pilha);

                    if (top_ch == '\0') {
                        printf("\nFunçaõ inválida\n");
                        exit(1);
                    }

                    else {

                        if (top_ch != '(') {
                            posfixo[j++] = top_ch;
                            POP(&pilha);
                        }

                        else {
                            POP(&pilha);
                            break;
                        }
                    }
                }

                continue;
            }
        }
    }

    posfixo[j] = '\0';
}

int Prefixo(char infixo[], char prefixo[]) {

    int i, tamanho;
    int j = 0;
    char top_ch;

    PILHA2 pilha;

    iniciaPilha2(&pilha);

    tamanho = strlen(infixo);

    j = tamanho;

    if (tamanho) {

        PUSH2(&pilha, '(');
        strcat(infixo, ")");

        tamanho++;

        for (i = 0; i < tamanho; i++) {

            if (isdigit(infixo[i])) {
                prefixo[j--] = infixo[i];
            }

            else if (infixo[i] == '(') {
                PUSH2(&pilha, '(');
            }

            else if (operadores(infixo[i])) {

                while (VERDADEIRO) {

                    top_ch = topoDaPilha2(&pilha);

                    if (top_ch == '\0') {
                        printf("\nFunção inválida\n");
                        exit(1);
                    }

                    else {

                        if (operadores(top_ch)) {

                            if (prioridadeNivel(top_ch) >= prioridadeNivel(infixo[i]))
                                prefixo[j--] = POP2(&pilha);

                            else
                                break;
                        }

                        else
                            break;
                    }
                }

                PUSH2(&pilha, infixo[i]);
            }

            else if (infixo[i] == ')') {

                while (VERDADEIRO) {

                    top_ch = topoDaPilha2(&pilha);

                    if (top_ch == '\0') {
                        printf("\nFunçaõ inválida\n");
                        exit(1);
                    }

                    else {

                        if (top_ch != '('){
                            prefixo[j--] = top_ch;
                            POP2(&pilha);
                        }

                        else {
                            POP2(&pilha);
                            break;
                        }
                    }
                }

                continue;
            }
        }
    }

    return j;
}

int operadores(char o) {

    if (o == '+' || o == '-' || o == '*' || o == '/' || o == '%' || o == '^') {
        return VERDADEIRO;
    }

    else
        return FALSO;
}

int prioridadeNivel(char p) {

    if (p == '+' || p == '-')
        return 1;

    else if (p == '^')
        return 3;

    else
        return 2;
}

int prioridade(char operador1, char operador2) {

    if (prioridadeNivel(operador1) > prioridadeNivel(operador2))
        return 1;

    else if (prioridadeNivel(operador1) < prioridadeNivel(operador2))
        return -1;

    else
        return 0;
}

char topoDaPilha(PILHA *pilha) {

    if (!(pilhaVazia(pilha)))
        return pilha->dados[pilha->top];

    else
        return '\0';
}

int pilhaVazia(PILHA *pilha) {

    if (pilha->top == -1)
        return VERDADEIRO;

    else
        return FALSO;
}

int pilhaCheia(PILHA *pilha) {

    if (pilha->top == 19)
        return VERDADEIRO;

    else
        return FALSO;
}

char topoDaPilha2(PILHA2 *pilha) {

    if (!(pilhaVazia2(pilha)))
        return pilha->dados2[pilha->top2];

    else
        return '\0';
}

int pilhaVazia2(PILHA2 *pilha) {

    if (pilha->top2 == -1)
        return VERDADEIRO;

    else
        return FALSO;
}

int pilhaCheia2(PILHA2 *pilha) {

    if (pilha->top2 == 19)
        return VERDADEIRO;

    else
        return FALSO;
}

void result(char posfixo[]) {
    printf("\nFunção Posfixa: %s\n\n", posfixo);
}

void result2(char prefixo[], int j) {

    printf("\nFunção Posfixa: ");

    for (int i = j; i < 20; i++) {
        printf("%c", prefixo[i]);
    }
}
