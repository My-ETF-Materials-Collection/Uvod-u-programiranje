/*
Zadatak
Napisati funkciju zamijeni_slova koja prima dva stringa. Funkcija transformiše string koji je primljen kao prvi parametar tako što u njemu zamjenjuje prvi znak iz stringa koji je proslijeđen kao drugi parametar sa posljednjim znakom iz istog stringa, drugi sa pretposljednjim itd. do sredine stringa. Ako drugi parametar sadrži neparan broj znakova, sa znakom koji se nalazi u sredini ne treba raditi ništa. Ako je jedan od parametara prazan string, funkcija ne treba raditi ništa.

Npr. ako prvi parametar glasi "dobar dan" a drugi glasi "abcde" nakon zamjene tekst treba glasiti "doder den" jer je slovo "a" zamijenjeno slovom "e", a slovo "b" slovom "d", dok sa slovom "c" nije urađeno ništa jer se nalazi u sredini stringa "abcde" i tu se rad prekida.

Funkcija treba vraćati pokazivač na početak stringa tekst radi lakšeg lančanog pozivanja.

Napomena: U zadatku je dozvoljeno koristiti funkcije iz biblioteke string.h, ali nije obavezno, odnosno zadatak se može riješiti i bez njih. Nije dozvoljeno koristiti pomoćne nizove i takvo rješenje će dobiti 0 bodova!
*/

// MOJ KOD

#include <stdio.h>

void unesi (char* niz, int vel) {
    int i=0;
    char z=getchar();
    if (z=='\n') {z=getchar();}
    while (z!='\n' && i<vel-1) {
        niz[i]=z;
        i++;
        z=getchar();
    }
    niz[i]='\0';
}

char* zamijeni_slova(char* a, char* b){
    char* p1=b;
    char* p2=b;

    while(*p2!='\0'){//isla do kraja b
        p2++;
    }
    p2--;

    while(p2>=p1){//poredila da bi promjenila kod a ove vrijednosti
        char* p3=a;//od b
        while(*p3!='\0'){//sve dok ne dodje do kraja stringa a da bi ih sve izmjenilo
            if(*p3==*p1){
                *p3=*p2;
            }
            p3++;
        }
        p1++;
        p2--;
    }
    
    return a;
}

int main() {
    char tekst[100], slova[100];
    printf("Unesite neki tekst: ");
    unesi(tekst, 100);
    printf("Unesite string sa slovima za zamjenu: ");
    unesi(slova, 100);
    zamijeni_slova(tekst, slova);
    printf("Nakon transformacije tekst glasi: '%s'\n", tekst);
    return 0;
}
