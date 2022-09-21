#include <stdio.h>

char* popuni_lijevo(char* str, int n){
    char *kraj = str;
    while(*kraj!='\0') kraj++;//sveli na kraj pokazivac

    if(n<(kraj-str)) return str;//ako je string veci od n
    int razlika = n - (kraj-str), i;
    do{
        *(kraj+razlika) = *kraj;
        kraj--;
    }while(kraj>=str);

    for(i=0; i<razlika; i++) *(str+i) = ' ';
    return str;
}

char* popuni_desno(char* str, int n){
    char *kraj = str;
    while(*kraj!='\0') kraj++;//sveli na kraj pokazivac

    if(n<(kraj-str)) return str;//ako je string veci od n
    int razlika = n - (kraj-str), i;
    *(kraj+razlika)=*kraj;
    for(i=0; i<razlika; i++) *(kraj+i) = ' ';
    return str;
}

int main() {
	char n1[100] = "Bosna", n2[100] = "Hercegovina";
    char *p1 = popuni_lijevo(n1, 15);
    char *p2 = popuni_lijevo(n2, 15);
    printf ("\n'%s'\n'%s'", p1, p2);
	return 0;
}
