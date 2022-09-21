#include <stdio.h>

int string2double(const char* string, double *broj){
    
    const char *s = string, *provjera=string;
    int brojac=0;

    while(*provjera!='\0'){
        if(*provjera=='.'){
            provjera++;
            brojac++;
            if(brojac>1) return 0;
            continue;
        }
        if(*provjera<'0' || *provjera>'9') return 0;
        provjera++;
    }
    
    while(*s!='.' && *s!='\0') s++;

    const char *pom = --s;
    double suma=0;
    int desetice=1;

    while(pom>=string){
        suma+=(*pom-'0')*desetice;    
        desetice*=10;
        pom--;
    } 

    if(*(s+1)=='\0'){
        *broj=suma;
        return 1;
    }

    pom=s+2;
    double zarez=0.1;

    while(*pom!='\0'){
        suma+=(*pom-'0')*zarez;
        zarez/=10;
        pom++;
    }

    *broj = suma;  
    return 1;  
}

int main() {
	return 0;
}
