/*
ZADATAK

Napravite program koji učitava realnu matricu dimenzija AxB (A i B su konstante) te pronalazi
sumu elemenata na rubu matrice.
*/

// MOJ KOD: 

#include <stdio.h>
#define A 5
#define B 5
int main() {
float mat[A][B],suma;
int i,j;
/* Unos matrice */
for (i=0; i<A; i++) {
for (j=0; j<B; j++) {
printf ("Unesite element mat[%d][%d]: ",i,j);
scanf ("%f", &mat[i][j]);
}
}
suma=0;
/* Suma gornje i donje stranice */
for (i=0; i<A; i++)
suma += mat[i][0]+mat[i][B-1];
Skinuto sa www.etf.ba
/* Suma lijeve i desne stranice */
for (i=1; i<B-1; i++) /* iskljucujemo coskove */
suma += mat[0][i]+mat[A-1][i];
printf ("Suma rubova je: %.3f\n", suma);
return 0;
}