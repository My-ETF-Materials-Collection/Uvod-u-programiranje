/*
Zadatak
Napisati funkciju

Vektor3d vektorski_proizvod (Vektor3d v1, Vektor3d v2)
koja vraća vektorski proizvod v1 i v2 vektora. Struktura Vektor3d je definisana na sljedeći način:

typedef struct {
	double x, y, z;
} Vektor3d;
Podsjetimo, ako su vektori v1 i v2 zadani kao v1=(x1,y1,z1), v2=(x2,y2,z2), njihov vektorski proizvod je jednak:

image.png

Također obavezno napraviti i main funkciju sa sljedećim oblikom ulaza i izlaza:

Unesite vektor v1: 1 1 1
Unesite vektor v2: 2 2 2
Vektorski proizvod vektora v1 i v2 je: (0,0,0)
*/

// MOJ KOD:

#include <stdio.h>

typedef struct {
  double x, y, z;
} Vektor3d;

Vektor3d vektorski_proizvod(Vektor3d v1, Vektor3d v2) {
  Vektor3d v3;
  v3.x = (v1.y * v2.z - v1.z * v2.y);
  v3.y = (v1.z * v2.x - v1.x * v2.z);
  v3.z = (v1.x * v2.y - v1.y * v2.x);
  return v3;
}

int main() {
  Vektor3d v1, v2, v3;
  printf("Unesite vektor v1: ");
  scanf("%lf %lf %lf", &v1.x, &v1.y, &v1.z);
  printf("\nUnesite vektor v2: ");
  scanf("%lf %lf %lf", &v2.x, &v2.y, &v2.z);
  v3=vektorski_proizvod(v1, v2);
  printf("\nVektorski proizvod vektora v1 i v2 je: (%g,%g,%g)", v3.x, v3.y,v3.z);
  return 0;
}
