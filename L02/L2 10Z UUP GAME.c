/*
Zadatak
Napisati program koja izračunava vrijednost ln(1+x) po sljedećoj formuli dobijenoj koristeći Taylorov razvoj:
image.png

Program treba omogućiti korisniku da unese dva broja: realan broj x (tipa double) na intervalu (-1,1) i pozitivan cijeli broj n koji označava broj članova sume. Ako uneseni brojevi nisu iz traženog opsega treba ispisati poruku "Greska." i tražiti ponavljanje unosa.

Zatim treba ispisati vrijednost sume koja je izračunata po gornjoj fomuli, vrijednost dobijenu koristeći bibliotečnu funkciju za računanje prirodnog logaritma, te razliku u postotcima vrijednosti koja je izračunata u odnosu na bibliotečnu funkciju (ova razlika može biti i negativan broj ako je funkcija ln1x vratila vrijednost manju od bibliotečne).

Vrijednosti funkcije ln trebaju biti ispisane na 6 decimala, a vrijednost postotka treba biti ispisana i zaokružena na dvije decimale (treba ispisati obje decimale čak i ako su nule) i ispisana sa znakom %. Primjer ulaza i izlaza:


Unesite broj x: 0.5
Unesite broj n: 5
Izracunata vrijednost: 0.407292
Bibliotecna funkcija: 0.405465
Razlika u postotcima: 0.45%
*/

// MOJ KOD:

#include <stdio.h>
#include <math.h>

int main() {
    double x;
    int n;

    printf("\nUnesite broj x: ");
    scanf("%lf",&x);
	while(x>=1 || x<=-1){
        printf("Greska.");
        printf("\nUnesite broj x: ");
        scanf("%lf",&x);
    }
    printf("Unesite broj n: ");
    scanf("%d",&n);
    while(n<=0){
        printf("Greska.");
        printf("\nUnesite broj n: ");
        scanf("%d",&n);
    }      
        int i;
        double suma=0;
        for(i=1;i<=n;i++){
            suma+=(pow((-1),i-1)*pow(x,i))/i;
        }
        
    double bibsuma;
    bibsuma=log(1+x);
    
    double rp;
    rp=((suma-bibsuma)/bibsuma)*100;

    printf("\nIzracunata vrijednost: %.6lf", suma);
    printf("\nBibliotecna funkcija: %.6lf", bibsuma);
    if(suma==0){
        printf("\nRazlika u postotcima: 0.00%%");
    }else{
        printf("\nRazlika u postotcima: %.2lf%%", rp);
    }

    return 0;
}
