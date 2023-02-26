/*
Zadatak
Napisati program koji omogućuje unos kvadratne matrice cijelih brojeva dimenzija NxN (N nije veće od 100). Korisnik najprije unosi broj N (do-while petljom osigurati da je u traženom opsegu), zatim unosi elemente matrice. Zatim se ispisuje vrsta matrice, tj. jedan od sljedećih tekstova:

Nul-matrica (matrica čiji su svi elementi 0)
Jedinicna matrica (dijagonalna matrica na čijoj dijagonali su svi elementi jedinice),
Dijagonalna matrica (kod koje su svi elementi van glavne dijagonale 0)
Gornja trougaona matrica (kod koje su svi elementi ispod glavne dijagonale 0)
Donja trougaona matrica (kod koje su svi elementi iznad glavne dijagonale 0)
Sporedna dijagonalna matrica (matrica kod koje su svi elementi van sporedne dijagonale 0)
Nista od navedenog

Ako matrica ispunjava više uslova odjednom, treba ispisati tekst koji se u tabeli nalazi prije. Npr. jedinična matrica je ujedno i dijagonalna ali za nju treba ispisati "Jedinicna matrica".

Napomena: Zadatak obavezno riješiti koristeći matricu.
*/

// MOJ KOD:

#include <stdio.h>

int main() {
  int n, i, j, matrica[100][100];
  int N = 1;
  int I = 1;
  int D = 1;
  int U = 1;
  int L = 1;
  int S = 1;

  printf("Unesite broj N: ");
  scanf("%d", &n);

  printf("Unesite elemente matrice: ");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &matrica[i][j]);
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        if (matrica[i][j] != 0) {
          N = 0;
        }
        if (matrica[i][j] != 1 && matrica[j][i] != 0) {
          I = 0;
        } 
        if (matrica[i][j] != 0 && j!=i) {
          D = 0;
        } 
        if (j-i<0 && matrica[i][j]!=0) {
          U = 0;
        } 
        if (j-i>0 && matrica[i][j]!=0) {
          L = 0;
        } 
        if (j!=i && matrica[i][n-i]!=0) {
          S = 0;
        }
    }
  }
  if (N == 1) {
    printf("Nul-matrica");
    return 0;
  } else if (I == 1) {
    printf("Jedinicna matrica");
    return 0;
  } else if (D == 1) {
    printf("Dijagonalna matrica");
    return 0;
  } else if (U == 1) {
    printf("Gornja trougaona matrica");
    return 0;
  } else if (L == 1) {
    printf("Donja trougaona matrica");
    return 0;
  } else if (S == 1) {
    printf("Sporedna dijagonalna matrica");
    return 0;
  } else {
    printf("Nista od navedenog");
  }

  return 0;
}
