#include<stdio.h>

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
