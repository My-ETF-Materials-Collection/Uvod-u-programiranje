/*
Zadatak
Napisati program koji prvo od korisnika traži da unese dimenzije matrica A i B, zatim unosi elemente tih matrica, te vertikalno nadovezuje (konketuje) matrice A i B u matricu C, koju ispisuje na ekranu na 4 mjesta širine. Ako matrice nisu saglasne za nadovezivanje (nemaju isti broj redova) ili ako su unesene dimenzije prevelike (veće od 10), program ispisuje grešku i završava s radom.

Primjeri ulaza i izlaza:

Unesite dimenzije matrice A (p q): 2 3
Unesite dimenzije matrice B (r s): 3 3
Matrica A:
1. red: 1 2 3
2. red: 3 2 1
Matrica B:
1. red: 0 0 0
2. red: 5 6 7
3. red: 9 8 7
Matrica C:
   1   2   3
   3   2   1
   0   0   0
   5   6   7
   9   8   7
Napomena: Pri rješavanju zadatka obavezno deklarisati i unijeti matrice A i B, zatim popuniti matricu C odgovarajućim brojevima, te na kraju ispisati matricu C na ekran. Zadaci koji ne budu urađeni na ovaj način neće biti priznati!
*/

// MOJ KOD:

#include <stdio.h>

int main() {
  int p, q, r, s;
  int m1[10][10];
  int m2[10][10];
  int i, j;

  printf("Unesite dimenzije matrice A (p q): ");
  scanf("%d %d", &p, &q);

  if (p > 10 || q > 10) {
    printf("Matrica A je prevelika!");
    return 0;
  } else if (p <= 0 || q <= 0) {
    printf("Neispravne dimenzije matrice!");
    return 0;
  }

  printf("Unesite dimenzije matrice B (r s): ");
  scanf(" %d %d", &r, &s);

  if (r <= 0 || s <= 0) {
    printf("Neispravne dimenzije matrice!");
    return 0;
  }
  if (q != s) {
    printf("Matrice nisu saglasne za konkatenaciju!");
    return 0;
  }
  if (r > 10 || s > 10) {
    printf("Matrica B je prevelika!");
    return 0;
  }
  printf("Matrica A: ");
  for (i = 0; i < p; i++) {
    printf("%d. red: ", i + 1);
    for (j = 0; j < q; j++) {
      scanf(" %d", &m1[i][j]);
    }
  }

  printf("Matrica B: ");
  for (i = 0; i < r; i++) {
    printf("%d. red: ", i + 1);
    for (j = 0; j < s; j++) {
      scanf(" %d", &m2[i+p][j]);
    }
  }

  int m3[10][10];
  int k;
  for (i = 0; i < p; i++) {
    for (j = 0; j < q; j++) {
      m3[i][j] = m1[i][j];
    }
  }

  for (i = p; i < p + r; i++) {
    for (j = 0; j < q; j++) {
      m3[i][j] = m2[i][j];
    }
  }

  printf("Matrica C:\n");
  for (i = 0; i < p + r; i++) {
    for (j = 0; j < q; j++) {
      for (k = 1; k <= 3; k++) {
        printf(" ");
      }
      printf("%d", m3[i][j]);
    }
    printf("\n");
  }
  return 0;
}