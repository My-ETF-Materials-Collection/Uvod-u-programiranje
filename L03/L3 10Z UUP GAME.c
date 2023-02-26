/*
Zadatak
Napisati program koji omogućuje unos proizvoljnog broja pozitivnih cijelih brojeva (maksimalno 100, a minimalno 3 elementa) u niz A. Unos se prekida unosom broja -1.

Program treba provjeriti da li je uneseni niz v-niz. V-niz je niz kod kojeg su svi elementi najprije strogo opadajući do nekog elementa koji je minimum niza, a nakon njega su svi elementi strogo rastući. Ako je minimum prvi ili posljednji član niza, taj niz se ne smatra v-nizom.

Primjeri:
4 2 1 5 10 - niz je v-niz
5 5 4 3 4 5 - niz nije v-niz jer su prva dva elementa jednaka (nije strogo opadajući)
8 5 3 7 2 4 6 10 - niz nije v-niz jer ima dva lokalna minimuma
*/

// MOJ KOD:

#include <stdio.h>

int main() {

  int i, a[100], brojac = 0;

  for (i = 0; i < 100; i++) {
    scanf("%d", &a[i]);
    if (a[i] == -1 && brojac < 3) {
      printf("Nedovoljno elemenata");
      return 0;
    } else if (a[i] == -1) {
      break;
    }
    brojac++;
  }

  double min = a[0];
  i = 0;
  int pozicija;

  for (i = 0; i < brojac; i++) {
    if (min > a[i]) {
      min = a[i];
      pozicija=i;
    }
  }

  int opdomin = 0;
  int rasposmin = 0;
  i = 0;

  for (i = 0; i < brojac; i++) {
    double d = a[i + 1] - a[i];
    if (d < 0) {
      opdomin++;
    }
    if (d > 0) { 
      rasposmin++;
    }
    if (d == 0 || (d > 0 && i<pozicija)) {
      printf("Niz nije v-niz");
      return 0;
    }
  }

  if (opdomin > 0 && rasposmin > 0) {
    printf("Niz je v-niz");
  } else {
    printf("Niz nije v-niz");
  }

  return 0;
}
