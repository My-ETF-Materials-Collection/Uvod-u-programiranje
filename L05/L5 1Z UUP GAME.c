/*
Zadatak
Napisati funkciju int NZD (int a, int b) koja vraća najveći zajednički djelilac brojeva a i b. Npr. NZD (8, 12) je 4, NZD (6, 366) je 6. Napomena: funkcija je jako kratka ako se koristi rekurzija.

Napisati i kraću main funkciju koja omogućuje testiranje napisane funkcije NZD. Primjer ulaza i izlaza:

Unesite a: 8
Unesite b: 12
NZD(8,12) je 4.
*/

// MOJ KOD:

#include <stdio.h>

int NZD(int a, int b);

int main() {
    int a, b;    

	printf("Unesite a: ");
    scanf("%d",&a);
    printf("Unesite b: ");
    scanf("%d",&b);

    printf("NZD(%d,%d) je %d.",a,b,NZD(a,b));
	return 0;
}

int NZD(int a, int b)
{
    if(b!=0){
        return NZD(b,a%b);
    }else{
    return a;
    } 
}
