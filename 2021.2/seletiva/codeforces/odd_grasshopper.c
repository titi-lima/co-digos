#include <stdio.h>
// por algum motivo bizarro, long int nao eh o bastante no codeforces
int main() {
    int n, aux;
    long long int ip, nj, aux2;
    scanf("%d", &n);
    for(aux=0; aux<n; ++aux) {
        scanf("%lld %lld", &ip, &nj);
        if(ip%2==0) {
            if(nj%4==0) printf("%lld\n", ip);
            else if(nj%4==1) printf("%lld\n", ip-nj);
            else if(nj%4==2) printf("%lld\n", ip+1);
            else if(nj%4==3) printf("%lld\n", nj+ip+1);
        }
        else {
            if(nj%4==0) printf("%lld\n", ip);
            else if(nj%4==1) printf("%lld\n", nj+ip);
            else if(nj%4==2) printf("%lld\n", ip-1);
            else if(nj%4==3) printf("%lld\n", ip-nj-1);
        }
    }


    return 0;
}