/*
Zadatak
Napisati funkciju sekunde2hms koja pretvara sekunde u sate, minute i sekunde. Prototip funkcije zaključite sami na osnovu sljedećeg kôda:

    
int H, M, S;
int s = 3665;
sekunde2hms(s, &H, &M, &S);
printf ("%02d:%02d:%02d", H, M, S); //ispisuje: „01:01:05“
*/

// MOJ KOD:

#include <stdio.h>

void sekunde2hms(int s, int *H, int *M, int *S);

int main() {
    int H,M,S;
    int s= 3665;
    sekunde2hms(s, &H, &M, &S);
	printf ("%02d:%02d:%02d", H, M, S);
	return 0;
}

void sekunde2hms(int s, int *H, int *M, int *S){
    int ostatak;
    *H=s/3600;
    ostatak=s-(*H*3600);
    *M = ostatak/60;

	ostatak -= (*M * 60);
	*S = ostatak;
}
