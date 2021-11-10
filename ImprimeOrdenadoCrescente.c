#include<stdio.h>

//imprime ordenado caso o vetor esteja em ordem crescente, deixa de imprimir se não estiver
void imprimeOrdenadoCrescente(int* v, int n){
     int i;
    for(i=0;i<n;i++){
        if(v[i]>v[i+1])
           break;
        else
           printf("%d\n", v[i]);
    }
}
