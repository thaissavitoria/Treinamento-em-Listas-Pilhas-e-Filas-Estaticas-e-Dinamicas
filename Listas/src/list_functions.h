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
    float distancia;
}Item;

struct Bloco{
    Item dado;
    Bloco *prox;
};

typedef struct Lista{
    Bloco* cabeca;
    Bloco* cauda;
}Lista;

typedef struct BlocoProximos BlocoProximos;
typedef struct ItemProximos{
    Item pares[2];
    float distancia;
}ItemProximos;

struct BlocoProximos{
    ItemProximos dado;
    BlocoProximos *prox;
};

typedef struct ListaProximos{
    BlocoProximos* cabeca;
    BlocoProximos* cauda;
}ListaProximos;

void FLVazia(Lista *l);
void insertLista(Lista *l,Item i);
void FLVaziaProximos(ListaProximos *l);
void insertListaProx(ListaProximos *l,ItemProximos i);
void preencheLista(Lista *l);
void removeListaItem(Lista *l, int item);
void printLista(Lista *l);
void printLista2(Lista *l);

void countImpar(Lista *l, bool recursiva);
int EvenNum(Bloco* item, int* tamanho);

void listaRand();

void uneListasContrarias(Lista *l1, Lista *l2,Lista *l3);

void uneListas(Lista *l1,Lista *l2,Lista *l3);
float DistanciaEuclidiana(int x, int y) ;

BlocoProximos* CaminharAteJ(ListaProximos* lista,BlocoProximos *auxj);
void swap(BlocoProximos* a,BlocoProximos* b);
#endif