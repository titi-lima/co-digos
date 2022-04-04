#include <stdio.h>
#include <stdlib.h>

void swap(int *vet, int i, int j) {
    if(vet[i] == vet[j]) return;
    vet[i]^=vet[j];
    vet[j]^=vet[i];
    vet[i]^=vet[j];
}

int HoarePartition(int *vet, int l, int r) {
    int p = vet[l];
    int i = l;
    int j = r+1;
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

void Quicksort(int *vet, int l, int r) {
    if(l<r) {
        int s = HoarePartition(vet, l, r);
        Quicksort(vet, l, s-1);
        Quicksort(vet, s+1, r);
    }
}

int main() {
    int array[17], i=0, soma=0;
    while(scanf("%d", &array[i])!=EOF) i++;
    Quicksort(array, 0, i-1);
    for(int k = 3; k<i; ++k) {
        printf("Nota %d: %d\n", k-1, array[k]);
        soma+=array[k];
    }
    printf("Media: %f\n", (float)soma/(i-3));

    return 0;
}
