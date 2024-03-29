/*
Zadatak
Potrebno je napraviti program koji pomaže učenicima da nauče rješavati zadatke iz matematike sa kvadratnom jednačinom.
Kvadratna jednačina (polinom drugog stepena) je jednačina oblika:
 
(za a=0 u pitanju bi bila linearna jednačina). Jednačina u opštem slučaju ima dva korijena (dva rješenja) koja označavamo sa x1 i x2 . U ovom zadatku x1 će biti manje rješenje, a x2 veće rješenje kvadratne jednačine.
Napisati program koji omogućuje unos koeficijenata a, b i c. Ako su rješenja imaginarni brojevi, treba ispisati odgovarajuću poruku i prekinuti program:

Unesite koeficijente a, b i c: 1 1 1
Rjesenja su imaginarni brojevi.
Ako su koeficijenti realni brojevi, postoje dva rješenja (koja mogu biti jednaka ali to za ovaj zadatak nije bitno).
Korisnik najprije treba da unese rješenje x1. Ako se vrijednost koju je korisnik unio razlikuje od tačnog rješenja za manje od ε=0.001, program ispisuje poruku "Tacno" i prelazi se na unos rješenja x2. U suprotnom, ako je rješenje manje od tačnog ispisuje se poruka "Manje", a ako je veće ispisuje se "Vece". Ako je razlika između unesenog i tačnog rješenja manja od 0.1 ispisuje se "Priblizno manje" odnosno "Priblizno vece". U svakom od ovih slučajeva traži se da korisnik ponovo unese rješenje x1.
Isti princip koristi se za rješenje x2 te se unos ponavlja dok korisnik ne unese tačno rješenje. Primjer ulaza i izlaza:

	Unesite koeficijente a, b i c: 1 2 1
	Unesite rjesenje x1: 1
	Vece
	Unesite rjesenje x1: -2
	Manje
	Unesite rjesenje x1: -0.95
	Priblizno vece
	Unesite rjesenje x1: -1
	Tacno
	Unesite rjesenje x2: 0
	Vece
	Unesite rjesenje x2: -0.9999
	Tacno
Napomena: Koristiti vrijednost ε=0.001 i tip double.
*/

// MOJ KOD:

#include <math.h>
#include <stdio.h>
#define EPS 0.001

int main() {

  double a, b, c, x1, x2;

  printf("Unesite koeficijente a, b i c: ");
  scanf("%lf %lf %lf", &a, &b, &c);

  double D = b * b - 4 * a * c;

  if (D < 0) {
    printf("Rjesenja su imaginarni brojevi.");
  } else {

    double rj1, rj2;

    rj1 = (-b + sqrt(D)) / (2 * a);
    rj2 = (-b - sqrt(D)) / (2 * a);

    do {
      printf("\nUnesite rjesenje x1:");
      scanf("%lf", &x1);

      if ((fabs(x1 - rj1)) < EPS) {
        printf(" Tacno");

        do {
          printf("\nUnesite rjesenje x2:");
          scanf("%lf", &x2);

          if ((fabs(x2 - rj2)) < EPS) {
            printf(" Tacno");
            break;
          } else if (x2 - rj2 < 0.1 && (x2 - rj2) > 0) {
            printf(" Priblizno vece");
          } else if (rj2 - x2 < 0.1 && (rj2 - x2) > 0) {
            printf(" Priblizno manje");
          } else if (rj2 > x2) {
            printf(" Manje");
          } else {
            printf(" Vece");
          }
        } while (x2 != rj2);
        break;

      } else if (rj1 - x1 < 0.1 && (rj1 - x1) > 0) {
        printf(" Priblizno manje");
      } else if (rj1 > x1) {
        printf("  Manje");
      } else if (x1 - rj1 < 0.1 && (x1 - rj1) > 0) {
        printf(" Priblizno vece");
      } else {
        printf(" Vece");
      }
    } while (x1 != rj1);
  } /*
        a == b fabs(a - b)<EPSILON
        a != b fabs(a - b)> EPSILON
        a > b a - b >  EPSILON
        a < b b - a >  EPSILON
    */

  return 0;
}