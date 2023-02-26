/*
Zadatak
Korisnik najprije unosi broj N koji predstavlja broj članova niza (najviše 100), pri čemu je do-while petljom osigurano da je ovaj broj u opsegu koji ima smisla. Zatim se unose realni brojevi koji su članovi niza.

Program treba ispisati DA ako se svaki član niza ponavlja tačno jednom (ukupno se javlja dvaput u nizu), a u suprotnom treba ispisati NE. (Za poređenje nije potrebno koristiti epsilon.)

Primjeri:


Unesite broj clanova niza: 6
Unesite niz: 1.1 2.2 3.3 3.3 2.2 1.1
DA
Unesite broj clanova niza: 5
Unesite niz: 0.1 0.2 0.1 0.2 0.1
NE
Napomena: Rješenje koje uvijek ispisuje DA ili NE ili hardcodira rješenja (npr. ako je niz jednak nekom iz autotesta uvijek ispisuje DA ili NE) biće bodovana sa 0 bodova bez obzira na potencijalno ispravne dijelove koda!
*/

// MOJ KOD:

#include <stdio.h>

int main() {
   
    int i, n, brojac=0;
    double niz[100];
    do{
        printf("Unesite broj clanova niza: ");
        scanf(" %d",&n);
    }while(n<=0 || n>100);
	

    printf("Unesite niz:");
    for(i=1; i<=n; i++){
        scanf(" %lf",&niz[i]);
    }

    int j;

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(niz[i] == niz[j] ){
                brojac++;
            }
        }
    }

    if(brojac==2*n){
        printf(" DA");
    }else{
        printf(" NE");
    }

    return 0;
}
