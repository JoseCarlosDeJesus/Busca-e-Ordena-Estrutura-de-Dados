#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void quickSort(char *v,int inicio,int fim){
     int pivo;
     if(fim>inicio){
        pivo= particiona(v,inicio,fim);
        quickSort(v,inicio,pivo-1);
        quickSort(v,pivo+1,fim);
     }
}

int particiona(char* v, int inicio,int final){
    int esq,dir;
    char pivo, aux;
    esq=final;
    dir=inicio;
    pivo=v[inicio];
    while(esq<dir){
          while(esq<=final && strcmp(v[esq],pivo)<0)
                esq--;
          while(dir>=0 && strcmp(v[dir],pivo)>0)
                dir++;
          if(esq>dir){
             aux=v[esq];
             v[esq]=v[dir];
             v[dir]=aux;
          }
    }
    v[inicio]=v[dir];
    v[dir]=pivo;
    return dir;
}
