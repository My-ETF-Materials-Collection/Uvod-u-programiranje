/*
Zadatak
Napisati program koji od korisnika traži unos broja n i rednog broja cifre c. Broj n može biti u (isključivom) intervalu (-1000000, 1000000) (ukoliko to nije slučaj program ispisuje Neispravan unos! i završava sa radom), dok redni broj cifre može biti od 1 do broja cifara unesenog broja n (ukoliko to nije slučaj program ispisuje Neispravna cifra! i završava sa radom).

Redni broj cifre se određuje slijeva nadesno odnosno ako je broj n = 17482, a redni broj cifre c = 2, tada se 2 odnosi na drugu cifru slijeva odnosno cifru 7.

Program treba da izdvoji cifru sa rednim brojem c iz broja n, te je ispiše i izračuna njen kvadrat.

Primjer

Unesite broj: 2451
Koju cifru zelite kvadrirati: 2
Izdvojena cifra je 4, a njen kvadrat je 16
Napomena: Zabranjeno korištenje petlji i nizova, te se preporučuje da se zadatak uradi bez math.h biblioteke.
*/

// MOJ KOD:
#include <stdio.h>

int main() {
    int n,x;
	printf("Unesite broj: ");
	scanf("%d",&n);
    x=n;
    if(n<=-1000000 || n>=1000000){
        printf("Neispravan unos!");
    }else{
        int brojac=0;
        if(n<0){
            n=n*(-1);
        }
        cifra:
        if(n>0){
            n=n/10;
            brojac++;
            goto cifra;
        }
        
        int r;
        printf("Koju cifru zelite kvadrirati: ");
        scanf("%d",&r);
        if(r<=0 || r>brojac){
            printf("Neispravna cifra!");
        }else{
            if(brojac==2){
                if(r==1){
                    x=x/10;
                }else if(r==2){
                    x=x%10;
                }
            }else if(brojac==3){
                if(r==1){
                    x=x/100;
                }else if(r==2){
                    x=(x%100)/10;
                }else if(r==3){
                    x=x%10;
                }
            }else if(brojac==4){
                if(r==1){
                    x=x/1000;
                }else if(r==2){
                    x=(x%1000)/100;
                }else if(r==3){
                    x=(x%100)/10;
                }else if(r==4){
                    x=x%10;
                }
            }else if(brojac==5){                if(r==1){
                    x=x/10000;
                }else if(r==2){
                    x=(x%10000)/1000;
                }else if(r==3){
                    x=(x%1000)/100;
                }else if(r==4){
                    x=(x%100)/10;
                }else if(r==5){
                    x=x%10;
                }
            }else if(brojac==6){
                if(r==1){
                    x=x/100000;
                }else if(r==2){
                    x=(x%100000)/10000;
                }else if(r==3){
                    x=(x%10000)/1000;
                }else if(r==4){
                    x=(x%1000)/100;
                }else if(r==5){
                    x=(x%100)/10;
                }else if(r==6){
                    x=x%10;
                }
            
            }
            int kvadrat;

            kvadrat=x*x;
            printf("Izdvojena cifra je %d, a njen kvadrat je %d",x,kvadrat);
            }
    } 
    return 0;
}


