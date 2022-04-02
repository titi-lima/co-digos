#include <stdio.h>

int main() {
    int qtd, k, flag=0, reg, td=0, km1;
    float vida=100.0;
    scanf("%d", &qtd);
    float d[qtd], t[qtd], temp;
    for(k=0; k<qtd; ++k) {
        scanf("%f %f", &d[k], &t[k]);
    }
    for(k=0; k<qtd; ++k) {
        for(km1=k+1; km1<qtd; ++km1) {
            if(t[k]>t[km1]) {
                temp = t[k];
                t[k] = t[km1];
                t[km1]=temp;
                temp = d[k];
                d[k] = d[km1];
                d[km1]=temp;
            }
        }
    }

    scanf("%d", &reg);
    for(k=0; k<qtd && flag==0; ++k) {
        //printf(".\n");
        if(vida<100) {
            vida+=(t[k]-td)*reg;
        }
        td+=t[k];
        vida-=d[k];
        //printf("vida = %d, dano = %d\n", vida, d[k]);
        if(vida<=0) {
            flag=1;
        }
    }
    if(flag==1) {
        printf("Inimigo Morto\n");
    }
    else printf("Inimigo Vivo\n");



    return 0;
}