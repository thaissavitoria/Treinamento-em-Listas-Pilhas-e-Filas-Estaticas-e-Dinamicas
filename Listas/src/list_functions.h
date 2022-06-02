#ifndef LIST_FUNCTIONS
#define LIST_FUNCTIONS

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bloco Bloco;
typedef struct Item{
    int value[2];
}Item;

struct Bloco{
    Item dado;
    Bloco *prox;
};

typedef struct Lista{
    Bloco* cabeca;
    Bloco* cauda;
}Lista;

void FLVazia(Lista *l);
void insertLista(Lista *l,Item i);
void preencheLista(Lista *l);
void removeListaItem(Lista *l, int item);
void printLista(Lista *l);

void countImpar(Lista *l, bool recursiva);
int EvenNum(Bloco* item, int* tamanho);

void listaRand();

void uneListasContrarias(Lista *l1, Lista *l2,Lista *l3);

float DistanciaEuclidiana(int x1, int y1, int x2, int y2) ;
#endif