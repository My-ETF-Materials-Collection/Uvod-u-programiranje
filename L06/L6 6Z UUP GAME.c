/*
Zadatak
Koristeći isključivo pokazivačku aritmetiku, napisati funkciju

int podniz (const int *p1, const int *p2, const int *q1, const int *q2)
koja provjerava da li se niz omeđen sa pokazivačima q1 i q2 (q1 pokazuje na prvi element, a q2 tačno iza zadnjeg) nalazi unutar niza omeđenog pokazivačima p1 i p2 (p1 pokazuje na početak, a p2 tačno iza kraja niza).

Funkcija treba da vrati indeks prvog elementa prvog niza na kojem počinje drugi podniz odnosno -1 ukoliko prvi niz ne sadrži drugi niz unutar sebe. Ukoliko ima više podnizova, treba vratiti indeks prvog. Primjeri radi boljeg razumijevanja:

Niz1 = {1, 2, 3, 4, 5, 6, 7}; Niz2 = {2, 3, 4};
Funkcija treba da vrati 1 jer Niz1 sadrži Niz2 i to počevši od 2. elementa (sa indeksom 1).

Niz1 = {1, 2, 3, 4, 5, 6, 7}; Niz2 = {3, 4, 5};
Funkcija treba da vrati 2 jer Niz2 počinje od 3. elementa niza Niz1.

Niz1 = {1, 2, 3, 4, 5, 6, 7}; Niz2 = {2, 0, 4};
Funkcija treba da vrati -1 jer Niz2 nije podniz niza Niz1.

Napomena: Pri rješavanju zadatka obavezno koristiti pokazivačku aritmetiku! Nije dozvoljena ni trivijalna simulacija indeksiranja izrazima oblika *(niz+i).
*/

// MOJ KOD:

#include <stdio.h>

int podniz (const int *p1, const int *p2, const int *q1, const int *q2){
    const int *i=p1;//da se ne bi mjenjali p1 i q1
    const int *j=q1;//uvodim pomocne varijable
    int pozicija=0;

    while(i != p2){//prolazimo kroz elemente p niza
        pozicija= i-p1;
        while(i<p2 && j<q2 && *i==*j){
            i++;
            j++;
        }
        if(j != q2){//ako smo dosli do kraja niza return -1
            j=q1;
            pozicija++;
            i=p1+pozicija;
        }else{//ako nije dosao do kraja
            return pozicija;
        }
    }
    return -1;
}
/*
4 5 6 3 4 1 2 3 4 5 6 p niz
1 2 3 q niz
dok god element q niza nije jednak elementu p niza ide dalje
onda u drugoj while petlji provjerim da li sljedeci clan q niza je sljedeci clan p niza
ako broj prolaza nije jedan br elemenata niza onda to nije podniz
*/
int main() {
    int niz1[]={1,2,3,4,5,6,7};
    int niz2[]={3,4,5};
	printf("%d",podniz(niz1,niz1+4,niz2,niz2+3));
	return 0;
}
