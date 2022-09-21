#include <stdio.h>

struct Tacka {
    float x,y;
};

struct Pravougaonik{
    struct Tacka dolje_lijevo;
    struct Tacka gore_desno;
};

struct Pravougaonik min_pravougaonik(struct Tacka* niz, int velicina){
    
    int i;
    float maxx,minx, maxy, miny;
    struct Pravougaonik minPrav;

    maxx = niz[0].x;
    miny = niz[0].y;
    maxy = niz[0].y;
    minx = niz[0].x;

    for(i=0; i<velicina; i++){
        if(niz[i].x>maxx) maxx = niz[i].x;
        if(niz[i].y>maxy) maxy = niz[i].y;
        if(niz[i].x<minx) minx = niz[i].x;
        if(niz[i].y<miny) miny = niz[i].y;
    }

    minPrav.dolje_lijevo.x = minx;
    minPrav.dolje_lijevo.y = miny;
    minPrav.gore_desno.x = maxx;
    minPrav.gore_desno.y = maxy;

    return minPrav;
}

int main() {

    int n, i;
    struct Tacka point[100];

    printf("Unesite broj tacaka: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Unesite koordinate x i y tacke %d: ", i+1);
        scanf("%f %f", &point[i].x, &point[i].y);
    }

    struct Pravougaonik p = min_pravougaonik(point, n);
    printf("Minimalni pravougaonik za ove tacke ima uglove:\n(%g,%g) - (%g,%g)", p.dolje_lijevo.x, p.dolje_lijevo.y, p.gore_desno.x, p.gore_desno.y);


	return 0;
}
