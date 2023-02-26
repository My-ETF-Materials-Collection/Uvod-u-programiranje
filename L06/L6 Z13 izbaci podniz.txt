#include <stdio.h>

int izbaci_podniz(int *p1, int *p2, const int *q1, const int *q2){
    
    int brojElemenata = q2-q1;//br Elemenata sto se treba izbaciti
    int brPodnizova = 0;
    int *a = p1;//pocetak glavnog niza
    const int *b = q1;//pocetak podniza
    int *zaIzbaciti;

    while(a<p2){//sve dok ne dodjes na kraj glavnog niza

        if(*a==*q1){//ako naletis na pocetak podniza
            
            zaIzbaciti = a;//za pocetak se treba izbaciti prva vrijednost

            while(b<q2){//idemo kroz podniz
                if(*a==*b){//ako naletimo na pocetak podniza 
                    a++; b++;//pomjeri i a i b na sljedeci clan podniza i niza
                }else if(*a!=*b && q2-b!=0){//ako nisu isti a i b ali nsmo dosli do kraja podniza 
                    b = q1; a--; break;//stavi da je b pocetak podniza, a a smanji 
                }
            }

            if(q2-b==0){//ako jesi dosao do kraja podniza 
                brPodnizova++;//reci da imamo zasad bar jedan podniz u nizu
                while(a<p2){//sve dok ne dodjemo do kraja glavnog
                    *zaIzbaciti=*a;//svi ti se moraju izbaciti 
                    zaIzbaciti++;
                    a++;
                }
                a=p1-1;
                b=q1;
                p2-=brojElemenata;//smanji glavni za broj elemenata podniza
            }
        }
        a++;
    }
    return brPodnizova*brojElemenata;//ako ih je bilo vise pomnozi sa brPodnizova i brojem elemenata podniza
}

int main() {

	return 0;
}
