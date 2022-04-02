#include <stdio.h>
int main () {
    int valortv, namigos, i, x=1, y=2;
    scanf("%d", &valortv);
    scanf(" %d", &namigos);
    int emprestado[namigos];
    i=namigos;
    for(namigos=0; namigos<i; ++namigos) {
        scanf(" %d", &emprestado[namigos]);
    }
    //printf("%d\n", namigos);
    i=0;
    for(y=2; ((i+2)<namigos && (y-5)<namigos); ++y) {
        if (emprestado[i] + emprestado[x] + emprestado[y] == valortv) {
            printf("Zeca nao vai ter que trabalhar!");
            goto end;
        }
        if (y == (namigos-1)) {
            y=(x+2);
            x=(x+1);
            continue;
        }
        if (x == (namigos-2)) {
            x=(i+2);
            i=(i+1);
            y=(i+3);
            continue;
        }
    }
    y=2;
    for(x=3; x<namigos; ++x) {
        if ((emprestado[i] + emprestado[x] + emprestado[y]) == valortv) {
            printf("Zeca nao vai ter que trabalhar!");
            goto end;
        }
    }
    x=1;
    for(i=4; i<namigos; ++i) {
        if ((emprestado[i] + emprestado[x] + emprestado[y]) == valortv) {
            printf("Zeca nao vai ter que trabalhar!");
            goto end;
        }
    }
    i=0;
    printf("Zeca vai ter que trabalhar.");


    end:
    return 0;
}