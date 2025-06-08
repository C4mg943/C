//mostrar el nombre en ingles de los numeros del 1 al 9 si es mayor que nueve decir 
//greater than nine. 

#include <stdio.h>
#include <stdlib.h>

void dato(char *arr[], int num){

    if(num>=1 && num <= 9){
        printf("%s",arr[num-1]);
    }else{
        if(num > 9){
            printf("%s",arr[9]);
        }
    }
    
}

int main(){
    int num; 
    scanf("%d",&num);

    char *names[10]={
        "one","two","three","four","five","six","seven","eight","nine","Greater than 9"
    };

    dato(names, num);

    return EXIT_SUCCESS;
}