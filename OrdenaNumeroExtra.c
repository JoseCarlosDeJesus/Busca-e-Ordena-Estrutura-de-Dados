#include<stdio.h>
#include<stdlib.h>

void selectionSort(int *v,int n,int numero_extra){
     int i, j, menor,troca;
     v[n]=numero_extra;// no caso o vetor começa com zero, ou seja se ele tem n elementos ele vai até n-1,acrescentando mais um fica a posição n
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
