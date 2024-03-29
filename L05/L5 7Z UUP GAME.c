/*
Zadatak
Napraviti program koji ispisuje na ekranu Pascalov trougao sa n redova pri čemu se prirodan broj n unosi sa tastature:

image.png

Svaki broj u Pascalovom trouglu je jednak sumi dva broja koji se nalaze iznad njega. Iznad je crvenom bojom označen broj 4 koji je jednak zbiru brojeva 1 i 3.

Za računanje broja na koordinatama x,y napisati i koristiti funkciju int pascal(int x, int y). Tako broj 4 iz prethodnog primjera ima koordinate x=5, y=2.

Primjer ulaza i izlaza programa:

Unesite n: 10

1
1   1
1   2   1
1   3   3   1
1   4   6   4   1
1   5   10  10  5   1
1   6   15  20  15  6   1
1   7   21  35  35  21  7   1
1   8   28  56  70  56  28  8   1
1   9   36  84  126 126 84  36  9   1
*/

// MOJ KOD:

#include <stdio.h>

int pascal(int x, int y);

int main() {
    int n,i,j;
	printf("Unesite n: ");
    scanf("%d",&n);

    for(i=1;i<=n;++i)
    {
    for(j=1;j<=i;++j)
    {
      printf("%d   ",pascal(i,j));
    }
    printf("\n");
  }

	return 0;
}

int pascal(int x, int y){
    int pas[100][100];
    int i,j;
    for(i=0;i<x;++i)
    {
    for(j=0;j<=i;j++){
        if(j==0 || j==i){
            pas[i][j]=1;
        }else{
            pas[i][j]=pas[i-1][j-1]+pas[i-1][j];
        }
    }
    }
    return pas[x-1][y-1];
}
