/*
Zadatak
Napisati funkciju int potpun_kvadrat(int a) koja vraća vrijednost 1 ako je broj a potpun kvadrat (a je kvadrat nekog broja), a vraća vrijednost 0 u suprotnom. Na primjer, za broj 64 će biti vraćena vrijednost 1, jer je 64 = 82. U slučaju da se funkciji proslijedi negativan broj, zanemariti predznak te nastaviti rad kao da je proslijeđen pozitivan broj.

Pri rješavanju zadatka nije dozvoljeno koristiti biblioteku math.h.

Napisati i kraću main funkciju koja omogućuje testiranje napisane funkcije potpun_kvadrat. Primjeri ulaza i izlaza:

Unesite n: 64
Broj 64 je potpun kvadrat.
Drugi primjer:

Unesite n: 24
Broj 24 nije potpun kvadrat.
*/

// MOJ KOD:

#include <stdio.h>
#include <stdlib.h>

int potpun_kvadrat(int a);

int main() {
  int a;
  printf("Unesite n: ");
  scanf("%d", &a);
  if (potpun_kvadrat(a)) {
    printf("Broj %d je potpun kvadrat.", a);
  } else {
    printf("Broj %d nije potpun kvadrat.", a);
  }
  return 0;
}

int potpun_kvadrat(int a) {
  int i;
  a = abs(a);
  for (i = 1; i <= a; i++) {
    if (a == i * i) {
      return 1;
    }
  }
  return 0;
}