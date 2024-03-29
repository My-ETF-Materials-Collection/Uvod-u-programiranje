/*
Zadatak
Napraviti funkciju int drugi(int niz[], int vel) koja u datom nizu cijelih brojeva pronalazi drugi po veličini i vraća indeks tog člana u nizu. U slučaju da niz ne sadrži drugi po veličini element funkcija treba vratiti broj -1.

Primjer ulaza i izlaza programa:

Unesite niz brojeva: 10 5 4 9 8 3 10 -1
Indeks drugog po velicini je: 3
Najveći element u unesenom nizu je 10, a drugi po veličini je 9. Broj 9 se nalazi na 4. mjestu odnosno označen je indeksom 3 (prvi član ima indeks 0, drugi indeks 1 itd.)

U postavci zadatka je uključena main funkcija Nije dozvoljeno izmijeniti ovu main funkciju! Kôd vaše funkcije drugi napišite iznad main funkcije, umjesto komentara koji se tamo nalazi. U funkciji nije dozvoljeno kreirati pomoćni niz niti je dozvoljeno sortirati primljeni niz.
*/

// MOJ KOD:

#include <stdio.h>
#include <limits.h>

int drugi(int niz[], int vel){
    int max,drugimax;
    max=drugimax=INT_MIN;
    int i,index=-1;

    if(vel==1 || vel==0){
        index=-1;
    }

    for(i=0;i<vel;i++){
        if(niz[i]>max){
            drugimax=max;
            max=niz[i];
            index=i-1;
        }else if(niz[i]>drugimax && niz[i]<max){
            drugimax=niz[i];
            index=i;
        }
    }

    if(max==drugimax){
        return -1;
    }

    return index;

}

int main() {
    int niz[100], i, rez;
    printf("Unesite niz brojeva: ");
    for (i=0; i<100; i++) {
        scanf("%d", &niz[i]);
        if (niz[i] == -1) break;
    }

    rez = drugi(niz, i);
  
    printf("Indeks drugog po velicini je: %d", rez);
    return 0;
}