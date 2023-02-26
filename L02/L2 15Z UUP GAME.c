/*
Zadatak
Napisati program koji iscrtava Descartesov koordinatni sistem (u nastavku KS) i tačku na njemu. Korisnik unosi n, dimeziju KS-a, a program iscrtava 2n × 4n pôlja KS-a, tj. svaki kvadrant KS-a ima dimenziju n × 2n (ovo je odabrano zbog odnosa visine i širine znakova na konzoli).

U centru KS-a je iscrtan znak „+“, na „krajevima“ x-ose su znakovi „<“ i „>“, dok su na „krajevima“ y-ose znakovi „^“ i „v“ (ovo je slovo „v“). Nakon unosa n, korisnik unosi i koordinate tačke na kojoj će program ispisati znak „x“. Ukoliko su koordinate tačke van „opsega“ KS-a, program treba ispisati grešku i završiti s radom. Unos parametara i iscrtavanje ponavljati sve dok korisnik ne unese broj -1 kao dimenziju KS-a (n).

Primjeri ulaza i izlaza:

Unesite dimenziju: 4
Unesite (x y): -3 3
         ^
         |
      x  |
         |
         |
<--------+-------->
         |
         |
         |
         |
         v

Unesite dimenziju: 4
Unesite (x y): 8 4
         ^
         |       x
         |
         |
         |
<--------+-------->
         |
         |
         |
         |
         v

Unesite dimenziju: 4
Unesite (x y): 0 2
         ^
         |
         |
         x
         |
<--------+-------->
         |
         |
         |
         |
         v

Unesite dimenziju: 4
Unesite (x y): 0 0
         ^
         |
         |
         |
         |
<--------x-------->
         |
         |
         |
         |
         v

Unesite dimenziju: -1
Zavrsio!
Primjer 2:

Unesite dimenziju: 4
Unesite (x y): 8 5
Koordinate tacke izvan opsega!
*/

// MOJ KOD:

#include <stdio.h>

int main() {
    int n, i, j, x, y;

    do{
	printf("Unesite dimenziju: ");
    scanf("%d",&n);

    if(n==-1){
       printf("Zavrsio!"); 
       return 0;
    }

    printf("Unesite (x y): ");
    scanf("%d %d", &x, &y);
    
    if(x>2*n || y>n){
        printf("Koordinate tacke izvan opsega!");
        return 0;
    }

     for(i=0;i<2*n+3;i++){
        for(j=0;j<4*n+3;j++){
            if(i==0 && j == 2*n+1){
                printf("^");
            }
            else if(i!=n+1 && i!=0 && i!=2*n+2 && j== 2*n+1){
              
                if (x==0 && i==n+1-y) {
                    printf("x");    
                }
                else {
                    printf("|");
                }
            
              
               
            }else if(i==n+1){
                if(j==0){
                    printf("<");
                }else if(j!=4*n+2 && j!=2*n+1){
                    printf("-");
                }else if(j==2*n+1){
                    if(x==0 && y==0){
                    printf("x");
                    }else{
                    printf("+");
                }}
                else if(j==4*n+2){
                    printf(">");
                }}
                
            else if(i==2*n+2 && j==2*n+1){
                printf("v");
            }

            else{

                if(i==n+1-y && j==2*n+1+x){
                    printf("x");
                }else{
                    printf(" ");
                }

            }
        }
         
        printf("\n");
    }
    }while(n!=-1);

	return 0;
}
