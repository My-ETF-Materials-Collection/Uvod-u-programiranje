/*
Zadatak
Potrebno je napraviti program koji ispituje da li na fakultetu postoje studenti koji su rođeni sa tačno 100 dana razlike, što znači da je razlika između njihovih datuma rođenja jednaka 100.

Korisnik najprije treba unijeti broj studenata na fakultetu (najviše 1000). Ukoliko se unese broj studenata manji od 1 ili veći od 1000 treba ispisati poruku “Neispravan broj studenata” i tražiti ponovni unos. Zatim se unose datumi rođenja studenata, tj. unosi se dan, mjesec i godina razdvojeni znakom zarez (bez razmaka). Ako uneseni datum ne čini validan datum, program treba ispisati poruku “Neispravan datum” nakon čega se traži ponovni unos datuma rođenja za istog studenta. Nakon unosa datuma program treba ispisati određeni broj poruka oblika:

Student X. je rodjen tacno 100 dana prije studenta Y.
pri čemu su X i Y redni brojevi studenata koji se odnose na redoslijed unosa studenata. Ako nema studenata koji zadovoljavaju uslov, program ne ispisuje ništa.

Program treba uzeti u obzir sve osobine važećeg (gregorijanskog) kalendara, kao što su broj dana u svakom mjesecu i prestupne godine. Prestupna je svaka godina koja je djeljiva sa 4, osim godina koje su djeljive sa 100 (npr. 1900. nije bila prestupna), ali su godine djeljive sa 400 ipak bile prestupne (npr. 2000. je bila prestupna).

Primjer ulaza i izlaza:

       
Unesite broj studenata: 10000
Neispravan broj studenata
Unesite broj studenata: 0
Neispravan broj studenata
Unesite broj studenata: 2
Unesite datum rodjenja 1. studenta: 1,1,2000
Unesite datum rodjenja 2. studenta: 31,2,2000
Neispravan datum
Unesite datum rodjenja 2. studenta: 10,4,2000
Student 1. je rodjen tacno 100 dana prije studenta 2.
*/

// MOJ KOD:

#include <stdio.h>

int main() {
  int n;
  int dan[1000];
  int mjesec[1000];
  int godina[1000];
  int broj_dana_u_mjesecu[12] = {31, 28, 31, 30, 31, 30,
                                 31, 31, 30, 31, 30, 31};
  int i = 0, j = 0;
  int prvi_student, drugi_student;
  int razlika_datuma = 0;
  int month = 0;
  int year = 0;

  // Unos broja studenata
  do {
    printf("Unesite broj studenata: ");
    scanf("%d", &n);
    if (n < 1 || n > 1000)
      printf("Neispravan broj studenata\n");
  } while (n < 1 || n > 1000);

  // Unos datuma studenata

  for (i = 0; i < n; i++) {
    printf("Unesite datum rodjenja %d. studenta: ", i + 1);
    scanf("%d,%d,%d", &dan[i], &mjesec[i], &godina[i]);
    if (godina[i] % 4 == 0 && (godina[i] % 400 == 0 || godina[i] % 100 != 0))
      broj_dana_u_mjesecu[1] = 29;
    if (dan[i] < 1 || mjesec[i] < 1 || mjesec[i] > 12 || godina[i] < 1 ||
        dan[i] > broj_dana_u_mjesecu[mjesec[i] - 1]) {
      printf("Neispravan datum\n");
      i--;
    }
    broj_dana_u_mjesecu[1] = 28;
  }

  // Provjera

  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      razlika_datuma = 0;
      if (godina[i] == godina[j] && mjesec[i] == mjesec[j])
        break;
      if (godina[i] < godina[j] ||
          (godina[i] == godina[j] && mjesec[i] < mjesec[j])) {
        prvi_student = i;
        drugi_student = j;
      } else {
        prvi_student = j;
        drugi_student = i;
      }
  
      // Kalkulacija
      month = mjesec[prvi_student] + 1;
      year = godina[prvi_student];

      if (month > 12) {
        year++;
        month = 1;
      }
      while (month != mjesec[drugi_student] || year != godina[drugi_student]) {
        razlika_datuma += broj_dana_u_mjesecu[month - 1];
        if (year % 4 == 0 && ((year % 400) == 0 || (year % 100) != 0)) {
          if (month == 2)
            razlika_datuma += 1;
        }
        month++;
        if (month == 13) {
          year++;
          month = 1;
        }
      }
      razlika_datuma +=
          dan[drugi_student] +
          (broj_dana_u_mjesecu[mjesec[prvi_student] - 1] - dan[prvi_student]);
      if (razlika_datuma == 100)
        printf("Student %d. je rodjen tacno 100 dana prije studenta %d.\n",
               prvi_student + 1, drugi_student + 1);
    }
  }
  return 0;
}