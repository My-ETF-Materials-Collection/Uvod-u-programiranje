/*
Zadatak
Napisati funkciju void sortiraj(double niz[], int n) koja sortira elemente niza u opadajućem poretku koristeći Selection sort algoritam sa predavanja. Pri rješavanju zadatka koristiti isključivo pokazivačku aritmetiku!

Napomena: Pri rješavanju zadatka obavezno koristiti pokazivačku aritmetiku! Nije dozvoljena ni trivijalna simulacija indeksiranja izrazima oblika *(niz+i). Rješenja u kojima je korišten Bubble Sort ili neki drugi algoritam, a ne Selection sort, biti će vraćena na popravku!
*/

// MOJ KOD:

#include <stdio.h>

void swap(double *x, double *y) {
    double temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void sortiraj(double niz[], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(niz[i] < niz[j]) {
                swap(&niz[i], &niz[j]);
            }
        }
    }
}
int main()
{
    double niz[100];
    int n, i;
    printf("\n Unesite broj clanova niza:  ");
    scanf("%d", &n);
    printf("\n Unesite clanove niza:  ");
    for(i = 0; i < n; i++)
        {scanf("%lf", &niz[i]);}
    
    sortiraj(niz, n);
    printf("\n Sortiran niz: ");
    for(i = 0; i < n; i++)  {
        printf(" %lf \t", niz[i]);
    }
    
    return 0;
}