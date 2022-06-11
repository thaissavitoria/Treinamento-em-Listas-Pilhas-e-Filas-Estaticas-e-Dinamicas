#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Fila Fila;

struct Item
{
    int val;
};

struct Block
{
    Item data;
    Block *prox;
};

struct Fila
{
    Block *first;
    Block *last;
};

void FFVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f, Item *d);
void PreencherFila(Fila *f, int tam);
void SwapFilas(Fila *f1, Fila *f2, int tam);
void FImprime(Fila *f);

#endif