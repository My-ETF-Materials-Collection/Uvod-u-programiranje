/*
Napisati program koji računa sumu kvadratu prirodnih brojeva manjih ili jednakih broja n koji se unosi sa tastature. Ukoliko korisnik unese broj koji nije prirodan,  program treba ispisati grešku "Broj nije prirodan!" i završiti sa radom. Ukoliko uopšte ne bude unesen broj (nego npr. slovo ili riječ), program treba ispisati poruku "Nije unesen broj!" i završiti sa radom. Primjeri izlaza:

Unesite n: 143
Suma je: 984984

Unesite n: or
Nije unesen broj!

Unesite n: 17
Suma je 1785
*/

// MOJ KOD:

#include <stdio.h>

int main(){

int n;
printf("Unesite n: ");

if(scanf("%d",&n)==0){
	printf("Nije unesen broj!");
}else if(n<0){
	printf("Broj nije prirodan!");
}else{
	int suma,i;
	while(i<=n){
	suma+= i*i;
	i++;
}
	printf("Suma je: %d",suma);
}

return 0;
}