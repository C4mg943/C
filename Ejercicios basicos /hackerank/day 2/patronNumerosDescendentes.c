#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Calculamos la distancia mínima al borde
            int min_dist = i;
            if (j < min_dist) min_dist = j;
            if (size - 1 - i < min_dist) min_dist = size - 1 - i;
            if (size - 1 - j < min_dist) min_dist = size - 1 - j;

            // Valor en la celda = n - min_dist
            printf("%d", n - min_dist);

            // Espacio entre números (excepto al final de la fila)
            if (j < size - 1)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
