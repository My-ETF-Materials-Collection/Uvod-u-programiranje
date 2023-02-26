/*
Zadatak
Napisati program koji računa sumu svih prostih brojeva do broja n (uključivo). Pored toga, program treba da ispisuje te (proste) brojeve, svaki u novom redu. Zabranjeno je korištenje biblioteka osim „stdio.h“ biblioteke. Također je zabranjeno koristiti pomoćne funkcije (odnosno, jedina funkcija koja smije biti u programu je main funkcija). Primjer ispisa:

        
Unesite n: 17
2
3
5
7
11
13
17
Suma je: 58
*/

// MOJ KOD:

#include<stdio.h>

int main()
{
    int prost, n, i, suma=0, j;

    printf("Unesite n: ");
    scanf("%d", &n);
    
    for(i=2; i<=n; i++)
    {
        prost = 1;
        for(j=2; j<i; j++){
            if(i%j == 0)
            {
                prost = 0;
                break;
            }
        }
            
        if(prost){
            printf(" %d\n ",i);
            suma+=i;
        }
                        
    }

    printf("Suma je: %d",suma);
    return 0;
}