#include <stdio.h>
#include <ctype.h>

void unesi(char niz[], int velicina){
    char znak = getchar();
    if(znak=='\n') znak = getchar();
    int i=0; 
    while(i<velicina-1 && znak!='\n'){
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

int main() {
    
    char datoteka[255];
    printf("Unesite naziv ulazne datoteke: ");
    unesi(datoteka, 255);

    FILE* ulaz = fopen(datoteka, "r");
    if(!ulaz){
        printf("Datoteka %s ne postoji", datoteka);
        return 1;
    }

    FILE* izlaz = fopen("statistika.txt", "w");
    if(!izlaz){
        fclose(ulaz);
        printf("Datoteka statistika.txt ne postoji");
        return 1;
    }

    char c;
    unsigned int histogram[127] = {0};
    do{
        c = fgetc(ulaz);
        if(isalpha(c)){
            if(isupper(c)) histogram[c]++;
            else histogram[c-32]++;
        }
    }while(c!=EOF);

    int max = histogram[0]; //maxBrojPonavljanjaBroja
    int i;

    while(1){
        for(i=0; i<127; i++){
            if(histogram[i]>histogram[max]) max=i;
        }
        if(max==0) break;
        fputc(max, izlaz);
        histogram[max]=0;
        max = histogram[0];
    }

    fclose(ulaz);
    fclose(izlaz);

	return 0;
}
