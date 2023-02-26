/*
Zadatak
Date su dvije matrice cijelih brojeva A i B koje imaju deklarisanu dimenziju 100x100 ali je stvarno uneseno manje od tog broja elemenata odnosno njihova logička veličina je V1xS1 i V2xS2. Napisati funkciju matrica_sadrzana koja prima ove dvije matrice i provjerava da li je matrica B sadržana u matrici A. Funkcija vraća 1 ako jeste a 0 ako nije. Npr. ako matrice glase:

   Matrica A				Matrica B
   1  2  3  4  5	         2  3
   6  7  8  9 10	         7  8
  11 12 13 14 15	        12 13
  16 17 18 19 20
Vidimo da je matrica B sadržana u matrici A.
*/

// MOJ KOD:

#include <stdio.h>
int matrica_sadrzana(int A[100][100],int V1, int S1, int B[100][100],int V2, int S2);
int main() {

    int A[100][100],B[100][100],V1,S1,V2,S2,i,j,rj;

	printf("Unesite dimenzije matrice A: ");
    scanf("%d%d", &V1,&S1);
    printf("Unesite dimenzije matrice B: ");
    scanf("%d%d", &V2,&S2);

    printf("Unesite elemente matrice A: ");
    for(i=0;i<V1;i++){
        for(j=0;j<S1;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("Unesite elemente matrice B: ");
    for(i=0;i<V2;i++){
        for(j=0;j<S2;j++){
            scanf("%d",&B[i][j]);
        }
    }
    
    rj=matrica_sadrzana(A,V1,S1,B,V2,S2);
    printf("%d",rj);


	return 0;
}

int matrica_sadrzana(int A[100][100],int V1, int S1, int B[100][100],int V2, int S2){
    int x,y,h=1,i,j,k,l;
    if(V2>V1 || S2>S1){
        return 0;
    }

    x=V1-V2;
    y=S1-S2;

    for(i=0;i<=x;i++){
        for(j=0;j<=y;j++){
            h=1;
            for(k=0;k<V2;k++){
                for(l=0;l<S2;l++){
                    if(A[k+i][l+j]!=B[k][l]){
                        h=0;
                        break;
                    }
                }
            }
            if(h==1){
                break;
            }
        }
        if(h==1){
            break;
        }
    }
        return h;
}

