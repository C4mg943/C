#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int max = 0, count = 0;

    for (int i = 0; i < n; i++) {
        int h;
        scanf("%d", &h);

        if (h > max) {
            max = h;
            count = 1;
        } else if (h == max) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
