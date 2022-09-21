#include <stdio.h>

int main() {

    int n;
    printf("Unesite broj: ");
    scanf("%d", &n);

    if(n<1){
        printf("Pogresan unos");
        return 1;
    }

    FILE* ulaz = fopen("input.txt", "r");
    if(!ulaz){
        printf("Datoteka input.txt ne postoji");
        return 1;
    }

    FILE* izlaz = fopen("output.txt", "w");
    if(!izlaz){
        fclose(ulaz);
        printf("Datoteka output.txt ne postoji");
        return 1;
    }

    char c, temp=' ';
    unsigned int brojac = 0;
    int i;

    do{
        c = fgetc(ulaz);
        if(temp!=c){
            if(brojac>=n){
                for(i=0; i<brojac; i++) fputc(temp, izlaz);
            }
            brojac = 0;
        }
    brojac++;
    temp = c;
    }while(c!=EOF);

    fclose(ulaz);
    fclose(izlaz);

	return 0;
}
