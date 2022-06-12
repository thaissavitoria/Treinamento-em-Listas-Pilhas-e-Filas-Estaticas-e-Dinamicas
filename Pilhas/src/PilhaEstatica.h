#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXTAM 10
#define TAM 100


typedef struct Item3 {
    int val3;
} Item3;

typedef struct Pilha3 {
    Item3 vet3[MAXTAM];
    int top3;
    int base3;
} Pilha3;

void FPVazia3(Pilha3 *p3);
void PUSH3(Pilha3 *p3, Item3 d3);
void PImprime3(Pilha3 *p3);


typedef struct Item4 {
    int val4;
} Item4;

typedef struct Pilha4 {
    Item4 vet4[MAXTAM];
    int top4;
    int base4;
} Pilha4;

void FPVazia4(Pilha4 *p4);
void PUSH4(Pilha4 *p4, Item4 d4);
void PImprime4(Pilha4 *p4);

void Verifica();

#endif