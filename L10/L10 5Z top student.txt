#include <stdio.h>
#include <string.h>
struct Student {
        char ime[20];
        char prezime[20];
};

struct Ocjena {
        struct Student s;
        char predmet[100];
        int ocjena;
};

struct Predmet {
        int id;
        char naziv[100];
        float prosjek;
};

struct Student top_student(struct Ocjena* niz, int velicina){
    int i, j, suma=0, brojPredmeta, najStudent=0;
    float prosjek, maxProsjek=0;
    for(i=0; i<velicina; i++){
        suma=0; brojPredmeta=0;
        for(j=0; j<velicina; j++){
            if(!strcmp(niz[i].s.ime, niz[j].s.ime) && !strcmp(niz[i].s.prezime, niz[j].s.prezime)){
                suma+=niz[j].ocjena;
                brojPredmeta++;
            }
        }
        prosjek = (float)suma/brojPredmeta;
        if(prosjek>maxProsjek){
            najStudent = i;
            maxProsjek = prosjek;
        }
        if(maxProsjek==prosjek){
            if(strcmp(niz[i].s.prezime, niz[najStudent].s.prezime)<0){
                najStudent=i;
                maxProsjek=prosjek;
            }
        }
    }
    return niz[najStudent].s;
}

int ucitaj_ocjene(struct Ocjena* niz, int kapacitet){
    FILE* ulaz = fopen("ocjene.dat", "rb");
    if(!ulaz){
        printf("Greska.\n");
        return 1;
    }
    int i=0;
    while(i<kapacitet && fread(niz[i].s.ime,1,20,ulaz)==20 && fread(niz[i].s.prezime,1,20,ulaz)==20 && fread(niz[i].predmet,1,100,ulaz)==100 && fread(&niz[i].ocjena,4,1,ulaz)==1) i++;
    fclose(ulaz);
    return i;
}

int ucitaj_predmete(struct Predmet* niz, int kapacitet){
    int i=0, j; char c;
    FILE* ulaz = fopen("predmeti.txt", "r");
    if(!ulaz){
        printf("Greska.\n");
        return 1;
    }
    while(i<kapacitet && fscanf(ulaz, "%d,", &niz[i].id)==1){
        j=-1;
        do{
            j++;
            if(j>30){
                do{
                    c = fgetc(ulaz);
                }while(c!=',' && c!=EOF);
                break;
            }
            niz[i].naziv[j] = fgetc(ulaz);
        }while(niz[i].naziv[j]!=',' && niz[i].naziv[j]!=EOF);
        niz[i].naziv[j]='\0';
        if(fscanf(ulaz, "%f\n", &niz[i].prosjek)!=1) break;
        i++;
    }
    return i;
}

struct Predmet max_prosjek(struct Predmet* niz, int kapacitet){
    int i, max=0;
    for(i=0; i<kapacitet; i++){
        if(niz[i].prosjek>niz[max].prosjek) max=i;
    }
    return niz[max];
}

void predmet_studenti(struct Predmet* nizP, int velP, struct Ocjena* nizO, int velO){
    int i;
    struct Predmet maxProsjek = max_prosjek(nizP, velP);
    for(i=0; i<velO; i++){
        if(!strcmp(maxProsjek.naziv, nizO[i].predmet)) printf("%s %s %d\n", nizO[i].s.ime, nizO[i].s.prezime, nizO[i].ocjena);
    }
}

void zapisi_predmete(struct Predmet* niz, int velicina){
    FILE* ulaz = fopen("predmeti.txt", "w");
    if(!ulaz){
        printf("Greska.\n");
        return;
    }
    int i;
    for(i=0; i<velicina; i++) fprintf(ulaz, "%d,%s,%.2f\n", niz[i].id, niz[i].naziv, niz[i].prosjek);
    fclose(ulaz);
}

int main() {

	return 0;
}
