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
       selectionSort(v,n);
       for(i=0;i<n;i++){
           printf("%s\n", v[i]);
       }
    }
    else{
       exit(1);
    }
}

void selectionSort(int *v,int n){
     int i, j, menor;
     char troca[n];
     for(i=0;i<n-1;i++){
         menor=i;
         for(j=i+1;j<n;j++){
             if(strcmp(v[j],v[menor])>0)
                menor=j;
         }
         if(i!=menor){
            troca=v[i];
            v[i]=v[menor];
            v[menor]=troca;
         }
     }
}
