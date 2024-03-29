/*
Zadatak
Date su dvije jednačine:
image.png
Ove jednačine opisuju dvije kružnice u koordinatnom prostoru. Kružnica A ima centar u tački (p1,q1) sa poluprečnikom r1, dok kružnica B ima centar u tački (p2,q2) sa poluprečnikom r2.

Potrebno je napisati program koji na osnovu unesenih centara kružnice te vrijednosti poluprečnika određuje odnos ove dvije kružnice. Ukoliko su kružnice iste, potrebno je ispisati poruku ‘Kruznice su identicne.’, ukoliko se kružnice dodiruju/sijeku u jednoj tački, potrebno je ispisati poruku ‘Kruznice se dodiruju u tacki (X,Y).’ gdje X i Y predstavljaju koordinate tačke u kojoj se kružnice dodiruju. Ukoliko se kružnice sijeku, potrebno je odrediti tačke presjeka dviju kružnica i ispisati poruku ‘Kruznice se sijeku u tackama (X1,Y1) i (X2,Y2).’ gdje su X1,Y1,X2 i Y2 koordinate presječnih tačaka. Ukoliko se jedna kružnica nalazi unutar druge potrebno je ispisati poruku ‘Jedna kruznica je sadrzana u drugoj.’. Konačno, ukoliko se kružnice ne sijeku, potrebno je ispisati poruku ‘Kruznice se ne sijeku’. Potrebno je dodati eventualna ograničenja na parametre, čisto reda radi.

Napomena: Koordinate centara kružnica i dužina poluprečnika kružnice mogu biti realni brojevi. Obratiti pažnju na probleme prilikom rada sa realnim brojevima.

Primjer ulaza i izlaza:

Unesite koordinate centra kruznice A: 5 5
Unesite poluprecnik kruznice A: 5
Unesite koordinate centra kruznice B: 20 4
Unesite poluprecnik kruznice B: 2
Kruznice se ne sijeku.
*/

// MOJ KOD:

#include <math.h>
#include <stdio.h>
#define eps 0.0001

int main() {
  // A: (x-p1)^2+(y-q1)^2=r1^2
  // B: (x-p2)^2+(y-q2)^2=r2^2

  double p1, q1, p2, q2, r1, r2;
  
  printf("Unesite koordinate centra kruznice A: ");
  scanf("%lf %lf", &p1, &q1);
  printf("Unesite poluprecnik kruznice A: ");
  scanf("%lf", &r1);

  printf("Unesite koordinate centra kruznice B: ");
  scanf("%lf %lf", &p2, &q2);
  printf("Unesite poluprecnik kruznice B: ");
  scanf("%lf", &r2);

  double d = sqrt(pow((p2 - p1), 2) + pow((q2 - q1), 2));
  double x3, y3, xp1, xp2, yp1, yp2;
  double l = (pow(r1, 2) - pow(r2, 2) + pow(d, 2)) / (2 * d);
  double h = sqrt(pow(r1, 2) - pow(l, 2));

  if (fabs(p1 - p2) < eps && fabs(q1 - q2) < eps && fabs(r1 - r2) < eps) {
    printf("Kruznice su identicne.");
  } else if ((r1 > r2 && d + r2 < r1) || (r1 < r2 && d + r1 < r2)) {
    printf("Jedna kruznica je sadrzana u drugoj.");
  } else if (fabs((r1 - r2) - d) < eps || fabs(r1 + r2 - d) < eps) {
      
    if (fabs((r1 - r2) - d) < eps) {
      x3 = ((r1 * p2 - r2 * p1) / (r1 - r2));
      y3 = ((r1 * q2 - r2 * q1) / (r1 - r2));
    } else if (fabs(r1 + r2 - d) < eps) {
      x3 = ((r1 * p2 - r2 * p1) / (r1 + r2));
      y3 = ((r1 * q2 - r2 * q1) / (r1 + r2));
    }
    printf("Kruznice se dodiruju u tacki (%.2lf,%.2lf).", x3, y3);
  } else if (d < r1 + r2 || d < fabs(r1 - r2)) {

    double xp1 = (l / d) * (p2 - p1) + (h / d) * (q2 - q1) + p1;
    double xp2 = (l / d) * (p2 - p1) - (h / d) * (q2 - q1) + p1;
    double yp1 = (l / d) * (q2 - q1) - (h / d) * (p2 - p1) + q1;
    double yp2 = (l / d) * (q2 - q1) + (h / d) * (p2 - p1) + q1;

    printf("Kruznice se sijeku u tackama (%.2lf,%.2lf) i (%.2lf,%.2lf).", xp1,
           yp1, xp2, yp2);
  }  else {
    printf("Kruznice se ne sijeku.");
  }

  return 0;
}
