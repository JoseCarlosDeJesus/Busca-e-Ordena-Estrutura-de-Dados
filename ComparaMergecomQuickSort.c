#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int particiona(int* v, int inicio,int final);
void quickSort(int *v,int inicio,int fim);
void merge(int* v,int inicio,int meio,int fim);
void mergeSort(int*v,int inicio,int fim);

int main(){
    int v[]={3,4,9,2,5,8,2,1,7,4,6,2,9,8,5,1};
    int i;
    printf("Merge Sort: ");
    mergeSort(v,0,15);
    for(i=0;i<=15;i++){
        printf("%d  ", v[i]);
    }
    printf("\n");
    printf("Quick Sort: ");
    quickSort(v,0,15);
    for(i=0;i<=15;i++){
        printf("%d  ", v[i]);
    }

}

void mergeSort(int*v,int inicio,int fim){
     int meio;
     int i;
     if(inicio<fim){
        meio=floor((inicio+fim)/2);
        mergeSort(v,inicio,meio);
        for(i=inicio;i<=fim;i++)
            printf("%d  ", v[i]);
        printf("\n");
        mergeSort(v,meio+1,fim);
        for(i=inicio;i<=fim;i++)
            printf("%d  ", v[i]);
        printf("\n");
        merge(v,inicio,meio,fim);
     }
}

void merge(int* v,int inicio,int meio,int fim){
     int*temp,p1,p2,tamanho,i,j,k;
     int fim1=0,fim2=0;
     tamanho=fim-inicio+1;
     p1=inicio;
     p2=meio+1;
     temp=(int*)malloc(tamanho*sizeof(int));
     if(temp!=NULL){
        for(i=0;i<tamanho;i++){
            if(!fim1 && !fim2){
               if(v[p1]<v[p2])
                  temp[i]=v[p1++];
               else
                  temp[i]=v[p2++];
               if(p1>meio)
                  fim1=1;
               if(p2>fim)
                  fim2=1;
            }
            else{
               if(!fim1)
                  temp[i]=v[p1++];
               else
                  temp[i]=v[p2++];
            }
        }
        for(j=0,k=inicio;j<tamanho;j++,k++)
            v[k]=temp[j];
     }
     free(temp);
}

void quickSort(int *v,int inicio,int fim){
     int pivo;
     int i;
     if(fim>inicio){
        pivo= particiona(v,inicio,fim);
        quickSort(v,inicio,pivo-1);
        for(i=inicio;i<=fim;i++)
            printf("%d  ", v[i]);
        printf("\n");
        quickSort(v,pivo+1,fim);
        for(i=inicio;i<=fim;i++)
            printf("%d  ", v[i]);
        printf("\n");
     }
}

int particiona(int* v, int inicio,int final){
    int esq,dir, pivo, aux;
    esq=inicio;
    dir=final;
    pivo=v[inicio];
    while(esq<dir){
          while(esq<=final && v[esq]<=pivo)
                esq++;
          while(dir>=0 && v[dir]>pivo)
                dir--;
          if(esq<dir){
             aux=v[esq];
             v[esq]=v[dir];
             v[dir]=aux;
          }
    }
    v[inicio]=v[dir];
    v[dir]=pivo;
    return dir;
}
