#include "list_functions.h"
void FLVazia(Lista *l){
    l->cabeca=(Bloco*)malloc(sizeof(Bloco));
    l->cauda=l->cabeca;
    l->cauda->prox=NULL;
}
void insertLista(Lista *l,Item item){
    l->cauda->prox=(Bloco*)malloc(sizeof(Bloco));
    l->cauda=l->cauda->prox;
    l->cauda->dado=item;
    l->cauda->prox=NULL;
}
void preencheLista(Lista *l){
	char string[93]={'.','.','/','a','r','q','u','i','v','o','s','/'},arquivo[80];
	printf("Qual o nome do arquivo da lista dos numeros? (Max 80)\n");
	fgets(arquivo,80,stdin);
	arquivo[strlen(arquivo)-1]='\0';
    strcat(string,arquivo);
    FILE *f;
    int item;
    Item aux;
    if(!(f=fopen(string,"r"))){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    while(!feof (f)){
        fscanf(f,"%d",&item);
        l->cauda->prox=(Bloco*)malloc(sizeof(Bloco));
        l->cauda=l->cauda->prox;
        aux.value[0]=item;
        l->cauda->dado=aux;
        l->cauda->prox=NULL;
    }
    fclose(f);
}
void removeListaItem(Lista *l, int item){
    Bloco* aux, *freeBloco;
    aux=l->cabeca;
    while (aux->prox!=NULL)
    {
        if (aux->prox->dado.value[0]==item)
        {
            if (aux->prox==l->cauda)
            {
                free(aux->prox);
                aux->prox=NULL;
                l->cauda=aux;
            }
            else{
                freeBloco=aux->prox;
                aux->prox=aux->prox->prox;
                free(freeBloco);
            }
        }
        else{
            aux=aux->prox;
        }
    }
}
void printLista(Lista *l){
    Bloco* aux;
    aux=l->cabeca;
    while (aux->prox!=NULL)
    {
        printf("%d ",aux->prox->dado.value[0]);
        aux=aux->prox;
    }
    printf("\n");
}
void printLista2(Lista *l){
    Bloco* aux;
    aux=l->cabeca;
    while (aux->prox!=NULL)
    {
        printf("{%d, %d}",aux->prox->dado.value[0],aux->prox->dado.value[1]);
        aux=aux->prox;
    }
    printf("\n");
}



void countImpar(Lista *l,bool recursiva){
    int impar=0, par=0,tamanho=0;
    if (recursiva)
    {
        par=EvenNum(l->cabeca,&tamanho);
        impar=tamanho-par;
    }
    else{
        Bloco* aux;
        aux=l->cabeca;
        while (aux->prox!=NULL)
        {
            if(aux->prox->dado.value[0]%2==0)
                par++;
            else
                impar++;
            aux=aux->prox;
        }
    }
    printf("%d numeros pares, e %d numeros impares.\n",par,impar);
}
int EvenNum(Bloco* item, int* tamanho){
    if (item->prox==NULL) 
        return 0;
    int result;
    if ((item->prox->dado.value[0] % 2) == 0)
        result = 1;
    else
        result = 0;
    *tamanho+=1;
    return result + EvenNum(item->prox,tamanho);
}


void listaRand(){
    int l1[3],l2[3], item1,item2,soma1=0,soma2=0;
    for (int i = 0; i < 3; i++)
    {   
        l1[i]=(2+(rand()%11));
        l2[i]=(2+(rand()%11));
    }
    item1=(2+(rand()%11));
    item2=(2+(rand()%11));
    printf("Numeros aleatorios escolhidos: %d, %d\n", item1,item2);
    printf("{");
    for (int i = 0; i < 3; i++){
        printf("{%d,%d}",l1[i],l2[i]);
        soma1+=l1[i];
        soma2+=l2[i];
    }
    printf("}\n");
    soma1-=3*item1;
    soma2-=3*item2;
    if (soma1>soma2)
        printf("A lista 1 ganhou\n");
    else
        printf("A lista 2 ganhou\n");
    
}


void uneListasContrarias(Lista *l1,Lista *l2,Lista *l3){
    Bloco *aux;
    Item item;
    while (l1->cabeca->prox!=NULL)
    {
        aux=l2->cabeca;
        while(aux->prox!=l2->cauda)
            aux=aux->prox;
        item.value[0]=l1->cabeca->prox->dado.value[0];
        item.value[1]=aux->prox->dado.value[0];
        l1->cabeca=l1->cabeca->prox;
        l2->cauda=aux;
        insertLista(l3,item);
    }
    printLista2(l3);
}



void uneListas(Lista *l1,Lista *l2,Lista *l3){
    Item item;
    while (l1->cabeca->prox!=NULL)
    {
        item.value[0]=l1->cabeca->prox->dado.value[0];
        item.value[1]=l2->cabeca->prox->dado.value[0];
        l1->cabeca=l1->cabeca->prox;
        l2->cabeca=l2->cabeca->prox;
        insertLista(l3,item);
    }
    printLista2(l3);
    Bloco *aux;
    aux=l3->cabeca;
    while (aux->prox!=NULL)
    {
        aux->prox->dado.distancia=DistanciaEuclidiana(aux->prox->dado.value[0],aux->prox->dado.value[1]);

        aux=aux->prox;
    }
    

}
float DistanciaEuclidiana(int x, int y) {
	float distancia;
	distancia = sqrt((pow(x, 2) + pow(y, 2)));
	return distancia;
}