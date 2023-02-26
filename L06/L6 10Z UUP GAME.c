/*
Zadatak
Napišite funkciju zaokruzi koja kao parametar prima niz proizvoljne dužine sastavljen od realnih brojeva dvostruke preciznosti, a zatim sve brojeve u nizu zaokružuje na jednu decimalu.

Napomena: Pri rješavanju zadatka obavezno koristiti pokazivačku aritmetiku! Nije dozvoljena ni trivijalna simulacija indeksiranja izrazima oblika *(niz+i).
*/

// MOJ KOD:

#include <stdio.h> 
#include <math.h> 

void zaokruzi(double *niz, int n){ 
    double *pok = niz; 
    double *kraj= niz+n; 
    for(;pok<kraj;pok++){ 
        *pok=round(*pok*10)/10; 
    } 
} // 1.23, 3.47, 0, 1.23666 , niz,4 --> 1.2 3.5 0 1.2
// 1.23*10=12.3/10=1.2

int main() { 
    double niz[] = { 1.23, 3.47, 0, 1.23666 }; 
    zaokruzi(niz, 4); 
    int i; 
    for(i = 0; i < 4; i++) { 
      printf("%g ", niz[i]); 
    } 
    return 0; 
}