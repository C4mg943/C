#include <stdio.h>
#include <stdlib.h>

void suma(long arr[],long n){
    long sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    printf("%ld",sum);
}

int main(){

    long n = 0;
    scanf("%d",&n);
    long arr[n];

    for(int i = 0; i<n; i++){
        scanf("%ld",&arr[i]);
    }

    suma(arr,n);

    return EXIT_SUCCESS;
}