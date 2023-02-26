/*
Zadatak
Date su strukture

struct Tacka {
    int x,y;
};
struct Trougao {
    struct Tacka A,B,C;
};
U pitanju su likovi u Dekartovom dvodimenzionalnom koordinatnom sistemu, pri čemu je trougao opisan koordinatama svojih vrhova.

Napisati funkciju pod imenom izbaci_pravougle koja prima niz trouglova i iz njega izbacuje sve pravougle trouglove bez promjene redoslijeda. Napravite i glavni program koji omogućuje testiranje ispravnog rada ove funkcije.

Napomena: U funkciji nije dozvoljeno kreirati pomoćni niz.
*/

// MOJ KOD:

#include <math.h>
#include <stdio.h>

struct Tacka {
  int x, y;
};
struct Trougao {
  struct Tacka A, B, C;
};

int izbaci_pravougle(struct Trougao *trouglovi, int vel) {
  int jelPravougli, i, j;
  double AB, BC, AC;
  for (i = 0; i < vel; i++) {
    jelPravougli = 0;
    BC = pow(trouglovi[i].C.x - trouglovi[i].B.x, 2) +
         pow(trouglovi[i].C.y - trouglovi[i].B.y, 2);
    AC = pow(trouglovi[i].C.x - trouglovi[i].A.x, 2) +
         pow(trouglovi[i].C.y - trouglovi[i].A.y, 2);
    AB = pow(trouglovi[i].B.x - trouglovi[i].A.x, 2) +
         pow(trouglovi[i].B.y - trouglovi[i].A.y, 2);
    if (AC == AB + BC || BC == AC + AB || AB == BC + AC)
      jelPravougli = 1;

    if (jelPravougli) {
      for (j = i; j < vel - 1; j++) {
        trouglovi[j] = trouglovi[j + 1];
      }
      vel--;
      i--;
    }
  }

  return vel;
}

int main() {
  struct Trougao trouglovi[3];
  int i, vel;
  trouglovi[0].A.x = 0;
  trouglovi[0].A.y = 0;
  trouglovi[0].B.x = 1;
  trouglovi[0].B.y = 0;
  trouglovi[0].C.x = 0;
  trouglovi[0].C.y = 1;

  vel = izbaci_pravougle(trouglovi, 3);
  for (i = 0; i < vel; i++) {
    printf("Trougao %d: (%d,%d)-(%d,%d)-(%d,%d)\n", i, trouglovi[i].A.x,
           trouglovi[i].A.y, trouglovi[i].B.x, trouglovi[i].B.y,
           trouglovi[i].C.x, trouglovi[i].C.y);
  }
  return 0;
}
