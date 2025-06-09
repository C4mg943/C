#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

#define MIN_VAL -100
#define MAX_VAL 100

int **crear_matriz(int n) {
    int **matriz = malloc(n * sizeof(int *));
    if (!matriz) {
        perror("Error al reservar memoria para la matriz");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        matriz[i] = malloc(n * sizeof(int));
        if (!matriz[i]) {
            perror("Error al reservar memoria para una fila");
            exit(EXIT_FAILURE);
        }
    }
    return matriz;
}

void leer_matriz(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            if (scanf("%d", &temp) != 1) {
                perror("Error al leer un número");
                exit(EXIT_FAILURE);
            }
            if (temp < MIN_VAL || temp > MAX_VAL) {
                fprintf(stderr, "Valor fuera de rango permitido (%d a %d): %d\n", MIN_VAL, MAX_VAL, temp);
                perror("Número inválido");
                exit(EXIT_FAILURE);
            }
            matriz[i][j] = temp;
        }
    }
}

void liberar_matriz(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int suma_diagonal_principal(int **matriz, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += matriz[i][i];
    }
    return suma;
}

int suma_diagonal_secundaria(int **matriz, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += matriz[i][n - 1 - i];
    }
    return suma;
}

int diferencia_diagonales(int **matriz, int n) {
    int sumaA = suma_diagonal_principal(matriz, n);
    int sumaB = suma_diagonal_secundaria(matriz, n);
    return abs(sumaA - sumaB);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        perror("Tamaño inválido de matriz");
        return EXIT_FAILURE;
    }

    int **matriz = crear_matriz(n);
    leer_matriz(matriz, n);

    int resultado = diferencia_diagonales(matriz, n);
    printf("%d\n", resultado);

    liberar_matriz(matriz, n);

    return EXIT_SUCCESS;
}
