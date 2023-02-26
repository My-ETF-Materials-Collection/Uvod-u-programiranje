/*
Zadatak
Data je struktura:

struct Grad {
    char naziv[20];
    int pozivni_broj;
}
Napisati funkciju preslozi_pozivni koja prima niz gradova, veličinu i jedan pozivni broj. Potrebno je niz presložiti tako da se na početku niza nalaze gradovi čiji je pozivni broj jednak parametru funkcije, a zatim svi ostali. Unutar ove dvije grupe (jednak i različit pozivni broj) redoslijed mora biti nepromijenjen u odnosu na primljeni niz.

Napisati i main funkciju koja omogućuje da se unese niz gradova proizvoljne dužine, zatim poziva funkciju preslozi_pozivni, te na kraju ispisuje tako presložen niz na ekran.

Napomena: U funkciji je strogo zabranjeno kreirati pomoćni niz, i takvo rješenje će biti bodovano sa 0 bodova.
*/

// MOJ KOD:

#include <stdio.h>
struct Grad{
    char naziv[20];
    int pozivni_broj;
};

void preslozi_pozivni (struct Grad *niz, int vel, int pozivni)
{
    int i=0, mjesto, x=0, y;
    struct Grad temp;
    while(i<vel){
        y=i;
        if(pozivni==niz[i].pozivni_broj)
        {
            temp=niz[x];
            niz[x]=niz[i];
            if(x!=i)
            {
                while(x+1<i)
                {
                    niz[i]=niz[i-1];
                    i--;
                }
                niz[x+1]=temp;
            }
            i=y;
            x++;
        }
        i++;
    }
}
int main() {
  struct Grad niz[6] = {{"Sarajevo", 033}, {"Tuzla", 032},  {"Mostar", 031},
                        {"Vogosca", 033},  {"Zenica", 034}, {"Ilidza", 033}};
  int i;
  preslozi_pozivni(niz, 6, 033);
  for (i = 0; i < 6; i++)
    printf("%s ", niz[i].naziv);
  return 0;
}


