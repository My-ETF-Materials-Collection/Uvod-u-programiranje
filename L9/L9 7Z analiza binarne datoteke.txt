#include <stdio.h>

int analiza(){

    FILE* ulaz = fopen("brojevi.dat", "rb");//rb jer je citanje u binarnom modu
    if(!ulaz){
        printf("Datoteka brojevi.dat ne postoji");
        return 1;
    }

    unsigned short niz[100000];//mora ici short da bi radilo, zbog raspona podataka 
    unsigned int histogram[65536] = {0};

    int brojUcitanih = fread(niz, 2, 100000, ulaz);
    int i, max = 0;
    
    for(i = 0; i<brojUcitanih; i++){
        histogram[niz[i]]++;
    }

    for(i=1; i<65536; i++){
        if(histogram[i]>histogram[max]) max = i;
    }

    int suma = 0;
    //posto trazim od onog koji se max pojavljuje i krece od max+1 pa do kraja
    for(i= max+1; i<65536; i++){
        suma+=histogram[i];
    }

    fclose(ulaz);

    return suma;

}

int main() {

    printf("%d", analiza());
	return 0;
}
