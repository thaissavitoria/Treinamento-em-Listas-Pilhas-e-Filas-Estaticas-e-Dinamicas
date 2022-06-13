#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXTAM 10
#define TAM 100


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
void PImprimeO(PilhaEst *p3);


void Verifica();

#endif