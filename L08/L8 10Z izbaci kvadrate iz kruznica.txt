#include <stdio.h>
#include <math.h>
#define EPS 0.00001

struct Tacka{
    double x,y;
};

struct Kruznica{
    struct Tacka centar;
    double poluprecnik;
};

struct Kvadrat{
    struct Tacka dl;//donji lijevi ugao
    double stranica;
};

int daLiKvadratPripadaKruznici(struct Tacka a, struct Tacka b, struct Tacka c, struct Tacka d, struct Kruznica kr){
    if(pow(kr.centar.x-a.x,2)+pow(kr.centar.y-a.y,2)>pow(kr.poluprecnik,2)+EPS) return 0;
    if(pow(kr.centar.x-b.x,2)+pow(kr.centar.y-b.y,2)>pow(kr.poluprecnik,2)+EPS) return 0;
    if(pow(kr.centar.x-c.x,2)+pow(kr.centar.y-c.y,2)>pow(kr.poluprecnik,2)+EPS) return 0;
    if(pow(kr.centar.x-d.x,2)+pow(kr.centar.y-d.y,2)>pow(kr.poluprecnik,2)+EPS) return 0;
    return 1;
}

int izbaci_visak(struct Kruznica* kr, int velkr, struct Kvadrat* kv, int velkv){
    struct Tacka A,B,C,D;//A-dl, B-gl, C-gd, D-dd (g-gore, d-dolje, d-desno, l-lijevo)
    int ispunjenUslovZaItiKvadrat = 0;
    /*
 ^ y   
 |   B---------C
 |   |             |
 |   |             |
 |   |             |
 |   A---------D
-|------------------>x
    */
    for(int i=0; i<velkv; i++){
        
        A=kv[i].dl;
        B.x=kv[i].dl.x;
        B.y=kv[i].dl.y+kv[i].stranica;
        C.x=kv[i].dl.x+kv[i].stranica;
        C.y=kv[i].dl.y+kv[i].stranica;
        D.x=kv[i].dl.x+kv[i].stranica;
        D.y=kv[i].dl.y;

        ispunjenUslovZaItiKvadrat=0;

        for(int j=0; j<velkr; j++){
            
            int ispunjenUslovZaJtuKruznicu=daLiKvadratPripadaKruznici(A,B,C,D,kr[j]);
            if(ispunjenUslovZaJtuKruznicu){
                ispunjenUslovZaItiKvadrat=1;
                break;
            }
        
        }

        if(!ispunjenUslovZaItiKvadrat){
            for(int k=i; k<velkv-1;k++){
                kv[k]=kv[k+1];
            }
            velkv--;
            i--;
        }

    }

    return velkv;
}

int main() {

	return 0;
}
