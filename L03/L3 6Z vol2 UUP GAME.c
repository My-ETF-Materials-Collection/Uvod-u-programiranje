/*
Zadatak
Napišite program koji omogućuje korisniku da unese proizvoljan broj cijelih brojeva sa tastature, pri čemu broj -1 označava kraj unosa. Dozvoljeno je unositi brojeve između 0 i 100. Ukoliko se unese broj van ovog opsega, ponavlja se unos. Nakon što korisnik unese broj -1, treba za svaki broj napisati koliko puta se ponavlja. Brojeve koji se ne javljaju nijednom na ulazu ne treba ispisivati.

Primjer ulaza i izlaza:


Unesite brojeve:
15
22
151
Brojevi moraju biti izmedju 0 i 100!
15
35
22
35
15
7
-1
Broj 7 se javlja 1 puta.
Broj 15 se javlja 3 puta.
Broj 22 se javlja 2 puta.
Broj 35 se javlja 2 puta.
*/

// MOJ KOD:

#include <stdio.h>

int main() {
    int i, brojac[101]={0},n;

	printf("Unesite brojeve:\n");

    while(1){
        scanf("%d",&n);
        if(n==-1){
            break;
        }
        if(n<0 || n>100){
            printf("Brojevi moraju biti izmedju 0 i 100!\n");
            continue;
        }
        brojac[n]++;
    }

    for(i=0; i<=100; i++){
        if(brojac[i]!=0){
            printf("Broj %d se javlja %d puta.\n",i,brojac[i]);
        }
    }
	return 0;
}
