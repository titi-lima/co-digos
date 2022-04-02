#include <stdio.h>

int main() {
    int c, k, cont=0, aux;
    char s;

    scanf("%d", &c);

    for(aux=0; aux<c; ++aux) {
        scanf(" %c", &s);
        switch(s) {
            case 'R': {
                scanf("%d", &k);
                cont+=k;
                break;
            }
            case 'T': {
                printf("%d\n", cont);
                break;
            }
        }
    }


    return 0;
}