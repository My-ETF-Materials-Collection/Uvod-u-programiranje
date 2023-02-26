/*
Zadatak
Data je struktura koja opisuje trenutni kurs neke valute u kursnoj listi (koliko KM ćete dobiti za jednu jedinicu te valute).

struct Kurs {
    char valuta[5];
    float vrijednost;
};
Npr. trenutni kurs za valutu EUR je 1.955830 KM, pa struktura za tu valutu sadrži vrijednosti "EUR" i 1.95583.

Napisati funkciju razmjena koja prima kursnu listu (niz proizvoljne dužine čiji su članovi tipa struct Kurs), jedan string koji označava valutu (npr. "EUR") i iznos novca u toj valuti, a vraća iznos u KMovima. U gornjem primjeru, ako bismo poslali iznos 2, funkcija bi trebala vratiti 3.91166. Ako se valuta ne nalazi u nizu treba vratiti 0.

Obavezno napisati i main funkciju koja omogućuje: unos kursne liste, zatim unos valute i iznosa, poziv funkcije i na kraju ispis rezultata konverzije.
*/

// MOJ KOD:

#include <stdio.h>
#include <string.h>

struct Kurs{
    char valuta[5];
    float vrijednost;
};

float razmjena(struct Kurs* niz, int n, char* valuta, float marke){
int i=0;
while(i<n){
    if(strcmp(valuta,niz[i].valuta)==0){
        return niz[i].vrijednost*marke;
    }
    i++;
}
return 0;
}

int main() {
	return 0;
}
