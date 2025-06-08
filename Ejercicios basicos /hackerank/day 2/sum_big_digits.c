/* mostrar la suma de los digitos de un numero de 5 digitos, ejemplo si n es 12345, el out es 15 */
#include <stdio.h>
#include <stdlib.h>

void sum(int n){
    int aux = 0;
    int suma = 0;

    while (n > 0){
        aux = n % 10;
        suma += aux;
        n = n / 10;
    }
    
    printf("%d", suma);

}

int main(){
    int n;
    scanf("%d",&n);
    sum(n);
    return EXIT_SUCCESS;
}