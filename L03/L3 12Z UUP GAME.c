/*
Zadatak
Napisati program koji omogućuje unos niza realnih brojeva, pronalazi u njemu član koji se ponavlja najviše puta, a zatim iz niza izbacuje sve članove koji su veći od njega (bez promjene redoslijeda). Ako se više članova ponavlja isti broj puta, treba koristiti najmanji od njih. Na kraju program ispisuje niz na ekranu.

Primjer ulaza i izlaza:

Unesite broj clanova niza: 9
Unesite clanove niza: 5.2 -10.1 8.3 -140 2.1 5.2 -4 -21.1 -10.1
Nakon izbacivanja niz glasi:
-10.1 -140 -21.1 -10.1
Članovi niza 5.2 i -10.1 se ponavljaju jednak broj puta (po dva puta), ali -10.1 je manji.

Napomena: U postavci zadatka je dat polazni kod - nije dozvoljeno promijeniti ovaj kod! Vaše rješenje zadatka napišite umjesto komentara === OVDJE UBACITI KOD === a ono što se nalazi prije i poslije toga nipošto nemojte mijenjati jer vam neće prolaziti testovi!

Također nije dozvoljeno kreirati pomoćni niz.
*/

// MOJ KOD:

#include <stdio.h>

int main() {
    double niz[100];
    int i, vel;
	
    printf("Unesite broj clanova niza: ");
    scanf("%d",&vel);
    printf("Unesite clanove niza: ");
    for(i=0; i<vel; i++)
        scanf("%lf", &niz[i]);

    int max=0, maxel=0, j;
    int brojac;
    for(i=0; i<vel; i++){
        brojac=0;
        for(j=0; j<vel; j++){
            if(niz[i]==niz[j]){
                brojac++;
            }
        }
            if(brojac>max){
                max=brojac;
                maxel=i;
            }
            if(brojac==max && niz[i]<niz[maxel]){
                maxel=i;
            }
    }
    
    double x=niz[maxel];

    for(i=0; i<vel; i++){
        if(niz[i]>x){
            for(j=i; j<vel-1; j++){
                niz[j]=niz[j+1];
                
            }
            vel--;
            i--;
        }
    }

    printf("Nakon izbacivanja niz glasi:\n");
    for (i=0; i<vel; i++)
        printf("%g ", niz[i]);
    return 0;
}