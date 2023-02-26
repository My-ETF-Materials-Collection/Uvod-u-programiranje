#include <stdio.h>
#include <math.h>

double sinus(double x,long int n);
long int faktorijel(int n);

int main() {
    long int n;
    double x;
    double razlika, procenat;
	printf("Unesite x: ");
    scanf("%lf",&x);
    printf("\nUnesite n: ");
    scanf("%ld",&n);

    printf("\nsin(x)=%g",sin(x));
    printf("\nsinus(x)=%g",sinus(x,n));

    razlika=fabs(sinus(x,n)-sin(x));
    procenat=razlika/100;

    printf("\nRazlika: %lf (%.2lf%%).",razlika,procenat);

	return 0;
}

long int faktorijel(int n){
    int i;
    long int fakt=1;
    for(i=1;i<=n;i++){
        fakt*=(i);
    }
    return fakt;
}

double sinus(double x,long int n){
    long double suma=0;
    int i;
    for(i=1;i<=n;i++){
        suma+=pow(-1,i-1)*((pow(x,2*i-1))/(faktorijel(2*i-1)));
    }
    return suma;
}
