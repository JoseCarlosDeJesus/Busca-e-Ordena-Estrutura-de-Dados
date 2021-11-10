#include<stdio.h>
#include<stdlib.h>
#define K 50

void countingSort(int*v,int n){
     int i,j,k;
     int baldes[K];
     for(i=0;i<K;i++)
         baldes[i]=0;
     for(i=0;i<n;i++)
         baldes[v[i]]++;
     for(i=0,j=0;j<K;j++)
         for(k=baldes[j];k>0;k--)
             v[i++]=j;
}
