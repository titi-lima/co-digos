#include <stdio.h>
int main () {
int reais, x0, x1, y0, y1, z0, z1;
    scanf("%d", &reais);
    scanf("%d", &x0);
    scanf(" %d", &x1);
    scanf(" %d", &y0);
    scanf(" %d", &y1);
    scanf(" %d", &z0);
    scanf(" %d", &z1);

    if ((x0+y0+z0) > reais) {
        printf("N\n");
    }
    else if ((x0+y0+z0 == reais)) {
        printf ("S\n");
        printf("%d %d %d\n", x0, y0, z0);
    }
    else {
        while (((x0+y0+z0) < reais) && (y0<y1)) {
            ++y0;
        }
        if ((x0+y0+z0 == reais)) {
        printf ("S\n");
        printf("%d %d %d\n", x0, y0, z0);
        }
        else {
        while (((x0+y0+z0) < reais) && (z0<z1)) {
            ++z0;
        }
        if ((x0+y0+z0 == reais)) { 
        printf ("S\n");
        printf("%d %d %d\n", x0, y0, z0);
        }
        else {
        while (((x0+y0+z0) < reais) && (x0<x1)) {
            ++x0;
        }
        printf ("S\n");
        printf("%d %d %d\n", x0, y0, z0);
        }

        }

    }
    
    return 0;
}