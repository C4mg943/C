#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char** usernames = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        usernames[i] = malloc(1001 * sizeof(char));
        scanf("%s", usernames[i]);
    }

    for (int i = 0; i < n; i++) {
        char* s = usernames[i];
        int len = strlen(s);
        int found = 0;

        for (int j = 0; j < len && !found; j++) {
            for (int k = j + 1; k < len; k++) {
                if (s[k] < s[j]) {
                    found = 1;
                    break;
                }
            }
        }

        if (found) printf("YES\n");
        else printf("NO\n");

        free(usernames[i]);
    }

    free(usernames);
    return 0;
}
