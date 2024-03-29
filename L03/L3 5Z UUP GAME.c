/*
Zadatak
Napisati program koji od korisnika traži unos n, broj elemenata niza (najviše 100). Nakon toga korisnik unosi elemente u niz, a program treba da iz niza izbaci sve parne elemente. Elemente izbacivati uz očuvanje redoslijeda (tako da se na njihovo mjesto pomjere ostali elementi). Program treba da ispiše novonastali niz kao i sumu njegovih elemenata.

Primjer ulaza i izlaza:

Unesite broj elemenata niza: 10
Unesite 10 brojeva: 1 2 3 4 6 5 7 8 10 1
Niz je: 1, 3, 5, 7, 1, 
Suma je: 17
Napomena: kada se kaže "izbaciti" tada se misli da se niz modificira, a ne da se samo preskoče njegovi elementi prilikom ispisa ili unosa. Također nije dozvoljeno kreirati pomoćni niz.

Napomena: U postavci zadatka je dat polazni kod - nije dozvoljeno promijeniti ovaj kod! Vaše rješenje zadatka napišite umjesto komentara /* === OVDJE UBACITI KOD === */ a ono što se nalazi prije i poslije toga nipošto nemojte mijenjati jer vam neće prolaziti testovi!
*/

// MOJ KOD:

#include <stdio.h>

int main() {
	int niz[100], i, vel, suma;
	
	printf("Unesite broj elemenata niza: ");
	scanf("%d",&vel);
	printf("Unesite %d brojeva: ",vel);
	for(i=0; i<vel; i++)
		scanf("%d",&niz[i]);
        
    int j=0;    //redni broj neparnih clanova
    for(i=0; i<vel; i++){
        if(niz[i]%2!=0){
            niz[j]=niz[i];
            suma+=niz[j];
            j++;
            }else{
                niz[i]=0;
            }
            
    }    vel=j;
        
	printf("Niz je:\n");
	for (i=0; i<vel; i++)
		printf(" %d,", niz[i]);
	printf("\nSuma je: %d", suma);
	return 0;
}