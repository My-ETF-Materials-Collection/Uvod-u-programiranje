/*
Zadatak
Napišite program koji će iscrtavati BGA kolo. Korisnik unosi broj n, koji predstavlja broj pinova (lopticâ, predstavljenih znakom „o“) u jednom redu i jednoj koloni BGA kola. Broj n mora biti u granicama [1, 35]. Pinove BGA kola staviti u okvir (po dva razmaka sa lijeve i desne strane okvira), koji ima izvode za daljnju ugradnju na desnoj strani. Izvodi su sastavljeni od „>“ i „<“ znakova. Primjeri ispisa:

Unesite N, dimenziju BGA kola: 3

+---------+
|  o o o  >
|  o o o  <
|  o o o  >
+---------+

Unesite N, dimenziju BGA kola: 5

+-------------+
|  o o o o o  >
|  o o o o o  <
|  o o o o o  >
|  o o o o o  <
|  o o o o o  >
+-------------+
*/

// MOJ KOD:

#include <stdio.h>

int main() {
  int n;
  printf("Unesite N, dimenziju BGA kola: ");
  scanf("%d", &n);
  int i, j;
  if (n >= 1 && n <= 35) {
    for (i = 1; i <= 2 * n + 3; i++) {
      for (j = 1; j <= 2 * n + 5; j++) {
        if ((i == 1 && j == 1) || (i == 1 && j == 2 * n + 5) ||
            (i == 2 * n + 3 && j == 1) || (i == 2 * n + 3 && j == 2 * n + 5)) {
          printf("+");
        } else if (i % 2 == 0) {
          printf(" ");
        } else {
          if (i > 1 && i % 2 != 0 && i < 2 * n + 3) {
            if (j == 1) {
              printf("|");
            }
            if (j >= 4 && j % 2 == 0 && j<=2*n+3) {
              printf("o");
            } else {
              printf(" ");
            }

            if (j == 2 * n + 5) {

              if (i >=3 && i%4==3) {
                printf(">");
              } else {
                printf("<");
              }
            }
          } else {
            printf("-");
          }
        }
      }
      printf("\n");
    }
  }
  return 0;
}
