#include <stdio.h>
#include <ctype.h>
#include <string.h>

void unesi(char niz[]){
    char znak;
    int i=0;
    do{
        znak=getchar();
        niz[i]=znak;
        i++;
    }while(znak!='\n');
    i--;
    niz[i]='\0';
}

int main(){
    char datoteka[255],c;
    int brojac=0, max=0;
    long pozicija, maxPozicija;

    printf("Unesite naziv datoteke: ");
    unesi(datoteka);

    FILE* ulaz2 =fopen(datoteka, "r");

    if(!ulaz2){
        printf("Datoteka %s ne postoji", datoteka);
        return 1;
    }

    do{
        
        brojac=0;
        pozicija=ftell(ulaz2);
        c=fgetc(ulaz2);

        while(isalpha(c) && !feof(ulaz2)){
            brojac++;
            c = fgetc(ulaz2);
        }

        if(brojac>max){
            max = brojac;
            maxPozicija = pozicija;
        }

    }while(!feof(ulaz2));

    if(!max) return 1;

    fseek(ulaz2, maxPozicija, SEEK_SET);

    do{
        c = fgetc(ulaz2);
        printf("%c",c);
    }while(isalpha(c));

    fclose(ulaz2);

    return 0;
}