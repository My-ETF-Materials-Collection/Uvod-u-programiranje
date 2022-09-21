#include <stdio.h>
#include <math.h> 

void zaokruzi1(double niz[], int n){
	int i;
	for (i=0; i<n; i++){
		niz[i]=(round(niz[i]*10))/10;
	}
}

void preslozi(double niz[], int n, int k){

    zaokruzi1(niz, n);
    double *p1 = niz, *p2 = niz, temp, lastChange=1000;
    unsigned int suma = 0;
    
    while(p2<niz+n){
        suma=0;
        if(*p2<0){
            temp = *p2*(-1)*10;
        }else temp = *p2 * 10;
    
        while(temp>=1){
            suma+=(int)temp%10;
            temp/=10;
        }

        if(suma>=k){
            
            p1 = p2;
            temp = *p2;

            while(p1>niz){
                if(*(p1-1)==lastChange) break;
                *p1=*(p1-1);
                p1--;
            }

            lastChange = temp;
            *p1 = temp;

        }
        p2++;
    }
}
 
int main() {
    int i, vel, k;
    double niz[100];
    
    printf("Unesite broj elemenata niza: ");
    scanf("%d", &vel);
    printf("Unesite clanove niza: ");
    for (i=0; i<vel; i++)
        scanf("%lf", &niz[i]);
    printf("Unesite broj k: ");
    scanf("%d", &k);
  
    preslozi(niz, vel, k);
  
    printf("Nakon poziva funkcije preslozi niz glasi:\n");
    for (i=0; i<vel; i++)
        printf("%g ", niz[i]);
	return 0;
}
