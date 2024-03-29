/*
Zadatak
Napisati program koji omogućuje unos tri niza cijelih brojeva različite veličine, a ispisuje na ekran broj članova koji se javljaju u dva od tri niza (bez ponavljanja). Obratite pažnju da ne treba brojati članove koji se nalaze u sva tri niza, nego samo one koji se nalaze u dva od tri niza!

Primjer ulaza i izlaza:

           
Unesite broj clanova prvog niza: 4
Unesite prvi niz: 1 2 3 5
Unesite broj clanova drugog niza: 5
Unesite drugi niz: 1 2 4 6 7
Unesite broj clanova treceg niza: 6
Unesite treci niz: 1 3 4 8 9 10
U dva od tri niza se nalazi 3 clanova.
Objašnjenje: Brojevi 2, 3 i 4 se nalaze u dva od tri niza. Broj 2 se nalazi u prvom i drugom, 3 u prvom i trećem, a 4 u drugom i trećem. Broj 1 se nalazi u sva tri niza pa ga ne brojimo. Brojevi 5, 6, 7, 8, 9 i 10 se nalaze u samo po jednom nizu, pa ni njih ne računamo

Napomena: Rješenje koje uvijek ispisuje isti broj članova koji se ponavljaju ili hardcodira rješenja (npr. ako je niz jednak nekom iz autotesta uvijek ispisuje DA ili NE) biće bodovana sa 0 bodova bez obzira na potencijalno ispravne dijelove koda!
*/

// MOJ KOD:

#include <stdio.h>

int main() {

  int a[100], b[100], c[100];
  int avel, bvel, cvel;
  int i, j, k;
  int brojac = 0;

  printf("Unesite broj clanova prvog niza: ");
  scanf("%d", &avel);
  printf("Unesite prvi niz: ");
  for (i = 0; i < avel; i++) {
    scanf("%d", &a[i]);
  }
  i = 0;
  printf("Unesite broj clanova drugog niza: ");
  scanf("%d", &bvel);
  printf("Unesite drugi niz: ");
  for (i = 0; i < bvel; i++) {
    scanf("%d", &b[i]);
  }
  i = 0;
  printf("Unesite broj clanova treceg niza: ");
  scanf("%d", &cvel);
  printf("Unesite treci niz: ");
  for (i = 0; i < cvel; i++) {
    scanf("%d", &c[i]);
  }
  i = 0;
  int pon1=a[0], pon2=b[0], pon3=c[0];
  for (i = 0; i < avel; i++) {
      if(a[i]==pon1 && i!=0){continue;}
    for (j = 0; j < bvel; j++) {
        if(b[j]==pon2 && j!=0){continue;}
      if (a[i] == b[j]) {
          if(cvel==0){
              brojac++;
              break;
          }else{
            for (k = 0; k < cvel; k++) {
          if (a[i] == c[k]) {
            break;
          }
          if (k == cvel - 1) {
            brojac++;
            break;
          }
        }  
      }
    pon2=b[j];
      }
    pon1=a[i];
    }
  }
  i = j = k = 0;
  for (i = 0; i < avel; i++) {
      if(a[i]==pon1 && i!=0){continue;}
    for (j = 0; j < cvel; j++) {
        if(c[j]==pon3 && j!=0){continue;}
      if (a[i] == c[j]) {
          if(bvel==0){
              brojac++;
              break;
          }else{
              for (k = 0; k < bvel; k++) {
          if (a[i] == b[k]) {
            break;
          }
          if (k == bvel - 1) {
            brojac++;
            break;
          }
        }
          }
    pon3=c[j];
      }
    pon1=a[i];
    }
  }
  i = j = k = 0;
  for (i = 0; i < cvel; i++) {
      if(c[i]==pon3 && i!=0){continue;}
    for (j = 0; j < bvel; j++) {
        if(b[j]==pon2 && j!=0){continue;}
      if (c[i] == b[j]) {
          if(avel==0){
              brojac++;
              break;
          }else{
            for (k = 0; k < avel; k++) {
          if (c[i] == a[k]) {
            break;
          }
          if (k == avel - 1) {
            brojac++;
            break;
          }
        }  
          }
        pon2=b[j];
      }
      pon3=c[i];
    }
  }

  printf("U dva od tri niza se nalazi %d clanova.", brojac);
  return 0;
}
