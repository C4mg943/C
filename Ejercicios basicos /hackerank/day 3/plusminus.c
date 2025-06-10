#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

#define min_val_arr -100
#define max_val_arr 100
#define min_n -100
#define max_n 100

void error(const char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

void separar(int *arr, int n, int *arrP, int *arrN, int *arr0) {
    *arrP = 0;
    *arrN = 0;
    *arr0 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            (*arrP)++;
        } else if (arr[i] < 0) {
            (*arrN)++;
        } else {
            (*arr0)++;
        }
    }
}

void calcular(int positivos, int negativos, int ceros, int total) {
    printf("%.6f\n", (positivos * 1.0) / total);
    printf("%.6f\n", (negativos * 1.0) / total);
    printf("%.6f\n", (ceros * 1.0) / total);
}

void guardararreglo(int *arr, int n){
    for (int i = 0; i < n; i++) {
        int temp; 
        if(scanf("%d",&temp)!=1){
            error("Caracter invalido.");
        }
        if(temp < min_val_arr || temp > max_val_arr){
            error("No esta en el rango valido.");
        }
        arr[i] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if(n<min_n || n>max_n){
        error("n no valido");
    }

    int arr[n];

    guardararreglo(arr,n);
    int positivos, negativos, ceros;
    separar(arr, n, &positivos, &negativos, &ceros);
    calcular(positivos, negativos, ceros, n);

    return EXIT_SUCCESS;
}
