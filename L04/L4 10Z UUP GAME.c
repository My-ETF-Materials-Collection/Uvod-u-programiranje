/*
Zadatak
U matematici je poznat pojam Teplicove matrice. Teplicova matrica je matrica kod koje su svi elementi na glavnoj dijagonali međusobno jednaki, ali su i na svakoj dijagonali koja je paralelna sa glavnom dijagonalom svi elementi također međusobno jednaki. Primjer Teplicove matrice:

image.png

Također su poznate Cirkularne matrice. Cirkularna matrica je matrica kod koje svaki red ima iste elemente kao red iznad pomaknute za jedno mjesto u desno, pri čemu element koji je u prethodnom redu bio posljednji u sljedećem postaje prvi. Možemo zaključiti da je svaka cirkularna matrica ujedno i Teplicova, dok obrnuto ne važi. Primjer cirkularne matrice:

image.png

Napišite program koji korisniku omogućuje unos dva prirodna broja M i N manja ili jednaka od 100. Koristite do-while petlju da osigurate da su brojevi u traženom opsegu (jednu petlju za oba broja).

Zatim korisnik unosi matricu realnih brojeva čije su dimenzije MxN, te na kraju ispisuje jednu od poruka "Matrica je cirkularna", "Matrica je Teplicova" ili "Matrica nije ni cirkularna ni Teplicova".

Primjer ulaza i izlaza:


Unesite M i N: 101 5
Pogresan unos!
Unesite M i N: 99 -1
Pogresan unos!
Unesite M i N: 4 5
Unesite elemente matrice: 1 2 3 4 5 5 1 2 3 4 4 5 1 2 3 3 4 5 1 2
Matrica je cirkularna
Napomena: Zadatak obavezno riješiti koristeći matricu.
*/

// MOJ KOD:

#include <stdio.h>

int main() {
  int m, n, i, j, matrica[100][100];
  do {
    printf("Unesite M i N: ");
    scanf("%d %d", &m, &n);
    if (m > 100 || n > 100 || m <= 0 || n <= 0) {
      printf("Pogresan unos!\n");
    }
  } while (m > 100 || n > 100 || m <= 0 || n <= 0);

  printf("Unesite elemente matrice: ");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &matrica[i][j]);
    }
  }
  // pretpostavimo da jeste i teplic i cirkularna
  int Teplic = 1;
  int cirkularna = 1;

  for (i = 0; i < m - 1; i++) {
    for (j = 0; j < n - 1; j++) { //
      if (matrica[i][j] != matrica[i + 1][j + 1]) {
        Teplic = 0;
      }
    }
    if (matrica[0][n - 1 - i] != matrica[i + 1][0]) {
      cirkularna =0; // posto prvi red se ne mijenja, drugi su samo kombinacije prvog
             // zbog toga moze se staviti [0] za redove i porediti isto [0] za
             // kolone jer kolona prva je ista kao prvi obrnuto red
             // n-1-i je od clana zadnje kolone ka naprijed kako se i povecava
             // tako da time smo provjerili za sve brojeve da li se podudaraju
             // sa sljedecim redovima
    }
  }
  if (cirkularna == 1 && Teplic == 1) {
    printf("Matrica je cirkularna");
  } else if (Teplic == 1) {
    printf("Matrica je Teplicova");
  } else {
    printf("Matrica nije ni cirkularna ni Teplicova");
  }

  return 0;
}
