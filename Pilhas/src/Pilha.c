#include "Pilha.h"

void FPVazia(Pilha *p)
{
	p->base = (Block *)malloc(sizeof(Block));
	p->top = p->base;
	p->base->prox = NULL;
}

void Push(Pilha *p, Item d)
{
	Block *aux = (Block *)malloc(sizeof(Block));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}

void Pop(Pilha *p, Item *d)
{
	Block *aux;

	if (p->base == p->top || p == NULL)
	{
		return;
	}

	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
	free(aux);
}
///Problema a

///Problema c
void PreencheP(Pilha *p)
{
	Item aux;
	srand(time(NULL));

	for(int i=0;i<MAXTAM;i++)
	{
		aux.value= rand()%99;
		Push(p,aux);
	}
}

void CalculaTotiente(int num)
{
	int coprimos=0;

	printf("\nOs primos entre si do número %02d são:",num);

		for(int i=1;i<num;i++)
		{
			if(MDC(i,num)==1)
			{
				printf(" %02d ",i);
				coprimos++;
			}
		}
	printf("\nO número primos entre si que foi calculado é de %02d.\n",coprimos);
	printf("\n");
}

int MDC(int a,int b)
{
	if(a==0)
		return b;
	return MDC((b%a),a);
}

void AplicaTotientePilha(Pilha *p)
{
	Block *aux;

	aux = p->top;
	while (aux != p->base)
	{
		CalculaTotiente(aux->data.value);
		aux = aux->prox;
	}
}

////Problema d
void PImprime(Pilha *p)
{
	Block *aux;


	aux = p->top;
	while (aux != p->base)
	{
		printf("%d\n",aux->data.value);
		aux = aux->prox;
	}
}

void Fibonacci(int num,Pilha*p)
{
	Item num1,num2,soma;

	if((p->maxnum)==3)
	{
		num1.value=1;
		num2.value=1;
		
		Push(p,num1);
		Push(p,num2);
	}

	Item d;

	if(p->maxnum<num)
	{
		for(int i=p->maxnum;i<num;i++)
		{
			num2.value=p->top->data.value;
			Pop(p,&d);

			num1.value=p->top->data.value;
			Pop(p,&d);

			soma.value=num1.value+num2.value;

			Push(p,num1);
			Push(p,num2);
			Push(p,soma);
		}
		printf("\nO Fibonacci de %d é %d.",num,soma.value);
		p->maxnum=num;
	}
	else
	{
		Block *aux;

		aux = p->top;

		for (int i=p->maxnum;i>num;i--)
		{
			aux=aux->prox;
		}

		printf("\nO Fibonacci de %d é %d.",num,aux->data.value);

	}
}
