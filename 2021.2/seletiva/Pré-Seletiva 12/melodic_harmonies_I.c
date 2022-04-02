#include <stdio.h>
#include <math.h>

int main() {
    long double a, b, aux, contd=0;
    long long int k, cont=0;
    int flag=0;
    scanf("%lld", &k);
    while(k--) {
        scanf("%Lf %Lf", &a, &b);
        if(b>a) aux=b/a;
        else {
            aux = a/b;
            flag=1;
        }
        if(flag==0) cont += round(log2(aux)*12.0);
        else cont -= round(log2(aux)*12.0);
        flag=0;
    }
    printf("%lld\n", abs(cont));

    return 0;
}