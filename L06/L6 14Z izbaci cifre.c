#include <stdio.h>
#include <stdlib.h>

int izbaci_cifre(int* niz, int n, int* cifre, int vel){
    
    for(int i=0; i<vel; i++){
        if(*(cifre+i)<0 || *(cifre+i)>9) return 0;
        for(int j=i+1; j<vel; j++) if(*(cifre+i)==*(cifre+j)) return 0;
    }

    int temp, desetice, suma;

    for(int i=0; i<n; i++){
        for(int j=0; j<vel; j++){
            desetice=1;
            temp=abs(*(niz+i));
            suma=0;
            while(temp>0){
                if(*(cifre+j)!=temp%10){
                    suma+=(temp%10)*desetice;
                    desetice*=10;
                }
                temp/=10;
            }
            if(*(niz+i)<0) suma*=(-1);
            *(niz+i)=suma;
        }
    }

    return 1;
}

int main() {
	return 0;
}
