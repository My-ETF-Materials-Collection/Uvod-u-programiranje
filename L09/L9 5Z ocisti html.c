#include <stdio.h>

int main() {
    
    FILE* ulaz = fopen("index.html", "r");
    if(!ulaz){
        printf("Datoteka index.html ne postoji");
        return 1;
    }

    FILE* izlaz = fopen("index.txt", "w");
    if(!izlaz){
        fclose(ulaz);
        printf("Datoteka index.txt ne postoji");
        return 1;
    }

    char c;

    do{
        c=fgetc(ulaz);
        if(c=='<'){
            while(c!='>' && !feof(ulaz)) c = fgetc(ulaz);
            continue;
        }
        if(c=='&'){
            while(c!=';' && !feof(ulaz)) c = fgetc(ulaz);
            continue;
        }
        fputc(c, izlaz);
    }while(!feof(ulaz));

    fclose(ulaz);
    fclose(izlaz);

    return 0;
}
