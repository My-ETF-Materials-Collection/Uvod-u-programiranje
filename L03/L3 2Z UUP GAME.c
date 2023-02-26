/*
Zadatak
Napisati program koji od korisnika traži unos najviše 100 elemenata (sa -1 se unos prekida). Program zatim od korisnika traži da unese neki broj n i ispituje da li je broj n među unesenim brojevima. Ako nije, treba ispisati odgovarajuću poruku (pogledati drugi primjer), a ukoliko jeste, treba reći koji je po redu broj n unesen, pri čemu se gleda samo posljednji unos broja n.

Primjeri ulaza i izlaza:
Primjer 1:

Unesite 1. element (-1 za kraj unosa): 1
Unesite 2. element (-1 za kraj unosa): 5
Unesite 3. element (-1 za kraj unosa): 3
Unesite 4. element (-1 za kraj unosa): 7
Unesite 5. element (-1 za kraj unosa): 3
Unesite 6. element (-1 za kraj unosa): 7
Unesite 7. element (-1 za kraj unosa): 9
Unesite 8. element (-1 za kraj unosa): -1
Unesite broj za pretragu: 7
Broj 7 je unesen kao 6. broj po redu.
U ovom primjeru broj 7 se nalazi na dvije pozicije (4. i 6.) Program treba ispisati 6 jer je to posljednje pojavljivanje broja 7.

Primjer 2:

Unesite 1. element (-1 za kraj unosa): 1
Unesite 2. element (-1 za kraj unosa): 2
Unesite 3. element (-1 za kraj unosa): 3
Unesite 4. element (-1 za kraj unosa): -1
Unesite broj za pretragu: 5
Broj 5 se ne nalazi medju unesenim brojevima!
*/

// MOJ KOD:

#include <stdio.h>

int main() {
    double n, niz[100]={0};
    int i,velicina=0, j;
  for (i = 1; i<100; i++) {
    printf("Unesite %d. element (-1 za kraj unosa): \n", i);
    scanf("%lf", &niz[i]);
    if(niz[i]==-1){
          break;
      }
    
  }
  double p;
  int pozicija;
  int nema=0;
  printf("Unesite broj za pretragu: \n");
  scanf("%lf", &p);
  velicina=i;
  for(i=1; i<=velicina; i++){
      if(niz[i]==p){
              pozicija=i;
        }else{
            nema++;
        }
      for(j=i+1; j<velicina; j++){
          if(niz[i]==niz[j]){
              pozicija=j;
          }
      }
  }
      if(nema==velicina){
          printf("Broj %g se ne nalazi medju unesenim brojevima!",p);
          return 0;
      }else{
          printf("Broj %g je unesen kao %d. broj po redu.", p, pozicija);
      }


  return 0;
}