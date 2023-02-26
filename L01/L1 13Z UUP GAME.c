/*
Date su tri tačke u dvodimenzionalnom Dekartovom prostoru preko koordinata x i y. Ove tri tačke čine trougao.

Potrebno je napraviti program koji omogućuje unos ovih tačaka (koordinate su realni brojevi), zatim ispisuje koju vrstu trougla one čine, te ispisuje najveći ugao u trouglu (u stepenima).

Vrsta trougla može biti: Linija (ako sve tri tačke leže na istom pravcu onda u pitanju uopšte nije trougao nego linija), Jednakostranični, Pravougli, Jednakokraki, Raznostranični. Vrsta trougla se ispisuje u zasebnoj liniji, bez naših slova. Ako je trougao istovremeno jednakokraki i pravougli, ispisuje se oboje. Iznosi stepeni, minuta i sekundi su uvijek cijeli brojevi.

Primjer ulaza i izlaza:

Unesite koordinate tacke t1: 0.1 0.1
Unesite koordinate tacke t2: 0.1 0.2
Unesite koordinate tacke t3: 0.2 0.2
Pravougli
Jednakokraki
Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.
Napomena: Koristiti vrijednost ε=0.0001 i tip double.
*/

#include <math.h>
#include <stdio.h>
#define EPS 0.0001
#define PI 3.141592
int main() {

  double x1, x2, x3, y1, y2, y3;

  printf("Unesite koordinate tacke t1: ");
  scanf("%lf %lf", &x1, &y1);
  printf("Unesite koordinate tacke t2: ");
  scanf("%lf %lf", &x2, &y2);
  printf("Unesite koordinate tacke t3: ");
  scanf("%lf %lf", &x3, &y3);

  double a, b, c, P;
  double alfa, beta, gama;

  a = pow(((x2 - x1)*(x2-x1) + (y2 - y1)*(y2-y1)), 0.5);
  b = pow(((x3 - x2)*(x3-x2) + (y3 - y2)*(y3-y2)), 0.5);
  c = pow(((x3 - x1)*(x3-x1) + (y3 - y1)*(y3-y1)), 0.5);

  P = pow(((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))), 0.5);

  alfa = acos((b*b + c*c - a*a) / (2 * b * c)) *(180.0/PI);
  beta = acos((a*a + c*c - b*b) / (2 * a * c)) *(180.0/PI);
  gama = acos((b*b + a*a - c*c) / (2 * b * a)) *(180.0/PI);
  
    double maxugao;

  if ((((alfa-beta)>EPS) || alfa>beta) && (((alfa-gama)>EPS)) || alfa>gama) {
    maxugao = alfa;
  } else if ((((beta-alfa)>EPS) || beta>alfa) && (((beta-gama)>EPS) || beta>gama)) {
    maxugao = beta;
  } else {
    maxugao = gama;
  }

  if((fabs(90-alfa)<EPS || fabs(90-beta)<EPS || fabs(90-gama)<EPS) && P!=0){
    printf("Pravougli\n");
  }

  if (P == 0) {
    printf("Linija\n");
  } else if (fabs(a-b)<EPS && fabs(b-c)<EPS) {
    printf("Jednakostranicni\n");
  } else if ((fabs(a-b)>EPS && fabs(a-c)<EPS) || fabs(a-c)>EPS && fabs(a-b)<EPS) {
    printf("Jednakokraki\n");
  } else if (fabs(a-b)>EPS && fabs(b-c)>EPS) {
    printf("Raznostranicni\n");
  }

  int h, m, s;
  h=maxugao;
  m=((maxugao-h)*60);
  s=((((maxugao-h)*60-m)*60));

  printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", h, m, s);

  return 0;
}
