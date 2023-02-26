/*
Zadatak
Napisati program koji ispisuje na ekranu jediničnu matricu dimenzije n, pri čemu se broj n unosi sa tastature. Pri tome je od korisnika potrebno tražiti da unese dodatni parametar r, koji će definisati format ispisa matrice, tako da između svake susjedne kolone bude r praznih mjesta. (Pri rješavanju zadatka nemojte koristiti nizove ni matrice!)

Primjer ulaza i izlaza:

Unesite n: 4
Unesite sirinu ispisa: 7
       1       0       0       0
       0       1       0       0
       0       0       1       0
       0       0       0       1
*/

// MOJ KOD:

#include <stdio.h>

int main() {
    int n,r,i,j,k,dijagonala=1;
	printf("Unesite n: ");
    scanf("%d",&n);
    printf("Unesite sirinu ispisa: ");
    scanf("%d",&r);

    for(i=1; i<=n; i++){
        for (j=1;j<=n;j++){
            for(k=1;k<=r;k++){
                printf(" ");
            }
            if(dijagonala%(n+1)==1){
                printf("1");
                
            }else {
                printf("0");
            }
            
            dijagonala++;
        }
        printf("\n");
        
    }

	return 0;
}
