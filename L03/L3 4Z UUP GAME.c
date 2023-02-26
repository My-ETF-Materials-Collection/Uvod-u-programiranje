/*
Zadatak
Napisati program koji od korisnika traži unos n realnih elemenata niza (ne više od 100) koji će te elemente ispisati sortirane od manjeg ka većem unutar vitičastih zagrada, razdvojene znakom zarez (iza posljednjeg elementa nema znaka zarez). Ukoliko je broj n van opsega, ponovo tražiti unos.

Primjer ulaza i izlaza:

Unesite broj elemenata niza: 7
Unesite 7 brojeva: 1 0 2.1 -2 5 7 3
{-2, 0, 1, 2.1, 3, 5, 7}
*/

// MOJ KOD:

#include <stdio.h>

int main() {
    int n;
    double niz[100];

    do{
        printf("Unesite broj elemenata niza: ");
        scanf(" %d", &n);

        if(n>100 || n<=0){
            printf("Unos neispravan!\n");
        }
    }while(n>100 || n<=0);

    printf("Unesite %d brojeva: \n",n);

    int i;
    
    for(i=0; i<n; i++){
        scanf("%lf",&niz[i]);
    }
    
    int j;
    double x;

    for(i=0; i<n; i++){
        for(j=i; j<n; j++){
            if(niz[j]<niz[i]){
                x=niz[i];
                niz[i]=niz[j];
                niz[j]=x;
            }
        }
    }

    printf(" ");
    printf("{");
    
    for(i=0; i<n; i++){
        
        printf("%g", niz[i]);

        if(i<n-1){
            printf(", ");
        }

    }

    printf("}");

	return 0;
}


uslov da bude opadajuci niz potrebno je samo staviti j=0 a ne j=n u for petlji
