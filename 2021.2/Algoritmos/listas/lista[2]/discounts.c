#include <stdio.h>
#include <stdlib.h>

void swap(long long int *vet, long long int i, long long int j) {
    if(vet[i] == vet[j]) return;
    vet[i]^=vet[j];
    vet[j]^=vet[i];
    vet[i]^=vet[j];
}

long long int HoarePartition(long long int *vet, long long int l, long long int r) {
    long long int p = vet[l];
    long long int i = l;
    long long int j = r+1;
    do {
        do {
            ++i;
        } while(p > vet[i] && r > i);
        do {
            --j;
        } while(p < vet[j]);
        swap(vet, i, j);
    } while(i<j);
    swap(vet, i, j);
    swap(vet, l, j);
    return j;
}

void Quicksort(long long int *vet, long long int l, long long int r) {
    if(l<r) {
        long long int s = HoarePartition(vet, l, r);
        Quicksort(vet, l, s-1);
        Quicksort(vet, s+1, r);
    }
}

int main() {
    long long int s, k, n, sum=0, saux=0;
    scanf("%lld", &s);
    long long int vet[s];
    for(k=0; k<s; ++k){
        scanf("%lld", &vet[k]);
        sum+=vet[k];
    }
    Quicksort(vet, 0, s-1);
    scanf("%lld", &n);
    while(n--) {
        scanf("%lld", &k);
        printf("%lld\n", sum-vet[s-k]);
    }
    return 0;
}