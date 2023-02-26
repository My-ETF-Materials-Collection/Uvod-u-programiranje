#include <stdio.h>
#include <string.h>
#include <limits.h>

struct Datum { int dan, mjesec, godina; };
struct Predmet {
    int id;
    char naziv[100];
    double ects;
};
struct Ocjena {
    char imeprezime[100];
    int ocjena;
    struct Predmet predmet;
    struct Datum datum;
};

int brCifara(struct Datum d){

    unsigned int histogram[10]={0};
    int dan = d.dan, m = d.mjesec, g = d.godina;

    while(dan!=0){
        histogram[dan%10]++;
        dan/=10;
    }
    while(m!=0){
        histogram[m%10]++;
        m/=10;
    }
    while(g!=0){
        histogram[g%10]++;
        g/=10;
    }

    int i, br=0;
    for(i=0; i<10; i++){
        if(histogram[i]>0) br++;
    }

    return br;

}

int cifre_u_datumu(struct Ocjena *o, int vel){
    int i,j,k;
    for(i=0; i<vel; i++){
        struct Ocjena temp = *(o+i);
        int brisi = 0;
        double trenutniECTS = 0;
        for(j=i; j<vel; j++){
            if(!strcmp((o+i)->imeprezime, (o+j)->imeprezime) && (o+j)->ocjena>=6) trenutniECTS+=(o+j)->predmet.ects;
        }
        if(trenutniECTS>=30){
            int minCifara = INT_MAX;
            for(j=0; j<vel; j++){
                if(!strcmp((o+i)->imeprezime, (o+j)->imeprezime) && (o+j)->ocjena>=6)
                    if(brCifara((o+j)->datum)<minCifara) minCifara=brCifara((o+j)->datum);
            }
            for(j=0; j<vel; j++){
                if(!strcmp(temp.imeprezime, (o+j)->imeprezime) && brCifara((o+j)->datum)==minCifara && (o+j)->ocjena>=6){
                    for(k=j; k<vel-1; k++){
                        *(o+k)=*(o+k+1);
                    }
                    vel--;
                    if(j==0) brisi=1;
                    j--;
                }
            }
        }
        if(brisi) i--;
    }
    return vel;
}

int main() {
	return 0;
}
