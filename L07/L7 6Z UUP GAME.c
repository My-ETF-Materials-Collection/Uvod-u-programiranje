/*
Zadatak
Napisati funkciju

void nta_rijec(const char* str, char* rijec, int n)
koja pronalazi n-tu riječ u rečenici str i smješta je u niz na koji pokazuje parametar rijec. Ukoliko je n veći od broja riječi u rečenici, funkcija treba da stavi „prazan“ string u parametar rijec (nul znak tj. '\0' na početak stringa). Pod pojmom "riječ" podrazumijevamo neprekinuti niz velikih ili malih slova. Primjer ispod treba da ispiše „2. rijec: 'pije'“:

const char *tekst = "  Zeko    pije   mlijeko!  ";
char rijec[101]; //pretpostavimo da nije duza od 100 znakova
nta_rijec(tekst, rijec, 2); // 2. rijec po redu ("pije")
printf ("2. rijec: '%s'", rijec);
Napomena: Nije dozvoljeno kreirati pomoćne stringove u funkciji ili globalno.
*/

// MOJ KOD:

#include <stdio.h>

void nta_rijec(const char *s, char *rijec, int n){
  const char *p;
  int br=1;
  for(p=s;*p!='\0';p++){
    if(br==n && ((*p>='A'&& *p<='Z') || (*p>='a'&& *p<='z'))){
      br++;
      while((*p>='A'&&*p<='Z') || (*p>='a'&&*p<='z')){
        *rijec=*p;
        if(*p=='\0') break;
        rijec++;
        p++;
        
      }
      *rijec='\0';
    }
    if((*p>='A'&&*p<='Z') || (*p>='a'&&*p<='z')){
      br++;
      while((*p>='A'&&*p<='Z') || (*p>='a'&&*p<='z')) {
        p++;
        if(*p=='\0') break;
      };
    }
    if(br<n) *rijec='\0';
  }
}
int main() {
  int n = 12;
 const char *tekst = "  .  UUP -  Uvod  !@#u. . . . . . ...  ......  ......///...  programiranje";
char rijec[2], rrijec[]="rijec"; /* Niz je taman dovoljno velik */
nta_rijec(tekst, rijec, 3); 
printf ("3. %s: '%s'", rrijec, rijec);
  return 0;
}