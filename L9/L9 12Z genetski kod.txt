#include <stdio.h>

void printajGresku(){
    printf("Pogresan format\n");
    return;
}

int PrebrojKaraktere(char* a){
    int brojac=0;
    char prvi = *a, drugi = *(a+1), treci = *(a+2);
    char *pomocni = a;

    while(*pomocni){
        if(*(pomocni+1)=='\0') break;
        if(*(pomocni+2)=='\0') break;
        if(prvi==*pomocni && drugi==*(pomocni+1) && treci==*(pomocni+2)) brojac++;
        else break;
        pomocni=pomocni+3;
    } 
    return brojac;
}

int main() {

    FILE* ulaz;
    ulaz = fopen("genetski_kod.txt", "r");
    if(!ulaz){
        printajGresku();
        return 0;
    }

    char niz[200000], c;

    c=fgetc(ulaz);
    if(c==EOF){
        printajGresku();
        return 0;
    }else ungetc(c, ulaz);

    fgets(niz, 200000, ulaz);

    int max, poz, poredbeni, i, vel=0;

    char* pom = niz;

    while(*pom!='\0'){
        vel++;
        pom++;
    }

    if(vel<3){
        printajGresku();
        fclose(ulaz);
        return 0;
    }

    for(i=0; i<vel; i++){
        if(niz[i]!='A' && niz[i]!='C' && niz[i]!='T' && niz[i]!='G'){
            printajGresku();
            fclose(ulaz);
            return 0;
        }
    }

    max = PrebrojKaraktere(niz);
    poz = 0;

    for(i=1; i<vel; i++){
        poredbeni = PrebrojKaraktere(niz+i);
        if(poredbeni>max){
            max = poredbeni;
            poz = i;
        }
    }

    printf("%c%c%c\n", *(niz+poz), *(niz+poz+1), *(niz+poz+2));

    fclose(ulaz);
    
	return 0;
}
