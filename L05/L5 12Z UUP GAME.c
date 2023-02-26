/*
Zadatak
Napisati funkciju matrice_permutacija koja prima tri matrice A, B i C istih dimenzija MxN te vraća logičku istinu ako sve tri matrice sadrže iste elemente sa istim brojem ponavljanja, a logičku neistinu u suprotnom. Prototip funkcije glasi:

int matrice_permutacija(double A[100][100], double B[100][100], double C[100][100], int M, int N)
Napišite i main funkciju pomoću koje se možete uvjeriti da je navedena funkcija ispravna.
*/

// MOJ KOD: 

#include <stdio.h>
#define eps 0.0001
int matrice_permutacija(double A[100][100], double B[100][100], double C[100][100], int M, int N);

int main() {

    int i,j,M,N;
    double A[100][100], B[100][100], C[100][100];

    //POSTAVLJANJE DIMENZIJA MATRICA
	printf("Unesite dimenzije matrica:");
    scanf("%d%d",&M,&N);

    //UNOS
    printf("Unesite elemente matrice A: ");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%lf",&A[i][j]);
        }
    }
    printf("Unesite elemente matrice B: ");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%lf",&B[i][j]);
        }
    }
    printf("Unesite elemente matrice C: ");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%lf",&C[i][j]);
        }
    }
    
    printf("%d",matrice_permutacija(A,B,C,M,N));

	return 0;
}

int matrice_permutacija(double A[100][100], double B[100][100], double C[100][100], int M, int N){

    int i,j;
    double As=0,Bs=0,Cs=0; //As - suma elemenata A, Bs - suma elemenata B, Cs - suma elemenata C
    double Aks=0, Bks=0, Cks=0;//Aks, Bks, Cks - suma kvadrata elemenata
    
    //sa sumom kvadrata provjerimo jer se moze desiti da je tacan zbir 
    // npr. 1 1 0 0 i 0 0 0 2 ali nisu isti elementi
    
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            As+=A[i][j];
            Aks+=A[i][j]*A[i][j];
        }
    }
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            Bs+=B[i][j];
            Bks+=B[i][j]*B[i][j];
        }
    }
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            Cs+=C[i][j];
            Cks+=C[i][j]*C[i][j];
        }
    }
    if(As!=(int)As || Bs!=(int)Bs || Cs!=(int)Cs){
        if((As-Bs)>eps || (Bs-Cs)>eps || (Aks-Bks)>eps || (Bks-Cks)>eps){
        return 0;
        }
    return 1;
    }else{// 1 2 3   1 3 2   3 1 3
    if((As!=Bs) || (Bs!=Cs) || (Aks!=Bks) || (Bks!=Cks)){
        return 0;
    }
        return 1;
    }
}

/*
    a==b fabs(a-b)<EPSILON
    a!=b fabs(a-b)>EPSILON
    a>b a-b>EPSILON
    a<b b-a>EPSILON
    a>=b a>b || fabs(a-b)<EPSILON
    a<=b a<b || fabs(a-b)<EPSILON   
*/
