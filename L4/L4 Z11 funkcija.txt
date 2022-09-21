#include <stdio.h>

int main() {
    
    char m[12][22];
    int n;

    printf("Crtat cemo funkciju y + x = n. ");

    do{
        printf("Unesite n: ");
        scanf("%d",&n);
        if(n<=0 || n>20) printf("Pogresan unos");
    }while(n<=0 || n>20);

    int i,j;
    for(i=0; i<12; i++){
        for(j=0; j<22; j++){
            m[i][j] = ' ';
        }
    }
    int br = 2;
    for(i=0; i<12; i++){
        for(j=0; j<22; j++){
            m[0][0] = 10;
            if(!j && i<=10 && i>0) m[i][j] = 58-i;
            else if(j==1 && i<=10) m[i][j] = '+';
            else if(i==10 && j>1) m[i][j] = '+';
            else if(i==11) m[i][j] = j;
            if(i>10-n && i<10 && j>1){m[i][br] = '*';}
        }
        if(i>10-n && i<11 && j>1) br++;
    }

    for(i=0; i<12; i++){
        for(j=0; j<22; j++){
            if(!i && !j){printf("%d", m[i][j]);}
            else if(!j && i<=10 && i>0){printf("%c ", m[i][j]);}
            else if(j==1 && i<=10){printf("%c", m[i][j]);}
/*            else if(i==10 && j>1) printf("%3c", m[i][j]);*/
            else if(i==11 && j<21){printf("%3d", m[i][j]);}
            if(i>10-n && i<11 && j>1){printf("%3c", m[i][j]);if(m[i][j]=='*'){break;}}
        }
        printf("\n");
    }

	return 0;
}
