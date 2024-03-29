/*
Zadatak
Napišite funkciju izbaci_iste_cifre. Funkcija prima dva niza cijelih brojeva A i B. Funkcija treba iz niza B izbaciti (bez promjene redoslijeda!) sve članove koji se sastoje od istih cifara kao neki (bilo koji) od članova niza A. Npr. broj 7731 se sastoji od istih cifara kao broj 33117 (a to su cifre 1, 3 i 7).

Napišite i glavni program koji omogućuje najprije unos niza A od najviše 100 elemenata, pri čemu se unos završava brojem -1, zatim unos istog takvog niza B. (Obratite pažnju da je ovo ograničenje za main, funkcija treba raditi i sa nizovima od više od 100 elemenata). Glavni program zatim poziva napravljenu funkciju izbaci_iste_cifre te na kraju ispisuje članove niza B razdvojene zarezom, ali tako da se nakon posljednjeg člana niza ne nalazi zarez nego tačka.

Primjer ulaza i izlaza:

Unesite niz A: 8 9 7 169 121 18 11 -1
Unesite niz B: 7 1 2 818 96 12 16 999 -1
2,96,16.
Napomena: U zadatku je strogo zabranjeno koristiti pomoćne nizove tj. deklarisati bilo kakav niz osim nizova A i B koji su deklarisani u main funkciji! Rješenje u kojem budu korišteni pomoćni nizovi će biti bodovano sa 0 bodova!
*/

// MOJ KOD:

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int iste_cifre(int a, int b) {

  int i;
  a = abs(a);
  b = abs(b);

  int bra[10] = {0}, brb[10] = {0};

  // prebrojati koliko se cifre broja a javljaju
  while (a > 0) {  // 4423
    bra[a % 10]++; // 0 0 1 1 2 0 0 0 0
    a /= 10;
  }
  // prebrojati koliko se cifre broja b javljaju
  while (b > 0) {  // 332
    brb[b % 10]++; // 0 0 1 2 0 0 0 0 0
    b /= 10;
  }
  // ako se na istim indexima javljaju razlicite vrijednosti return 0
  for (i = 0; i < 10; i++) {
    if ((bra[i] == 0 && brb[i] > 0) || (bra[i] > 0 && brb[i] == 0)) {
      return 0;
    }
  }
  return 1;
}
int izbaci_iste_cifre(int *niz1, int vel1, int *niz2, int vel2) {
  int i, j, k;
  for (j = 0; j < vel2; j++) {
    for (i = 0; i < vel1; i++) {
      if (iste_cifre(niz2[j], niz1[i])) {
        for (k = j; k < vel2-1; k++) //k=3,k<3
          niz2[k] = niz2[k+1];
        //if(k==vel2-1) 
        i--;
        vel2--;
        j--;
        break;
      }
    }
  }
  return vel2;
}

int main() {
  int nizA[100] = {0}, nizB[100] = {0}, i, velA = 0, velB = 0;
  printf("Unesite niz A: ");
  for (i = 0; i < 100; i++) {
    scanf("%d", &nizA[i]);
    if (nizA[i] == -1)
      break;
    velA++;
  }
  printf("Unesite niz B: ");
  for (i = 0; i < 100; i++) {
    scanf("%d", &nizB[i]);
    if (nizB[i] == -1)
      break;
    velB++;
  }
  velB=izbaci_iste_cifre(nizA, velA, nizB, velB);
  for (i = 0; i < velB; i++) {
    if (i == velB - 1) {
      printf("%d.", nizB[i]);
    } else
      printf("%d,", nizB[i]);
  }

  return 0;
}
