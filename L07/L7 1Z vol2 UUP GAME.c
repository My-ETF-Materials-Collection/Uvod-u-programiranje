/*
Zadatak
U predavanjima je data funkcija

const char* podstring (const char *str, const char *trazi)
koja traži tekst trazi unutar proslijeđenog stringa str. Funkcija treba da vrati pokazivač na poziciju u string str gdje se nalazi podstring. Ukoliko ima više takvih stringova funkcija treba vratiti indeks koji predstavlja početak prvog stringa, a ko se podstring ne nalazi u stringu treba vratiti nul-pokazivač.

Napisati novu funkciju pronadji_posljednji koja slično funkciji podstring pronalazi tekst unutar stringa ali ovaj put vraća indeks posljednjeg pojavljivanja. Primjeri:

const char *n = "Danas je divan dan!";
printf ("%d", pronadji_posljednji(n, "divan")); 	//9
printf ("%d", pronadji_posljednji(n, "Divan")); 	//-1 (nema)
printf ("%d", pronadji_posljednji(n, "Danas")); 	//0
printf ("%d", pronadji_posljednji(n, "an"));    	//16
printf ("%d", pronadji_posljednji(n, "an!"));   	//16
printf ("%d", pronadji_posljednji("abc cde abc", "abc")); 	//8
Napomena: Pri rješavanju ovog zadatka zabranjeno je korištenje funkcija iz biblioteke string.h. Nije dozvoljeno kreirati pomoćne stringove u funkciji ili globalno.
*/

// MOJ KOD:

#include <stdio.h>

int pronadji_posljednji(const char *s1, const char *s2) {
  int logi = 0, brojac = 0, brojac2 = 0;
  // pamtim pocetak 2 stringa
  const char *p = s1;
  const char *q = s2;
  // idem do kraja oba stringa i brojim koliko je dug prvi string
  while (*s1 != '\0') {
    s1++;
    brojac2++;
  }
  while (*s2 != '\0')
    s2++;
  // vracam drugi string na zadnji znak da nije na \0
  s2--;
  s1--;
  // krecem s kraja i poredim oba stringa, tako cu naci indeks zadnjeg
  // podstringa
  while (s1 != p) {
    // pamtim krajeve stringova svaki put kada ne nađem podstring
    const char *m = s1;
    const char *n = s2;
    if (*m == *n) {
      while (m>=p && n>=q && *m == *n) {
        if (n == q) { // n==q znaci da mi je trazeni podstring dosao do svog
                      // pocetka, tj da sam ga pronasla
          logi = 1;
          break;
        }
        m--;
        n--;
        brojac++; // brojim koliko sam presla znakova od kraja
      }

      if (!logi)
        brojac--; // ukoliko nije pronađen podstring smanjujem brojac jer ce
                  // biti prebrojan jedan znak više
    } else
      brojac++;
    if (logi)
      break;
    s1--;
  }
  if (logi) {
    return brojac2 - brojac - 1; // vracam razliku velicine prvog stringa i brojaca
                             // koji je brojao clanove od kraja tog stringa
  } else
    return -1;
}

int main() { return 0; }