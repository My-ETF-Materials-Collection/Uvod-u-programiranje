/*
Zadatak
Napravite program koji učivata matricu cijelih brojeva dimenzija 10x10, a zatim pronalazi red sa najvećim i red sa najmanjim elementom. Ako se oba elementa nalaze u istom redu, program treba ispisati poruku "Najveci i najmanji element se nalaze u istom redu." i završiti s radom. U suprotnom, potrebno je zamijeniti mjesta ta dva reda u matrici i ispisati tako modifikovanu matricu na ekranu.

Primjer ulaza i izlaza:

Unesite elemente matrice: 1 2 3 4 ...
Nakon zamjene matrica glasi:
1 2 3 4 ...
Napomena: Zadatak obavezno riješiti koristeći matricu.
*/

// MOJ KOD:

#include <stdio.h>

int main() {
	printf("Unesite elemente matrice: ");
    int i, j, matrica[10][10], matrica2[10][10];

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            scanf("%d",&matrica[i][j]);
        }
    }

    int max = matrica[0][0];
    int min = max;
    int maxred=0;
    int tempmaxred=0;
    int minred=0;

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(matrica[i][j]>max){
                max=matrica[i][j];
                maxred=i;
            }
            if(matrica[i][j]<min){
                min=matrica[i][j];
                minred=i;
            }
        }
    }
    
    for(j=0;j<10;j++){
            tempmaxred=matrica[maxred][j];
            matrica[maxred][j]=matrica[minred][j];
            matrica[minred][j]=tempmaxred;
    }
    
    
    if(maxred==minred){
            printf("Najmanji i najveci element se nalaze u istom redu.");
            return 0;
    }

    printf("Nakon zamjene matrica glasi: \n");
    
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%d ",matrica[i][j]);
        }
        printf("\n");
    }
	return 0;
}
