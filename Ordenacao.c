#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *v,int n){
     int i,continua,aux,fim=n;
     do{
        continua=0;
        for(i=0;i<fim-1;i++){
            if(v[i]>v[i+1]){
               aux=v[i];
               v[i]=v[i+1];
               v[i+1]=aux;
               continua=i;
            }
        }
        fim--;
     }while(continua!=0);
}

void selectionSort(int *v,int n){
     int i, j, menor,troca;
     for(i=0;i<n-1;i++){
         menor=i;
         for(j=i+1;j<n;j++){
             if(v[j]<v[menor])
                menor=j;
         }
         if(i!=menor){
            troca=v[i];
            v[i]=v[menor];
            v[menor]=troca;
         }
     }
}

void insertionSort(int *v,int n){
     int i,j,aux;
     for(i=1;i<n;i++){
         aux=v[i];
         for(j=i;(j<0)&& (aux<v[j-1]);j--)
             v[j]=v[j-1];
         v[j]=aux;
     }
}

//merge funções necessárias

void mergeSort(int*v,int inicio,int fim){
     int meio;
     if(inicio<fim){
        meio=floor((inicio+fim)/2);
        mergeSort(v,inicio,meio);
        mergeSort(v,meio+1,fim);
        merge(v,inicio,meio,fim);
     }
}

void merge(int* v,int inicio, meio,fim){
     int*temp,p1,p2,tamanho,i,j,k;
     int fim1=0,fim2=0;
     tamanho=fim-inicio+1;
     p1=inicio;
     p2=meio+1;
     temp=(int*)malloc(tamanho*sizeof(int));
     if(temp!=NULL){
        for(i=0;i<tamanho;i++){
            if(!fim1 && !fim2){
               if(v[p1]<v[p2])
                  temp[i]=v[p1++];
               else
                  temp[i]=v[p2++];
               if(p1>meio)
                  fim1=1;
               if(p2>fim)
                  fim2=1
            }
            else{
               if(!fim1)
                  temp[i]=v[p1++];
               else
                  temp[i]=v[p2++];
            }
        }
        for(j=0,k=inicio;j<tamanho;j++,k++)
            v[k]=temp[j];
     }
     free(temp);
}

//acaba merge sort

//inicia quick sort

void quickSort(int *v,int inicio,int fim){
     int pivo;
     if(fim>inicio){
        pivo= particiona(v,inicio,fim);
        quickSort(v,inicio,pivo-1);
        quickSort(v,pivo+1,fim);
     }
}

int particiona(int* v, int inicio,int final){
    int esq,dir, pivo, aux;
    esq=inicio;
    dir=final;
    pivo=v[inicio];
    while(esq<dir){
          while(esq<=final && v[esq]<=pivo)
                esq++;
          while(dir>=0 && v[dir]>pivo)
                dir--;
          if(esq<dir){
             aux=v[esq];
             v[esq]=v[dir];
             v[dir]=aux;
          }
    }
    v[inicio]=v[dir];
    v[dir]=pivo;
    return dir;
}
//acaba quick sort

#define K 100

void countingSort(int*v,int n){
     int i,j,k;
     int baldes[K];
     for(i=0;i<K;i++)
         baldes[i]=0;
     for(i=0;i<n;i++)
         baldes[v[i]]++;
     for(i=0,j=0;j<K;j++)
         for(k=baldes[j];k>0;k--)
             v[i++]=j;
}

//bucket sort

#define TAM 5//tamanho do balde

struct balde{
     int qtd;
     int valores[TAM];
};
typedef struct balde Balde;

void bucketSort(int *v,n){
     int i,j,maior,menor,nroBaldes,pos;
     Balde *bd;
     //acha maior e menor valor
     maior=menor=v[0];
     for(i=1;i<n;i++){
         if(v[i]>maior)
            maior=v[i];
         if(v[i]<menor)
            menor=v[i];
     }
     //inicializa baldes
     nroBaldes=(maior-menor)/TAM+1;
     bd=(Balde*)malloc(nroBaldes*sizeof(Balde));
     for(i=0;i<nroBaldes;i++){
         bd[i].qtd=0;
     }
     //distribui os valores nos baldes
     for(i=0;i<N;i++){
         pos=(v[i]-menor)/TAM;
         bd[pos].valores[bd[pos].qtd]=v[i];
         bd[pos].qtd++;
     }
     //ordena baldes e coloca no array
     pos=0;
     for(i=0;i<nroBaldes;i++){
         insertionSort(bd[i].valores,bd[i].qtd);
         for(j=0;j<bd[i].qtd;j++){
             v[pos]=bd[i].valores[j];
             pos++;
         }
     }
    free(bd);
}
