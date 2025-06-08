#include <stdio.h>
#include <stdlib.h>


void dato(char *arr[], char *even[], int a, int b){

    for (int i = a; i <= b; i++)
    {
        if(i>=1 && i<=9){
            printf("%s\n",arr[i-1]);
        }else{
            if(i % 2 ==0){
                printf("%s\n",even[0]);
            }else{
                printf("%s\n",even[1]);
            }
        }
    }

    
}

int main(){

    int a,b;
    scanf("%d%d",&a,&b);

    char *names[10]={
        "one","two","three","four","five","six","seven","eight","nine"
    };

    char *evenodd[2] = {"even","odd"};

    dato(names,evenodd, a,b);

    return EXIT_SUCCESS;
}