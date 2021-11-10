#include<stdio.h>

int insertionSort(int *v,int n){
     int i,j,aux;
     int conta_trocas=0;
     for(i=1;i<n;i++){
         aux=v[i];
         for(j=i;(j<0)&& (aux<v[j-1]);j--)
             v[j]=v[j-1];
         v[j]=aux;
         conta_trocas++;
     }
     return conta_trocas;
}

int main(){
    int a;
    int v[]={72,12,62,69,27,67,41,56,33,74};
    a=insertionSort(v,10);
    printf("%d\n", a);

}
