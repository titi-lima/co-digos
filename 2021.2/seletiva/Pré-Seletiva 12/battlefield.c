#include <stdio.h>
#include <stdlib.h>

int main() {
    int tab[10][10];
    int d, l, r, c, k, aux, aux2;
    scanf("%d", &k);
    for(aux=0; aux<10; ++aux) {
        for(aux2=0; aux2<10; ++aux2) {
            tab[aux][aux2] = 0;
        }
    }
    while(k--) {
        scanf("%d %d %d %d", &d, &l, &r, &c);
        --r;
        --c;
        if(d==0) {
            if(c+l>10) {
                printf("N\n");
                return 0;
            }
            for(aux=c; aux<c+l; ++aux) {
                if(tab[r][aux]==1) {
                    printf("N\n");
                    return 0;
                }
                tab[r][aux] = 1;
            }
        }
        else {
            if(r+l>10) {
                printf("N\n");
                return 0;
            }
            for(aux=r; aux<r+l; ++aux) {
                if(tab[aux][c]==1) {
                    printf("N\n");
                    return 0;
                }
                tab[aux][c] = 1;
            }
        }
    }
    printf("Y\n");

    return 0;
}