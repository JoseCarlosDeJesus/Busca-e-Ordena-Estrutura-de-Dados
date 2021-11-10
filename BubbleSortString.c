#include<stdio.h>
#include<string.h>

void bubbleSort(int *v,int n){
     int i,continua,fim=n;
     char aux[n];
     do{
        continua=0;
        for(i=0;i<fim-1;i++){
            if(strcmp(v[i],v[i+1])>0){
               aux=v[i];
               v[i]=v[i+1];
               v[i+1]=aux;
               continua=i;
            }
        }
        fim--;
     }while(continua!=0);
}
