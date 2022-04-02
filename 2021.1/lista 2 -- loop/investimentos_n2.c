#include <stdio.h>
int main () {
    int a, c, cont=0;
    scanf("%d %d", &a, &c);
    while (c>cont) {
        if (30 % (a+1) == 0) {
            printf("Curvou\n");
            ++cont;
            ++a;
        }
        else {
            printf("Pedro se cagou todo e foi pego.\n");
            break;
        }
    }
    return 0;
}