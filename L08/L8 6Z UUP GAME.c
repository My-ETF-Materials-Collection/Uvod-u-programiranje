/*
Zadatak
Date su strukture:

	struct Tacka {			struct Kruznica {
		double x,y;			    struct Tacka centar;
    }						    double poluprecnik;
                            }
Napisati funkciju sa prototipom:

struct Kruznica obuhvat(struct Tacka* niz, int vel)
Funkcija prima niz tačaka (barem jedna tačka se nalazi u nizu), a vraća najmanju kružnicu koja obuhvata sve tačke u nizu. Smatra se da kružnica "obuhvata" tačku ako se tačka nalazi unutar kružnice ili na kružnici.
*/

// MOJ KOD:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define infinity 1e18

/*
inspiracija za rjesenje: https://www.nayuki.io/res/smallest-enclosing-circle/computational-geometry-lecture-6.pdf
*/

struct Tacka{
    double x,y;
};

struct Kruznica{
    struct Tacka centar;
    double poluprecnik;
};

void ispis_kruznice(struct Kruznica c);
int ciniKrug(struct Kruznica c, struct Tacka p[], int vel);
struct Kruznica udaljenostIzmedjuDvijeTacke(struct Tacka a, struct Tacka b);
struct Kruznica obuhvat(struct Tacka *niz, int vel);
double udaljenost(struct Tacka a, struct Tacka b);

int main(){
    return 0;
}

struct Kruznica obuhvat(struct Tacka* niz, int vel){
    //kada nema tacke nijedne
    if(vel==0){
        struct Kruznica temp1 ={{0,0},0};
        return temp1;
    }
    //kada ima jedna samo tacka 
    if(vel==1){
        struct Kruznica temp2 ={niz[0],0};
        return temp2;
    }
    struct Kruznica pocetak = {{0, 0}, infinity};
    int i,j,k;
    for(i=0;i<vel;i++){
        for(j=i+1;j<vel;j++){
            struct Kruznica temp = udaljenostIzmedjuDvijeTacke(niz[i],niz[j]);

            if(temp.poluprecnik<pocetak.poluprecnik && ciniKrug(temp,niz,vel)) pocetak=temp;
        }
    }

return pocetak;

}

double udaljenost(struct Tacka a, struct Tacka b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

struct Kruznica udaljenostIzmedjuDvijeTacke(struct Tacka a, struct Tacka b){
    struct Tacka c = {(a.x+b.x)/2.0,(a.y+b.y)/2.0};//medijan koordinate AB
    struct Kruznica temp = {c,udaljenost(a,b)/2.0};
    return temp;
}

int unutarKruga(struct Kruznica c, struct Tacka x){
    if(udaljenost(c.centar,x)<=c.poluprecnik) return 1; else return 0;
}

int ciniKrug(struct Kruznica c, struct Tacka n[], int vel){
    int i;
    for(i=0;i<vel;i++){
        if(!unutarKruga(c,n[i])) return 0;
    }
    return 1;
}

void ispis_kruznice(struct Kruznica c){
    printf("(%.2f,%.2f) %.2f",c.centar.x, c.centar.y, c.poluprecnik);
}

