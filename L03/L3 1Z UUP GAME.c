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
Zadatak
Napišite program koji omogućuje korisniku da unese neograničeno mnogo cijelih brojeva sa tastature, pri čemu broj -1 označava kraj unosa. Zatim se na ekranu ispisuje koliko unesenih brojeva je djeljivo sa 5, sa 7 i sa 11.

Primjer ulaza i izlaza:

Unesite brojeve:
2
5
6
16
5
22
35
55
56
-1
Djeljivih sa 5: 4
Djeljivih sa 7: 2
Djeljivih sa 11: 2
*/

// MOJ KOD:

#include <stdio.h>
#define VEL 10000
int main() {
    int n, niz[VEL],brojac[VEL]={0},a,y,z;
	printf("Unesite brojeve:");
	do{
      scanf("%d",&n); 
      /*if(n%5==0){
          brojac[a]++;
      }else*/ if(n%7==0){
          brojac[y]++;
      }else if(n%11==0){
          brojac[z]++;
      }
    }while(n!=-1);
    /*
    printf("\nDjeljivih sa 5: %d",brojac[a]);*/
    printf("\nDjeljivih sa 7: %d",brojac[y]);
    printf("\nDjeljivih sa 11: %d",brojac[z]);
    
    return 0;
}
