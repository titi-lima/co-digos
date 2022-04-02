#include <stdio.h>

int main() {
    char c;
    int mat[4][4], x=0, y=0, j=0, k=0;
    for(j=0; j<4; ++j) {
        for(k=0; k<4; ++k) {
            mat[j][k] = 0;
        }
    }

    for(j=0; j<20; ++j) {
        scanf(" %c", &c);
        switch (c) {
            case 'b': {
                ++y;
                mat[x][y] += 1;
                break;
            }
            case 'c': {
                --y;
                mat[x][y] += 1;
                break;
            }
            case 'd': {
                ++x;
                mat[x][y] += 1;
                break;
            }
            case 'e': {
                --x;
                mat[x][y] += 1;
                break;
            }
        }
    }
    int aux=0;
    x=0;
    y=0;
    for(j=0; j<4; ++j) {
        for(k=0; k<4; ++k) {
            if(mat[j][k] > aux) {
                x = j;
                y = k;
                aux = mat[j][k];
            }
        }
    }
    printf("Coordenada X:%d, Y:%d\n", x, y);
    return 0;
}