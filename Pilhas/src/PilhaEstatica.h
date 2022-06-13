#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXTAM 10
#define TAM 100

#define VERDADEIRO 1
#define FALSO 0

typedef struct {
    char dados[20];
    int top;
} PILHA;

typedef struct {
    char dados2[20];
    int top2;
} PILHA2;


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

void iniciaPilha(PILHA *pilha);
void Infixo(char infixo[]);
void Posfixo(char infixo[], char posfixo[]);
int operadores(char c);
int prioridade(char operador1, char operador2);
int prioridadeNivel(char ch);
void PUSH(PILHA *pilha, char val);
char POP(PILHA *pilha);
char topoDaPilha(PILHA *pilha);
int pilhaVazia(PILHA *pilha);
int pilhaCheia(PILHA *pilha);
void result(char posfixo[]);



void iniciaPilha2(PILHA2 *pilha);
int Prefixo(char infixo[], char prefixo[]);
void PUSH2(PILHA2 *pilha, char val);
char POP2(PILHA2 *pilha);
char topoDaPilha2(PILHA2 *pilha);
int pilhaVazia2(PILHA2 *pilha);
int pilhaCheia2(PILHA2 *pilha);
void result2(char prefixo[], int j);

#endif
