#include <stdio.h>
#include <math.h>
int main () {
    int x, y;
    scanf("%d %d", &x, &y);
    int matriz[x][y];
    for (int s=0; s<x; ++s) {
        for (int r=0; r<y; ++r) {
            scanf("%d", &matriz[s][r]);
        }
    }
    for (int s=0; s<x; ++s) {
        int flag = 0, cont = 0;
        for (int r=1; r<y && flag==0; ++r) {
            if(matriz[s][r] != -1) {
                int q = matriz[s][r];
                
                //printf("cont: %d\n", cont);
                float e = (1.0/(cont+1));
                int u = pow(q, e);

                for (r=1; r<y && flag==0; ++r) {
                    if (matriz[s][r]==-1) {
                        matriz[s][r]=matriz[s][r-1]*u;
                    }
                }
            }
            else if(matriz[s][r] == -1) {
                ++cont;
            }
        }
    }
    for (int s=0; s<x; ++s) {
        for (int r=0; r<y; ++r) {
            if(r!=(y-1)) {
                printf("%d ", matriz[s][r]);
            }
            else printf("%d\n", matriz[s][r]);
        }
    }


    return 0;
}