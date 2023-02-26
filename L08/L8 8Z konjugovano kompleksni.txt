#include <math.h>
#include <stdio.h>

typedef struct {
  int im;
  int re;
} Kompleksni;

int konjugovano_kompleksni(Kompleksni *p1, Kompleksni *p2, Kompleksni *rez) {

  int parovi = 0;
  int i, j;

  Kompleksni a = {0, 0};
  Kompleksni *pok1 = &a, *pok2 = &a;

  while (p1 != p2) {
    pok1 = p1 + 1;
    while (pok1 != p2) {
      if ((*pok1).im == (*p1).im && (*pok1).re == (*p1).re) {
        pok2 = pok1;
        while (pok2 != p2- 1) {
          *pok2 = *(pok2 + 1);
          pok2++;
        }
        p2--;
        pok1--;
      }
      pok1++;
    }
    (rez->re) = (p1->re);
    (rez->im) = -(p1->im);
    rez++;
    p1++;
    parovi++;
  }
  return parovi;
}

int main() {
  return 0;
}
