
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
    HUFFno* novo=(HUFFno*)malloc(sizeof(HUFFno));
    novo->chave=(char*)malloc(sizeof(char*));
    novo->chave=nos[i];
    novo->freq=freq[i];
    novo->esq=NULL;
    novo->dir=NULL;
    HUFFNo *aux=(*h);
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    aux->prox=novo;
    }
    while(tam!=1){
        HUFFNo* novo=(HUFFNo*)malloc(sizeof(HUFFNo));
        HUFFNo *aux1=(*h);
        HUFFNo *aux2=(*h)->prox;
        novo->chave=(char*)malloc(sizeof(char*)*(aux1->tam+aux2->tam));
        for(int j=0;j<aux1->tam;j++){
            novo->chave[j]=aux1->chave[j];
        }
        for(int k;k<aux2->tam;k++){
            novo->chave[j]=aux2->chave[k];
            j++;
        }
        novo->freq=aux1->freq+aux2->freq;
        novo->tam=aux1->tam+aux2->tam;
        novo->esq=aux1;
        novo->dir=aux2;
        aux1=aux2->prox;
        int cont=0;
        while(novo->freq>aux2->freq){
                aux2=aux2->prox;
                if(aux2==NULL){
                        novo->prox=NULL;
                        (*h)=aux1;

                }
                if(cont==0&&aux2->freq>=novo->freq){
                        novo->prox=aux2;
                        (*h)=novo;

                }
                else{
                    novo->prox=aux2;
                    (*h)=aux1;
                }
            cont++;
        }
        tam--;
    }
}

int main()
{

	char arr[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[6] = { 5, 9, 17, 18, 21, 30 };
    HUFFNo *h=NULL;
	criaarv(freq,nos,&h,6)

	return 0;
}

