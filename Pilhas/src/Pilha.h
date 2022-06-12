#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXTAM 20


typedef struct Item Item;
typedef struct Block Block;
typedef struct Pilha Pilha;

struct Item
{
    int value;
};

struct Block
{
    Item data;
    Block *prox;
};

struct Pilha
{
    Block *base;
    Block *top; 
    int maxnum;
};


void FPVazia(Pilha *p);
void Push(Pilha *p, Item d);
void Pop(Pilha *p, Item *d);
void PImprime(Pilha *p);

///Problema c
void PreencheP(Pilha *p);
void CalculaTotiente(int num);
int MDC(int a,int b);
void AplicaTotientePilha(Pilha *p);

///Problema d
void Fibonacci(int num,Pilha*p);
#endif