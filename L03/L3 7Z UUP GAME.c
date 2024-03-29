/*
Zadatak
Napisati program koji od korisnika traži unos n elemenata niza (ne više od 200), unos se prekida brojem -1 (koji se ne unosi u niz). Program nakon toga treba pronaći i ispisati najmanji i drugi najmanji broj u unesenom nizu.

Primjeri ulaza i izlaza:

Unesite 1. element (-1 za kraj unosa): 10
Unesite 2. element (-1 za kraj unosa): 5
Unesite 3. element (-1 za kraj unosa): 8
Unesite 4. element (-1 za kraj unosa): 1
Unesite 5. element (-1 za kraj unosa): 3
Unesite 6. element (-1 za kraj unosa): 8
Unesite 7. element (-1 za kraj unosa): -1
Niz glasi:
10 5 8 1 3 8 
Najmanji broj je: 1
Drugi najmanji broj je: 3

Unesite 1. element (-1 za kraj unosa): 1
Unesite 2. element (-1 za kraj unosa): 1
Unesite 3. element (-1 za kraj unosa): 1
Unesite 4. element (-1 za kraj unosa): -1
Niz glasi:
1 1 1 
Najmanji broj je: 1
Drugi najmanji broj je: 1
Napomena: U postavci zadatka je dat polazni kod - nije dozvoljeno promijeniti ovaj kod! Vaše rješenje zadatka napišite umjesto komentara === OVDJE UBACITI KOD === a ono što se nalazi prije i poslije toga nipošto nemojte mijenjati jer vam neće prolaziti testovi!

Pored toga, nije dozvoljeno kreirati pomoćni niz.
*/

//MOJ KOD:

#include <stdio.h>

int main() {
  double niz[200], najmanji = -1, drugi = -1;
  int i, vel;

  for (i = 0; i < 200; i++) {
    printf("Unesite %d. element (-1 za kraj unosa): ", i + 1);
    scanf("%lf", &niz[i]);
    if (niz[i] == -1)
      break;
  }
  vel = i;

  int j;
  double p;
  for(i=0; i<vel; i++){
      if(niz[0]<niz[1]){
        najmanji=niz[0];
        drugi=niz[1];      
      }else{
        najmanji=niz[1];
        drugi=niz[0];
      }
      
  }
  for (i = 2; i < vel; i++) {
    if (najmanji > niz[i]) {
        drugi=najmanji;
        najmanji=niz[i];
      }else if(najmanji==drugi){
        najmanji=drugi=niz[i];
      }else if(niz[i]<drugi && niz[i]>najmanji){
          drugi=niz[i];
      }
    }

    if(vel==0){
        najmanji=drugi=0;
    }else if(vel==1){
        najmanji=drugi=niz[0];
    }

  printf("Niz glasi:\n");
  for (i = 0; i < vel; i++)
    printf("%g ", niz[i]);
  printf("\nNajmanji broj je: %g\n", najmanji);
  printf("Drugi najmanji broj je: %g\n", drugi);

  return 0;
}
