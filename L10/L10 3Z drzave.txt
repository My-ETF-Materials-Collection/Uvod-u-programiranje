#include <stdio.h>

struct Drzava{
    char ime_drzave[50], glavni_grad[50];
    int broj_stanovnika, broj_stanovnika_gg;
};

int br_drzava = 0;
struct Drzava drzave[1000];

void ucitaj(){
    FILE* ulaz = fopen("ulaz.txt", "r");
    if(!ulaz){
        printf("Datoteka ulaz.txt ne postoji");
        return;
    }
    int i=0; 
    while(i<1000 && fscanf(ulaz, "%s %d %s %d", drzave[i].ime_drzave, &drzave[i].broj_stanovnika, drzave[i].glavni_grad, &drzave[i].broj_stanovnika_gg)==4) i++;
    fclose(ulaz);
    br_drzava=i;
}

void zapisi(){
    FILE* izlaz = fopen("izlaz.txt", "w");
    if(!izlaz){
        printf("Datoteka izlaz.txt ne postoji");
        return;
    }
    int i;
    for(i=0; i<br_drzava; i++){
        double prosjek = 100.*drzave[i].broj_stanovnika_gg/drzave[i].broj_stanovnika;
        char *pom = drzave[i].ime_drzave;
        char ime[50] = {' '};
        int j;
        for(j=0; j<50; j++){
            if(*(pom+j)=='\0') break;
            else if(*(pom+j)=='.') ime[j]=' ';
            else ime[j]=*(pom+j);
        }
        ime[49] = '\0';
        if(prosjek>20) fprintf(izlaz, "%-49s %d %.2lf\n", ime, drzave[i].broj_stanovnika, prosjek);
    }
    fclose(izlaz);
}

int main(){
    ucitaj(); zapisi();
	return 0;
}
