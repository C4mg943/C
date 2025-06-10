//arbol de navidad clasico
/*
    1
    11
    111
    1111
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

#define nmax 100
#define nmin 0

void error(const char *message ){
    perror(message);
    exit(EXIT_FAILURE);
}

int main(){

    int n;
    scanf("%d",&n);

    if(n<nmin || n > nmax){
        error("Estos valores estan fuera de los limites.");
    }
    for (int i = 1; i <= n; i++){
        for(int j = 1; j<=n-i;j++){
            printf(" ");
        }
        for(int k = 1; k<=i; k++){
            printf("#");
        }
        printf("\n");

    }
    return EXIT_SUCCESS;
}