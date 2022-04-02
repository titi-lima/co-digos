#include <stdio.h>
int main () {
    int x, y, a, b, qbombas, flag=0;
    char z;
    scanf("%dx%d", &x, &y);
    scanf("%d", &qbombas);
    int bombas[qbombas], campo[x][y];
    for (int s=0; s<x; ++s) {
        for (int r=0; r<y; ++r) {
            campo[s][r] = 0;
        }
    }

    for(int i=0; i<qbombas; ++i) {
        scanf(" %c%d", &z, &b);
        a=z-97;
        b-=1;
        campo[a][b] = 9;
        if(a > 0 && b > 0) {
            campo[a-1][b-1]+=1;
            campo[a][b-1]+=1;
            campo[a-1][b]+=1;
        }
        if(a<(x-1) && b<(y-1)) { 
            campo[a+1][b+1]+=1;
            campo[a][b+1]+=1;
            campo[a+1][b]+=1;
        }
        if(a<(x-1) && b==(y-1)) { // n pode b+1
            campo[a+1][b]+=1;
        }
        if(a==(x-1) && b<(y-1)) { // n pode a+1
            campo[a][b+1]+=1;
        }
        if(a > 0 && b == 0) { // n pode b-1
            campo[a-1][b] +=1;
        }
        if(a == 0 && b > 0) { // n pode a-1
            campo[a][b-1]+=1;
        }
        if(a > 0 && b > 0 && a<(x-1) && b<(y-1)) {
            campo[a-1][b+1]+=1;
            campo[a+1][b-1]+=1;
        }
        if((b<(y-1) && a > 0) && (a==(x-1) || b==0)) { // n pode a+1 ou b-1
            campo[a-1][b+1]+=1;
        }
        if((a<(x-1) && b > 0) && (b==(y-1) || a==0)) { // n pode a-1 ou b+1
            campo[a+1][b-1]+=1;
        }
    }

    for (int s=0; s<x; ++s) {
        for (int r=0; r<y; ++r) {
            if (campo[s][r] > 9) {
                campo[s][r] = 9;
            }
        }
    }
    if (qbombas>=(x*y)) {
        flag=1;
        printf("BANDECLAY OVERLOAD!\n");
    }

    for (int s=0; s<x && flag!=1; ++s) {
        for (int r=0; r<y; ++r) {
            printf("%d ", campo[s][r]);
        }
        printf("\n");
    }



    return 0;
}