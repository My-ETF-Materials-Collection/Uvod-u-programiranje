/*
Zadatak
Najprije treba omogućiti korisniku da unese matricu proizvoljnih dimenzija MxN. Korisnik najprije unosi prirodne brojeve M i N koji su manji ili jednaki 200. Petljom do-while treba osigurati da su brojevi u traženom opsegu. Nakon toga, unose se elementi matrice.

Nakon unosa, program treba izbaciti iz matrice sve redove koji se ponavljaju (svi elementi redova su jednaki) tako da u matrici ostane samo prvi odozgo takav red. Nakon toga treba izbaciti i sve kolone koje se ponavljaju, tako da u matrici ostane samo prva slijeva takva kolona. Konačno treba ispisati tako promijenjenu matricu.

Pri rješavanju obavezno koristiti izbacivanje redova/kolona iz matrice uz očuvanje redoslijeda! Rješenja u kojem suvišni redovi/kolone budu samo preskočeni prilikom ispisa na ekran biće bodovana sa 0 bodova. Zadatak obavezno riješiti koristeći matricu.

Primjer ulaza i izlaza:

Unesite brojeve M i N: 50 205
Brojevi nisu u trazenom opsegu.
Unesite brojeve M i N: -4 5
Brojevi nisu u trazenom opsegu.
Unesite brojeve M i N: 4 4
Unesite elemente matrice:
1 2 3 2
4 5 6 5
1 2 3 2
7 8 9 8
Nakon izbacivanja redova/kolona matrica glasi:
    1    2    3
    4    5    6
    7    8    9
*/

// MOJ KOD:

#include <stdio.h>

int main() {
    int m,n,i,j,matrica[200][200]={0};

    do{
    printf("\nUnesite brojeve M i N: ");
    scanf("%d %d",&m,&n);
    if(m<=0 || m>200 || n<=0 || n>200){
        printf("Brojevi nisu u trazenom opsegu. ");
    }
    }while(m<=0 || m>200 || n<=0 || n>200);
	
    printf("Unesite elemente matrice:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&matrica[i][j]);
        }
    }

    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");

    int duplired=0,k,l;
    for(i=0;i<m-1;i++){
        for(j=i+1;j<m;j++){
            if(matrica[i][0]==matrica[j][0]){
                duplired=1;
                    for(k=0;k<n;k++){
                        if(matrica[i][k]!=matrica[j][k]){
                            duplired=0;
                            break;
                        }               
                    }
                if(duplired){
                    for(k=j;k<m-1;k++){
                        for(l=0;l<n;l++){
                           matrica[k][l]=matrica[k+1][l]; 
                        }
                    }
                    m--;
                    j=i;
                }
                
            }
        }
    }
    int duplakolona;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(matrica[0][i]==matrica[0][j]){
                duplakolona=1;
                    for(k=0;k<m;k++){
                        if(matrica[k][i]!=matrica[k][j]){
                            duplakolona=0;
                            break;
                        }               
                    }
                if(duplakolona){
                    for(k=j;k<n-1;k++){
                        for(l=0;l<m;l++){
                           matrica[l][k]=matrica[l][k+1]; 
                        }
                    }
                    n--;
                    j=i;
                }
                
            }
        }
    }
  
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("    %d",matrica[i][j]);
        }
        printf("\n");
    }

	return 0;
}

DRUGI NACIN KODA:

#include <stdio.h>
 
int main() {
    int matrica[200][200];
    int m, n, i, j, k, brojac=0, x, y, t=0;
    printf("Unesite brojeve M i N: ");
    scanf("%d %d", &m, &n);
    
    if(m>200 || n>200 || m<0 || n<0){
        do{
            printf("Brojevi nisu u trazenom opsegu.");
            printf("\nUnesite brojeve M i N: ");
            scanf("%d %d", &m, &n);
        }while(m>200 || n>200 || m<0 || n<0);
    }
    printf("Unesite elemente matrice: ");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &matrica[i][j]);
        }
    }
    
    for(i=0; i<m; i++){/*Izbacivanje reda*/
    if(m==1) break;
    brojac=0;
    t=0;
        for(k=i+1; k<m; k++){
            t=0;
            if(matrica[i][0]==matrica[k][0]){
                for(j=1; j<n; j++){
                    if(matrica[i][j]==matrica[k][j]) brojac++;
                }
                t=1;
                break;
            }
        }
        if(t==1 && brojac==n-1){
            for(x=k; x<m-1; x++){
                for(y=0; y<n; y++){
                    matrica[x][y]=matrica[x+1][y];
                }
            }
            m--;
            i--;
        }
    }
    
    for(i=0; i<n; i++){/*Izbacivanje kolone*/ 
    brojac=0;
    t=0;
        for(k=i+1; k<n; k++){
            t=0;
            if(matrica[0][i]==matrica[0][k]){
                for(j=1; j<m; j++){
                    if(matrica[j][i]==matrica[j][k]) brojac++;
                }
                t=1;
                break;
            }
        }
        if(t==1 && brojac==m-1){
            
            for(x=k; x<n-1; x++){
                for(y=0; y<m; y++){
                    matrica[y][x]=matrica[y][x+1];
                }
            }
            /*printf("\n n ti je sad %d", n);*/
            n--;
            i--;
        }
        
    }
/*  printf("\nm je %d, n je %d\n", m, n);*/
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%5d", matrica[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
