#include <stdio.h>

int provjeri(int matrica[100][100], int visina){
    
    int i,j;
    for(i=0; i<visina; i++){
        for(j=0; j<100; j++){
            if(matrica[i][j]==-1) break;
            if(matrica[i][j]<=0) return 0; 
        }
        if(j==100) return 0; //ako je doslo dovde a nije naletilo nijednom na -1 e onda nije matrica ok
    }

    return 1;
}

void ufibonacciNiz(int niz[]){
    
    niz[0]=1;
    niz[1]=1;

    for(int i=2; i<100; i++){
        niz[i]=niz[i-1]+niz[i-2];
    }

}

int fibonacci_matrica(int matrica[100][100], int visina){
    
    int fibbNiz[100];
    ufibonacciNiz(fibbNiz);
    
    int i,j,k;
    for(i=0; i<visina; i++){
        for(j=0; j<100; j++){
            for(k=0; k<100; k++){//poredjenje sa elementima fibb NIza
                if(matrica[i][j]==-1) break;
                if(fibbNiz[k]==matrica[i][j]){
                    while(fibbNiz[k]==matrica[i][j]){
                        j++; k++;
                    }
                    break;
                }
            }
            if(matrica[i][j]!=-1) return 0; //ako nije -1 znaci da nema svaki el. u tom redu u fibb NIzu
            if(matrica[i][j]==-1) break;
            printf("\n");
        }
        if(j==100) return 0;
    }
    
    return 1;
}

int main() {

    int v, m[100][100];
    while(1){
        printf("Unesite visinu matrice: ");
        scanf("%d", &v);
        if(v<=0) continue;
        break;
    }

    printf("Unesite matricu: ");
    for(int i=0; i<v; i++){
        for(int j=0; j<100; j++){
            scanf("%d ", &m[i][j]);
            if(m[i][j]==-1) break;
            if(m[i][j]<=0) j--; 
        }
    }
    
    if(provjeri(m,v)) printf("\nMatrica je validna."); else printf("\nMatrica nije validna.");

    if(fibonacci_matrica(m,v)) printf("\nMatrica je Fibonacci matrica."); else printf("\nMatrica nije Fibonacci matrica.");

	return 0;
}
