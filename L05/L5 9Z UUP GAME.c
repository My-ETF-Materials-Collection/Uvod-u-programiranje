/*
Zadatak
Napisati funkciju čiji je prototip:

	int iste_cifre(int a, int b)
Funkcija vraća logičku istinu (1) ako su brojevi a i b sastavljeni od istih cifara, a logičku neistinu (0) ako nisu. Predznak zanemarite. Napravite i kraću main funkciju pomoću koje možete testirati ispravnost funkcije iste_cifre.

Primjeri:
Ako je a=4423 i b=2433 funkcija treba vratiti 1 jer se ovi brojevi sastoje od istih cifara (2, 3, 4).
Ako je a=4423 i b=322 funkcija treba vratiti 0 jer se u broju b ne nalazi cifra 4 koja se nalazi u broju a.

Napisati i kraću main funkciju koja omogućuje testiranje napisane funkcije iste_cifre. Primjer ulaza i izlaza:

Unesite broj a: 4423
Unesite broj b: 2433
Brojevi a i b se sastoje od istih cifara.
*/

// MOJ KOD:

#include <stdio.h>
#include <stdlib.h>
int iste_cifre(int a, int b);
int main() {
    int a, b;
	printf("Unesite broj a: ");
    scanf("%d",&a);
    printf("Unesite broj b: ");
	scanf("%d",&b);
    if(iste_cifre(a,b)){
    printf("Brojevi a i b se sastoje od istih cifara.");
    }else{
        printf("Brojevi a i b se ne sastoje od istih cifara.");
    }
    return 0;
}
int iste_cifre(int a, int b){
    
    int i,j;
    a=abs(a);
    b=abs(b);

    int bra[10]={0};
    int brb[10]={0};
    //prebrojati koliko se cifre broja a javljaju 
    while(a>0){//4423
        bra[a%10]++;// 0 0 1 1 2 0 0 0 0  
        a/=10;
    }
    //prebrojati koliko se cifre broja b javljaju
    while(b>0){//332
        brb[b%10]++;// 0 0 1 2 0 0 0 0 0 
        b/=10;
    }
    //ako se na istim indexima javljaju razlicite vrijednosti return 0
    for(i=0;i<10;i++){
        if((bra[i]==0 && brb[i]>0) || (bra[i]>0 && brb[i]==0)){
            return 0;
        }
    }    
    return 1;
}