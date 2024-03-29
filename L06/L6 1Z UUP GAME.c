/*
Zadatak
Koristeći isključivo pokazivaču aritmetiku napisati funkciju max_el koja vraća pokazivač na najveći elemenat u nizu. Ako postoji više identičnih (najvećih) elemenata, treba vratiti prvi po redu. Prototip funkcije izgleda ovako:

int *max_el(int *p1, int *p2)
Paziti da ova funkcija ne vrati „viseći“ pokazivač tj. pokazivač na neku varijablu koja prestaje postojati u funkciji! Funkcija iznad omogućava direktno mijenjanje najvećeg elementa, kao u sljedećim slučajevima:

int niz[7] = {1, 2, 9, 8, 4, 0, 1};
int *p = max_el(niz, niz + 7); //p pokazuje na max. el.
*p = 100; //niz: {1, 2, 100, 8, 4, 0, 1}
//ili direktno:	
*max_el(niz, niz + 7) = 100; //direktno mijenjamo max. el.
Također, napisati funkciju min_el koja, slično funkciji max_el, pronalazi minimalan elemenat i vraća pokazivač na njega.

Napomena: Pri rješavanju zadatka obavezno koristiti pokazivačku aritmetiku! Nije dozvoljena ni trivijalna simulacija indeksiranja izrazima oblika *(niz+i).
*/

// MOJ KOD:

#include <stdio.h>

int *max_el(int *p1, int *p2);

int *min_el(int *p1, int *p2);

int main() {
	int n;
    int niz[100],i;

    printf("Unesite broj clanova: ");
    scanf("%d",&n);

    printf("\nUnesite clanove niza: ");
    for(i=0; i<n; i++){
        scanf("%d",&niz[i]);
    }

	return 0;
}
//bez zvjezdice je pozicija, sa je vrijednost
int *max_el(int *p1, int *p2){

    int *max;
    max=p1;

    int *k;
    k=p1;

    while(k<(p2)){
        if(*k>*max){
            max=k;
        }
        k++;
    }

    return max;
}
int *min_el(int *p1, int *p2){
    
    int *min;
    min=p1;

    int *k;
    k=p1;

    while(k<(p2)){
        if(*k<*min){
            min=k;
        }
        k++;
    }
    return min;
}