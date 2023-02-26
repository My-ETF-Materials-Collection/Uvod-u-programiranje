/*
Zadatak
Date su funkcije double f(double x) i double g(double x). Potrebno je napisati funkciju sa prototipom:

double presjek(double A, double B, int* status)
Funkcija treba vratiti tačku x na intervalu [A,B] u kojoj se funkcije f(x) i g(x) sijeku, tj. daju istu vrijednost (pri čemu za provjeru jednakosti koristimo vrijednost ε=0.0001), te na adresu na koju pokazuje pokazivač status upisati vrijednost 0 (postaviti status na nulu). Ako postoji više takvih tačaka na ovom intervalu, funkcija treba vratiti jednu od njih prema algoritmu opisanom ispod. Ako se funkcije ne sijeku niti u jednoj tačci, treba postaviti status na 1 i vratiti 0. Ako su funkcije identične (sijeku se u svim tačkama), treba postaviti status 2 i vratiti 0.

Problem određivanja tačaka u kojoj se funkcije f(x) i g(x) sijeku je identičan problemu pronalaska nula funkcije h(x)=f(x)-g(x), pa se mogu koristiti iste metode. Da biste dobili iste rezultate kao u testovima, u ovom zadatku trebate koristiti metodu polovljenja intervala koja se može opisati na sljedeći način:

Najprije treba podijeliti interval [A,B] na dva jednaka podintervala [A,H] i [H,B] pri čemu je H=(A+B)/2. Ako je jedna od tačaka A, H ili B presjek funkcija, treba vratiti tu tačku. Ako se funkcije sijeku u sve tri tačke, trebamo smatrati da su funkcije identične. U suprotnom, traženje presjeka se nastavlja na jednom od ova dva podintervala na kojem funkcija h(x) mijenja znak. Npr. ako je h(A) pozitivno, a h(H) negativno, kažemo da funkcija h(x) mijenja znak na intervalu [A,H]. Ako funkcija mijenja znak na oba podintervala, nastavićemo traženje na podintervalu [A,H]. Ako ne mijenja niti na jednom, tražićemo presjek na oba podintervala sve dok širina intervala ne bude manja od δ=0.01, nakon čega smatramo da se funkcije ne sijeku.

Pored navedene funkcije, vaš program treba sadržavati i funkcije f, g i main, kako bi se mogao kompajlirati i kako biste se uvjerili da radi ispravno. No, prilikom testiranja vaših rješenja, ove funkcije će biti zamijenjene testnim funkcijama.
*/

// MOJ KOD:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 0.0001
#define delta 0.01

double presjek(double A, double B, int* status);
double f(double x);
double g(double x);

int main() {
    int status=-1;
	printf("%g %d\n",presjek(-3,3,&status),status);//vrijednosti iz test1
	return 0;
}

double f(double x){
    return 2*x+2;//test 1 uvrstena fja f
}

double g(double x){
    return 4*x-2;//test 1 uvrstena fja g
}

double presjek(double A, double B, int* status){
    double H, dg=A, gg=B;//dg - donja granica fje, gg - gornja

    H=(dg+gg)/2;

    if(fabs(f(B)-g(B))<eps && fabs(f(A)-g(A))<eps && fabs(f(H)-g(H))<eps){
        *status=2;//ako su identicne 
        return 0;
    }else if(fabs(f(A)-g(A))<eps){//ako je presjecna tacka A
        *status=0;
        return A;
    }else if(fabs(f(B)-g(B))<eps){//ako je presjecna tacka B
        *status=0;
        return B;
    }

    while(1){
        H=(dg+gg)/2.;
        if(fabs(f(H)-g(H))<eps){//ako je presjecna tacka H
            *status=0;
            return H;
        }
        if(((f(dg)-g(dg))*(f(H)-g(H)))>0 && ((f(gg)-g(gg))*(f(H)-g(H)))<0){
            dg=H;
        }else if(((f(dg)-g(dg))*(f(H)-g(H)))<0){
            gg=H;
        }else if(((f(dg)-g(dg))*(f(H)-g(H)))>0 && ((f(gg)-g(gg))*(f(H)-g(H)))>0){
            gg=H;
            if(gg-dg<delta || fabs((gg-dg)-delta)<eps){
                break;
            }
        }
    }

    *status=1;//ako se ne sijeku ni u jednoj tacki
    return 0;

}