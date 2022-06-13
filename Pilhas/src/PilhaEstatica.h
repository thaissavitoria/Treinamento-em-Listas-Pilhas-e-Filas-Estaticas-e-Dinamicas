#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXTAM 10
#define TAM 100

typedef struct {
    char dados[20];
    int top;
} PILHA;


typedef struct ItemEst {
    int val;
} ItemEst;

typedef struct PilhaEst {
    ItemEst vet[MAXTAM];
    int top;
    int base;
} PilhaEst;

void FPEVazia(PilhaEst *p3);
void PUSHE(PilhaEst *p3, ItemEst d3);
void PImprimeI(PilhaEst *p3);
void PImprimeO(PilhaEst *p4);

void Verifica();


void iniciaPilha(PILHA *pilha);
void Infixo(char infixo[]);
void Posfixo(char infixo[], char posfixo[]);
bool operadores(char c);
int prioridadeNivel(char ch);
void PUSH(PILHA *pilha, char val);
char POP(PILHA *pilha);
char topoDaPilha(PILHA *pilha);
bool pilhaVazia(PILHA *pilha);
bool pilhaCheia(PILHA *pilha);
void result(char posfixo[]);

int Prefixo(char infixo[], char prefixo[]);
void result2(char prefixo[], int j);

#endif
