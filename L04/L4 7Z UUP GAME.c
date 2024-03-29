/*
Zadatak
Napravite program koji obavlja sljedeći zadatak:

Korisnik najprije unosi neparan broj N na intervalu [1,100]. Koristite do-while petlju da osigurate da je broj ovakav. Korisnik zatim unosi matricu cijelih brojeva dimenzija NxN. Program treba ispisati DA ako je unesena matrica "Matrica meta", a u suprotnom ispisati NE.

Matrica meta je matrica organizirana u koncentrične kružnice. U sredini matrice se nalazi neki broj X, u kružnici oko njega (iznad, ispod, lijevo, desno i dijagonalno) se nalaze brojevi za jedan manji od njega. Zatim u kružnici oko ove za jedan manji od njih itd. Matrica dimenzija 1x1 se smatra da jeste matrica meta. Primjeri matrice meta:

1 1 1 1 1				5 5 5
1 2 2 2 1				5 6 5
1 2 3 2 1				5 5 5
1 2 2 2 1
1 1 1 1 1
Napomena: Zadatak u kojem se budu koristili bilo kakvi nizovi ili matrice osim jedne jedine matrice dimenzija 100x100 će dobiti 0 bodova!
*/

// MOJ KOD:

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, m[100][100], brda;
  // UNOS
  do {
    printf("Unesite broj N: ");
    scanf("%d", &n);
    if ((n < 1 || n > 100) || (n % 2 == 0)) {
      printf("Neispravna vrijednost!\n");
    }
  } while ((n < 1 || n > 100) || (n % 2 == 0));

  int i, j, sr;
  printf("Unesite matricu: ");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &m[i][j]);
      if (i == (n / 2) && j == (n / 2)) {
        sr = m[i][j];
      }
    }
  }

  if (n == 1) {
    printf("DA");
    return 0;
  }

  int meta_matrica=1;
  int br_koncentricnih= n/2;

  for(i=0; i<br_koncentricnih; i++){//sirimo krug od centra tj sr.
      //sr-1-i = posto i krece od 0 obuhvatit cemo od sredine pa nadalje sve brojeve do rubova da se smanjuje vrijednost
      int j;
      for(j=n/2-1-i; j<n/2+2+i; j++){//druga for petlja mijenja za prva dva trougla kolone, a u zadnja dva po redovima 
          //provjerimo za dijagonalni gornji, donji, lijevi i desni trougao
          if(m[n/2-1-i][j] != sr-1-i){
              meta_matrica=0;
              break;
          }

          if(m[n/2+1+i][j] != sr-1-i){
              meta_matrica=0;
              break;
          }

          if(m[j][n/2-1-i] != sr-1-i){
              meta_matrica=0;
              break;
          }

          if(m[j][n/2+1+i] != sr-1-i){
              meta_matrica=0;
              break;
          }
        if(meta_matrica==0) break;//ako naidje na jedan krug da ne odgovara zasto se muciti nije meta nema potrebe da dalje provjerava
      }
  }  

  if(meta_matrica==0){
      printf("NE");
  }else{
      printf("DA");
  }

  return 0;
}
