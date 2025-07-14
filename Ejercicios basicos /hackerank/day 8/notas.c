#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

// cantidad  de notas, 3(1 2 3) 'g' o 'b' suma de esas, las pares son chicos las impares chicas

void error(const char *msg){
    errno = EINVAL;
    perror(msg);
    exit(EXIT_FAILURE);
}

void llenar(int *arr, int tam){
    for(int i = 0; i<tam; i++){
        scanf("%d",&arr[i]);
    }
}

void solucion(int arr[],int tam, char gender){
    int aux = 0;
    for (int i = 0; i < tam; i++)
    {
        if(gender == 'b'){
            if((i%2)==0){
                aux += arr[i];
            }
        }else{
            if((i%2)!=0){
                aux += arr[i];
            }            
        }
    }
    printf("%d",aux);
}

int main(){
    int flag;
    scanf("%d",&flag);
    int arr[flag];
    llenar(arr,flag);
    char gender; 
    scanf(" %c", &gender);

    if(gender != 'b' && gender != 'g'){
        error("Genero incorrecto ('g' o 'b')");
    }
    solucion(arr,flag,gender);
    return EXIT_SUCCESS;
}
