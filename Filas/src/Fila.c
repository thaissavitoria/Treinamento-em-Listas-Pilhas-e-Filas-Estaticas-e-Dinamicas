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

void PreencherFila(Fila *f, int tam)
{
    FFVazia(f);
    Item aux;

    for (int i = 0; i < tam; i++)
    {
        aux.val = rand() % 99;
        Enfileira(f, aux);
    }
}

void SwapFilas(Fila *f1, Fila *f2, int tam)
{
    Block *a;
    Block *b;

    Item aux;

    a = f1->first->prox;
    b = f2->first->prox;

    int metade = tam / 2;
    int cont = 1;

    while (a != NULL && b != NULL)
    {

        if (cont > metade)
        {
            aux = a->data;
            a->data = b->data;
            b->data = aux;
        }
        a = a->prox;
        b = b->prox;
        cont++;
    }
    printf("\n");
}

void FImprime(Fila *f)
{
    Block *aux;

    aux = f->first->prox;
    while (aux != NULL)
    {
        printf("%d ", aux->data.val);
        aux = aux->prox;
    }
    printf("\n");
}