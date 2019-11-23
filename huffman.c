

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{   int tam;
	char* chave;
	float freq;
	struct no *esq, *dir;
	struct no *prox;
}   HUFFNo;
void criaarv(float *freq,char *nos,HUFFNo **h,int tam){
    for(int i=0;i<tam;i++){
    HUFFNo* novo=(HUFFNo*)malloc(sizeof(HUFFNo));
    novo->chave=(char*)malloc(sizeof(char*));
    novo->chave[0]=nos[i];
    novo->freq=freq[i];
    novo->esq=NULL;
    novo->dir=NULL;
    novo->prox=NULL;
    novo->tam=1;
    HUFFNo *aux=(*h);
    if(aux==NULL)(*h)=novo;
    else{
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    aux->prox=novo;
    }}
    while(tam!=1){
    int j=0;
    int k=0;
        HUFFNo* novo=(HUFFNo*)malloc(sizeof(HUFFNo));
        novo->prox=NULL;
        HUFFNo *aux1=(*h);
        HUFFNo *aux2=(*h)->prox;
        novo->chave=(char*)malloc(sizeof(char*)*(aux1->tam+aux2->tam));
        for( j;j<aux1->tam;j++){
            novo->chave[j]=aux1->chave[j];
        }
        for( k;k<aux2->tam;k++){
            novo->chave[j]=aux2->chave[k];
            j++;
        }
        novo->freq=aux1->freq+aux2->freq;
        novo->tam=aux1->tam+aux2->tam;
        novo->esq=aux1;
        novo->dir=aux2;
        HUFFNo *aux3=aux2->prox;
        int cont=0;
        while(cont!=-1){
                aux2=aux2->prox;
                aux1=aux1->prox;
                if(aux2==NULL){
                    (*h)=novo;
                    cont=-2;
                }
                if(cont!=-2&&aux2->prox==NULL){
                        aux2->prox=novo;
                        (*h)=aux3;
                        cont=-2;

                }
                else if(cont!=-2&&cont==0&&aux2->freq>=novo->freq){
                        novo->prox=aux2;
                        (*h)=novo;
                        cont=-2;

                }
                else if(cont!=-2&&cont!=0&&aux2->freq>=novo->freq){
                    aux1->prox=novo;
                    novo->prox=aux2;
                    (*h)=aux3;
                    cont=-2;
                }
            cont++;
        }
        tam--;
    }
}
void imprime_aux(HUFFNo* a, int andar){
  if(a){
    int j;
    imprime_aux(a->esq, andar + 1);
    for(j = 0; j <= andar; j++) printf("   ");
    for(int i = 0; i<a->tam; i++){
            if(i==a->tam-1)printf("%c\n", a->chave[i]);
            else printf("%c", a->chave[i]);
    }
    imprime_aux(a->dir, andar + 1);
  }
}

void imprime_ab(HUFFNo* a){
  imprime_aux(a, 0);
}

int main()
{

	char arr[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	float freq[6] = { 5.0, 9.0, 17.0, 18.0, 21.0, 30.0 };
    HUFFNo *h=NULL;
	criaarv(freq,arr,&h,6);
	imprime_ab(h);

	return 0;
}

