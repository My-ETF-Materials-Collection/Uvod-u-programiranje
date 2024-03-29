/*
Zadatak
Napisati funkciju dva_od_tri koja prima tri niza cijelih brojeva različite veličine, a vraća broj članova koji se javljaju u dva od tri niza (bez ponavljanja). Obratite pažnju da ne treba brojati članove koji se nalaze u sva tri niza, nego samo one koji se nalaze u dva od tri niza!

Primjer: Recimo da nizovi glase ovako:
1 2 3 5
1 2 4 6 7
1 3 4 8 9 10
Funkcija treba vratiti broj 3 jer:

Brojevi 2, 3 i 4 se nalaze u dva od tri niza. Broj 2 se nalazi u prvom i drugom, 3 u prvom i trećem, a 4 u drugom i trećem.
Broj 1 se nalazi u sva tri niza pa ga ne brojimo.
Brojevi 5, 6, 7, 8, 9 i 10 se nalaze u samo po jednom nizu, pa ni njih ne računamo.
Napomena: Pri rješavanju ovog zadatka (a ni inače), nije dozvoljeno kreirati pomoćni niz u funkciji ako ne znamo koliko veliki niz nam treba, čak i ako zadatak prolazi sve testove.
*/

// MOJ KOD:

#include <stdio.h>

int jelvecbio(int niz[100], int doIndex, int broj){
    int i;
    for(i=0;i<doIndex;i++){
        if(niz[i]==broj) return 1;
    }
    return 0;
}

int kombinacija(int A[100], int velA, int B[100], int velB, int C[100], int velC){
    int brojac = 0;
    int i, j, k;

    for (i = 0; i < velA; i++) {
        if(!jelvecbio(A,i,A[i])){
            for (j = 0; j < velB; j++) {
                 if (A[i] == B[j] && !jelvecbio(B,j,B[j])) {
                    if (velC == 0) {
                        brojac++;
                        break;
                    } else {
                    for (k = 0; k < velC; k++) {
                        if (A[i] == C[k]) {
                        break;
                        }
                        if (k == velC - 1) {
                        brojac++;
                        break;
                        }
                    }
                    }
                }
                }
            }
        }        
      return brojac;  
}

int dva_od_tri(int A[100], int velA, int B[100], int velB, int C[100],
               int velC) {

    int brojac = 0;
    int i, j, k;

    brojac+=kombinacija(A,velA,B,velB,C,velC);
    brojac+=kombinacija(A,velA,C,velC,B,velB);
    brojac+=kombinacija(B,velB,C,velC,A,velA);

  return brojac;
}

int main() {
  int A[100], B[100], C[100], velA, velB, velC, i, rez;

  printf("Unesite niz A (-1 za kraj): ");
  for (i = 0; i < 100; i++) {
    scanf("%d", &A[i]);
    if (A[i] == -1)
      break;
  }
  velA = i;
  printf("Unesite niz B (-1 za kraj): ");
  for (i = 0; i < 100; i++) {
    scanf("%d", &B[i]);
    if (B[i] == -1)
      break;
  }
  velB = i;
  printf("Unesite niz C (-1 za kraj): ");
  for (i = 0; i < 100; i++) {
    scanf("%d", &C[i]);
    if (C[i] == -1)
      break;
  }
  velC = i;

  rez = dva_od_tri(A, velA, B, velB, C, velC);

  printf("%d clanova se nalaze u dva od tri niza.", rez);
  return 0;
}
