#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 128

void moj_broj() {
    srand(time(NULL));

    int number = rand() % 10 + 1;
    int broj1 = rand() % 10 + 1;
    int broj2 = rand() % 10 + 1;
    int broj3 = rand() % 10 + 1;
    int broj4 = rand() % 100 + 1;
    int broj5 = rand() % 100 + 1;

    printf("Zadat broj je %d\n", number);

    printf("Na raspolaganju su brojevi:\nBroj 1: %d\nBroj 2: %d\nBroj 3: %d\nBroj 4: %d\nBroj 5: %d\n", broj1, broj2, broj3, broj4, broj5);

    int rezultat = 0;
    int i = 0;

    for (i = 0; i < 5; i++) {
        char dane[3];
        printf("Da li želiš da nastaviš sa radom? ");
        scanf("%s", dane);
        if (strcmp(dane, "da") == 0) {

            printf("Koje brojeve hocete koristiti? ");
            printf("Na raspolaganju su brojevi:\nBroj 1: %d\nBroj 2: %d\nBroj 3: %d\nBroj 4: %d\nBroj 5: %d\n", broj1, broj2, broj3, broj4, broj5);

            int x, y;

            scanf("%d", &x);
            scanf("%d", &y);

            int odabir1;
            int odabir2;

            if (x == 1) {
                odabir1 = broj1;
            } else if (x == 2) {
                odabir1 = broj2;
            } else if (x == 3) {
                odabir1 = broj3;
            } else if (x == 4) {
                odabir1 = broj4;
            } else if (x == 5) {
                odabir1 = broj5;
            } else if(x==0) {
                odabir1=0;
            }

            if (y == 1) {
                odabir2 = broj1;
            } else if (y == 2) {
                odabir2 = broj2;
            } else if (y == 3) {
                odabir2 = broj3;
            } else if (y == 4) {
                odabir2 = broj4;
            } else if (y == 5) {
                odabir2 = broj5;
            } else if(y==0) {
                odabir2=0;
            }

            printf("%d %d\n", odabir1, odabir2);

            printf("Koju operaciju zelite? (+, -, *, /): ");
            char c;
            scanf(" %c", &c);

            if (c == '+') {
                printf("%d + %d = %d\n", odabir1, odabir2, odabir1 + odabir2);
                rezultat += (odabir1 + odabir2);
            } else if (c == '-') {
                printf("%d - %d = %d\n", odabir1, odabir2, odabir1 - odabir2);
                rezultat += (odabir1 - odabir2);
            } else if (c == '*') {
                printf("%d * %d = %d\n", odabir1, odabir2, odabir1 * odabir2);
                rezultat += (odabir1 * odabir2);
            } else if (c == '/') {
                if (odabir2 != 0) {
                    printf("%d / %d = %.2f\n", odabir1, odabir2, (float)odabir1 / odabir2);
                    rezultat += (odabir1 / odabir2);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
            } else {
                printf("Error: Invalid operator.\n");
            }

        } else {
            if (number != rezultat) {
                printf("Pogresno ste odradili. ");
                if ((rezultat - number) > 0) {
                    printf("Omasili ste za %d.\n", rezultat - number);
                } else if ((number - rezultat) > 0) {
                    printf("Omasili ste za %d.\n", number - rezultat);
                }
            } else {
                printf("Tacan odgovor.\n");
            }
            break;
        }
    }
}
