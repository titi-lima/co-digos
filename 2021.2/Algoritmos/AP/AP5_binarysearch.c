#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* vet, int k, int r) {
    int l=0, m;
    while(l<=r) {
        m = (l + r)/2;
        if (k == vet[m]) return m;
        else if (k<vet[m]) r = m-1;
        else l = m + 1;
    }
    return -1;
}

int main() {
    int n, nelementos, key, index;
    scanf("%d", &n);
    int vet[n];
    for(int k=0; k<n; ++k) scanf("%d", &vet[k]);
    scanf("%d", &nelementos);
    while(nelementos--) {
        scanf("%d", &key);
        index=binarySearch(vet, key, n-1);
        if(index==-1) printf("x\n");
        else printf("%d\n", index);
    }

    return 0;
}