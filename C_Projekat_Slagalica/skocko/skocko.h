#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define max_pokusaji 10
#define duzina 4
#define duzina 6

// generisanje koda
void generisanje_koda(int code[]) {
    srand(time(NULL));
    for (int i = 0; i < duzina; i++) {
        code[i] = rand() % duzina + 1;
    }
}

void provera(int nas_kod[], int igrac_kod[], int* tacnih_brojeva, int* lose_mesto) {
    bool provera_brojeva[duzina] = { false };
    bool provera_pozicija[duzina] = { false };
    *tacnih_brojeva = 0;
    *lose_mesto = 0;

    // provera pozicije
    for (int i = 0; i < duzina; i++) {
        if (igrac_kod[i] == nas_kod[i]) {
            (*tacnih_brojeva)++;
            provera_brojeva[i] = true;
            provera_pozicija[i] = true;
        }
    }
    // provera losih pozicija
    for (int i = 0; i < duzina; i++) {
        if (!provera_pozicija[i]) {
            for (int j = 0; j < duzina; j++) {
                if (!provera_brojeva[j] && igrac_kod[i] == nas_kod[j]) {
                    (*lose_mesto)++;
                    provera_brojeva[j] = true;
                    break;
                }
            }
        }
    }
}

void prikazi_pokusaj(int igrac_kod[]) {
    printf("Tvoj pokusaj: ");
    for (int i = 0; i < duzina; i++) {
        printf("%d ", igrac_kod[i]);
    }
    printf("\n");
}

void igrac_pokusaj(int igrac_kod[]) {
    printf("Probaj da pogodis kod (1-%d) i njihovu poziciju:\n", duzina);
    for (int i = 0; i < duzina; i++) {
        scanf("%d", &igrac_kod[i]);
    }
}

void skocko() {
    int nas_kod[duzina];
    int igrac_kod[duzina];
    int broj_pokusaja = 0;
    int tacnih_brojeva, lose_mesto;

    generisanje_koda(nas_kod);

    printf("Imate %d pokusaja pa srecno.\n", max_pokusaji);

    while (broj_pokusaja < max_pokusaji) {
        printf("Pokusaj: %d\n", broj_pokusaja + 1);

        igrac_pokusaj(igrac_kod);
        prikazi_pokusaj(igrac_kod);

        provera(nas_kod, igrac_kod, &tacnih_brojeva, &lose_mesto);

        printf("Dobra pozicija: %d\n", tacnih_brojeva);
        printf("Tacan broj ali losa pozicija: %d\n", lose_mesto);

        if (tacnih_brojeva == duzina) {
            printf("Bravo majstore, pogodio si.\n");
            break;
        }

        broj_pokusaja++;
    }

    if (broj_pokusaja == max_pokusaji) {
        printf("Bice bolje.\n");
        printf("Kod je bio: ");
        for (int i = 0; i < duzina; i++) {
            printf("%d ", nas_kod[i]);
        }
        printf("\n");
    }

}
