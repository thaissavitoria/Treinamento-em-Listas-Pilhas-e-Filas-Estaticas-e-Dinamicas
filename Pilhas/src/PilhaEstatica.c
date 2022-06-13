#include "PilhaEstatica.h"

void FPEVazia(PilhaEst *p3) {
    p3->top = 0;
    p3->base = 0;
}

void PUSHE(PilhaEst *p3, ItemEst d3) {
    if (p3->top >= MAXTAM) {
        printf("PILHA CHEIA!\n");
    } else {
        p3->vet[p3->top] = d3;
        p3->top++;
    }
}

void PImprimeI(PilhaEst *p3) {
    printf("Operandos:\n");
    for (int i = p3->base; i <= p3->top-1; i++)
        printf("%d\n", p3->vet[i].val);
    printf("\n");
}

void PImprimeO(PilhaEst *p4) {
     printf("Operadores:\n");
    for (int j = p4->base; j <= p4->top-1; j++)
        printf("%c\n", p4->vet[j].val);
    printf("\n");
}



void Verifica() {

    PilhaEst p3,p4;
    ItemEst aux3,aux4;
    
    FPEVazia(&p3);
    FPEVazia(&p4);

    char funcao[TAM];

    printf("Informe uma função matemática: ");
    fgets(funcao, TAM-1, stdin);
    strtok(funcao, "\n");

    int tamanho = strlen(funcao);

    for (int i=0; i < tamanho; i++) {
        if (funcao[i] >= '0' && funcao[i] <= '9') {
            int aux2 = funcao[i] - '0';
            aux3.val = aux2;
            PUSHE(&p3, aux3);
        }
        else if (funcao[i] == '+' || funcao[i] == '-' || funcao[i] == '*' || funcao[i] == '/') {
            char aux3 = funcao[i];
            aux4.val = aux3;
            PUSHE(&p4, aux4);
        }
    }

    PImprimeI(&p3);
    PImprimeO(&p4);

}

void iniciaPilha(PILHA *pilha) {

    pilha->top = 0;
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

                while (true) {

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

                while (true) {

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

    PILHA pilha;

    iniciaPilha(&pilha);

    tamanho = strlen(infixo);

    j = tamanho;

    if (tamanho) {

        PUSH(&pilha, '(');
        strcat(infixo, ")");

        tamanho++;

        for (i = 0; i < tamanho; i++) {

            if (isdigit(infixo[i])) {
                prefixo[j--] = infixo[i];
            }

            else if (infixo[i] == '(') {
                PUSH(&pilha, '(');
            }

            else if (operadores(infixo[i])) {

                while (true) {

                    top_ch = topoDaPilha(&pilha);

                    if (top_ch == '\0') {
                        printf("\nFunção inválida\n");
                        exit(1);
                    }

                    else {

                        if (operadores(top_ch)) {

                            if (prioridadeNivel(top_ch) >= prioridadeNivel(infixo[i]))
                                prefixo[j--] = POP(&pilha);

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

                while (true) {

                    top_ch = topoDaPilha(&pilha);

                    if (top_ch == '\0') {
                        printf("\nFunçaõ inválida\n");
                        exit(1);
                    }

                    else {

                        if (top_ch != '('){
                            prefixo[j--] = top_ch;
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

    return j;
}

bool operadores(char o) {

    if (o == '+' || o == '-' || o == '*' || o == '/' || o == '%' || o == '^') {
        return true;
    }

    else
        return false;
}

int prioridadeNivel(char p) {

    if (p == '+' || p == '-')
        return 1;

    else if (p == '^')
        return 3;

    else
        return 2;
}

char topoDaPilha(PILHA *pilha) {

    if (!(pilhaVazia(pilha)))
        return pilha->dados[pilha->top];

    else
        return '\0';
}

bool pilhaVazia(PILHA *pilha) {

    if (pilha->top == -1)
        return true;

    else
        return false;
}

bool pilhaCheia(PILHA *pilha) {

    if (pilha->top == 19)
        return true;

    else
        return false;
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
