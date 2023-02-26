/*
Zadatak
Zamislimo da na ekranu imamo koordinatni sistem sastavljen od 20x20 mjesta. Ishodište koordinatnog sistema je u gornjem lijevom uglu i ono odgovara koordinatama (0,0).
Omogućite korisniku da unese najviše 10 tačaka koristeći koordinate [0,19]. Zatim iscrtajte oblik sastavljen od znakova zvjezdica (asterisk) na onim koordinatama koje je korisnik unio, a na ostalim lokacijama prazno mjesto. U slučaju da je unesen neispravan broj tačaka ili koordinate izvan dozvoljenog opsega treba ispisati poruku "Pogresan unos" i zatražiti da se ponovo unese broj tačaka odnosno koordinate te tačke.

Primjer ulaza i izlaza:


Unesite broj tacaka: 4
Unesite 1. tacku: 1 1
Unesite 2. tacku: 2 2
Unesite 3. tacku: 3 1
Unesite 4. tacku: 4 0
   *
* *
 *
(radi uštede prostora izostavili smo 16 praznih redova ispod nacrtanog oblika)
*/

// MOJ KOD: 

#include <stdio.h>

int main() {

  int n, M[20][20] = {0}, i = 0, j = 0, x, y;

UNOS:
  printf("Unesite broj tacaka: ");
  scanf("%d", &n); // 4
  if (n > 10 || n <= 0) {
    printf("Pogresan unos\n");
    goto UNOS;
  }

  do {
    printf("Unesite %d. tacku: ", i + 1);
    scanf("%d %d", &x, &y); // 1 1
    if (x < 0 || x > 19 || y < 0 || y > 19) {
      printf("Pogresan unos\n");
    } else {
      i++; // 1
      M[x][y] = 1;
    }
  } while (i < n || x < 0 || x > 19 || y > 19 || y < 0);

  for (i = 0; i < 20; i++) {
    for (j = 0; j < 20; j++) {
      if (M[j][i] == 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}
