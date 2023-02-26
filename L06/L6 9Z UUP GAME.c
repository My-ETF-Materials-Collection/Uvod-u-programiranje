/*
Zadatak
Napisati funkciju popuni koja prima matricu cijelih brojeva deklarisanih dimenzija 100x100 te cijeli broj M koji predstavlja stvarnu širinu i visinu matrice. Funkcija treba popuniti matricu brojevima na sljedeći način. U donjem desnom uglu se nalazi broj 1, a zatim se matrica popunjava redom brojevima 2, 3, 4 itd. tako da se najprije popunjavaju brojevi prema lijevo, zatim gore, zatim prema desno, pa dole, pa opet lijevo itd. u obliku spirale dok se ne dođe do centra. Primjer matrice za M=5 dat je ispod.

9 10 11 12 13  
8 21 22 23 14
7 20 25 24 15
6 19 18 17 16
5  4  3  2  1
*/

// MOJ KOD:

#include <stdio.h>

void popuni(int matrica[100][100], int n);

int main() {

  int i, j, n = 4, m = 3;
  int matrica[100][100];

  printf("Unesite dimenziju matrice: ");
  scanf("%d", &n);

  popuni(matrica, n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d\t", matrica[i][j]);
    }
    printf("\n");
  }
  return 0;
}

void popuni(int matrica[100][100], int n) {

  int i, j, broj = 1;
  for (i = 0; i < n; i++) {
    // 3 (s desna na lijevo)
    for (j = n - 1 - i; j >= i; j--) {
      matrica[n - 1 - i][j] = broj;
      if(broj==n*n){
      break;}
      broj++;
    } // 1 (odozdo prema gore)
    for (j = n - 2 - i; j > i; j--) {
      matrica[j][i] = broj;
      broj++;
    } // 2 (s lijeva na desno)
    for (j = i; j < n - i; j++) {
      matrica[i][j] = broj;
      broj++;
    } // 4 (odozgo prema dolje)
    for (j = i + 2; j < n - i; j++) {
      matrica[j - 1][n - 1 - i] = broj;
      broj++;
    }
    
  }
}

DRUGA MOGUĆNOST ZADATKA 

Zadatak
Napisati funkciju popuni koja prima matricu cijelih brojeva deklarisanih dimenzija 100x100 te cijeli broj M koji predstavlja stvarnu širinu i visinu matrice. Funkcija treba popuniti matricu brojevima na sljedeći način. U donjem desnom uglu se nalazi broj 1, a zatim se matrica popunjava redom brojevima 2, 3, 4 itd. tako da se najprije popunjavaju brojevi prema lijevo, zatim gore, zatim prema desno, pa dole, pa opet lijevo itd. u obliku spirale dok se ne dođe do centra. Primjer matrice za M=5 dat je ispod.

17 18 19 20 21
16  5  6  7 22
15  4  1  8 23
14  3  2  9 24
13 12 11 10 25

MOJ KOD:

#include <stdio.h>

void popuni(int matrica[100][100], int n);

int main() {

  int i, j, n = 4, m = 3;
  int matrica[100][100];

  printf("Unesite dimenziju matrice: ");
  scanf("%d",&n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d ",&matrica[i][j]);
    }
  }

  popuni(matrica, n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d \t", matrica[i][j]);
    }
    printf("\n");
  }
  return 0;
}

void popuni(int matrica[100][100], int n) {

    int i,j,broj=1;
    for(i=n-1;i>=0;i--){

        for(j=n-2-i;j>=i;j--){
            matrica[n-1-i][j]=broj;
            broj++;
        }

        for(j=n-2-i;j>i;j--){
            matrica[j][i]=broj;
            broj++;
        }

        for(j=i;j<n-i;j++){
            matrica[i][j]=broj;
            broj++;
        }

        for(j=i+1;j<n-i;j++){
            matrica[j][n-1-i]=broj;
            broj++;
        }
    }

}

TREĆA MOGUĆNOST ZADATKA

 9  8  7  6  5
10 21 20 19  4
11 22 25 18  3
12 23 24 17  2
13 14 15 16  1

tada se koristi identican kod kao kod druge mogucnosti samo se postavi 

broj=n*n;
te u popunjavanju umjesto ++, broj--;

1243, x 

1432, x 

3124, x zapisala vec

4312, x 


13      12      11      10      9
14      23      22      21      8
15      24      25      20      7
16      17      18      19      6
1       2       3       4       5

5       4       3       2       1
14      19      18      17      13
15      24      25      23      12
16      20      21      22      11
6       7       8       9       10

9       8       7       6       5
10      21      20      19      4
11      22      25      18      3
12      23      24      17      2
13      14      15      16      1

5       4       3       2       1
6       19      18      17      16
7       20      25      24      15
8       21      22      23      14
9       10      11      12      13