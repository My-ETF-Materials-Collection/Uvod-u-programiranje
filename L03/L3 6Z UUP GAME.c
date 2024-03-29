/*
Zadatak
U nekoj školi na velikom odmoru se dijele kolači. Učenici su se poredali abecednim redom i svaki učenik izjavljuje koliko želi kolača. Pošto je ispečen ograničen broj kolača, neće ih biti dovoljno za sviju. Vaš zadatak je da napravite program koji ispisuje koliko učenika će dobiti kolače prije nego što se kolači potroše (računamo i učenika koji je dobio manje kolača nego što želi).

Najprije se sa tastature unosi niz prirodnih brojeva (najviše 1000) koji se završava brojem -1. Članovi tog niza predstavljaju broj kolača koje učenici žele, npr. ako niz glasi 2 1 5 -1 to znači da ukupno ima tri učenika, prvi učenik želi dva kolača, drugi jedan a treći pet kolača. Nakon toga se unosi ukupan broj ispečenih kolača, te konačno treba ispisati koliko učenika je dobilo kolače.

Primjer ulaza i izlaza:

2 3 1 5 -1
3
2 ucenika su dobila kolace
Obratite pažnju da ispis broja učenika treba biti gramatički ispravan npr.:

Nijedan ucenik nije dobio kolace
32 ucenika su dobila kolace
121 ucenik je dobio kolace
12 ucenika je dobilo kolace
*/

// MOJ KOD:

#include <stdio.h>

int main() {

    int A[1000]; //clanovi niza su br kolaca sto svaki ucenik hoce
    int i, vel; // vel --> brojac

    int suma=0; // suma kolaca sto bi ucenici htjeli dobiti//
    int kolaci; //ukupno kolaca sto se napravilo//
       
    for(i=0; i<1000; i++){
        scanf("%d",&A[i]);
        if(A[i]==-1){
            break;
        }
    }

    vel=i-1; // -1 jer necemo da uzimamo u obzir zadnji unos tj prekid unosa -1

    scanf("%d",&kolaci);

    for(i=0; i<vel; i++){ 
        suma+=A[i];
        if(suma>=kolaci){
            break;
        }
    }
    if(kolaci==0){
        printf("Nijedan ucenik nije dobio kolace");
    }else if((i+1)%10==1 && (1+i)!=11){ // i+1 jer smo gore krenuli od 0
        printf("%d ucenik je dobio kolace", 1+i);
    }else if((1+i)%10==2 && (1+i)!=12){
        printf("%d ucenika su dobila kolace", 1+i);
    }else{
        printf("%d ucenika je dobilo kolace", 1+i);
    }

  return 0;
}