/*
Zadatak
Napišite funkciju obrnut koja vraća primljeni pozitivan cijeli broj okrenut naopako. Npr. ako se funkcija pozove sa vrijednošću 12345 (dvanaest hiljada tristo četrdeset i pet), treba vratiti broj 54321 (pedeset četiri hiljade tristo dvadeset i jedan). Pri tome nije dozvoljeno koristiti nizove niti raditi bilo kakav ispis u funkciji!

Napisati i kraću main funkciju koja omogućuje testiranje napisane funkcije obrnut. Primjer ulaza i izlaza:

Unesite broj: 12345
Broj 12345 okrenut naopako glasi 54321.
*/

// MOJ KOD:

#include <stdio.h>

int obrnut(int n);

int main() {
  int n;
  printf("Unesite broj: ");
  scanf("%d", &n);
  printf("Broj %d okrenut naopako glasi %d.",n,obrnut(n));
  return 0;
}

int obrnut(int n) {//12345
  int suma=0;
  while(n!=0){
      suma = suma*10 + n%10;//0+5->5*10+4=54->54*10+3--->54321
      n/=10;
  }
  return suma;
}