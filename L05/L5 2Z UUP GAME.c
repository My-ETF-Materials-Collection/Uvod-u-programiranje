/*
Zadatak
Napisati funkciju prva_cifra koja za proslijeđeni parametar n vraća prvu cifru toga broja. Npr. prva_cifra(7392); treba da vrati broj 7. Predznak broja zanemariti.

Napisati i kraću main funkciju koja omogućuje testiranje napisane funkcije prva_cifra. Primjer ulaza i izlaza:

Unesite broj: -7392
Prva cifra broja je 7.
*/

// MOJ KOD:

#include <stdio.h>
#include <stdlib.h>

int prva_cifra(int n);

int main() {
    int n;
	printf("Unesite broj: ");
	scanf("%d",&n);
    
    printf("Prva cifra broja je %d.",prva_cifra(n));
    
    return 0;
}

int prva_cifra(int n){
    while(abs(n)>=10){
        n/=10;
    }
    return abs(n);
}
