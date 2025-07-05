#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10007 // Número primo para la tabla hash

// Nodo de la tabla hash
typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

int hash(int key) {
    if (key < 0) key = -key;
    return key % HASH_SIZE;
}

void hashInsert(HashNode** table, int key, int value) {
    int idx = hash(key);
    HashNode* node = malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;
    node->next = table[idx];
    table[idx] = node;
}

int hashFind(HashNode** table, int key) {
    int idx = hash(key);
    HashNode* node = table[idx];
    while (node) {
        if (node->key == key)
            return node->value;
        node = node->next;
    }
    return -1;
}

void hashFree(HashNode** table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = table[i];
        while (node) {
            HashNode* tmp = node;
            node = node->next;
            free(tmp);
        }
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashNode* table[HASH_SIZE] = {0};
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int idx = hashFind(table, complement);
        if (idx != -1) {
            int* result = malloc(2 * sizeof(int));
            result[0] = idx;
            result[1] = i;
            *returnSize = 2;
            hashFree(table);
            return result;
        }
        hashInsert(table, nums[i], i);
    }
    *returnSize = 0;
    hashFree(table);
    return NULL;
}

int main() {
    int capacidad = 10;
    int *nums = malloc(capacidad * sizeof(int));
    int n = 0, temp, target;

    printf("Ingrese los números del arreglo separados por espacio (finalice con ENTER):\n");
    while (scanf("%d", &temp) == 1) {
        if (n >= capacidad) {
            capacidad *= 2;
            nums = realloc(nums, capacidad * sizeof(int));
            if (!nums) {
                fprintf(stderr, "Error de memoria\n");
                return 1;
            }
        }
        nums[n++] = temp;
        // Si el siguiente caracter es salto de línea, terminamos de leer
        int c = getchar();
        if (c == '\n' || c == EOF) break;
    }

    printf("Ingrese el valor target:\n");
    if (scanf("%d", &target) != 1) {
        fprintf(stderr, "Error leyendo el target\n");
        free(nums);
        return 1;
    }

    int returnSize = 0;
    int* result = twoSum(nums, n, target, &returnSize);

    if (result && returnSize == 2) {
        printf("Índices de la solución: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No se encontró solución.\n");
    }

    free(nums);
    return 0;
}

