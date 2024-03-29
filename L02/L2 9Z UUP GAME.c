/*
Zadatak
Napisati program koji ispisuje tablicu kvadrâta brojeva iz intervala [a b] sa korakom k. Korisnik unosi granice intervala a i b, korak k, te širinu ispisa i broj decimala koje će program ispisivati.

Primjeri ulaza i izlaza:

Unesite interval [a b]: 1 2
Unesite korak: 0.2
Unesite sirinu ispisa: 8
Unesite broj decimala: 2
X             X^2
-----------------
1.00    |    1.00
1.20    |    1.44
1.40    |    1.96
1.60    |    2.56
1.80    |    3.24
2.00    |    4.00

Unesite interval [a b]: 1.15 1.32
Unesite korak: 0.03
Unesite sirinu ispisa: 10
Unesite broj decimala: 4
X                 X^2
---------------------
1.1500    |    1.3225
1.1800    |    1.3924
1.2100    |    1.4641
1.2400    |    1.5376
1.2700    |    1.6129
1.3000    |    1.6900

Unesite interval [a b]: 1 3
Unesite korak: 1
Unesite sirinu ispisa: 3
Unesite broj decimala: 0
X   X^2
-------
1  |  1
2  |  4
3  |  9

Unesite interval [a b]: 2.5 3.5
Unesite korak: 0.1
Unesite sirinu ispisa: 30
Unesite broj decimala: 5
X                                                         X^2
-------------------------------------------------------------
2.50000                       |                       6.25000
2.60000                       |                       6.76000
2.70000                       |                       7.29000
2.80000                       |                       7.84000
2.90000                       |                       8.41000
3.00000                       |                       9.00000
3.10000                       |                       9.61000
3.20000                       |                      10.24000
3.30000                       |                      10.89000
3.40000                       |                      11.56000
3.50000                       |                      12.25000
*/

// MOJ KOD:

#include <stdio.h>

int main() {
  int s, d, i, j;
  double a, b, k, aa;
  printf("Unesite interval [a b]: ");
  scanf("%lf %lf", &a, &b);
  printf("Unesite korak: ");
  scanf("%lf", &k);
  printf("Unesite sirinu ispisa: ");
  scanf("%d", &s);
  printf("Unesite broj decimala: ");
  scanf("%d", &d);
    aa=a;
    printf("X");
    for(i=1;i<=2*s-3;i++){
        printf(" ");
    }
    printf("X^2\n");

    for(i=1;i<=2*s+1;i++){
        printf("-");
    }
    printf("\n");

    for(i=1;i<=(((b-a)/k)+1);i++){
        printf("%.*lf",d, aa);
        printf(" %*c", s-d-3, ' ');
        /*
        for(j=1;j<=s-d-2;j++){
        printf(" ");
        }
*/
        printf("|");
/*
        for(j=1;j<=s-d-2;j++){
            printf(" ");
        }
    */
        printf("%*.*lf",s,d,aa*aa);
        printf("\n");
        aa+=k;
    }
  return 0;
}

