#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void error(const char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int encontrar(int n, int a, int b, int c){
    if(n==1) return a;
    if(n==2) return b;
    if(n==3) return c;
    return encontrar(n-1,a,b,c) + encontrar(n-2,a,b,c) + encontrar(n-3,a,b,c);
}

int main(){
    int n,a,b,c;
    scanf("%d%d%d%d",&n,&a,&b,&c);

    int nterm = encontrar(n,a,b,c);
    printf("%d",nterm);
    return EXIT_SUCCESS;
}