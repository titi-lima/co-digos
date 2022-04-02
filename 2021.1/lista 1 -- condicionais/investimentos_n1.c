#include <stdio.h>

int main () {
int total, cobrado, resto;
    scanf("%d", &total);
    scanf("%d", &cobrado);
    resto = cobrado % 100;
    if (total<cobrado) {
        printf("Pedro vai ter que fugir\n");
    }
    else if (cobrado==0) {
        printf("Esta pago\n");
        printf("Sobrou %d\n", total);
    }
    else if (total==cobrado) {
        if (resto==0) {
        printf("Esta pago\n");
        printf ("Sobrou %d\n", 0);
        }
        else printf("Pedro vai ter que fugir\n");
    }
    else if (resto==0) {
            printf("Esta pago\n");
            printf ("Sobrou %d\n", total-cobrado);
        }
        else {
            if ((total-cobrado)-(100-resto)<0) {
                printf ("Pedro vai ter que fugir\n");
            }
            else {
                printf("Pegou mais\n");
                printf("Esta pago\n");
                printf("Sobrou %d\n", (total-cobrado)-(100-resto));
            }
        }
    
    
    return 0;
}