#include <stdio.h>
int main () {
    int quant, X, guarda, quantmais1, i=0;
    scanf("%d", &quant);
    int original[quant], ordenado[quant], iguais[quant];
    X=quant;
    for(quant=0; quant<X; ++quant) {
        scanf(" %d", &original[quant]);
    }
    //printf("%d\n", original[0]);
    for(quant=0; quant<X; ++quant) {
        ordenado[quant] = original[quant];
    }
    for(quant=0; quant<X; ++quant) {
        quantmais1=(quant+1);

        //printf("quant: %d\n", quant);
        while (quantmais1<X) {
         if (original[quant]>original[quantmais1]) {
            guarda = original[quant];
            original[quant] = original[quantmais1];
            original[quantmais1] = guarda;
            ++quantmais1;
         }
         else quantmais1++;
        }
        //printf("vetor %d\n", original[quant])
    }
    for(quant=0; quant<X; ++quant) {
        if (original[quant] == ordenado[quant]) {
            //printf("%d igual a %d\n", original[quant], ordenado[quant]);
            iguais[quant] = original[quant];
            ++i;
           // printf("%d %d\n", iguais[i], i);
        }
        else iguais[quant] = 0;
    }
    printf("%d\n", i);
    //printf("iguaisquant2: %d\n", iguais[1]);
    for(quant=0; quant<X; ++quant) {
        if ((iguais[quant]!=0)) {
            if (iguais[quant]==1) {
                if (quant==0) {
                    printf("%d %d\n", iguais[quant], (quant+1));
                }
                else continue;
            }
            else printf("%d %d\n", iguais[quant], (quant+1));

        }
    }
    return 0;
}