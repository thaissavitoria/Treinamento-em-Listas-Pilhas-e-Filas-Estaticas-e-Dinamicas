#include "Fila.h"

void FFVazia(Fila *f)
{
    f->first = (Block *)malloc(sizeof(Block));
    f->last = f->first;
    f->first->prox = NULL;
}

void Enfileira(Fila *f, Item d)
{
    f->last->prox = (Block *)malloc(sizeof(Block));
    f->last = f->last->prox;
    f->last->data = d;
    f->last->prox = NULL;
}

void Desenfileira(Fila *f, Item *d)
{
    Block *aux;

    if (f->first == f->last || f == NULL || f->first->prox == NULL)
    {
        printf("FILA VAZIA!\n");
        return;
    }

    aux = f->first->prox;
    f->first->prox = aux->prox;
    if (f->first->prox == f->last)
        f->last = f->first;
    d->val = aux->data.val;
    free(aux);
}

void PreencherFila(Fila *f, int tam, int choice)
{
    FFVazia(f);
    Item aux;

    for (int i = 0; i < tam; i++)
    {
        aux.val = rand() % 99;
        if (choice == 2)
            aux.calc = aux.val * 2 + 1;
        Enfileira(f, aux);
    }
}

void SwapFilas(Fila *f1, Fila *f2, int tam, int choice)
{
    Block *a;
    Block *b;

    a = f1->first->prox;
    b = f2->first->prox;

    int metade = tam / 2;
    int cont = 1;

    while (a != NULL && b != NULL)
    {
        if (cont > metade)
        {
            if (choice == 2)
                SwapCalc(a, b);
            SwapVal(a, b);
        }
        a = a->prox;
        b = b->prox;
        cont++;
    }
    printf("\n");
}

void SwapCalc(Block *a, Block *b)
{
    Item aux;
    aux.calc = a->data.calc;
    a->data.calc = b->data.calc;
    b->data.calc = aux.calc;
}

void SwapVal(Block *a, Block *b)
{
    Item aux;
    aux.val = a->data.val;
    a->data.val = b->data.val;
    b->data.val = aux.val;
}

void MetodoBolhaInterativo(Fila *f)
{

    Block *a, *aux;
    Block *b;

    a = f->first->prox;
    aux = a;
    b = a;

    while (a != NULL)
    {
        while (b != NULL)
        {
            if (a->data.calc < b->data.calc)
            {
                SwapCalc(a, b);
            }
            if (a->data.val < b->data.val)
            {
                SwapVal(a, b);
            }
            b = b->prox;
        }
        b = f->first->prox;
        aux = aux->prox;
        a = aux;
    }
}

void FImprime(Fila *f, int choice)
{
    Block *aux;

    aux = f->first->prox;
    while (aux != NULL)
    {
        printf("%d ", aux->data.val);
        aux = aux->prox;
    }

    if (choice == 2)
    {
        printf("\n");
        aux = f->first->prox;
        while (aux != NULL)
        {
            printf("%d ", aux->data.calc);
            aux = aux->prox;
        }
    }

    printf("\n");
}