#include <stdio.h>

struct Planina{
    char naziv[50];
    int visina;
};

int ucitaj(struct Planina* planine, int velicina){
    FILE* ulaz = fopen("ulaz.txt", "r");
    if(!ulaz){
        printf("Datoteka ulaz.txt ne postoji");
        return 1;
    }
    int i=0;
    while(i<velicina && fscanf(ulaz, "%s %d\n", planine[i].naziv, &planine[i].visina)==2) i++;
    fclose(ulaz);
    return i;
}

void zapisi(struct Planina* planine, int velicina, int maxVisina){
    FILE* izlaz = fopen("izlaz.txt", "w");
    if(!izlaz){
        printf("Datoteka izlaz.txt ne postoji");
        return;
    }
    int i;
    for(i=0; i<velicina; i++){
        if(planine[i].visina>maxVisina) fprintf(izlaz, "%s\n", planine[i].naziv);
    }
    fclose(izlaz);
}

int main() {
	return 0;
}
