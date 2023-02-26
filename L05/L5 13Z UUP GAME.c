/*
Zadatak
Jedan od najstarijih algoritama za izračunavanje pseudoslučajnih brojeva je algoritam "sredine korijena" predstavljen na predavanjima. Vaš zadatak je da napišete funkciju slucajni koja prima cijeli broj na intervalu 0-99999999 (osmocifreni broj) koji predstavlja prethodni slučajni broj, a vraća cijeli broj na istom intervalu koji predstavlja sljedeći slučajni broj izračunat ovim algoritmom.

Da bismo izbjegli "tačna" rješenja za koja ne prolaze testovi, pridržavajte se sljedećeg algoritma:

Najprije se formira realan broj x takav da je primljeni cijeli broj postavljen iza decimalnog zareza. Npr. ako je primljen broj 12345678, x treba glasiti 0,12345678. Koristite tip double. Obratite pažnju da ako funkcija primi npr. broj 1000, to je ustvari 00001000 i treba dobiti realni broj 0,00001.
Zatim izračunajte korijen broja x. U prethodnom primjeru, ovaj korijen glasi: 0,35136417005722…
Iskoristite decimale od pete do dvanaeste i od njih formirajte cijeli broj. U prethodnom primjeru taj cijeli broj će glasiti 64170057 i to je vrijednost koju funkcija treba vratiti.
*/

// MOJ KOD:

#include <stdio.h>
#include <math.h>

int slucajni(int x);

int main() {
  printf("%d", slucajni(12345678));
  return 0;
}

int slucajni(int x) {

  double x2 = x / pow(10,8); // 0.1234567
  double korijen = sqrt(x2);  // 0,3513641700572
  long int novi = korijen * (pow(10, 13));// 3513641700572

  novi = (long int)(novi / 10);// 351364170057
  int rezultat = novi % (int)(pow(10, 8));// 64170057

  return rezultat;
}