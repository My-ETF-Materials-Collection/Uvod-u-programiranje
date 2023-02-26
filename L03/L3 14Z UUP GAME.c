/*
Zadatak
Program omogućuje unos niza pozitivnih cijelih brojeva proizvoljne dužine (ne duži od 100 članova). Unos se završava brojem nula ili negativnim brojem koji se ne smatra za član niza. Ako korisnik pokuša unijeti više od 100 brojeva, biće razmatrano samo prvih 100 i unos će se prekinuti čim to bude moguće. Biće unesen najmanje jedan pozitivan broj (nije potrebno testirati). Program zatim treba ispisati cifre koje se pojavljuju u unesenim brojevima, poredane od manjih ka većim.

Primjer ulaza i izlaza:

       
Unesite brojeve:
351 4 13 443 53413 -1
Cifre: 1,3,4,5.
Obratite pažnju da su cifre razdvojene znakom zarez, osim posljednje nakon koje se nalazi znak tačka.
*/

// MOJ KOD:

#include <stdio.h>

int main() {

  int niz[100] = {0}, cifre[10]={0}, rem[200]={0};
  int ukclanova = 0, i = 0,j,c=0;
 int konacno[10];
  printf("Unesite brojeve: ");
  // unos
  for (i = 0; i < 100; i++) {
    scanf("%d", &niz[i]);
    if (niz[i] <= 0) {
      break;
    }
  }
  ukclanova = i;
  for (i = 0; i < ukclanova; i++) {
      while(niz[i]>0){
          rem[i] = niz[i]%10;
          niz[i]/=10;
          cifre[rem[i]]++;
      }
  }
  for(j=0;j<10;j++){
        if(cifre[j]!=0){
            konacno[c]=j;
            c++;            
        }   
}
printf("\nCifre: ");
for(i=0;i<c;i++){
    if(i==c-1){
    printf("%d.",konacno[i]);
    }else{
        printf("%d,",konacno[i]);
    }
}
  return 0;
}