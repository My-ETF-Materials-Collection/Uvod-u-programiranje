/*
Zadatak
Data je struktura

struct Tacka3d { double x, y, z };
koja opisuje tačku u trodimenzionalnom dekartovom prostoru preko tri koordinate. Napisati funkciju

int komplanarne_tacke (struct Tacka3d t1, struct Tacka3d t2, struct Tacka3d t3, struct Tacka3d t4) 
koja provjerava da li su četiri tačke poslane kao parametri komplanarne (leže u istoj ravni). Ukoliko jesu, funkcija treba vratiti 1, a ukoliko nisu -1. U slučaju da su tačke jednake, vratiti 0. Najlakši način za provjeru jeste da se naprave tri vektora koja polaze iz jedne tačke, te se posmatra vrijednost mješovitog proizvoda ta tri vektora.

Podsjetimo, mješoviti proizvod tri vektora: v1=(ax,ay,az) i v2=(bx,by,bz) i v3=(cx,cy,cz) je:

image.png

Ako je vrijednost matričnog proizvoda jednaka 0, tada su vektori (samim tim i tačke koje ih čine), komplanarne. U suprotnom, tačke su nekomplanarne.
*/

// MOJ KOD:

#include <stdio.h>

// Korisna stranica da provjerite komplanarnost tacaka
// http://www.ambrsoft.com/TrigoCalc/Plan3D/PointsCoplanar.htm

struct Tacka3d {
  double x, y, z;
};

int komplanarne_tacke(struct Tacka3d t1, struct Tacka3d t2, struct Tacka3d t3,
                      struct Tacka3d t4) {

  if (t1.x == t2.x && t1.y == t2.y && t1.z == t2.z && t2.x == t3.x &&
      t2.y == t3.y && t2.z == t3.z && t3.x == t4.x && t3.y == t4.y &&
      t3.z == t4.z)
    return 0;

  double determinanta = 0;

  determinanta = (t2.x - t1.x) * (t3.y - t1.y) * (t4.z - t1.z) -
                 (t2.x - t1.x) * (t3.z - t1.z) * (t4.y - t1.y) -
                 (t2.y - t1.y) * (t3.x - t1.x) * (t4.z - t1.z) +
                 (t2.y - t1.y) * (t3.z - t1.z) * (t4.x - t1.x) +
                 (t2.z - t1.z) * (t3.x - t1.x) * (t4.y - t1.y) -
                 (t2.z - t1.z) * (t3.y - t1.y) * (t4.x - t1.x);

  if (determinanta == 0) {
    return 1;
  } else
    return -1;

  return 0;
}
/*
x1 y1 z1 1
x2 y2 z2 1
x3 y3 z3 1
x4 y4 z4 1
*/
int main() {
  struct Tacka3d t1 = {1, 1, 1}, t2 = {1, 1, 1}, t3 = {1, 1, 1}, t4 = {1, 1, 1};
  printf("%d ", komplanarne_tacke(t1, t2, t3, t4));
  return 0;
}
