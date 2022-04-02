#include <stdio.h>
#include <math.h>
int main () {
    long long int x, cont=0, numero=0, letra=0, k, d=2;
    char y;
    scanf("%lld", &x);
    while (x>cont) {
        scanf(" %c", &y);
        if ((y>48) && (y<58)) {
            ++numero;
            ++cont;
        }
        else {
            ++letra;
            ++cont;
        }
    }
    cont = 1;
    scanf(" %lld", &k);
  //  printf("letra: %lld\n", letra);
    //printf("numero: %lld\n", numero);
    while (k>=cont) {
        while ((d<=(cont/2) || cont == 1) && (k>=cont)) {
            if ((cont % d == 0) || (cont == 1)) {
                //letras
                printf("Tamanho %lld:\n", cont);
                printf("Sequencias: %.0f, Numeros: 0\n", pow(letra, cont));
                d=2;
                ++cont;
            }
            else ++d;
        }
        while ((d>(cont/2) || cont == 2) && (k>=cont)) {
            printf("Tamanho %lld:\n", cont);
            printf("Sequencias: 0, Numeros: %.0f\n", pow(numero, cont));
            d=2;
            ++cont;
        }
    }
    return 0;
}