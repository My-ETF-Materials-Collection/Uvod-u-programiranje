#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 0.0001

struct Tacka {
    int x,y;
};

struct Cetverougao {
    struct Tacka A,B,C,D;
};

struct Tacka unos_tacke() {
    struct Tacka t;
    scanf("%d %d", &t.x, &t.y);
    return t;
}

struct Cetverougao unos_cetverougla() {
    struct Cetverougao c;
    c.A = unos_tacke();
    c.B = unos_tacke();
    c.C = unos_tacke();
    c.D = unos_tacke();
    return c;
}

double udaljenost(struct Tacka A, struct Tacka B){
    return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));
}

int pravougaonik(struct Cetverougao k){
    float a, b, c, d, d1, d2;
    a = udaljenost(k.A, k.B);
    b = udaljenost(k.B, k.C);
    c = udaljenost(k.C, k.D);
    d = udaljenost(k.D, k.A);
    d1 = udaljenost(k.A, k.C);
    d2 = udaljenost(k.B, k.D);
    if(fabs(a-c)<EPS && fabs(b-d)<EPS && fabs(d1-d2)<EPS) return 1; 
    return 0;
}

int kvadrat(struct Cetverougao k){
    float a, b, c, d, d1, d2;
    a = udaljenost(k.A, k.B);
    b = udaljenost(k.B, k.C);
    c = udaljenost(k.C, k.D);
    d = udaljenost(k.D, k.A);
    d1 = udaljenost(k.A, k.C);
    d2 = udaljenost(k.B, k.D);
    if(fabs(a-d)<EPS && fabs(d1-d2)<EPS) return 1; 
    if(fabs(a-d1)<EPS && fabs(d-b)<EPS) return 1;
    if(fabs(d1-d)<EPS && fabs(a-c)<EPS) return 1;
    return 0;
}

double DajPovrsinu(struct Tacka A, struct Tacka B, struct Tacka C){
    return (abs(A.x*(B.y-C.y)+B.x*(C.y-A.y)+C.x*(A.y-B.y)))/2.;
}

int tacka_u_cetverouglu(struct Tacka t, struct Cetverougao c){
    struct Tacka tacke[4], temp, gore1, gore2, dolje1, dolje2;
    tacke[0]=c.A, tacke[1]=c.B, tacke[2]=c.C, tacke[3]=c.D;
    int i,j;
    for(i=0; i<3; i++){
        for(j=i; j<4; j++){
            if(tacke[j].x>tacke[i].x){
                temp=tacke[j];
                tacke[j]=tacke[i];
                tacke[i]=temp;
            }
        }
    }
    if(tacke[0].y>tacke[1].y){
        gore1=tacke[0];
        dolje1=tacke[1];
    }else{
        gore1=tacke[1];
        dolje1=tacke[0];
    }
    if(tacke[2].y>tacke[3].y){
        gore2=tacke[2];
        dolje2=tacke[3];
    }else{
        gore2=tacke[3];
        dolje2=tacke[2];
    }
    double P = (double)DajPovrsinu(gore1, gore2, dolje1)+DajPovrsinu(gore2, dolje1, dolje2);
    double P1 = DajPovrsinu(t, gore1, dolje1);
    double P2 = DajPovrsinu(t, dolje1, dolje2);
    double P3 = DajPovrsinu(t, dolje2, gore2);
    double P4 = DajPovrsinu(t, gore2, gore1);
    if(P1==0 || P2==0 || P3==0 || P4==0) return 0;
    if((P1+P2+P3+P4)==P) return 1; 
   // if(t.y<c.D.y && t.y>c.A.y && t.x<c.C.x && t.x>c.A.x) return 1;
    return 0;
}

int filtriraj_tacke(struct Tacka *t, int vel, struct Cetverougao c){
    int i,j;
    for(i=0; i<vel; i++){
        if(tacka_u_cetverouglu(t[i], c)==0){
            for(j=i; j<vel-1; j++){
                t[j]=t[j+1];
            }
            vel--;
            i--;
        }
    }
    return vel;
}

void sortiraj_tacke(struct Tacka *t, int vel){
    int i, j;
    struct Tacka temp, nula;
    nula.x = 0, nula.y = 0;
    for(i=0; i<vel; i++){
        for(j=i; j<vel; j++){
            if(udaljenost(t[j],nula)<udaljenost(t[i],nula)){
                temp = t[i];
                t[i] = t[j];
                t[j] = temp; 
            }
        }
    }
}

int main(){
struct Cetverougao c;
c.A.x=1;
c.A.y=1;
c.B.x=1;
c.B.y=2;
c.C.x=2;
c.C.y=1;
c.D.x=2;
c.D.y=2;
double x = udaljenost(c.A, c.B);
double y = udaljenost(c.C, c.D);
double z = udaljenost(c.B, c.C);
double p = udaljenost(c.D, c.A);
double q = udaljenost(c.A, c.C);
double r = udaljenost(c.B, c.D);
printf("%lf %lf %lf %lf %lf %lf", x, y, z, p, q, r);
	return 0;
}
