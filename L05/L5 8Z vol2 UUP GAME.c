/*
Zadatak
Napišite funkciju sa prototipom:

int broj_sadrzan(unsigned int a, unsigned int b)
koja prima dva pozitivna cijela broja a i b čije su vrijednosti u opsegu dozvoljenih vrijednosti tipa unsigned int, a vraća logičku istinu (cijeli broj 1) ako je broj b sadržan u broju a, a logičku neistinu (cijeli broj 0) ako nije. Npr. u broju 2358 sadržan je broj 35.

Napravite i main funkciju koja omogućuje da se unesu dva cijela broja, poziva funkciju broj_sadrzan, te ispisuje tekst ISTINA ili NEISTINA ovisno od toga šta je funkcija vratila.

Primjeri ulaza i izlaza:
Primjer 1:

Unesite broj a: 2358
Unesite broj b: 35
ISTINA
Primjer 2:

Unesite broj a: 2358
Unesite broj b: 223
NEISTINA
Primjer 3:

Unesite broj a: 2358
Unesite broj b: 8
ISTINA
Primjer 4:

Unesite broj a: 2358
Unesite broj b: 2358
ISTINA
Napomena: Zabranjeno je korištenje funkcija iz biblioteke string.h kao što je sprintf ili snprintf.
*/

// MOJ KOD:

#include <stdio.h>
#include <math.h>

int broj_sadrzan(unsigned int a, unsigned int b);

int main() {

    unsigned int a,b;

    printf("Unesite broj a: ");
    scanf("%d",&a);
    printf("Unesite broj b: ");
    scanf("%d",&b);
    
    if(broj_sadrzan(a,b)){
        printf("ISTINA");
    }else{
        printf("NEISTINA");
    }

    return 0;
}

int broj_sadrzan(unsigned int a, unsigned int b){
    //2358, 35

    if(a==0 && b==0){
        return 1;
    }
    //log broja daje vrijednost zavisno od broja cifara npr. log(10-99) je 1-2 log(100-199) je 2-3 itd.
    int div=pow(10, (int)(log10(b+1.1))+1);//10^(1+1)=100 
    //1,0 , (1-0)%undefined, mora kod logaritma numerus biti >0 
    //0,0,  (0-0) ali postoji poseban slucaj ako je b=0 zbog unsigned
    
    while(a){
        if((a-b)%div==0){//(2358-35)=2323 x, 235-35=200 yes
            return 1;
        }
        a/=10;
    }// 2358, 223 , (2358-223)%1000 x, 235-223=12%1000 x
    return 0;
   
}