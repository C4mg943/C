#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
        scanf("%d",&n);
        int size = 2 * n - 1;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int Mini = i;
                    if (j < Mini) Mini = j;
                    if (size - 1 - i < Mini) Mini = size - 1 - i;
                    if (size - 1 - j < Mini) Mini = size - 1 - j;

                    printf("%d", n - Mini);

                    if (j < size - 1)
                        printf(" ");
                }
                printf("\n");
            }
}