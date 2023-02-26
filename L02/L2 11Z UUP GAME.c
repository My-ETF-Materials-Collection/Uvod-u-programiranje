/*
Zadatak
Napišite program koji računa ukupnu udaljenost puta između dva mjesta. Korisnik unosi početnu i krajnju tačku puta, a zatim neograničeno mnogo udaljenosti između tačaka koje čine međuputeve između ta dva mjesta. Unos međuputeva se vrši u formatu „a x b“, gdje a predstavlja početnu tačku, x udaljenost između dva mjesta u metrima, dok b predstalja odredišnu tačku. Unos se prekida kada se dođe do krajnje tačke puta.

Oznake a i b su tipa char, i nije potrebno provjeravati da li postoji štamparska greška prilikom unosa a i b (tj. pretpostavit ćemo da su zaista uneseni karakteri), međutim potrebno je provjeriti da li postoji logička greška prilikom unosa tačaka. Tako, krajnja tačka prvog puta mora biti jednaka početnoj tački sljedećeg puta. U slučaju da korisnik pogrešno unese tačku, treba ispisati obavještenje i tražiti od korisnika ponovni unos, a taj zanemariti. Također, obratiti pažnju da udaljenost ne može biti negativna.

Na primjer, ako se od tačke a putuje do tačke c preko tačke b, to bi bilo zapisano na sljedeći način: a 100 b, b 150 c. Ukupan pređeni put u ovom slučaju je 250m (100+150).

Primjeri ulaza i izlaza:

Unesite pocetne tacke: a d
Unesite udaljenost(x udaljenost b): a 100 b
Unesite udaljenost(x udaljenost b): b 150 c
Unesite udaljenost(x udaljenost b): c 120 d
Udaljenost izmedju tacaka je 370 metara.

Unesite početne tacke: a d
Unesite udaljenost(x udaljenost b): a 100 b
Unesite udaljenost(x udaljenost b): c 100 d
Niste unijeli dobar medjuput! Probajte ponovo
Unesite udaljenost(x udaljenost b): b 100 b
Napomena: Obratite pažnju da na to da izraz scanf(„%c“, &c) u varijablu c može smjestiti i znak novi red, pa je isti potrebno ignorirati.
*/

// MOJ KOD:

#include <stdio.h>

int main() {
  char p, k;
  int duk = 0;
  // p-pocetna, k-odredisna tačka, duk-ukupan predjeni put
  printf("Unesite pocetne tacke: ");
  scanf(" %c %c", &p, &k);

  char kalt = k;
  char palt = p;
  char p2, k2;
  int korak = 0;

  while (1) {
    printf("Unesite udaljenost(x udaljenost b): ");
    scanf(" %c %d %c", &p2, &korak, &k2);

    while (p2 != p || palt == k2 || p2 == k2 || k == k2) {
      printf("Niste unijeli dobar medjuput! Probajte ponovo \n");
      printf("Unesite udaljenost(x udaljenost b): ");
      scanf(" %c %d %c", &p2, &korak, &k2);
    }
    duk += korak;
    p = k2;
    k = p2;

    if (k2 == kalt) {
      printf("Udaljenost izmedju tacaka je %d metara.", duk);
      break;
    }
  }
  return 0;
}