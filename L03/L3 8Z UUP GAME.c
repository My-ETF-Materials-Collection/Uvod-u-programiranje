/*
Zadatak
Napisati program koji će od korisnika tražiti unos n realnih elemenata niza (ne više od 20). Zatim korisnik unosi broj decimala na koliko želi zaokružiti svaki član niza, kao i broj decimala za ispis. Pri tome se misli na pravo zaokruživanje, a ne samo zaokruživanje prilikom ispisa. Tako modificiran niz ispisati sa preciznošću na traženi broj decimalnih mjesta, unutar vitičastih zagrada.

Primjer ulaza i izlaza:

Unesite broj elemenata niza: 3
Unesite 3 brojeva: 123.45678 123.45477 12.3512
Unesite broj decimala za zaokruzivanje: 3
Unesite broj decimala za ispis: 7
{123.4570000, 123.4550000, 12.3510000}
*/

// MOJ KOD:

#include <stdio.h>
#include <math.h>
int main() {

    double n[20];
    int i, br;
    int decz, deci;
    UNOS:
    printf("\nUnesite broj elemenata niza: ");
    scanf("%d",&br);
    if(br>20 || br<=0){
        printf("Unos neispravan!");
        goto UNOS;
    }else{
        printf("Unesite %d brojeva: ",br);
        for(i=0;i<br;i++){
        scanf("%lf",&n[i]);
    }
     
    printf("\nUnesite broj decimala za zaokruzivanje: ");
    scanf("%d",&decz);
    decz=pow(10,decz);
    printf("\nUnesite broj decimala za ispis: ");
    scanf("%d",&deci);
    printf("\n{");
    for(i=0;i<br;i++){
        n[i]=round(n[i]*decz)/decz;
        printf("%.*lf",deci,n[i]);
        if(i<br-1){
            printf(", ");
        }
    }
    
    printf("}");
    }
	
	return 0;
}
