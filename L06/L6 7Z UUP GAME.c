/*
Zadatak
Napisati funkciju proste_sume koja ima četiri parametra. Prva dva parametra su niz cijelih brojeva (niz 1) i njegova veličina, treći parametar je prazan niz cijelih brojeva (niz 2), a četvrti je kapacitet (dimenzija) tog niza. Funkcija treba u niz 2 zapisati sve članove niza 1 čija je suma cifara prost broj, te vratiti broj tako zapisanih članova.

Članovi trebaju biti zapisani u niz 2 istim redoslijedom kojim su navedeni u nizu 1. Pri tome se ne smije prekoračiti kapacitet niza 2! Ako niz 1 sadrži više članova koji zadovoljavaju uslov nego što je kapacitet niza 2 (n), treba u niz 2 upisati samo prvih n takvih članova.

Napomena: U zadatku je strogo zabranjeno koristiti pomoćne nizove tj. deklarisati bilo kakav niz osim nizova A i B koji su deklarisani u main funkciji! Rješenje u kojem budu korišteni pomoćni nizovi će biti bodovano sa 0 bodova! Pri rješavanju zadatka obavezno koristiti pokazivačku aritmetiku.
*/

// MOJ KOD:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int proste_sume(int *niz1, int vel1, int *niz2, int vel2);

int jel_prost(int n);

int main() { return 0; }

int proste_sume(int *niz1, int vel1, int *niz2, int vel2) {

  int broj_prostih = 0, broj_cifara, suma_cifara;
  int *p1, *p2, i , j;

  p2 = niz2;
  for (p1 = niz1; p1 < niz1 + vel1; p1++) {
    
    suma_cifara = 0;
    broj_cifara = floor(log10(abs(*p1))) + 1;
    
    for (i = 0; i < broj_cifara; i++) {
      suma_cifara += ((int)(*p1 / pow(10, i)) % 10);
    }

    if (abs(suma_cifara) < 2) {
      continue;
    }

    if (jel_prost(suma_cifara) && broj_prostih < vel2) {
      *p2 = *p1;
      p2++;
      broj_prostih++;
    }
  }

  return broj_prostih;
}

int jel_prost(int n){
    
    int i;
    for(i=2;i<=(n/2);i++){
        if(n%i==0){
            return 0;
        }
    }

    return 1;
}