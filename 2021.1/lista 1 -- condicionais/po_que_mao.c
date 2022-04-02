#include <stdio.h>

int main () {
    float dd, dn1, dn2, dn3;
        scanf("%f", &dd);
        scanf("%f", &dn1);
        scanf("%f", &dn2);
        scanf("%f", &dn3);

        if ((dn1+dn2+dn3)<=dd) {
            printf("3\n");
        }
        else if ((dn1+dn2)<=dd || (dn1+dn3)<=dd || (dn2+dn3)<=dd) {
            printf("2\n");
        }
        else if (dn1<=dd || dn2<=dd || dn3<=dd) {
            printf("1\n");     
        }
        else printf("0\n");
        
    return 0;
}