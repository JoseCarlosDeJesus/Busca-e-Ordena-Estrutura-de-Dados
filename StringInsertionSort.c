#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void insertionSort(int *v,int n);

int main(){
    int n,i;
    scanf("%d", &n);
    char *v;
    v=(char*)malloc(n*sizeof(char));
    if(v!=NULL){
       for(i=0;i<n;i++){
           scanf("%s", &v[i]);
       }
       insertionSort(v,n);
       for(i=0;i<n;i++){
           printf("%s\n", v[i]);
       }
    }
    else{
       exit(1);
    }
}

void insertionSort(int *v,int n){
     int i,j,aux;
     for(i=1;i<n;i++){
         aux=v[i];
         for(j=i;(j<0)&& (strcmp(aux,v[j-1])<0);j--)
             v[j]=v[j-1];
         v[j]=aux;
     }
}
