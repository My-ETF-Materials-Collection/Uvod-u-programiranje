/*
Zadatak
Sabit i Fadila su se odlučili okušati u pikadu, tradicionalnoj igri koja potiče iz Engleske, a danas je vrlo popularan sport. Sabit je odlučio da igraju igru 301, u kojoj je cilj prije protivnika doći do 0 poena.

Na standardnoj pikado tabli postoje tri vrste polja za brojeve: Single, Double i Triple, te Outer Bullseye i Inner Bullseye. Broj bodova koji je igrač ostvario se računa prema tipu polja u koje se strelica zabila. Tako se za brojeve od 1 do 20 pogotkom single polja ostvaruje broj bodova jednak tom broju, pogotkom double polja ostvaruje dupli broj poena dok pogotkom triple polja se ostvaruje trostruki broj poena. Outer Bullseye i Inner Bullseye nose 25 i 50 poena respektivno. Sabit i Fadila nisu vješti u ovoj igri te su se odlučili da će gađati samo brojeve koji su manji od 10.

Vaš zadatak je da napravite program koji najprije omogućuje da se unesu dvije sekvence karaktera koje predstavljaju 9 strelica koje su Sabit i Fadila bacili prema ploči, te da na osnovu unesenih sekvenci karaktera odredite koliko poena je koji igrač ostvario, te na osnovu preostalog broja poena odredite pobjednika u ovoj igri. Ukoliko je neki od igrača premašio 301 poen, potrebno je za njega ispisati poruku ‘Igrac X je premasio potrebni broj poena, ...’. Ukoliko oba igrača premaše potrebni broj poena, potrebno je ispisati poruku ‘Oba igraca su premasila potrebni broj poena, rezultat je nerijesen.’ Polja u sekvenci karaktera se označavaju slijedećim redom: single (S), double (D), triple (T), promašaj (X), outer bullseye (O), inner bullseye (I). Kraj unosa se označava znakom tačka. U slučaju da unos nije ispravan, tj. da se u unosu nalaze nelegalni karakteri ili nije unesen dovoljan broj strelica (9), program treba ispisati ‘Neispravni ulazni podaci’ te ponovo tražiti unos za odgovarajućeg igrača.

Primjer ulaza i izlaza:


Unesite pogotke za Sabita: T9T8D2XD4XOIX.
Unesite pogotke za Fadilu: T8T8T8D9XXD7T3I.
Sabit je ostvario 138 poena, Fadila je ostvarila 163 poena. Pobjednik je Fadila, kojoj je ostalo još 138 poena do pobjede.
Primjer ulaza i izlaza:


Unesite pogotke za Sabita: IIIIIIXXO.
Unesite pogotke za Fadilu: T7D8S9S7S2S1OOX.
Sabit je premašio potrebni broj poena, Fadila je ostvarila 106 poena. Pobjednik je Fadila, kojoj je ostalo još 195 poena do pobjede. 
Primjer ulaza i izlaza:


Unesite pogotke za Sabita: IIIIIIXXS5.
Unesite pogotke za Fadilu: S7XOOIIIII.
Oba igrača su premašila potrebni broj poena, rezultat je neriješen.
*/

// MOJ KOD:

#include <stdio.h>

int main() {
	
    int error=0;
    int sabit=0,fadila=0;
    int arrows=0;
    int br, poljemult;
    char polje;

//SABIT

do{
    if(error != 0){
        printf("Neispravni ulazni podaci.\n");
    }
    error = 0;
    sabit = 0;
    arrows = 0;
    printf("Unesite pogotke za Sabita: ");
    do{
    scanf(" %c", &polje);
    if(polje == 'S' || polje == 'D' || polje == 'T' || polje == 'X' || polje == 'O' || polje == 'I' || polje == '.'){
        if(polje == 'S' || polje == 'D' || polje == 'T'){
            scanf("%d", &br);
            if(br<1 || br>10){
                error++;
                continue;
            }
            if(polje == 'S'){
                poljemult = 1;
            }
            if(polje == 'D'){
                poljemult = 2;
            }
            if(polje == 'T'){
                poljemult = 3;
            }
            sabit += br * poljemult;
        }else{
            if(polje == 'O'){
                sabit += 25;
            }
            if(polje == 'I'){
                sabit += 50;
            }
        }
        if(polje != '.'){
            arrows++;
        }
    }else{
        error++;
        continue;
    }
}while(polje != '.');
    if(arrows<9){
        error++;
    }
}while(error!=0);

//FADILA (SVE ISTO SAMO NJENI SE BODOVI MJENJAJU)

error = 0; //idemo opet 
arrows = 0;

do{
    if(error != 0){
        printf("Neispravni ulazni podaci.\n");
    }
    error = 0;
    fadila = 0;
    arrows = 0;
    printf("Unesite pogotke za Fadilu: ");
    do{
    scanf(" %c", &polje);
    if(polje == 'S' || polje == 'D' || polje == 'T' || polje == 'X' || polje == 'O' || polje == 'I' || polje == '.'){
        if(polje == 'S' || polje == 'D' || polje == 'T'){
            scanf("%d", &br);
            if(br<1 || br>10){
                error++;
                continue;
            }
            if(polje == 'S'){
                poljemult = 1;
            }
            if(polje == 'D'){
                poljemult = 2;
            }
            if(polje == 'T'){
                poljemult = 3;
            }
            fadila += br * poljemult;
        }else{
            if(polje == 'O'){
                fadila += 25;
            }
            if(polje == 'I'){
                fadila += 50;
            }
        }
        if(polje != '.'){
            arrows++;
        }
    }else{
        error++;
        continue;
    }
}while(polje != '.');
    if(arrows<9){
        error++;
    }
}while(error!=0);

if(sabit>301 && fadila>301){
    printf("Oba igraca su premasila potrebni broj poena, rezultat je nerijesen. ");
    return 0;
}
if(sabit>301){
    printf("Sabit je premasio potrebni broj poena, Fadila je ostvarila %d poena. Pobjednik je Fadila, kojoj je ostalo jos %d poena do pobjede.", fadila, 301-fadila);
    return 0;
}
if(fadila>301){
    printf("Fadila je premasila potrebni broj poena, Sabit je ostvario %d poena. Pobjednik je Sabit, kojem je ostalo jos %d poena do pobjede.",sabit, 301-sabit);
    return 0;
}

printf("Sabit je ostvario %d poena, Fadila je ostvarila %d poena. ", sabit, fadila);

if(sabit==fadila){
    printf("Rezultat je nerijesen. ");
}

if(sabit>fadila){
    printf("Pobjednik je Sabit, kojem je ostalo jos %d poena do pobjede. ",301-sabit);
}
if(fadila>sabit){
    printf("Pobjednik je Fadila, kojoj je ostalo jos %d poena do pobjede. ",301-fadila);
}

	return 0;
}
