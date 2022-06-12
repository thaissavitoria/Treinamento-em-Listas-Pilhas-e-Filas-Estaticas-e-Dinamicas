#include "list_functions.h"

int main(){
	Lista l1,l2,l3;
	char opcao,temp[80];
	do
	{
		FLVazia(&l1);
		FLVazia(&l2);
		FLVazia(&l3);
		printf("O que deseja fazer?\n\ta-Quantidade par e impar\n\tb-Jogo randomico\n\tc-Unir listas\n\td-Pares mais próximos\n\t0-Sair\n");
		scanf(" %c",&opcao);
		switch (opcao)
		{
		case 'a':
			fgets(temp,80,stdin);
			preencheLista(&l1);
			printf("Deseja usar:\n\ta-Funcao recursiva\n\tb-Funcao nao recursiva\n");
			scanf(" %c",&opcao);
			if (opcao=='a')
				countImpar(&l1,true);
			else
				countImpar(&l1,false);
			
			break;
		case 'b':
			listaRand();
			break;
		case 'c':
			fgets(temp,80,stdin);
			preencheLista(&l1);
			preencheLista(&l2);
			uneListasContrarias(&l1,&l2,&l3);
			break;
		case 'd':
			fgets(temp,80,stdin);
			preencheLista(&l1);
			preencheLista(&l2);
			uneListas(&l1,&l2,&l3);
			break;
		case '0':
			printf("Saindo\n");
			break;
		default:
			break;
		}
	}while (opcao!='0');
	return 0;
}
