#include <stdio.h>
int main() {
    int n, qaltos=0, qmedios=0, qbaixos=0, flag = 0, repetidos = 0, s, st;
    scanf("%d", &n);
    int nmaisum = n+1, guarda, cont=0, i=n;
    int predios[n], altos[qaltos], medios[qmedios], baixos[qbaixos];
    for (n=0; n<i; ++n) {
        scanf(" %d", &predios[n]);
    }
    if (i==1) {
        if (predios[0] < 50) {
            baixos[qbaixos] = predios[0];
            ++qbaixos;
        }
        else if (predios[0] >= 100) {
            altos[qaltos] = predios[0];
            ++qaltos;
        }
        else {
            medios[qmedios] = predios[0];
            ++qmedios;
        }
        printf("%d\n", 1);
        printf("%d\n", qaltos);
        printf("%d\n", qmedios);
        printf("%d\n", qbaixos);
        printf("%d\n", 0);
    }
    n=0;
    nmaisum = (n+1);
    //printf("pnm1:%d", predios[nmaisum]);
    //printf("pn:%d", predios[n]);
    while (n<=(i-1)) {
        if (predios[n] == predios[nmaisum]) {
           // printf("pn:%d\n", predios[n]);
            ++n;
            ++cont;
            ++repetidos;
            nmaisum = (n+1);
        }
        else {
            ++nmaisum;
            //printf("'pn:%d\n", predios[n]);
            if (nmaisum == (i)) {
                ++n;
                ++cont;
                nmaisum = (n+1);
              //  printf("cont:%d\n", cont);
            }
        }
        if (nmaisum == (i)) {
            ++n;
            ++cont;
            nmaisum = (n+1);
            //printf("cont:%d\n", cont);
        }
    }
    //printf("repetidos: %d\n", repetidos);
    for (n=0; n<i; ++n) {
        nmaisum = (n+1);
        while (nmaisum<i) {
        if (predios[n]>predios[nmaisum]) {
            guarda = predios[n];
            predios[n] = predios[nmaisum];
            predios[nmaisum] = guarda;
            ++nmaisum;
        }
         else nmaisum++;
        }
    }
    for (n=0; n<i; ++n) {
       // printf("ord:%d\n", predios[n]);
    }
    s=predios[0];
    st=predios[n-1];
    for (n=0; n<i; ++n) {
        if (predios[n] < 50) {
            baixos[qbaixos] = predios[n];
            ++qbaixos;
        }
        else if (predios[n] >= 100) {
            altos[qaltos] = predios[n];
            ++qaltos;
        }
        else {
            medios[qmedios] = predios[n];
            ++qmedios;
        }
    }
    //printf("0:%d\n", s);
    //printf(("n:%d\n"), predios[n-1]);
    printf("%d\n", cont-repetidos);
    printf("%d\n", qaltos);
    printf("%d\n", qmedios);
    printf("%d\n", qbaixos);
    printf("%d\n", st-s);


    return 0;
}