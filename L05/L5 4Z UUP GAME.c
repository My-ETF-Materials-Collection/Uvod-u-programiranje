/*
Zadatak
Napisati funkciju double stepen (double b, int e) koja vraća potenciju broja b^e bez korištenja funkcije pow. Funkcija treba da radi i sa negativnim eksponentom.

Napisati i kraću main funkciju koja omogućuje testiranje napisane funkcije stepen. Primjer ulaza i izlaza:

Unesite bazu: 0.1
Unesite eksponent: 2
0.1^2 je 0.01.
*/

// MOJ KOD:

#include <stdio.h>
#include <stdlib.h>

double stepen(double b, int e);

int main() {
  double b;
  int e;

  printf("Unesite bazu: ");
  scanf("%lf", &b);
  printf("\nUnesite eksponent: ");
  scanf("%d", &e);

  printf("%g^%d je %g.", b, e, stepen(b, e));

  return 0;
}

double stepen(double b, int e) { // 0,5 -3
  int i;
  double x = b;
  if (e >= 0) {
    for (i = 1; i < e; i++) {
      b = b * x;
    }
    return b;
  } else {
    for (i = 1; i < -e; i++) {
      b = b * x;
    }
    return 1/b;
  }
}