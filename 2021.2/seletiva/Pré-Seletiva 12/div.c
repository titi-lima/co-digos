#include <stdio.h>

int main() {
    int n, cont=0;
    scanf("%d", &n);
    if(n%2==0) --cont;
    n/=2;
    //else if(n>3) ++cont;
    while(n!=0) {
        --n;
        cont+=2;
    }
    printf("%d\n", cont);

    return 0;
}