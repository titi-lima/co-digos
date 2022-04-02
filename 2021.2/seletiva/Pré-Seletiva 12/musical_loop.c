#include <stdio.h>

int main() {
    int n, samples[10003], aux, cont=0;
    scanf("%d", &n);
    while(n!=0) {
        for(aux=1; aux<n+1; ++aux) {
            scanf("%d", &samples[aux]);
        }
        samples[0]=samples[n];
        samples[n+1]=samples[1];
        for(aux=1; aux<n+1; ++aux) {
            if(samples[aux]>samples[aux-1] && samples[aux]>samples[aux+1] || samples[aux]<samples[aux-1] && samples[aux]<samples[aux+1]) ++cont;
        }
        scanf("%d", &n);
        printf("%d\n", cont);
        cont=0;
    }

    return 0;
}