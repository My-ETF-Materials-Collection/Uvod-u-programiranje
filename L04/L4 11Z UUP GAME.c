/*
Zadatak
Napisati program za množenje matrica.
Od korisnika se prvo traži unos dvije matrice pozitivnih cijelih brojeva. Unos reda matrice se završava sa -1, a unos matrice sa -2, pri čemu pretpostavljamo da niti jedna matrica neće imati više od 100 redova i 100 kolona. Ukoliko se prekorače date dimenzije ili unesene vrijednosti ne čine matricu, prvom prilikom nakon pogrešnog unosa obavijestiti korisnika i završiti program. Nakon unosa obje matrice, provjeriti da li su one pogodne za množenje, te ako nisu ispisati odgovarajuću poruku. Ako su matrice pogodne za množenje, program računa i ispisuje proizvod matrica.

Primjeri ulaza i izlaza:
Primjer 1:

Unesite elemente 1. matrice: 
1 2 3 -1
4 5 6 -2
Unesite elemente 2. matrice:
1 2 -1
3 4 -1
5 6 -2
Matrice su pogodne za mnozenje. Matricni proizvod je:
   22   28
   49   64
Primjer 2:

Unesite elemente 1. matrice: 
1 2 3 4 -1
5 6 7 8 -2
Unesite elemente 2. matrice:
1 2 -1
3 4 -1
5 6 -2
Matrice nisu pogodne za mnozenje.

Primjer 3:

Unesite elemente 1. matrice: 
1 2 3 4 -1
5 6 7 8 -2
Unesite elemente 2. matrice:
1 2 -1
3 4 5 -1
Ovo nije matrica!
Napomena: Zadatak obavezno riješiti koristeći matrice.
*/

// MOJ KOD:

#include <stdio.h>

int main() {
  int matrica1[100][100], matrica2[100][100], i = 0, j = 0, krajunosa = 0, k, suma = 0;
  int brkolona1 = 100, brredova1, brkolona2 = 100, brredova2, matrica[100][100];

  //unos prve matrice
  printf("Unesite elemente 1. matrice:\n");
  do {
    j = 0;
    do {
      scanf("%d", &matrica1[i][j]);
      if (i==0 && matrica1[i][j] == -1) {
        brkolona1 = j;
        break;
      }
      if (matrica1[i][j] == -1){
        if (j != brkolona1){
          printf("Ovo nije matrica!");
          return 0;
        }
        break;
      }
      if (matrica1[i][j] == -2) {
        if (j != brkolona1) {
          printf("Ovo nije matrica!");
          return 0;
        }
        krajunosa = 1;
        break;
      }
      j++;
    } while (j < 100);
    i++;
    if (krajunosa == 1) {break;}
    if (brkolona1 >= 100) {
      printf("Prekoracena dimenzija matrice!");
      return 0;
    }
  } while (i < 100);
  krajunosa = 0;
  brredova1 = i;
  i = 0;
  j = 0;

  //unos druge matrice
  printf("Unesite elemente 2. matrice:\n");
  do {
    j = 0;
    do {
      scanf("%d", &matrica2[i][j]);
      if (i==0 && matrica2[i][j] == -1) {
        brkolona2 = j;
        break;
      }
      if (matrica2[i][j] == -1) {
        if (j != brkolona2) {
          printf("Ovo nije matrica!");
          return 0;
        }
        break;
      }
      if (matrica2[i][j] == -2) {
        if (j != brkolona2) {
          printf("Ovo nije matrica!");
          return 0;
        }
        krajunosa = 1;
        break;
      }
      j++;
    } while (j < 100);
    i++;
    if (krajunosa == 1) {break;}
    if (brkolona2 >= 100) {
      printf("Prekoracena dimenzija matrice!");
      return 0;
    }
  } while (i < 100);

  brredova2 = i;
  if (brkolona1 == brredova2){
    printf("Matrice su pogodne za mnozenje. ");
  }else {
    printf("Matrice nisu pogodne za mnozenje.");
    return 0;
  }
  
  //proizvod matrice 
  for (i = 0; i < brredova1; i++){
    for (j = 0; j < brkolona2; j++) {
      suma = 0;
      for (k = 0; k < brkolona1; k++){
        suma += matrica1[i][k] * matrica2[k][j];}
      matrica[i][j] = suma;
    }}
    
  printf("\nMatricni proizvod je:\n");
  for (i = 0; i < brredova1; i++) {
    for (j = 0; j < brkolona2; j++){
      printf("%d ", matrica[i][j]);}
    printf("\n");
  }

  return 0;
}
