#include <stdio.h>
#include <math.h>

int main() {
    long long int n, m, a;
    long long int cont;
    scanf("%lld %lld %lld", &n, &m, &a);
    if(n%a!=0) {
        n+=a-n%a;
    }
    if(m%a!=0) {
        m+=a-m%a;
    }
    cont=(n*m)/(a*a);
    printf("%lld\n", cont);

    return 0;
}