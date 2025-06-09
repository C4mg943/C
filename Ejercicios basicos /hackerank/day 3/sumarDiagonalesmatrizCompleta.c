#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int diagonaldiference(int **matriz,int n){
    //se suma el primero, luego el primero mas 1, luego asi hasta n, y ya
    int sumaA = 0, sumaB = 0;

    for (int i = 0; i < n; i++){
        sumaA += matriz[i][i];
        sumaB += matriz[i][n-1-i];
    }

    return abs(sumaA-sumaB);

    
}

int main(){

    int n;
    scanf("%d",&n);


    int **matriz = malloc(n * sizeof(int *));
    for(int i=0; i<n; i++){
        matriz[i]= malloc(n * sizeof(int));
    }

    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            scanf("%d",&matriz[i][j]);
        }
    }

    int resultado  = diagonaldiference(matriz, n);
    printf("%d",resultado);

    for(int i = 0; i<n; i++){
        free(matriz[i]);
    }
    free (matriz);

    return EXIT_SUCCESS;
}