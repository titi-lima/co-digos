#include <stdio.h>
int main () {
    int x, y;
    scanf("%d %d", &y, &x);
    int m1[x][y];
    for (int k=0; k<y; ++k) {
        for (int j=0; j<x; ++j) {
            scanf("%d", &m1[j][k]);
        }
    }
    for (int k=0; k<x; ++k) {
        for (int j=0; j<y; ++j) {
            printf("%d ", m1[k][j]);
        }
        printf("\n");
    }
}