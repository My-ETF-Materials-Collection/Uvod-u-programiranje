#include <stdio.h>

int uOpsegu(char a, char b, char c) {
  if (a >= b &&  a <= c) // ako se neki char nalazi u opsegu izmedju druga dva chara
    return 1;
  return 0;
}

char *prebroji(char *tekst, char *slova){
    
    int i;
    char *kraj = slova;
    char *sptr = slova;
    int histogram[127]={0};

    if(tekst[0]=='\0'){
        slova[0]='\0';
        return kraj;
    }

    i=0;
    while(tekst[i]!='\0'){
        if(uOpsegu(tekst[i],'A','Z')) histogram[tekst[i]]++;
        else if(uOpsegu(tekst[i], 'a', 'z')) histogram[tekst[i]-32]++;
        i++;
    }

    int k=0;
    int max = histogram[0];

    while(1){
        for(i=0; i<127; i++){
            if(histogram[i]>histogram[max]){
                max=i;
            }
        }

        if(max==0) break;

        slova[k] = max;
        k++;
        histogram[max] = 0;
        max = histogram[0];
    }
 
    while(*sptr != slova[k-1]) sptr++;
    *(sptr+1) = '\0';
    return kraj;
}

void unesi(char niz[], int velicina) {//unesi u niz ovo sve prvo
  char znak = getchar();
  if (znak == '\n')  znak = getchar();
  int i = 0;
  while (i < velicina - 1 && znak != '\n') {
    niz[i] = znak;
    i++;
    znak = getchar();
  }
  niz[i] = '\0';
}

int main() {
    
}