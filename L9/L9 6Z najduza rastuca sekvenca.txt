#include <stdio.h>

int main() {
	
    FILE* ulaz = fopen("ulaz.txt", "r");
    if(!ulaz){
        printf("Datoteka ulaz.txt ne postoji");
        return 1;
    }

    FILE* izlaz = fopen("izlaz.txt", "w");
    if(!izlaz){
        fclose(ulaz);
        printf("Datoteka izlaz.txt ne postoji");
        return 1;
    }

    int c = -1, brojac = 1, prosli, pok, novi, cMax = 0, i, maxPozicija = 0;
    do{

        prosli = c;
        if(brojac == 1) pok = ftell(ulaz);
        c = fgetc(ulaz);

        if(prosli!=-1 && prosli+1==c){ 
            brojac++;
        }else{
             if(brojac>cMax){
                cMax = brojac;
                maxPozicija = pok;
            }
            brojac = 1;
        }
    }while(c!=EOF);

    fseek(ulaz, maxPozicija-1, SEEK_SET);

    for(i=0; i<cMax; i++){
        c = fgetc(ulaz);
        fputc(c, izlaz);
    }

    fclose(ulaz);
    fclose(izlaz);

    return 0;
}
