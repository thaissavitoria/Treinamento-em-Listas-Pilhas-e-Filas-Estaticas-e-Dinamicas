#include "PilhaDinamica.h"
#include "PilhaEstatica.h"

int main()
{
	///Problema c
	PilhaDinamica p1;
	FPVazia(&p1);

	///Problema d
	PilhaDinamica p2;
	FPVazia(&p2);

	int prob;

	////Problema d
	int num;

	do{
	printf("\nQual problema deseja testar? (para sair do programa, digite '0')");
	printf("\n\t1 - Recebe uma equação matemática e retorna duas pilhas.");
	printf("\n\t2 - Apresenta uma operação matemática em notação prefixa e posfixa.");
	printf("\n\t3 - Mostra primos entre si de cada valor de uma pilha aleatoriamente preenchida com valores de 0 a 99.");
	printf("\n\t4 - Fibonacci usando pilha.\n");
	printf("\nDigite a opção que deseja: ");
	scanf("%d",&prob);

	switch (prob)
	{
	case 1:
	 	setbuf(stdin,NULL);
		Verifica();
		break;

	case 2:
		
		break;

	case 3:
		PreencheP(&p1);

		printf("\n................Imprimindo Pilha.............\n");
		PImprime(&p1);

		printf("\n................Calculando primos entre si de cada elemento da pilha.............\n");
		AplicaTotientePilha(&p1);
		
		break;

	case 4:
		printf("\nDigite o número do qual deseja saber a sequência Fibonacci:\n");
		scanf("%d",&num);
		p2.maxnum=3;
		Fibonacci(num,&p2);

		printf("\n................Imprimindo Pilha.............\n");
		PImprime(&p2);

		int op;

		do{
			printf("\nDeseja saber a sequência de Fibonacci de outro número?\n\t0-Não;\n\t1-Sim.\n");
			scanf("%d",&op);

			if(op==1)
			{
				printf("\nDigite o número do qual deseja saber a sequência Fibonacci:\n");
				scanf("%d",&num);
				Fibonacci(num,&p2);
				printf("\n................Imprimindo Pilha.............\n");
				PImprime(&p2);
			}
		}while(op!=0);
		break;

	case 0:		
		break;
	
	default:
		printf("\nOpção inválida, por favor, escolha outra!\n");
		break;
	}
	}while(prob!=0);

	printf("\nObrigada por utilizar o programa! :)\n");


	return 0;
}
