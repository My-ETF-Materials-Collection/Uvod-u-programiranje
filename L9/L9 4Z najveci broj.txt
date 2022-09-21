#include <stdio.h>
#include <ctype.h> //za isdigit treba
#include <limits.h> 

int main() {
    
    FILE* ulaz = fopen("zadatak.txt", "r");
    if(!ulaz){
        printf("Greska.\n");
        return 1;
    }

    FILE* izlaz = fopen("rjesenje.txt", "w");
    if(!izlaz){
        fclose(ulaz);
        printf("Greska.\n");
        return 1;
    }

    char c;
    int postojiBroj = 0;
    int BrojJe = 0;
    int broj=0;
    int predznak = 1;
    int maxBroj = INT_MIN;
    
    do{
        
        c = fgetc(ulaz);

        if(isdigit(c)){
            postojiBroj = 1;
        }

        if(c>='0' && c<='9'){
            BrojJe=1;
            broj = 10 * broj + (c-'0');
        }else if(c=='-') predznak = -1;
        else {
            if(broj*predznak>maxBroj && BrojJe) maxBroj = broj*predznak;
            broj = 0;
            BrojJe = 0;
            predznak = 1;
            }
    }while(!feof(ulaz));

    if(!postojiBroj) maxBroj = 0;

    fprintf(izlaz, "%d", maxBroj);

    fclose(ulaz);
    fclose(izlaz);

	return 0;
}
