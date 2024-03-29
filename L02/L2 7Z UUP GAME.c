/*
Zadatak
Program najprije treba omogućiti unos cijelog broja n. Ako je broj neparan, manji od 4 ili veći od 100 treba ispisati poruku ‘Broj je van trazenog opsega.’ i prekinuti rad programa. U suprotnom na ekranu treba iscrtati oblik kao na primjeru ulaza i izlaza ispod, sastavljen od znakova plus (+):

image.png
++++++++++++++++
++            ++
+ +          + +
+  ++++++++++  +
+              +
+              +
+              +
++++++++++++++++

Oblik koverte sastoji od:

Pravougaonika n x 2*n
Dvije kose crte i prave crte koji čine ‘poklopac koverte’ koji ima visinu od n/2 - 1 pluseva.
*/

// MOJ KOD:

#include <stdio.h>

int main() {
  int n;
  printf("Unesite broj n: ");
  scanf("%d", &n);

  if (n % 2 != 0 || n < 4 || n > 100) {
    printf("Broj je van trazenog opsega.");
  } else {
    int i, j;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= 2 * n; j++) {
        if (i == 1 || i == n || j == 1 || j == 2 * n ||
            (i == j && i < (n / 2)) ||
            (i==(n/2) && (j>=i && j<=(2*n+1-i)) || j==0)|| (i<n/2  && j==2*n+1-i)) {
          printf("+");
        } else {
          printf(" ");
        }
    }printf("\n");
    }
  }

  return 0;
}

