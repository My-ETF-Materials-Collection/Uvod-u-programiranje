/*
Zadatak
Data je sljedeća struktura podataka:

struct Osoba {
	char ime[15];
	char prezime[20];
	int telefon;
};
Napravite program koji sadrži niz od 100 osoba:

struct Osoba imenik[100];
te omogućuje unos osobe ili ispis do sada unesenih osoba. Primjer ulaza i izlaza:

Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: 1
Unesite ime: Meho
Unesite prezime: Mehic
Unesite broj telefona: 123456
Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: 2
1. Meho Mehic, Tel: 123456
Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: 0
Program treba sadržavati funkcije:

unos_osobe
ispis_osobe
Niz ne smije biti deklarisan kao globalna promjenljiva nego treba biti lokalan za funkciju main.
*/

// MOJ KOD:

#include <stdio.h>


struct Osoba {
    char ime[15];
    char prezime[20];
    int telefon;
};

void unesi(char niz[], int velicina) {
    char znak=getchar();
    if(znak =='\n') znak = getchar();
    int i = 0;
    while(i<velicina-1 && znak !='\n'){
        niz[i] = znak;
        i++;
        znak=getchar();
    }
    niz[i] = '\0';
}

struct Osoba unos_osobe(){
    struct Osoba imenik;
    int i, j;
    printf("Unesite ime: ");
    unesi(imenik.ime, 15);
    printf("Unesite prezime: ");
    unesi(imenik.prezime, 20);
    printf("Unesite broj telefona: ");
    scanf("%d", &imenik.telefon);

    return imenik;
}

void ispis_osobe(struct Osoba imenik){
    printf("%s %s, Tel: %d\n", imenik.ime, imenik.prezime, imenik.telefon);
}

int main() {
    struct Osoba imenik[100],x;
    int unos, vel=0,i;
    
    do{
       printf("Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: \n");
        scanf("%d ", &unos); 
        if(unos==1){
            imenik[vel]=unos_osobe();
            vel++;
        }
        if(unos==2){
            for(i=0;i<vel;i++){
                printf("%d. ",i+1);
                x=imenik[i];
                ispis_osobe(x);
            }
            
        }
        
    }while(unos!=0);

    return 0;
}