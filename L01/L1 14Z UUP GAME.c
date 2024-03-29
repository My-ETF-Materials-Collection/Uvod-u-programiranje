/*
Zadatak
Tri drugarice Anja, Elma i Una odlučile su za vikend da idu u neki grad u kojem je lijepo vrijeme. Problem je što se njih tri ne slažu oko toga šta je tačno "lijepo vrijeme": Anja voli sunce i snijeg ali ne voli kišu, Elma ne voli kada je vrlo vruće niti vrlo hladno, a Una ne voli padavine generalno i ne voli kad je vrijeme "onako".

Napravite program koji će drugaricama pomoći da izaberu da li će ići u Sarajevo, Mostar ili Bihać. Najprije je potrebno unijeti vremensku prognozu za svaki od ova tri grada, i to u vidu temperature u °C i podatka da li se predviđaju padavine ili ne (ako ne onda pretpostavljamo da će biti sunčano). Ako je temperatura veća od 0°C, padavina je kiša, a u suprotnom padavina je snijeg. Doživljaj toplote je dat u tabeli:

30°C - vrlo vruće
20-30°C - vruće
5-20°C - onako
-5-5°C - hladno
<-5°C - vrlo hladno

Ako ima više gradova u kojima vrijeme odgovara sve tri drugarice, treba ispisati najbliži (drugaricama je najbliže Sarajevo, zatim Mostar i na kraju Bihać). Poruka treba glasiti npr. "Drugarice idu u Mostar." Ako niti jedan grad ne odgovara svim drugaricama, treba ispisati najbliži grad u koji mogu ići barem dvije od tri drugarice npr. "Elma i Una mogu u Bihac." (imena treba poredati abecednim redom). Ako ni takav grad ne postoji, onda treba ispisati "Ne odgovara niti jedan grad."

Primjer ulaza i izlaza:


Padavine (D/N): d
Unesite prognozu za Mostar:
Temperatura: 29
Padavine (D/N): N
Unesite prognozu za Bihac:
Temperatura: 20
Padavine (D/N): N
Drugarice idu u Mostar.
Na upit "Padavine (D/N):" dozvoljeno je unijeti veliko ili malo slovo D ili N. Ako korisnik ne unese ništa od toga, treba ispisati poruku "Pogresan unos." i prekinuti program. Primjer:


Unesite prognozu za Sarajevo:
Temperatura: 25
Padavine (D/N): k
Pogresan unos.
*/

// MOJ KOD:
#include <stdio.h>

int main() {

  char padavineM, padavineS, padavineB;
  double tempM, tempS, tempB;
  
  printf("Unesite prognozu za Sarajevo:\n");
  printf("Temperatura: ");
  scanf("%lf", &tempS);
  printf("Padavine (D/N): ");
  scanf(" %c", &padavineS);
   if (padavineS != 'D' && padavineS != 'N' && padavineS != 'd' && padavineS != 'n'){
    printf("Pogresan unos.");
    return 0;
  }
  printf("Unesite prognozu za Mostar:\n");
  printf("Temperatura: ");
  scanf("%lf", &tempM);
  printf("Padavine (D/N): ");
  scanf(" %c", &padavineM);
  if (padavineM != 'D' && padavineM != 'N' && padavineM != 'd' && padavineM != 'n'){
    printf("Pogresan unos.");
    return 0;
  }
  printf("Unesite prognozu za Bihac:\n");
  printf("Temperatura: ");
  scanf("%lf", &tempB);
  printf("Padavine (D/N): ");
  scanf(" %c", &padavineB);
  if (padavineB != 'D' && padavineB != 'N' && padavineB != 'd' && padavineB != 'n'){
    printf("Pogresan unos.");
    return 0;
  }
int anjaS=0,elmaS=0,unaS=0,anjaM=0,elmaM=0,unaM=0,anjaB=0,elmaB=0,unaB=0;

  if(tempS<=0){
      if(padavineS=='D' || padavineS=='d'){
          if(tempS>=-5){
              elmaS++;
          }
          anjaS++;
      }else if(padavineS=='N' || padavineS=='n'){
          if(tempS>=-5){
              elmaS++;
          }
          if(tempS<5){
              unaS++;
          }
          anjaS++;
      }
  }else{
      if(padavineS=='D' || padavineS=='d')
      {
          if(tempS<30){
              elmaS++;
          }
      }else if(padavineS=='N' || padavineS=='n')
      {
          if(tempS<30){
              elmaS++;
          }
          if(tempS<5 || tempS>20)
          {
              unaS++;
          }
          anjaS++;
      }
  } 
  
  if(tempM<=0){
      if(padavineM=='D' || padavineM=='d'){
          if(tempM>=-5){
              elmaM++;
          }
          anjaM++;
      }else if(padavineM=='N' || padavineM=='n'){
          if(tempM>=-5){
              elmaM++;
          }
          if(tempM<5 || tempM>20){
              unaM++;
          }
          anjaM++;
      }
  }else{
      if(padavineM=='D' || padavineM=='d'){
          if(tempM<30){
              elmaM++;
          }
      }else if(padavineM=='N' || padavineM=='n'){
          if(tempM<30){
              elmaM++;
          }
          if(tempM<5 || tempM>20){
              unaM++;
          }
          anjaM++;
      }
  }

  if(tempB<=0){
      if(padavineB=='D' || padavineB=='d'){
          if(tempB>=-5){
              elmaB++;
          }
          anjaB++;
      }else if(padavineB=='N' || padavineB=='n'){
          if(tempB>=-5){
              elmaB++;
          }
          if(tempB<5 || tempB>20){
              unaB++;
          }
      }
  }else{
      if(padavineB=='D' || padavineB=='d'){
          if(tempB<30){
              elmaB++;
          }
      }else if(padavineB=='N' || padavineB=='n'){
          if(tempB<30){
              elmaB++;
          }
          if(tempB<5 || tempB>20){
              unaB++;
          }
          anjaB++;
      }
  }
if(anjaS>=1 && elmaS>=1 && unaS>=1){
      printf("Drugarice idu u Sarajevo.");
      return 0;
  }else if(anjaM>=1 && elmaM>=1 && unaM>=1){
      printf("Drugarice idu u Mostar.");
      return 0;
  }else if(anjaB>=1 && elmaB>=1 && unaB>=1){
      printf("Drugarice idu u Bihac.");
      return 0;
  }else if(anjaS>=1 && elmaS>=1 && unaS==0){
      printf("Anja i Elma mogu u Sarajevo.");
      return 0;
  }else if(anjaS==0 && elmaS>=1 && unaS>=1){
      printf("Elma i Una mogu u Sarajevo.");
      return 0;
  }else if(anjaS>=1 && elmaS==0 && unaS>=1){
      printf("Anja i Una mogu u Sarajevo.");
      return 0;
  }else if(anjaM>=1 && elmaM>=1 && unaM==0){
      printf("Anja i Elma mogu u Mostar.");
      return 0;
  }else if(anjaM>=1 && elmaM==0 && unaM>=1){
      printf("Anja i Una mogu u Mostar.");
      return 0;
  }else if(anjaM==0 && elmaM>=1 && unaM>=1){
      printf("Elma i Una mogu u Mostar.");
      return 0;
  }else if(anjaB>=1 && elmaB>=1 && unaB==0){
      printf("Anja i Elma mogu u Bihac.");
      return 0;
  }else if(anjaB>=1 && elmaB==0 && unaB>=1){
      printf("Anja i Una mogu u Bihac.");
      return 0;
  }else if(anjaB==0 && elmaB>=1 && unaB>=1){
      printf("Elma i Una mogu u Bihac.");
      return 0;
  }else{
      printf("Ne odgovara niti jedan grad.");
      return 0;
  }
  return 0;
  }  
    