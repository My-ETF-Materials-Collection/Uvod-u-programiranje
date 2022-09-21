#include <stdio.h>
#include <string.h> //zbog strcpy

struct Grad{
    char naziv[50];
    int br_stanovnika;
};

int ucitaj(struct Grad *gradovi, int velicina){
    FILE* ulaz = fopen("gradovi.txt", "r");
    if(!ulaz){
        printf("Datoteka gradovi.txt ne postoji");
        return 0;
    }
    char c, tempGrad[50], *p = tempGrad;
    int i=0;
    while((c=fgetc(ulaz))!=EOF && i<velicina){
        if(c<'0' || c>'9'){
            *p=c; p++;
        }else{
            p--;
            *p='\0';
            strcpy(gradovi[i].naziv, tempGrad);
            fseek(ulaz, -1, SEEK_CUR);
            fscanf(ulaz, "%d\n", &gradovi[i].br_stanovnika);
            i++;
            p = tempGrad;
        }
    }
    fclose(ulaz);
    return i;
}

void zapisi(struct Grad* gradovi, int velicina, int n){
    FILE* ulaz = fopen("izlaz.txt", "w");
    if(!ulaz){
        printf("Datoteka izlaz.txt ne postoji");
        return;
    }
    int i;
    for(i=0; i<velicina; i++){
        if(gradovi[i].br_stanovnika>n){
            fprintf(ulaz, "%s\n", gradovi[i].naziv);
        }
    }
    fclose(ulaz);
}

void ispis(struct Grad* gradovi, int velicina, char z){
    int i;
    for(i=0; i<velicina; i++){
        if(*(gradovi[i].naziv)==z) printf("%s\n",gradovi[i].naziv);
    }
}

int main() {
        struct Grad gradovi[100];
        int br_gradova = ucitaj(gradovi, 100);
        printf("Broj gradova: %d\n", br_gradova);
        if (br_gradova > 0) {
                printf("Prvi grad: %s (%d)\n", gradovi[0].naziv, gradovi[0].br_stanovnika);
        }
        zapisi(gradovi, br_gradova, 100000);
        ispis(gradovi, br_gradova, 'A');
        return 0;
}
