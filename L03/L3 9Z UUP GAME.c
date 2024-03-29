/*
Zadatak
Dat je neki niz prirodnih brojeva. Ako na svaki član tog niza primijenimo operaciju binarni XOR (ekskluzivna disjunkcija) sa nekim prirodnim brojem X dobićemo neki drugi niz prirodnih brojeva.

Recimo da niz glasi 4 2 3 1. Ako je X=6 dobićemo niz 2 4 5 7. Objašnjenje

image.png

Vaš zadatak je da napravite program koji za uneseni niz provjerava da li postoji X takvu da se nakon primjene XOR dobije niz koji je sortiran u rastućem poretku (ali ne strogo rastućem, dakle dozvoljeno je da dva susjedna člana budu jednaka). U prethodnom primjeru za niz 4 2 3 1 postoji takvo X i ono iznosi 6.

Najprije treba unijeti broj članova niza N (ne veći od 100), a zatim unijeti N prirodnih brojeva (nije potrebno provjeravati). Program treba ispisati najmanje X ako postoji, a ako X ne postoji, treba ispisati -1.

Primjer ulaza i izlaza:

       
Unesite N: 4
4 2 3 1
X=6
*/

// MOJ KOD:

#include <stdio.h>

int main() {
  int n;
  printf("Unesite N: ");
  scanf("%d", &n);

  int niz[100], x, max = 0, r[100];
  int i, j;

  for (i = 0; i < n; i++) {
    scanf("%d", &niz[i]);
    if (niz[i] > max) {
      max = niz[i];
    }
  }

  i = -1;
  int k;

provjera:
  while (i < 2 * max) {
    i++;
    for (j = 0; j < n; j++) {
      r[j] = i ^ niz[j];
    }
    for (k = 1; k < n; k++) {
      if (r[k] < r[k - 1]) {
        goto provjera;
      }
    }
    printf("X=%d", i);
    return 0;
  }

  if (i == 2 * max) {
    printf("X=-1");
    return 0;
  }
  return 0;
}
