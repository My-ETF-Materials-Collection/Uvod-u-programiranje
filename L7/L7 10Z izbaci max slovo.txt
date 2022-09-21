#include <stdio.h>
#include <string.h>

char* izbaci_max_slovo(char* s){
    char* rez = s;
    int histogram[30]={0};
    while(*rez!='\0'){
        if(*rez>='A' && *rez<='Z') histogram[*rez-'A']++;
        if(*rez>='a' && *rez<='z') histogram[*rez-'a']++;
        rez++;
    }

    int i, maxPonavljanja = histogram[0]; char slovo=0;
    for(i=0; i<30; i++){
        if(histogram[i]>maxPonavljanja){maxPonavljanja = histogram[i]; slovo=i;}
    }
    
    int brSlova=0;
    while(s[brSlova]!='\0') brSlova++;

    for(i=0; i<brSlova; i++){
        if(s[i]==slovo+'A' || s[i]==slovo+'a'){
            for(int j=i; j<brSlova-1; j++){
                s[j]=s[j+1];
            }
            brSlova--;
            i--;
        }
    }
    s[i]='\0';
    return s;
}

int main() {
    char s[200] ="Ovako glasi rečenica koju ćemo koristiti za primjer i iz koje će se izbrisati slovo koje se najčešće pojavljuje";
    printf("%s",izbaci_max_slovo(s));
	return 0;
}
