/*
Zadatak
Napisati program koji učitava matricu cijelih brojeva dimenzija 10x10 te pronalazi najmanji element na glavnoj dijagonali. Primjere ulaza i izlaza možete vidjeti kroz testove.

Napomena: Zadatak obavezno riješiti koristeći matricu.
*/

// MOJ KOD:

#include <stdio.h>

int main() {
	
    float A[10][10], min;
    int i,j;

    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            scanf("%f", &A[i][j]);
        }

    }

    min = A[0][0];

    for(i=1; i<10; i++){
        if(A[i][i]<min){
            min=A[i][i];
        }
    }

    printf("%g",min);

	return 0;
}
