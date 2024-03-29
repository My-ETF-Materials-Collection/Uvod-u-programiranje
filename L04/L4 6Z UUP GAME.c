/*
Zadatak
Potrebno je napisati program koji omogućuje unos tri matrice cjelobrojnih elemenata A, B i C čije su dimenzije jednake: MxN, a M i N su najviše 100. Najprije se unose brojevi M i N (pomoću do-while petlje osigurati da su ti brojevi u traženom opsegu). Zatim se provjerava da li su matrice B i C sastavljene od istih elemenata kao matrica A, pri čemu se ti elementi trebaju ponavljati isti broj puta. Ako je uslov zadatka ispunjen program treba na ekranu ispisati DA, u suprotnom treba ispisati NE.

Primjeri ulaza i izlaza:

Unesite brojeve M i N: 101 101
Unesite brojeve M i N: 2 2
Unesite clanove matrice A: 1 2 1 2
Unesite clanove matrice B: 2 1 2 2
Unesite clanove matrice C: 2 1 2 1
NE
Objašnjenje: iako se matrice A i B sastoje od istih elemenata (1 i 2) njihov broj nije isti jer se u matrici B dvica javlja 3 puta, a u matrici A dva puta, slično i za broj 1.

Primjer 2:

Unesite brojeve M i N: 3 3
Unesite clanove matrice A: 1 2 3 6 6 4 3 7 -1
Unesite clanove matrice B: -1 3 3 2 6 4 6 1 7
Unesite clanove matrice C: 3 6 7 2 6 -1 3 4 1
DA
Napomena: Rješenje koje uvijek ispisuje DA ili NE ili hardcodira rješenja (npr. ako je matrica jednaka nekoj iz autotesta uvijek ispisuje DA ili NE) biće bodovana sa 0 bodova bez obzira na potencijalno ispravne dijelove koda! Zabranjeno je kreirati pomoćne nizove ili sortirati elemente u matricama!

Napomena: U postavci zadatka je dat polazni kod - nije dozvoljeno promijeniti ovaj kod! Vaše rješenje zadatka napišite umjesto komentara === OVDJE UBACITI KOD === a ono što se nalazi prije i poslije toga nipošto nemojte mijenjati jer vam neće prolaziti testovi!
*/

// MOJ KOD:

#include <stdio.h>

int main() {
    int A[100][100], B[100][100], C[100][100], i, j, M, N;
    int isti_elementi = 0;
    do {
        printf ("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
    } while (M<1 || N<1 || M>100 || N>100);
	
    printf("Unesite clanove matrice A: ");
    for (i=0; i<M; i++)
        for (j=0; j<N; j++)
            scanf("%d", &A[i][j]);
    printf("Unesite clanove matrice B: ");
    for (i=0; i<M; i++)
        for (j=0; j<N; j++)
            scanf("%d", &B[i][j]);
      printf("Unesite clanove matrice C: ");
    for (i=0; i<M; i++)
        for (j=0; j<N; j++)
            scanf("%d", &C[i][j]);
  
    
    int As=0, Bs=0, Cs=0, Aks=0, Bks=0, Cks=0;
    //sume elemenata i kvadrata elemenata matrica
    //ako su iste sve odgovarajuce sume onda su permutacije jedna drugih

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
    
    if(As!=Bs || Bs!=Cs || Aks!=Bks || Bks!=Cks){
        isti_elementi=0;
    }else{
        isti_elementi=1;
    }

    if (isti_elementi) printf("DA\n"); else printf("NE\n");
    return 0;
}

