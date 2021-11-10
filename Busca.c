#include<stdio.h>
#include<stdlib.h>

int buscalinear(int*v,int n,int elem){
    int i;
    for(i=0;i<n;i++){
        if(elem=v[i])
           return i;//elemento encontrado
    }
    return -1;//elemento não encontrado
}

int buscaOrdenada(int *v, int n,int elem){
    int i;
    for(i=0;i<n;i++){
        if(elem==v[i])
           return i;//elemento encontrado
        else
           if(elem<v[i])
              return -1;//para a busca elemento nao encontrado
    }
    return -1;//elemento nao aencontrado
}

int buscaBinaria(int *v,int n,int elem){
    int i, inicio,meio,final;
    inicio=0;
    final=n-1;
    while(inicio<=final){
          meio=(inicio+final)/2;
          if(elem<v[meio])
             final=meio-1;//busca na metade da esquerda
          else
             if(elem>v[meio])
                inicio=meio+1;//busca na metade da direita
             else
                return meio;
    }
    return -1;//elemento não encontrado
}
