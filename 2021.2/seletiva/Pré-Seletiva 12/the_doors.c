#include <stdio.h>

int main() {
    int vet[200001];
    int n, flag0=0, flag1=0, s0, s1;
    scanf("%d", &n);
    int naux=n;
    for(int k=0; k<n; ++k) {
        scanf("%d", &vet[k]);
    }
    while(n--) {
        //printf("a:%d\n", vet[n]);
        if(vet[n] == 0) {
            if (flag1 == 1 && flag0 == 0) { // ja encontrou 1 antes mas n encontrou 0
                printf("%d\n", n+1);
                return 0;
            }
            //else s0=n;
            flag0=1;
        }
        else if(vet[n] == 1) {
            if (flag1 == 0 && flag0 == 1) { // ja encontrou 0 mas n encontrou 1
                printf("%d\n", n+1);
                return 0;
            }
            //else s1=n;
            flag1=1;
        }
    }
    printf("%d\n", naux);


    return 0;
}