#include <stdio.h>
#include <stdlib.h>

void error(const char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

void ciclo(char s[], int t, int hora[], char *jornada){
    // suponer que s = "12:40AM"
    hora[0] = (s[0] - '0') * 10 + (s[1] - '0'); // hora
    hora[1] = (s[3] - '0') * 10 + (s[4] - '0'); // minutos
    hora[2] = (s[6] - '0') * 10 + (s[7] - '0'); // segundos
    *jornada = s[8]; // 'A' o 'P'
}

void convertir_a_militar(char s[], char resultado[]) {
    int hh = (s[0] - '0') * 10 + (s[1] - '0');
    int mm = (s[3] - '0') * 10 + (s[4] - '0');
    int ss = (s[6] - '0') * 10 + (s[7] - '0');

    char ampm1 = s[8]; // 'A' o 'P'
    char ampm2 = s[9]; // 'M'

    if (ampm1 == 'A') {
        if (hh == 12) {
            hh = 0;
        }
    } else if (ampm1 == 'P') {
        if (hh != 12) {
            hh += 12;
        }
    }

    // Guarda en resultado con formato hh:mm:ss
    sprintf(resultado, "%02d:%02d:%02d", hh, mm, ss);
}

int main() {
    char entrada[11];     // "hh:mm:ssAM" + '\0'
    char salida[9];       // "HH:MM:SS" + '\0'

    scanf("%s", entrada); // por ejemplo: 07:05:45PM

    convertir_a_militar(entrada, salida);

    printf("%s\n", salida); // muestra: 19:05:45

    return 0;
}
