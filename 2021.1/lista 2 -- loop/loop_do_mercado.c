#include <stdio.h>
int main () {
    int a, n, cont=0;

    scanf("%d %d", &a, &n);
    n=(n*60);

    while ((n>cont) && (a != 0)) {
        if ((a % 13 != 0)) {
            ++cont;
            ++a;
        }
        else {
         //   ++cont;
            (a=(a-60));
            if (a % 60 == 0) {
                (a=(a+90));
            }
            else continue;
        }
    }
    if (a == 0) {
        printf("%d\n", cont);
    }
    else printf("fui pedir comida mesmo\n");
    return 0;
}