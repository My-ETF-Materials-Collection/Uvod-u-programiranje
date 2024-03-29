/*
Zadatak
Potrebno je napisati program koji će testirati simetričnost matrice po najvećim i najmanjim vandijagonalnim elementima. Matrica je simetrična ako ima jednake najveće elemente iz O1 i O4 oblasti i ako ima jednake najmanje elemente iz O2 i O3 oblasti (pogledati sliku). Korisnik sa tastature unosi cijeli broj n, koji predstavlja dimenziju matrice, te nakon toga unosi i elemente matrice formata n × n. Unos napraviti takvim da se jedan red matrice unosi istovremeno (elementi se pri unosu razdvajaju razmacima – pogledati primjer). Uneseni broj n mora biti u intervalu
[3, 30], u suprotnom program ispisuje grešku i završava sa radom. Program, pored toga što treba ispitati simetričnost matrice, treba da ispiše najveće (odnosno najmanje) vandijagonalne elemente iz pojedinih oblasti (zaokruženo na 3 decimale).

image.png

Vaš zadatak jeste da, za unesenu matricu, pronađete najveći ili najmanji elemenat iz navedenih oblasti, ispitate simetričnost matrice i ispišete pronađene elemente.

Primjer 1:

Unesite broj n: 5
Unesite elemente 1. reda: 1 2 3 4 5
Unesite elemente 2. reda: 6 5 4 3 2
Unesite elemente 3. reda: 1 2 3 4 5
Unesite elemente 4. reda: 8 3 0 2 1
Unesite elemente 5. reda: 6 4 0 0 0
Matrica je simetricna!
Elementi: O1 = 4.000, O2 = 1.000, O3 = 1.000, O4 = 4.000
Objašnjenje: U oblasti O1 najveći elemenat je 4, isto kao i u oblasti O4. U oblastima O2 i O3 najmanji elemenat je 1.

Primjer 2:

Unesite broj n: 4
Unesite elemente 1. reda: 1 2 4.12 -4.12
Unesite elemente 2. reda: 0 2 3.11 23.11
Unesite elemente 3. reda: 2 4 34.1 -0.02
Unesite elemente 4. reda: 0 0 0.04 33.01
Matrica nije simetricna!
Elementi: O1 = 4.120, O2 = 0.000, O3 = -0.020, O4 = 0.040
Primjer 3:

Unesite broj n: 2
Unos pogresan!
Napomena: Zadatak obavezno riješiti koristeći matricu.
*/

// MOJ KOD:

#include <stdio.h>

int main() {

  int n, i, j;
  double matrica[100][100];
  double max1, max4, min2, min3;

  printf("Unesite broj n: ");
  scanf("%d", &n);
  if (n < 3 || n > 30) {
    printf("Unos pogresan!");
    return 0;
  }

  for (i = 0; i < n; i++) {
    printf("\nUnesite elemente %d. reda: ", i + 1);
    for (j = 0; j < n; j++) {
      scanf("%lf", &matrica[i][j]);
    }
  }

  max1 = matrica[0][1];
  min2 = matrica[1][0];
  min3 = matrica[1][n-1];
  max4 = matrica[n-1][1];

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i > j && i != j && j != n - 1 - i && n - j - i > 0) {
        if (matrica[i][j] <= min2) {
          min2 = matrica[i][j];
        }
      }
      if (i > j && i != j && j != n - 1 - i && n - j - i <= 0) {
        if (matrica[i][j] > max4) {
          max4 = matrica[i][j];
        }
      }
      if (i < j && i != j && j != n - 1 - i && n - j - i <= 0) {
        if (matrica[i][j] <= min3) {
          min3 = matrica[i][j];
        }
      }
      if (i < j && i != j && j != n - 1 - i && n - j - i > 0) {
        if (matrica[i][j] > max1) {
          max1 = matrica[i][j];
        }
      }
    }
  }
  if (min2 == min3 && max1 == max4) {
    printf("Matrica je simetricna!");
  } else {
    printf("Matrica nije simetricna!");
  }

  printf("\nElementi: O1 = %.3lf, O2 = %.3lf, O3 = %.3lf, O4 = %.3lf", max1,
         min2, min3, max4);

  return 0;
}
