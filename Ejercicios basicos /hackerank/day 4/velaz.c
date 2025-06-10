#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void guardarA(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void ordenar(int *arr, int n, int *mayor) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
    (*mayor) = arr[n - 1];
}

void cake(int arr[], int n, int *velas, int mayor) {
    (*velas) = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == mayor) {
            (*velas)++;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    guardarA(arr, n);
    int nmayor;
    ordenar(arr, n, &nmayor);

    int cantidadvelas;
    cake(arr, n, &cantidadvelas, nmayor);
    printf("%d\n", cantidadvelas);

    return EXIT_SUCCESS;
}
