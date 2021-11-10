#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct pessoa{
       int matricula;
       char nome[30];
       float nota;
};
typedef struct pessoa Pessoa;

void insertionSortNome(Pessoa* v, int n);
void insertionSortMatricula(Pessoa *v,int n);
void insertionSortNota(Pessoa*v, int n);

int main(){
    int n;
    char escolha[8];
    scanf("%d", &n);
    Pessoa* novo;
    novo=(Pessoa*)malloc(n*sizeof(Pessoa));
    printf("Digite o campo que deseja ordenar: ");
    scanf("%s", escolha);
    if(escolha=="Matricula"){
         insertionSortMatricula(novo,n);
    }
    else if(escolha=="nome"){
         insertionSortNome(novo,n);
    }
    else{
        insertionSortNota(novo,n);
    }
}

void insertionSortNome(Pessoa* v, int n){
     int i, j;
     Pessoa aux;
     for(i=1;i<n;i++){
         aux= v[i];
         for(j=i;(j>0)&& (strcmp(aux.nome,v[j-1].nome)<0);j--)
             v[j]=v[j-1];
         v[j]=aux;
     }
}

void insertionSortMatricula(Pessoa *v,int n){
     int i,j;
     Pessoa aux;
     for(i=1;i<n;i++){
         aux=v[i];
         for(j=i;(j<0)&& (aux.matricula<v[j-1].matricula);j--)
             v[j]=v[j-1];
         v[j]=aux;
     }
}

void insertionSortNota(Pessoa*v, int n){
     int i,j;
     Pessoa aux;
     for(i=1;i<n;i++){
         aux=v[i];
         for(j=i;(j<0)&& (aux.nota<v[j-1].nota);j--)
             v[j]=v[j-1];
         v[j]=aux;
     }
}
