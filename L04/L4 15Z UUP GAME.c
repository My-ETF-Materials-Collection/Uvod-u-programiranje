/*
Zadatak
Napisati program koji na ekranu iscrtava stupčasti grafik (bar graph) na osnovu unesenog niza brojeva, koristeći znakove | (vertikalna linija), * (zvjezdica) i - (minus).
Program najprije omogućuje unos niza od maksimalno 20 elemenata na intervalu [-10,10]. Unos niza se prekida kada korisnik unese vrijednost 999. Ukoliko korisnik unese neku vrijednost van intervala [-10,10] koja nije 999, potrebno je ispisati poruku "Broj nije u trazenom intervalu" i prekinuti rad programa. Nakon završetka unosa iscrtavaju se vertikalni stupci sastavljeni od onoliko znakova | kolika je vrijednost člana niza, pri čemu se umjesto posljednjeg člana niza stavlja znak * (zvjezdica). Između svaka dva stupca se nalaze po dva znaka razmaka. Potrebno je iscrtati i vodoravnu crtu koja označava nulu. Za članove niza čija je vrijednost nula treba staviti zvjezdicu na vodoravnu crtu.

Primjer ulaza i izlaza:


Unesite članove niza: 4 -3 7 0 -1 999
      *
      |
      |
*     |
|     |
|     |
|     |
---------*-----
   |        *
   |
   *
*/

// MOJ KOD:

/*
kolika je vrijednost clana niza toliko je i duzina vertikalnog stupca
najbolje naci prvo koji clan je najveci jer ce to biti najvisi stupac, a
ujedno i najmanji clan jer ce biti ispod x ose zajedno te duzine sa x osom cine
ukupnu visinu ove matrice za sirinu je potrebno vidjeti koliko elemenata ima
ovaj niz jer matrica krece od prvog clana onda sve poslije je sa dva razmaka pa
je to ukupna sirina = brClanova + brRazmaka = brClanova + brClanova * 2 = 3 *
brClanova

    raspisati ovu x osu:
    matrica[red za jedan veci od duzine max elementa][j]=matrica[xi][j]

    raspisati stupce:
    za clanove niza koji su 0 ide if(niz[i]==0) matrica[xi][3i]
    if(niz[i]>0) ...
    if(niz[i]<0) ...

*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  int niz[20];
  int i, j;
  int brClanova = 0;
  printf("Unesite clanove niza: ");
  for (i = 0; i < 20; i++) {
    int unos;
    scanf("%d", &unos);
    if (unos == 999) {
      break;
    }else if (unos < -10 || unos > 10) {
      printf("Broj nije u trazenom intervalu");
      return 0;
    } else {
      niz[i] = unos;
      brClanova++;
    }
  }
  if(i==0){
       return 0;
  }
  int max = niz[0], min = niz[0]; // odredjivanje broja redova (max + min + 1)

  for (i = 0; i < brClanova; i++) {
    if (niz[i] > max) {
      max = niz[i];
    }
    if (niz[i] < min) {
      min = niz[i];
    }
  }
  if(max<0) max = 0; 
if(min>0) min =0;
  printf("\n");
  int brRedova = max + abs(min) + 1;
  for (i = 0; i < brRedova; i++) {
    for (j = 0; j < brClanova; j++) {
      if (i == max) { // red crtica
        if (niz[j] == 0)
          printf("*"); // ukoliko je broj jednak 0 (red crtica predstavlja nulu)
        else
          printf("-"); // za ostale brojeve
      } else if (i == 0) {
        if (niz[j] == max)
          printf("*"); // kad je i=0 za maksimalan broj u nizu staviti zvjezdicu
        else
          printf(" "); // za ostale brojeve razmak
      } else if (i == max - niz[j] && i < max &&
                 niz[j] > 0) { // za pozitivne brojeve
        printf("*");           // za vrh stubića staviti *
      } else if (i > max - niz[j] && i < max &&
                 niz[j] > 0) { // za pozitivne brojeve
        printf("|");           // za tijelo stubića staviti |
      } else if (i < max) {
        printf(" "); // za nepostojeće pozitivne stubiće
      } else if (i > max && i == brRedova - abs(min) + abs(niz[j]) - 1 &&
                 niz[j] < 0) { // za negativne brojeve
        printf("*");           // za vrh negativnog stubića staviti *
      } else if (i > max && i < brRedova - abs(min) + abs(niz[j]) - 1 &&
                 niz[j] < 0) { // za negativne brojeve
        printf("|");           // za tijelo negativnog stubića staviti |
      } else
        printf(" "); // za nepostojeće negativne stubiće

      if (i == max)
        printf("--"); // za nulu(red crtica) treba dodati dvije crtice poslije
                      // broja
      else
        printf("  "); // za ostale redove dodati dva razmaka poslije broja
    }
    printf("\n");
  }
  return 0;
}