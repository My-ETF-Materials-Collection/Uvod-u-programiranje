/*
Zadatak
Dat je neki niz prirodnih brojeva (uključujući nulu), na primjer:
233, 38, 17777, 7737, 152
Ovaj niz možemo posmatrati kao neprekinuti niz cifara, npr:
23338177777737152
Potrebno je u drugi niz upisati: cifru i koliko puta uzastopno se ta cifra nalazi u ovom neprekinutom nizu. Dakle, za primjer iznad drugi niz bi trebao glasiti:
2 1 3 3 8 1 1 1 7 6 3 1 7 1 1 1 5 1 2 1
(cifra 2 se pojavljuje 1 put uzastopno, cifra 3 se pojavljuje 3 puta uzastopno itd.)

Potrebno je napisati program koji radi na sljedeći način: najprije se unosi veličina polaznog niza (max. 100 elemenata), a zatim i njegovi članovi (osigurati da se ponavlja unos ako korisnik proba unijeti neispravnu veličinu ili član koji nije prirodan broj ili nula). Zatim se na ekranu ispisuju članovi drugog niza razdvojeni znakom razmaka.

Primjer ulaza i izlaza:

Unesite velicinu niza: 5
Unesite clanove niza: 233 38 17777 7737 152
Finalni niz glasi:
2 1 3 3 8 1 1 1 7 6 3 1 7 1 1 1 5 1 2 1
Napomena: U postavci zadatka je dat polazni kod - nije dozvoljeno promijeniti ovaj kod! Vaše rješenje zadatka napišite umjesto komentara === OVDJE UBACITI KOD === a ono što se nalazi prije i poslije toga nipošto nemojte mijenjati jer vam neće prolaziti testovi!
*/

// MOJ KOD:

#include <stdio.h>

int main() {
  int niz[100], vel, niz2[1000], vel2, i;
  printf("Unesite velicinu niza: ");
  scanf("%d", &vel);
  printf("Unesite clanove niza: ");
  for (i = 0; i < vel; i++)
    scanf("%d", &niz[i]);

  int cifra, n = 0, a, j;
  for(i=0;i<30;i++){//1000000200330000 iz nekog razloga se pamti viska 0 pa kako je
  //niz definisan sa ovim scanafovanim clanovima i ostalim 0-ama provjerava se je li 0 u testu 5
  //pa ako se promjene svi ostali clanovi u neki br sto nije cifra popravit cemo da se to ne desi niti za jedan element niza
      niz2[i]=10;
  }
  
  for (i = 0; i < vel; i++) {
    cifra = niz[i]; // spasi se broj npr.456,21
    j = 0;
    do {
      cifra /= 10;        // dobije se prva cifra od br. tj 456,45,4-21,2
      n++;                // poveca se 3 puta tj
    } while (cifra != 0); // koliko neki br ima cifara
    cifra = niz[i];       // 456,21 (zbg n se uradilo ovo gore)
    do {
      a = cifra % 10; // spasi se zadnja, 456->6, 21->1
      niz2[n - j - 1] =
          a;       // niz2[4]=1, niz2[3]=2, niz2[2]=6, niz2[1]=5, niz2[0]=4
      cifra /= 10; // 45,2
      j++;         // 1,2
    } while (cifra != 0);
  }
  vel = n;                      // 3+2=5, 456,21
  a = n;                        // 5
  for (i = 0; i < n-1; i++) { // provjeriti ako ima uzastopnih cifara
    if (niz2[i] == niz2[i + 1]) {
      a--; // ovoliko ima ako se uzastopni gledaju kao 1 br
    }      // 4 4 5 6 2 1 --> 4 2 5 1 6 1 2 1 1 1
  }
  
  n = 2 * a; // 10 jer sve se cifre jave u paru (cifra,brponavljanja)
  j = 1;
  cifra = niz2[0]; // 4
  vel2 = 0;        // vel=5, koliko cifara ima
  for (i = 1; i <= vel; i++) {
    if (cifra == niz2[i]) {
      j++;
    } else {
      niz[vel2] = cifra; // 4
      niz[vel2 + 1] = j;
      vel2 += 2;       // 4 1, 5 1, 6 1,...
      cifra = niz2[i]; // 5
      j = 1;           // koliko se cifra ponavlja
    }
    if (i == vel) {
      // za kraj
      niz[vel2] = cifra;
      niz[vel2 + 1] = j;
      vel2 += 2;
      cifra = niz2[i];
      j = 1;
    }
  }

  vel2 = n;
  for (i = 0; i < n; i++) {
    niz2[i] = niz[i]; // jer u ispisu se trazi niz2[i] a ja "punila" niz[i], pa
                      // samo vrijednosti zamjenila
  }

  /*
  233 38 17777 7737 152
  23338177777737152
  brojac ++ za svaku cifru sto naleti
  prvo spremit cifre u neki niz redom koje se javljaju
  ako se neka ponovi samo brojac povecati ali ne
  spasavati u niz cifara, ako se ne ponavlja, spasiti
  u niz cifara i brojac povecati koliko se ta
  cifra javlja
  */

  printf("Finalni niz glasi:\n");
  for (i = 0; i < vel2; i++)
    printf("%d ", niz2[i]);
  return 0;
}
