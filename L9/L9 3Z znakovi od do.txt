#include <stdio.h>

int main() {
    
    char x,y;
    printf("Unesite znakove x i y: ");
    scanf("%c %c",&x,&y);

    if(y<x){
        printf("Pogresan unos");
        return 1;
    }

    FILE* ulaz = fopen("input.txt", "r");
    if(!ulaz){
        printf("Otvaranje datoteke input.txt nije uspjelo");
        return 1;
    }

    FILE* izlaz = fopen("output.txt", "w");
    if(!izlaz){
        fclose(ulaz);
        printf("Otvaranje datoteke output.txt nije uspjelo");
        return 1;
    }

    char c;
    do{
        c = fgetc(ulaz);
        if(c!=EOF && (c>=x && c<=y)){
            fputc(c,izlaz);
        }
        if(ferror(ulaz) || ferror(izlaz)){
            printf("Greska.\n"); return 1;
        }
    }while(!feof(ulaz));

    fclose(ulaz);
    fclose(izlaz);
    
	return 0;
}
