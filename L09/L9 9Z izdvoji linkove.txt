#include <stdio.h>

int main() {

    FILE* ulaz = fopen("index.html", "r");
    if(!ulaz){
        printf("Datoteka index.html ne postoji");
        return 1;
    }

    FILE* izlaz = fopen("linkovi.txt", "w");
    if(!izlaz){
        fclose(ulaz);
        printf("Datoteka linkovi.txt ne postoji");
        return 1;
    }

    char c;
    int i, dobar = 0, pok;
    
    
    do{
        c = fgetc(ulaz);
        if(c=='<'){
            pok=ftell(ulaz);
            dobar = 0;
            while(c!=EOF){
                c = fgetc(ulaz);
                if(c=='>'){
                    dobar = 1;
                    break;
                }
            }
            if(!dobar) break;
            fseek(ulaz, pok, SEEK_SET);
            dobar = 0;
            c = fgetc(ulaz);
            if(c==EOF) break;
            if(c=='a'){
                c = fgetc(ulaz);
                if(c==' '){
                while(c!='>' && c!=EOF){
                    while(c!='h'){
                        if(c=='>' || c==EOF){
                            dobar=1; break;
                        }
                        c = fgetc(ulaz);
                    }
                    if(dobar==1) break;
                    c=fgetc(ulaz);
                    if(c=='r') c=fgetc(ulaz); else continue;
                    if(c=='e') c=fgetc(ulaz); else continue;
                    if(c=='f'){
                        c=fgetc(ulaz);//=
                        c=fgetc(ulaz);// /
                        c=fgetc(ulaz);//''
                        while(c!='"'){
                            fputc(c, izlaz);
                            c = fgetc(ulaz);
                            if(c=='"') break;
                        }
                        fputc('\n', izlaz);
                    }
                }
            }}
            if(c==EOF) break;
        }
    }while(c!=EOF);

    fclose(ulaz);
    fclose(izlaz);

	return 0;
}
