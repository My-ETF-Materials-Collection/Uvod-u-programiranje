/*
Zadatak
Napišite funkciju pod imenom daj_prost koja nema parametara, a svaki put kada se pozove vraća sljedeći prost broj. Kada prvi put pozovete funkciju, ona treba vratiti broj 2, drugi put treba vratiti broj 3, zatim broj 5, 7, 11 itd.

Ovu funkciju iskoristite u programu koji omogućuje korisniku da unese prirodne brojeve A i B takve da je A<B, a zatim ispisuje sumu svih prostih brojeva strogo većih od A a strogo manjih od B. U ovom programu se obavezno mora iskoristiti napravljena funkcija daj_prost, ne smiju se računati prosti brojevi na neki drugi način.

Primjer ulaza i izlaza:

    
	Unesite brojeve A i B: 0 15
	A nije prirodan broj.
	Unesite brojeve A i B: 5 -5
	A nije manje od B.
	Unesite brojeve A i B: 10 10
	A nije manje od B.
	Unesite brojeve A i B: -5 -7
	A nije prirodan broj.
	Unesite brojeve A i B: 2 10
	Suma prostih brojeva izmedju 2 i 10 je 15.
Objašnjenje: 3+5+7 = 15.

Pri rješavanju zadatka nije dozvoljeno koristiti globalne promjenljive.
*/

// MOJ KOD:

#include <stdio.h>

long int daj_prost();

int main() {
  long int a, b, suma=0, br, i;
  do {
    printf("Unesite brojeve A i B: ");
    scanf("%ld %ld", &a, &b);
    if (a >= b && a > 0) {
      printf("A nije manje od B.\n");
    } else if (a <= 0) {
      printf("A nije prirodan broj.\n");
    } else if (b <= 0) {
      printf("B nije prirodan broj.\n");
    }
  } while (a >= b || a <= 0 || b <= 0);

    while(1){
        br=daj_prost();
        if(br>a && br<b){
            suma+=br;
        }else if(br>b){
            break;
        }
    }

  printf("Suma prostih brojeva izmedju %ld i %ld je %ld.", a, b, suma);
  return 0;
}

long int daj_prost(){
  long int suma = 0, prost;
  static long int p=2;
  long int i, j, a, b;
  for (i=p; ; i++) {
      prost=1;
    for (j = 2; j <=i/2; j++) {
      if (i % j == 0) {
        prost=0;
        break;
      }
    }
    p++;
    if(prost){
      return i;
  }
 }
}

