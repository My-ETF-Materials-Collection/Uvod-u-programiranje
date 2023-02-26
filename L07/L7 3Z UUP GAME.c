/*
Zadatak
Napisati funkciju

char *izbaci_viska_razmake (char *str)
koja izbacuje sve višestruke razmake iz proslijeđenog stringa. Dodatno, funkcija treba da ukloni sve eventualne razmake prije prve riječi i nakon posljednje riječi. Npr. ako je string „ volim UUP “, nakon poziva funkcije string treba da ima sljedeći tekst „volim UUP“. Funkcija treba vratiti pokazivač na početak stringa.

Napomena: Nije dozvoljeno kreirati pomoćne stringove u funkciji ili globalno.
*/

// MOJ KOD:

#include <stdio.h>
#include <string.h>

char *izbaci_viska_razmake(char *str);

int main() {
    char s[100]=" volim UUP";
	printf("'%s'",izbaci_viska_razmake(s));
	return 0;
}

char *izbaci_viska_razmake(char *str){
    
   int vel=strlen(str),i,j;
   for(i=0;i<vel;i++){
       if(str[0]==' '){
           for(i=0;i<vel-1;i++){
               str[i]=str[i+1];
           }
           str[i]='\0';
           vel--;
           i=-1;
           continue;
       }
       if(str[i]==' ' && str[i+1]==' ')
        {
            for(j=i; j<(vel-1); j++)
            {
                str[j] = str[j+1];
            }
            str[j] = '\0';
            vel--;
            i--;
        }
        if(i==vel-1 && str[i]==' '){
            str[i]='\0';
        }
    }
    return str;
}