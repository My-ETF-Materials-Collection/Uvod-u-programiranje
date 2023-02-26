#include <math.h>
#include <stdio.h>

struct Tacka {
  double x, y;
};

struct Trapez {
  struct Tacka A, B, C, D;
};

double udaljenost(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void trapezi(struct Trapez t[], int n, double niz1[], double niz2[]) {
  int i;
  double a, b, c, d, s;
  for (i = 0; i < n; i++) {
    b = udaljenost(t[i].B.x, t[i].B.y, t[i].A.x, t[i].A.y);
    d = udaljenost(t[i].C.x, t[i].C.y, t[i].B.x, t[i].B.y);
    a = udaljenost(t[i].D.x, t[i].D.y, t[i].C.x, t[i].C.y);
    c = udaljenost(t[i].A.x, t[i].A.y, t[i].D.x, t[i].D.y);

    // obimi trapeza niz1
    niz1[i] = a + b + c + d;
    // povrsine trapeza niz2
    if (a == b && a == c && a == d) {
      niz2[i] = ((a + c) / 2) * sqrt(d * d - pow((a - c) / 2, 2));
    }else{
        s=niz1[i]/2;
         niz2[i]=((a+b)/fabs(b-a))*sqrt((s-a)*(s-b)*(s-b-c)*(s-b-d));
     }
  }
}

int main() {
  /* AT6: Pravi trapezi (povrsine) */
  struct Trapez niz[] = {{{-4, 2}, {3, 2}, {1, 5}, {-3, 5}},
                         {{-4, 2}, {3, 2}, {1, 7}, {-3, 7}},
                         {{-4, 2}, {6, 2}, {5, 7}, {-3, 7}},
                         {{-12, 5}, {6, 5}, {5, 7}, {-3, 7}}};
  double obimi[4], povrsine[4];
  int i;

  trapezi(niz, 4, obimi, povrsine);
  for (i = 0; i < 4; i++)
    printf("%.2f ", povrsine[i]);
  return 0;
}
