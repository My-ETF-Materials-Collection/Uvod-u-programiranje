/*
Zadatak
Napisati funkciju

void prekopiraj (const int *izvor, int *odrediste, int n)
koja treba da prekopira elemente niza na koje pokazuje pokazivac izvor u niz na kojeg pokazuje pokazivač odrediste. Pretpostaviti da odrediste pokazuje na dovoljno velik niz koji može prihvatiti svih n elemenata prvog niza; ovo ne treba provjeravati.

Napomena: Pri rješavanju zadatka obavezno koristiti pokazivačku aritmetiku! Nije dozvoljena ni trivijalna simulacija indeksiranja izrazima oblika *(niz+i).
*/

// MOJ KOD:

#include <stdio.h>

void prekopiraj (const int *izvor, int *odrediste, int n){
    int *p;
    p=odrediste;
    while(p<odrediste+n){
        *p=*izvor;   
        izvor++; 
        p++;
    }
}

int main() {
    int niz1 [10] = {1,2,3,4,5,6,7,8,9,10};
    int niz2 [10];
    prekopiraj(niz1, niz2, 10);
    int i;
    for(i=0; i<10; i++) printf("%d ",niz2[i]);
    return 0;
}