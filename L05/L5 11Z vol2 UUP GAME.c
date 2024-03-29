/*
Zadatak
Napisati funkciju sa prototipom:

double aritmeticka(int* niz, int vel, int* max_cifra, int* min_cifra)
Funkcija prima niz cijelih brojeva, njegovu veličinu, te pokazivače min_cifra i max_cifra za koje se pretpostavlja da pokazuju na neke cjelobrojne promjenljive u funkciji iz koje je pozvana funkcija aritmeticka. Ova funkcija treba najprije odrediti aritmetičku sredinu članova niza niz, što je vrijednost koja se vraća iz funkcije. Zatim u vrijednost na koju pokazuje pokazivač max_cifra treba upisati cifru koja se najviše puta pojavljuje u onim članovima niza koji su veći od aritmetičke sredine. Ako se dvije cifre pojavljuju isti broj puta u datim brojevima, treba upisati onu od tih cifara koja je veća.

Slično tome u pokazivač min_cifra treba upisati cifru koja se najmanje puta pojavljuje u članovima niza koji su veći od aritmetičke sredine. Obratite pažnju da tu ne treba upisivati cifru koja se ne pojavljuje niti jednom - cifra se treba pojavljivati barem jednom. Ako se više cifara pojavljuju isti (najmanji) broj puta, treba upisati onu koja je najmanja.

Konačno ako u nizu nema članova većih od aritmetičke sredine, u vrijednosti na koje pokazuju pokazivači treba upisati brojeve -1.

Primjer: ako niz glasi

10365 2841 31000 23711 17
Aritmetička sredina je 13586.8, brojevi veći od ovog broja su 31000 i 23711. U ovim brojevima cifre 0 i 1 se pojavljuju najveći broj puta (3 puta), ali od te dvije cifre 1 je veća, pa u max_cifra treba upisati 1. Cifre 2 i 7 se pojavljuju samo po jednom, ali od te dvije cifre 2 je manja pa u min_cifra treba upisati 2. Ako bi niz glasio npr:

42 42 42
niti jedan član niza nije veći od aritmetičke sredine, tako da min_cifra i max_cifra trebaju postati -1.

Napisati i kraću main funkciju koja omogućuje testiranje napisane funkcije aritmeticka. Primjer ulaza i izlaza:

Unesite clanove niza (0 za kraj):
10365 2841 31000 23711 17 0
Najvise puta se ponavlja cifra 1 a najmanje cifra 2.
*/

// MOJ KOD:

#include <stdio.h>
#include <stdlib.h>
double aritmeticka(int *niz, int vel, int *max_cifra, int *min_cifra) {

  double aritmeticka, suma = 0;
  int i;
  for (i = 0; i < vel; i++) {
    suma += niz[i];
  }
  aritmeticka = suma / vel;

  int nizar[1000] = {0}, brcifara[10] = {0}, rem;
  int vel2 = 0;

  for (i = 0; i < vel; i++) {
    if (niz[i] > aritmeticka) {
      nizar[vel2] = abs(niz[i]);
      vel2++;
    }
  }

  for (i = 0; i < vel2; i++) {
    do{
      rem = nizar[i] % 10; // 1 2 6 5 11 12, 1 2 6 5 1 2    
      nizar[i] /= 10;      // 0 0 0 0 1 1
      brcifara[rem]++;     
    }while (nizar[i] > 0);
  }
  int brpon,provjera=0;

provjera=0;
if(brcifara[0]>0){
   for(i=1;i<10;i++){
    if(brcifara[i]!=0){
        provjera=1;
        break;
    }
    }
    if(provjera==0){
        *max_cifra=0;
        *min_cifra=0;
        return aritmeticka;
    }
}
provjera=0;

for(i=0;i<10;i++){

    if(brcifara[i]!=0){
        provjera=1;
        break;
    }
    
}

if(provjera==0){
    *min_cifra=-1;
    *max_cifra=-1;
    return aritmeticka;
}

//max
for(i=9;i>-1;i--){
    if(brcifara[i]!=0){
        brpon=brcifara[i];
        *max_cifra=i;
        break;

    }
}

for(i=9;i>-1;i--){
    if(brcifara[i]>brpon){
        brpon=brcifara[i];
        *max_cifra=i;
    }
}
//min
for(i=0;i<10;i++){
    if(brcifara[i]!=0){
        brpon=brcifara[i];
        *min_cifra=i;
        break;

    }
}

for(i=0;i<10;i++){
    if(brcifara[i]<brpon && brcifara[i]!=0){
        brpon=brcifara[i];
        *min_cifra=i;
    }
}

  return aritmeticka;
}

int main() {
  int niz[1000] = {0};
  int i, vel = 0;
  int *max_cifra;
  int *min_cifra;
  int a=0,b=0;
  max_cifra=&a;
  min_cifra=&b;
  printf("Unesite clanove niza (0 za kraj): ");
  for (i = 0; i < 1000; i++) {
    scanf("%d", &niz[i]);
    if (niz[i] == 0)
      break;
  }
  vel = i; 
  aritmeticka(niz,vel,max_cifra,min_cifra);
  printf("Najvise puta se ponavlja cifra %d a najmanje cifra %d.", *max_cifra,*min_cifra);

  return 0;
}
