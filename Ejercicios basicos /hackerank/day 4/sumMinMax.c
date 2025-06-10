//encontrar el minimo y maximo de sumas posibles en un arreglo de n numeros

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

#define maxi 10e9
#define mini 1

void error(const char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

void crear(long *arr,int n){
    for(int i = 0; i<n; i++){
        scanf("%ld",&arr[i]);
    }
}

void ordenamiento(long *arr,int n){
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n-1; j++){
            long aux; 
            if(arr[j]>arr[j+1]){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux; 
            }
        }
    }
}

void obtenerMinymax(long *arr,int n,long *min, long *max){
    *min = 0;
    *max = 0;
    for (int i = 0; i < n-1; i++)
    {
        (*min) += arr[i];
        
    }
    for(int i = 1; i<n; i++){
        (*max) += arr[i];
    }
    
}

int main(){

    int n = 5;
    long arr[n];
    crear(arr,n);
    long minimo, maximo;
    ordenamiento(arr,n);

    obtenerMinymax(arr,n,&minimo,&maximo);

    printf("%ld %ld",minimo,maximo);
    return EXIT_SUCCESS;
}
