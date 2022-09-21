#include <stdio.h>

int i=0, j=0;
/* Ovdje pisete funkcije unesi_niz i srednja_vrijednost */
void unesi_niz(){
    double p, niz[100];
    while(i!=100){
        scanf("%lf", &p);
        if(p!=-1){
            niz[i]=p;
            i++;
        }else break;
    }
    FILE *ulaz = fopen("niz.bin", "w");
    if(!ulaz) printf("Greska pri otvaranju.\n");
    for(j=0; j<i; j++) fwrite(niz, sizeof(double), i, ulaz);
    fclose(ulaz);
}

double srednja_vrijednost(){
    double suma = 0; 
    if(i==0) return 0;
    FILE *ulaz = fopen("niz.bin", "r");
    if(!ulaz){printf("Greska pri otvaranju.\n"); return 0;}
    double niz[100];
    fread(niz, sizeof(double), i, ulaz);
    int j;
    for(j=0; j<i; j++) suma += niz[j];
    fclose(ulaz);
    return suma/i;
}

int main() {
    unesi_niz();
    printf("%g\n", srednja_vrijednost());
    return 0;
}
