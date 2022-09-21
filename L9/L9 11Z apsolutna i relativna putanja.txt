#include <stdio.h>

int uOpsegu(char c){
  if (c >= 'A' && c <= 'Z') return 1;
  return 0;
}

char* pretvori(char* s1, char* s2, char* s3){
    char* rez = s1;
    while(*s1!='\0') s1++;
    while((*s1++=*s2++)) if(s2==s3) break;
    return rez;
}

void pomakniZa(char *p1, char* p2){
    while((*p1++=*p2++));
}

char* apsolutna(char *s1, char *s2){
    
    char *p=s1, *q=s1, *r=s2;
    int preskociti=0, razmaknut=0;
    while(*p!='\0'){
        if(*p=='.' && *(p+1)=='.') preskociti++;
        p++;
    }
    p=s1;

    while(*r!='\0'){
        if(*r=='\\') razmaknut++;
        r++;
    }
    r=s2;

    if(*s1=='\0') return s2;
    if(*s2=='\0') return s1;
    if(uOpsegu(*s1) && *(s1+1)==':') return s1;
    if(preskociti>=razmaknut) return s1;

    while(*s2!='\0') s2++;
    if(*(s2-1)=='\\') s2--;

    while(*p!='\0'){
        if(*p=='.' && *(p+1)=='.'){
            do{
                s2--;
            }while(*s2!='\\');
            char *x = p;
            char *y = p+1+1;
            pomakniZa(x,y);
            p--;
        }
        p++;
    }

    pretvori(s1, r, s2);

    p=s1;
    while(*q!='\0') q++;
    *q='\\';
    q++;
    *q='\0';

    while(!uOpsegu(*p) && *(p+1)!=':'){
        *q=*p;
        p++;
        q++;
    }
    *q='\0';

    q=s1;
    pomakniZa(q,p);

    p=s1;
    while(*p!='\0'){
        if(*p=='.' && *(p+1)=='\\'){
            char* x=p;
            char* y=p+1;
            pomakniZa(x,y);
            p--;
        }
        if(*p=='\\' && *(p+1)=='\\'){
            char* x=p;
            char* y=p+1;
            pomakniZa(x,y);
            p--;
        }
        p++;
    }

    return s1;

}

int main() {
	return 0;
}
