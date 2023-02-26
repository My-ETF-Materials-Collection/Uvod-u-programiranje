#include <stdio.h>

struct Radnik{
    char ime[20], prezime[20];
    int godina;
    double plata[12];
};

struct Radnik radnici[1000];
int br_radnika;

void ucitaj(){
    
    FILE* ulaz = fopen("ulaz.txt", "r");
    if(!ulaz){
        printf("Datoteka ulaz.txt ne postoji");
        return;
    }
    int i=0;
    while(i<1000 && fscanf(ulaz, "%19s %19s %d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", radnici[i].ime, radnici[i].prezime, &radnici[i].godina, &radnici[i].plata[0], &radnici[i].plata[1], &radnici[i].plata[2], &radnici[i].plata[3], &radnici[i].plata[4], &radnici[i].plata[5], &radnici[i].plata[6], &radnici[i].plata[7], &radnici[i].plata[8], &radnici[i].plata[9], &radnici[i].plata[10], &radnici[i].plata[11]) ==15) i++;
    br_radnika = i;
    fclose(ulaz);
}

void zapisi(){
    
    FILE* izlaz = fopen("izlaz.txt", "w");
    if(!izlaz){
        printf("Datoteka izlaz.txt ne postoji");
        return;
    }

    int i, velicina = br_radnika, j;
    double x, suma = 0;
    for(i=0; i<velicina; i++){
        suma=0;
        for(j=0; j<12;j++){
            suma+=radnici[i].plata[j];
            }
        x=suma/12;
        if(x>1000 && radnici[i].godina==2010) fprintf(izlaz, "%s %s %.2f\n", radnici[i].ime, radnici[i].prezime, x);
    }
    fclose(izlaz);

}

int main() {
	ucitaj(); zapisi();
	return 0;
}
