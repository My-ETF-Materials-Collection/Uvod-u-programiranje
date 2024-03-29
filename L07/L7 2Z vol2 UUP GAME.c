/*
Zadatak
Napisati funkciju void ispisi_unazad (const char *str) koja ispisuje proslijeđeni string u obrnutom redoslijedu. Funkcija ne smije koristiti nikakve pomoćne funkcije niti petlje, nego njena implementacija treba biti rekurzivna. Primjer:

const char *str = "Uvod u programiranje - UUP";
ispisi_unazad(str); //Ispisuje: „PUU - ejnarimargorp u dovU“
Napomena: Nije dozvoljeno kreirati pomoćne stringove u funkciji ili globalno.
*/

// MOJ KOD:

#include <stdio.h>

void ispisi_unazad(const char *str);

int main() {
    const char str[]="Uvod u programiranje - UUP";
	ispisi_unazad(str);
	return 0;
}


void ispisi_unazad(const char *str){

if(*str){
    ispisi_unazad(str+1);
    printf("%c",*str);
}

}