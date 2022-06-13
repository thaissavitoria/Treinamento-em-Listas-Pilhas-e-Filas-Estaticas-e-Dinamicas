#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

///Problema c
#define MAXTAMC 20


typedef struct Item Item;
typedef struct Block Block;
typedef struct PilhaDinamica PilhaDinamica;

struct Item
{
    int value;
};

struct Block
{
    Item data;
    Block *prox;
};

struct PilhaDinamica
{
    Block *base;
    Block *top; 
};


void FPVazia(PilhaDinamica *p);
void Push(PilhaDinamica *p, Item d);
void Pop(PilhaDinamica *p, Item *d);
void PImprime(PilhaDinamica *p);

///Problema c
void PreencheP(PilhaDinamica *p);
void CalculaTotiente(int num);
int MDC(int a,int b);
void AplicaTotientePilha(PilhaDinamica *p);

///Problema d
void Fibonacci(int num,PilhaDinamica*p);
void ImprimePMenor(PilhaDinamica*p,int num);
#endif