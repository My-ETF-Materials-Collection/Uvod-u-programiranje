/*
Zadatak
Napisati program koji za uneseno n ispisuje dvije simetrične strelice (u ogledalu) dimenzija 2n × n. Ukoliko je n manje od 2, program treba ispisati grešku i završiti s radom. Primjer ispisa:

Unesite n: 5
*         *
**       **
***     ***
****   ****
***** *****
****   ****
***     ***
**       **
*         *
*/

// MOJ KOD:

#include <stdio.h>

int main() {
  int n;
  printf("Unesite n: ");
  scanf("%d", &n);

  int i, j;
if(n>=2){
  for (i = 0; i < n; i++) {
    for (j = 0; j <= 2*n; j++) {

        if(j>(2*n)-(i+1) && j<=2*n){
            printf("*");
        }
        if(j<i+1){
            printf("*");
        }
        if(j>=i+1 && j<=(2*n)-(i+1)){
            printf(" ");
        }
      }printf("\n");
    }

    for(i=n-1; i>0; i--){
        for (j=0; j<=2*n; j++){

        if(j>=(2*n)-(i-1) && j<=2*n){
            printf("*");
        }
        if(j<i){
            printf("*");
        }
        if(j>=i && j<(2*n)-(i-1)){
            printf(" ");
        }

        }
        printf("\n");
    }
}else{
    printf("Neispravan unos");
}
    return 0;
}
