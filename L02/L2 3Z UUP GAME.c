/*
Zadatak
Napisati program koji računa proizvod svih prirodnih parnih brojeva do broja n (uključivo) koji se unosi sa tastature. Ukoliko uneseni broj nije prirodan, program treba da ispiše grešku i završi sa radom. Primjer ulaza i izlaza:


Unesite n: 5
Proizvod je: 8

Unesite n: 14
Proizvod je: 645120
*/

// MOJ KOD:

#include <stdio.h>

int main() {
    int n;
	printf("Unesite n: ");
    scanf("%d",&n);
    int p=0,i;
    if(n>0){
        if(n==1){
            printf("Proizvod je: %d",p);
            return 0;
        }
        p=1;
       for(i=1; i<=n; i++){
           if(i%2==0){
               p=p*i;
           }
       }
       printf("Proizvod je: %d",p);
    }else{
        printf("Broj nije prirodan");
    }
    
	return 0;
}
