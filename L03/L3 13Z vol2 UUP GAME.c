/*
Zadatak
Potrebno je napraviti sljedeći program: Korisnik najprije unosi niz realnih brojeva (najviše 100) na način da se prvo unese broj članova niza, a zatim članovi. U ovom nizu treba pronaći parove susjednih članova takvih da je desni član dvostruko veći od lijevog člana (koristiti ε=0.0001). Između svaka dva takva člana treba ubaciti broj koji predstavlja srednju vrijednost ta dva člana. Ovako kreiran niz treba ispisati na ekran.

U nastavku programa treba iz svakog člana niza izdvojiti prvu cifru nakon decimalnog zareza, te prebrojati koliko puta se ponavlja svaka takva cifra.

Primjer ulaza i izlaza:

       
Unesite broj clanova niza: 5
Unesite niz: 1 2 3 4 5
Nakon ubacivanja niz glasi:
1 1.5 2 3 4 5
Cifra 0 se ponavlja 5 puta.
Cifra 5 se ponavlja 1 puta.
*/

// MOJ KOD:

#include <stdio.h>
#include <math.h>
#define eps 0.0001

int main() {
    int n,i,j;
    double niz[200],broj;
    int brojac[200]={0},cifre[200]={0};
    do{
	printf("Unesite broj clanova niza: ");
    scanf("%d",&n);
    }while(n<=0 || n>100);
	
    printf("Unesite niz: ");
    for(i=0;i<n;i++){
        scanf("%lf",&niz[i]);
    }

    for(i=1;i<n;i++){
        if(fabs(niz[i]-2*niz[i-1])<eps){
            for(j=n;j>i;j--){
                niz[j]=niz[j-1];
            }
            broj=(niz[i]+niz[i-1])/2;
            niz[i]=broj;
            n++;
            i++;
        }
    }
    
    printf("Nakon ubacivanja niz glasi: \n");
        for(i=0;i<n;i++){
            printf("%g ",niz[i]);
        }

    for(i=0;i<n;i++){
        cifre[i]=niz[i]*10;
        cifre[i]%=10;
    }

    for(i=0;i<n;i++){
        brojac[cifre[i]]++;
    }

    for(i=0;i<100;i++){
        if(brojac[i]!=0){
            printf("\nCifra %d se ponavlja %d puta.", i, brojac[i]);
        }
    }
    return 0;
}
