#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Datum { int dan, mjesec, godina; };
struct Osoba {
    char ime[20], prezime[20];
    struct Datum datum_rodjenja;
};

int daLiJePalindrom(char *s){
    int uslov=1;
    if(isalpha(s[0])){
        for(int i=0; i<strlen(s); i++){
            if(toupper(s[i])!=toupper(s[strlen(s)-1-i])){
                uslov=0; break;
            }
        }
    }else{
        for(int i=0; i<strlen(s); i++){
            if(s[i]!=s[strlen(s)-1-i]){
                uslov=0; break;
            }
        }
    }
    if(uslov) return 1;
    return 0;
}

int daLiJeDatumPalindrom(struct Datum d){
    
    char dani[3], mjeseci[3], godine[3];
    int a = d.dan, b = d.mjesec, c = d.godina;

    if(a<=9){
        dani[0]=a+'0'; dani[1]='\0';
    }
    if(a>9){
        dani[0]=(a/10)+'0'; dani[1]=a%10+'0'; dani[2]='\0';
    }

    if(b<=9){
        mjeseci[0]=b+'0'; mjeseci[1]='\0';
    }
    if(b>9){
        mjeseci[0]=(b/10)+'0'; mjeseci[1]=b%10+'0'; mjeseci[2]='\0';
    }
    
    godine[0]=((c%100)/10)+'0'; 
    godine[1]=c%10+'0';
    godine[2]='\0';

    char noviDatum[10]="";
    strcat(noviDatum, dani), strcat(noviDatum, mjeseci), strcat(noviDatum, godine);

    return daLiJePalindrom(noviDatum);
}

int izbaci_palindrome(struct Osoba nizOsoba[], int vel){
    int j;
    for(int i=0; i<vel; i++){
        if(daLiJePalindrom(nizOsoba[i].ime) || daLiJePalindrom(nizOsoba[i].prezime) || daLiJeDatumPalindrom(nizOsoba[i].datum_rodjenja)){
            for(j=i; j<vel-1; j++){
                nizOsoba[j]=nizOsoba[j+1];
            }
            vel--;
            i--;
            continue;
        }
    }
    return vel;
}

int main() {
	return 0;
}
