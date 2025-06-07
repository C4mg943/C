//para 2 arreglos con 3 valores de 1 a 100 determinar los puntos de cada jugador depeiendo si
// a[o] < b[b] si si, da 1 punto de 3 y asi con todas. mostrar quien tiene mas puntos

#include <stdio.h>
#include <stdlib.h>

void print(int arr[]){
    for (int i = 0; i < 3; i++)
    {
        printf("%d - ",arr[i]);
    }
    
}

void compare(int arra[], int arrb[]){

    int point_a = 0;
    int point_b = 0;

    for (int i = 0; i < 3; i++)
    {
        if(arra[i]>arrb[i]){
            point_a= point_a + 1;
        }else{
            if (arra[i]<arrb[i]){
                point_b = point_b+1;
            }
        }
    }

    printf("%d %d",point_a, point_b);
    
}

int main(){
    int a[3]; 
    int b[3];

    for (int i = 0; i < 3; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<1&&a[i]>100){
            printf("error");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        scanf("%d",&b[i]);
        if(b[i]<1&&b[i]>100){
            printf("error");
            return EXIT_FAILURE;
        }
    }

    compare(a,b);

    return EXIT_SUCCESS;


}