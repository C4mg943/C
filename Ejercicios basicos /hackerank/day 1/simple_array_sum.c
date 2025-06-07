/*dado un arreglo con n numeros enteros, calcular la suma de todos los elementos del arreglo
Ejemplo: array = [1, 2, 3, 4, 5] = 15
*/

#include <stdio.h>
#include <stdlib.h>

int simpleArraySum(int arr[], int n){
    int aux = 0;

    for (int i = 0; i < n; i++)
    {
        aux = aux + arr[i];
    }

    return aux;
    
}

int main(int argc,char argv[]){

    int n; 

    scanf("%d",&n);

    int arr[n]; //declaramos el tamaño del arreglo estaticamente, corregir a futuro: 

    //pedir los datos de el arreglo

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int resultado = simpleArraySum(arr, n);
    printf("%d", resultado);

    return EXIT_SUCCESS;
}