/*
Zadatak
U predavanjima je data funkcija

const char* podstring (const char *str, const char *trazi)
koja traži tekst trazi unutar proslijeđenog stringa str. Funkcija treba da vrati pokazivač na poziciju u string str gdje se nalazi podstring. Ukoliko ima više takvih stringova funkcija treba vratiti indeks koji predstavlja početak prvog stringa, a ko se podstring ne nalazi u stringu treba vratiti nul-pokazivač.

Napisati novu funkciju pronadji_posljednji koja slično funkciji podstring pronalazi tekst unutar stringa ali ovaj put vraća indeks posljednjeg pojavljivanja. Primjeri:

const char *n = "Danas je divan dan!";
printf ("%d", pronadji_posljednji(n, "divan")); 	//9
printf ("%d", pronadji_posljednji(n, "Divan")); 	//-1 (nema)
printf ("%d", pronadji_posljednji(n, "Danas")); 	//0
printf ("%d", pronadji_posljednji(n, "an"));    	//16
printf ("%d", pronadji_posljednji(n, "an!"));   	//16
printf ("%d", pronadji_posljednji("abc cde abc", "abc")); 	//8
Napomena: Pri rješavanju ovog zadatka zabranjeno je korištenje funkcija iz biblioteke string.h. Nije dozvoljeno kreirati pomoćne stringove u funkciji ili globalno.
*/

// MOJ KOD:

#include <stdio.h>

int main() {

    int n,i=0,p,q,j,k;
    do{
        printf("Unesite broj matrica: ");
        scanf("%d",&n);
        if(n<=0 || n>10){
            printf("\nBroj matrica mora biti u opsegu [1,10]\n");
        }
    }while(n<=0 || n>10);
    
    do{
            printf("Unesite dimenzije matrice (p q): ");
            scanf("%d %d",&p,&q);
            if(p>5 || q>5 || p<=0 || q<=0){
                printf("p i q moraju biti u opsegu [1,5]\n");
            }
}while(p>5 || q>5 || p<=0 || q<=0);

    int maxindex=0,maxsuma=0,suma=0,matrica[10][10][10];

    for(i=0;i<n;i++){
        printf("\nMatrica br. %d\n",i+1);
        for(j=0;j<p;j++){
            printf("%d. red: ",j+1);
            for(k=0;k<q;k++){
                scanf("%d ",&matrica[i][j][k]);
            }
        }
    }

    printf("\nSume za sve matrice, format \"matrica: suma\":\n");

    for(i=0;i<n;i++){
        suma=0;
        for(j=0;j<p;j++){
            for(k=0;k<q;k++){
                suma+=matrica[i][j][k];
            }
        }
        
        if(i!=n-1){
           printf("%d: %d, ",i+1,suma); 
        }else{
           printf("%d: %d ",i+1,suma); 
        }
        
        if(suma>maxsuma){
            maxsuma=suma;
            maxindex=i;
        }

    }
    printf("\nMatrica s najvecom sumom:\n");
    for(j=0;j<p;j++){
        for(k=0;k<q;k++){
                printf("    %d",matrica[maxindex][j][k]);
        }
        printf("\n");
    }
   
	return 0;
}
